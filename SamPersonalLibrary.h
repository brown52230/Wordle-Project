#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h> 
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

void endProgram() {
	cout << "\nPress enter to close.";
	cin.ignore(100, '\n');
	cin.get();
	exit(0);
}

#pragma region ~~~~~< Validation Functions >~~~~~

int validateInteger(string prompt) {
	int num = 0;
	cout << prompt;
	while (!(cin >> num) || cin.fail() || num < 0)
	{
		if (num < 0) cout << "Value cannot be negative.";
		else cout << "\nValue is not a valid entry Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

int validateInteger(string prompt, int min, int max) {
	int num = 0;
	cout << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max))
	{
		if (num < 0) cout << "\nValue cannot be negative." << endl;
		else cout << "\nValue is Invalid, please re-enter." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

double validateDouble(string prompt) {
	double num = 0;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || num < 0)
	{
		if (num < 0) cout << "Value cannot be negative.";
		else cout << "\nValue is not a valid entry. Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

double validateDouble(string prompt, double min, double max) {
	double num = 0;
	cout << "\n" << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max))
	{
		if (min < 0 || max < 0) cout << "\nValue cannot be negative." << endl;
		else if (min > max) cout << "\nValue is out of range." << endl;
		else cout << "\nValue is not a valid entry. Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

float validateFloat(string prompt) {
	float num = 0;
	cout << prompt;
	while (!(cin >> num) || cin.fail() || num < 0)
	{
		if (num < 0) cout << "Value cannot be negative.";
		else cout << "\nValue is not a valid entry. Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

float validateFloat(string prompt, float min, float max) {
	float num = 0;
	cout << prompt;
	while (!(cin >> num) || cin.fail() || (num < min || num > max))
	{
		if (min < 0 || max < 0) cout << "\nValue cannot be negative." << endl;
		else if (min > max) cout << "\nValue is out of range." << endl;
		else cout << "\nValue is not a valid entry. Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return num;
}

char validateYesNo(string prompt) {
	char yesNo;
	cout << prompt;
	while (!(cin >> yesNo) || cin.fail() || toupper(yesNo) != 'Y' && toupper(yesNo) != 'N')
	{
		cout << "\nInvalid Data Entered. Try Again." << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << prompt;
	}
	return toupper(yesNo);
}

#pragma endregion;

int randomNum (int min, int max) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	int output;
		random_device rand_dev;
		mt19937 generator(seed);
		uniform_int_distribution<int> distr(min, max);
	output = distr(generator);
	return output;
}

