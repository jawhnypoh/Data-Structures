/* CS261- HW1 - Program1.c*/
/* Name: Johnny Po
 * Date: April 4th, 2017
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {
    /* Increment a */
    *a += 1;
    printf("a is %d\n", *a);

    /* Decrement  b */
    *b -= 1;
    printf("b is %d\n", *b);

    /* Assign a-b to c */
    c = *a - *b;
    printf("c is %d\n", c);

    printf("\n");
    /* Return c */
    return c;
}

int main() {
    srand(time(NULL));

    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand()%10;

    int y = rand()%10;

    int z = rand()%10;

    int c;

    /* Print the values of x, y and z */
    printf("x before foo() is: %d \n", x);

    printf("y before foo() is: %d\n", y);

    printf("z before foo() is: %d\n", z);

    printf("\n");

    /* Call foo() appropriately, passing x,y,z as parameters */
    c = foo(&x, &y, z);

    /* Print the values of x, y and z */
    printf("x after foo() is: %d \n", x);

    printf("y after foo() is: %d\n", y);

    printf("z after foo() is: %d\n", z);

    printf("\n");

    /* Print the value returned by foo */
    printf("c returned from the function foo() is: %d\n", c);

    /* Is the return value different than the value of z?  Why? */

    return 0;
}
