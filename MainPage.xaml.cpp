//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//
#include "pch.h"
#include "MainPage.xaml.h"
#include "GameLoadPage.xaml.h"
#include "LeaderboardPage.xaml.h"
#include "load_save.h"
#include "players.h"
#include <fstream>
#include <string>

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
using namespace Windows::Storage;
using namespace std;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}

// Declaration
player allplayers2[10];
int playernumber2;

// Binary file handling
void SAVE(player allplayers[], int& playernumber) // Saves player’s data to a binary file
{
	Platform::String^ localfolder = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring folderNameW(localfolder->Begin());
	std::string folderNameA(folderNameW.begin(), folderNameW.end());
	const char* charStr = folderNameA.c_str();
	char fileName[512];
	sprintf(fileName, "%s\\players.txt", charStr);

	ofstream output_file(fileName, ios::binary | std::ofstream::trunc);
	for (int i = 0; i < playernumber; i++) {
		output_file.write((char*)&allplayers[i], sizeof(allplayers[i]));
	}
	output_file.close();
	playernumber = 0;
}

void LOAD(player allplayers[], int& playernumber) // Load player’s data from a binary file
{
	Platform::String^ localfolder = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring folderNameW(localfolder->Begin());
	std::string folderNameA(folderNameW.begin(), folderNameW.end());
	const char* charStr = folderNameA.c_str();
	char fileName[512];
	sprintf(fileName, "%s\\players.txt", charStr);

	ifstream input_file(fileName, ios::binary);
	if (input_file.is_open())
	{
		while (input_file.good())
		{
			input_file.read((char*)&allplayers[playernumber], sizeof(allplayers[playernumber]));
			playernumber++;
		}
		playernumber--;
	}
	input_file.close();
}


// GUI Buttons
void Connect4___GUI::MainPage::play_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	LOAD(allplayers2, playernumber2);
	if (playernumber2 > 1)
	{
		username_text->Text = "";
		password_text->Password = "";
		this->Frame->Navigate(TypeName(GameLoadPage::typeid));
	}
	else
		error_text->Text = "You need at least 2 players to play the game!";
	SAVE(allplayers2, playernumber2);
}

void Connect4___GUI::MainPage::leaderboard_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	username_text->Text = "";
	password_text->Password = "";
	this->Frame->Navigate(TypeName(LeaderboardPage::typeid));
}

void Connect4___GUI::MainPage::quit_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Application::Current->Exit();
}


void Connect4___GUI::MainPage::addplayer_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) // Add player
{
	LOAD(allplayers2, playernumber2);
	bool player_exists = false;
	wstring usernameTB(username_text->Text->Begin());
	string username(usernameTB.begin(), usernameTB.end());
	wstring passwordTB(password_text->Password->Begin());
	string password(passwordTB.begin(), passwordTB.end());
	for (int i = 0; i < playernumber2; i++)
	{
		if (allplayers2[i].Nickname == username && allplayers2[i].Password == password)
			player_exists = true;
		break;
	}
	if (player_exists == false && username != "" && password != "")
	{
		allplayers2[playernumber2].Nickname = username;
		allplayers2[playernumber2].Password = password;
		allplayers2[playernumber2].Win = 0;
		allplayers2[playernumber2].Even = 0;
		allplayers2[playernumber2].Loss = 0;
		playernumber2++;
		username_text->Text = "";
		password_text->Password = "";
		error_text->Text = "";
	}
	else
		error_text->Text = "Error: Player already exists!";
	SAVE(allplayers2, playernumber2);
}

void Connect4___GUI::MainPage::deleteplayer_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	wstring usernameTB(username_text->Text->Begin());
	string username(usernameTB.begin(), usernameTB.end());
	wstring passwordTB(password_text->Password->Begin());
	string password(passwordTB.begin(), passwordTB.end());
	if (username == "Admin" && password == "Admin") {
		playernumber2 = 0;
		SAVE(allplayers2, playernumber2);
		username_text->Text = "";
		password_text->Password = "";
		error_text->Text = "";
		error_text->Text = "Players are cleared!";
	}
	else {
		username_text->Text = "";
		password_text->Password = "";
		error_text->Text = "";
		error_text->Text = "You have no premission to do that!";
	}
}
