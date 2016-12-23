/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "MidiUtil.h"

//==============================================================================
SineSynthAudioProcessorEditor::SineSynthAudioProcessorEditor (SineSynthAudioProcessor& p)
    : AudioProcessorEditor (&p),
      keyboardComponent(p.keyboardState, MidiKeyboardComponent::horizontalKeyboard),
	  mainPage(),
      timecodeDisplayLabel(String()),
      startTime(Time::getMillisecondCounterHiRes() * 0.001)
{
	// add the midi keyboard component..
	addAndMakeVisible(keyboardComponent);
	addAndMakeVisible(timecodeDisplayLabel);
	timecodeDisplayLabel.setColour(Label::textColourId, Colours::blue);
	timecodeDisplayLabel.setFont(Font(Font::getDefaultMonospacedFontName(), 15.0f, Font::plain));

	addAndMakeVisible(mainPage);

	// set resize limits for this plug-in
    setResizeLimits (WIDTH, HEIGHT, WIDTH, HEIGHT);

    // set our component's initial size to be the last one that was stored in the filter's settings
    setSize (p.lastUIWidth,
             p.lastUIHeight);

	// start a timer which will keep our timecode display updated
	startTimerHz(50);
}

SineSynthAudioProcessorEditor::~SineSynthAudioProcessorEditor()
{
}

//==============================================================================
void SineSynthAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
}

void SineSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    timecodeDisplayLabel.setBounds(8, 8, WIDTH-(8*2), 20);
	mainPage.setBounds(8, 8+20, WIDTH-(8*2), HEIGHT-(8*2)-76-8-20);
	keyboardComponent.setBounds(80, HEIGHT-76-8, WIDTH - 80 - 20, 76);

	getProcessor().lastUIWidth  = getWidth();
	getProcessor().lastUIHeight = getHeight();
}

void SineSynthAudioProcessorEditor::timerCallback()
{
	timecodeDisplayLabel.setText(getTimecodeString(getProcessor().lastPosInfo),
		                         dontSendNotification);
	while (!getProcessor().midiMessageQueue.empty()) {
		std::cout << getProcessor().midiMessageQueue.front() << std::endl;
		getProcessor().midiMessageQueue.pop();
	}
}
