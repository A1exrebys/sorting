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

void heapsort(int *ptr, int sz)
{
	for (int i = sz/2 - 1; i >= 0; i--)
		heapify(ptr, i, sz);

	for (int i = sz - 1; i >= 0; i--) {
		swap(&ptr[0], &ptr[i]);
		heapify(ptr, 0, i);
	}
}
