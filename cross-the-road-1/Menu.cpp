#include"Menu.h"
#include "Ctrl.h"
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

void GoTo(int x, int y)//Di chuyen tren khap man hinh console
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Ham do hoa
void SetColor(int color)//Mau chu + mau nen
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void Text(string name, int color, int x, int y)//In text
{
	GoTo(x, y);
	SetColor(color);
	cout << name;

}
void Box(int color, int width, int height, int x, int y)//Hop mau
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
void BoxLoading(int color, int width, int height, int x, int y) //Man hinh loading dau tien
{

	int n = 0;
	BigText("Logo.txt", 240, 20, 3);
	BigText("LogoCar.txt", 240, 43, 15);
	for (int i = 0; i < height; i++)
	{
		GoTo(x, y + i);
		for (int j = 0; j < width; j++)
		{
			SetColor(color);
			Sleep(30);
			cout << " ";
			n++;
			Text(to_string(n) + "%", 240, x, y + 1);
			GoTo(x + j, y);
		}
	}
	SetColor(240);
}
void BigText(string filename, int color, int x, int y) //In du lieu tep tin
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
	Box(124, 53, 13, X_CENTER - 25, Y_CENTER + 5);
	Text("*********** MENU ************", 117, menu.x, menu.y - 2);
	Text("   Press '1' to Start Game   ", 124, menu.x, menu.y);
	Text("   Press '2' to Load Game    ", 124, menu.x, menu.y + 1);
	Text("    Press '3' to Ranking     ", 124, menu.x, menu.y + 2);
	Text("      Press '4' to Help      ", 124, menu.x, menu.y + 3);
	Text("    Press 'e' to Exit Game   ", 124, menu.x, menu.y + 4);
	SetColor(240);
	return menu;
}
vector<string> FileSaved(string filename)
{
	fstream f;
	vector<string> File;
	string line;
	f.open(filename, ios::in);
	while (!f.eof())
	{
		getline(f, line);
		File.push_back(line);
	}
	return File;
}
void ShowFile()
{
	MENU menu;
	vector<string> File = FileSaved("FileDaLuu.txt");
	string s;
	menu.x = X_CENTER - 13;
	menu.y = Y_CENTER + 10;

	system("cls");
	File.size() - 1;
	BigText("Logo.txt", 240, 20, 3);
	BigText("LogoCar.txt", 240, 43, 15);
	Box(124, 53, 13, X_CENTER - 25, Y_CENTER + 5);
	Text("*********** FILES ************", 117, menu.x, menu.y - 3);
	Text(File[File.size() - 1], 124, menu.x, menu.y - 1);
	Text(File[File.size() - 2], 124, menu.x, menu.y);
	Text(File[File.size() - 3], 124, menu.x, menu.y + 1);
	InputFileName(s, menu.x, menu.y + 3);
	SetColor(240);
}
bool FileAvailable(string s)
{
	vector<string> File = FileSaved("FileDaLuu.txt");
	for (int i = 0; i < File.size(); i++)
	{
		if (s == File[i])
		{
			return 1;
		}

	}
	return 0;
}
void Clear(string& s, string t, int x, int y)
{
	for (int i = 0; i < s.size() + t.size() + 2; i++)
	{
		Text(" ", 124, x + i, y);
	}
}
void InputFileName(string& s, int x, int y)
{
	MENU menu;
	string s1 = "Nhap ten file: ", s2 = "Sai ten file!", s3 = "Nhap lai ten: ";
	vector<string> File = FileSaved("FileDaLuu.txt");
	Text(s1, 124, x, y);
	getline(cin, s);
	while (FileAvailable(s) == 0)
	{
		Clear(s, s1, x, y);
		Text(s2, 124, x, y);
		Clear(s, s3, x, y + 1);
		Text(s3, 124, x, y + 1);
		getline(cin, s);
	}
	Clear(s, s2, x, y);
	Clear(s, s3, x, y + 1);
	Text("Dung ten file! ", 124, x, y);


}
void Help() //Tro giup
{
	Box(124, 75, 27, X_CENTER - 34, Y_CENTER - 15);
	BigText("Help.txt", 124, X_CENTER - 15, Y_CENTER - 10);
	SetColor(240);
	char press;
	press = _getch();
	if (press == 'r')
	{
		MenuControl();
	}
}
void ExitGame()
{
	BigText("ThankYou.txt", 71, 40, 15);
	Sleep(3000);
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