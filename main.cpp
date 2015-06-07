#include <SFML\Graphics.hpp>

#include <iostream>
#include "src\game.cpp"

int main()
{
    Game game;
    game.Init();
    game.Loop();
    return 0;
}
