/* CS261- HW1 - Program3.c*/
/* Name: Johnny Po
 * Date: April 5th, 2017
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void sort(int* numbers, int n) {
     /*Sort the given array numbers , of length n*/
     int min, i, j;

     printf("\n");
     for(i=0; i<n; i++) {
       for(j=0; j<n-1; j++) {
        if(numbers[j] > numbers[j+1]) {
          min = numbers[j];
          numbers[j] = numbers[j+1];
          numbers[j+1] = min;
        }
      }
     }

     printf("\n");
}

int main() {
    srand(time(NULL));

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *numbers;

    numbers = malloc(n*sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    int i;
    for(i=0; i<n; i++) {
      numbers[i] = rand()%101;
    }

    /*Print the contents of the array.*/
    printf("Array numbers in Original Order: \n");
    for(i=0; i<n; i++) {
      printf("%d ", numbers[i]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(numbers, n);

    /*Print the contents of the array.*/
    printf("Array numbers in Ascending Order: \n");
    for(i=0; i<n; i++) {
      printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}
