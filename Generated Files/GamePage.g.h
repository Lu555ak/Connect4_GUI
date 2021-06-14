﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Image;
                ref class Button;
                ref class TextBlock;
            }
        }
    }
}

namespace Connect4___GUI
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class GamePage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        void UnloadObject(::Windows::UI::Xaml::DependencyObject^ dependencyObject);
        void DisconnectUnloadedObject(int connectionId);
    
    private:
        bool _contentLoaded;
    
        class GamePage_obj1_Bindings;
    
        private: ::Windows::UI::Xaml::Controls::Image^ red_color;
        private: ::Windows::UI::Xaml::Controls::Image^ yellow_color;
        private: ::Windows::UI::Xaml::Controls::Image^ empty_color;
        private: ::Windows::UI::Xaml::Controls::Image^ gb00;
        private: ::Windows::UI::Xaml::Controls::Image^ gb01;
        private: ::Windows::UI::Xaml::Controls::Image^ gb02;
        private: ::Windows::UI::Xaml::Controls::Image^ gb03;
        private: ::Windows::UI::Xaml::Controls::Image^ gb04;
        private: ::Windows::UI::Xaml::Controls::Image^ gb05;
        private: ::Windows::UI::Xaml::Controls::Image^ gb06;
        private: ::Windows::UI::Xaml::Controls::Image^ gb10;
        private: ::Windows::UI::Xaml::Controls::Image^ gb11;
        private: ::Windows::UI::Xaml::Controls::Image^ gb12;
        private: ::Windows::UI::Xaml::Controls::Image^ gb13;
        private: ::Windows::UI::Xaml::Controls::Image^ gb14;
        private: ::Windows::UI::Xaml::Controls::Image^ gb15;
        private: ::Windows::UI::Xaml::Controls::Image^ gb16;
        private: ::Windows::UI::Xaml::Controls::Image^ gb20;
        private: ::Windows::UI::Xaml::Controls::Image^ gb21;
        private: ::Windows::UI::Xaml::Controls::Image^ gb22;
        private: ::Windows::UI::Xaml::Controls::Image^ gb23;
        private: ::Windows::UI::Xaml::Controls::Image^ gb24;
        private: ::Windows::UI::Xaml::Controls::Image^ gb25;
        private: ::Windows::UI::Xaml::Controls::Image^ gb26;
        private: ::Windows::UI::Xaml::Controls::Image^ gb30;
        private: ::Windows::UI::Xaml::Controls::Image^ gb31;
        private: ::Windows::UI::Xaml::Controls::Image^ gb32;
        private: ::Windows::UI::Xaml::Controls::Image^ gb33;
        private: ::Windows::UI::Xaml::Controls::Image^ gb34;
        private: ::Windows::UI::Xaml::Controls::Image^ gb35;
        private: ::Windows::UI::Xaml::Controls::Image^ gb36;
        private: ::Windows::UI::Xaml::Controls::Image^ gb40;
        private: ::Windows::UI::Xaml::Controls::Image^ gb41;
        private: ::Windows::UI::Xaml::Controls::Image^ gb42;
        private: ::Windows::UI::Xaml::Controls::Image^ gb43;
        private: ::Windows::UI::Xaml::Controls::Image^ gb44;
        private: ::Windows::UI::Xaml::Controls::Image^ gb45;
        private: ::Windows::UI::Xaml::Controls::Image^ gb46;
        private: ::Windows::UI::Xaml::Controls::Image^ gb50;
        private: ::Windows::UI::Xaml::Controls::Image^ gb51;
        private: ::Windows::UI::Xaml::Controls::Image^ gb52;
        private: ::Windows::UI::Xaml::Controls::Image^ gb53;
        private: ::Windows::UI::Xaml::Controls::Image^ gb54;
        private: ::Windows::UI::Xaml::Controls::Image^ gb55;
        private: ::Windows::UI::Xaml::Controls::Image^ gb56;
        private: ::Windows::UI::Xaml::Controls::Button^ column0_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column1_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column2_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column3_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column4_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column5_button;
        private: ::Windows::UI::Xaml::Controls::Button^ column6_button;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ display;
        private: ::Windows::UI::Xaml::Controls::Image^ turn_display;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ player_display;
        private: ::Windows::UI::Xaml::Controls::Image^ blue_color;
        private: ::Windows::UI::Xaml::Controls::Image^ purple_color;
        private: ::Windows::UI::Xaml::Controls::Image^ pink_color;
        private: ::Windows::UI::Xaml::Controls::Image^ green_color;
        private: ::Windows::UI::Xaml::Controls::Image^ brown_color;
        private: ::Windows::UI::Xaml::Controls::Image^ orange_color;
        private: ::Windows::UI::Xaml::Controls::Image^ player1_c;
        private: ::Windows::UI::Xaml::Controls::Image^ player2_c;
    };
}

