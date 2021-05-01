#include "Game.h"

void ControlInGame()
{
	while (1)
	{

	}
}
void InGame()
{
	DrawBoard(0, 0, 10, 5.5, 110, 30);
}
void PauseGame()
{
	Box(124, 53, 13, X_CENTER - 25, Y_CENTER + 5);
}
void ExitGame()
{
	BigText("ThankYou.txt", 71, 40, 15);
	Sleep(3000);
	SetColor(255);
}
void DrawBoard(int row, int col, int x, int y, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		//Sleep(1);
		GoTo(x, y + i);
		cout << "|";
	}
	for (int i = 0; i <= height; i += 6)
	{
		for (int j = 0; j <= width; j++)
		{
			//Sleep(1);
			GoTo(x + j + 1, y + i - 1);
			cout << "_";
		}
	}
	for (int i = 0; i < height; i++)
	{
		//Sleep(1);
		GoTo(x + width + 2, y + i);
		cout << "|";
	}
	GoTo(0, 0);
	_getch();
}