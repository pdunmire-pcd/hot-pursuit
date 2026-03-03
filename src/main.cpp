#include <bn_core.h>
#include <bn_random.h>
#include <bn_display.h>
#include <bn_vector.h>

#include "bounding_box.h"
#include "score_display.h"
#include "player.h"
#include "enemy.h"

// Width and height of the player and enemy bounding boxes
static constexpr bn::size PLAYER_SIZE = {8, 8};
static constexpr bn::size ENEMY_SIZE  = {8, 8};

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y =  bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width()  / 2;
static constexpr int MAX_X =  bn::display::width()  / 2;

static constexpr int SPAWN_EVERY_FRAMES = 120; // Can change to 90 or 150 for different difficulty

int main() {
    bn::core::init();

    bn::vector<Enemy, 6> enemies;
    ScoreDisplay scoreDisplay; // Create a new score display
    Player player(22, 44, 3.5, PLAYER_SIZE); // Create a player and initialize it

    enemies.push_back(Enemy(-70, 0, bn::fixed(1.2), ENEMY_SIZE));

    // Frame counter and spawn rate
    bn::random rng;
    int frame_count = 0;

    while(true) {
        player.update();
        frame_count++;

        // Spawn a new enemy every SPAWN_EVERY_FRAMES frames (up to the max)
        if(frame_count % SPAWN_EVERY_FRAMES == 0 && enemies.size() < enemies.max_size()) {
            int x = rng.get_int(MIN_X, MAX_X + 1);
            int y = rng.get_int(MIN_Y, MAX_Y + 1);
            // Randomize speed a bit — change 0.4 and range (0,4) for faster enemies
            bn::fixed spd = bn::fixed(0.4 + (rng.get_int(0, 4) / 10.0));
            enemies.push_back(Enemy(x, y, spd, ENEMY_SIZE));
        }

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

            // Remove all enemies except the first
            while(enemies.size() > 1) enemies.pop_back();

            frame_count = 0;
        }

        // Update the scores and display them
        scoreDisplay.update();
        bn::core::update();
    }
}