/*
  ==============================================================================

    MidiUtil.cpp
    Created: 26 Oct 2016 10:35:54pm
    Author:  Mahavishnu

  ==============================================================================
*/

#include "MidiUtil.h"

/** Starts listening to a MIDI input device, enabling it if necessary. */
void setMidiInput(AudioDeviceManager &deviceManager,int index, MidiInputCallback *callback)
{
	const StringArray list(MidiInput::getDevices());
	static int lastInputIndex = 0;

	deviceManager.removeMidiInputCallback(list[lastInputIndex], callback);

	const String newInput(list[index]);

	if (!deviceManager.isMidiInputEnabled(newInput))
		deviceManager.setMidiInputEnabled(newInput, true);

	deviceManager.addMidiInputCallback(newInput, callback);
	//midiInputList.setSelectedId(index + 1, dontSendNotification);

	lastInputIndex = index;
}

String getMidiMessageDescription(const MidiMessage& m) {
	if (m.isNoteOn())           return "Note on " + MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3);
	if (m.isNoteOff())          return "Note off " + MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3);
	if (m.isProgramChange())    return "Program change " + String(m.getProgramChangeNumber());
	if (m.isPitchWheel())       return "Pitch wheel " + String(m.getPitchWheelValue());
	if (m.isAftertouch())       return "After touch " + MidiMessage::getMidiNoteName(m.getNoteNumber(), true, true, 3) + ": " + String(m.getAfterTouchValue());
	if (m.isChannelPressure())  return "Channel pressure " + String(m.getChannelPressureValue());
	if (m.isAllNotesOff())      return "All notes off";
	if (m.isAllSoundOff())      return "All sound off";
	if (m.isMetaEvent())        return "Meta event";

	if (m.isController())
	{
		String name(MidiMessage::getControllerName(m.getControllerNumber()));
		if (name.isEmpty())
			name = "[" + String(m.getControllerNumber()) + "]";
		return "Controller " + name + ": " + String(m.getControllerValue());
	}

	return String::toHexString(m.getRawData(), m.getRawDataSize());
}


//==============================================================================
// quick-and-dirty function to format a timecode string
String timeToTimecodeString(double seconds)
{
	const int millisecs = roundToInt(seconds * 1000.0);
	const int absMillisecs = std::abs(millisecs);

	return String::formatted("%02d:%02d:%02d.%03d",
		millisecs / 360000,
		(absMillisecs / 60000) % 60,
		(absMillisecs / 1000) % 60,
		absMillisecs % 1000);
}

// quick-and-dirty function to format a bars/beats string
String quarterNotePositionToBarsBeatsString(double quarterNotes, int numerator, int denominator)
{
	if (numerator == 0 || denominator == 0)
		return "1|1|000";

	const int quarterNotesPerBar = (numerator * 4 / denominator);
	const double beats = (fmod(quarterNotes, quarterNotesPerBar) / quarterNotesPerBar) * numerator;

	const int bar = ((int)quarterNotes) / quarterNotesPerBar + 1;
	const int beat = ((int)beats) + 1;
	const int ticks = ((int)(fmod(beats, 1.0) * 960.0 + 0.5));

	return String::formatted("%d|%d|%03d", bar, beat, ticks);
}

String getTimecodeString(AudioPlayHead::CurrentPositionInfo pos)
{
	MemoryOutputStream displayText;

	displayText //<< "[" << SystemStats::getJUCEVersion() << "]   "
		<< String(pos.bpm, 2) << " bpm, "
		<< pos.timeSigNumerator << '/' << pos.timeSigDenominator
		<< "  -  " << timeToTimecodeString(pos.timeInSeconds)
		<< "  -  " << quarterNotePositionToBarsBeatsString(pos.ppqPosition,
			pos.timeSigNumerator,
			pos.timeSigDenominator);

	if (pos.isRecording)
		displayText << "  (recording)";
	else if (pos.isPlaying)
		displayText << "  (playing)";

	return displayText.toString();
}
