/*
    Description: This program is intended to create a 2D array of integers ranging from 1-9. 
     The program will continuoulsy, and randomly, populate the array without any number repeating,
     until a 'Lo Shu Magic Square' appears. At which point the program will print out the number of
     tries it took to get the magic square as well as the 2D array before terminating.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to check if the 2D array is a Lo Shu Square (accepts a 2D array as a parameter)
int checkLoShuSquare(int arr[3][3]) //return 0 for true and 1 for false
{
    // constant to compare to
    const int LO_SHU_VALUE = 15;
    // local variable to hold the total of each row, column, or diagonal
    int addition = 0;

    // iterate through all rows
    for(int row = 0; row <= 2; row++)
    {
        // reset addition to 0 for each row
        addition = 0;
        // iterate through each column in each row
        for(int column = 0; column <= 2; column++)
        {
            addition += arr[row][column];
        }
        // check if the value adds up to 15
        if(addition != LO_SHU_VALUE)
        {
            // return false
            return 1;
        }
    }

    // iterate through all columns
    for(int row = 0; row <= 2; row++)
    {
        // reset addition to 0 for each row
        addition = 0;
        // iterate through each column in each row
        for(int column = 0; column <= 2; column++)
        {
            addition += arr[column][row];
        }
        // check if the value adds up to 15
        if(addition != LO_SHU_VALUE)
        {
            // return false
            return 1;
        }
    }
    
    // reset variable
    addition = 0;
    // iterate through the 2D array diagonally (top left to bottom right)
    for(int row = 0; row <= 2; row++)
    {
        addition += arr[row][row];
    }
    if(addition != LO_SHU_VALUE)
    {
        // return false
        return 1;
    }

    // reset variable
    addition = 0;
    // iterate through the 2D array diagonally (bottom left to top right)
    for(int row = 0; row <= 2; row++)
    {
        addition += arr[2-row][row];
    }
    if(addition != LO_SHU_VALUE)
    {
        // return false
        return 1;
    }

    // return true
    return 0;
}

// array to print out the matrix/2D array
void printArray(int arr[3][3])
{
    // iterate through each row
    for(int row = 0; row <= 2; row++)
    {
        // print open bracket for each set of 3 integers
        printf("[ ");
        // iterate through each column
        for(int column = 0; column <= 2; column++)
        {
            // print 2D array
            printf("%d ", arr[row][column]);
        }
        // print close bracket for each set of 3 integers
        printf("]\n");
    }
}

void main()
{
    // declare 2D array
    int loShuSquare[3][3];
    // initialize counter and declare random variable
    int counter = 0, randomNumber;

    // simulating a Lo Shu Square using predefined array
    int firstArray[3][3] = {{4, 2, 9}, {3, 5, 7}, {1, 8, 6}};       // is not a lo shu square
    // print first array
    printArray(firstArray);
    // check if the first array is a lo shu square
    if(checkLoShuSquare(firstArray) == 0)
    {
        printf("This is a Lo Shu Square.\n");
    }
    else
    {
        printf("This is NOT a Lo Shu Square.\n");
    }

    // simulating a Lo Shu Square using predefined array
    int secondArray[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};      // is a lo shu square
    // print second array
    printArray(secondArray);
    // check if the second array is a lo shu square
    if(checkLoShuSquare(secondArray) == 0)
    {
        printf("This is a Lo Shu Square.\n");
    }
    else
    {
        printf("This is NOT a Lo Shu Square.\n");
    }


    // iterate through infinitely (any non-zero value can be used here)
    while(-1)
    {
        // create a temporary array (MUST bebe inside the infinite while loop)
        int tempArray[10] = {2, };
        // get new seed for random number each time
        srand(time(0) + counter);
        // iterate through each rows
        for(int row = 0; row <= 2; row++)
        {
            // iterate through each column
            for(int column = 0; column <= 2; column++)
            {
                // loop through as long as the condition is true
                while(tempArray[randomNumber])
                {
                    // store a random value from 1 to 9 in variable
                    randomNumber = (rand() % 9) + 1;
                }
                // populate 2D array with random values from to 1 to 9 (w/o repetition)
                loShuSquare[row][column] = randomNumber;
                // assign an integer value to the index specifed by the random value in the tempArray
                tempArray[randomNumber] = 10;
            }
        }

        // increment counter each time the loop is run, returns the amount of tries it took to get a lo shu square
        counter++;

        // check if the 2D array thats passed in the function call is a lo shu square, if so, the function will return 0
        if(checkLoShuSquare(loShuSquare) == 0)
        {
            // breaks out of loop
            break;
        }
    }

    // let the user know how many times it took to get a Lo Shu Square
    printf("\nNumber of attempts required for a Lo Shu Square to be generated randomly is: %d\n", counter);

    printArray(loShuSquare);
}