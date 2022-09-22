#include "sorts.h"
#define Swap(type, a, b) {type temp = a; a = b; b = temp;}

void selection_sort(num* i, size_t size)
{
	//num* end = i + size;
	for (num* end = i + size; i < end; i++)
	{
		//searching minimum
		num* min = i;
		for (num* j = i+1; j < end; j++)
		{
			if (*j < *min)
			{
				min = j;
			}
		}
		Swap(num, *i, *min);
	}
}

void bubble_sort(num* arr, size_t len)
{
	num* i = arr;
	num* end = arr + len;
	num* b_start = arr + 1;
	bool n_sorted = true;
	while (n_sorted)
	{
		n_sorted = false;
		for (num* b = b_start; b < end; b++)
		{
			if (b[0] < b[-1])
			{
				Swap(num, b[0], b[-1]);
				n_sorted = true;
			}
		}
	}
}

void optimized_bubble_sort(num* arr, size_t len)
{
	num* i = arr;
	num* end = arr + len;
	num* b_start = arr + 1;
	bool n_sorted = true;
	while (n_sorted)
	{
		n_sorted = false;
		
		num* b = b_start;
		while (b < end-1)
		{
			if (b[0] < b[-1])
			{
				Swap(num, b[0], b[-1]);
				n_sorted = true;
			}
			b++;
		}
		if (b[0] < b[-1])
		{
			Swap(num, b[0], b[-1]);
			n_sorted = true;
			end--;
		}
		else
		{
			end -= 2;
		}
	}
}

inline num* partition(num* arr, size_t len)
{
	return arr + len / 2;
}

void quick_sort(num* arr, size_t size)
{
	if (size < 2) { return; }
	else
	{
		
	}
}


