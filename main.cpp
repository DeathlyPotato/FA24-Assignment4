/*
Name: Chen, Isaac, 2002582920, CS 135 1001, 
Assignment FA 24 - Assignment 4
Description: Creating a C++ program that makes a piggy
bank game. You will be able to ask again.
Input: Replay (yes or no), amount of coins (1 or 2)
Output: A piggy bank game
*/

#include <iostream>
#include <string>

using namespace std;

//Constants
const int MIN_BANK_SIZE = 5;
const int MAX_BANK_SIZE = 50;

const string DASHES = "---------------";
const string BANK_MSG = "Please enter the size of the bank";
const string COINS_MSG = "Please enter the number of coins you would like to play (1 or 2)";
const string AGAIN_MSG = "Would you like to play again? (y/n)";
const string PLAYED_MSG = "Total games played : ";
const string INT_READ_ERR_MSG = "Invalid number, please try again";
const string CHAR_READ_ERR_MSG = "Invalid choice. Please type 'y' for yes or 'n' for no";

//This program is intended to give some practice with iteration (for and while loops)
//You are asked to implement the game described in the accompanying pdf.
//Please use the pdf and the description comments to implement the game
int main()
{
	//YOUR CODE HERE
	
	//Prompt the user and ask for the bank size using the provided variable
	//Error check the bankSize variable to make sure it is between the min and max size. If not, print an error message
		/*If the entered value is incorrect, re-prompt the user until they enter a valid number
		(HINT: Remember that .fail() can be used to check for bad reads. The read must succeed before we can even
		check if it is in bounds)*/
	int bankSize = -1;

	cout << BANK_MSG << endl;

	do {
		cin >> bankSize;

		if ((cin.fail()) || (bankSize < 5) || (bankSize > 50)) {
			cout << "Invalid number, please try again" << endl;
			cin.clear();
		}
	} while ((cin.fail()) || (bankSize < 5) || (bankSize > 50));

	//The following code is provided for you for reference. The code prints the initial bank to the screen.
	//Consider copy-pasting and modifying this code to fit your needs
	cout << "Initial Bank (0/ " << bankSize << ")" << endl;	//Print header
	for (int row = 0; row < bankSize; row++) {	//Repeat the code as many times as there are rows in the piggy bank
		cout << "| |" << endl; //Print each row of the piggy bank (left wall, middle, right wall) in the for loop
	}					
	cout << " - " << endl << endl;				//Print the bottom of the piggy bank after the for loop is done

	//YOUR CODE HERE
	int gameNumber = 1;
	int currentCoins = 0;
	int currentPlayer = 1;
	int addCoin = 0;
	string playAgain = "y";

	while (playAgain == "y") {
		cout << "Game " << gameNumber << endl << endl;

		while (currentCoins < bankSize) {
			cout << DASHES << "Player " << currentPlayer << " turn" << DASHES << endl;
			cout << COINS_MSG << endl;
			do {
				cin >> addCoin;
				if ((cin.fail()) || (addCoin != 1 && addCoin !=2)) {
					cout << INT_READ_ERR_MSG << endl;
				}
			} while ((cin.fail()) || (addCoin != 1 && addCoin !=2));

			currentCoins += addCoin;

			cout << "Bank: (" << currentCoins << "/ " << bankSize << ")" << endl;

			if (currentCoins > bankSize) {
				for (int row = 0; row < (currentCoins -1); row++) {
					cout << "|0|" << endl;
				}	
			} else if (currentCoins < bankSize) {
				for (int row = 0; row < bankSize - currentCoins; row++) {
					cout << "| |" << endl;
				}
			}
			if (!(currentCoins > bankSize)) {
			for (int row = 0; row < currentCoins; row++) {
				cout << "|0|" << endl;
			}					
			}
			cout << " - " << endl << endl;

			if (currentPlayer == 1) {
				currentPlayer += 1;
			} else if (currentPlayer == 2) {
				currentPlayer -= 1;
			}
		}

		if (currentCoins == bankSize) {
			if (currentPlayer == 1) {
				currentPlayer += 1;
			} else if (currentPlayer == 2) {
				currentPlayer -= 1;
			}
			cout << "Player " << currentPlayer << " wins!" << endl;
		}
		if (currentCoins > bankSize) {
			cout << "Player " << currentPlayer << " wins!" << endl;
		}
		
		cout << "Would you like to play again? (y/n)" << endl;

		do {
			cin >> playAgain;
			
			if ((playAgain != "y") && (playAgain != "n")) {
				cout << "Invalid choice. Please type 'y' for yes or 'n' for no" << endl;
				cin.clear();
			}

			if (playAgain == "y") {
				gameNumber+= 1;
				currentCoins = 0;

			} else if (playAgain == "n") {
				cout << "Total games played : " << gameNumber << endl;
				return 0;
			}
			} while ((playAgain != "y") && (playAgain != "n"));

	}
	

	//Create any variables you think you need to play the game

	/* Below is one possible algorithm for playing the game(instructor solution). You are encouraged to try and think of your own solution
	* before using the below description. Your solution does not need to be the same, the below is only a suggested strategy.
	* It is recommended to start with tasks at the smallest scope (biggest indent in suggested strategy), test, and work your way
	* outwards. That is, try to solve the sub-problems or shorter pieces of code like getting the number of coins a player
	* wants to play or printing messages before adding the loop that repeats that code. Try doing one player turn first and then
	* worry about repeating player turns and playing multiple games!
	*/

	//While the user wants to keep playing, keep playing the game
		//Set up the game by initializing game-related variables	
		//Play the game until someone wins
			//Player Turn
				//Print whose turn it is (Player 1 or Player 2)
				//Ask the player to enter the number of coins they want to put into the bank
				//Read the number from the player. Repeat asking and reading until they enter a valid number of coins (1 or 2)
				//After the player enters a valid number of coins, add those coins to the bank
				//Print the state of the bank
			//Check if the player won. If so, end the game
			//If they're still playing, change whose turn it is. Player 1 <-> Player 2
		//When the game is done, print a message saying which player won and end the game
		//Count the game as finished and add to the count of total games played 
		//Once the game is over, ask if they want to play again. If not, stop playing
			//Prompt the user if they want to play again
			//Error check their input. They must enter a "y" for yes or 'n' for no

	return 0;
}