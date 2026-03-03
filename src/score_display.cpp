#include "score_display.h"
#include "common_fixed_8x16_font.h"
#include <bn_string.h>

ScoreDisplay::ScoreDisplay() :
    score(0),
    high_score(0),
    score_sprites(bn::vector<bn::sprite_ptr, MAX_SCORE_CHARS>()),
    text_generator(bn::sprite_text_generator(common::fixed_8x16_sprite_font))
{}

void ScoreDisplay::update() {
    score++;
    if(score > high_score) {
        high_score = score;
    }

    score_sprites.clear();

    show_number(SCORE_X, SCORE_Y, score);
    show_number(HIGH_SCORE_X, HIGH_SCORE_Y, high_score);
}

void ScoreDisplay::show_number(int x, int y, int number) {
    bn::string<MAX_SCORE_CHARS> number_string = bn::to_string<MAX_SCORE_CHARS>(number);
    text_generator.generate(x, y, number_string, score_sprites);
}

void ScoreDisplay::resetScore() {
    score = 0;
}