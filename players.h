#pragma once
#ifndef PLAYERS
#define PLAYERS

#include <string>
struct player
{
	std::string Nickname;
	std::string Password;
	int Win = 0;
	int Even = 0;
	int Loss = 0;
};
#endif