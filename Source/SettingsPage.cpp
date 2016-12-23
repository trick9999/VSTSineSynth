/*
  ==============================================================================

    SettingsPage.cpp
    Created: 20 Dec 2016 11:46:37pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "SettingsPage.h"

SettingsPage::SettingsPage() :
	settingsMessageBox()
{
	addAndMakeVisible(settingsMessageBox);

	settingsMessageBox.setMultiLine(true);
	settingsMessageBox.setReturnKeyStartsNewLine(true);
	settingsMessageBox.setReadOnly(true);
	settingsMessageBox.setScrollbarsShown(true);
	settingsMessageBox.setCaretVisible(false);
	settingsMessageBox.setPopupMenuEnabled(true);
	settingsMessageBox.setColour(TextEditor::textColourId, Colours::black);
	settingsMessageBox.setColour(TextEditor::backgroundColourId, Colour(0x32ffffff));
	settingsMessageBox.setColour(TextEditor::outlineColourId, Colour(0x1c000000));
	settingsMessageBox.setColour(TextEditor::shadowColourId, Colour(0x16000000));

	settingsMessageBox.setBounds(8, 8, 800 - 32, 450 - 16);
	settingsMessageBox.setText(SETTINGS_TEXT);
}
