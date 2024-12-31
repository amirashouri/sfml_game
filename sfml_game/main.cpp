#include "Game2.h"

int main(int, char const**) {
    
    /*
     GAME ONE:
     
    // init srant
    std::srand(static_cast<unsigned>(time(NULL)));
    // Init Game
    Game game;

    // Start the game loop
    while (game.running() && !game.getEndGame()) {
        game.update();
        game.render();
    }
    */
    
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));
    
    // Initialize game object
    Game game;
    
    // Game loop
    while (game.running()) {
        game.update();
        game.render();
    }

    return EXIT_SUCCESS;
}
