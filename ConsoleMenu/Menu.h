#pragma once
#include <string>
#include<vector>
#include "Button.h"
#include "ProgressBar.h"

class Menu
{
public:
	std::vector<Button> buttons;
	std::vector<ProgressBar> progressBars;
	std::vector<int> Options; // 0 = button, 1 = progress bar
	Menu(std::string text);
	Menu(std::string header, std::string footer);
	void AddOption(std::string text);
	void AddOption(float minValue, float maxValue, bool active = false);
	void Print();
	void UpdateOption();
	void UpdateOption(bool on);
	void UpdateButton(int index);
	void UpdateProgressBar(int index, float currentValue);
	void UpdateOption(int index, float currentValue = -1);
private:
	std::string text;
	std::string footer = "";
	void ShowCursor(bool showFlag);
};