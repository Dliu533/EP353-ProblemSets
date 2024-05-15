/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicSVFFilterWalkthroughAudioProcessorEditor::BasicSVFFilterWalkthroughAudioProcessorEditor (BasicSVFFilterWalkthroughAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    cutOffSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    cutOffSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100,50);
    addAndMakeVisible (cutOffSlider);
    
    cutOffSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "Peak_Freq", cutOffSlider);
    
    setSize (400, 300);
}

BasicSVFFilterWalkthroughAudioProcessorEditor::~BasicSVFFilterWalkthroughAudioProcessorEditor()
{
}

//==============================================================================
void BasicSVFFilterWalkthroughAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void BasicSVFFilterWalkthroughAudioProcessorEditor::resized()
{
    cutOffSlider.setBounds (getWidth() / 2 - 100, getHeight() / 2 - 50, 200, 100);
}
