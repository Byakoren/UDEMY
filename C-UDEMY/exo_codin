#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
char ** mountain(int * array, int arraysize , int *maxheigth, int *maxlen){

    int i = 0;

    int temp = array[i];

    for(i = 0; i < arraysize; i++){

        if (temp < array[i]){
            temp=array[i];
        }
    }
    *maxlen = temp;
    int temp2 = 0;
    for(i = 0; i < arraysize; i++){
        temp2=temp2+ array[i]*2;
    }
    char **T = malloc(sizeof(char*)*temp2);
    *maxheigth = temp2;
    for(int i =0; i<temp2 ; i++){
        T[i]=malloc(sizeof(char)*temp);
    }
    return T;
}



int main()
{
    // the number of mountains
    int n;
    scanf("%d", &n);
    int *T = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        // height of the mountain
        int height;
        scanf("%d", &height);
        T[i]=height;
    }
    int maxheigth;
    int maxlen;
    char ** table = mountain(T ,n ,&maxheigth , &maxlen);

    for(int i = 0; i < n; i++){
        for(int j = 0; j< T[i];j++ ){
            for(int k = 0; k<T[j]; k++){
                if (k / 2 > T[j]){
                    table[i][j] = '\\';
                }
                else {
                    table[i][j] = '/';
                }
            }
        }
    }
    for(int i =0; i< maxheigth; i++){
        for(int j=0 ; j< maxlen; j ++){
            printf("%c", table[i][j]);

        }
        printf("\n");
    }
    
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("answer\n");

    return 0;
}