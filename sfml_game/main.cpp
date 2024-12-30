#include "Game1.h"

int main(int, char const**) {
    // init srant
    std::srand(static_cast<unsigned>(time(NULL)));
    // Init Game
    Game game;

    // Start the game loop
    while (game.running() && !game.getEndGame()) {
        game.update();
        game.render();
    }

    return EXIT_SUCCESS;
}
