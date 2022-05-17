#include <cstdio>
#include <time.h>
#include <thread>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h> 
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

string wordSelect()
{
    string line;
    vector<string> lines;
    
    srand(time(0));
    
    ifstream file("wordlist.txt");
    
    int total_lines=0;
    while(getline(file,line))
    {
       total_lines++; 
    lines.push_back(line);  
    }

    int random_number=rand()%total_lines;

    return lines[random_number];
}

void endProgram() {
	cout << "\nPress enter to close.";
	cin.get();
	exit(0);
}