//
// GameLoadPage.xaml.cpp
// Implementation of the GameLoadPage class
//

#include "pch.h"
#include "GameLoadPage.xaml.h"
#include "MainPage.xaml.h"
#include "GamePage.xaml.h"
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
using namespace std;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

GameLoadPage::GameLoadPage()
{
	InitializeComponent();
}

// Declaration
player allplayers3[100];
int playernumber3;
bool player1_ready = false, player2_ready = false;
bool player1_finish = false, player2_finish = false;
int player11_index = 0, player22_index = 0;
char fileName[512];

int player1_color, player2_color;
bool player1_color_set = false, player2_color_set = false;

// Load Buttons
void Connect4___GUI::GameLoadPage::load_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_ready && player2_ready)
	{
		ofstream output_file(fileName, ios::app);
		output_file << endl << player1_color;
		output_file << endl << player2_color;
		output_file.close();

		player11_index = NULL;
		player22_index = NULL;
		player1_ready = false; 
		player2_ready = false;
		player1_finish = false; 
		player2_finish = false;
		player1_ready_text->Text = "";
		player2_ready_text->Text = "";
		this->Frame->Navigate(TypeName(GamePage::typeid));
	}
	else
		error_text2->Text = "Players are not ready!";
}


void Connect4___GUI::GameLoadPage::back_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	player11_index = NULL;
	player22_index = NULL;
	player1_ready = false;
	player2_ready = false;
	player1_finish = false;
	player2_finish = false;
	player1_ready_text->Text = "";
	player2_ready_text->Text = "";
	this->Frame->Navigate(TypeName(MainPage::typeid));
}


void Connect4___GUI::GameLoadPage::player1_ready_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	bool player_exists = false;
	LOAD(allplayers3, playernumber3);
	wstring usernameTB(username1_text->Text->Begin());
	string username(usernameTB.begin(), usernameTB.end());
	wstring passwordTB(password1_text->Password->Begin());
	string password(passwordTB.begin(), passwordTB.end());
	if (player1_finish == false)
	{
		for (int i = 0; i < playernumber3; i++)
		{
			if (allplayers3[i].Nickname == username && allplayers3[i].Password == password)
			{
				player_exists = true;
				player11_index = i;

				ofstream output_file(fileName, ios::app);
				if (player2_ready)
					output_file << player11_index;
				else
					output_file << player11_index << endl;
				output_file.close();
				break;
			}
			else
			{
				error_text2->Text = "Player does not exist";
			}
		}

		if (player_exists)
		{
			if (player2_ready)
			{
				if (allplayers3[player11_index].Nickname != allplayers3[player22_index].Nickname && allplayers3[player11_index].Password != allplayers3[player22_index].Nickname)
				{
					player1_ready = true;
					player1_finish = true;
					error_text2->Text = "";
					username1_text->Text = "";
					password1_text->Password = "";
					player1_ready_text->Text = "READY!";
					player1_ready_button->Content = lock_symbol->Content;
				}
				else
				{
					error_text2->Text = "You can not play against yourself!";
				}
			}
			else
			{
				player1_ready = true;
				player1_finish = true;
				error_text2->Text = "";
				username1_text->Text = "";
				password1_text->Password = "";
				player1_ready_text->Text = "READY!";
				player1_ready_button->Content = lock_symbol->Content;
			}
		}
	}
	else
	{
		error_text2->Text = "Player 1 is ready!";
		username1_text->Text = "";
		password1_text->Password = "";
	}
	SAVE(allplayers3, playernumber3);
}


void Connect4___GUI::GameLoadPage::player2_ready_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	bool player_exists = false;
	LOAD(allplayers3, playernumber3);
	wstring usernameTB(username2_text->Text->Begin());
	string username(usernameTB.begin(), usernameTB.end());
	wstring passwordTB(password2_text->Password->Begin());
	string password(passwordTB.begin(), passwordTB.end());
	if (player2_finish == false)
	{
		for (int i = 0; i < playernumber3; i++)
		{
			if (allplayers3[i].Nickname == username && allplayers3[i].Password == password)
			{
				player_exists = true;
				player22_index = i;
				
				ofstream output_file(fileName, ios::app);
				if (player1_ready)
					output_file << player22_index;
				else
					output_file << player22_index << endl;
				output_file.close();
				break;
			}
			else
			{
				error_text2->Text = "Player does not exist";
			}
		}

		if (player_exists)
		{
			if (player1_ready)
			{
				if (allplayers3[player22_index].Nickname != allplayers3[player11_index].Nickname && allplayers3[player22_index].Password != allplayers3[player11_index].Nickname)
				{
					player2_ready = true;
					player2_finish = true;
					error_text2->Text = "";
					username2_text->Text = "";
					password2_text->Password = "";
					player2_ready_text->Text = "READY!";
					player2_ready_button->Content = lock_symbol->Content;

				}
				else
				{
					error_text2->Text = "You can not play against yourself!";
				}
			}
			else
			{
				player2_ready = true;
				player2_finish = true;
				error_text2->Text = "";
				username2_text->Text = "";
				password2_text->Password = "";
				player2_ready_text->Text = "READY!";
				player2_ready_button->Content = lock_symbol->Content;
			}
		}
	}
	else
	{
		error_text2->Text = "Player 2 is ready!";
		username2_text->Text = "";
		password2_text->Password = "";
	}
	SAVE(allplayers3, playernumber3);
}


void Connect4___GUI::GameLoadPage::PageLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Platform::String^ localfolder = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring folderNameW(localfolder->Begin());
	std::string folderNameA(folderNameW.begin(), folderNameW.end());
	const char* charStr = folderNameA.c_str();
	sprintf(fileName, "%s\\indexes.txt", charStr);

	ofstream output_file(fileName, ios::trunc);
	output_file.close();

	player1_color = 1;
	player2_color = 2;
}


void Connect4___GUI::GameLoadPage::p1_red_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 1)
	{
		player1_color = 1;
		player1_ready_button->Background = p1_red->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_yellow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 2)
	{
		player1_color = 2;
		player1_ready_button->Background = p1_yellow->Background;
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
	error_text2->Text = "";
}


void Connect4___GUI::GameLoadPage::p1_orange_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 3)
	{
		player1_color = 3;
		player1_ready_button->Background = p1_orange->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_blue_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 4)
	{
		player1_color = 4;
		player1_ready_button->Background = p1_blue->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_green_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 5)
	{
		player1_color = 5;
		player1_ready_button->Background = p1_green->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_purple_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 6)
	{
		player1_color = 6;
		player1_ready_button->Background = p1_purple->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_pink_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 7)
	{
		player1_color = 7;
		player1_ready_button->Background = p1_pink->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p1_brown_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player2_color != 8)
	{
		player1_color = 8;
		player1_ready_button->Background = p1_brown->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 2 has already selected this color!";
}


//Player2 Colors
void Connect4___GUI::GameLoadPage::p2_red_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 1)
	{
		player2_color = 1;
		player2_ready_button->Background = p2_red->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_yellow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 2)
	{
		player2_color = 2;
		player2_ready_button->Background = p2_yellow->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_orange_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 3)
	{
		player2_color = 3;
		player2_ready_button->Background = p2_orange->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_blue_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 4)
	{
		player2_color = 4;
		player2_ready_button->Background = p2_blue->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_green_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 5)
	{
		player2_color = 5;
		player2_ready_button->Background = p2_green->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_purple_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 6)
	{
		player2_color = 6;
		player2_ready_button->Background = p2_purple->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_pink_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 7)
	{
		player2_color = 7;
		player2_ready_button->Background = p2_pink->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}


void Connect4___GUI::GameLoadPage::p2_brown_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (player1_color != 8)
	{
		player2_color = 8;
		player2_ready_button->Background = p2_brown->Background;
		error_text2->Text = "";
	}
	else
		error_text2->Text = "Player 1 has already selected this color!";
}
