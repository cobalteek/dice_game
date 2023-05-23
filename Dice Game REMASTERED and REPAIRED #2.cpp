#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


void showCube1 () {

    cout<<" ---------" << endl << "|         |" << endl << "|    .    |" << endl << "|         |" << endl << " ---------" << endl;
}

void showCube2 () {

    cout<<" ---------" << endl << "|  .      |" << endl << "|         |" << endl << "|      .  |" << endl << " ---------" << endl;
}

void showCube3 () {

    cout<<" ---------" << endl << "|      .  |" << endl << "|    .    |" << endl << "|  .      |" << endl << " ---------" << endl;
}

void showCube4 () {

    cout<<" ---------" << endl << "|  .   .  |" << endl << "|         |" << endl << "|  .   .  |" << endl << " ---------" << endl;
}

void showCube5 () {

    cout<<" ---------" << endl << "|  .   .  |" << endl << "|    .    |" << endl << "|  .   .  |" << endl << " ---------" << endl;
}

void showCube6 () {

    cout<<" ---------" << endl << "|  .   .  |" << endl << "|  .   .  |" << endl << "|  .   .  |" << endl << " ---------" << endl;
}


void RollDice (int& Score) {

    int cube1,cube2;
    cube1 = 1 + rand() % 6;
    cube2 = 1 + rand() % 6;

    cout << "On the first die, "<< cube1 <<" fell out\n";
    switch (cube1) {
        case 1:
            showCube1();
            break;
        case 2:
            showCube2();
            break;
        case 3:
            showCube3();
            break;
        case 4:
            showCube4();
            break;
        case 5:
            showCube5();
            break;
        case 6:
            showCube6();
            break;
    }
    cout << "On the second die, "<< cube2 <<" fell out\n";
    switch (cube2) {
        case 1:
            showCube1();
            break;
        case 2:
            showCube2();
            break;
        case 3:
            showCube3();
            break;
        case 4:
            showCube4();
            break;
        case 5:
            showCube5();
            break;
        case 6:
            showCube6();
            break;
    }
    int Sum = cube1 + cube2;
    Score = Sum;
    cout << "Total number of points: " << Score << endl;

}


void ResDice (int& Score1, int& Score2, int& ResComp, int& ResUser) {

    if (Score1 > Score2) {
        cout << "In this round, a point goes to the computer!\n";
        ResComp++;
    }
    else if (Score1 == Score2){
        cout << "A draw! No one gets points.\n";
    }
    else {
        cout << "In this round, a point goes to you!\n";
        ResUser++;
    }

}


void Game1 () {
    int ScoreComp, ScoreUser, ResUser = 0,ResComp = 0;

    for (int i = 1 ; i <=4 ; i++ ) {
        cout << "\tComputer running.\n";
        RollDice(ScoreComp);
        Sleep(2000);
        cout << "\tYour running.\n";
        RollDice(ScoreUser);
        ResDice(ScoreComp, ScoreUser, ResComp, ResUser);
        if (i == 2){
            cout << "Let's summarize the interim results!\nCurrent Score:\nComputer: " << ResComp << "\t" << "You: " << ResUser << endl;
            cout << "To continue, enter any character: ";
        }
        Sleep(4000);
    }

    cout << "Final score:\nComputer: "<< ResComp << "\t" << "You: " << ResUser << endl;
    if (ResComp > ResUser) {
        cout << "The computer won this game!\n";
    }
    else if (ResComp == ResUser){
        cout << "Impossible...A draw!\n";
    }
    else {
        cout << "You won this game!\n";
    }

}

void Game2 () {
    int ScoreComp, ScoreUser, ResUser = 0,ResComp = 0;

    for (int i = 1 ; i <=4 ; i++ ) {
        cout << "\tYour running.\n";
        RollDice(ScoreUser);
        Sleep(2000);
        cout << "\tComputer running.\n";
        RollDice(ScoreComp);
        ResDice(ScoreComp, ScoreUser, ResComp, ResUser);
        if (i == 2){
            cout << "Let's summarize the interim results!\nCurrent Score:\nYou: " << ResUser << "\t" << "Computer: " << ResComp << endl;
        }
        Sleep(4000);
    }

    cout << "Final score:\nYou: "<< ResUser << "\t" << "Computer: " << ResComp << endl;
    if (ResComp > ResUser) {
        cout << "The computer won this game!\n";
    }
    else if (ResComp == ResUser){
        cout << "Impossible...A draw!\n";
    }
    else {
        cout << "You won this game!\n";
    }

}


int main() {
    srand(time(0));
    int lot,CoinSide;
    char next;

    cout << ".......Dice Game.......\nThe Dice game welcomes you! In this game you are competing with me, the computer!\nTo win, you need to score more points in the course of 4 dice rolls. To get started, flip a coin.\nChoose the side of the coin, 1-Heads or 2-Tails?";

    Choice:
    cout << "\nYour choice:\n";
    cin >> CoinSide;
    switch (CoinSide){
        case 1:
            cout << "Your choice of Heads!\nToss a coin..." << endl;
            break;
        case 2:
            cout << "Your choice of Tails!\nToss a coin..." << endl;
            break;
        default:
            cout << "Incorrect data, please, try again." << endl;
            goto Choice;
    }
    lot = 1 + rand() % 2;
    switch (lot) {
        case 1:
            cout << "Heads!\n";
            if (CoinSide == 1) {
                cout << "Your move is the first!\n";
                Game2();
            } else if (CoinSide == 2) {
                cout << "Computer move is the first!\n";
                Game1();
            }
            break;
        case 2:
            cout << "Tails!\n";
            if (CoinSide == 1) {
                cout << "Computer move is the first!\n";
                Game1();
            }
            else if (CoinSide == 2) {
                cout << "Your move is the first!\n";
                Game2();
            }
            break;
    }
    cout << "Do you want to play again?\nY-Yes\tN-No\n";
    cin >> next;
    if (next == 'Y' || next == 'y') {
        cout << "Great, let's continue!";
        goto Choice;
    }
    else if (next == 'N' || next == 'n') {
        cout << "See you soon!";
    }
    return 0;

}