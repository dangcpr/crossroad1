#include "Game.h"

void ControlInGame()
{
	while (1)
	{
		char press;
		press = _getch();
		if (press == 'p')
		{
			PauseGame();
			char press1;
			press1 = _getch();
			if (press1 == 'r') {
				ClearScreen(45, 10, X_CENTER + 43, Y_CENTER - 16);
				GoTo(0, 0);
			}
			else if (press1 == 'e') {
				ExitGame();
			}
		}
	}
}
void InGame()
{
	DrawBoard(0, 0, 10, 5.5, 110, 30);
	ControlInGame();
}

void PauseGame()
{
	MENU menu;
	menu.x = X_CENTER + 51;
	menu.y = Y_CENTER - 11;
	Box(124, 45, 10, X_CENTER + 43, Y_CENTER - 16);
	Text("*********** PAUSE ************", 117, menu.x, menu.y - 2);
	Text("   Press 'r' to Resume Game   ", 124, menu.x, menu.y);
	Text("    Press 's' to Save Game    ", 124, menu.x, menu.y + 1);
	Text("    Press 'e' to Exit Game    ", 124, menu.x, menu.y + 2);
}
void ExitGame()
{
	SetColor(255);
	system("cls");
	BigText("ThankYou.txt", 71, 40, 15);
}
void DrawBoard(int row, int col, int x, int y, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		//Sleep(0.8);
		GoTo(x, y + i);
		cout << "|";
	}
	for (int i = 0; i <= height; i += 6)
	{
		for (int j = 0; j <= width; j++)
		{
			//Sleep(0.8);
			GoTo(x + j + 1, y + i - 1);
			cout << "_";
		}
	}
	for (int i = 0; i < height; i++)
	{
		//Sleep(0.8);
		GoTo(x + width + 2, y + i);
		cout << "|";
	}
	GoTo(0, 0);
}
void ClearScreen(int width, int height, int x, int y)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			Text(" ", 255, x + j, y + i);
	}
}