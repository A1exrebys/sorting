#include "mergesort.h"

/*
 * merge - merge subarrays;
 */
void merge(int *ptr, int low, int mid, int midn, int high)
{
	int l = low, h = midn, cnt = 0;
	int tmp[high - low];

	while (l <= mid && h <= high) {
		if (ptr[l] < ptr[h])
			tmp[cnt++] = ptr[l++];
		else
			tmp[cnt++] = ptr[h++];
	}

	while (l <= mid)
		tmp[cnt++] = ptr[l++];

	while (h <= high)
		tmp[cnt++] = ptr[h++];

	for (int i = low, j = 0; i <= high; i++, j++)
		ptr[i] = tmp[j];
}

/*
 * mergesort - sort array;
 */
void mergesort(int *ptr, int low, int high)
{
	if (high - low < 1)
		return;

	int mid = (high + low) / 2;

	mergesort(ptr, low, mid);
	mergesort(ptr, mid + 1, high);
	merge(ptr, low, mid, mid + 1, high);
}
