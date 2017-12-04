// The first function Main will access is "puzzleSize". This will ask which size puzzle to play.

// Second function Main will access is "difficulty". This will ask which difficulty to play.

// Using these two choices together, Main will access 1 of 9 functions "small puzzle, easy difficulty = easy4x4()".

// These functions will display 3 different puzzles, and every puzzle is different across all difficulties.

// The user chooses a puzzle out of these choices, and goes straight into the appropriate playGame() function
// from the function they selected a puzzle in.

// Inside the playSmallGame function, for example, only the selected puzzle will appear, along with
// user input such as which row, column, and number to enter in chosen cell.



#include "stdafx.h"
#include "iostream"
#include "string"
#include <sstream>

using namespace std;

//======== PROTOTYPES =========
string puzzleSize(string &);    //--- not sure if referencing was done right, or if was even necessary. I(Michael) suck with them.
string difficulty(string &);
void easy4x4();                 //--- these 9 will not be passed anything,
void med4x4();                  //--- they only show puzzles to choose from
void hard4x4();                 //--- and will access their related playGame() function
void easy6x6();
void med6x6();
void hard6x6();
void easy9x9();
void med9x9();
void hard9x9();
void playSmallGame(string[][5], string[][5], string, string, string, int, int);
void playMedGame(string[][7], string[][7], const int, const int);
void playLargeGame(string[][10], string[][10], string, string, int, int);
void SmallGamesolution(string[][5], string[][5], string, string, string, int, int);
void mediumGameSolution();
void largeGameSolution(string[][10], string[][10], string, string, int, int, int, bool);

int main()
{
	string choiceOne;                                  //--- store puzzle size choice
	string choiceTwo;                                  //--- store puzzle difficulty choice

	puzzleSize(choiceOne);                             //--- go to puzzleSize function
	difficulty(choiceTwo);                             //--- go to difficulty function

	if (choiceOne == "1" && choiceTwo == "1")          //--- if "small puzzle" and "easy" was chosen...
	{
		easy4x4();                                     //--- enter easy4x4 function
	}
	if (choiceOne == "1" && choiceTwo == "2")          //--- if "small" and "medium"...
	{
		med4x4();                                      //--- enter med4x4 function, etc.
	}
	if (choiceOne == "1" && choiceTwo == "3")
	{
		hard4x4();
	}
	if (choiceOne == "2" && choiceTwo == "1")
	{
		easy6x6();
	}
	if (choiceOne == "2" && choiceTwo == "2")
	{
		med6x6();
	}
	if (choiceOne == "2" && choiceTwo == "3")
	{
		hard6x6();
	}
	if (choiceOne == "3" && choiceTwo == "1")
	{
		easy9x9();
	}
	if (choiceOne == "3" && choiceTwo == "2")
	{
		med9x9();
	}
	if (choiceOne == "3" && choiceTwo == "3")
	{
		hard9x9();
	}





	system("pause");
	return 0;
}

string puzzleSize(string &choiceOne)
{

	bool valid = false;                                                 //--- flag to get out of check-input loop

	cout << endl;
	cout << "Puzzle Sizes" << endl;                                     //--- puzzle size menu
	cout << "============" << endl;
	cout << "1. 4 x 4" << endl;
	cout << "2. 6 x 6" << endl;
	cout << "3. 9 x 9" << endl;
	cout << "============" << endl;
	cout << "Select a puzzle size: ";
	getline(cin, choiceOne);

	while (valid == false)                                              //--- check-input loop. While bad input, ask again
	{
		if (choiceOne == "1" || choiceOne == "2" || choiceOne == "3")   //--- if good input...
		{
			valid = true;                                               //--- set flag to true to leave loop
		}
		else                                                            //--- otherwise...
		{
			cout << "Invalid input. Please select a number 1-3: ";      //--- ask again
			getline(cin, choiceOne);
		}
	}

	return choiceOne;                                                   //--- send Main choiceOne
}
string difficulty(string &choiceTwo)
{
	bool valid = false;                                                 //--- flag to get out of check-input loop

	cout << endl;
	cout << "Difficulty" << endl;                                       //--- difficulty menu
	cout << "==========" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;
	cout << "==========" << endl;
	cout << "Select a difficulty: ";
	getline(cin, choiceTwo);

	while (valid == false)                                              //--- check-input loop. While bad input, ask again
	{
		if (choiceTwo == "1" || choiceTwo == "2" || choiceTwo == "3")   //--- if good input...
		{
			valid = true;                                               //--- set flag to true to leave loop
		}
		else                                                            //--- otherwise...
		{
			cout << "Invalid input. Please select a number 1-3: ";      //--- ask again
			getline(cin, choiceTwo);
		}
	}

	return choiceTwo;                                                   //--- send Main choiceTwo
}
//================Elise Borbely Start====================================
void easy4x4()
{
	system("CLS");                                                      //--- clear screen
	string boardChoice;                                                 //--- user's board selection
	bool valid = false;                                                 //--- check-input flag

	const int rows = 5;                                                 //--- small board dimensions
	const int cols = 5;

	const string num1 = "[1]";                                          //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";

	string boardTop = "=====================";                          //--- small board top border / block divider
	string boardMid = "|===|=======|=======|";                          //--- small board mid border / block divider

	string boardOne[rows][cols] =                                       //--- puzzle arrays
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " , "   " , "   " ,  num3 },
		{ " 2 " , "   " ,  num2 ,  num1 , "   " },
		{ " 3 " , "   " ,  num4 ,  num3 , "   " },
		{ " 4 " ,  num2 , "   " , "   " , "   " }
	};

	string boardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num4 ,  num1 ,  num2 ,  num3 },
		{ " 2 " ,  num3 ,  num2 ,  num1 ,  num4 },
		{ " 3 " ,  num1 ,  num4 ,  num3 ,  num2 },
		{ " 4 " ,  num2 ,  num3 ,  num4 ,  num1 }
	};

	string boardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " ,  num4 ,  num1 , "   " },
		{ " 2 " , "   " , "   " , "   " ,  num4 },
		{ " 3 " ,  num2 , "   " , "   " , "   " },
		{ " 4 " , "   " ,  num3 ,  num2 , "   " }
	};

	string boardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num3 ,  num4 ,  num1 ,  num2 },
		{ " 2 " ,  num1 ,  num2 ,  num3 ,  num4 },
		{ " 3 " ,  num2 ,  num1 ,  num4 ,  num3 },
		{ " 4 " ,  num4 ,  num3 ,  num2 ,  num1 }
	};

	string boardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num1 , "   " , "   " ,  num2 },
		{ " 2 " , "   " ,  num2 , "   " , "   " },
		{ " 3 " , "   " , "   " ,  num3 , "   " },
		{ " 4 " ,  num3 , "   " , "   " ,  num4 }
	};

	string boardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num1 ,  num3 ,  num4 ,  num2 },
		{ " 2 " ,  num4 ,  num2 ,  num1 ,  num3 },
		{ " 3 " ,  num2 ,  num4 ,  num3 ,  num1 },
		{ " 4 " ,  num3 ,  num1 ,  num2 ,  num4 }
	};


	//============ GENERATING THE BOARDS SIDE BY SIDE =============
	cout << endl;
	cout << "      PUZZLE 1                 PUZZLE 2                 PUZZLE 3      " << endl;            //---- puzzle headers
	cout << boardTop << "    " << boardTop << "    " << boardTop << "    " << endl;                      //---- print top of each board
	for (int i = 0; i < rows; i++)                                                                       //---- main rows loop (do the following per entire row)
	{
		cout << "|";                                                               //---- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                             //---- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << boardOne[i][j];                                                //---- (puzzle 1) print puzzle 1's elements
			if (i == 0)                                                            //---- (puzzle 1) if first row...
			{
				cout << "|";                                                       //---- (puzzle 1) print right-side wall of each cell, will close last cell (prints column header dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last element in current row...
				{
					cout << "    ";                                                //---- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 4; ii++)                                      //---- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                           //---- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << boardTwo[ii][jj];                                          //---- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                       //---- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                   //---- (puzzle 2) print column header dividers
								if (jj == 4)                                                   //---- (puzzle 2) if last element of first row...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 4; iii++)                               //---- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                       //---- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                               //---- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << boardThree[iii][jjj];                                  //---- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                                  //---- (puzzle 3) if first row...
											{
												cout << "|";                                               //---- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 2 || j == 4)                                   //---- (puzzle 1) if not first row, but is column 0, 2, or 4...
			{
				cout << "|";                                                       //---- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "    |";                                               //---- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                          //---- (puzzle 2) loop for puzzle 2's contents
					{
						cout << boardTwo[i][jj];                                               //---- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 2 || jj == 4)                                     //---- (puzzle 2) if column 0, 2, or 4...
						{
							cout << "|";                                                       //---- (puzzle 2) print wall
							if (jj == 4)                                                       //---- (puzzle 2) if column 4...
							{
								cout << "    |";                                               //---- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                       //---- (puzzle 3) loop for puzzle 3's contents
								{
									cout << boardThree[i][jjj];                                            //---- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 2 || jjj == 4)                                  //---- (puzzle 3) if column 0, 2, or 4...
									{
										cout << "|";                                                       //---- (puzzle 3) print wall
									}
									else                                                                   //---- (puzzle 3) otherwise...
									{
										cout << " ";                                                       //---- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                   //---- (puzzle 2) otherwise...
						{
							cout << " ";                                                       //---- (puzzle 2) print space to even out rows
						}
					}
				}

			}
			else                                                                   //---- (puzzle 1) if not first row, or columns 0, 2, or 4...
			{
				cout << " ";                                                       //---- (puzzle 1) print space to even out rows
			}
		}
		if (i == 0 || i == 2 || i == 4)                                //---- if row 0, 2, or 4, print boardTop to separate blocks
		{
			if (i == 0 || i == 2)
			{
				cout << endl << boardMid << "    " << boardMid << "    " << boardMid << endl;
			}
			else if (i == 4)
			{
				cout << endl << boardTop << "    " << boardTop << "    " << boardTop << endl; //---- print boardTop to separate blocks
			}
		}
		else                                                           //---- otherwise...
		{
			cout << endl;                                              //---- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                         //---- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                        //---- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                               //---- (puzzle 1) print row header divider
				}
				else if (j == 2 || j == 4)                                         //---- (puzzle 1) if at column 2 or 4...
				{
					cout << "       |";                                            //---- (puzzle 1) print gap and wall to form borders
					if (j == 4)                                                    //---- (puzzle 1) if at column 4...
					{
						cout << "    ";                                            //---- (puzzle 1 to puzzle 2) print space between puzzles
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                       //---- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                               //---- (puzzle 2) print row header divider
							}
							else if (jj == 2 || jj == 4)                                       //---- (puzzle 2) if at column 2 or 4...
							{
								cout << "       |";                                            //---- (puzzle 2) prrint gap and wall to form borders
								if (jj == 4)                                                   //---- (puzzle 2) if at column 4...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzles
									for (int jjj = 0; jjj < cols; jjj++)                                   //---- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                      //---- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                               //---- (puzzle 3) print row header divider
										}
										else if (jjj == 2 || jjj == 4)                                     //---- (puzzle 3) if at column 2 or 4...
										{
											cout << "       |";                                            //---- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                              //---- once at the end of an empty space row, start new line to print next row of array elements
		}
	}


	//=========== USER INPUT ============
	cout << endl << endl;
	cout << "Select a puzzle to play (1-3): ";
	getline(cin, boardChoice);

	while (valid == false)                                                       //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")      //--- if good input...
		{
			valid = true;                                                        //--- flag to true to leave loop
		}
		else                                                                     //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";                //--- ask again
			getline(cin, boardChoice);
		}
	}
	//--- NOTE: I was sending boardChoice to eventually use it in solution() function. Haven't gone that far.
	if (boardChoice == "1")                                                      //--- if puzzle 1 is chosen...
	{
		playSmallGame(boardOne, boardOneAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function along with board parameters
	}
	if (boardChoice == "2")                                                      //--- if puzzle 2 is chosen...
	{
		playSmallGame(boardTwo, boardTwoAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function
	}
	if (boardChoice == "3")
	{
		playSmallGame(boardThree, boardThreeAnswer, boardTop, boardMid, boardChoice, rows, cols);
	}
}
//==========================Elise Borbely End========================================

//========================Elise Borbely Start=======================================
void med4x4()
{
	system("CLS");                                                      //--- clear screen
	string boardChoice;
	bool valid = false;

	const int rows = 5;
	const int cols = 5;

	const string num1 = "[1]";
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";

	string boardTop = "=====================";
	string boardMid = "|===|=======|=======|";


	string MboardOne[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num4 , "   " , "   " , "   " },
		{ " 2 " , "   " ,  num2 , "   " ,  num1 },
		{ " 3 " , "   " ,  num4 , "   " ,  num2 },
		{ " 4 " ,  num2 , "   " , "   " , "   " }
	};

	string MboardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num4 ,  num1 ,  num2 ,  num3 },
		{ " 2 " ,  num3 ,  num2 ,  num4 ,  num1 },
		{ " 3 " ,  num1 ,  num4 ,  num3 ,  num2 },
		{ " 4 " ,  num2 ,  num3 ,  num1 ,  num4 }
	};

	string MboardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " ,  num1 ,  num3 , "   " },
		{ " 2 " , "   " , "   " , "   " ,  num1 },
		{ " 3 " , "   " , "   " , "   " ,  num3 },
		{ " 4 " , "   " ,  num3 ,  num4 , "   " }
	};

	string MboardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num2 ,  num1 ,  num3 ,  num4 },
		{ " 2 " ,  num3 ,  num4 ,  num2 ,  num1 },
		{ " 3 " ,  num4 ,  num2 ,  num1 ,  num3 },
		{ " 4 " ,  num1 ,  num3 ,  num4 ,  num2 }
	};

	string MboardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " ,  num1 , "   " , "   " },
		{ " 2 " ,  num3 , "   " ,  num1 , "   " },
		{ " 3 " ,  num4 , "   " ,  num3 , "   " },
		{ " 4 " , "   " ,  num3 , "   " , "   " }
	};

	string MboardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num2 ,  num1 ,  num4 ,  num3 },
		{ " 2 " ,  num3 ,  num4 ,  num1 ,  num2 },
		{ " 3 " ,  num4 ,  num2 ,  num3 ,  num1 },
		{ " 4 " ,  num1 ,  num3 ,  num2 ,  num4 }
	};

	//============ GENERATING THE BOARDS SIDE BY SIDE =============
	cout << endl;
	cout << "      PUZZLE 1                 PUZZLE 2                 PUZZLE 3      " << endl;            //---- puzzle headers
	cout << boardTop << "    " << boardTop << "    " << boardTop << "    " << endl;                      //---- print top of each board
	for (int i = 0; i < rows; i++)                                                                       //---- main rows loop (do the following per entire row)
	{
		cout << "|";                                                               //---- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                             //---- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << MboardOne[i][j];                                                //---- (puzzle 1) print puzzle 1's elements
			if (i == 0)                                                            //---- (puzzle 1) if first row...
			{
				cout << "|";                                                       //---- (puzzle 1) print right-side wall of each cell, will close last cell (prints column header dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last element in current row...
				{
					cout << "    ";                                                //---- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 4; ii++)                                      //---- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                           //---- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << MboardTwo[ii][jj];                                          //---- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                       //---- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                   //---- (puzzle 2) print column header dividers
								if (jj == 4)                                                   //---- (puzzle 2) if last element of first row...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 4; iii++)                               //---- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                       //---- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                               //---- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << MboardThree[iii][jjj];                                  //---- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                                  //---- (puzzle 3) if first row...
											{
												cout << "|";                                               //---- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 2 || j == 4)                                   //---- (puzzle 1) if not first row, but is column 0, 2, or 4...
			{
				cout << "|";                                                       //---- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "    |";                                               //---- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                          //---- (puzzle 2) loop for puzzle 2's contents
					{
						cout << MboardTwo[i][jj];                                               //---- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 2 || jj == 4)                                     //---- (puzzle 2) if column 0, 2, or 4...
						{
							cout << "|";                                                       //---- (puzzle 2) print wall
							if (jj == 4)                                                       //---- (puzzle 2) if column 4...
							{
								cout << "    |";                                               //---- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                       //---- (puzzle 3) loop for puzzle 3's contents
								{
									cout << MboardThree[i][jjj];                                            //---- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 2 || jjj == 4)                                  //---- (puzzle 3) if column 0, 2, or 4...
									{
										cout << "|";                                                       //---- (puzzle 3) print wall
									}
									else                                                                   //---- (puzzle 3) otherwise...
									{
										cout << " ";                                                       //---- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                   //---- (puzzle 2) otherwise...
						{
							cout << " ";                                                       //---- (puzzle 2) print space to even out rows
						}
					}
				}

			}
			else                                                                   //---- (puzzle 1) if not first row, or columns 0, 2, or 4...
			{
				cout << " ";                                                       //---- (puzzle 1) print space to even out rows
			}
		}
		if (i == 0 || i == 2 || i == 4)                                //---- if row 0, 2, or 4, print boardTop to separate blocks
		{
			if (i == 0 || i == 2)
			{
				cout << endl << boardMid << "    " << boardMid << "    " << boardMid << endl;
			}
			else if (i == 4)
			{
				cout << endl << boardTop << "    " << boardTop << "    " << boardTop << endl; //---- print boardTop to separate blocks
			}
		}
		else                                                           //---- otherwise...
		{
			cout << endl;                                              //---- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                         //---- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                        //---- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                               //---- (puzzle 1) print row header divider
				}
				else if (j == 2 || j == 4)                                         //---- (puzzle 1) if at column 2 or 4...
				{
					cout << "       |";                                            //---- (puzzle 1) print gap and wall to form borders
					if (j == 4)                                                    //---- (puzzle 1) if at column 4...
					{
						cout << "    ";                                            //---- (puzzle 1 to puzzle 2) print space between puzzles
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                       //---- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                               //---- (puzzle 2) print row header divider
							}
							else if (jj == 2 || jj == 4)                                       //---- (puzzle 2) if at column 2 or 4...
							{
								cout << "       |";                                            //---- (puzzle 2) prrint gap and wall to form borders
								if (jj == 4)                                                   //---- (puzzle 2) if at column 4...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzles
									for (int jjj = 0; jjj < cols; jjj++)                                   //---- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                      //---- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                               //---- (puzzle 3) print row header divider
										}
										else if (jjj == 2 || jjj == 4)                                     //---- (puzzle 3) if at column 2 or 4...
										{
											cout << "       |";                                            //---- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                              //---- once at the end of an empty space row, start new line to print next row of array elements
		}
	}


	//=========== USER INPUT ============
	cout << endl << endl;
	cout << "Select a puzzle to play (1-3): ";
	getline(cin, boardChoice);

	while (valid == false)                                                       //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")      //--- if good input...
		{
			valid = true;                                                        //--- flag to true to leave loop
		}
		else                                                                     //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";                //--- ask again
			getline(cin, boardChoice);
		}
	}
	//--- NOTE: I was sending boardChoice to eventually use it in solution() function. Haven't gone that far.
	if (boardChoice == "1")                                                      //--- if puzzle 1 is chosen...
	{
		playSmallGame(MboardOne, MboardOneAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function along with board parameters
	}
	if (boardChoice == "2")                                                      //--- if puzzle 2 is chosen...
	{
		playSmallGame(MboardTwo, MboardTwoAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function
	}
	if (boardChoice == "3")
	{
		playSmallGame(MboardThree, MboardThreeAnswer, boardTop, boardMid, boardChoice, rows, cols);
	}
}
//=========================Elise Borbely End=================================

//=======================Elise Borbely Start================================
void hard4x4()
{
	system("CLS");                                                      //--- clear screen
	string boardChoice;
	bool valid = false;

	const int rows = 5;
	const int cols = 5;

	const string num1 = "[1]";
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";

	string boardTop = "=====================";
	string boardMid = "|===|=======|=======|";

	string HboardOne[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " ,  num3 , "   " , "   " },
		{ " 2 " ,  num4 , "   " , "   " , "   " },
		{ " 3 " , "   " , "   " , "   " ,  num1 },
		{ " 4 " ,  num3 , "   " ,  num2 , "   " }
	};

	string HboardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num1 ,  num3 ,  num4 ,  num2 },
		{ " 2 " ,  num4 ,  num2 ,  num1 ,  num3 },
		{ " 3 " ,  num2 ,  num4 ,  num3 ,  num1 },
		{ " 4 " ,  num3 ,  num1 ,  num2 ,  num4 }
	};

	string HboardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " ,  num2 ,  num4 , "   " },
		{ " 2 " ,  num1 , "   " , "   " , "   " },
		{ " 3 " , "   " , "   " , "   " ,  num4 },
		{ " 4 " , "   " , "   " ,  num3 , "   " }
	};

	string HboardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num3 ,  num2 ,  num4 ,  num1 },
		{ " 2 " ,  num1 ,  num4 ,  num2 ,  num3 },
		{ " 3 " ,  num2 ,  num3 ,  num1 ,  num4 },
		{ " 4 " ,  num4 ,  num1 ,  num3 ,  num2 }
	};

	string HboardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num4 , "   " , "   " ,  num2 },
		{ " 2 " , "   " ,  num2 , "   " , "   " },
		{ " 3 " , "   " , "   " ,  num3 , "   " },
		{ " 4 " , "   " , "   " , "   " ,  num1 }
	};

	string HboardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " ,  num4 ,  num3 ,  num1 ,  num2 },
		{ " 2 " ,  num1 ,  num2 ,  num4 ,  num3 },
		{ " 3 " ,  num2 ,  num1 ,  num3 ,  num4 },
		{ " 4 " ,  num3 ,  num4 ,  num2 ,  num1 }
	};

	//============ GENERATING THE BOARDS SIDE BY SIDE =============
	cout << endl;
	cout << "      PUZZLE 1                 PUZZLE 2                 PUZZLE 3      " << endl;            //---- puzzle headers
	cout << boardTop << "    " << boardTop << "    " << boardTop << "    " << endl;                      //---- print top of each board
	for (int i = 0; i < rows; i++)                                                                       //---- main rows loop (do the following per entire row)
	{
		cout << "|";                                                               //---- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                             //---- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << HboardOne[i][j];                                                //---- (puzzle 1) print puzzle 1's elements
			if (i == 0)                                                            //---- (puzzle 1) if first row...
			{
				cout << "|";                                                       //---- (puzzle 1) print right-side wall of each cell, will close last cell (prints column header dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last element in current row...
				{
					cout << "    ";                                                //---- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 4; ii++)                                      //---- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                           //---- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << HboardTwo[ii][jj];                                          //---- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                       //---- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                   //---- (puzzle 2) print column header dividers
								if (jj == 4)                                                   //---- (puzzle 2) if last element of first row...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 4; iii++)                               //---- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                       //---- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                               //---- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << HboardThree[iii][jjj];                                  //---- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                                  //---- (puzzle 3) if first row...
											{
												cout << "|";                                               //---- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 2 || j == 4)                                   //---- (puzzle 1) if not first row, but is column 0, 2, or 4...
			{
				cout << "|";                                                       //---- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 4)                                                        //---- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "    |";                                               //---- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                          //---- (puzzle 2) loop for puzzle 2's contents
					{
						cout << HboardTwo[i][jj];                                               //---- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 2 || jj == 4)                                     //---- (puzzle 2) if column 0, 2, or 4...
						{
							cout << "|";                                                       //---- (puzzle 2) print wall
							if (jj == 4)                                                       //---- (puzzle 2) if column 4...
							{
								cout << "    |";                                               //---- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                       //---- (puzzle 3) loop for puzzle 3's contents
								{
									cout << HboardThree[i][jjj];                                            //---- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 2 || jjj == 4)                                  //---- (puzzle 3) if column 0, 2, or 4...
									{
										cout << "|";                                                       //---- (puzzle 3) print wall
									}
									else                                                                   //---- (puzzle 3) otherwise...
									{
										cout << " ";                                                       //---- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                   //---- (puzzle 2) otherwise...
						{
							cout << " ";                                                       //---- (puzzle 2) print space to even out rows
						}
					}
				}

			}
			else                                                                   //---- (puzzle 1) if not first row, or columns 0, 2, or 4...
			{
				cout << " ";                                                       //---- (puzzle 1) print space to even out rows
			}
		}
		if (i == 0 || i == 2 || i == 4)                                //---- if row 0, 2, or 4, print boardTop to separate blocks
		{
			if (i == 0 || i == 2)
			{
				cout << endl << boardMid << "    " << boardMid << "    " << boardMid << endl;
			}
			else if (i == 4)
			{
				cout << endl << boardTop << "    " << boardTop << "    " << boardTop << endl; //---- print boardTop to separate blocks
			}
		}
		else                                                           //---- otherwise...
		{
			cout << endl;                                              //---- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                         //---- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                        //---- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                               //---- (puzzle 1) print row header divider
				}
				else if (j == 2 || j == 4)                                         //---- (puzzle 1) if at column 2 or 4...
				{
					cout << "       |";                                            //---- (puzzle 1) print gap and wall to form borders
					if (j == 4)                                                    //---- (puzzle 1) if at column 4...
					{
						cout << "    ";                                            //---- (puzzle 1 to puzzle 2) print space between puzzles
						for (int jj = 0; jj < cols; jj++)                                      //---- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                       //---- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                               //---- (puzzle 2) print row header divider
							}
							else if (jj == 2 || jj == 4)                                       //---- (puzzle 2) if at column 2 or 4...
							{
								cout << "       |";                                            //---- (puzzle 2) prrint gap and wall to form borders
								if (jj == 4)                                                   //---- (puzzle 2) if at column 4...
								{
									cout << "    ";                                            //---- (puzzle 2 to puzzle 3) print space between puzzles
									for (int jjj = 0; jjj < cols; jjj++)                                   //---- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                      //---- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                               //---- (puzzle 3) print row header divider
										}
										else if (jjj == 2 || jjj == 4)                                     //---- (puzzle 3) if at column 2 or 4...
										{
											cout << "       |";                                            //---- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                              //---- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	//=========== USER INPUT ============
	cout << endl << endl;
	cout << "Select a puzzle to play (1-3): ";
	getline(cin, boardChoice);

	while (valid == false)                                                       //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")      //--- if good input...
		{
			valid = true;                                                        //--- flag to true to leave loop
		}
		else                                                                     //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";                //--- ask again
			getline(cin, boardChoice);
		}
	}
	//--- NOTE: I was sending boardChoice to eventually use it in solution() function. Haven't gone that far.
	if (boardChoice == "1")                                                      //--- if puzzle 1 is chosen...
	{
		playSmallGame(HboardOne, HboardOneAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function along with board parameters
	}
	if (boardChoice == "2")                                                      //--- if puzzle 2 is chosen...
	{
		playSmallGame(HboardTwo, HboardTwoAnswer, boardTop, boardMid, boardChoice, rows, cols);              //--- send it to playSmallGame function
	}
	if (boardChoice == "3")
	{
		playSmallGame(HboardThree, HboardThreeAnswer, boardTop, boardMid, boardChoice, rows, cols);
	}
}
//============================Elise Borbely End=====================================================

//===========================Trevor Ruelle Start==================================
void easy6x6()
{
	system("CLS");
	const string num1 = "[1]", num2 = "[2]", num3 = "[3]", num4 = "[4]",
		num5 = "[5]", num6 = "[6]";
	const int row = 7, col = 7;
	string choice;
	bool valid = false;

	string board_One[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_One_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Two[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Two_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Three[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Three_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };


	string boardTop = "=============================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "           PUZZLE 1                           PUZZLE 2                             PUZZLE 3             " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < row; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < col; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << board_One[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < row - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << board_Two[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 6)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < row - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < col; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << board_Three[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < col; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << board_Two[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 6)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < col; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << board_Three[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 2 || i == 4 || i == 6)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 2 || i == 4 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 6)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < col; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 6)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 6)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < col; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;



	cout << "Select a puzzle to play: ";
	getline(cin, choice);

	while (valid == false)
	{
		if (choice == "1" || choice == "2" || choice == "3")
		{
			valid = true;
		}
		else
		{
			cout << "Incorrect input, please try again: ";
			getline(cin, choice);
		}
	}

	if (choice == "1")
	{
		playMedGame(board_One, board_One_Answer, row, col);
	}
	if (choice == "2")
	{
		playMedGame(board_Two, board_Two_Answer, row, col);
	}
	if (choice == "3")
	{
		playMedGame(board_Three, board_Three_Answer, row, col);
	}


}
void med6x6()
{
	system("CLS");
	const string num1 = "[1]", num2 = "[2]", num3 = "[3]", num4 = "[4]",
		num5 = "[5]", num6 = "[6]";
	const int row = 7, col = 7;
	string choice;
	bool valid = false;

	string board_One[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_One_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Two[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Two_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Three[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Three_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };


	string boardTop = "=============================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "           PUZZLE 1                           PUZZLE 2                             PUZZLE 3             " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < row; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < col; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << board_One[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < row - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << board_Two[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 6)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < row - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < col; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << board_Three[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < col; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << board_Two[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 6)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < col; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << board_Three[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 2 || i == 4 || i == 6)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 2 || i == 4 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 6)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < col; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 6)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 6)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < col; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;




	cout << "Select a puzzle to play: ";
	getline(cin, choice);

	while (valid == false)
	{
		if (choice == "1" || choice == "2" || choice == "3")
		{
			valid = true;
		}
		else
		{
			cout << "Incorrect input, please try again: ";
			getline(cin, choice);
		}
	}

	if (choice == "1")
	{
		playMedGame(board_One, board_One_Answer, col, row);
	}
	if (choice == "2")
	{
		playMedGame(board_Two, board_Two_Answer, col, row);
	}
	if (choice == "3")
	{
		playMedGame(board_Three, board_Three_Answer, col, row);
	}


}
void hard6x6()
{
	system("CLS");
	const string num1 = "[1]", num2 = "[2]", num3 = "[3]", num4 = "[4]",
		num5 = "[5]", num6 = "[6]";
	const int row = 7, col = 7;
	string choice;
	bool valid = false;

	string board_One[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_One_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Two[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Two_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };

	string board_Three[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, "   ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", "   " } };

	string board_Three_Answer[row][col] = {
		{ "   ", " A ", " B ", " C ", " D ", " E ", " F " },
		{ " 1 ", num1 , " 4 ", " 5 ",  num2, num3 ,  num6 },
		{ " 2 ", " 2 ", " 6 ", " 3 ",  num5, num1 , " 4 " },
		{ " 3 ", num4 , num3 , " 2 ",  num6, " 5 ",  num1 },
		{ " 4 ", num5 , num1 , " 6 ", " 3 ", num4 ,  num2 },
		{ " 5 ", " 3 ", " 2 ", num4 ,  num1, num6 ,  num5 },
		{ " 6 ", num6 , num5 , num1 ,  num4, " 2 ", " 3 " } };


	string boardTop = "=============================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "           PUZZLE 1                           PUZZLE 2                             PUZZLE 3             " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < row; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < col; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << board_One[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < row - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << board_Two[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 6)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < row - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < col; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << board_Three[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 6)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < col; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << board_Two[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 6)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < col; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << board_Three[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 2 || i == 4 || i == 6)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 2 || i == 4 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 6)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < col; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 6)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < col; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 6)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < col; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;




	cout << "Select a puzzle to play: ";
	getline(cin, choice);

	while (valid == false)
	{
		if (choice == "1" || choice == "2" || choice == "3")
		{
			valid = true;
		}
		else
		{
			cout << "Incorrect input, please try again: ";
			getline(cin, choice);
		}
	}

	if (choice == "1")
	{
		playMedGame(board_One, board_One_Answer, col, row);
	}
	if (choice == "2")
	{
		playMedGame(board_Two, board_Two_Answer, col, row);
	}
	if (choice == "3")
	{
		playMedGame(board_Three, board_Three_Answer, col, row);
	}

}

//========================= Trevor Ruelle End====================================

//======================== MICHAEL APPERSON START =============================
void easy9x9()
{
	system("CLS");                                                               //--- clear screen
	string boardChoice;                                                          //--- user's puzzle choice
	bool valid = false;                                                          //--- check-input flag

	const int rows = 10;                                                         //--- large board dimensions
	const int cols = 10;

	const string num1 = "[1]";                                                   //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";
	const string num5 = "[5]";
	const string num6 = "[6]";
	const string num7 = "[7]";
	const string num8 = "[8]";
	const string num9 = "[9]";

	string boardOne[rows][cols] = {
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num4  , "   " , num1  , num2  , num9  , "   " , "   " , num7  , num5 },
		{ " 2 " , num2  , "   " , "   " , num3  , "   " , "   " , num8  , "   " , "   " },
		{ " 3 " , "   " , num7  , "   " , "   " , num8  , "   " , "   " , "   " , num6 },
		{ " 4 " , "   " , "   " , "   " , num1  , "   " , num3  , "   " , num6  , num2 },
		{ " 5 " , num1  , "   " , num5  , "   " , "   " , "   " , num4  , "   " , num3 },
		{ " 6 " , num7  , num3  , "   " , num6  , "   " , num8  , "   " , "   " , "   " },
		{ " 7 " , num6  , "   " , "   " , "   " , num2  , "   " , "   " , num3  , "   " },
		{ " 8 " , "   " , "   " , num7  , "   " , "   " , num1  , "   " , "   " , num4 },
		{ " 9 " , num8  , num9  , "   " , "   " , num6  , num5  , num1  , "   " , num7 }
	};
	string boardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num4  , " 8 " , num1  , num2  , num9  , " 6 " , " 3 " , num7  , num5 },
		{ " 2 " , num2  , " 5 " , " 6 " , num3  , " 1 " , " 7 " , num8  , " 4 " , " 9 " },
		{ " 3 " , " 3 " , num7  , " 9 " , " 5 " , num8  , " 4 " , " 2 " , " 1 " , num6 },
		{ " 4 " , " 9 " , " 4 " , " 8 " , num1  , " 5 " , num3  , " 7 " , num6  , num2 },
		{ " 5 " , num1  , " 6 " , num5  , " 9 " , " 7 " , " 2 " , num4  , " 8 " , num3 },
		{ " 6 " , num7  , num3  , " 2 " , num6  , " 4 " , num8  , " 9 " , " 5 " , " 1 " },
		{ " 7 " , num6  , " 1 " , " 4 " , " 7 " , num2  , " 9 " , " 5 " , num3  , " 8 " },
		{ " 8 " , " 5 " , " 2 " , num7  , " 8 " , " 3 " , num1  , " 6 " , " 9 " , num4 },
		{ " 9 " , num8  , num9  , " 3 " , " 4 " , num6  , num5  , num1  , " 2 " , num7 }
	};

	string boardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num9  , "   " , num2  , "   " , num1  , num7  , num4  , num6  , "   " },
		{ " 2 " , "   " , num1  , "   " , num9  , num4  , "   " , "   " , "   " , "   " },
		{ " 3 " , num3  , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " },
		{ " 4 " , "   " , "   " , num5  , num8  , "   " , "   " , num6  , "   " , num4 },
		{ " 5 " , "   " , num4  , num9  , num3  , "   " , num5  , num7  , num2  , "   " },
		{ " 6 " , num1  , "   " , num3  , "   " , "   " , num4  , num9  , "   " , "   " },
		{ " 7 " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , num5 },
		{ " 8 " , "   " , "   " , "   " , "   " , num3  , num2  , "   " , num4  , "   " },
		{ " 9 " , "   " , num3  , num1  , num6  , num5  , "   " , num2  , "   " , num7 }
	};
	string boardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num9  , " 8 " , num2  , " 5 " , num1  , num7  , num4  , num6  , " 3 " },
		{ " 2 " , " 7 " , num1  , " 6 " , num9  , num4  , " 3 " , " 5 " , " 8 " , " 2 " },
		{ " 3 " , num3  , " 5 " , " 4 " , " 2 " , " 8 " , " 6 " , " 1 " , " 7 " , " 9 " },
		{ " 4 " , " 2 " , " 7 " , num5  , num8  , " 9 " , " 1 " , num6  , " 3 " , num4 },
		{ " 5 " , " 8 " , num4  , num9  , num3  , " 6 " , num5  , num7  , num2  , " 1 " },
		{ " 6 " , num1  , " 6 " , num3  , " 7 " , " 2 " , num4  , num9  , " 5 " , " 8 " },
		{ " 7 " , " 6 " , " 2 " , " 8 " , " 4 " , " 7 " , " 9 " , " 3 " , " 1 " , num5 },
		{ " 8 " , " 5 " , " 9 " , " 7 " , " 1 " , num3  , num2  , " 8 " , num4  , " 6 " },
		{ " 9 " , " 4 " , num3  , num1  , num6  , num5  , " 8 " , num2  , " 9 " , num7 }
	};

	string boardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num8  , "   " , "   " , "   " , num9  , "   " , num6  , "   " , "   " },
		{ " 2 " , "   " , "   " , num4  , num1  , num5  , num6  , num8  , "   " , "   " },
		{ " 3 " , "   " , num6  , num5  , "   " , "   " , num8  , "   " , "   " , "   " },
		{ " 4 " , num5  , "   " , "   " , num3  , num6  , "   " , num2  , "   " , "   " },
		{ " 5 " , num9  , "   " , num8  , "   " , "   " , "   " , num1  , "   " , num6 },
		{ " 6 " , "   " , "   " , num7  , "   " , num1  , num9  , "   " , "   " , num4 },
		{ " 7 " , "   " , "   " , "   " , num9  , "   " , "   " , num7  , num1  , "   " },
		{ " 8 " , "   " , "   " , num9  , num2  , num7  , num5  , num4  , "   " , "   " },
		{ " 9 " , "   " , "   " , num2  , "   " , num4  , "   " , "   " , "   " , num9 }
	};
	string boardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num8  , " 1 " , " 3 " , " 7 " , num9  , " 2 " , num6  , " 4 " , " 5 " },
		{ " 2 " , " 2 " , " 9 " , num4  , num1  , num5  , num6  , num8  , " 3 " , " 7 " },
		{ " 3 " , " 7 " , num6  , num5  , " 4 " , " 3 " , num8  , " 9 " , " 2 " , " 1 " },
		{ " 4 " , num5  , " 4 " , " 1 " , num3  , num6  , " 7 " , num2  , " 9 " , " 8 " },
		{ " 5 " , num9  , " 3 " , num8  , " 5 " , " 2 " , " 4 " , num1  , " 7 " , num6 },
		{ " 6 " , " 6 " , " 2 " , num7  , " 8 " , num1  , num9  , " 3 " , " 5 " , num4 },
		{ " 7 " , " 4 " , " 5 " , " 6 " , num9  , " 8 " , " 3 " , num7  , num1  , " 2 " },
		{ " 8 " , " 1 " , " 8 " , num9  , num2  , num7  , num5  , num4  , " 6 " , " 3 " },
		{ " 9 " , " 3 " , " 7 " , num2  , " 6 " , num4  , " 1 " , " 5 " , " 8 " , num9 }
	};


	string boardTop = "=========================================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "                PUZZLE 1                                        PUZZLE 2                                        PUZZLE 3                 " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < rows; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << boardOne[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << boardTwo[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 9)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << boardThree[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << boardTwo[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 9)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << boardThree[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 3 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 9)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 9)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 9)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < cols; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;

	cout << "Select a puzzle to play (1-3): ";                                  //--- user selects a puzzle
	getline(cin, boardChoice);

	while (valid == false)                                                      //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")     //--- if good input...
		{
			valid = true;                                                       //--- set flag to true
		}
		else                                                                    //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";               //--- ask again
			getline(cin, boardChoice);
		}
	}

	if (boardChoice == "1")                                                     //--- if puzzle 1 chosen...
	{
		playLargeGame(boardOne, boardOneAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function
	}
	if (boardChoice == "2")                                                     //--- if puzzle 2...
	{
		playLargeGame(boardTwo, boardTwoAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function, etc.
	}
	if (boardChoice == "3")
	{
		playLargeGame(boardThree, boardThreeAnswer, boardTop, boardMid, rows, cols);
	}

}
void med9x9()
{
	system("CLS");                                                               //--- clear screen
	string boardChoice;                                                          //--- user's puzzle choice
	bool valid = false;                                                          //--- check-input flag

	const int rows = 10;                                                         //--- large board dimensions
	const int cols = 10;

	const string num1 = "[1]";                                                   //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";
	const string num5 = "[5]";
	const string num6 = "[6]";
	const string num7 = "[7]";
	const string num8 = "[8]";
	const string num9 = "[9]";

	string boardOne[rows][cols] = {
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , "   " , "   " , "   " , num9  , "   " , "   " , num5  , "   " , "   " },
		{ " 2 " , "   " , "   " , num2  , "   " , num3  , "   " , num9  , num1  , "   " },
		{ " 3 " , num9  , "   " , "   " , "   " , num8  , num5  , num2  , "   " , num6 },
		{ " 4 " , num8  , "   " , "   " , "   " , num7  , "   " , "   " , "   " , num4 },
		{ " 5 " , "   " , "   " , num4  , num3  , "   " , num6  , num1  , "   " , "   " },
		{ " 6 " , num6  , "   " , "   " , "   " , num9  , "   " , "   " , "   " , num5 },
		{ " 7 " , num2  , "   " , num5  , num8  , num6  , "   " , "   " , "   " , num1 },
		{ " 8 " , "   " , num6  , num7  , "   " , num1  , "   " , num8  , "   " , "   " },
		{ " 9 " , "   " , "   " , num8  , "   " , "   " , num2  , "   " , "   " , "   " }
	};
	string boardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , " 1 " , " 4 " , " 6 " , num9  , " 2 " , " 7 " , num5  , " 8 " , " 3 " },
		{ " 2 " , " 5 " , " 8 " , num2  , " 6 " , num3  , " 4 " , num9  , num1  , " 7 " },
		{ " 3 " , num9  , " 7 " , " 3 " , " 1 " , num8  , num5  , num2  , " 4 " , num6 },
		{ " 4 " , num8  , " 5 " , " 9 " , " 2 " , num7  , " 1 " , " 3 " , " 6 " , num4 },
		{ " 5 " , " 7 " , " 2 " , num4  , num3  , " 5 " , num6  , num1  , " 9 " , " 8 " },
		{ " 6 " , num6  , " 3 " , " 1 " , " 4 " , num9  , " 8 " , " 7 " , " 2 " , num5 },
		{ " 7 " , num2  , " 9 " , num5  , num8  , num6  , " 3 " , " 4 " , " 7 " , num1 },
		{ " 8 " , " 4 " , num6  , num7  , " 5 " , num1  , " 9 " , num8  , " 3 " , " 2 " },
		{ " 9 " , " 3 " , " 1 " , num8  , " 7 " , " 4 " , num2  , " 6 " , " 5 " , " 9 " }
	};

	string boardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num2  , "   " , num3  , "   " , num9  , num7  , "   " , "   " , num8 },
		{ " 2 " , "   " , num7  , "   " , num6  , num8  , "   " , "   " , num2  , "   " },
		{ " 3 " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " },
		{ " 4 " , "   " , "   " , "   " , "   " , num2  , num3  , num1  , "   " , "   " },
		{ " 5 " , "   " , "   " , num9  , num1  , num4  , num6  , num8  , "   " , "   " },
		{ " 6 " , "   " , "   " , num4  , num9  , num5  , "   " , "   " , "   " , "   " },
		{ " 7 " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , "   " },
		{ " 8 " , "   " , num9  , "   " , "   " , num7  , num5  , "   " , num6  , "   " },
		{ " 9 " , num8  , "   " , "   " , num2  , num1  , "   " , num5  , "   " , num4 }
	};
	string boardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num2  , " 4 " , num3  , " 5 " , num9  , num7  , " 6 " , " 1 " , num8 },
		{ " 2 " , " 9 " , num7  , " 5 " , num6  , num8  , " 1 " , " 4 " , num2  , " 3 " },
		{ " 3 " , " 6 " , " 8 " , " 1 " , " 4 " , " 3 " , " 2 " , " 7 " , " 9 " , " 5 " },
		{ " 4 " , " 5 " , " 6 " , " 8 " , " 7 " , num2  , num3  , num1  , " 4 " , " 9 " },
		{ " 5 " , " 3 " , " 2 " , num9  , num1  , num4  , num6  , num8  , " 5 " , " 7 " },
		{ " 6 " , " 7 " , " 1 " , num4  , num9  , num5  , " 8 " , " 2 " , " 3 " , " 6 " },
		{ " 7 " , " 1 " , " 5 " , " 7 " , " 3 " , " 6 " , " 4 " , " 9 " , " 8 " , " 2 " },
		{ " 8 " , " 4 " , num9  , " 2 " , " 8 " , num7  , num5  , " 3 " , num6  , " 1 " },
		{ " 9 " , num8  , " 3 " , " 6 " , num2  , num1  , " 9 " , num5  , " 7 " , num4 }
	};

	string boardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , "   " , "   " , "   " , "   " , "   " , num7  , num9  , num5  , "   " },
		{ " 2 " , num7  , "   " , num3  , "   " , num5  , "   " , "   " , "   " , num2 },
		{ " 3 " , "   " , "   " , "   " , "   " , num6  , num4  , "   " , num3  , "   " },
		{ " 4 " , "   " , num9  , "   " , "   " , "   " , "   " , num2  , "   " , num8 },
		{ " 5 " , "   " , num6  , "   " , "   " , "   " , "   " , "   " , num9  , "   " },
		{ " 6 " , num4  , "   " , num7  , "   " , "   " , "   " , "   " , num1  , "   " },
		{ " 7 " , "   " , num3  , "   " , num8  , num4  , "   " , "   " , "   " , "   " },
		{ " 8 " , num5  , "   " , "   " , "   " , num1  , "   " , num4  , "   " , num3 },
		{ " 9 " , "   " , num4  , num1  , num7  , "   " , "   " , "   " , "   " , "   " }
	};
	string boardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , " 6 " , " 8 " , " 4 " , " 3 " , " 2 " , num7  , num9  , num5  , " 1 " },
		{ " 2 " , num7  , " 1 " , num3  , " 9 " , num5  , " 8 " , " 6 " , " 4 " , num2 },
		{ " 3 " , " 9 " , " 5 " , " 2 " , " 1 " , num6  , num4  , " 8 " , num3  , " 7 " },
		{ " 4 " , " 3 " , num9  , " 5 " , " 4 " , " 7 " , " 1 " , num2  , " 6 " , num8 },
		{ " 5 " , " 1 " , num6  , " 8 " , " 5 " , " 3 " , " 2 " , " 7 " , num9  , " 4 " },
		{ " 6 " , num4  , " 2 " , num7  , " 6 " , " 8 " , " 9 " , " 3 " , num1  , " 5 " },
		{ " 7 " , " 2 " , num3  , " 6 " , num8  , num4  , " 5 " , " 1 " , " 7 " , " 9 " },
		{ " 8 " , num5  , " 7 " , " 9 " , " 2 " , num1  , " 6 " , num4  , " 8 " , num3 },
		{ " 9 " , " 8 " , num4  , num1  , num7  , " 9 " , " 3 " , " 5 " , " 2 " , " 6 " }
	};


	string boardTop = "=========================================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "                PUZZLE 1                                        PUZZLE 2                                        PUZZLE 3                 " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < rows; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << boardOne[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << boardTwo[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 9)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << boardThree[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << boardTwo[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 9)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << boardThree[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 3 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 9)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 9)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 9)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < cols; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;

	cout << "Select a puzzle to play (1-3): ";                                  //--- user selects a puzzle
	getline(cin, boardChoice);

	while (valid == false)                                                      //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")     //--- if good input...
		{
			valid = true;                                                       //--- set flag to true
		}
		else                                                                    //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";               //--- ask again
			getline(cin, boardChoice);
		}
	}

	if (boardChoice == "1")                                                     //--- if puzzle 1 chosen...
	{
		playLargeGame(boardOne, boardOneAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function
	}
	if (boardChoice == "2")                                                     //--- if puzzle 2...
	{
		playLargeGame(boardTwo, boardTwoAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function, etc.
	}
	if (boardChoice == "3")
	{
		playLargeGame(boardThree, boardThreeAnswer, boardTop, boardMid, rows, cols);
	}
}
void hard9x9()
{
	system("CLS");                                                               //--- clear screen
	string boardChoice;                                                          //--- user's puzzle choice
	bool valid = false;                                                          //--- check-input flag

	const int rows = 10;                                                         //--- large board dimensions
	const int cols = 10;

	const string num1 = "[1]";                                                   //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";
	const string num5 = "[5]";
	const string num6 = "[6]";
	const string num7 = "[7]";
	const string num8 = "[8]";
	const string num9 = "[9]";

	string boardOne[rows][cols] = {
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , "   " , "   " , num3  , num9  , num6  , "   " , "   " , num4  , "   " },
		{ " 2 " , "   " , num7  , "   " , "   " , "   " , "   " , "   " , num2  , num9 },
		{ " 3 " , "   " , "   " , "   " , "   " , num8  , "   " , num1  , "   " , "   " },
		{ " 4 " , "   " , "   " , "   " , "   " , "   " , num6  , "   " , "   " , "   " },
		{ " 5 " , num1  , "   " , num2  , "   " , num5  , "   " , num6  , "   " , num4 },
		{ " 6 " , "   " , "   " , "   " , num7  , "   " , "   " , "   " , "   " , "   " },
		{ " 7 " , "   " , "   " , num7  , "   " , num3  , "   " , "   " , "   " , "   " },
		{ " 8 " , num2  , num5  , "   " , "   " , "   " , "   " , "   " , num1  , "   " },
		{ " 9 " , "   " , num3  , "   " , "   " , num4  , num9  , num8  , "   " , "   " }
	};
	string boardOneAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , " 5 " , " 1 " , num3  , num9  , num6  , " 2 " , " 7 " , num4  , " 8 " },
		{ " 2 " , " 8 " , num7  , " 6 " , " 4 " , " 1 " , " 5 " , " 3 " , num2  , num9 },
		{ " 3 " , " 9 " , " 2 " , " 4 " , " 3 " , num8  , " 7 " , num1  , " 6 " , " 5 " },
		{ " 4 " , " 7 " , " 4 " , " 8 " , " 1 " , " 9 " , num6  , " 5 " , " 3 " , " 2 " },
		{ " 5 " , num1  , " 9 " , num2  , " 8 " , num5  , " 3 " , num6  , " 7 " , num4 },
		{ " 6 " , " 3 " , " 6 " , " 5 " , num7  , " 2 " , " 4 " , " 9 " , " 8 " , " 1 " },
		{ " 7 " , " 4 " , " 8 " , num7  , " 5 " , num3  , " 1 " , " 2 " , " 9 " , " 6 " },
		{ " 8 " , num2  , num5  , " 9 " , " 6 " , " 7 " , " 8 " , " 4 " , num1  , " 3 " },
		{ " 9 " , " 6 " , num3  , " 1 " , " 2 " , num4  , num9  , num8  , " 5 " , " 7 " }
	};

	string boardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num1  , num6  , "   " , num3  , num2  , "   " , num4  , "   " , "   " },
		{ " 2 " , "   " , "   " , "   " , "   " , num4  , "   " , "   " , num2  , num9 },
		{ " 3 " , "   " , num2  , "   " , "   " , "   " , "   " , "   " , "   " , "   " },
		{ " 4 " , num9  , "   " , num3  , num4  , "   " , "   " , num7  , "   " , "   " },
		{ " 5 " , "   " , "   " , num4  , "   " , "   " , "   " , num6  , "   " , "   " },
		{ " 6 " , "   " , "   " , num2  , "   " , "   " , num5  , num3  , "   " , num8 },
		{ " 7 " , "   " , "   " , "   " , "   " , "   " , "   " , "   " , num6  , "   " },
		{ " 8 " , num2  , num3  , "   " , "   " , num9  , "   " , "   " , "   " , "   " },
		{ " 9 " , "   " , "   " , num6  , "   " , num1  , num7  , "   " , num5  , num3 }
	};
	string boardTwoAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , num1  , num6  , " 5 " , num3  , num2  , " 9 " , num4  , " 8 " , " 7 " },
		{ " 2 " , " 3 " , " 7 " , " 8 " , " 6 " , num4  , " 1 " , " 5 " , num2  , num9 },
		{ " 3 " , " 4 " , num2  , " 9 " , " 7 " , " 5 " , " 8 " , " 1 " , " 3 " , " 6 " },
		{ " 4 " , num9  , " 8 " , num3  , num4  , " 6 " , " 2 " , num7  , " 1 " , " 5 " },
		{ " 5 " , " 7 " , " 5 " , num4  , " 1 " , " 8 " , " 3 " , num6  , " 9 " , " 2 " },
		{ " 6 " , " 6 " , " 1 " , num2  , " 9 " , " 7 " , num5  , num3  , " 4 " , num8 },
		{ " 7 " , " 5 " , " 9 " , " 7 " , " 8 " , " 3 " , " 4 " , " 2 " , num6  , " 1 " },
		{ " 8 " , num2  , num3  , " 1 " , " 5 " , num9  , " 6 " , " 8 " , " 7 " , " 4 " },
		{ " 9 " , " 8 " , " 4 " , num6  , " 2 " , num1  , num7  , " 9 " , num5  , num3 }
	};

	string boardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , "   " , "   " , "   " , "   " , num9  , "   " , num5  , "   " , "   " },
		{ " 2 " , "   " , num5  , num9  , num8  , "   " , num1  , "   " , "   " , "   " },
		{ " 3 " , "   " , "   " , num8  , num2  , "   " , "   " , "   " , num6  , "   " },
		{ " 4 " , "   " , num7  , "   " , "   " , num5  , "   " , num3  , "   " , "   " },
		{ " 5 " , "   " , "   " , num5  , "   " , num3  , "   " , num4  , "   " , "   " },
		{ " 6 " , "   " , "   " , num1  , "   " , num8  , "   " , "   " , num9  , "   " },
		{ " 7 " , "   " , num9  , "   " , "   " , "   " , num8  , num2  , "   " , "   " },
		{ " 8 " , "   " , "   " , "   " , num6  , "   " , num4  , num9  , num1  , "   " },
		{ " 9 " , "   " , "   " , num6  , "   " , num7  , "   " , "   " , "   " , "   " }
	};
	string boardThreeAnswer[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " , " E " , " F " , " G " , " H " , " I " },
		{ " 1 " , " 6 " , " 1 " , " 4 " , " 3 " , num9  , " 7 " , num5  , " 2 " , " 8 " },
		{ " 2 " , " 2 " , num5  , num9  , num8  , " 6 " , num1  , " 7 " , " 4 " , " 3 " },
		{ " 3 " , " 7 " , " 3 " , num8  , num2  , " 4 " , " 5 " , " 1 " , num6  , " 9 " },
		{ " 4 " , " 9 " , num7  , " 2 " , " 4 " , num5  , " 6 " , num3  , " 8 " , " 1 " },
		{ " 5 " , " 8 " , " 6 " , num5  , " 1 " , num3  , " 9 " , num4  , " 7 " , " 2 " },
		{ " 6 " , " 3 " , " 4 " , num1  , " 7 " , num8  , " 2 " , " 6 " , num9  , " 5 " },
		{ " 7 " , " 4 " , num9  , " 7 " , " 5 " , " 1 " , num8  , num2  , " 3 " , " 6 " },
		{ " 8 " , " 5 " , " 8 " , " 3 " , num6  , " 2 " , num4  , num9  , num1  , " 7 " },
		{ " 9 " , " 1 " , " 2 " , num6  , " 9 " , num7  , " 3 " , " 8 " , " 5 " , " 4 " }
	};


	string boardTop = "=========================================";              //--- large board top / block borders
	string boardMid = "|===|===========|===========|===========|";

	//================ GENERATE LARGE PUZZLES =======================
	cout << endl;
	cout << "                PUZZLE 1                                        PUZZLE 2                                        PUZZLE 3                 " << endl;  //--- puzzle headers
	cout << boardTop << "       " << boardTop << "       " << boardTop << endl;     //--- print top of each board

	for (int i = 0; i < rows; i++)                                              //--- main rows loop (do the following per entire row)
	{
		cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
		{
			cout << boardOne[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- (puzzle 1) if first row...
			{
				cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last element in current row...
				{
					cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
					for (int ii = 0; ii < rows - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
					{
						cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
						{
							cout << boardTwo[ii][jj];                                       //--- (puzzle 2) print puzzle 2's elements
							if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
							{
								cout << "|";                                                //--- (puzzle 2) print column header dividers
								if (jj == 9)                                                //--- (puzzle 2) if last element in first row...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int iii = 0; iii < rows - 9; iii++)                            //--- (puzzle 3) loop for puzzle 3's first row
									{
										cout << "|";                                                    //--- (puzzle 3) print left wall of puzzle 3 in column 0
										for (int jjj = 0; jjj < cols; jjj++)                            //--- (puzzle 3) loop to print puzzle 3's first row
										{
											cout << boardThree[iii][jjj];                               //--- (puzzle 3) print puzzle 3's elements
											if (iii == 0)                                               //--- (puzzle 3) if first row...
											{
												cout << "|";                                            //--- (puzzle 3) print column header dividers
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
				if (j == 9)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
				{
					cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
					for (int jj = 0; jj < cols; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
					{
						cout << boardTwo[i][jj];                                            //--- (puzzle 2) print puzzle 2's elements
						if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
						{
							cout << "|";                                                    //--- (puzzle 2) print wall
							if (jj == 9)                                                    //--- (puzzle 2) if column 9...
							{
								cout << "       |";                                         //--- (puzzle 2 to puzzle 3) print space and puzzle 3's left wall
								for (int jjj = 0; jjj < cols; jjj++)                                    //--- (puzzle 3) loop for puzzle 3's contents
								{
									cout << boardThree[i][jjj];                                         //--- (puzzle 3) print puzzle 3's elements
									if (jjj == 0 || jjj == 3 || jjj == 6 || jjj == 9)                   //--- (puzzle 3) if column 0, 3, 6, or 9...
									{
										cout << "|";                                                    //--- (puzzle 3) print wall
									}
									else                                                                //--- (puzzle 3) otherwise...
									{
										cout << " ";                                                    //--- (puzzle 3) print space to even out rows
									}
								}
							}
						}
						else                                                                //--- (puzzle 2) otherwise...
						{
							cout << " ";                                                    //--- (puzzle 2) print space to even out rows
						}
					}
				}
			}
			else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
			{
				cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)                  //--- if row 0, 3, 6, or 9...
		{
			if (i == 0 || i == 3 || i == 6)                             //--- if row 0, 3, or 6...
			{
				cout << endl << boardMid << "       " << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
			}
			else if (i == 9)                                            //--- else if row 9...
			{
				cout << endl << boardTop << "       " << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
			}

		}
		else                                                       //--- otherwise...
		{
			cout << endl;                                          //--- start new line for empty space rows
			for (int j = 0; j < cols; j++)                                      //--- (puzzle 1) loop to print empty rows
			{
				if (j == 0)                                                     //--- (puzzle 1) if at column 0...
				{
					cout << "|---|";                                            //--- (puzzle 1) print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
					if (j == 9)                                                 //--- (puzzle 1) if at column 9...
					{
						cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print empty rows
						{
							if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
							{
								cout << "|---|";                                            //--- (puzzle 2) print row header divider
							}
							else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
							{
								cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								if (jj == 9)                                                //--- (puzzle 2) if at column 9...
								{
									cout << "       ";                                      //--- (puzzle 2 to puzzle 3) print space between puzzle 2 and puzzle 3
									for (int jjj = 0; jjj < cols; jjj++)                                //--- (puzzle 3) loop to print empty rows
									{
										if (jjj == 0)                                                   //--- (puzzle 3) if at column 0...
										{
											cout << "|---|";                                            //--- (puzzle 3) print row header divider
										}
										else if (jjj == 3 || jjj == 6 || jjj == 9)                      //--- (puzzle 3) if at column 3, 6, or 9...
										{
											cout << "           |";                                     //--- (puzzle 3) print gap and wall to form borders
										}
									}
								}
							}
						}
					}
				}
			}
			cout << endl;                                          //--- once at the end of an empty space row, start new line to print next row of array elements
		}
	}

	cout << endl << endl;

	cout << "Select a puzzle to play (1-3): ";                                  //--- user selects a puzzle
	getline(cin, boardChoice);

	while (valid == false)                                                      //--- check-input loop
	{
		if (boardChoice == "1" || boardChoice == "2" || boardChoice == "3")     //--- if good input...
		{
			valid = true;                                                       //--- set flag to true
		}
		else                                                                    //--- otherwise...
		{
			cout << "Invalid input. Please enter a number 1-3: ";               //--- ask again
			getline(cin, boardChoice);
		}
	}

	if (boardChoice == "1")                                                     //--- if puzzle 1 chosen...
	{
		playLargeGame(boardOne, boardOneAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function
	}
	if (boardChoice == "2")                                                     //--- if puzzle 2...
	{
		playLargeGame(boardTwo, boardTwoAnswer, boardTop, boardMid, rows, cols);             //--- send it to playLargeGame function, etc.
	}
	if (boardChoice == "3")
	{
		playLargeGame(boardThree, boardThreeAnswer, boardTop, boardMid, rows, cols);
	}
}
//======================== MICHAEL APPERSON END ===============================


//===========================Elise Borbely Start===================================
void playSmallGame(string board[][5], string boardAnswer[][5], string boardTop, string boardMid, string boardChoice, int rows, int cols)
{
	system("CLS");                                                              //--- clear screen

	const string num1 = "[1]";                                          //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";

	string choiceRow;                                                           //--- input variables
	string choiceCol;
	string choiceNum;
	int numRow;                                                                 //--- used as row when entering number into array
	int numCol;                                                                 //--- used as col when entering number into array
	bool valid = false;                                                         //--- check-input flag
	bool CorrectAnswer = false;
	bool ArraysEqual = true;
	cout << endl << endl;

	while (CorrectAnswer == false)												//---Elise Borbely figured out the loop. 
	{

		cout << boardTop << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << "|";
			for (int j = 0; j < cols; j++)
			{
				cout << board[i][j];
				if (i == 0)
				{
					cout << "|";
				}
				else if (j == 0 || j == 2 || j == 4)
				{
					cout << "|";
				}
				else
				{
					cout << " ";
				}
			}
			if (i == 0 || i == 2 || i == 4)
			{
				if (i == 0 || i == 2)
				{
					cout << endl << boardMid << endl;
				}
				else if (i == 4)
				{
					cout << endl << boardTop << endl;
				}
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
					else if (j == 2 || j == 4)
					{
						cout << "       |";
					}
				}
				cout << endl;
			}
		}

		cout << endl << endl << "Select a row (1-4) to enter a number in: ";        //--- get desired row
		getline(cin, choiceRow);

		while (valid == false)                                                      //--- check-input loop
		{
			if (choiceRow == "1" || choiceRow == "2" || choiceRow == "3" || choiceRow == "4") //--- if good input...
			{
				valid = true;                                                       //--- set flag to true
				if (choiceRow == "1")                                               //--- then, if user chose row 1 to enter a number in...
				{
					numRow = 1;                                                     //--- set numRow to 1
				}
				if (choiceRow == "2")                                               //--- if user chose row 2...
				{
					numRow = 2;                                                     //--- set numRow to 2, etc.
				}
				if (choiceRow == "3")
				{
					numRow = 3;
				}
				if (choiceRow == "4")
				{
					numRow = 4;
				}
			}
			else                                                                    //--- otherwise, bad input. ask again
			{
				cout << "Invalid input. Please select a row (1-4) to enter a number in: ";
				getline(cin, choiceRow);
			}
		}

		valid = false;                                                              //--- reset check-input flag to false for next loop

		cout << endl << endl << "Select a column (A-D) to enter a number in: ";     //--- ask user for a column
		getline(cin, choiceCol);
		choiceCol[0] = toupper(choiceCol[0]);                                       //--- if user enters lowercase letter, this will change it to uppercase

		while (valid == false)                                                      //--- check-input loop
		{
			if (choiceCol == "A" || choiceCol == "B" || choiceCol == "C" || choiceCol == "D")  //--- if good input...
			{
				valid = true;                                                       //--- set flag to true
				if (choiceCol == "A")                                               //--- then, if column A is chosen...
				{
					numCol = 1;                                                     //--- set numCol to 1
				}
				if (choiceCol == "B")                                               //--- if column B...
				{
					numCol = 2;                                                     //--- set numCol to 2, etc.
				}
				if (choiceCol == "C")
				{
					numCol = 3;
				}
				if (choiceCol == "D")
				{
					numCol = 4;
				}
			}
			else                                                                    //--- otherwise, bad input, ask again.
			{
				cout << "Invalid input. Please select a column (A-D) to enter a number in: ";
				getline(cin, choiceCol);
				choiceCol[0] = toupper(choiceCol[0]);                               //--- changing new entered-letter to uppercase again
			}
		}

		valid = false;                                                              //--- flag to false again for next loop

		cout << endl << endl << "Select a number (1-4) to insert in cell " << choiceCol << "-" << choiceRow << ": ";  //--- get a number to enter in chosen cell
		getline(cin, choiceNum);

		while (valid == false)                                                      //--- check-input loop
		{
			if (choiceNum == "1" || choiceNum == "2" || choiceNum == "3" || choiceNum == "4")  //--- if good input...
			{
				valid = true;                                                       //--- flag to true
				if (choiceNum == "1")                                               //--- if user wants to insert a 1 in chosen cell...
				{
					choiceNum = num1;                                              //--- set the variable to same number with spaces around it (this keeps the board from thinning when the number is entered in array)
				}
				if (choiceNum == "2")                                               //--- if user wants to insert a 2...
				{
					choiceNum = num2;                                              //--- set variable to 2 with spaces, etc.
				}
				if (choiceNum == "3")
				{
					choiceNum = num3;
				}
				if (choiceNum == "4")
				{
					choiceNum = num4;
				}
			}
			else                                                                     //--- otherwise, bad input, ask again
			{
				cout << "Invalid input. Please select a number (1-4) to insert in cell " << choiceCol << "-" << choiceRow << ": ";
				getline(cin, choiceNum);
			}
		}
		board[numRow][numCol] = choiceNum;                                          //--- update the array using the converted row and col variables, and insert the modified number into array
		valid = false;																//--- This fixed the loops problem--From Elise. 

																					//===========Elise Borbely==============================================
		if (board[numRow][numCol] == boardAnswer[numRow][numCol])               //---- Compares the user input to the board answer
		{
			cout << endl << "That number is correctly placed" << endl;        //---If the input matches the answer the number has brackets.

		}
		else if (board[numRow][numCol] != boardAnswer[numRow][numCol])          //---If the number isn't correct
		{
			cout << endl << "That number is not correctly placed" << endl;     //---This code makes it so it doesn't have brackets so the user knows to try and change that one. 

			if (board[numRow][numCol] == num1)
			{
				board[numRow][numCol] = " 1 ";
			}
			if (board[numRow][numCol] == num2)
			{
				board[numRow][numCol] = " 2 ";
			}
			if (board[numRow][numCol] == num3)
			{
				board[numRow][numCol] = " 3 ";
			}
			if (board[numRow][numCol] == num4)
			{
				board[numRow][numCol] = " 4 ";
			}
		}

		int rowCount = 0;
		int colCount = 0;
		while (ArraysEqual && rowCount < 5)
		{
			while (ArraysEqual && colCount < 5)
			{
				if (board[rowCount][colCount] != boardAnswer[rowCount][colCount])
				{
					ArraysEqual = false;

				}
				colCount++;
			}
			rowCount++;
			colCount = 0;

		}
		if (ArraysEqual)
		{
			CorrectAnswer = true;
		}
		ArraysEqual = true;
	}


	while (CorrectAnswer == true)
	{
		SmallGamesolution(board, boardAnswer, boardTop, boardMid, boardChoice, rows, cols);
		CorrectAnswer = false;

	}

	//=====================Elise Borbely End======================================



	////=============== GENERATE UPDATED BOARD ===================
	//cout << boardTop << endl;
	//for (int i = 0; i < rows; i++)
	//{
	//	cout << "|";
	//	for (int j = 0; j < cols; j++)
	//	{
	//		cout << board[i][j];
	//		if (i == 0)
	//		{
	//			cout << "|";
	//		}
	//		else if (j == 0 || j == 2 || j == 4)
	//		{
	//			cout << "|";
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//	}
	//	if (i == 0 || i == 2 || i == 4)
	//	{
	//		cout << endl << boardTop << endl;
	//	}
	//	else
	//	{
	//		cout << endl;
	//		for (int j = 0; j < cols; j++)
	//		{
	//			if (j == 0)
	//			{
	//				cout << "|---|";
	//			}
	//			else if (j == 2 || j == 4)
	//			{
	//				cout << "       |";
	//			}
	//		}
	//		cout << endl;
	//	}
	//}

	//cout << endl << endl;











}
//===============Elise Borbely End=========================================

void playMedGame(string board[][7], string board_answer[][7], const int rows, const int cols)
{
	system("CLS");
	const string num1 = "[1]", num2 = "[2]", num3 = "[3]", num4 = "[4]",
		num5 = "[5]", num6 = "[6]";

	string boardTop = "=============================";
	string boardMid = "|===|===========|===========|";
	bool Input = false;
	bool Equal = false;
	bool Terminated = false;
	bool ValidCell = false;
	int celldiff = 0;
	string row;
	string column;
	string number;
	string cnumber;
	int ccolumn;
	int crow;

	while (Equal == false && Terminated == false)
	{
		cout << boardTop << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

			for (int j = 0; j < cols; j++)
			{
				cout << board[i][j];
				if (i == 0)
				{
					cout << "|";
				}
				else if (j == 0 || j == 3 || j == 6)
				{
					cout << "|";
				}

				else
				{
					cout << " ";
				}
			}
			if (i == 0 || i == 2 || i == 4 || i == 6)
			{
				if (i == 0 || i == 2 || i == 4 || i == 6)
				{
					cout << endl << boardMid << endl;
				}

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
					else if (j == 3 || j == 6)
					{
						cout << "           |";
					}
				}
				cout << endl;
			}

		}

		//start valid cell loop
		while (ValidCell == false)
		{

			cout << endl << "Select a row (1-6) to enter a number in: ";
			getline(cin, row);

			Input = false;

			while (!Input)
			{
				if (row >= "1" && row <= "6" && row.length() == 1)
				{
					Input = true;
					stringstream(row) >> crow;


				}
				else
				{
					cout << "Bad input. Enter a row(1-6): ";
					getline(cin, row);
				}

			}
			Input = false;

			cout << "Select a column (A-F): ";
			getline(cin, column);

			column[0] = toupper(column[0]);

			while (!Input)
			{


				if (column.length() > 1 || column < "A" || column > "F")
				{
					cout << "Bad input. Enter a column(A-F): ";
					getline(cin, column);
					column[0] = toupper(column[0]);
					ccolumn = (column[0] - 64); //subtracts ascii value to equate with array
				}
				else
				{
					Input = true;
				}

			}
			ccolumn = (column[0] - 64); //subtracts ascii value to equate with array
			if (board[crow][ccolumn] >= num1 && board[crow][ccolumn] <= num6)
			{
				cout << "You cannot edit this cell." << endl;
			}
			else
			{
				ValidCell = true;
			}
			Input = false;
		}



		//end valid cell loop


		ValidCell = false; //reset valid cell for next iteration
		cout << "Enter a number to insert: ";
		getline(cin, number);

		while (!Input)
		{

			if (number >= "1" && number <= "6" && number.length() == 1)
			{
				cnumber = number;
				number = ' ' + number + ' ';
				Input = true;
			}
			else
			{
				cout << "Bad input. Enter a number between 1 and 9: ";
				getline(cin, number);
			}

		}

		board[crow][ccolumn] = number;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] != board_answer[i][j])
				{
					Equal = false;
					celldiff++;
				}

			}
		}
		if (celldiff == 0)
		{
			Equal = true;
		}

		celldiff = 0;

	}

	mediumGameSolution();
}

//======================= MICHAEL APPERSON START ==============================
void playLargeGame(string board[][10], string boardAnswer[][10], string boardTop, string boardMid, int rows, int cols)
{
	system("CLS");

	const string num1 = "[1]";                    //--- constants
	const string num2 = "[2]";
	const string num3 = "[3]";
	const string num4 = "[4]";
	const string num5 = "[5]";
	const string num6 = "[6]";
	const string num7 = "[7]";
	const string num8 = "[8]";
	const string num9 = "[9]";
	string terminate = "-999";                    //--- sentinel
	string choiceRow;
	string choiceCol;
	string choiceNum;
	int numRow;
	int numCol;
	int steps = 0;                                //--- score tracker
	bool validInput = false;                      //--- validate input flag
	bool validCell = false;                       //--- valid cell flag
	bool gameOver = false;                        //--- main running loop flag
	bool win = false;                             //--- if user finished puzzle flag
	bool arraysEqual = true;                      //--- if arrays match flag



	cout << endl << endl;

	while (gameOver == false)                                             //--- run game loop
	{
		cout << boardTop << endl;                                         //--- generate board
		for (int i = 0; i < rows; i++)
		{
			cout << "|";

			for (int j = 0; j < cols; j++)
			{
				cout << board[i][j];
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
				if (i == 0 || i == 3 || i == 6)
				{
					cout << endl << boardMid << endl;
				}
				else if (i == 9)
				{
					cout << endl << boardTop << endl;
				}
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


		while (validCell == false && gameOver == false)                                //--- This loop prevents already-given cells from being changed
		{
			cout << endl << "Select a row (1-9) to enter a number in: ";
			getline(cin, choiceRow);

			while (validInput == false)                                                //--- input validation loop for row selection
			{

				if (choiceRow == terminate)                                            //======= IF SENTINEL WAS ENTERED AS ROW =========
				{
					gameOver = true;                                                   //--- set gameOver flag to true to quit game
					validInput = true;                                                 //--- set validInput flag to true to leave current loop
				}                                                                      //================================================


				else if ((choiceRow >= "1" && choiceRow <= "9") && choiceRow.size() == 1)     //--- else if good input...
				{

					validInput = true;                                                        //--- set flag to leave loop
					if (choiceRow == "1")                                                     //--- assign corresponding integer for array row
					{
						numRow = 1;
					}
					if (choiceRow == "2")
					{
						numRow = 2;
					}
					if (choiceRow == "3")
					{
						numRow = 3;
					}
					if (choiceRow == "4")
					{
						numRow = 4;
					}
					if (choiceRow == "5")
					{
						numRow = 5;
					}
					if (choiceRow == "6")
					{
						numRow = 6;
					}
					if (choiceRow == "7")
					{
						numRow = 7;
					}
					if (choiceRow == "8")
					{
						numRow = 8;
					}
					if (choiceRow == "9")
					{
						numRow = 9;
					}
				}
				else                                                                          //--- otherwise, bad input
				{
					cout << "Invalid input. Please select a row (1-9) to enter a number in: ";
					getline(cin, choiceRow);
				}
			}

			if (gameOver == false)                                                            //======= IF SENTINEL HAS NOT BEEN ENTERED ==========
			{
				validInput = false;                                                           //--- set input flag to false for next input loop
				cout << endl << "Select a column (A-I) to enter a number in: ";               //--- get column input
				getline(cin, choiceCol);
				choiceCol[0] = toupper(choiceCol[0]);                                         //--- raise letter to uppercase if possible
			}                                                                                 //===================================================



			while (validInput == false)                                                       //--- input validation loop for column selection
			{

				if (choiceCol == terminate)                                                   //======= IF SENTINEL WAS ENTERED AS COLUMN =========
				{
					gameOver = true;                                                          //--- set gameOver flag to true to quit game
					validInput = true;                                                        //--- set input flag to true to leave current loop
				}                                                                             //===================================================


				else if ((choiceCol >= "A" && choiceCol <= "I") && choiceCol.size() == 1)     //--- else if good input...
				{
					validInput = true;                                                        //--- set input flag to true to leave loop
					if (choiceCol == "A")                                                     //--- set column input to corresponding integer for array column
					{
						numCol = 1;
					}
					if (choiceCol == "B")
					{
						numCol = 2;
					}
					if (choiceCol == "C")
					{
						numCol = 3;
					}
					if (choiceCol == "D")
					{
						numCol = 4;
					}
					if (choiceCol == "E")
					{
						numCol = 5;
					}
					if (choiceCol == "F")
					{
						numCol = 6;
					}
					if (choiceCol == "G")
					{
						numCol = 7;
					}
					if (choiceCol == "H")
					{
						numCol = 8;
					}
					if (choiceCol == "I")
					{
						numCol = 9;
					}
				}
				else                                                                          //--- otherwise, bad input
				{
					cout << "Invalid input. Please select a column (A-I) to enter a number in: ";
					getline(cin, choiceCol);
					choiceCol[0] = toupper(choiceCol[0]);
				}
			}

			if (gameOver == false)                                                            //======= IF SENTINEL HAS NOT BEEN ENTERED =======
			{
				if (board[numRow][numCol] >= num1 && board[numRow][numCol] <= num9)           //--- if the user's chosen row and col matches an element already given...
				{
					cout << endl << "You cannot change this cell. Try again." << endl;        //--- display error, loop back to row and col input
				}
				else                                                                          //--- otherwise...
				{
					validCell = true;                                                         //--- the chosen element is acceptable to change
				}
			}                                                                                 //================================================
		}


		if (gameOver == false)                                                                //======= IF SENTINEL HAS NOT BEEN ENTERED =======
		{
			validCell = false;                                                                //--- reset validCell flag for next iteration
			validInput = false;                                                               //--- reset input flag for next loop
			cout << endl << "Select a number (1-9) to insert in cell " << choiceRow << "-" << choiceCol << ": ";
			getline(cin, choiceNum);
		}                                                                                     //================================================



		while (validInput == false)                                                           //--- input validation loop for selected number to enter in cell
		{

			if (choiceNum == terminate)                                                       //======= IF SENTINEL WAS ENTERED AS NUMBER =======
			{
				gameOver = true;                                                              //--- set gameOver flag to true to quit game
				validInput = true;                                                            //--- set input flag to true to leave current loop
			}                                                                                 //=================================================


			else if ((choiceNum >= "1" && choiceNum <= "9") && choiceNum.size() == 1)         //--- else if good input...
			{
				validInput = true;                                                            //--- set input flag to true to leave loop
				if (choiceNum == "1")                                                         //--- modify user's input for the array
				{
					choiceNum = " 1 ";
				}
				if (choiceNum == "2")
				{
					choiceNum = " 2 ";
				}
				if (choiceNum == "3")
				{
					choiceNum = " 3 ";
				}
				if (choiceNum == "4")
				{
					choiceNum = " 4 ";
				}
				if (choiceNum == "5")
				{
					choiceNum = " 5 ";
				}
				if (choiceNum == "6")
				{
					choiceNum = " 6 ";
				}
				if (choiceNum == "7")
				{
					choiceNum = " 7 ";
				}
				if (choiceNum == "8")
				{
					choiceNum = " 8 ";
				}
				if (choiceNum == "9")
				{
					choiceNum = " 9 ";
				}
			}
			else                                                                              //--- otherwise, bad input
			{
				cout << "Invalid input. Please select a number (1-9) to insert in cell " << choiceRow << "-" << choiceCol << ": ";
				getline(cin, choiceNum);
			}
		}
		if (gameOver == false)                                                                //======= IF SENTINEL WAS NOT ENTERED ========
		{
			board[numRow][numCol] = choiceNum;                                                //--- add user's input into array
			validInput = false;                                                               //--- reset input flag to false for next iteration
			steps++;                                                                          //--- increment score counter
		}                                                                                     //============================================


		for (int i = 0; i < rows; i++)                                                        //--- loop to compare if user board matches finished board
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] != boardAnswer[i][j])                                         //--- if board does not match answer...
				{
					arraysEqual = false;                                                      //--- set flag to false
				}
			}
		}
		if (arraysEqual)                                                                      //--- if flag is true, then user board matches finished board...
		{
			win = true;                                                                       //--- user completed puzzle
			gameOver = true;                                                                  //--- and game is over (leave game loop)
		}
		arraysEqual = true;                                                                   //--- reset equal arrays flag to true for next iteration

	}

	largeGameSolution(board, boardAnswer, boardTop, boardMid, rows, cols, steps, win);        //--- solution function call when gameOver is true
}
//======================= MICHAEL APPERSON END ================================

//====================Elise Borbely Start======================================
void SmallGamesolution(string board[][5], string boardAnswer[][5], string boardTop, string boardMid, string boardChoice, int rows, int cols)
{
	//system("CLS"); 
	cout << "Congratulations! You solved the puzzle!" << endl;
}
//=====================Elise Borbely End=======================================
//======================Trevor Ruelle Start==================================
void mediumGameSolution()
{

}
//======================Trevor Ruelle End======================================
//======================= MICHAEL APPERSON START ==============================
void largeGameSolution(string board[][10], string boardAnswer[][10], string boardTop, string boardMid, int rows, int cols, int steps, bool win)
{
	system("CLS");
	if (win)                                                                     //--- if WIN flag is true (user finished puzzle)...
	{                                                                            //--- show congratulations and their solved puzzle
		cout << endl << endl << "Congratulations! You solved the puzzle in " << steps << " steps!";
		cout << endl << endl << endl;
		cout << "               YOUR PUZZLE " << endl;
		cout << boardTop << endl;

		for (int i = 0; i < rows; i++)                                           //--- main rows loop (do the following per entire row)
		{
			cout << "|";                                                         //--- print left wall of puzzle 1 column 0
			for (int j = 0; j < cols; j++)                                       //--- loop to print puzzle 1's contents
			{
				cout << board[i][j];                                             //--- print elements
				if (i == 0)                                                      //--- if first row...
				{
					cout << "|";                                                 //--- print right-side wall of each cell, will close last cell (column header dividers)
				}
				else if (j == 0 || j == 3 || j == 6 || j == 9)                   //--- if not first row, but is column 0, 3, 6, or 9...
				{
					cout << "|";                                                 //--- print divider (this will close off row headers as well as become block dividers)
				}
				else                                                             //--- if not first row, or columns 0, 3, 6, or 9...
				{
					cout << " ";                                                 //--- print space to even out the rows
				}
			}
			if (i == 0 || i == 3 || i == 6 || i == 9)                            //--- if row 0, 3, 6, or 9...
			{
				if (i == 0 || i == 3 || i == 6)                                  //--- if row 0, 3, or 6...
				{
					cout << endl << boardMid << endl;                            //--- skip line, print mid border, skip line (these are block floors / ceilings)
				}
				else if (i == 9)                                                 //--- else if row 9...
				{
					cout << endl << boardTop << endl;                            //--- skip line, print top border, skip line (these are the top and bottom of entire board)
				}

			}
			else                                                                 //--- otherwise...
			{
				cout << endl;                                                    //--- start new line for empty space rows
				for (int j = 0; j < cols; j++)                                   //--- loop to print empty rows
				{
					if (j == 0)                                                  //--- if at column 0...
					{
						cout << "|---|";                                         //--- print row-header divider
					}
					else if (j == 3 || j == 6 || j == 9)                         //--- if column 3, 6, or 9...
					{
						cout << "           |";                                  //--- print gap and wall to form borders
					}
				}
				cout << endl;                                                    //--- once at the end of an empty space row, start new line to print next row of array elements
			}
		}
	}

	else                                                                            //--- if WIN flag is false (incomplete puzzle)...
	{                                                                               //--- show incomplete puzzle and solution to puzzle
		cout << endl;
		cout << "               YOUR PUZZLE                                      SOLUTION                " << endl;  //--- puzzle headers
		cout << boardTop << "       " << boardTop << endl;                          //--- print top of each board

		for (int i = 0; i < rows; i++)                                              //--- main rows loop (do the following per entire row)
		{
			cout << "|";                                                            //--- (puzzle 1) print left wall of puzzle 1 column 0
			for (int j = 0; j < cols; j++)                                          //--- (puzzle 1) loop to print puzzle 1's contents
			{
				cout << board[i][j];                                                //--- (puzzle 1) print elements
				if (i == 0)                                                         //--- (puzzle 1) if first row...
				{
					cout << "|";                                                    //--- (puzzle 1) print right-side wall of each cell, will close last cell (column header dividers)
					if (j == 9)                                                     //--- (puzzle 1) if last element in current row...
					{
						cout << "       ";                                          //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
						for (int ii = 0; ii < rows - 9; ii++)                                   //--- (puzzle 2) loop for puzzle 2's first row
						{
							cout << "|";                                                        //--- (puzzle 2) print left wall of puzzle 2 in column 0
							for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print puzzle 2's first row
							{
								cout << boardAnswer[ii][jj];                                    //--- (puzzle 2) print puzzle 2's elements
								if (ii == 0)                                                    //--- (puzzle 2) if first row in puzzle 2...
								{
									cout << "|";                                                //--- (puzzle 2) print column header dividers
								}
							}
						}
					}
				}
				else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- (puzzle 1) if not first row, but is column 0, 3, 6, or 9...
				{
					cout << "|";                                                    //--- (puzzle 1) print divider (this will close off row headers as well as become block dividers)
					if (j == 9)                                                     //--- (puzzle 1) if last column in current row of puzzle 1...
					{
						cout << "       |";                                         //--- (puzzle 1 to puzzle 2) print space and left wall of puzzle 2
						for (int jj = 0; jj < cols; jj++)                                       //--- (puzzle 2) loop for puzzle 2's contents
						{
							cout << boardAnswer[i][jj];                                         //--- (puzzle 2) print puzzle 2's elements
							if (jj == 0 || jj == 3 || jj == 6 || jj == 9)                       //--- (puzzle 2) if column 0, 3, 6, or 9...
							{
								cout << "|";                                                    //--- (puzzle 2) print wall
							}
							else                                                                //--- (puzzle 2) otherwise...
							{
								cout << " ";                                                    //--- (puzzle 2) print space to even out rows
							}
						}
					}
				}
				else                                                                //--- (puzzle 1) if not first row, or columns 0, 3, 6, or 9...
				{
					cout << " ";                                                    //--- (puzzle 1) print space to even out the rows
				}
			}
			if (i == 0 || i == 3 || i == 6 || i == 9)                             //--- if row 0, 3, 6, or 9...
			{
				if (i == 0 || i == 3 || i == 6)                                   //--- if row 0, 3, or 6...
				{
					cout << endl << boardMid << "       " << boardMid << endl;    //--- skip line, print mid border, skip line (these are block floors / ceilings)
				}
				else if (i == 9)                                                  //--- else if row 9...
				{
					cout << endl << boardTop << "       " << boardTop << endl;    //--- skip line, print top border, skip line (these are the top and bottom of entire board)
				}

			}
			else                                                                  //--- otherwise...
			{
				cout << endl;                                                     //--- start new line for empty space rows
				for (int j = 0; j < cols; j++)                                      //--- (puzzle 1) loop to print empty rows
				{
					if (j == 0)                                                     //--- (puzzle 1) if at column 0...
					{
						cout << "|---|";                                            //--- (puzzle 1) print row-header divider
					}
					else if (j == 3 || j == 6 || j == 9)                            //--- (puzzle 1) if column 3, 6, or 9...
					{
						cout << "           |";                                     //--- (puzzle 1) print gap and wall to form borders
						if (j == 9)                                                 //--- (puzzle 1) if at column 9...
						{
							cout << "       ";                                      //--- (puzzle 1 to puzzle 2) print space between puzzle 1 and puzzle 2
							for (int jj = 0; jj < cols; jj++)                                   //--- (puzzle 2) loop to print empty rows
							{
								if (jj == 0)                                                    //--- (puzzle 2) if at column 0...
								{
									cout << "|---|";                                            //--- (puzzle 2) print row header divider
								}
								else if (jj == 3 || jj == 6 || jj == 9)                         //--- (puzzle 2) if at colum 3, 6, or 9...
								{
									cout << "           |";                                     //--- (puzzle 2) print gap and wall to form borders
								}
							}
						}
					}
				}

				cout << endl;                                                       //--- once at the end of an empty space row, start new line to print next row of array elements
			}
		}
	}
}
//======================= MICHAEL APPERSON END ================================