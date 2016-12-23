/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#define WIDTH  800
#define HEIGHT 600

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MainPage.h"


//==============================================================================
/**
*/
class SineSynthAudioProcessorEditor  : public AudioProcessorEditor,
                                       private Timer
{
public:
    SineSynthAudioProcessorEditor (SineSynthAudioProcessor&);
    ~SineSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void timerCallback() override;
	
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    //SineSynthAudioProcessor& processor;
	SineSynthAudioProcessor& getProcessor() const
	{
		return static_cast<SineSynthAudioProcessor&> (processor);
	}
	
	MidiKeyboardComponent keyboardComponent;

	MainPage mainPage;
	Label timecodeDisplayLabel;

	double startTime;
    
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SineSynthAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
