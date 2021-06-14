//
// GameLoadPage.xaml.h
// Declaration of the GameLoadPage class
//

#pragma once

#include "GameLoadPage.g.h"

namespace Connect4___GUI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GameLoadPage sealed
	{
	public:
		GameLoadPage();
	private:
		void load_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void back_button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void player1_ready_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void player2_ready_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PageLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

		void p1_red_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_yellow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_orange_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_blue_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_green_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_purple_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_pink_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p1_brown_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_red_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_yellow_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_orange_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_blue_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_green_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_purple_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_pink_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void p2_brown_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
