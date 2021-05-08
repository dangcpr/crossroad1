#pragma once
#include "Data.h"
#include "Ctrl.h"
#include "Menu.h"

void ErasePerson();
void MoveUp();
void MoveDown();
void MoveLeft();
void MoveRight();
void DrawCar();
void MoveCar();
void EraseCar();
void SubThread();

void ControlInGame(); //
void InGame();
void ExitGame();
void PauseGame();

//Ham do hoa
void DrawBoard(int row, int col, int x, int y, int width, int height); //Ve lan duong
void ClearScreen(int width, int height, int x, int y); //Xoa man hinh

//Luu file
void SaveGame();
