#pragma once
#include <string>
#include <windows.h> //Virtual-Key Codes

class Button
{
public:
	Button(std::string text);
	void Print();
	void UpdateStatus();
	void UpdateStatus(int status);
private:
	int status;
	std::string text;
};