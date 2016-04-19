#include "Labyrinth.h"
#include "LabyrinthPathFinder.h"

#include <iostream>

Labyrinth::Labyrinth(ImageProvider & imageProvider, int height, int width)
    : playfield(imageProvider, height, width),
    player(imageProvider, Position::Center(height, width)),
    solved(false),
    surface(height, width) {

    while (true) {

        LabyrinthPathFinder labyrinthPathFinder(this->playfield);
        bool playfieldHasExit = labyrinthPathFinder.findPath(Position::Center(height, width));
        if (playfieldHasExit) {
            break;
        }
        else {
            this->playfield.regenerate();
        }
    }

    this->objectsToDraw.push_back(&this->playfield);
    this->objectsToDraw.push_back(&this->player);
}

void Labyrinth::draw(void) {

    for (std::vector<IDrawable *>::iterator objectToDraw = this->objectsToDraw.begin();
    objectToDraw != this->objectsToDraw.end(); objectToDraw++) {
        (*objectToDraw)->draw(this->surface);
    }

    this->surface.drawOnScreen();
}

void Labyrinth::doCommand(const UserCommand & command) {
    bool useSwitch = true;
    IMoveable::Direction direction = IMoveable::DIRECTION_INVALID_DIRECTION;
    if (useSwitch)
    {

        { {
                switch (command) {
                case USER_COMMAND_MOVE_LEFT:
                    direction = IMoveable::DIRECTION_LEFT;
                    break;
                case USER_COMMAND_MOVE_UP:
                    direction = IMoveable::DIRECTION_UP;
                    break;
                case USER_COMMAND_MOVE_RIGHT:
                    direction = IMoveable::DIRECTION_RIGHT;
                    break;
                case USER_COMMAND_MOVE_DOWN:
                    direction = IMoveable::DIRECTION_DOWN;
                    break;
                default:
                    std::cerr << "Invalid direction!" << std::endl;
                    return;
                }}}
    }
    else
    {
        if (command != USER_COMMAND_MOVE_LEFT)
        {
            if (command != USER_COMMAND_MOVE_UP)
            {
                if (command != USER_COMMAND_MOVE_RIGHT)
                {
                    if (command != USER_COMMAND_MOVE_DOWN)
                    {
                        std::cerr << "Invalid direction!" << std::endl;
                        {
                            return;
                        }
                    }
                    else
                    {
                        direction = IMoveable::DIRECTION_DOWN;

                    }
                }
                else
                {
                    direction = IMoveable::DIRECTION_RIGHT;

                }
            }
            else {
                direction = IMoveable::DIRECTION_UP;

            }
        }
        else
        {
            direction = IMoveable::DIRECTION_LEFT;

        }
    }
    bool successfulMove = this->player.move(direction, this->playfield);
    if (successfulMove) {
        if (this->playfield.onExit(this->player.getPosition())) {
            this->solved = true;
        }
        else {
            this->draw();
        }
    }
    else {
        std::cout << "Invalid move!" << std::endl;
    }
}

Score Labyrinth::getScore(void) {

    Score score = static_cast<Score> (this->player.getMovements());
    return score;
}

bool Labyrinth::isSolved(void) {

    return this->solved;
}

