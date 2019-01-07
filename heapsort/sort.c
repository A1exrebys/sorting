#include "heapsort.h"

static void swap(int *lhs, int *rhs)
{
	int ptr = *lhs;
	*lhs = *rhs;
	*rhs = ptr;
}

static void heapify(int *ptr, int num, int sz)
{
	for (;;) {
		int l = 2 * num + 1;
		int r = 2 * num + 2;
		int large = num;

		if (l < sz && ptr[l] > ptr[large])
			large = l;

		if (r < sz && ptr[r] > ptr[large])
			large = r;

		if (large == num)
			return;

		swap(&ptr[large], &ptr[num]);

		num = large;
	}
}

#if 0
void heapsort(int *ptr, int sz)
{
	for (int i = sz/2 - 1; i >= 0; i--)
		heapify(ptr, i, sz);

	for (int i = sz - 1; i >= 0; i--) {
		swap(&ptr[0], &ptr[i]);
		heapify(ptr, 0, i);
	}
}
#endif

/*
 * heapsort - sort an array of elements;
 * ptr - pointer to data to sort;
 * sz - number of elements;
 */
void heapsort(int *ptr, int sz)
{
	int curr, root;

	/* heapify */
	for (int i = sz/2 -1 ; i >= 0; i--) {
		for (root = i; root * 2 + 1 < sz; root = curr) {
			curr = root * 2 + 1; /* left */

			if (curr < sz - 1 && *(ptr + curr) < *(ptr + curr + 1))
				curr += 1;	/* right */

			if (*(ptr + curr) <= *(ptr + root))
				break;

			swap(ptr + root, ptr + curr);
		}
	}

	for (int i = sz - 1; i >= 0; i--) {
		swap(ptr, ptr + i);
		for (root = 0; root * 2 + 1 < i; root = curr) {
			curr = root * 2 + 1; /* left */

			if (curr < i - 1 && *(ptr + curr) < *(ptr + curr + 1))
				curr += 1;	/* right */

			if (*(ptr + curr) <= *(ptr + root))
				break;

			swap(ptr + root, ptr + curr);
		}
	}
}
