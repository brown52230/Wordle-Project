#include "tools.h"
#include <cstdio>

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
        board(guess, turnsLeft, guesses);
        guess = guessLetter();
        turnsLeft--;
        guesses[turnCounter] = guess;
        turnCounter++;
        if (guess == word) solved = true;
    } while (solved == false || turnsLeft > 0);
    endProgram();
}

string guessLetter(){
    string userGuess = "";
    while(!(getline(cin, userGuess)) || (userGuess.length() < 5) || (userGuess.length() > 5)){
        cout << "Guess must be 5 letters." << endl;
    }
    return userGuess;
}

void board(string guess, int turnsLeft, string guesses[]){
    string temp = "";
    
    for (int i = 0; i < 6; i++){
        if (guesses[i] != "") {
        temp = guesses[i];
        for (int i = 0; i <= temp.length(); i++) {
            bool found = false;

            if (temp[i] == word[i]) {
                cout << "\u001b[32m" << temp[i] << "\033[0m ";
                found = true;
                continue;
            }

            for (int j = 0; j < 5; j++) {
                if (temp[i] == word[j]) {
                    
                    cout << "\033[33m" << temp[i] << "\033[0m ";
                    found = true;
                    break;
                }
            }
            if (found == false) {
                cout << temp[i] << " ";
            }
        }
        cout << endl;
        }
    }
    for (int i = 1; i <= turnsLeft; i++){    
        cout << "- - - - -" << endl;
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

