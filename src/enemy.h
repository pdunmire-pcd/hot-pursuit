#ifndef ENEMY_H
#define ENEMY_H

#include <bn_fixed.h>
#include <bn_random.h>
#include <bn_rect.h>
#include <bn_size.h>
#include <bn_sprite_ptr.h>
#include "player.h"

class Enemy {
    public:
        Enemy(int starting_x, int starting_y, bn::fixed enemy_speed, bn::size enemy_size);

        /**
         * Move toward player, update bounding box, and jump to a random position when catching player.
         */
        void update(Player& player);

        /**
         * Jump to a random position on screen.
         */
        void jump_random();

        bool caught_player = false;

        bn::sprite_ptr sprite;
        bn::fixed speed;
        bn::size size;
        bn::rect bounding_box;

    private:
        bn::random rng; // Random number generator for jumping to random location when catching player
};

#endif