#ifndef HEADER
#define HEADER

#include <iostream>
#include <stdio.h>
//#define _WIN32_WINNT 0x05232
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <tuple>
#include <time.h>

using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for size of Sudoku grid. Size will be NxN
#define N 9

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}

void RestoreOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // Same as above
    ShowWindow(consoleWindow, SW_RESTORE); // this mimics clicking on its' maximize for a second time, which puts it back to normal
}

/*  move the console cursor to the (x,y) coordinates as passed  */
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

/*  return the current console position as a tuple of (x,y) */
tuple <int, int> wherexy_tuple()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD result;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return tuple<int, int>(0, 0);
    else
    {
        result = csbi.dwCursorPosition;
        return tuple<int, int>(result.X, result.Y);
    }
}

#endif