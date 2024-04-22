#include <stdio.h>
#include <math.h>

float midiToFreq(int a){
    float freq = 440.0 * pow(2.0, (a - 69)/12.0);
    return freq;
}

void print_chord_freq(int arr[], int size){
    for (int i = 0; i < size; i++){
        float f = midiToFreq(arr[i]);
        printf("The value of MIDI note %d is %f\n", arr[i], f);
    }
}

int main(){
    int j;
    int midi[] = {0, 0, 0};
    int y;

    printf("enter total number of notes\n");
    scanf("%d", &j);

    printf("enter note values between 0 - 127\n");

    for (int i = 0; i < j; i++){
        scanf("%d", &midi[i]);
    }

    print_chord_freq(midi, j);
    
    return 0;
}