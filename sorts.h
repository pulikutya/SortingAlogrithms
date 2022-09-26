#pragma once
typedef int num;
/// <summary>
/// min to max sort
/// </summary>
/// <param name="arr">pointer to array</param>
/// <param name="size">length of array</param>
void selection_sort(num* arr, size_t size);
void bubble_sort(num* arr, size_t size);
void optimized_bubble_sort(num* arr, size_t size);
void quick_sort(num* arr, size_t size);
void insertion_sort(num* arr, size_t size);
void merge_sort(num* arr, size_t size);