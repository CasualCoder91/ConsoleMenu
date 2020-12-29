#include <iostream>
//#include <Windows.h>

#include "ConsoleMenu/Menu.h"

int main() {

	bool flyhack = false;
	bool scan = false;

	Menu menu = Menu("This is the Header Text","Press NUMPAD0 to exit");
	menu.AddOption("[N1] This is an Option Text", 0); //Option with Status = false
	menu.AddOption("[N2] This is another Option Text",0); //Option with Status = false
	menu.AddOption(0, 99, false); //Add progressbar
	menu.AddOption("[N3] No Status here"); //Option without Status
	menu.Print();
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			flyhack = !flyhack;
			menu.UpdateOption(0,flyhack);
			//code to be excecuted goes here
		}
		else if(GetAsyncKeyState(VK_NUMPAD2))
		{
			scan = !scan;
			menu.UpdateOption(1); //OFF -> Loading | On -> Off
			if (scan) {
				menu.UpdateProgressBar(0, 0);
				for (int i = 0; i < 99; i++) {
					menu.UpdateProgressBar(0, (float)i);
					Sleep(20);
				}
				menu.UpdateProgressBar(0,-1);
				menu.UpdateOption(1); // Loading -> On
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD0))
		{
			return 0;
		}
		Sleep(500);
	}
	return 0;
}

