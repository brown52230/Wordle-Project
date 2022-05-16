#include "tools.h"
#include <cstdio>
#include <chrono>
#include <time.h>


string word = wordSelect();

string guessLetter();
void board(string, int, string[]);
bool search(char);

int main(){
    bool solved = false;
    string guess;
    int turnsLeft = 6;
    int turnCounter = 0;
    string guesses[6];
    do {
        system("clear");
        board(guess, turnsLeft, guesses);
        guess = guessLetter();
        turnsLeft--;
        guesses[turnCounter] = guess;
        turnCounter++;
        if (guess == word) {
            cout << "The word was " << word << "!" << endl;
            cout << "Solved in " << turnCounter << " turns." << endl;
            cout << "Time: " << time(NULL) - startTime << " seconds." << endl;
            solved = true;
        } 
    } while (solved == false && turnsLeft > 0);

    endProgram();
}

string guessLetter(){
    string userGuess = "";
    cout << endl;
    cout << "       vvvvv" << endl;
    cout << "       ";
    while(!(getline(cin, userGuess)) || (userGuess.length() < 5) || (userGuess.length() > 5)){
        cout << "Guess must be 5 letters." << endl;
    }
    return userGuess;
}

void board(string guess, int turnsLeft, string guesses[]){
    string temp = "";
    
    for (int i = 0; i < 5; i++){
        if (guesses[i] != "") {
        temp = guesses[i];
        for (int i = 0; i <= (temp.length() - 1); i++) {
            bool found = false;

            if (temp[i] == word[i]) {
                cout << "\u001b[42m\u001b[30m " << temp[i] << " \033[0m ";
                found = true;
                continue;
            }

            for (int k = 0; k < 5; k++) {
                if (temp[k] == word[i]) {
                    
                    cout << "\u001b[43m\u001b[30m " << temp[i] << " \033[0m ";
                    found = true;
                    break;
                }
            }
            if (found == false) {
                cout << " " << temp[i] << "  ";
            }
        }
        cout << endl;
        }
    }
    for (int i = 1; i <= turnsLeft; i++){    
        cout << " -   -   -   -   -" << endl;
    }
}

bool search(char search){
    for (int i = 0; i < 6; i++){
        if (search == word[i]) {
            return true;
        }
    }
    return false;
}

