# Instructions
## Wave 0: Setup project
1. Choose one partner to be Partner A, one partner to Partner B.
1. Have ONLY Partner A fork this repository. PARTNER B SHOULD NOT FORK.
1. Have ONLY Partner A BOTH enable workflows AND switch GitHub pages to use GitHub actions. Feel free to look back at previous instructions if you forget how to do this.
1. Have Partner A add Partner B as a collaborator on their fork. Follow [these directions](https://docs.github.com/en/enterprise-server@3.10/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-access-to-your-personal-repositories/inviting-collaborators-to-a-personal-repository#inviting-a-collaborator-to-a-personal-repository).
1. Have the Partner A send the URL of their repository to Partner B.
1. Partner B should see an invitation at the top of the repository. Click "View Invitation", then "Accept Invitation".
1. Both partners should clone the repository to their own computer. The URL should include Partner A's username.
1. Both partners should change into the project repository:
    ```
    cd hot-pursuit
    ```
1. Both partners should open VSCode in the project repository. If the below command does not work, open VS Code and use File > Open Folder.
    ```
    code .
    ```
1. Re-open the project in the dev container.

## Wave 1: Understand
1. Make the code
1. Run the game
1. Look at the code. Understand what it's doing. Discuss with your partner.

## Wave 2: Player Constructor
1. Create a constructor for the player.
1. Move all initialization logic into the constructor.
1. Make and test your game.
1. Add/commit/push!

## Wave 3: Update Player Movement
1. Add logic to the `update` member function of Player so the player can move up and down.
1. Make and test your game
1. Add/commit/push!

## Wave 4: Refactor Enemy Into Class
1. Create a new class "Enemy" AFTER the Player class but before main. It should contain:
    - a sprite_ptr for its sprite
    - a size for the size
    - a rect for a bounding box
    - a constructor that takes a `starting_x`, `starting_y`, and `size` and initializes ALL values
1. Create an Enemy instance in main before the loop. Create it at a DIFFERENT POSITION than the current enemy sprite.
1. make/test your game. Note that collision with the new enemy will not work yet, but the new enemy should show up.
1. add/commit/push
1. REMOVE `enemy_sprite` and `enemy_bounding_box`
1. Change the `if` statement in main to use the enemy instance instead.
1. make/test your game. Collision should work now!
1. add/commit/push

## Wave 5: Chase!
1. Add an update member function to the Enemy class. It should take in one argument, like so: `void update(Player& player)`. In the update, it should:
    - Move the enemy towards the player. Think about how you can achieve this! Consider adding a speed instance variable to the enemy
    - Update the bounding box of the enemy
1. Call the update logic in the while loop. You will need to call it as `enemy.update(player);`
1. make/test your game. This part is tricky and may take quite a few tries.
1. Add/commit/push
1. Add logic to the Enemy to make it jump to a random position when it catches the Player.
1. make/test
1. Add/commit/push
1. Add logic to the Player `update` member function to prevent the Player from moving off the the screen.
1. make and test your game
1. Add/commit/push!

## Wave 6: Multiple enemies
1. Create a vector of Enemy instances in main.
1. Manually add a few enemies before the loop.
1. Update the while loop to include a for loop that loops over the enemies. It should update the position of each one and check for collision, resetting the player position and score if ANY enemy catches the player.
1. make/test your game. 
1. Add/commit/push

## Wave 7: Increasing enemies
1. Make it so there is only one enemy in the vector to start. Every X amount of frames, add a new enemy at a random location if there is room in the vector. Experiment to find a good value for X!
1. make/test
1. add/commit/push
1. Make it so that if an enemy catches the player, all enemies except for one are removed from the vector.
1. make/test
1. add/commit/push

## Wave 7.5 Refactoring
1. Refactor your code into separate files.
    - There should be NO class or function declarations in `main.cpp` other than `int main()`
    - There should be one `.cpp` and `.h` per class
    - There should be NO implementaion in the `.h` files, only declarations
    - Remember to have include guards in your headers!
1. make/test and add/commit/push as you go! There should be at least one commit per class.

## Wave 8: Prettifying
1. Modify the sprites to make them more interesting.
1. make/test
1. add/commit push

## Wave 9: Gamifying
Make the game your own in some way! A few ideas:
- Make it so that later enemies are faster than earlier ones
- Make it powerups appear than the player can collect that temporarily increase the speed or make it invincible
- Add sounds/music
- Make it so the enemies never overlap each other when chasing the player (very tricky, but is a huge improvement to the game!)
- Other ideas you come up with!

## Wave 10: Polishing
1. Once you're satisfied with your game and everything is pushed, verify that it works on GitHub pages. Fix configuration if needed.
1. Make a quick gif of your game!
    1. Open your game in mGBA.
    1. Click Audio/Video > Record GIF/WebP/APNG
    1. Choose GIF, and make sure "Loop" is checked
    1. Select a location in your repo and give a name to the GIF
    1. Click Start, and play your game for a short while (probably no more than 10 seconds)
    1. Click Stop.
    1. Verify your GIF has been saved in your repo and add/commit/push the GIF.
1. Update README.md. I encourage you to look up Markdown syntax online or look at this README in edit mode for an example.
    - Give a new name to your game, and a brief description of it.
    - Add a link to the deployed GitHub page from your README.
    - Embed your GIF
    - Keep the README short, but informative and exciting. You want someone to see it and quickly have an idea of what your game is and be able to find the link to play it.
    - Add/commit/push!
1. Make a Pull Request (PR) to the original repository. 


## Submitting
 See Canvas for instructions on how to submit

