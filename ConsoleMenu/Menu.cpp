#include "Menu.h"
#include <iostream>

Menu::Menu(std::string text)
{
	this->text = text;
	this->ShowCursor(false);
}

Menu::Menu(std::string header, std::string footer)
{
	this->text = header;
	this->footer = footer;
	this->ShowCursor(false);
}

void Menu::AddOption(std::string text, int status)
{
	Button option = Button(text, status);
	this->buttons.push_back(option);
	this->Options.push_back(0);
}

void Menu::AddOption(float minValue, float maxValue, bool active)
{
	ProgressBar progressBar = ProgressBar(minValue, maxValue, active);
	this->progressBars.push_back(progressBar);
	this->Options.push_back(1);
}

void Menu::Print()
{
	int button_counter = 0;
	int progressbar_counter = 0;
	system("CLS");
    std::cout << this->text << "\n\n";
	for (int i : Options) {
		if (i == 0) {
			buttons[button_counter].Print();
			button_counter++;
		}
		else if (i == 1) {
			progressBars[progressbar_counter].Print();
			progressbar_counter++;
		}
	}
	std::cout << "\n\n" << this->footer;
    //std::cout.flush();
}

void Menu::UpdateOption()
{
	for (std::vector<Button>::size_type i = 0; i != buttons.size(); i++) {
		buttons[i].UpdateStatus();
	}
	this->Print();
}

void Menu::UpdateOption(bool on)
{
	for (std::vector<Button>::size_type i = 0; i != buttons.size(); i++) {
		if(on)
			buttons[i].UpdateStatus(2);
		else
			buttons[i].UpdateStatus(0);
	}
	this->Print();
}

void Menu::UpdateOption(int index)
{
	try {
		buttons[index].UpdateStatus();
	}
	catch (const std::exception & e) { std::cout << e.what(); };
	this->Print();
}

void Menu::UpdateOption(int index, int status)
{
	try {
		buttons[index].UpdateStatus(status);
	}
	catch (const std::exception& e) { std::cout << e.what(); };
	this->Print();
}

void Menu::UpdateOption(int index, bool status)
{
	try {
		buttons[index].UpdateStatus(status);
	}
	catch (const std::exception& e) { std::cout << e.what(); };
	this->Print();
}


void Menu::UpdateProgressBar(int index, float currentValue)
{
	try {
		this->progressBars[index].Update(currentValue);
	}
	catch (const std::exception & e) { std::cout << e.what(); };
	this->Print();
}

void Menu::ShowCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
