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
void playSmallGame(string[][5], string, string, int, int);
void playMedGame(string[][7]);
void playLargeGame(string[][10], string, string, int, int);
void solution(string);


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


	string boardOne[rows][cols] =                                       //--- puzzle arrays
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " , "   " , "   " ,  num3 },
		{ " 2 " , "   " ,  num2 ,  num1 , "   " },
		{ " 3 " , "   " ,  num4 ,  num3 , "   " },
		{ " 4 " ,  num2 , "   " , "   " , "   " }
	};
	string boardTwo[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , "   " , " 4 " , " 1 " , "   " },
		{ " 2 " , "   " , "   " , "   " , " 4 " },
		{ " 3 " , " 2 " , "   " , "   " , "   " },
		{ " 4 " , "   " , " 3 " , " 2 " , "   " }
	};
	string boardThree[rows][cols] =
	{
		{ "   " , " A " , " B " , " C " , " D " },
		{ " 1 " , " 1 " , "   " , "   " , " 2 " },
		{ " 2 " , "   " , " 2 " , "   " , "   " },
		{ " 3 " , "   " , "   " , " 3 " , "   " },
		{ " 4 " , " 3 " , "   " , "   " , " 4 " }
	};

	//============ GENERATING THE BOARDS SIDE BY SIDE =============
	cout << endl;
	cout << "      PUZZLE 1                 PUZZLE 2                 PUZZLE 3      " << endl;            //---- puzzle headers
	cout << boardTop << "    " << boardTop << "    " << boardTop << "    " << endl;                      //---- print top of each board
	for (int i = 0; i < rows; i++)                                                                       //---- main rows loop (do the following per entire row)
	{
		cout << "|";                                                               //---- (puzzle 1) print left wall of puzzle 1 column 0
		for (int j = 0; j < cols; j++)                                             //---- (puzzle 2) loop to print puzzle 1's contents
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
			cout << endl << boardTop << "    " << boardTop << "    " << boardTop << endl; //---- print boardTop to separate blocks
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
	//============== GENERATING THE BOARDS STACKED ================
	cout << endl << endl;
	cout << "      PUZZLE 2      " << endl;

	cout << boardTop << endl;
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
			cout << endl << boardTop << endl;
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

	cout << endl << endl;

	cout << "      PUZZLE 3      " << endl;
	cout << boardTop << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < cols; j++)
		{
			cout << boardThree[i][j];
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
			cout << endl << boardTop << endl;
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
		playSmallGame(boardOne, boardTop, boardChoice, rows, cols);              //--- send it to playSmallGame function along with board parameters
	}
	if (boardChoice == "2")                                                      //--- if puzzle 2 is chosen...
	{
		playSmallGame(boardTwo, boardTop, boardChoice, rows, cols);              //--- send it to playSmallGame function
	}
	if (boardChoice == "3")
	{
		playSmallGame(boardThree, boardTop, boardChoice, rows, cols);
	}
}
void med4x4()
{

}
void hard4x4()
{

}
void easy6x6()
{

}
void med6x6()
{

}
void hard6x6()
{

}
void easy9x9()
{
	system("CLS");                                                               //--- clear screen
	string boardChoice;                                                          //--- user's puzzle choice
	bool valid = false;                                                          //--- check-input flag

	const int rows = 10;                                                         //--- large board dimensions
	const int cols = 10;

	const string num1 = " 1 ";                                                   //--- constants
	const string num2 = " 2 ";
	const string num3 = " 3 ";
	const string num4 = " 4 ";
	const string num5 = " 5 ";
	const string num6 = " 6 ";
	const string num7 = " 7 ";
	const string num8 = " 8 ";
	const string num9 = " 9 ";

	string boardOne[rows][cols] = {
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

	//--- other large easy boards to come
	string boardTwo[rows][cols] = {

	};

	string boardThree[rows][cols] = {

	};


	string boardTop = "=========================================";              //--- large board top / block borders

																				//================ GENERATE LARGE PUZZLES =======================
	cout << "                PUZZLE 1                " << endl;
	cout << boardTop << endl;

	for (int i = 0; i < rows; i++)                                              //--- main loop to print all rows
	{
		cout << "|";                                                            //--- print left-most border

		for (int j = 0; j < cols; j++)                                          //--- loop to print a row's contents
		{
			cout << boardOne[i][j];                                             //--- (puzzle 1) print elements
			if (i == 0)                                                         //--- if row 0...
			{
				cout << "|";                                                    //--- print wall (walls of the column headers)
			}
			else if (j == 0 || j == 3 || j == 6 || j == 9)                      //--- if not row 0, but is column 0, 3, 6, or 9...
			{
				cout << "|";                                                    //--- print wall (these form the block's walls)
			}
			else                                                                //--- otherwise...
			{
				cout << " ";                                                    //--- print space (this evens out the rows)
			}
		}
		if (i == 0 || i == 3 || i == 6 || i == 9)                               //--- if row 0, 3, 6, or 9...
		{
			cout << endl << boardTop << endl;                                   //--- skip line, print border, skip line (these are block floors / ceilings)
		}
		else                                                                    //--- otherwise...
		{
			cout << endl;                                                       //--- skip line
			for (int j = 0; j < cols; j++)                                      //--- loop to print empty row's contents (not part of the array)
			{
				if (j == 0)                                                     //--- if column 0...
				{
					cout << "|---|";                                            //--- print row-header divider
				}
				else if (j == 3 || j == 6 || j == 9)                            //--- if column 3, 6, or 9...
				{
					cout << "           |";                                     //--- print empty space and right-side wall (these also form the block's walls)
				}
			}
			cout << endl;                                                       //--- skip line
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
		playLargeGame(boardOne, boardTop, boardChoice, rows, cols);             //--- send it to playLargeGame function
	}
	if (boardChoice == "2")                                                     //--- if puzzle 2...
	{
		playLargeGame(boardTwo, boardTop, boardChoice, rows, cols);             //--- send it to playLargeGame function, etc.
	}
	if (boardChoice == "3")
	{
		playLargeGame(boardThree, boardTop, boardChoice, rows, cols);
	}

}
void med9x9()
{

}
void hard9x9()
{

}
void playSmallGame(string board[][5], string boardTop, string boardChoice, int rows, int cols)
{
	system("CLS");                                                              //--- clear screen

	string choiceRow;                                                           //--- input variables
	string choiceCol;
	string choiceNum;
	int numRow;                                                                 //--- used as row when entering number into array
	int numCol;                                                                 //--- used as col when entering number into array
	bool valid = false;                                                         //--- check-input flag
	cout << endl << endl;

	//============= GENERATE CHOSEN BOARD TO PLAY ===============
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
			cout << endl << boardTop << endl;
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
				choiceNum = " 1 ";                                              //--- set the variable to same number with spaces around it (this keeps the board from thinning when the number is entered in array)
			}
			if (choiceNum == "2")                                               //--- if user wants to insert a 2...
			{
				choiceNum = " 2 ";                                              //--- set variable to 2 with spaces, etc.
			}
			if (choiceNum == "3")
			{
				choiceNum = " 3 ";
			}
			if (choiceNum == "4")
			{
				choiceNum = " 4 ";
			}
		}
		else                                                                     //--- otherwise, bad input, ask again
		{
			cout << "Invalid input. Please select a number (1-4) to insert in cell " << choiceCol << "-" << choiceRow << ": ";
			getline(cin, choiceNum);
		}
	}
	board[numRow][numCol] = choiceNum;                                           //--- update the array using the converted row and col variables, and insert the modified number into array


																				 //=============== GENERATE UPDATED BOARD ===================
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
			cout << endl << boardTop << endl;
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


	cout << endl << endl;
}
void playMedGame()
{

}
void playLargeGame(string board[][10], string boardTop, string boardChoice, int rows, int cols)
{
	system("CLS");

	string choiceRow;
	string choiceCol;
	string choiceNum;
	int numRow;
	int numCol;
	bool valid = false;
	cout << endl << endl;

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
			cout << endl << boardTop << endl;
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


	cout << endl << endl << "Select a row (1-9) to enter a number in: ";
	getline(cin, choiceRow);

	while (valid == false)
	{
		if (choiceRow == "1" || choiceRow == "2" || choiceRow == "3" || choiceRow == "4" || choiceRow == "5" || choiceRow == "6" || choiceRow == "7" || choiceRow == "8" || choiceRow == "9")
		{
			valid = true;
			if (choiceRow == "1")
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
		else
		{
			cout << "Invalid input. Please select a row (1-9) to enter a number in: ";
			getline(cin, choiceRow);
		}
	}

	valid = false;

	cout << endl << endl << "Select a column (A-I) to enter a number in: ";
	getline(cin, choiceCol);
	choiceCol[0] = toupper(choiceCol[0]);

	while (valid == false)
	{
		if (choiceCol == "A" || choiceCol == "B" || choiceCol == "C" || choiceCol == "D" || choiceCol == "E" || choiceCol == "F" || choiceCol == "G" || choiceCol == "H" || choiceCol == "I")
		{
			valid = true;
			if (choiceCol == "A")
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
		else
		{
			cout << "Invalid input. Please select a column (A-I) to enter a number in: ";
			getline(cin, choiceCol);
			choiceCol[0] = toupper(choiceCol[0]);
		}
	}

	valid = false;

	cout << endl << endl << "Select a number (1-9) to insert in cell " << choiceCol << "-" << choiceRow << ": ";
	getline(cin, choiceNum);

	while (valid == false)
	{
		if (choiceNum == "1" || choiceNum == "2" || choiceNum == "3" || choiceNum == "4" || choiceNum == "5" || choiceNum == "6" || choiceNum == "7" || choiceNum == "8" || choiceNum == "9")
		{
			valid = true;
			if (choiceNum == "1")
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
		else
		{
			cout << "Invalid input. Please select a number (1-9) to insert in cell " << choiceCol << "-" << choiceRow << ": ";
			getline(cin, choiceNum);
		}
	}
	board[numRow][numCol] = choiceNum;


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
			cout << endl << boardTop << endl;
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

}
void solution(string boardChoice)
{

}