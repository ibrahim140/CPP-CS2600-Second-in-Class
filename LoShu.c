/*
    Description: This program is intended to create a 2D array of integers ranging from 1-9. 
     The program will continuoulsy, and randomly, populate the array without any number repeating,
     until a 'Lo Shu Magic Square' appears. At which point the program will print out the number of
     tries it took to get the magic square as well as the 2D array before terminating.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkLoShuSquare(int arr[3][3])
{
    const int LO_SHU_VALUE = 15;
    int addition = 0;

    for (int row = 0; row < 3; row++)
    {
        addition = 0;
        for (int column = 0; column < 3; column++)
        {
            addition += arr[row][column];
        }
        if (addition != LO_SHU_VALUE)
        {
            return 1;
        }
    }

    for (int row = 0; row < 3; row++)
    {
        addition = 0;
        for (int column = 0; column < 3; column++)
        {
            addition += arr[column][row];
        }
        if (addition != LO_SHU_VALUE)
        {
            return 1;
        }  
    }
    
    return 0;
}

void printArray(int arr[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        printf("[ ");
        for (int column = 0; column < 3; column++)
        {
            printf("%d ",arr[row][column]);
        }
        printf("]\n");
    }
}

int main()
{
    int loShuSquare[3][3];
    int counter = 0; 
    
    return 0;
}