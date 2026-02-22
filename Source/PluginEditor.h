#pragma once
#include "PluginProcessor.h"

class AudioPluginEditor : public juce::AudioProcessorEditor
{
public:
    AudioPluginEditor (AudioPluginProcessor&);
    ~AudioPluginEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginProcessor& audioProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginEditor)
};
