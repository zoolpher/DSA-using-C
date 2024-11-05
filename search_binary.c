#include <stdio.h>

// works only for sorted array

int binary_search(int arr[], int size, int elem);

int main() {
    int arr[] = {12, 23, 34, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(int);
    int elem;
    printf("Enter the element u want to search: ");
    scanf("%d", &elem);
    int searched_pos = binary_search(arr, size, elem);
    if (searched_pos == -1) 
        printf("Element not present in the array.");
    else 
        printf("Element found at poistion %d", searched_pos + 1);
    return 0;
}

int binary_search(int arr[], int size, int elem) {
    int lo, mid, hi;
    lo = 0;
    hi = size - 1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] == elem)
            return mid;
        else if (arr[mid] < elem)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}