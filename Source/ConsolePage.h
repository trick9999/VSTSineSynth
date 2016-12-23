/*
  ==============================================================================

    ConsolePage.h
    Created: 20 Dec 2016 9:59:42pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef CONSOLEPAGE_H_INCLUDED
#define CONSOLEPAGE_H_INCLUDED

#include "ConsoleBox.h"

class ConsolePage : public Component
{
public:
	ConsolePage();
private:
	ConsoleBox consoleBox;
};



#endif  // CONSOLEPAGE_H_INCLUDED
