#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>
#include <bn_vector.h>
#include <bn_string.h>

// Number of characters required to show two of the longest number possible in an int (-2147483647)
static constexpr int MAX_SCORE_CHARS = 22;

// Score location
static constexpr int SCORE_X = 70;
static constexpr int SCORE_Y = -70;

// High score location
static constexpr int HIGH_SCORE_X = -70;
static constexpr int HIGH_SCORE_Y = -70;

class ScoreDisplay {
    public:
        ScoreDisplay();

        /**
         * Increases score by 1 and updates high score if needed. Displays score and high score.
         */
        void update();

        /**
         * Displays a number at the given position.
         */
        void show_number(int x, int y, int number);

        /**
         * Sets score back to 0. Does NOT reset high score.
         */
        void resetScore();

        int score;
        int high_score;
        bn::vector<bn::sprite_ptr, MAX_SCORE_CHARS> score_sprites;
        bn::sprite_text_generator text_generator;
};

#endif