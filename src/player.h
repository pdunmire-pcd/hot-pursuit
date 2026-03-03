#ifndef PLAYER_H
#define PLAYER_H

#include <bn_fixed.h>
#include <bn_rect.h>
#include <bn_size.h>
#include <bn_sprite_ptr.h>

class Player {
    public:
        Player(int starting_x, int starting_y, bn::fixed player_speed, bn::size player_size);

        /**
         * Update the position and bounding box of the player based on d-pad movement.
         */
        void update();

        bn::sprite_ptr sprite;
        bn::fixed speed;
        bn::size size;
        bn::rect bounding_box;
};

#endif