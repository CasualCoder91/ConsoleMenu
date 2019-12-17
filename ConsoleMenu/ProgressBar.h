#pragma once
#include "Color.h"
//credits: https://stackoverflow.com/questions/14539867/how-to-display-a-progress-indicator-in-pure-c-c-cout-printf

class ProgressBar {
public:
    ProgressBar(float minValue, float maxValue);
    ProgressBar(float minValue, float maxValue, bool active);
    void Print();
    void Update(float currentValue);
    float GetProgress();
    void SetActive(bool value);
    bool GetActive();
private:
    float progress = 0.0; //goes from 0 to 1
    int barWidth = 70;      //size of the progress bar
    float minValue = 0;
    float maxValue = 1;
    float currentValue = 0;
    bool active = false;
};