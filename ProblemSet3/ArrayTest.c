#include <stdio.h>


int main(){
    int j = 0; 
    int freq[] = {0, 0, 0}; 
    printf("enter total number of notes\n");
    scanf("%d", &j);
    printf("j = %d\n", j);

    printf("enter values\n");

    for (int k = 0; k < j; ++k){
        printf("input %d notes\n", k); 
        scanf("%i", &freq[k]); 
        printf("k is %d\n", k);
        printf("j = %d\n", j);
    }

    printf("printing Values\n");

    for (int i = 0; i < j; ++i){
        printf("%d\n", freq[i]);
        printf("i is %d\n", i);
        printf("j = %d\n", j);
    }

    return 0;
}


