#pragma once
#include <string>
#include <windows.h> //Virtual-Key Codes

class Button
{
public:
	Button(std::string text, int status=-1);
	void Print();
	void UpdateStatus();
	void UpdateStatus(int status);
	void UpdateStatus(bool status);
private:
	int status;
	std::string text;
};