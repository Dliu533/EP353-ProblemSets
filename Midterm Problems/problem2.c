#include <stdio.h>

typedef enum Mode {
    Ionian, Dorian, Phrygian
} Mode;

typedef struct Note {
  unsigned char pitch;
  unsigned char velocity;
  unsigned char channel;
} Note;

typedef struct Scale {
  Note notes[7];
  unsigned char rootNote;
} Scale;

int main() {
 
  Scale ionian ={{
    {0, 127, 1},
    {2, 127, 1},
    {4, 127, 1},
    {5, 127, 1},
    {7, 127, 1},
    {9, 127, 1},
    {11, 127, 1}},
    60};
  Scale dorian = {{
    {0, 127, 1},
    {2, 127, 1},
    {3, 127, 1},
    {5, 127, 1},
    {7, 127, 1},
    {9, 127, 1},
    {10, 127, 1}},
    60};
  Scale phrygian = {{
    {0, 127, 1},
    {1, 127, 1},
    {3, 127, 1},
    {5, 127, 1},
    {7, 127, 1},
    {8, 127, 1},
    {10, 127, 1}},
    60};

  //ask the user to enter which mode they want to print out with integers between 0 ~ 2.

int pick;
printf("pick a scale, ionian = 0, dorian = 1, phrygian = 2");
scanf("%d", &pick);
  //choose the mode to use using the Scale structure defined above using the switch statement.
  
switch(pick){
    case 0:
    int rtnotetimesaver;
    printf("pick note between 0 - 127:");
    scanf("%d", &rtnotetimesaver);
    for (int i = 0, i < 127, i++){
        int note = rtnotetimesaver + scale.ionian.pitch;
        printf("%d\n", note);
    }
    break;
    case 1:
    int rtnotetimesaver;
    printf("pick note between 0 - 127:");
    scanf("%d", &rtnotetimesaver);
    for (int i = 0, i < 127, i++){
        int note = rtnotetimesaver + scale.dorian.pitch;
        printf("%d\n", note);
    }

    break;

    case 2:
    int rtnotetimesaver;
    printf("pick note between 0 - 127:");
    scanf("%d", &rtnotetimesaver);
    for (int i = 0, i < 127, i++){
        int note = rtnotetimesaver + scale.phrygian.pitch;
        printf("%d\n", note);
    }

    break;
}
// I know the implementation for this is tremenmdously inaccurate but I am out of time so this is hail mary

  return 0;
}