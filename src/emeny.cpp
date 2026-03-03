#include "enemy.h"
#include "bounding_box.h"
#include <bn_display.h>
#include "bn_sprite_items_square.h"

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y =  bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width()  / 2;
static constexpr int MAX_X =  bn::display::width()  / 2;

Enemy::Enemy(int starting_x, int starting_y, bn::fixed enemy_speed, bn::size enemy_size) :
    sprite(bn::sprite_items::square.create_sprite(starting_x, starting_y)),
    speed(enemy_speed),
    size(enemy_size),
    bounding_box(create_bounding_box(sprite, size)),
    rng()
{}

void Enemy::update(Player& player) {
    caught_player = false;

    // Move in x direction toward player
    if(sprite.x() < player.sprite.x())      sprite.set_x(sprite.x() + speed);
    else if(sprite.x() > player.sprite.x()) sprite.set_x(sprite.x() - speed);

    // Move in y direction toward player
    if(sprite.y() < player.sprite.y())      sprite.set_y(sprite.y() + speed);
    else if(sprite.y() > player.sprite.y()) sprite.set_y(sprite.y() - speed);

    bounding_box = create_bounding_box(sprite, size);

    if(bounding_box.intersects(player.bounding_box)) {
        caught_player = true;
        jump_random();
    }
}

void Enemy::jump_random() {
    int new_x = rng.get_int(MIN_X, MAX_X + 1);
    int new_y = rng.get_int(MIN_Y, MAX_Y + 1);

    sprite.set_x(new_x);
    sprite.set_y(new_y);

    bounding_box = create_bounding_box(sprite, size);
}