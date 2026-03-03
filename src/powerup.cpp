#include "powerup.h"
#include "bounding_box.h"
#include <bn_display.h>

#include "bn_sprite_items_cheese_powerup.h"

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y =  bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width()  / 2;
static constexpr int MAX_X =  bn::display::width()  / 2;

Powerup::Powerup(bn::size powerup_size) :
    size(powerup_size),
    bounding_box(),
    sprite(),
    rng()
{}

void Powerup::update(Player& player) {
    if(!active) return;

    collected = false;

    if(bounding_box.intersects(player.bounding_box)) {
        collected = true;
        despawn();
    }
}

void Powerup::spawn() {
    int x = rng.get_int(MIN_X, MAX_X + 1);
    int y = rng.get_int(MIN_Y, MAX_Y + 1);

    sprite = bn::sprite_items::cheese_powerup.create_sprite(x, y);
    bounding_box = create_bounding_box(*sprite, size);
    active = true;
}

void Powerup::despawn() {
    sprite.reset();
    active = false;
}