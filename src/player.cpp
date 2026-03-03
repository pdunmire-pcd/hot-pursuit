#include "player.h"
#include "bounding_box.h"
#include <bn_display.h>
#include <bn_keypad.h>
#include "bn_sprite_items_dot.h"

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y =  bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width()  / 2;
static constexpr int MAX_X =  bn::display::width()  / 2;

Player::Player(int starting_x, int starting_y, bn::fixed player_speed, bn::size player_size) :
    sprite(bn::sprite_items::dot.create_sprite(starting_x, starting_y)),
    speed(player_speed),
    size(player_size),
    bounding_box(create_bounding_box(sprite, size))
{}

void Player::update() {
    if(bn::keypad::right_held()) sprite.set_x(sprite.x() + speed);
    if(bn::keypad::left_held())  sprite.set_x(sprite.x() - speed);
    if(bn::keypad::up_held())    sprite.set_y(sprite.y() - speed);
    if(bn::keypad::down_held())  sprite.set_y(sprite.y() + speed);

    // Keep player on screen
    bn::fixed half_w = bn::fixed(size.width()  / 2);
    bn::fixed half_h = bn::fixed(size.height() / 2);

    if(sprite.x() < MIN_X + half_w) sprite.set_x(MIN_X + half_w);
    if(sprite.x() > MAX_X - half_w) sprite.set_x(MAX_X - half_w);
    if(sprite.y() < MIN_Y + half_h) sprite.set_y(MIN_Y + half_h);
    if(sprite.y() > MAX_Y - half_h) sprite.set_y(MAX_Y - half_h);

    bounding_box = create_bounding_box(sprite, size);
}