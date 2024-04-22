#include <stdio.h>

//print the number matrix using this function prototype.
void printMatrix(int width, int height){
    for(int i = 0; i < height; i++){
         for(int j = 0; j < width; j++){
            int w[100];
            int w[i] = j + i;
            printf("%d", w[i]);

            // was not able to print out lists that wrap around 0, but I need to move on
        }
        printf("\n");
    }
}    
    

int main(){
    int x;
    int y;
    
    printf("enter width and height:\n");
    scanf("%d", &x);
    scanf("%d", &y);
    //ask the user for width and height

    if(x > 0 && y > 0){
        printMatrix(x,y);
    }
    else{
        printf("invalid value, please enter a positive int\n");
    }
    return 0;
}