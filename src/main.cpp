#include <bn_core.h>
#include <bn_random.h>
#include <bn_display.h>
#include <bn_vector.h>
#include <bn_music_items.h>

#include "bounding_box.h"
#include "score_display.h"
#include "player.h"
#include "enemy.h"
#include "powerup.h"

static constexpr bn::size PLAYER_SIZE = {8, 8};
static constexpr bn::size ENEMY_SIZE  = {8, 8};
static constexpr bn::size POWERUP_SIZE = {8, 8};

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y =  bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width()  / 2;
static constexpr int MAX_X =  bn::display::width()  / 2;

static constexpr int SPAWN_EVERY_FRAMES  = 120;
static constexpr int POWERUP_SPAWN_RATE  = 180;  // Spawn a powerup every 10 seconds
static constexpr int BOOST_DURATION      = 300;  // Boost lasts 5 seconds
static constexpr bn::fixed NORMAL_SPEED  = bn::fixed(3.5);
static constexpr bn::fixed BOOSTED_SPEED = bn::fixed(6.0);

int main() {
    bn::core::init();

       bn::music_items::arcade.play();

    bn::vector<Enemy, 6> enemies;
    ScoreDisplay scoreDisplay;
    Player player(22, 44, NORMAL_SPEED, PLAYER_SIZE);
    Powerup powerup(POWERUP_SIZE);

    enemies.push_back(Enemy(-70, 0, bn::fixed(0.6), ENEMY_SIZE));

    bn::random rng;
    int frame_count = 0;
    int boost_timer = 0; // 0 means no active boost

    while(true) {
        player.update();
        frame_count++;

        // Spawn enemies with escalating speed
        if(frame_count % SPAWN_EVERY_FRAMES == 0 && enemies.size() < enemies.max_size()) {
            int x = rng.get_int(MIN_X, MAX_X + 1);
            int y = rng.get_int(MIN_Y, MAX_Y + 1);
            bn::fixed base_speed = bn::fixed(0.5) + bn::fixed(enemies.size()) * bn::fixed(0.15);
            bn::fixed spd = base_speed + bn::fixed(rng.get_int(0, 3)) * bn::fixed(0.1);
            enemies.push_back(Enemy(x, y, spd, ENEMY_SIZE));
        }

        // Spawn powerup periodically if not already active
        if(!powerup.active && frame_count % POWERUP_SPAWN_RATE == 0) {
            powerup.spawn();
        }

        // Update powerup and handle collection
        powerup.update(player);
        if(powerup.collected && boost_timer == 0) {
            player.speed = BOOSTED_SPEED;
            boost_timer = BOOST_DURATION;
        }

        // Count down boost timer and restore speed when it expires
        if(boost_timer > 0) {
            boost_timer--;
            if(boost_timer == 0) {
                player.speed = NORMAL_SPEED;
            }
        }

        // Update enemies and check for catch
        bool caught = false;
        for(Enemy& enemy : enemies) {
            enemy.update(player);
            if(enemy.caught_player) caught = true;
        }

        if(caught) {
            scoreDisplay.resetScore();

            player.sprite.set_x(44);
            player.sprite.set_y(22);
            player.bounding_box = create_bounding_box(player.sprite, player.size);
            player.speed = NORMAL_SPEED;

            // Reset boost
            boost_timer = 0;

            // Despawn powerup
            powerup.despawn();

            while(enemies.size() > 1) enemies.pop_back();
            frame_count = 0;
        }

        scoreDisplay.update();
        bn::core::update();
    }
}