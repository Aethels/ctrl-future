// A program that uses a void pointer to print different types of data
#include <stdio.h>
#include <stdlib.h> // For memory allocation functions

void print(void *ptr, char type)
{
    switch (type) // Switching on the type of data
    {
        case 'i': printf("%d\n", *((int *)ptr)); // Printing an int
                  break;
        case 'c': printf("%c\n", *((char *)ptr)); // Printing a char
                  break;
        case 'f': printf("%f\n", *((float *)ptr)); // Printing a float
                  break;
        default: printf("Invalid type\n"); // Printing an error message
                 break;
    }
}

int main(void)
{
    int *x = (int *)malloc(sizeof(int)); // Allocating memory for an int pointer
    char *c = (char *)malloc(sizeof(char)); // Allocating memory for a char pointer
    float *f = (float *)malloc(sizeof(float)); // Allocating memory for a float pointer
    
    if (x == NULL || c == NULL || f == NULL) // Checking if memory allocation failed
    {
        printf("Memory allocation failed\n");
        exit(1); // Terminating the program with an error code
    }
    
    *x = 10; // Assigning a value to the int pointer
    *c = 'a'; // Assigning a value to the char pointer
    *f = 3.14; // Assigning a value to the float pointer
    
    print(x, 'i'); // Passing an int pointer and its type
    print(c, 'c'); // Passing a char pointer and its type
    print(f, 'f'); // Passing a float pointer and its type
    
    free(x); // Freeing the memory allocated for the int pointer
    free(c); // Freeing the memory allocated for the char pointer
    free(f); // Freeing the memory allocated for the float pointer
    
    int *ptr = NULL; // A null pointer declaration
    if (ptr == NULL) // Checking if the pointer is null
    {
        printf("The pointer is null\n");
    }
    else
    {
        printf("The pointer is not null\n");
    }
    return 0;
}

