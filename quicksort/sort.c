#include "quicksort.h"

static void swap(int *lhs, int *rhs)
{
	int ptr = *lhs;
	*lhs = *rhs;
	*rhs = ptr;
}

/*
 * quicksort - sort an array of elements;
 */
void quicksort(int *ptr, int low, int high)
{
	int pivot = ptr[(low + high) / 2];
	int l = low;
	int h = high;

	while (l <= h) {
		while (ptr[l] < pivot)
			l++;

		while (ptr[h] > pivot)
			h--;

		if (l <= h) {
			swap((ptr + l), (ptr + h));
			l++; h--;
		}
	}

	if (low < h)
		quicksort(ptr, low, h);
	if (l < high)
		quicksort(ptr, l, high);
}
