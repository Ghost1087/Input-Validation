// TestingInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;



int main()
{
	const int rows = 10;
	const int cols = 10;

	bool keepgoing = true;
	bool valid = false;

	string choiceRow = "";
	string choiceCol = "";
	string choiceNum = "";

	string one = "1";
	string two = "2";
	string three = "3";
	string four = "4";
	string five = "5";
	string six = "6";
	string seven = "7";
	string eight = "8";
	string nine = "9";

	string A = "A";
	string B = "B";
	string C = "C";
	string D = "D";
	string E = "E";
	string F = "F";
	string G = "G";
	string H = "H";
	string I = "I";

	


	const string num1 = " 1 ";
	const string num2 = " 2 ";
	const string num3 = " 3 ";
	const string num4 = " 4 ";
	const string num5 = " 5 ";
	const string num6 = " 6 ";
	const string num7 = " 7 ";
	const string num8 = " 8 ";
	const string num9 = " 9 ";

	string boardTwo[rows][cols] = {
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , " 4 " , "   " , num1  , num2  , " 9 " , "   " , "   " , " 7 " , " 5 " },
		{ " 2 " , " 2 " , "   " , "   " , " 3 " , "   " , "   " , " 8 " , "   " , "   " },
		{ " 3 " , "   " , " 7 " , "   " , "   " , " 8 " , "   " , "   " , "   " , " 6 " },
		{ " 4 " , "   " , "   " , "   " , num1  , "   " , " 3 " , "   " , "[6]" , "[2]" },
		{ " 5 " , "[1]" , "   " , " 5 " , "   " , "   " , "   " , " 4 " , "   " , " 3 " },
		{ " 6 " , "[7]" , " 3 " , "   " , " 6 " , "   " , " 8 " , "   " , "   " , "   " },
		{ " 7 " , " 6 " , "   " , "   " , "   " , "[2]" , "   " , "   " , " 3 " , "   " },
		{ " 8 " , "   " , "   " , " 7 " , "   " , "   " , num1  , "   " , "   " , " 4 " },
		{ " 9 " , " 8 " , " 9 " , "   " , "   " , "[6]" , "[5]" , " 1 " , "   " , " 7 " }
	};

	//============== GENERATE BOARD ================

	string boardTopTwo = "=========================================";
	string boardMidTwo = "-----------------------------------------";

	cout << boardTopTwo << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << "|";

		for (int j = 0; j < cols; j++)
		{
			cout << boardTwo[i][j];
			if (i == 0)
			{
				cout << "|";
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)
			{
				cout << "|";
			}

			else
			{
				cout << " ";
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)
		{
			cout << endl << boardTopTwo << endl;
		}
		else
		{
			cout << endl;
			for (int j = 0; j < cols; j++)
			{
				if (j == 0)
				{
					cout << "|---|";
				}
				else if (j == 3 || j == 6 || j == 9)
				{
					cout << "           |";
				}
			}
			cout << endl;
		}

	}

	cout << endl << endl;


	//============== INPUT VALIDATION ================

	cout << "Enter a row (1-9): ";
	getline(cin, choiceRow);

	while (valid == false)
	{
		if (choiceRow == one || choiceRow == two || choiceRow == three || choiceRow == four || choiceRow == five || choiceRow == six || choiceRow == seven || choiceRow == eight || choiceRow == nine)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid input. Enter a row (1-9): ";
			getline(cin, choiceRow);
		}
	}

	valid = false;

	cout << "Enter a column (A-I): ";
	getline(cin, choiceCol);

	choiceCol[0] = choiceCol[0] - 32;

	while (valid == false)
	{
		if (choiceCol == A || choiceCol == B || choiceCol == C || choiceCol == D || choiceCol == E || choiceCol == F || choiceCol == G || choiceCol == H || choiceCol == I)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid input. Enter a column (A-I): ";
			getline(cin, choiceCol);

			choiceCol[0] = choiceCol[0] - 32;
		}
	}

	valid = false;

	cout << "Enter a number to insert in cell " << choiceCol << choiceRow << ": ";
	getline(cin, choiceNum);


	while (valid == false)
	{
		if (choiceNum == one || choiceNum == two || choiceNum == three || choiceNum == four || choiceNum == five || choiceNum == six || choiceNum == seven || choiceNum == eight || choiceNum == nine)
		{
			valid = true;
		}
		else
		{
			cout << "Invalid input. Enter a row (1-9): ";
			getline(cin, choiceNum);
		}
	}

	

	cout << boardTopTwo << endl;

	for (int i = 0; i < rows; i++)
	{
		cout << "|";

		for (int j = 0; j < cols; j++)
		{
			cout << boardTwo[i][j];
			if (i == 0)
			{
				cout << "|";
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)
			{
				cout << "|";
			}

			else
			{
				cout << " ";
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)
		{
			cout << endl << boardTopTwo << endl;
		}
		else
		{
			cout << endl;
			for (int j = 0; j < cols; j++)
			{
				if (j == 0)
				{
					cout << "|---|";
				}
				else if (j == 3 || j == 6 || j == 9)
				{
					cout << "           |";
				}
			}
			cout << endl;
		}

	}

	cout << endl << endl;






	cout << endl << endl << endl;





	system("pause");
	return 0;
}

