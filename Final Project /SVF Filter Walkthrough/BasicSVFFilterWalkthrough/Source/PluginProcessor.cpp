/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicSVFFilterWalkthroughAudioProcessor::BasicSVFFilterWalkthroughAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

BasicSVFFilterWalkthroughAudioProcessor::~BasicSVFFilterWalkthroughAudioProcessor()
{
}

//==============================================================================
const juce::String BasicSVFFilterWalkthroughAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BasicSVFFilterWalkthroughAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BasicSVFFilterWalkthroughAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BasicSVFFilterWalkthroughAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double BasicSVFFilterWalkthroughAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BasicSVFFilterWalkthroughAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BasicSVFFilterWalkthroughAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BasicSVFFilterWalkthroughAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String BasicSVFFilterWalkthroughAudioProcessor::getProgramName (int index)
{
    return {};
}

void BasicSVFFilterWalkthroughAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void BasicSVFFilterWalkthroughAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    filter.prepare(spec);
    
    reset();
}

void BasicSVFFilterWalkthroughAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool BasicSVFFilterWalkthroughAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void BasicSVFFilterWalkthroughAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    auto p = apvts.getRawParameterValue("Peak_Freq");

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    filter.setCutoffFrequency (p);

    auto audioBlock = juce::dsp::AudioBlock<float> (buffer);
    auto context = juce::dsp::ProcessContextReplacing<float>(audioBlock);
    
    filter.process (context);
}

//==============================================================================
bool BasicSVFFilterWalkthroughAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* BasicSVFFilterWalkthroughAudioProcessor::createEditor()
{
    return new BasicSVFFilterWalkthroughAudioProcessorEditor (*this);
}

//==============================================================================
void BasicSVFFilterWalkthroughAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BasicSVFFilterWalkthroughAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BasicSVFFilterWalkthroughAudioProcessor();
}

void BasicSVFFilterWalkthroughAudioProcessor::reset()
{
    filter.reset();
}

void BasicSVFFilterWalkthroughAudioProcessor::setType()
{
    switch (filtertype)
    {
            
        case FilterType::LowPass:
            filter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
        case FilterType::BandPass:
            filter.setType(juce::dsp::StateVariableTPTFilterType::bandpass);
            break;
        case FilterType::HighPass:
            filter.setType(juce::dsp::StateVariableTPTFilterType::highpass);
            break;
            
        default:
            filter.setType(juce::dsp::StateVariableTPTFilterType::lowpass);
            break;
    }

}

//==============================================================================

juce::AudioProcessorValueTreeState::ParameterLayout BasicSVFFilterWalkthroughAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    
   /* layout.add(std::make_unique<juce::AudioParameterFloat>("LowCut Freq", "LowCut Freq", juce::NormalisableRange<float>(20.f, 10000.f, 1.f, 0.25f), 20.f));
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("HighCut Freq", "HighCut Freq", juce::NormalisableRange<float>(20.f, 10000.f, 1.f, 0.25f), 20000.f));
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Freq", "Peak Freq", juce::NormalisableRange<float>(20.f, 10000.f, 1.f, 0.25f), 750.f));
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Gain", "Peak Gain", juce::NormalisableRange<float>(-24.f, 24.f, 0.5f, 1.f), 0.0f));
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Quality", "Peak Quality", juce::NormalisableRange<float>(0.5f, 10.f, 0.05f, 1.f), 1.0f));
    
    juce::StringArray stringArray;
    for( int i = 0; i < 4; ++i)
    {
        juce::String str;
        str << (12 + i*12);
        str << "db/Oct";
        stringArray.add(str);
    }
    
    layout.add(std::make_unique<juce::AudioParameterChoice>("LowCut Slope", "LowCut Slope", stringArray, 0));
    
    layout.add(std::make_unique<juce::AudioParameterChoice>("HighCut Slope", "HighCut Slope", stringArray, 0));*/
    
    layout.add(std::make_unique<juce::AudioParameterFloat>("Peak_Freq", "Peak Freq", juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.25f), 250.f));

    
    return layout;
}

