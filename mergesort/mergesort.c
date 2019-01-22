#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergesort.h"

#define NITEMS	10

static void print_array(const int *ptr, int sz)
{
	for (size_t i = 0; i < sz; i++)
		printf("%d ", *ptr++);

	printf("\n");
}

int main(void)
{
	int *ptr = (int *)malloc(sizeof(int) * NITEMS);
	int *head = ptr;

	if (ptr == NULL)
		return -1;

	srand(time(NULL));

	for (size_t i = 0; i < NITEMS; i++) {
		*ptr = rand() % 10;
		ptr++;
	}

	print_array(head, NITEMS);

	mergesort(head, 0, NITEMS - 1);

	print_array(head, NITEMS);
}
