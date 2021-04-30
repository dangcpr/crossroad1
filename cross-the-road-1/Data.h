#pragma once
#define MAX_CAR 17
#define MAX_CAR_LENGTH 40
#define MAX_SPEED 3
//Biến toàn cục
 // Đại diện người qua đường
#define WIDTH 1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32
//Chess Board
#define BOARD_SIZE 13
#define LEFT 2
#define TOP 1
#define HORIZONTAL_DISTANCE 4
#define VERTICAL_DISTANCE 2
//ASCII
#define SPACE 32
#define ENTER 13
#define ESC 27
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define TOP_LEFT (char)218
#define TOP_RIGHT (char)191
#define BOTTOM_LEFT (char)192
#define BOTTOM_RIGHT (char)217
#define TOP_CROSS (char)194
#define BOTTOM_CROSS (char)193
#define	LEFT_CROSS (char)195
#define RIGHT_CROSS (char)180
#define CROSS (char)197
#define HORIZONTAL_LINE (char)196
#define VERTICAL_LINE (char)179
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

#define SAVED_LIST "FileDaLuu.txt" //Ten cac file game duoc save
#define PLAYER_LIST "DSNguoiChoi.txt" //Thong tin cac player da choi game

using namespace std;

struct MENU
{
	int choices; //So chuc nang menu
	int x;			 // Toa do cua diem bat 
	int y;			 //dau cua chuc nang dau tien
};