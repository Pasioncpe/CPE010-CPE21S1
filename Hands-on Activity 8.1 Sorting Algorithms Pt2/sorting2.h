#ifndef HOA_8_SORTING2_H
#define HOA_8_SORTING2_H
#include <iostream>

template <typename T>
void shellSort(T arr[], int size) {
    /*
    shellSort(array, size)
        for interval i <- size/2n down to 1
            for each interval "i" in array
                sort all the elements at interval "i"
    end shellSort
    */

    for (int gap = size/2 ; gap >= 1; gap = gap/2) {
        for (int k = gap ; k < size; k++ ) {
            T temp = arr[k];
            int pos = k;
            while (pos >= gap && arr[pos - gap] > temp) {
                arr[pos] = arr[pos - gap];
                pos = pos - gap;
            }
            arr[pos] = temp;
        }
    }
}


template <typename T>
void merge(T arr[], int left, int middle, int right) {
    T temp[right - left + 1];

    int i = left;
    int j = middle + 1;
    int temp_pos = 0;

    while (i <= middle && j <= right) {
        if (arr[i] < arr[j]) {
            temp[temp_pos] = arr[i];
            i++;
            temp_pos++;
        } else {
            temp[temp_pos] = arr[j];
            j++;
            temp_pos++;
        }
    }
    while (i <= middle) {
        temp[temp_pos] = arr[i];
        i++;
        temp_pos++;
    }
    while (j <= right) {
        temp[temp_pos] = arr[j];
        j++;
        temp_pos++;
    }
    int k = 0;
    for (int i = left; i <= right; i++) {
        arr[i] = temp[k];
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right) {

    /*
    If N=1, Arr is already sorted
    If N>1,
    Left = 0, right = N-1
    Find middle = (left + right)/2
    Call merge_sort(Arr,left,middle) =>sort first half recursively
    Call merge_sort(Arr,middle+1,right) => sort second half recursively
    Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.
    Exit
    */

    if (left >= right) {
        return;
    }
    int middle = (left + right) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot_value = arr[high];
    int boundary = low - 1;

    for (int i = low; i <= high-1; i++) {
        if (arr[i] < pivot_value) {
            boundary++;
            std::swap(arr[i], arr[boundary]);
        }
    }
    std::swap(arr[high], arr[boundary+1]);
    return boundary+1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    /*
        if(low < high)
        pivot = partition (A,low,high);
        quicksort(A,low,pivot-1)
        quicksort(A,pivot+1,high)
    */

    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif //HOA_8_SORTING2_H
