#ifndef SUP_ACT_7_SORTING_H
#define SUP_ACT_7_SORTING_H
template <typename T>
void insertionSort(T arr[], int size) {
    int k = 1, j;
    T temp;

    while (k < size) {
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp <= arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}
#endif //SUP_ACT_7_SORTING_H
