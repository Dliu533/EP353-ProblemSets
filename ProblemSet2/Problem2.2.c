#include <stdio.h>
#include <math.h>

float freqForm(float);

float freqForm(float p){
    float f;
    float t = (p-69)/12;
    float i = pow(2, t);
    f = i*440;
    return f;
}

int main(){
    float C4 = 60, A4 = 69;
    C4 = freqForm(C4);
    A4 = freqForm(A4);
    printf("The Frequency for MIDI pitch for C4 is %f\nThe Frequency for MIDI pitch for A4 is %f\n", C4, A4);
    return 0;
}
