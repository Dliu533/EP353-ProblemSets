#include <stdio.h>


typedef struct MIDINote{
    int pitch;
    int vel;
    int channel;
}MIDINote;

void print_MIDI_note(MIDINote *pNote);

int main(){

    MIDINote note1;
    MIDINote *pNote1 = &note1;

    printf("enter pitch, velocity, channel\n");

    scanf("%d", &note1.pitch);
    scanf("%d", &note1.vel);
    scanf("%d", &note1.channel);

    print_MIDI_Note(pNote1);

    return 0;
}

void print_MIDI_Note(MIDINote *pNote){
    printf("%d\n", pNote->pitch);
    printf("%d\n", pNote->vel);
    printf("%d\n", pNote->channel);
}