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
/*
#define INFO_TEXT "SEE THE HOST SETTINGS\n\n" \
"Music and Audio Computing Lab., KAIST\n" \
"http://mac.kaist.ac.kr\n\n" \
"Developers:\n" \
"Kyoungsoo Chun\n" \
"Sangeon Yong\n" \
"Soonbeom Choi\n\n" \
"Advisor:\n" \
"Prof. Juhan Nam"
*/


#include "../JuceLibraryCode/JuceHeader.h"

class SettingsPage : public Component
{
public:
	SettingsPage();
private:
	TextEditor settingsMessageBox;
};

#endif  // SETTINGSPAGE_H_INCLUDED
