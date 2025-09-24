
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*
 * Complete the function below.
 */
 
char myupper(char c) {
    if (c >= 'a' && c <= 'z') c -= ('a' - 'A');
    return c;
}

char* ucwords(char* string) {
    int i = 0;

    while (string[i] != '\0') {          
        if (i == 0) {
            string[i] = myupper(string[i]);
        } else if (string[i] == ' ') {
            string[i + 1] = myupper(string[i + 1]);  
        }
        i++;
    }
    return string;
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    char* res;
    char* _string;
    _string = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",_string);
    
    res = ucwords(_string);
    fprintf(f, "%s\n", res);
    
    fclose(f);
    return 0;
}
