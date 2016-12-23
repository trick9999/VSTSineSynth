/*
  ==============================================================================

    SineSynth.cpp
    Created: 1 Nov 2016 5:11:12pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "SineSynth.h"

/** A demo synth sound that's just a basic sine wave.. */
SineSound::SineSound() {}


//==============================================================================
/** A simple demo synth voice that just plays a sine wave.. */
SineVoice::SineVoice()
       : currentAngle (0), angleDelta (0), level (0), tailOff (0)
{
}

bool SineVoice::canPlaySound (SynthesiserSound* sound)
{
        return dynamic_cast<SineSound*> (sound) != nullptr;
}

void SineVoice::startNote (int midiNoteNumber, float velocity,
                          SynthesiserSound* /*sound*/,
                          int /*currentPitchWheelPosition*/)
{
    currentAngle = 0.0;
    level = velocity * 0.15;
    tailOff = 0.0;

    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();

    angleDelta = cyclesPerSample * 2.0 * double_Pi;
}

void SineVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
    if (allowTailOff)
    {
        // start a tail-off by setting this flag. The render callback will pick up on
        // this and do a fade out, calling clearCurrentNote() when it's finished.
        if (tailOff == 0.0) // we only need to begin a tail-off if it's not already doing so - the
                            // stopNote method could be called more than once.
            tailOff = 1.0;
    }
    else
    {
        // we're being told to stop playing immediately, so reset everything..

        clearCurrentNote();
        angleDelta = 0.0;
    }
}

void SineVoice::pitchWheelMoved (int /*newValue*/)
{
    // not implemented for the purposes of this demo!
}

void SineVoice::controllerMoved (int /*controllerNumber*/, int /*newValue*/)
{
    // not implemented for the purposes of this demo!
}

void SineVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        if (tailOff > 0)
        {
            while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * level * tailOff);

                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);

                currentAngle += angleDelta;
                ++startSample;

                tailOff *= 0.99;

                if (tailOff <= 0.005)
                {
                    // tells the synth that this voice has stopped
                    clearCurrentNote();

                    angleDelta = 0.0;
                    break;
                }
            }
        }
        else
        {
            while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * level);

                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);

                currentAngle += angleDelta;
                ++startSample;
            }
        }
    }
}