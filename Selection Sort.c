#include <stdio.h>

void main(){

int i, j, len;

printf("\t\t\t\t\tSELECTION SORT PROGRAM");
printf("\nENTER LENGTH OF ARRAY:\n");
scanf("%d", &len);

int arr[len];

printf("\nENTER ELEMENTS:-\n");

for(i = 0; i<len; i++){
    scanf("%d", &arr[i]);
}

for(i = 0; i<(len-1); i++){ //NO OF PASSES. PASSES WILL BE n-1 AND WE WILL START FROM 0 SO i<n-1

    int x = i;
    int temp = arr[i];//WILL STORE THE VALUE OF MINIMUM NO. INITIALLY STORING ORIG VAL OF arr[i]

    for(j = (i+1); j<len; j++){//TRAVERSING THE REST OF THE ARRAY

        if(arr[j]<arr[x]){

            x = j; //x WILL NOW POINT TO THE MINIMUM VALUE OF THE TWO

        }
    }

    if(x != i){ //IF A MINIMUM VALUE HAS BEEN FOUND WITH RESPECT TO arr[i] THEN SWAP THEM

        arr[i] = arr[x];
        arr[x] = temp;
    }

}

printf("\nPRINTING SORTED ARRAY...\n\n");

for(i = 0; i<len; i++){

    printf("\t%d", arr[i]);
}

printf("\n\n");
}

/* Let's sort the array [64, 25, 12, 22, 11] using Selection Sort.

Initial Array: [64, 25, 12, 22, 11]

Pass 1:

Find the minimum element in the entire array [64, 25, 12, 22, 11]. The minimum is 11.

Swap 11 with the first element (64).

Array after Pass 1: [11, 25, 12, 22, 64]

Pass 2:

Find the minimum element in the subarray [25, 12, 22, 64]. The minimum is 12.

Swap 12 with the first element of this subarray (25).

Array after Pass 2: [11, 12, 25, 22, 64]

Pass 3:

Find the minimum element in the subarray [25, 22, 64]. The minimum is 22.

Swap 22 with the first element of this subarray (25).

Array after Pass 3: [11, 12, 22, 25, 64]

Pass 4:

Find the minimum element in the subarray [25, 64]. The minimum is 25.

Since 25 is already in place, no swap is needed.

Array after Pass 4: [11, 12, 22, 25, 64]

Pass 5:

The remaining element [64] is already sorted.

Array remains: [11, 12, 22, 25, 64]

Final Sorted Array
The final sorted array is [11, 12, 22, 25, 64]*/
