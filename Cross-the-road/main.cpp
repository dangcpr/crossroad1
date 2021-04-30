// Cross-the-road.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ctrl.h"

int main()
{
    int cnt = 0;//Biến hỗ trợ trong quá trình tăng tốc độ xe di chuyển
    int MOVING;//Biến xác định hướng di chuyển của người
    int SPEED;// Tốc độ xe chạy (xem như level)
    bool STATE; // Trạng thái sống/chết của người qua đường
    CreateConsoleWindow(WIDTH, HEIGHT);
    FixConsoleWindow();
    MenuControl();
    GoTo(0, 0);
    return 0;
}
