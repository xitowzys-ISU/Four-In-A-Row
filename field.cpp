#include "field.h"

Field::Field(bool isRedFirst)
{
    clear(isRedFirst);
}

void Field::clear(bool isRedFirst)
{
    isRedTurn = isRedFirst;
    winner = EMPTY;

    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        for (int j = 0; j < FIELD_HEIGHT; j++)
        {
            cells[i][j] = EMPTY;
        }
    }
}

bool Field::makeTurn(int column)
{
    if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
    {
        return false;
    }

    int i=column-1;

    for (int j = 0; j < FIELD_HEIGHT; j++)
    {
        if (cells[i][j]==EMPTY)
        {
            cells[i][j] = isRedTurn ? RED : YELLOW;
            isRedTurn = !isRedTurn;
            checkWinner(); // Победа?
            return true;
        }
    }

    return false;
}

bool Field::isOver() const
{
    if (winner != EMPTY)
    {
       return true;
    }

    for (int i=0; i<FIELD_WIDTH; i++)
    {
       for (int j=0; j<FIELD_HEIGHT; j++)
       {
           if (cells[i][j]==EMPTY)
           {
                return false;
           }
       }
    }

    return true;
}

void Field::checkWinner()
{
    for (int i=0; i < FIELD_WIDTH; i++)
    {
        for (int j=0; j < FIELD_HEIGHT; j++)
        {
            Cell start = cells[i][j];

            if (start==EMPTY)
            {
                continue;
            }

            for (int dir=0; dir < DIR_NUMBER; dir++)
            {
                int length = 0, iline = i, jline = j;

                while (++length < WIN_LENGTH)
                {
                    iline += di[dir];
                    jline += dj[dir];

                    if (iline < 0 || iline >= FIELD_WIDTH || jline < 0 || jline >= FIELD_HEIGHT)
                    {
                        break;
                    }

                    if (cells[iline][jline]!=start)
                    {
                        break;
                    }
                }

                if (length == WIN_LENGTH) {
                    winner = start;
                    this->print();
                    return;
                }
            }
        }
    }
}

void Field::print() const
{
    for (int i = FIELD_HEIGHT - 1; i >= 0; i--)
    {
        for (int j = 0; j < FIELD_WIDTH; j++)
        {
            std::cout << cells[j][i] << ' ';
        }

        std::cout << std::endl;
    }
}

bool Field::isRedTurnNow() const
{
    return (isRedTurn);
}

Cell Field::getCell(int i, int j) const
{
    return cells[i][j];
}


void Field::printResult() const
{
    if(winner == 2)
    {
        std::cout << "Win RED" << std::endl;
    }
    else
    {
       std::cout << "Win YELLOW" << std::endl;
    }
}

