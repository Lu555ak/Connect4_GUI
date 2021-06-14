//
// LeaderboardPage.xaml.cpp
// Implementation of the LeaderboardPage class
//

#include "pch.h"
#include "LeaderboardPage.xaml.h"
#include "MainPage.xaml.h"
#include "load_save.h"
#include "players.h"
#include <fstream>
#include <string>
#include <sstream>
#include <utility>

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

// Declaration
player allplayers4[100];
int playernumber4;
player allplayers5[100];

LeaderboardPage::LeaderboardPage()
{
	InitializeComponent();
}

String^ StringToPlatfromString(std::string& String1)
{
    Platform::String^ String2;
    std::wstring wstring_temp(String1.begin(), String1.end());
    String2 = ref new String(wstring_temp.c_str());
    return String2;
}


void Connect4___GUI::LeaderboardPage::back_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(MainPage::typeid));
    TextBlock^ top10[2][10] = {
        {r1n, r2n, r3n, r4n, r5n, r6n, r7n, r8n, r9n, r10n},
        {r1s, r2s, r3s, r4s, r5s, r6s, r7s, r8s, r9s, r10s}
    };
    for (int i = 0; i < 10; i++) {
        top10[0][i]->Text = "";
        top10[1][i]->Text = "";
    }
    for (int i = 0; i < playernumber4; i++) {
        allplayers4[i].Nickname = "";
        allplayers4[i].Password = "";
        allplayers4[i].Win = NULL;
        allplayers4[i].Even = NULL;
        allplayers4[i].Loss = NULL;
    }
    SAVE(allplayers5, playernumber4);
}


void Connect4___GUI::LeaderboardPage::PageLoad(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    TextBlock^ top10[2][10] = {
        {r1n, r2n, r3n, r4n, r5n, r6n, r7n, r8n, r9n, r10n},
        {r1s, r2s, r3s, r4s, r5s, r6s, r7s, r8s, r9s, r10s}
    };
    stringstream ss[10];
    stringstream nicknames[10];
    LOAD(allplayers5, playernumber4);
    for (int i = 0; i < playernumber4; i++) {
        allplayers4[i] = allplayers5[i];
    }
    wstring usernameTB(username_text->Text->Begin());
    string username(usernameTB.begin(), usernameTB.end());
    for (int i = 0; i < playernumber4 - 1; i++) {
        for (int j = 0; j < playernumber4 - i - 1; j++) {
            if (allplayers4[j].Win < allplayers4[j + 1].Win || allplayers4[j].Win == allplayers4[j+1].Win && allplayers4[j].Loss > allplayers4[j+1].Loss || allplayers4[j].Win == allplayers4[j + 1].Win && allplayers4[j].Loss == allplayers4[j + 1].Loss && allplayers4[j].Even < allplayers4[j+1].Even) {
                swap(allplayers4[j], allplayers4[j + 1]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ss[i] << "Win: " << to_string(allplayers4[i].Win) << "\nEven: " << to_string(allplayers4[i].Even) << "\nLoss: " << to_string(allplayers4[i].Loss);
        nicknames[i] << "#" << i+1 << " " << allplayers4[i].Nickname;
    }
    for (int i = 0; i < 10; i++) {
        if (allplayers4[i].Nickname != "") {
            top10[0][i]->Text = StringToPlatfromString(nicknames[i].str());
            top10[1][i]->Text = StringToPlatfromString(ss[i].str());
        }
    }
}


void Connect4___GUI::LeaderboardPage::playersearch(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}

void Connect4___GUI::LeaderboardPage::findplayer_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    stringstream ss;
    wstring usernameTB(username_text->Text->Begin());
    string username(usernameTB.begin(), usernameTB.end());
    for (int i = 0; i < playernumber4; i++) {
        if (username == allplayers5[i].Nickname) {
            ss << "Win: " << to_string(allplayers5[i].Win) << "\nEven: " << to_string(allplayers5[i].Even) << "\nLoss: " << to_string(allplayers5[i].Loss);
            rss->Text = StringToPlatfromString(ss.str());
            break;
        }
        else {
            rss->Text = "Player not found!";
            break;
        }
    }
}


void Connect4___GUI::LeaderboardPage::TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
