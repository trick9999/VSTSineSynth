/*
  ==============================================================================

    PPM_sampler.h
    Created: 1 Nov 2016 5:10:33pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef SINESYNTH_H_INCLUDED
#define SINESYNTH_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

/** A demo synth sound that's just a basic sine wave.. */
class SineSound : public SynthesiserSound
{
public:
	SineSound();

    bool appliesToNote (int /*midiNoteNumber*/) override    { return true; }
    bool appliesToChannel (int /*midiChannel*/) override    { return true; }
};


//==============================================================================
/** A simple demo synth voice that just plays a sine wave.. */
class SineVoice   : public SynthesiserVoice
{
public:
    SineVoice();

    bool canPlaySound (SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound* /*sound*/,
                    int /*currentPitchWheelPosition*/) override;

    void stopNote (float /*velocity*/, bool allowTailOff) override;
    void pitchWheelMoved (int /*newValue*/) override;
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override;

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

private:
    double currentAngle, angleDelta, level, tailOff;
};



#endif  // SINESYNTH_H_INCLUDED
