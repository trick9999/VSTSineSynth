/*
  ==============================================================================

    ConsolePage.cpp
    Created: 20 Dec 2016 9:59:42pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "ConsolePage.h"

ConsolePage::ConsolePage() :
	consoleBox()
{
	addAndMakeVisible(consoleBox);

	consoleBox.setMultiLine(true);
	consoleBox.setReturnKeyStartsNewLine(true);
	consoleBox.setReadOnly(true);
	consoleBox.setScrollbarsShown(true);
	consoleBox.setCaretVisible(false);
	consoleBox.setPopupMenuEnabled(true);
	consoleBox.setColour(TextEditor::textColourId, Colours::black);
	consoleBox.setColour(TextEditor::backgroundColourId, Colour(0x32ffffff));
	consoleBox.setColour(TextEditor::outlineColourId, Colour(0x1c000000));
	consoleBox.setColour(TextEditor::shadowColourId, Colour(0x16000000));

	consoleBox.setBounds(8, 8, 800 - 32, 450 - 16);
}
