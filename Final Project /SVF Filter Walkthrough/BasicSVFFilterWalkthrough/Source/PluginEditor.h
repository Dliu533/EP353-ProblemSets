/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicSVFFilterWalkthroughAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BasicSVFFilterWalkthroughAudioProcessorEditor (BasicSVFFilterWalkthroughAudioProcessor&);
    ~BasicSVFFilterWalkthroughAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    juce::Slider cutOffSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutOffSliderAttachment;
    
    BasicSVFFilterWalkthroughAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicSVFFilterWalkthroughAudioProcessorEditor)
};
