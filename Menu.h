#pragma once
#include "lib.h"

class Menu {
    int check;
public:
    int startMenu() {
        cout << "Вiтаємємо у грi, юний маг! \nОбери потрiбний тобi пункт: \n1 - почати нову гру \n2 - продовжити гру \n3 - вийти\n";
        cin >> check;
        system("cls");
        return check;
    }

    int menuScills() {
        cout << "\n\nОберiть здiбнiсть: \n";
        cout << "1 - нанести атаку вогнем\n";
        cout << "2 - нанести атаку льодом\n";
        cout << "3 - нанести атаку електрикою\n";
        cout << "4 - нанести атаку землею\n";
        cout << "5 - вилiкуватися\n";

        cin >> check;
        system("cls");

        return check;
    }
    int appScills() {
        cout << "\nОберiть здiбнiсть: \n";
        cout << "1 - пiдвищiти магiю вогню\n";
        cout << "2 - пiдвищiти магiю льоду\n";
        cout << "3 - пiдвищiти магiю електрики\n";
        cout << "4 - пiдвищiти магiю землi\n";
        cout << "5 - пiдвищiти магiю лiкування\n";

        cin >> check;
        system("cls");

        return check;
    }

    int educationOrBegin() {
        cout << "Чи бажаєте ви пройти навчальний етап?\n";
        cout << "1 - Так\n";
        cout << "2 - Нi\n";

        cin >> check;
        system("cls");

        return check;
    }

    int labolatoryMenu() {
        cout << "\nВiтаємо у лаболаторiї! Оберiть що вас цiкавить:\n";
        cout << "1 - пiдвищити рiвень здiбностi\n";
        cout << "2 - перевiрити рiвень здiбностей\n";
        cout << "3 - стабiлiзувати ману\n";
        cout << "4 - покинути лаболаторiю\n";

        cin >> check;
        system("cls");

        return check;
    }

    int mainMenu() {
        cout << "\n\n1 - вiдвiдати 1 кiмнату\n";
        cout << "2 - вiдвiдати 2 кiмнату\n";
        cout << "3 - вiдвiдати 3 кiмнату\n";
        cout << "4 - пройти екзамен\n";
        cout << "5 - вiдвiдати лабораторiю\n";
        cout << "6 - зберигтися\n";
        cout << "0 - вийти iз гри\n";

        cin >> check;
        system("cls");

        return check;
    }
};