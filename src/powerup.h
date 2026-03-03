#ifndef POWERUP_H
#define POWERUP_H

#include <bn_fixed.h>
#include <bn_random.h>
#include <bn_rect.h>
#include <bn_size.h>
#include <bn_optional.h>
#include <bn_sprite_ptr.h>
#include "player.h"

class Powerup {
    public:
        Powerup(bn::size powerup_size);

        /**
         * Check if player has collected the powerup.
         * Does nothing if not active.
         */
        void update(Player& player);

        /**
         * Spawn the powerup at a random position and make it active.
         */
        void spawn();

        /**
         * Deactivate and hide the powerup.
         */
        void despawn();

        bool active = false;
        bool collected = false;

        bn::size size;
        bn::rect bounding_box;
        bn::optional<bn::sprite_ptr> sprite;

    private:
        bn::random rng;
};

#endif