#include <stdio.h>

int main(){

int i, j, temp, len;

printf("\t\t\t\t\t\t\tBUBBLE SORT");

printf("\nENTER LENGTH OF ARRAY:\n");
scanf("%d", &len);

int arr[len];

printf("\nENTER ELEMENTS:-\n");

for(i = 0; i<len; i++){
    scanf("%d", &arr[i]);
}

printf("PRINTING UNSORTED ARRAY:\n");

for(i=0;i<len;i++){
    printf("\t%d", arr[i]);
}
printf("\n");

for(i=0;i<(len-1);i++){//BUBBLE SORT REQIURES LEN-1 PASSES

    for(j=0; j < (len-i-1); j++){//TOTAL LEN - PASSES - 1. ARRAY 4 SORTING WILL REDUCE EACH TIME

        if(arr[j]> arr[j+1]){ //IF PRV>NXT, SWAP THEM

        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        }
    }
}

printf("\n\nTHIS IS THE SORTED ARRAY:-\n\n");

for(i= 0; i< len; i++){

    printf("\t%d", arr[i]);
}
printf("\n\n");
}

/* Let's sort the array [5, 2, 9, 1, 5, 6] using Bubble Sort.

Initial Array: [5, 2, 9, 1, 5, 6]

Pass 1:

Compare 5 and 2: 5 > 2 → Swap.
Array: [2, 5, 9, 1, 5, 6]

Compare 5 and 9: 5 < 9 → No swap.
Array: [2, 5, 9, 1, 5, 6]

Compare 9 and 1: 9 > 1 → Swap.
Array: [2, 5, 1, 9, 5, 6]

Compare 9 and 5: 9 > 5 → Swap.
Array: [2, 5, 1, 5, 9, 6]

Compare 9 and 6: 9 > 6 → Swap.
Array: [2, 5, 1, 5, 6, 9]


Pass 2:

Compare 2 and 5: 2 < 5 → No swap.
Array: [2, 5, 1, 5, 6, 9]

Compare 5 and 1: 5 > 1 → Swap.
Array: [2, 1, 5, 5, 6, 9]

Compare 5 and 5: 5 = 5 → No swap.
Array: [2, 1, 5, 5, 6, 9]

Compare 5 and 6: 5 < 6 → No swap.
Array: [2, 1, 5, 5, 6, 9]


Pass 3:

Compare 2 and 1: 2 > 1 → Swap.
Array: [1, 2, 5, 5, 6, 9]

Compare 2 and 5: 2 < 5 → No swap.
Array: [1, 2, 5, 5, 6, 9]

Compare 5 and 5: 5 = 5 → No swap.
Array: [1, 2, 5, 5, 6, 9]


Pass 4:

Compare 1 and 2: 1 < 2 → No swap.
Array: [1, 2, 5, 5, 6, 9]

Compare 2 and 5: 2 < 5 → No swap.
Array: [1, 2, 5, 5, 6, 9]

Since no swaps were made in the last pass, the array is now sorted.

Final Sorted Array
The final sorted array is [1, 2, 5, 5, 6, 9]*/
