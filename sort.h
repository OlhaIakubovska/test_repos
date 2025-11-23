#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <stddef.h>
#include <string.h>
void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;

}
size_t partition(char** arr, size_t low, size_t high)
{
    char* pivot = arr[high];
    size_t i = low;

    for (size_t j = low; j < high; j++)
    {
        if (strcmp(arr[j], pivot) < 0)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}
void quick_sort_recursive(char** arr, size_t low, size_t high)
{
    if (low < high)
    {
        size_t pi = partition(arr, low, high);
        if (pi > 0)
            quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(char** arr, size_t size)
{
    if (arr == NULL || size == 0)
        return;
    quick_sort_recursive(arr, 0, size - 1);
}
#endif // !SORT
