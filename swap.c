// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


void swapsimple(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
    // a devient b - b devient a
}

void swap(int * num1, int * num2) {
    printf("Avant le swap :\n");
    printf("Valeur de num1 = %d \nValeur de num2 = %d \n\n", *num1, *num2);
    
    int temp;
    temp = *num1;
    *num1= *num2;
    *num2= temp;
}


void swapDouble(int ** num1, int ** num2){
    printf("Avant le swap :\n");
    printf("Valeur de num1 = %d \n", **num1);
    printf("Valeur de num2 = %d \n\n", **num2);
    
    int * temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    
    printf("Après le swap :\n");
    printf("Valeur de num1 = %d \n", **num1);
    printf("Valeur de num2 = %d \n\n", **num2);
}

int main() {
    int a = 11;
    int b = 6;
    swap(&a,&b);
    
    int* c = malloc(sizeof(int));
    int * d = malloc(sizeof(int));
    *c = 27;
    *d = 45;
    swapDouble(&c,&d);
    
    return 0;
}

