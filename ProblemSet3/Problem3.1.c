#include <stdio.h>
#include <math.h>

float midiToFreq(int a){
    float freq = 440.0 * pow(2.0, (a - 69)/12.0);
    return freq;
}

int main(){
    int m;
    float f;
    printf("enter in MIDI note Value: \n");
    scanf("%d", &m);
    f = midiToFreq(m);
    printf("The Frequency of MIDI note %d is %f Hz\n", m, f);
    return 0;
}
