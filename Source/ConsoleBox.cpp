/*
  ==============================================================================

    ConsoleBox.cpp
    Created: 9 Dec 2016 10:34:52pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "ConsoleBox.h"

ConsoleBox::ConsoleBox() {
    startTimerHz(30);
    //==============================================================================
    messageSize = 0;
    
    std::cout.rdbuf(buffer.rdbuf());
}

ConsoleBox::~ConsoleBox() {
    
}

void ConsoleBox::timerCallback() {
    std::string text = buffer.str();
    int newMessageSize = (int)text.length();
    setText(text);
    
    if (newMessageSize > messageSize)
        moveCaretToEnd();
    
    messageSize = newMessageSize;
}
