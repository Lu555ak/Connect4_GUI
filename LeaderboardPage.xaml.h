//
// LeaderboardPage.xaml.h
// Declaration of the LeaderboardPage class
//

#pragma once

#include "LeaderboardPage.g.h"

namespace Connect4___GUI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class LeaderboardPage sealed
	{
	public:
		LeaderboardPage();
	private:
		void back_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PageLoad(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void playersearch(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
		void findplayer_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TextBlock_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
