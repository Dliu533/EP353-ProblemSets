#include <stdio.h>

int main(){
    int midiPitch;

    while(midiPitch != -1)
    {
        
    scanf("%d", &midiPitch);

        if(midiPitch == -1){
        
        }
        else if(midiPitch>0 && midiPitch<127)
        {
            int octave = midiPitch/12 - 1;

            int note = midiPitch % 12;
            char *noteName;

            switch(note){
                case 0:
                    noteName = "C";
                    break;
                
                case 1:
                    noteName = "C#";
                    break;

                case 2:
                    noteName = "D";
                    break;

                case 3:
                    noteName = "D#";
                    break;

                case 4:
                    noteName = "E";
                    break;

                case 5:
                    noteName = "F";
                    break;

                case 6: 
                    noteName = "F#";
                    break;
                
                case 7:
                    noteName = "G";
                    break;

                case 8:
                    noteName = "G#";
                    break;

                case 9:
                    noteName = "A";
                    break;

                case 10:
                    noteName = "A#";
                    break;

                case 11:
                    noteName = "B";
                    break;

            };

            printf("The Midi Pitch is %s%d\n", noteName, octave);
        }
        else
        {
            printf("Invalide MIDI Pitch, Please enter pitch between 1 - 127\n");
        }
    }
    
    return 0;
}
