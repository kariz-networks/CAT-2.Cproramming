
/*
Name: Joseph kariuki gichuhi
Reg: ct100/G/26129/25
Description: 2d array
*/
#include <stdio.h>

int main() {
    int scores[4][2] = {
        {65, 92},
        {84, 72},
        {35, 70},
        {59, 67}
    };
    
    // Declaration 
    int rows = 4;
    int columns = 2;
    int i, j;

    printf("--- Array  (Scores) ---\n");

    for(i = 0; i < rows; i++) {       
        
        for(j = 0; j < columns; j++) {  
            printf("%d\t", scores[i][j]);
        }
        
        printf("\n");  
    } 
    return 0;
	
	
	
	
	
	
}

