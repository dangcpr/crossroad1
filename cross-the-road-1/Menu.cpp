#include"Menu.h"
//OK
void CreateConsoleWindow(int pWidth, int pHeight)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, pWidth, pHeight, TRUE);
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GoTo(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Ham do hoa
void SetColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void Text(string name, int color, int x, int y)
{
	GoTo(x, y);
	SetColor(color);
	cout << name;

}
void Box(int color, int width, int height, int x, int y)
{
	SetColor(color);
	for (int i = 0; i < height; i++)
	{
		GoTo(x, y + i);
		for (int j = 0; j < width; j++)
		{
			cout << " ";
		}
	}
	SetColor(240);
}
void BoxLoading(int color, int width, int height, int x, int y)
{
	SetColor(color);
	int n = 0;
	for (int i = 0; i < height; i++)
	{
		GoTo(x, y + i);
		for (int j = 0; j < width; j++)
		{
			Sleep(100);
			cout << " ";
			n++;
			SetColor(124);
			Text(to_string(n), 124, x, y + 1);
			GoTo(x + j, y);
		}
	}

}
void BigText(string filename, int color, int x, int y)
{
	fstream f;
	f.open(filename, ios::in);

	string line;
	vector<string> subline;
	while (!f.eof())
	{
		getline(f, line);
		subline.push_back(line);
	}
	for (int i = 0; i < subline.size(); i++)
		Text(subline[i], color, x, y++);
	f.close();
}
//Man hinh menu
MENU DisplayMenu()
{
	MENU menu;
	menu.choices = 3;
	menu.x = X_CENTER - 13;
	menu.y = Y_CENTER + 10;
	
	system("cls");

	BigText("Logo.txt", 240, 20, 3);
	BigText("LogoCar.txt", 240, 43, 15);
	Box(124, 50, 13, X_CENTER - 25, Y_CENTER + 5);
	Text("********** MENU ***********\n", 124, menu.x, menu.y - 2);
	Text("   Press 1 to Start Game   ", 124, menu.x, menu.y);
	Text("   Press 2 to Load Game    ", 124, menu.x, menu.y + 1);
	Text("    Press 3 to Ranking     ", 124, menu.x, menu.y + 2);
	Text("      Press 4 to Help      ", 124, menu.x, menu.y + 3);
	Text("    Press E to Exit Game   ", 124, menu.x, menu.y + 4);
	SetColor(240);
	return menu;
}
void Help()
{
	Box(124, 75, 27, X_CENTER - 34, Y_CENTER - 15);
	BigText("Help.txt", 124, X_CENTER - 15, Y_CENTER - 10);
	SetColor(240);
}
/*void DrawBoard(int row, int col, int x, int y, int width, int height)
{
	GoTo(x, y);
	cout << TOP_LEFT;
	DrawTableLine(col, HORIZONTAL_LINE, TOP_CROSS, width);
	cout << TOP_RIGHT;

	for (int i = 0; i < (row - 1) * (height + 1); i++)
	{
		GotoXY(x, y + i + 1);
		if ((i + 1) % (height + 1) != 0)
		{
			cout << VERTICAL_LINE;
			DrawTableLine(col, SPACE, VERTICAL_LINE, width);
			cout << VERTICAL_LINE;
		}
		else
		{
			cout << LEFT_CROSS;
			DrawTableLine(col, HORIZONTAL_LINE, CROSS, width);
			cout << RIGHT_CROSS;
		}
	}
	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + (row - 1) * (height + 1) + 1 + i);
		cout << VERTICAL_LINE;
		DrawTableLine(col, SPACE, VERTICAL_LINE, width);
		cout << VERTICAL_LINE;
	}

	GotoXY(x, y + (row - 1) * (height + 1) + 1 + height);
	cout << BOTTOM_LEFT;
	DrawTableLine(col, HORIZONTAL_LINE, BOTTOM_CROSS, width);
	cout << BOTTOM_RIGHT;
}*/


