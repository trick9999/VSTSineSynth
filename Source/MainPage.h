/*
  ==============================================================================

    MainPage.h
    Created: 19 Dec 2016 10:34:09pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef MAINPAGE_H_INCLUDED
#define MAINPAGE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "ConsolePage.h"
#include "SettingsPage.h"

class InstrumentPage : public Component
{
public:
	InstrumentPage() {}
private:
};

class MainPage : public TabbedComponent
{
public:
	MainPage();
	static Colour getRandomTabBackgroundColour();
private:
	InstrumentPage *instrumentPage;
	SettingsPage   *settingsPage;
	ConsolePage    *consolePage;
};



#endif  // MAINPAGE_H_INCLUDED
