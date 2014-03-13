/*
 *  Write a program that asks the user for 
 *  five names then randomly chooses and
 *  prints out one of the names
*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUMBER 5

int main(void)
{
     string names[5];
     printf("Enter five strings: \n");
     for (int i = 0; i < NUMBER; i++)
     {
         names[i] = GetString();
     }
     srand(time(NULL));   
     printf("%s\n", names[rand() % NUMBER]);
}

