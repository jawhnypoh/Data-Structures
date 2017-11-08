/* CS261- HW1 - Program5.c*/
/* Name: Johnny Po
 * Date: April 7th, 2017
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	char initials[2];
	int score;
};

void sort(struct student* students, int n) {
     /*Sort the n students based on their initials*/
		 int i, j;
		 struct student temp;

		 for(i=0; i<n; i++) {
			 for(j=0; j<n-1; j++) {
				 if(students[j].initials[0] > students[j+1].initials[0]) {
					 temp = students[j];
					 students[j] = students[j+1];
					 students[j+1] = temp;
				 }

				 if(students[j].initials[0] == students[j+1].initials[0]) {
					if(students[j].initials[1] > students[j+1].initials[1]) {
						temp = students[j];
						students[j] = students[j+1];
						students[j+1] = temp;
					}
				}
			 }
		 }
}

int main(){
    /*Declare an integer n and assign it a value.*/
		int n = 20;

    /*Allocate memory for n students using malloc.*/

		/*If n = 0, then error handle*/
		if(n == 0) {
			printf("ERROR: There is no content to put into the Student Array, exiting... \n");
			printf("\n");
			exit(0);
		}

		struct student *students;

		students = malloc(n*sizeof(*students));

    /*Generate random IDs and scores for the n students, using rand().*/
		srand(time(NULL));

	  char c1, c2;

	  int i;
	  for(i=0; i<n; i++) {

	    c1 = rand()%26 + 'A';
	    c2 = rand()%26 + 'A';

	    int score = rand()%101;

	    students[i].initials[0] = c1;
	    students[i].initials[1] = c2;

	    students[i].score = score;
	  }

    /*Print the contents of the array of n students.*/
    for(i=0; i<n; i++) {
      printf("%d. %c%c %d\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
    }
		printf("\n");

    /*Pass this array along with n to the sort() function*/
		sort(students, n);

    /*Print the contents of the array of n students.*/
		printf("List of Students sorted in Alphabetical Order: \n");
		for(i=0; i<n; i++) {
			printf("%d. %c%c %d\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
		}
		printf("\n");

		/*Free the arrays and the memory that was allocated for them*/
		free(students);

    return 0;
}
