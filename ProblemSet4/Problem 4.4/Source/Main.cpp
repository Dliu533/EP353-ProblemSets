/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

// Define constant values as global variables for ease of access
const float kSampleRate = 44100.0f;
const float kSec = 1.0f;
const float kNumFrames = kSampleRate * kSec;
const int kNumChannels = 2;
const float kFrequency = 440.0f;
const float kAmplitude = 0.25f;
const float kLFORate = 2.0f;

//==============================================================================
int main (int argc, char* argv[])
{
    float att, dec, sus, rel;
    
    att = 1;
    dec = 0;

    // Prompt for the output file path
    std::cout << "Enter the path for the destination wave file: ";
    std::string destFilePath;
    std::getline(std::cin, destFilePath);

    // Create a File object from the path
    juce::File destFile(destFilePath);
    
    // Create an audio format manager and register the wav format
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    
    // Create a buffer to hold the samples
    juce::AudioBuffer<float> buffer(kNumChannels, kNumFrames);
    
    //Compute sine wave
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        float *channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Compute A sin(2πft+φ). Phase is ignored in this case.
            // kFrequency/kSampleRate converts frequency (continous) to sample rate representation (discrete).
            float y = kAmplitude * std::sin(2.0 * M_PI * (kFrequency/kSampleRate) * sample);
            float env = att + (sample - 0) * ((dec - att) / (buffer.getNumSamples() - 0));
            channelData[sample] = y * env;
        }
    }
    
    // Create a unique_ptr for the writer
    std::unique_ptr<juce::AudioFormatWriter> writer(formatManager.findFormatForFileExtension("wav")
                                          ->createWriterFor(new juce::FileOutputStream(destFile),
                                                             kSampleRate,
                                                             kNumChannels,
                                                             16,
                                                             {},
                                                             0));

    if (writer)
    {
       // Write the mixed samples to the output file
       writer->writeFromAudioSampleBuffer(buffer, 0, buffer.getNumSamples());
    }
    else
    {
       std::cout << "Failed to create a writer for the mixed file." << std::endl;
    }
}
