#pragma once
#include "Level.h"
#include <string>
#include <iostream>

class WindowManager
{
public:
	static void printLevel(Level* level);
	static void clearWindow();
};