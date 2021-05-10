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
			InGame();
			//PauseGame
		}
		else if (press == '2')
		{
			ShowFile();
		}
		else if (press == '3')
		{
			system("cls");
			Ranking();
			Box(124, 75, 27, X_CENTER - 34, Y_CENTER - 15);
			Text("****** TOP 5 BEST PLAYERS ******", 117, X_CENTER - 12, Y_CENTER - 15);
			BigText("Rank.txt", 124, X_CENTER - 15, Y_CENTER - 10);
			Text("Press 'r' to return to the menu screen.", 124, X_CENTER - 10, Y_CENTER - 5);
			char press;
			press = _getch();
			if (press == 'r')
			{
				SetColor(240);
				MenuControl();
			}
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