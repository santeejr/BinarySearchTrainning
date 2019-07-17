#include <stdio.h>
#include <stdlib.h>

int binarySearch(int A[], int x, int min, int max)
{
	max--;
	int mid = 0;
	do {
		mid = (min+max) / 2;
		if (x > A[mid])
			min = mid + 1;
		else
			max = mid - 1;
	} while ((A[mid] != x) && (min <= max));

	return (min <= max) ? mid : -1;
}

int comparator(const void *a, const void *b)
{
	int x = *((int*)a);
	int y = *((int*)b);
	return (x - y);
}

int main(int argc, char **argv)
{
	int i;
	int a[] = {1,4,7,8,6,42,34,55,56,64,67,486,708,65,4543,356,653};

	qsort( a, sizeof(a)/sizeof(int), sizeof(int), comparator);
	for (i = 0; i < sizeof(a)/sizeof(int); i++)
		printf("%d ", a[i]);

	int index = binarySearch(a, 4, 0, sizeof(a)/sizeof(int));
	if (index != -1)
		printf("\nNumber has been found at index %d.\n", index+1);
	else
		printf("\nThe number is not in the list.\n");
	return 0;
}

