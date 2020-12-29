#include "Button.h"
#include <iostream>
#include "Menu.h"

Button::Button(std::string text, int status)
{
	this->text = text;
	this->status = status;
}

void Button::Print()
{
    std::cout << this->text;
    if (status != -1) {

        std::cout << " [";
        if (status == 0)
            std::cout << ansi::foreground_red << "OFF";
        else if (status == 1) {
            std::cout << ansi::foreground_yellow << "LOADING";
        }
        else if (status == 2)
            std::cout << ansi::foreground_green << "ON";
        std::cout << ansi::reset << "]";
    }
    std::cout << std::endl;
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

void Button::UpdateStatus(bool status)
{
    int iStatus = status ? 2 : 0;
    this->status = iStatus;
}
