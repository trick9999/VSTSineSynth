/*
  ==============================================================================

    MainPage.cpp
    Created: 19 Dec 2016 10:34:01pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "MainPage.h"

MainPage::MainPage()
	: TabbedComponent(TabbedButtonBar::TabsAtTop),
	  instrumentPage (new InstrumentPage),
	  settingsPage   (new SettingsPage),
	  consolePage    (new ConsolePage)
{
	addTab("Instruments", getRandomTabBackgroundColour(), instrumentPage, true);
	addTab("Settings",    getRandomTabBackgroundColour(), settingsPage,   true);
	addTab("Console",     getRandomTabBackgroundColour(), consolePage,    true);
	/*
	getTabbedButtonBar().getTabButton(5)->setExtraComponent(new CustomTabButton(), TabBarButton::afterText);
	*/
}

Colour MainPage::getRandomTabBackgroundColour()
{
	return Colour(Random::getSystemRandom().nextFloat(), 0.1f, 0.97f, 1.0f);
}
