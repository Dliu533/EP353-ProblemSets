# Proposal

## What will (likely) be the title of your project?

TODO

## My project will be a resonator that uses peak filters to accentuate certain frequencies.

TODO

## The final software will be an audio plugin that has an external MIDI input. The plug-in will create bands based on MIDI notes inputed and create subsequent bands that are double or half the frequency of the MIDI notes given. Those subsequent bands will be attenuated at amp*(1/n) frequency, with n  being far away they are from the starting band. 

TODO

## N/A

TODO, if applicable

## In the software world, almost everything takes longer to implement than you expect. And it is not uncommon to accomplish less in a fixed amount of time than you hope.

### A good outocme would be to have a set of peak filters that has cutoffs and peaks that are controlled by knobs.
TODO

### A better outcome would be if I get any sort of Peak filter input that can be actively changed by MIDI inputs, however MIDI inputs may be difficult to figure out

TODO

### The best outcome would be to implement everything in the project description, though with the amount that I have listed explicitly it suddenly appears that I have bit off way more than I can chew

TODO

## In a paragraph or more, outline your next steps. What new skills will you need to acquire? What topics will you need to research?

TODO

##I will research the juce::IIRFilter aka Juce Infinite Impulse Response filter, figure out how to implement it in my AudioProcessor.cpp file, and figure out how to attach knobs to it using the juce::AudioProcessorValueTreeState. Once I figure out how to generate these paramenters, I will figure out how to receive MIDI input from the internal MIDI engine in DAWs. The final step is to create an algorithm that generates the IIR filters Dynamicly and attenuate them based on distance.
