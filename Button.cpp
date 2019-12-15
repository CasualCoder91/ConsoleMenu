#include "Button.h"
#include <iostream>
#include "Menu.h"

Button::Button(std::string text)
{
	this->text = text;
	this->status = 0; // = OFF
}

void Button::Print()
{
    std::cout << this->text << " [";
    if (status == 0)
        std::cout << ansi::foreground_red << "OFF";
    else if (status == 1) {
        std::cout << ansi::foreground_yellow << "LOADING";
    }
    else if (status == 2)
        std::cout << ansi::foreground_green << "ON";
    std::cout << ansi::reset << "]\n";
}

void Button::UpdateStatus()
{
    if (this->status == 2)
        this->status = 0;
    else if (this->status == 0) {
        this->status = 1;
    }
    else if (this->status == 1)
        this->status = 2;
}

void Button::UpdateStatus(int status)
{
    this->status = status;
}
