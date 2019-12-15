#include <iostream>
#include <Windows.h>

#include "Menu.h"

int main() {

	bool flyhack = false;
	bool scan = false;

	Menu menu = Menu("This is the Header Text","Press NUMPAD0 to exit");
	menu.AddOption("This is an Option Text");
	menu.AddOption("This is another Option Text");
	menu.AddOption(0, 99, false);
	menu.Print();
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			flyhack = !flyhack;
			menu.UpdateButton(0);
			//code to be excecuted goes here
		}
		else if(GetAsyncKeyState(VK_NUMPAD2))
		{
			scan = !scan;
			menu.UpdateButton(1);
			if (scan) {
				menu.UpdateProgressBar(0, 0);
				for (int i = 0; i < 99; i++) {
					menu.UpdateProgressBar(0, (float)i);
					Sleep(20);
				}
				menu.UpdateProgressBar(0,-1);
				menu.UpdateButton(1);
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

