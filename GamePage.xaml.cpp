//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "MainPage.xaml.h"
#include "load_save.h"
#include "players.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace Connect4___GUI;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;
using namespace std;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

GamePage::GamePage()
{
	InitializeComponent();
}

// Declaration
int gameBoard[6][7] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
};
int playerTurn = 1;
int playernumber = 0;
bool first_load = false;
player allplayers[100];
string player1_name, player2_name;
int player1_index = 0, player2_index = 0;
int player11_color, player22_color;


// Utility Functions
void gameBoardReset(int gameboard[6][7]) // Reset gameboard to 0
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
	SAVE(allplayers, playernumber);
}

// Game Handling Functions
void PlayerTurn(int& player) // Changes between Player1 & Player2
{
	if (player == 1)
		player = 2;
	else if (player == 2)
		player = 1;
}

void ColumnInput(int gameBoard[6][7], int columnNumber, int& playerTurn, Image^ TurnDisplay, TextBlock^& PlayerDisplay, Image^ p1, Image^ p2) // Takes input
{
	int rowCount = 5;
	while (rowCount >= 0) {
		if (gameBoard[rowCount][columnNumber] == 0) {
			gameBoard[rowCount][columnNumber] = playerTurn;
			PlayerTurn(playerTurn);
			break;
		}
		rowCount--;
	}
	if (playerTurn == 2)
	{
		TurnDisplay->Source = p2->Source;
		PlayerDisplay->Text = StringToPlatfromString(player2_name);
	}
	else if (playerTurn == 1)
	{
		TurnDisplay->Source = p1->Source;
		PlayerDisplay->Text = StringToPlatfromString(player1_name);
	}

}

int VictoryCheck(int gameBoard[6][7]) // Returns player ID (1 || 2) or returns 3 for a draw
{
	bool allFieldsAreFull = true; // Even Check
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (gameBoard[i][j] == 0)
				allFieldsAreFull = false;
		}
	}
	if (allFieldsAreFull)
		return 3;

	for (int i = 0; i < 6; i++) { // Horizontal Check
		for (int j = 0; j < 4; j++) {
			if (gameBoard[i][j] == gameBoard[i][j + 1] && gameBoard[i][j + 2] == gameBoard[i][j + 3] && gameBoard[i][j] == gameBoard[i][j + 3] && gameBoard[i][j] != 0)
				return gameBoard[i][j];
		}
	}
	for (int i = 0; i < 3; i++) { // Vertical Check
		for (int j = 0; j < 6; j++) {
			if (gameBoard[i][j] == gameBoard[i + 1][j] && gameBoard[i + 2][j] == gameBoard[i + 3][j] && gameBoard[i][j] == gameBoard[i + 3][j] && gameBoard[i][j] != 0)
				return gameBoard[i][j];
		}
	}
	for (int i = 0; i < 3; i++) { // Left Diagonal Check
		for (int j = 0; j < 4; j++) {
			if (gameBoard[i][j] == gameBoard[i + 1][j + 1] && gameBoard[i + 2][j + 2] == gameBoard[i + 3][j + 3] && gameBoard[i][j] == gameBoard[i + 3][j + 3] && gameBoard[i][j] != 0)
				return gameBoard[i][j];
		}
	}
	for (int i = 3; i < 6; i++) { // Right Diagonal Check
		for (int j = 0; j < 3; j++) {
			if (gameBoard[i][j] == gameBoard[i - 1][j + 1] && gameBoard[i - 2][j + 2] == gameBoard[i - 3][j + 3] && gameBoard[i][j] == gameBoard[i - 3][j + 3] && gameBoard[i][j] != 0)
				return gameBoard[i][j];
		}
	}
	return 0;
}

bool WinnerDisplay(player allplayers[], int gameBoard[6][7], int player1_index, int player2_index, TextBlock^ display) // Displays the winner
{
	bool winner = false;
	if (VictoryCheck(gameBoard) == 1) {
		display->Text = "Player 1 is the winner";
		allplayers[player1_index].Win++;
		allplayers[player2_index].Loss++;
		winner = true;
		return winner;
	}
	else if (VictoryCheck(gameBoard) == 2) {
		display->Text = "Player 2 is the winner!";
		allplayers[player1_index].Loss++;
		allplayers[player2_index].Win++;
		winner = true;
		return winner;
	}
	else if (VictoryCheck(gameBoard) == 3) {
		display->Text = "Even!";
		allplayers[player1_index].Even++;
		allplayers[player2_index].Even++;
		winner = true;
		return winner;
	}
	return false;
}

void Connect4___GUI::GamePage::LoadGameBoard()
{
	Image^ gameBoardGUI[6][7] =
	{
		{gb00, gb01, gb02, gb03, gb04, gb05, gb06},
		{gb10, gb11, gb12, gb13, gb14, gb15, gb16},
		{gb20, gb21, gb22, gb23, gb24, gb25, gb26},
		{gb30, gb31, gb32, gb33, gb34, gb35, gb36},
		{gb40, gb41, gb42, gb43, gb44, gb45, gb46},
		{gb50, gb51, gb52, gb53, gb54, gb55, gb56}
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (gameBoard[i][j] == 1)
				gameBoardGUI[i][j]->Source = player1_c->Source;
			else if (gameBoard[i][j] == 2)
				gameBoardGUI[i][j]->Source = player2_c->Source;
		}
	}
}


// Gameplay Buttons
void Connect4___GUI::GamePage::column0_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 0, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column1_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 1, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column2_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 2, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column3_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 3, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column4_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 4, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column5_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 5, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::column6_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ColumnInput(gameBoard, 6, playerTurn, turn_display, player_display, player1_c, player2_c);
	LoadGameBoard();
	if (WinnerDisplay(allplayers, gameBoard, player1_index, player2_index, display))
	{
		gameBoardReset(gameBoard);
		LoadGameBoard();
		this->Frame->Navigate(TypeName(MainPage::typeid));
	}
}


void Connect4___GUI::GamePage::game_loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	LOAD(allplayers, playernumber);

	Platform::String^ localfolder = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring folderNameW(localfolder->Begin());
	std::string folderNameA(folderNameW.begin(), folderNameW.end());
	const char* charStr = folderNameA.c_str();
	char fileName[512];
	sprintf(fileName, "%s\\indexes.txt", charStr);

	string read[4];
	ifstream input_file(fileName);
	if (input_file.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			getline(input_file, read[i]);
		}
	}

	input_file.close();
	player1_index = stoi(read[0]);
	player2_index = stoi(read[1]);
	player11_color = stoi(read[2]);
	player22_color = stoi(read[3]);


	if (player11_color == 1)
		player1_c->Source = red_color->Source;
	else if (player11_color == 2)
		player1_c->Source = yellow_color->Source;
	else if (player11_color == 3)
		player1_c->Source = orange_color->Source;
	else if (player11_color == 4)
		player1_c->Source = blue_color->Source;
	else if (player11_color == 5)
		player1_c->Source = green_color->Source;
	else if (player11_color == 6)
		player1_c->Source = purple_color->Source;
	else if (player11_color == 7)
		player1_c->Source = pink_color->Source;
	else if (player11_color == 8)
		player1_c->Source = brown_color->Source;
	else
		player1_c->Source = red_color->Source;

	if (player22_color == 1)
		player2_c->Source = red_color->Source;
	else if (player22_color == 2)
		player2_c->Source = yellow_color->Source;
	else if (player22_color == 3)
		player2_c->Source = orange_color->Source;
	else if (player22_color == 4)
		player2_c->Source = blue_color->Source;
	else if (player22_color == 5)
		player2_c->Source = green_color->Source;
	else if (player22_color == 6)
		player2_c->Source = purple_color->Source;
	else if (player22_color == 7)
		player2_c->Source = pink_color->Source;
	else if (player22_color == 8)
		player2_c->Source = brown_color->Source;
	else
		player2_c->Source = yellow_color->Source;

	player1_name = allplayers[player1_index].Nickname;
	player2_name = allplayers[player2_index].Nickname;
	turn_display->Source = player1_c->Source;
	player_display->Text = StringToPlatfromString(player1_name);
}
