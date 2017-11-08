#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "skipList.h"
#include <time.h>

/* ************************************************************************
Main Function
 ************************************************************************ */
/* Test function:
 param: no parameters
 pre:	no parameres
 post: prints out the contents of the skip list */

void test() {
	int i,j;
	int M;
	struct skipList *slst;

	 srand ( time(NULL) );


	slst = (struct skipList *)malloc(sizeof(struct skipList));  /*2*/
	assert(slst);


	/*  Initialize the skip list */

        /*  FIX ME */
				initSkipList(slst);
	/*  Add to the skip list  M = 20 random integers in [0,100] */

        /*  FIX ME */
				for(i=0; i<20; i++) {
					addSkipList(slst, rand()%101);
				}

	/*  Print out the contents of the skip list in the breadth-first order,
            starting from top.
	    While printing the elements,
            move to a new line every time you reach the end of one level,
	    and move down to the lower level of the skip list.
	    For example, the print out of a skip list with 5 elements
            should look like

	    7
	    7 14 29
	    3 7 9 14 20
	 */


        /*  FIX ME */
				printf("SkipList: \n");
				printf("The size is: %d \n", sizeSkipList(slst));
				printSkipList(slst);

	/* Develop 3 test cases for printing out the contents of skip list
           after remove function:
	         int removeSkipList(struct skipList *slst, TYPE e)
	 */


        /*  FIX ME */
				printf("Removing 3 random integers from the skipList...\n");
				for(i=0; i<=3; i++) {
					printf("Skip list before removing the integers: \n");
					printSkipList(slst);
					removeSkipList(slst, slst->topSentinel->next->value);
					printf("Skip list after removing the integers: \n");
					printSkipList(slst);
					printf("\n");
				}

         /* Develop 3 test cases corresponding to the above 3 test cases
            for printing out the output of contains function when e is equal to
            the elements you removed above:
	          int containsSkipList(struct skipList *slst, TYPE e)
	 */


        /*  FIX ME */
				for(i=0; i<=3; i++) {
					printf("The element has been found. \n ");
					printf("The element is %d \n", containsSkipList(slst, slst->topSentinel->next->value));
					printSkipList(slst);
				}

				printf("Removed %g from the SkipList \n", slst->topSentinel->next->value);
				removeSkipList(slst, slst->topSentinel->next->value);
				printf("The new size is: %d \n", sizeSkipList(slst));
				printSkipList(slst);
}


/* ************************************************************************
Internal Functions
 ************************************************************************ */

/* Coin toss function:
 param: 	no parameters
 pre:	no parameres
 post: output is a random integer number in {0,1} */
int flipSkipLink(void) {
	return rand() % 2;
}

/* Move to the right as long as the next element is smaller than the input value:
 param: 	current -- pointer to a place in the list from where we need to slide to the right
 param:	e --  input value
 pre:	current is not NULL
 post: returns one link before the link that contains the input value e */
struct skipLink * slideRightSkipList(struct skipLink *current, TYPE e) {
	while ((current->next != 0) && LT(current->next->value, e))
		current = current->next;
	return current;
}


/* Create a new skip link for a value
	param: e	 -- the value to create a link for
	param: nextLnk	 -- the new link's next should point to nextLnk
	param: downLnk -- the new link's down should point to downLnk
	pre:	none
	post:	a link to store the value */
struct skipLink* newSkipLink(TYPE e, struct skipLink * nextLnk, struct skipLink* downLnk) {
	struct skipLink * tmp = (struct skipLink *) malloc(sizeof(struct skipLink));
	assert(tmp != 0);
	tmp->value = e;
	tmp->next = nextLnk;
	tmp->down = downLnk;
	return tmp;
}


/* Add a new skip link recursively
 param: current -- pointer to a place in the list where the new element should be inserted
 param: e	 -- the value to create a link for
 pre:	current is not NULL
 post: a link to store the value */
struct skipLink* skipLinkAdd(struct skipLink * current, TYPE e) {

	/* FIX ME */
	struct skipLink *new, *down;
	new = 0;
	assert(current);

	if(current->down == 0) {
		new = newSkipLink(e, current->next, 0);
		current->next = new;
	}
	else {
		down = skipLinkAdd(slideRightSkipList(current->down, e), e);
		if(down && flipSkipLink()) {
			new = newSkipLink(e, current->next, down);
			current->next = new;
		}
	}
	return new;
}


/* ************************************************************************
Public Functions
 ************************************************************************ */

/* Initialize skip list:
 param:  slst -- pointer to the skip list
 pre:	slst is not null
 post: the sentinels are allocated, the pointers are set, and the list size equals zero */
void initSkipList (struct skipList *slst) {
	slst->size=0;
	slst->topSentinel=(struct skipLink * )malloc(sizeof(struct skipLink));
	assert(slst->topSentinel);
	slst->topSentinel->next=NULL;
	slst->topSentinel->down=NULL;
}

/* Checks if an element is in the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be checked
 pre:	slst is not null
 post: returns true or false  */
int containsSkipList(struct skipList *slst, TYPE e) {
	struct skipLink *tmp = slst->topSentinel;
	while (tmp != 0) {  /* 2pts */
		tmp = slideRightSkipList(tmp, e); /* 1pt */
		if ((tmp->next != 0) && EQ(e, tmp->next->value)) /* 2pts */
			return 1;
		tmp = tmp->down;  /* 1pt */
	}
	return 0;
}


/* Remove an element from the skip list:
 param: slst -- pointer to the skip list
 param: e -- element to be removed
 pre:	slst is not null
 post: the new element is removed from all internal sorted lists */
void removeSkipList(struct skipList *slst, TYPE e) {
	struct skipLink *current, *tmp;
	current = slst->topSentinel; /* 1pts */
	while (current != 0) {  /* 2pts */
		current = slideRightSkipList(current, e);
		if (current->next != 0 && EQ(e, current->next->value)) {  /* 2pts */
			tmp = current->next; /* 2pts */
			current->next = current->next->next;
			free(tmp);    /* 2pts */
			if (current->down == NULL)
				slst->size--;   /* 2pts */
		}
		current = current->down; /* 1pt */
	}
}




/* Add a new element to the skip list:
	param: slst -- pointer to the skip list
	param: e -- element to be added
	pre:	slst is not null
	post:	the new element is added to the lowest list and randomly to higher-level lists */
void addSkipList(struct skipList *slst, TYPE e) {

	/* FIX ME */
	struct skipLink *lnkDown, *lnkNew;
	lnkDown = skipLinkAdd(slideRightSkipList(slst->topSentinel, e), e);
	if(lnkDown != 0 && flipSkipLink()) {
		struct skipLink *newTopSentinel = (struct skipLink *) malloc (sizeof(struct skipLink));
		lnkNew = newSkipLink(e, 0, lnkDown);
		newTopSentinel->next = lnkNew;
		newTopSentinel->down = slst->topSentinel;
		slst->topSentinel = newTopSentinel;
	}
	slst->size++;
}

/* Find the number of elements in the skip list:
 param: slst -- pointer to the skip list
 pre:	slst is not null
 post: the number of elements */
int sizeSkipList(struct skipList *slst) {

	return slst->size;

}


/* Print the links in the skip list:
	param: slst -- pointer to the skip list
	pre:	slst is not null and slst is not empty
	post: the links in the skip list are printed breadth-first, top-down */
void printSkipList(struct skipList *slst) {

	/* FIX ME*/
	struct skipLink *lstCurrent = slst->topSentinel;
	struct skipLink *lnkCurrent;

	while(lstCurrent != NULL) {
		lnkCurrent = lstCurrent->next;
		while(lnkCurrent != NULL) {
			printf("%g ", lnkCurrent->value);
			lnkCurrent = lnkCurrent->next;
		}
		lstCurrent = lstCurrent->down;
		printf("\n");
	}
}


/* Merge two skip lists, by adding elements of skip list 2 to skip list 1
 that are not already contained in skip list 1.
 The function is also supposed to remove the entire skip list 2 from the memory.
 param: slst1 -- pointer to the skip list 1
 param: slst2 -- pointer to the skip list 2
 pre: slst1 and slst2 are not null, and skip list 1 and skip list 2 are not empty
 post: slst1 points to the merger skip list,  slst2 is null*/
void mergeSkipList(struct skipList *slst1, struct skipList *slst2) {

	/* FIX ME*/
	struct skipLink *current, *lvl;
	current = slst2->topSentinel;
	while(current->down != NULL) {
		current = current->down;
	}

	while(current->next != NULL) {
		if(!containsSkipList(slst1, current->next->value)) {
			addSkipList(slst1, current->next->value);
		}
		current = current->next;
	}

	current = slst2->topSentinel;
	while(current->down != NULL) {
		current = current->down;
	}

	current = current->next;
	lvl = current->next;
	while(current->next != NULL) {
		removeSkipList(slst2, current->value);
		current = lvl;
		lvl = lvl->next;
	}
} /* end of the function */
