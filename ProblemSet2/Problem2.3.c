#include <stdio.h>

int main(){
    int midiNote;
    scanf("%d", &midiNote);
    if(midiNote>0 && midiNote<127)
    {
        int octave = midiNote/12 - 1;
        printf("The octave for MIDI pitch %d is %d\n", midiNote, octave);
    }
    else
    {
        printf("Invalide MIDI Pitch, Please enter pitch between 1 - 127\n");
    }
    return 0;
}
