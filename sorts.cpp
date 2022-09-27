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
	num* end = arr + len -1 ;
	num* b_start = arr + 1;
	bool n_sorted = true;
	while (n_sorted)
	{
		n_sorted = false;
		
		num* b = b_start;
		while (b < end)
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
		num* i = arr;
		num* j = i + len-1;
		bool ci = false;

		while (i != j)
		{
			if (*j < *i)
			{
				Swap(num, *i, *j);
				ci = !ci;
			}

			if (ci) { i++; }
			else { j--; }
		}

		size_t len1 = i - arr;
		num* arr2 = i + 1; //can be unsafe
		size_t len2 = arr + len - arr2;

		if (len1 > 0)
		{
			quick_sort(arr, len1);
		}
		if (len2 > 0)
		{
			quick_sort(arr2, len2);
		}
	}
	else { return; }
}

void insertion_sort(num* arr, size_t len)
{
	num* end = arr + len;
	for (num* i = arr; i < end; i++)
	{
		for (num* j = i; j > arr; j--)
		{
			if (j[-1] > j[0])
			{
				Swap(num, j[0], j[-1]);
			}
			else { break; };
		}
	}
}

void merge_sort(num* arr, size_t len)
{
	if (len > 1)
	{
		size_t len2 = len / 2, len1 = len - len2;
		num* arr2 = arr + len1;
		
		merge_sort(arr, len1);
		merge_sort(arr2, len2);

		if(len > 2)
		{	
			num* marr = new num[len], * marrend = marr + len;
			num* i = arr, * j = arr2;
			num* end1 = i + len1, * end2 = j + len2;
			for (num* x = marr; x < marrend; x++)
			{
				bool e1 = i < end1, e2 = j < end2;
				if (e1 && e2)
				{
					if (*i < *j) {
						*x = *i; 
						i++;
					}
					else
					{
						*x = *j; 
						j++;
					}
				}
				else if (!e1 && e2)
				{
					*x = *j; 
					j++;
				}
				else if (!e2 && e1)
				{
					*x = *i; 
					i++;
				}
			}

			for (num* c = marr; c < marrend; c++, arr++)
			{
				*arr = *c;
			}

			delete[len] marr;	
		}
		else
		{
			if (arr[0] > arr[1])
			{
				Swap(num, arr[0], arr[1]);
			}
		}
	}
	else { return; }
}
