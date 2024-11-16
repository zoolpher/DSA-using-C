
#include <stdio.h>

void printArr(int*, int);
void mergeSort(int*, int);


int main() {
    int arr[5] = {12,4,67,2,1};
    int size = sizeof(arr)/sizeof(int);
    printArr(arr, size);
    mergeSort(arr, size);
    printArr(arr, size);
    return 0;
    return 0;
}

void printArr(int* _arr, int _size) {
    for (int i = 0; i < _size; i++) {
        printf("%d ", _arr[i]);
    }
    printf("\n");
}
void mergeSort(int* _arr, int _size) {
    int temp;
    for (int i = 1; i <= _size - 1; i++) {
        int key = _arr[i];
        int j = i - 1;
        while (key < _arr[j] && j >= 0 ) {
            _arr[j + 1] = _arr[j];
            j--;
        }
        _arr[j + 1] = key;
    }
}