#pragma once
// Kính thước màn hình console
#define WIDTH 1600 //1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32
//ASCII
#define ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <iomanip>
#include <MMsystem.h>


#define SAVED_LIST "FileDaLuu.txt" //Ten cac file game duoc save
#define PLAYER_LIST "DSNguoiChoi.txt" //Thong tin cac player da choi game

using namespace std;

struct MENU
{
	int choices; //So chuc nang menu
	int x;			 // Toa do cua diem bat 
	int y;			 //dau cua chuc nang dau tien
};
struct Name
{
	int n;
	string* s;
};
struct Cars
{
	int n[5];
	int x[5][3];
	bool State[5];
};

struct you
{
	int x, y;
};
#pragma comment (lib,"winmm.lib")
