//
// Created by rhiza on 9/9/2026.
//

#ifndef SUP_ACT_7_SEARCHING_H
#define SUP_ACT_7_SEARCHING_H

template <typename T>
int linearSearchArr(T data[], int arrSize, T datafind) {
    int i = 0;
    int counter = 0;
    while (i < arrSize) {
        if (data[i] == datafind) {
            counter++;
        }
        i++;
    }
    return counter;
}

template <typename T>
int findHighest(T data[], int arrSize) {
    int highest = data[0];
    int highestIndex = 0;

    for (int i = 1; i < arrSize; i++) {
        if (data[i] > highest) {
            highest = data[i];
            highestIndex = i;
        }
    }
    return highestIndex;
}

#endif //SUP_ACT_7_SEARCHING_H
