#pragma once
#ifndef LOAD_SAVE
#define LOAD_SAVE

#include <fstream>
#include "players.h"
void SAVE(player allplayers[], int& playernumber);
void LOAD(player allplayers[], int& playernumber);
Platform::String^ StringToPlatfromString(std::string& String1);
#endif