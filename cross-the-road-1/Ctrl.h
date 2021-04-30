#pragma once
#include "Menu.h"
#include "Data.h"
#include "Ctrl.h"

void MenuControl()
{
	DisplayMenu();
	char press;
	press = _getch();
	if (press == '1')
	{ }
	else if (press == '2')
	{ }
	else if (press == '3')
	{ }
	else if (press == '4')
	{
		system("cls");
		Help();
	}
}