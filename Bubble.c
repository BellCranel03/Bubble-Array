#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Increment swaps count for the swapped elements
                swaps[arr[j+1]]++;
                swaps[arr[j]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap arr[i] and arr[min_index]
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        // Increment swaps count for the swapped elements
        swaps[arr[i]]++;
        swaps[arr[min_index]]++;
    }
}

void printOutput(int arr[], int n, int swaps[], char *sortType) {
    printf("array %s:\n", sortType);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
    int total_swaps = 0;
    for (int i = 1; i <= 100; i++) {
        total_swaps += swaps[i];
    }
    printf("%d\n\n", total_swaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[101] = {0}; // Assuming values range from 1 to 100
    int swaps2[101] = {0};

    // Perform Bubble Sort and count swaps for array1
    bubbleSort(array1, n1, swaps1);
    printOutput(array1, n1, swaps1, "bubble sort");

    // Perform Bubble Sort and count swaps for array2
    bubbleSort(array2, n2, swaps2);
    printOutput(array2, n2, swaps2, "bubble sort");

    // Reset swaps arrays
    for (int i = 1; i <= 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    // Perform Selection Sort and count swaps for array1
    selectionSort(array1, n1, swaps1);
    printOutput(array1, n1, swaps1, "selection sort");

    // Perform Selection Sort and count swaps for array2
    selectionSort(array2, n2, swaps2);
    printOutput(array2, n2, swaps2, "selection sort");

    return 0;
}



