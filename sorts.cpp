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



void quick_sort(num* arr, size_t len)
{
	if (len > 1)
	{
		//partition
		


		num* iter1 = arr;
		num* iter2 = arr + len - 1;
		bool cri1 = false; //if true iter 1 moves if false iter2

		while (iter1 != iter2)
		{
			if (*iter1 > *iter2)
			{
				Swap(num, *iter1, *iter2);
				cri1 = !cri1;
			}

			if (cri1)
			{
				iter1++;
			}
			else
			{
				iter2--;
			}

			
			
		}
		quick_sort(arr, iter1 - arr);
		quick_sort(iter1, (arr + len) - iter1);
	}
	else
	{
		return;
	}
	
}

