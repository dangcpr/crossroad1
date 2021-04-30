#pragma once
#include "Data.h"
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();
void GoTo(int x, int y);
//Ham do hoa
void SetColor(int color);
void Text(string name, int color, int x, int y);
void Box(int color, int width, int height, int x, int y);
void BoxLoading(int color, int width, int height, int x, int y);
void BigText(string filename, int color, int x, int y);

//Ham menu
MENU DisplayMenu();
void Help();