/*
  ==============================================================================

    ConsoleBox.h
    Created: 9 Dec 2016 10:35:00pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef CONSOLEBOX_H_INCLUDED
#define CONSOLEBOX_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include <sstream>

class ConsoleBox :
		public  TextEditor,
		private Timer
{

public:
	ConsoleBox();
	~ConsoleBox();

	//TextEditor consoleBox;
	//==============================================================================
	void timerCallback() override;

private:
	//static TextEditor consoleBox;
	std::stringstream buffer;
	int messageSize;
};



#endif  // CONSOLEBOX_H_INCLUDED
