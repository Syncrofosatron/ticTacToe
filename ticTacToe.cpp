// Author : Neeraj Mishra
// nmcnemis@gmail.com

// ticTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

// Rendering the board to the console.
// Trick is, I am just printing the board on newline whenever I reach the right number.
// Thus, creating an illusion of 2D array.
void Render(char array[])
{
	for (char i = 0; i < 9; ++i)
	{
		cout << "|" << array[i] << " " << "|";
		if (i == 2 || i == 5) { cout << "\n"; }
	}
	cout << "\n";
}

// This function reverberates between 1 and 2, the turns of player 1 and 2.
int Turn()
{
	int temp;
	static int a = 2;
	static int b = 1;

	temp = a;
	a = b;
	b = temp;

	// Change colors when there are different turns. Different color for 1 and 2. More interactive.
	if (a == 1) { system("color 0d"); }
	if (a == 2) { system("color 0c"); }

	return a;
}

// Function to check if the player is winning or if it is a draw.
void Won(char array[])
{
	if ((array[0] == 'X' && array[1] == 'X' && array[2] == 'X') || (array[3] == 'X' && array[4] == 'X' && array[5] == 'X')
		|| (array[6] == 'X' && array[7] == 'X' && array[8] == 'X') || (array[0] == 'X' && array[3] == 'X' && array[6] == 'X')
		|| (array[1] == 'X' && array[4] == 'X' && array[7] == 'X') || (array[2] == 'X' && array[5] == 'X' && array[8] == 'X')
		|| (array[0] == 'X' && array[4] == 'X' && array[8] == 'X') || (array[2] == 'X' && array[4] == 'X' && array[6] == 'X'))
	{
		cout << "\n";
		cout << "Player 1" << " won!";
		exit(0);
	}

	else
		if ((array[0] == 'O' && array[1] == 'O' && array[2] == 'O') || (array[3] == 'O' && array[4] == 'O' && array[5] == 'O')
			|| (array[6] == 'O' && array[7] == 'O' && array[8] == 'O') || (array[0] == 'O' && array[3] == 'O' && array[6] == 'O')
			|| (array[1] == 'O' && array[4] == 'O' && array[7] == 'O') || (array[2] == 'O' && array[5] == 'O' && array[8] == 'O')
			|| (array[0] == 'O' && array[4] == 'O' && array[8] == 'O') || (array[2] == 'O' && array[4] == 'O' && array[6] == 'O'))
		{
			cout << "\n";
			cout << "Player 2" << " won!";
			exit(0);
		}

		// There's a problem that when there's a draw, the AIMoves() is getting stuck in infinite calling loop.
		// So, solved using this statement below, if there is a draw.
		else
			if ((array[0] != '1') && (array[1] != '2') && (array[2] != '3') && (array[3] != '4') && (array[4] != '5')
				&& (array[5] != '6') && (array[6] != '7') && (array[7] != '8') && (array[8] != '9'))
			{
				system("color 0b");
				cout << "Oops. Turns out to be a draw. So you're both winners! or Losers.";
				cout << "\n";
				exit(0);
			}
}

// Function to get the value by user to move.
void GetCoordinates(char array[])
{
	cout << "\n";
	int ch;
	// The number user will choose will get marked in the board.
	cout << "Enter the number you want to mark: ";
	cin >> ch;

	int turn;

	// This takes care of the proper symbols when a user makes a move.
	switch (ch)
	{
	case 1:turn = Turn();
		if (turn == 1) { array[0] = 'X'; }
		else { array[0] = 'O'; }
		break;
	case 2:turn = Turn();
		if (turn == 1) { array[1] = 'X'; }
		else { array[1] = 'O'; }
		break;
	case 3:turn = Turn();
		if (turn == 1) { array[2] = 'X'; }
		else { array[2] = 'O'; }
		break;
	case 4:turn = Turn();
		if (turn == 1) { array[3] = 'X'; }
		else { array[3] = 'O'; }
		break;
	case 5:turn = Turn();
		if (turn == 1) { array[4] = 'X'; }
		else { array[4] = 'O'; }
		break;
	case 6:turn = Turn();
		if (turn == 1) { array[5] = 'X'; }
		else { array[5] = 'O'; }
		break;
	case 7:turn = Turn();
		if (turn == 1) { array[6] = 'X'; }
		else { array[6] = 'O'; }
		break;
	case 8:turn = Turn();
		if (turn == 1) { array[7] = 'X'; }
		else { array[7] = 'O'; }
		break;
	case 9:turn = Turn();
		if (turn == 1) { array[8] = 'X'; }
		else { array[8] = 'O'; }
		break;
	default:cout << "Wrong choice there, sport.\n";
		break;
	}
}

// This function will randomly choose to mark any location on the board.
// If the processing takes some time and you see text in fancy colors flickering on the console,
// it is because the rand() is unable to generate the required number, so wait some more.
void AIMoves(char array[])
{
	srand((int)time(NULL));
	int randomMove = rand() % 9;	// Random number between 0 - 8 (Our board indices).

	int turn = Turn();

	// Here I am looking for places which has not been taken yet and also, if it is AI's turn to move.
	if ((array[randomMove] != 'X') && (array[randomMove] != 'O') && (turn == 2))
	{
		// AI making a move because you can't.
		array[randomMove] = 'O';
	}

	// If the random number is unable to find a proper number, call the function again to get such number.
	else
	{
		AIMoves(array);
	}
}

int main()
{
	// Not using a 2D array. See Render() for the trick.
	char array[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	Render(array);
	for (int i = 0; i < 9; ++i)
	{
		// This below condition will check if we can still mark places or not.
		while (array[i] >= '1' && array[i] <= '9')
		{
			GetCoordinates(array);
			Won(array);
			AIMoves(array);
			Won(array);
			Render(array);
		}
	}
}
