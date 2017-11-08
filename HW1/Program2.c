/* CS261- HW1 - Program2.c*/
/* Name: Johnny Po
 * Date: April 4th, 2017
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

struct student* allocate() {
     /*Allocate memory for ten students*/
     struct student *students;

     students = malloc(10*sizeof(*students));

     /*return the pointer*/
     return students;
}

void generate(struct student* students) {
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/

  /* Generate two random letters for the students' initials */
  srand(time(NULL));

  char c1, c2;

  int i;
  for(i=0; i<10; i++) {

    c1 = rand()%26 + 'A';
    c2 = rand()%26 + 'A';

    int score = rand()%101;

    students[i].initials[0] = c1;
    students[i].initials[1] = c2;

    students[i].score = score;
  }
}

void output(struct student* students) {
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/

    int i;
    for(i=0; i<10; i++) {
      printf("%d. %c%c %d\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
    }
}

void summary(struct student* students) {
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = students[0].score;
     int i;
     for(i=0; i<10; i++) {
       if(students[i].score < min) {
         min = students[i].score;
       }
     }

     printf("\n");
     printf("The minimum value is: %d\n", min);

     int max = students[0].score;
     for(i=0; i<10; i++) {
       if(students[i].score > max) {
         max = students[i].score;
       }
     }

     printf("\n");
     printf("The maximum value is: %d\n", max);

     int sum = 0;
     int avg;

     for(i=0; i<10; i++) {
       sum = sum + students[i].score;
     }

     avg = sum / 10;

     printf("\n");
     printf("The average value is: %d\n", avg);

     printf("\n");
}

void deallocate(struct student* stud) {
     /*Deallocate memory from stud*/
     free(stud);
}

int main() {
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
