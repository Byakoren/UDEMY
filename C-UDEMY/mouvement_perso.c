#include <stdio.h>
#include <stdlib.h>

void move(int movement, int ** map)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == 5)
            {
                if (movement == 1)
                {
                    if (map[i][j-1] == 0)
                    {
                        map[i][j] = 0; 
                        map[i][j-1] = 5;
                        
                        return;
                    }
                    else if (map[i][j] == 1)
                    {
                        return;
                    }
                    }
                else if (movement == 2)
                {
                    if (map[i][j+1] == 0)
                    {
                        map[i][j] = 0; 
                        map[i][j+1] = 5;
                        
                        return;
                    }
                    else if (map[i][j] == 1)
                    {
                        return;
                    }
                }
                else if (movement == 3)
                {
                    if (map[i-1][j] == 0)
                    {
                        map[i][j] = 0; 
                        map[i-1][j] = 5;
                        
                        return;
                    }
                    else if (map[i][j] == 1)
                    {
                        return;
                    }
                }
                else if (movement == 4)
                {
                    if (map[i+1][j] == 0)
                    {
                        map[i][j] = 0; 
                        map[i+1][j] = 5;
                        
                        return;
                    }
                    else if (map[i][j] == 1)
                    {
                        return;
                    }
                }
            }
        }
    }
}


void displayMapAfterMoves( int ** final_map)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <10; j++)
        {
            printf("%d ", final_map[i][j]);
        }
        printf("\n");
    }
    
    

}


int main() {
    int ** map = malloc(sizeof(int*)*10);
    
    int personnage = 5;
    int mur = 1;
    
    for(int i = 0; i < 10; i++){
        map[i] = calloc(10, sizeof(int));
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i==0 || i == 9 || j ==0 || j == 9){
                map[i][j] = mur;
            }
        }
    }
    
    map[1][1] = personnage;
    
    // map :
    // 1 1 1 1 1
    // 1 5 0 0 1
    // 1 0 0 0 1
    // 1 0 0 0 1
    // 1 1 1 1 1
    
    // 1 = HAUT
    // 2 = BAS
    // 3 = GAUCHE
    // 4 = DROITE
    
    
    int moves[6] = {1,2,4,3,3,4};
    for(int i = 0; i<6; i++){
        move(moves[i], map);
    }
    
    displayMapAfterMoves(map);
    
    return 0;
}
