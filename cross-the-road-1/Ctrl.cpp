#include "Menu.h"
#include "Data.h"
#include "Ctrl.h"

void MenuControl()
{
	DisplayMenu();
	char press;
	do
	{
		press = _getch();
		if (press == '1')
		{
			system("cls");
			DrawBoard(0, 0, 10, 5.5, 110, 30);
			//PauseGame
		}
		else if (press == '2')
		{
			ShowFile();
		}
		else if (press == '3')
		{
		}
		else if (press == '4')
		{
			system("cls");
			Help();
		}
	} while (press != 'e');
	system("cls");
	ExitGame();
	return;
}