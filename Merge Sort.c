#include <stdio.h>

/*IN THIS CODE WE BASICALLY HAVE 3 FUNCS:-

1.MAIN() - JUST CALLS THE MERGESORT()
2.MERGESORT() - DIVIDES THE ARRAY TILL ONY ONE ELEMENT REMAINS
3.MERGE() - COMPARES AND MERGES ONE SUB ARRAY WITH ANOTHER. IT TAKES 4 PARAMETERS
*/

void mergeSort(int arr[], int left, int mid, int right);
void merge(int arr[], int left, int mid, int right);

void mergesort(int arr[], int left, int right){

    int mid; //Calculate the middle index

    //Only if left < right
    if(left < right){

    mid = (left+right)/2; //Find the mid point

    //Now Recursively sort the other two halves
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    // Now Merge the sorted halves
    merge(arr, left, mid, right);

    }

}

void merge(int arr[], int left, int mid, int right) {

/*IN THIS FUNC WE WILL DO:-
1. JUST CREATE 2 TEMPORARY ARRAYS TO STORE DATA FROM/TO MID
2. WE WILL THEN COMPARE THEM AND OVERWRITE THEM IN THE ORIG ARRAY*/

    int n1 = mid - left + 1; //Size of Left part
    int n2 = right - mid;//Size of Right part

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; //Data of left to mid

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; //Data of mid to right

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) { //If L<R, L copied to the array
            arr[k] = L[i];
            i++;
        }
        else { //If R<L, R copied to the array
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


int main(){

int arraySize = 10;
int arr[10] = {90,20,100,30,50,80,10,70,40,60};

mergesort(arr, 0, arraySize - 1); //Calling Mergesort();

printf("\nSorted array:\n");

for(int n = 0;n<10;n++){
    printf("\n%d", arr[n]);
}
printf("\n\n");

    return 0;
}
/* For the array [38, 27, 43, 3, 9, 82, 10]:

Divide the array into two halves:

Left: [38, 27, 43, 3]
Right: [9, 82, 10]
Recursively divide these halves:

For [38, 27, 43, 3]:

Divide into [38, 27] and [43, 3]
Further divide [38, 27] into [38] and [27]
Further divide [43, 3] into [43] and [3]
For [9, 82, 10]:

Divide into [9] and [82, 10]
Further divide [82, 10] into [82] and [10]
2. Merge
Algorithm:

Merge two sorted subarrays into a single sorted array.
Compare elements from the two subarrays and insert the smaller element into the new array.
Continue until all elements from both subarrays are merged.
Example:

Merge [38] and [27]:

Result: [27, 38]
Merge [43] and [3]:

Result: [3, 43]
Merge [27, 38] and [3, 43]:

Compare 27 and 3 → Insert 3.
Compare 27 and 43 → Insert 27.
Compare 38 and 43 → Insert 38.
Result: [3, 27, 38, 43]
Merge [82] and [10]:

Result: [10, 82]
Merge [9] and [10, 82]:

Compare 9 and 10 → Insert 9.
Result: [9, 10, 82]
Finally, merge [3, 27, 38, 43] and [9, 10, 82]:

Compare 3 and 9 → Insert 3.
Compare 27 and 9 → Insert 9.
Compare 27 and 10 → Insert 10.
Compare 27 and 82 → Insert 27.
Compare 38 and 82 → Insert 38.
Compare 43 and 82 → Insert 43.
Result: [3, 9, 10, 27, 38, 43, 82]*/
