#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginEditor::AudioPluginEditor (AudioPluginProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

AudioPluginEditor::~AudioPluginEditor() {}

void AudioPluginEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::cyan);
    g.setFont (24.0f);
    g.drawFittedText ("JUCE Cloud Starter\nProgramando sin espacio!", getLocalBounds(), juce::Justification::centred, 2);
}

void AudioPluginEditor::resized() {}
