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
	const size_t len = 10;
	printIntArray(arr, len);
	std::cout << "----\n";
	quick_sort(arr, len);
	printIntArray(arr, len);
	return 0;
}