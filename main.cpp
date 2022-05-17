#include "tools.h"

string word = wordSelect();

void instructions();
string guessLetter();
void board(string, int, string[]);

int main()
{
    system("cls");
    bool solved = false;
    string guess;
    int turnsLeft = 6;
    int turnCounter = 0;
    string guesses[6];

    instructions();

    do
    {
        system("cls");
        board(guess, turnsLeft, guesses);
        guess = guessLetter();
        if (guess == word)
        {
            solved = true;
        }
        if (guess != "")
        {
            turnsLeft--;
            guesses[turnCounter] = guess;
            turnCounter++;
        }
    } while (solved == false && turnsLeft > 0);

    system("cls");
    board(guess, turnsLeft, guesses);
    cout << "The word was \u001b[42m\u001b[30m " << word << " \033[0m!" << endl;
    cout << turnCounter << " turns used" << endl;

    endProgram();
}

string guessLetter()
{
    string userGuess = "";
    cout << endl;
    cout << "       vvvvv" << endl;
    cout << "       ";
    while (!(getline(cin, userGuess)) || (userGuess.length() < 5) || (userGuess.length() > 5))
    {
        return "";
    }
    return userGuess;
}

void board(string guess, int turnsLeft, string guesses[])
{
    string temp = "";

    for (int i = 0; i < 6; i++)
    {
        bool found = false;
        if (guesses[i] != "")
        {

            temp = guesses[i];
            int letterCount = 0;
            int limit = count(temp.begin(), temp.end(), temp.at(i));
            for (int j = 0; j <= (temp.length() - 1); j++)
            {
                found = false;

                if (letterCount != limit)
                {
                    letterCount = 0;
                }

                if (temp.at(j) == word.at(j))
                {
                    cout << "\u001b[42m\u001b[30m " << temp[j] << " \033[0m ";
                    letterCount++;
                    continue;
                }

                else if (word.find(temp[j]) != string::npos)
                {
                    if (limit < letterCount)
                    {
                        cout << " " << temp[j] << "  ";
                        letterCount++;
                        continue;
                    }
                    cout << "\u001b[43m\u001b[30m " << temp.at(j) << " \033[0m ";
                    continue;
                }
                else
                    cout << " " << temp[j] << "  ";
                letterCount = 0;
            }
            cout << endl;
        }
    }

    for (int i = 1; i <= turnsLeft; i++)
    {
        cout << " -   -   -   -   -" << endl;
    }
}

void instructions()
{
    cout << "Welcome to Wordle! (But made in C++ very poorly.)" << endl;
    cout << "This game uses ANSI color codes, so some terminals \nmay not be able to support this." << endl;
    cout << endl;
    cout << "If you cant see the rainbow below, your terminal \nmay not be supported." << endl;
    cout << "\n\u001b[41m   \u001b[43m   \u001b[42m   \u001b[44m   \u001b[45m   \u001b[47m   \u001b[0m" << endl;
    cout << "\n";

    cout << "Guess the WORDLE in six tries." << endl;
    cout << endl;

    cout << "Each guess must be a valid five-letter word.\nHit the enter button to submit." << endl;
    cout << "\nAfter each guess, the color of the tiles will \nchange to show how close your guess was to the \nword." << endl;
    cout << endl;

    cout << "\t\u001b[42m\u001b[30m w \033[0m  o   r   l   d" << endl;
    cout << "The letter W is in the word and in the correct \nspot." << endl;

    cout << "\n\t p  \u001b[43m\u001b[30m i \033[0m  l   e   s" << endl;
    cout << "The letter I is in the word but in the wrong spot." << endl;

    cout << "\n\t c   l   a  s   s" << endl;
    cout << "Letters not colored are not in the word." << endl;
    cout << endl;

    cout << "\n\u001b[41m\u001b[30mKNOWN BUGS:\033[0m" << endl;
    cout << "If you guess a word with multiple letters, it \nwill mark all of them." << endl;
    cout << "I could not find a way to fix this. Words will \nhave no repeating letters in this build." << endl;

    cout << "\nThere is also no system for checking if your word \nis actually a word.\n"
         << endl;
    cout << "For the sake of this demo, please try to use \nactual words.\n"
         << endl;

    cout << "Press enter to begin." << endl;
    cin.ignore();
}