cmake_minimum_required(VERSION 3.22)

project(JUCE_CLOUD_STARTER VERSION 0.0.1)

# Include JUCE via FetchContent to avoid local installation
include(FetchContent)
FetchContent_Declare(
    juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        master # Latest JUCE
)
FetchContent_MakeAvailable(juce)

juce_add_plugin(JuceCloudPlugin
    COMPANY_NAME "MyCloudStudio"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PLUGIN_MANUFACTURER_CODE Jcld
    PLUGIN_CODE Plug
    FORMATS VST3 Standalone
    PRODUCT_NAME "JuceCloudPlugin")

target_sources(JuceCloudPlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp)

target_compile_definitions(JuceCloudPlugin PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0)

target_link_libraries(JuceCloudPlugin PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_extra
    juce::juce_gui_basics
    juce::juce_graphics
    juce::juce_events
    juce::juce_core)
