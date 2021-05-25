#include "Game.h"
#include "Data.h"
#include "Menu.h"

int timeStart[5], timeCur[5];
you Y;
Cars a;
int spd = 1;
char Moving;
bool STT;
bool mark[130];
int Score = 0;
int c = 50, d = 36;

void CreateCar()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		a.n[i] = (rand() % 3) + 1;
		a.x[i][0] = (i % 2 == 0) ? 11 : 109;
		for (int j = 1; j < a.n[i]; j++)
		{
			int temp = (i % 2 == 0) ? 35 : -35;
			a.x[i][j] = a.x[i][j - 1] + temp;
		}
		a.State[i] = 1;
		timeStart[i]  = (rand() % 50) + 50;
		timeCur[i] = timeStart[i];
	}
}

void StopCar()
{
	for (int i = 0; i < 5; i++)
	{
		timeCur[i]--;
		if (timeCur[i] < 0)
		{
			timeCur[i] = timeStart[i];
			a.State[i] = !a.State[i];
		}
		GoTo(5, 5.5 + (i * 6));
		cout << "  ";
		GoTo(5, 5.5 + (i * 6));
		cout << timeCur[i];
	}
	
}
void DrawCar()
{
	for (int i = 0; i < 5; i++)
	{
		if(i%2==0)
		for (int j = 0; j < a.n[i]; j++)
		{
			BigText("Car.txt", 240, a.x[i][j], 5.5 + (i * 6));
		}
		else 
		for (int j = 0; j < a.n[i]; j++)
		{
			BigText("ReCar.txt", 240, a.x[i][j], 5.5 + (i * 6));
		}
	}
}
void ErasePerson()
{
	for (int i = 0; i < 4; i++)
	{
		GoTo(Y.x, Y.y + i);
		cout << "   ";
	}
}

void EraseCar()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < a.n[i]; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				GoTo(a.x[i][j], 5.5 + (i * 6) + k);
					cout << "                     ";
			}
		}
	}
}

void MoveCar()
{
	for (int i = 0; i < 5; i+=2)
	{
		int cnt = 0;
		do
		{
			cnt++;
			if (a.State[i])
			{
				for (int j = 0; j < a.n[i]; j++)
				{
					if (a.x[i][j] + 1 > 109)
						a.x[i][j] = 11;
					else a.x[i][j]++;
				}
			}
		} while (cnt < spd);
	}
	for (int i = 1; i < 5; i += 2)
	{
		int cnt = 0;
		do
		{
			cnt++;
			if (a.State[i])
			{	
				for (int j = 0; j < a.n[i]; j++)
				{
					if (a.x[i][j] - 1 < 11)
						a.x[i][j] = 109;
					else a.x[i][j]--;
				}
			}
		} while (cnt < spd);
	}
}
void MoveUp()
{
	if (Y.y - 6 > 0)
	{
		PlaySound(TEXT("Move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		ErasePerson();
		Y.y -= 6;
		BigText("Person.txt", 240, Y.x, Y.y);
	}
	else if (Y.y - 6 == 0)
	{
		if (mark[Y.x] == 0)// && mark[Y.x + 1] == 0 && mark[Y.x + 2] == 0)
		{
			ErasePerson();
			Y.y -= 6;
			BigText("Person.txt", 240, Y.x, Y.y);
			mark[Y.x] = 1;
			//mark[Y.x + 1] = 1;
			//mark[Y.x + 2] = 1;
		}
		else
		{
			STT = 0;
			char press4 = ' ';
			MENU menu;
			menu.x = X_CENTER + 52;
			menu.y = Y_CENTER - 11;
			Box(124, 40,20, X_CENTER + 50, Y_CENTER - 16);
			Text("*********** PAUSE ************", 117, menu.x, menu.y - 2);
			Text(" Va vao nguoi khac se bi tru 50 diem ", 124, menu.x, menu.y);
			Text("    An 'q' de dong y    ", 124, menu.x, menu.y + 1);   
			Text("    An 's' de tu choi    ", 124, menu.x, menu.y + 2);
			do press4 = _getch();
			while (press4 != 'q' && press4 != 's');
			if (press4 == 'q')
			{
				ClearScreen(40, 20, X_CENTER + 50, Y_CENTER - 16);
				ErasePerson();
				Y.y -= 6;
				BigText("Person.txt", 240, Y.x, Y.y);
				GoTo(0, 0);
				mark[Y.x] = 1;
				//mark[Y.x + 1] = 1;
				//mark[Y.x + 2] = 1;
				Score -= 50;
				STT = 1;
			}
			else if(press4 =='s')
			{
				ClearScreen(40, 20, X_CENTER + 50, Y_CENTER - 16);
				GoTo(0, 0);
				STT = 1;
			}
		}
		
	}
}
void MoveDown()
{
	if (Y.y + 6 <= 36)
	{
		PlaySound(TEXT("Move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		ErasePerson();
		Y.y += 6;
		BigText("Person.txt", 240, Y.x, Y.y);
	}
}
void MoveRight()
{
	if (Y.x + 3 < 130)
	{
		ErasePerson();
		Y.x += 3;
		BigText("Person.txt", 240, Y.x, Y.y);
	}
}
void MoveLeft()
{
	if (Y.x - 3 > 10)
	{
		ErasePerson();
		Y.x -= 3;
		BigText("Person.txt", 240, Y.x, Y.y);
	}
}

bool Impact()
{
	
	int i = 4;
	while (5.5 + (i * 6) > Y.y) i--;
	for (int j = 0; j < a.n[i]; j++)
	{
		if (a.x[i][j] <= Y.x && a.x[i][j] + 20 >= Y.x && Y.y >= (5.5 + i * 6) && Y.y < (5.5 + (i + 1) * 6))
		{
			return true; // kiem tra nguoi co nam trong doan duong i hay khong va co o vi tri da co xe san hay khong 
		}
	}
	return false;
}
void GameOver(void)
{
	for (int i = 0; i <= 50; i++)
	{
		BigText("Car.txt", 240, i + 11, 30);
	}
}
bool PlayerAvailable(string s)
{
	vector<string> File = FileSaved("DSNguoiChoi.txt");
	for (int i = 0; i < File.size(); i++)
	{
		if (s == File[i])
		{
			return 1;
		}

	}
	return 0;
}
void YDead()
{
	string s;
	STT = 0;
	//thread t1(InGame);
	//TerminateThread((HANDLE)t1.native_handle(), 0);
	EraseCar();
	ErasePerson();
	for (int i = 0; i < 130; i++)
	{
		mark[i] = 0;
	}
	system("cls");
	PlaySound(TEXT("Gameover.wav"), NULL, SND_FILENAME | SND_ASYNC);
	BigText("Person.txt", 252, 100, 16);
	Ambulance();
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);

	system("cls");
	BigText("Skull.txt", 240, X_CENTER - 20, 1);
	Box(124, 70, 10, X_CENTER - 40, 30);
	Text("Game Over. Please type your name to save your infomation: ", 112, X_CENTER - 35 , 31);
	int t = 0;
	getline(std::cin, s);
	t++;
	//GoTo(X_CENTER - 55, 19 + t);
	ofstream f;
	f.open("DSNguoiChoi.txt", ios::app);
	f << s;
	f << endl;
	f << Score;
	f << endl;
	f.close();
	Text("Saved successfully.", 112, X_CENTER - 35, 32 + t);
	t++;
	Text("Press 'r' to return to main menu.", 112, X_CENTER - 35, 32 + t);
	char press6;
	do press6 = _getch(); while (press6 != 'r');
	Score = 0; spd = 1;
	MenuControl();
}

void Finish()
{
	if (spd == 3) spd = 1;
	else spd++;
	//PlaySound(TEXT("Up.wav"), NULL, SND_FILENAME | SND_SYNC);
	Score += 100;
	Y.x = 50;
	Y.y = 36;
	Moving = KEY_RIGHT;
}
void SubThread(void)
{
	while (1)
	{
		if (STT)
		{
			switch (Moving)
			{
			case KEY_LEFT:
				MoveLeft(); break;
			case KEY_RIGHT:
				MoveRight(); break;
			case KEY_DOWN:
				MoveDown(); break;
			case KEY_UP:
				MoveUp(); break;
			}
			Moving = ' ';
			EraseCar();
			StopCar();
			MoveCar();
			DrawCar();
			if (Impact())
			{
				YDead();
				return;
			}
			if (Y.y < 5.5)
			{
				Finish();
			}
			MENU menu;
			menu.x = X_CENTER + 52;
			menu.y = Y_CENTER - 11;
			Text("Score: ", 240, menu.x, menu.y);
			cout << Score;
			SetColor(240);
			Sleep(100);
		}
	}
	
}
void ControlInGame(void)
{
	thread t1(SubThread);
	while (1)
	{
		if (STT)
		{
			char press, press1;
			do press = _getch(); 
			while (press != 'p' && press != 'q' && press != 'r' && press != KEY_LEFT && press != KEY_RIGHT && press != KEY_UP && press != KEY_DOWN);
			if (press == 'p')
			{
				//SuspendThread((HANDLE)t1.native_handle());
				STT = 0;
				PauseGame();
				do press1 = _getch(); while (press1 != 'r' && press1 != 'e' && press1 != 'm' && press1 != 's');
				if (press1 == 'r') {
						
					ClearScreen(50, 20, X_CENTER + 50, Y_CENTER - 16);
					GoTo(0, 0);
					//ResumeThread((HANDLE)t1.native_handle());
					STT = 1;
				}
				else if (press1 == 'e') {
					ExitGame();
				}
				else if (press1 == 's') {
					TerminateThread((HANDLE)t1.native_handle(), 0);
					SaveGame();
				}
				else if (press1 == 'm') {
					system("cls");
					TerminateThread((HANDLE)t1.native_handle(), 0);
					MenuControl();
				}
				//}while (press1 != 'p' && press1 != 'e' && press1 != 's' && press1 != 'm');
			}
			else if (press == KEY_LEFT || press == KEY_RIGHT || press == KEY_DOWN || press == KEY_UP)
			{
				Moving = press;
			}
		}
	}
}

void InGame()
{
	system("cls");
	//SetColor(240);
	Score = 0;
	CreateCar();
	DrawBoard(0, 0, 10, 5.5, 120, 30);
	Y.x = c; Y.y = d;
	BigText("Person.txt", 240, Y.x, Y.y);
	Moving = 'd';
	spd = 1;
	STT = 1;
	DrawCar();
	ControlInGame();
}

void PauseGame()
{
	MENU menu;
	menu.x = X_CENTER + 59; //X_CENTER + 52;
	menu.y = Y_CENTER - 11; //Y_CENTER - 11;
	//DrawBoard(2, 1, 54, 15, 45, 10); 
	Box(124, 50, 20, X_CENTER + 50, Y_CENTER - 16);
	Text("*********** PAUSE ************", 117, menu.x, menu.y - 2);
	Text("    Press 'r' to Resume Game  ", 124, menu.x, menu.y);
	Text("    Press 's' to Save Game    ", 124, menu.x, menu.y + 1);
	Text("    Press 'e' to Exit Game    ", 124, menu.x, menu.y + 3);
	Text("    Press 'm' to Back To Menu ", 124, menu.x, menu.y + 2);
	SetColor(255);
}
void ExitGame()
{
	system("cls");
	SetColor(255);
	BigText("ThankYou.txt", 71, 45, 15);
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

void SaveGame()
{
	string s;
	MENU menu;
	menu.x = X_CENTER + 59;    //X_CENTER + 52
	menu.y = Y_CENTER - 11;     /*Y_CENTER - 11;*/
	//Box(124, 10, 10, 56, 16); 
	Box(124, 50, 20, X_CENTER + 50, Y_CENTER - 16); //+50 ,-16
	Text("***** SAVE GAME ******", 117, menu.x, menu.y - 2);
	Text("Enter your name: ", 124, menu.x, menu.y);
	int t = 0;
	do {
	t = t + 2;
	fflush(stdin);
	getline(cin, s);
	if (FileAvailable(s))
	{
		Text("This name is availble. Please type again.", 124, menu.x, menu.y + t);
		t = t + 2;
		GoTo(menu.x, menu.y + t);
	}
	} while (FileAvailable(s));
	string s1 = s + ".txt";
	ofstream f;
	f.open("FileDaLuu.txt", ios::app);
	f << s;
	f << endl;
	f.close();
	ofstream f1;
	f1.open(s1, ios::out);
	f1 << Score << " " << spd << " " << Y.x << " " << Y.y;
	f1 << endl;
	for (int i = 0; i < 5; i++)
	{
		f1 << a.n[i] << " ";
		for (int j = 0; j < a.n[i]; j++)
		{
			f1 << a.x[i][j] << " ";
		}
		f1 << timeStart[i] << " " << timeCur[i] << " " << a.State[i] << endl;
	}
	for (int i = 0; i < 130; i++)
	{
		if (mark[i] == 1)
		{
			f1 << i << " ";
		}
	}
	f1.close();
	/*ofstream f2;
	f2.open("DSNguoiChoi.txt", ios::app);
	f2 << s;
	f2 << endl;
	f2 << Score;
	f2 << endl;
	f2.close();*/
	Text("Saved successfully.", 124, menu.x, menu.y + t); t += 2;
	Text("Press any key to return to main menu.",124, menu.x, menu.y + t);
	_getch();
	MenuControl();
}
void LoadGame(string s)
{
	ifstream fb;
	fb.open(s + ".txt");
	fb >> Score >> spd >> c >> d;
	SetColor(240);
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		fb >> a.n[i];
		for (int j = 0; j < a.n[i]; j++)
		{
			fb >> a.x[i][j];
		}
		fb >> timeStart[i] >> timeCur[i] >> a.State[i];
	}
	if (Score != 0)
	while (!fb.eof())
	{
		int i;
		fb >> i;
		{
			BigText("Person.txt", 240, i, 0);
		}
		mark[i] = 1;
	}
	fb.close();
	DrawBoard(0, 0, 10, 5.5, 120, 30);
	Y.x = c; Y.y = d;
	BigText("Person.txt", 240, Y.x, Y.y);
	Moving = 'd';
	STT = 1;
	DrawCar();
	ControlInGame();
}
void Ambulance()
{
	for (int i = 0; i <= 190; i++)
	{
		BigText("Ambulance.txt", 252, i, 15);
		Sleep(20);
		for (int j = 0; j <= 5; j++)
		{
			Text("                                 ", 255, i, 15 + j);
		}
	}
}
