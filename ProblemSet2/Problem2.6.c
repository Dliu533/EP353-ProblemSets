#include <stdio.h>

int main(){
    
    int note1 = 0;
    
    for (int i = 0; i <= 12; i++)
    {
        int note2 = 0;
        
        for (int i = 0; i <= 12; i++)
        {
            char *intName;
            int interval = (note2 - note1 + 12) % 12;

             switch(interval){
                case 0:
                    intName = "unison";
                    break;
                
                case 1:
                    intName = "minor 2nd";
                    break;

                case 2:
                    intName = "major 2nd";
                    break;

                case 3:
                    intName = "minor 3rd";
                    break;

                case 4:
                    intName = "major 3rd";
                    break;

                case 5:
                    intName = "4th";
                    break;

                case 6: 
                    intName = "augmented 4th";
                    break;
                
                case 7:
                    intName = "perfect fifth";
                    break;

                case 8:
                    intName = "minor 6th";
                    break;

                case 9:
                    intName = "major 6th";
                    break;

                case 10:
                    intName = "minor 7th";
                    break;

                case 11:
                    intName = "major 7th";
                    break;
             }
                

            printf("the interval from note %d to note %d is a %s\n", note2, note1, intName);
            note2++;

        }

        note1++;
    }
    return 0;
}
