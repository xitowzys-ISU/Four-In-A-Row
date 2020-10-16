#include <QCoreApplication>
#include <iostream>
#include <field.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using namespace std;

    Field field(true);

    while (!field.isOver())
    {
        field.print();

        cout << "Ходит " << (field.isRedTurnNow() ? "красный" : "желтый") <<"  игрок, введите ход (1-7)" << endl;

        int column;
        cin >> column;

        field.makeTurn(column);
    }

    field.printResult();

    return 0;
}
