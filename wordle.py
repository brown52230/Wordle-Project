pref = "\033["
reset = f"{pref}0m"

class colors:
    black = "30m"
    red = "31m"
    green = "32m"
    yellow = "33m"
    blue = "34m"
    magenta = "35m"
    cyan = "36m"
    white = "37m"

def guessLetter():
    userGuess = ""
    try:
        userGuess = input(">> ")
    except:
        print("failed")
    return userGuess

def board(guess, turnsLeft, guesses):
    temp = ""
    
    for i in guesses:
        if (i != ""):
            temp = i
            for i, j in zip(temp, word):
                found = False
                if (i == j) :
                    print(u"\u001b[42m\u001b[30m {}\033[0m ".format(i), end = '');
                    found = True
                    continue

                for k in temp:
                    if (k == j): 
                        print(u"\u001b[43m\u001b[30m {} \033[0m ".format(i), end = '')
                        found = True
                        break
                if (found == False):
                    print(" {} ".format(i), end = '',)
            print("")
    for i in range(turnsLeft):  
        print(" -   -   -   -   -")


global word
word = "bread"

solved = False
guess = ""
turnsLeft = 6
turnCounter = 1
guesses = list()
while solved != True and turnsLeft > 0:
    board(guess, turnsLeft, guesses)
    guess = guessLetter()
    print(guess)
    turnsLeft -= 1
    guesses.append(guess)
    turnCounter += 1
    if (guess == word):
        solved = True
        board(guess, turnsLeft, guesses)
exit()

