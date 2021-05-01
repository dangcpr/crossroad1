#pragma once
#include "Ctrl.h"
#include "Data.h"
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();
void GoTo(int x, int y);//Di chuyen tren khap man hinh console

//Ham do hoa
void SetColor(int color);//Mau chu + mau nen
void Text(string name, int color, int x, int y);//In text
void Box(int color, int width, int height, int x, int y);//Hop mau
void BoxLoading(int color, int width, int height, int x, int y);//Man hinh loading dau tien
void BigText(string filename, int color, int x, int y);//In du lieu tep tin

//Ham menu
MENU DisplayMenu();

//Cac option
vector<string> FileSaved(string filename);//Luu ten tung file vao tung phan tu cua vector
void ShowFile();//Man hinh hien ten file
bool FileAvailable(string s);//Kiem tra file co ton tai khong
void InputFileName(string& s, int x, int y);//Nhap ten file
void Help();
void ExitGame();
void PauseGame();
void DrawBoard(int row, int col, int x, int y, int width, int height);