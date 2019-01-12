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

/*
 * quicksort3 - sort an array of elements;
 */
void quicksort3(int *ptr, int low, int high)
{
	if (high <= low)
		return;

	int pivot = ptr[low];
	int l = low, h = high;
	int ind = low + 1;

	while (ind <= h) {
		if (ptr[ind] < pivot)
			swap(&ptr[ind++], &ptr[l++]);
		else if (ptr[ind] > pivot)
			swap(&ptr[ind], &ptr[h--]);
		else
			ind++;
	}

	quicksort3(ptr, low, l - 1);
	quicksort3(ptr, h + 1, high);
}
