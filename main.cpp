#include<iostream>
#include"sorts.h"
void printIntArray(int* arr, size_t length)
{
	int* end = arr + length;
	for (; arr < end; arr++)
	{
		std::cout << *arr << '\n';
	}
}
int main()
{
	int arr[10] = { 1, 5, 8, 3, 0, 9, 4, 6, 5, 2 };
	printIntArray(arr, 10);
	std::cout << "----\n";
	optimized_bubble_sort(arr, 10);
	printIntArray(arr, 10);
	return 0;
}