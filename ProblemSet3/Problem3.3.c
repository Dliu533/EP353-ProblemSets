#include <stdio.h>
#include <math.h>

void freq_of_chord(int *chord, int size, float *freq);
float midiToFreq(int a);

const int MAX_SIZE = 255;

int main(){

    int chord[32];
    float freq[32];
    int size;

    int *ch = chord;
    float *fr = freq;

    printf("enter chord size 1 - 32\n");

    scanf("%d", &size);

    if(size > 32){
        printf("invalid entry, please enter value between 1 - 32\n");
    }
    else{
        
        printf("enter chord values\n");

        for(int i = 0; i < size; i++){
            scanf("%d", &chord[i]);
        }

        freq_of_chord(chord, size, freq);

        for(int i = 0; i < size; i++){
            printf("%d is %f\n", chord[i], freq[i]);
        }
    
    }

    return 0;
}

float midiToFreq(int a){
    float freq = 440.0 * pow(2.0, (a - 69)/12.0);
    return freq;
}

void freq_of_chord(int *chord, int size, float *freq){
     for (int i = 0; i < size; i++){
        freq[i] = midiToFreq(chord[i]);
        printf("%d is %f\n", i, freq[i]);
     }
}