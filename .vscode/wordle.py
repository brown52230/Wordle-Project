def guessLetter():
    userGuess = ""
    try:
        userGuess = input(">> ")
    except:
        print("failed")
    return userGuess

def board(guess, turnsLeft, guesses):
    temp = ""
    
    for i in len(guesses):
        if (guesses[i] != ""):
            temp = guesses[i]
            for i in temp.len():
                found = False

            if (temp[i] == word[i]) :
                print("\u001b[32m{}\033[0m ".format(temp[i]));
                found = True
                continue

            for j in temp.len():
                if (temp[i] == word[j]): 
                    print("\033[33m{}\033[0m ".format(temp[i]))
                    found = True
                    break
            if (found == False):
                print("{} ".format(temp[i]))
    for i in range(0, turnsLeft):  
        print("- - - - -")


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
    if (guess == word): solved = True
exit()

