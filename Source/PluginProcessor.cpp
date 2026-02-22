#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginProcessor::AudioPluginProcessor()
     : AudioProcessor (BusesProperties().withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{}

AudioPluginProcessor::~AudioPluginProcessor() {}

const juce::String AudioPluginProcessor::getName() const { return "JuceCloudPlugin"; }
bool AudioPluginProcessor::acceptsMidi() const { return false; }
bool AudioPluginProcessor::producesMidi() const { return false; }
bool AudioPluginProcessor::isMidiEffect() const { return false; }
double AudioPluginProcessor::getTailLengthSeconds() const { return 0.0; }
int AudioPluginProcessor::getNumPrograms() { return 1; }
int AudioPluginProcessor::getCurrentProgram() { return 0; }
void AudioPluginProcessor::setCurrentProgram (int index) {}
const juce::String AudioPluginProcessor::getProgramName (int index) { return {}; }
void AudioPluginProcessor::changeProgramName (int index, const juce::String& newName) {}

void AudioPluginProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {}
void AudioPluginProcessor::releaseResources() {}

void AudioPluginProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
            channelData[sample] *= 0.5f;
    }
}

bool AudioPluginProcessor::hasEditor() const { return true; }
juce::AudioProcessorEditor* AudioPluginProcessor::createEditor() { return new AudioPluginEditor (*this); }

void AudioPluginProcessor::getStateInformation (juce::MemoryBlock& destData) {}
void AudioPluginProcessor::setStateInformation (const void* data, int sizeInBytes) {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new AudioPluginProcessor(); }
