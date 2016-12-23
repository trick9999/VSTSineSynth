/*
  ==============================================================================

    MidiUtil.h
    Created: 26 Oct 2016 10:36:06pm
    Author:  Mahavishnu

  ==============================================================================
*/

#ifndef MIDIUTIL_H_INCLUDED
#define MIDIUTIL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

/** Starts listening to a MIDI input device, enabling it if necessary. */
void setMidiInput(AudioDeviceManager &deviceManager, int index, MidiInputCallback *callback);

String getMidiMessageDescription(const MidiMessage& m);

// quick-and-dirty function to format a timecode string
String timeToTimecodeString(double seconds);
// quick-and-dirty function to format a bars/beats string
String quarterNotePositionToBarsBeatsString(double quarterNotes, int numerator, int denominator);
String getTimecodeString(AudioPlayHead::CurrentPositionInfo pos);

#endif  // MIDIMESSAGEUTIL_H_INCLUDED
