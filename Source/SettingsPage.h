/*
  ==============================================================================

    SettingsPage.h
    Created: 20 Dec 2016 11:46:37pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef SETTINGSPAGE_H_INCLUDED
#define SETTINGSPAGE_H_INCLUDED

#define SETTINGS_TEXT "SEE THE HOST SETTINGS\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" \
			          "SINE WAVE SYNTHESIZER\n\n" \
                      "K.S. Chun\n"\
    		          "http://radiomix.kaist.ac.kr\n"


#include "../JuceLibraryCode/JuceHeader.h"

class SettingsPage : public Component
{
public:
	SettingsPage();
private:
	TextEditor settingsMessageBox;
};

#endif  // SETTINGSPAGE_H_INCLUDED
