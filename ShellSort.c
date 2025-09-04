#include <stdio.h>

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a big gap, then reduce the gap
    for(gap = n / 2; gap > 0; gap = gap/2) {
        // Perform a gapped insertion sort
        for(i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while(j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}

/* [64, 25, 12, 22, 11].

Original Array:
[64, 25, 12, 22, 11]

Detailed Steps of Shell Sort
Initial Gap:
Gap = 5 / 2 = 2
Iteration with Gap 2:

Index 2:
temp = 12
Compare with element at index 2 - 2 = 0 (64). Since 64 > 12, shift 64 to index 2.
Array becomes: [64, 25, 64, 22, 11]
Insert 12 at index 0.
Array becomes: [12, 25, 64, 22, 11]

Index 3:
temp = 22
Compare with element at index 3 - 2 = 1 (25). Since 25 > 22, shift 25 to index 3.
Array becomes: [12, 25, 64, 25, 11]
Insert 22 at index 1.
Array becomes: [12, 22, 64, 25, 11]

Index 4:
temp = 11
Compare with element at index 4 - 2 = 2 (64). Since 64 > 11, shift 64 to index 4.
Array becomes: [12, 22, 64, 25, 64]
Compare with element at index 2 - 2 = 0 (12). Since 12 > 11, shift 12 to index 2.
Array becomes: [12, 22, 12, 25, 64]
Insert 11 at index 0.
Array becomes: [11, 22, 12, 25, 64]

Reduce Gap:
Gap = 2 / 2 = 1
Iteration with Gap 1:
Index 1:
temp = 22
Compare with element at index 1 - 1 = 0 (11). No shift needed.
Array remains: [11, 22, 12, 25, 64]

Index 2:
temp = 12
Compare with element at index 2 - 1 = 1 (22). Since 22 > 12, shift 22 to index 2.
Array becomes: [11, 22, 22, 25, 64]
Insert 12 at index 1.
Array becomes: [11, 12, 22, 25, 64]

Index 3:
temp = 25
Compare with element at index 3 - 1 = 2 (22). No shift needed.
Array remains: [11, 12, 22, 25, 64]

Index 4:
temp = 64
Compare with element at index 4 - 1 = 3 (25). No shift needed.
Array remains: [11, 12, 22, 25, 64]
Final Sorted Array:
[11, 12, 22, 25, 64]*/
