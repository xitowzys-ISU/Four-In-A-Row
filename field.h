#ifndef FIELD_H
#define FIELD_H

#include <iostream>

const short di[] = { 1, 0, 1, 1 };
const short dj[] = { 0, 1, -1, 1 };

enum Cell
{
    EMPTY=0,
    RED=2,
    YELLOW=8
};


class Field
{

private:

    const static unsigned short FIELD_WIDTH = 7;
    const static unsigned short FIELD_HEIGHT = 6;

    const unsigned short DIR_NUMBER = 4;
    const unsigned short WIN_LENGTH = 4;

    // Очередь хода
    Cell cells[FIELD_WIDTH][FIELD_HEIGHT];

    bool isRedTurn = true;

    // Кто на данный момент выиграл
    Cell winner;

public:
    Field(bool isRedFirst); //y
    void clear(bool isRedFirst); //y
    bool makeTurn(int column); //y
    bool isWon(bool red) const; //create
    bool isOver() const; //y
    Cell getCell(int i, int j) const; // create
    bool isRedTurnNow() const; // create
    void print() const; //create
    void printResult() const; //create
    void checkWinner();
};

#endif // FIELD_H
