#include <stdio.h>

void main(){

int key, i, j;
int len;

printf("\t\t\t\t\t\tINSERTION SORT");

printf("\nENTER LENGTH OF ARRAY:\n");
scanf("%d", &len);

int arr[len];

printf("\nENTER ELEMENTS:-\n");

for(i = 0; i<len; i++){
    scanf("%d", &arr[i]);
}


for(i = 1; i<len; i++){ /*TO KEEP TRACK OF PASSES. PASSES ARE ALWAYS n-1 FOR AN ARRAY OF SIZE n.AND AS WE ARE TO START FRM THE
    SEC ELMNT SO i MUST BE 1*/

    key = arr[i]; //STORE VALUE OF NXT ELEMENT
    j = i-1; //PRVS ELMNT


    while(arr[j] > key && j >= 0){// TILL (PRVS > NXT) AND j SHOULD BE GREATER OR EQUAL TO ZERO

        arr[j+1] = arr[j]; //MOVE ELMNT TO RIGHT FROM IT'S CURRENT POSITION
        j--; //MOVE TO PRVS POSITION
    }

    arr[j+1] = key; //INSERT KEY INTO CORRECT POSITION
}

printf("\n\nPRINTING SORTED ARRAY....\n\n");

for(i = 0; i<len; i++){

    printf("\t%d", arr[i]);
}
printf("\n\n");

}
/* Let's sort the array [5, 2, 9, 1, 5, 6] using Insertion Sort.

Initial Array: [5, 2, 9, 1, 5, 6]

Start with the second element (2).

Current Element: 2
Compare with 5 (first element).
Since 2 < 5, shift 5 to the right and insert 2 in the first position.
Array after first insertion: [2, 5, 9, 1, 5, 6]

Move to the third element (9).

Current Element: 9
Compare with 5 (the last element in the sorted part). Since 9 > 5, no shifting is needed.
9 is already in its correct position.
Array remains: [2, 5, 9, 1, 5, 6]

Move to the fourth element (1).

Current Element: 1
Compare with 9. Since 1 < 9, shift 9 to the right.
Compare with 5. Since 1 < 5, shift 5 to the right.
Compare with 2. Since 1 < 2, shift 2 to the right.
Insert 1 in the first position.
Array after insertion: [1, 2, 5, 9, 5, 6]

Move to the fifth element (5).

Current Element: 5
Compare with 9. Since 5 < 9, shift 9 to the right.
Compare with 5. Since 5 = 5, no shifting is needed. Insert 5 in the correct position.
Array after insertion: [1, 2, 5, 5, 9, 6]

Move to the sixth element (6).

Current Element: 6
Compare with 9. Since 6 < 9, shift 9 to the right.
Insert 6 in the correct position.
Array after insertion: [1, 2, 5, 5, 6, 9]

Final Sorted Array
The final sorted array is [1, 2, 5, 5, 6, 9]*/
