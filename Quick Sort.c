#include <stdio.h>
#define len 8
/*
We have 4 parts here:

First is main() - Just calls Quicksort() & prints final array.

Second is Quicksort() - Partitions the array for the pivot. Then does it for array less then pivot then for array greater than
pivot

Third is Partition() - Compares all elements with the pivot. Only if any element smaller or equal to pivot, Swap() to least
position at the moment. A variable i keeps track of the least position at the moment

Fourth is Swap() - Just swaps any 2 nos
*/

void swap(int *a, int *b){//Nothing spl. Just swapping any two elements passed

int temp = *a;
*a = *b;
*b = temp;
}

int partition(int array[], int low, int high){

int pivot = array[high]; //Choosing the highest element as Pivot
int i = (low - 1); //Keep track of the least position at the moment. -1 in the first round

//Now traverse and compare all elements with Pivot

for(int j = low; j < high; j++){

    if(array[j] <= pivot){
    //If any element is less than or equal to pivot. Do:-
    i++;//Increment tracker
    swap(&array[i], &array[j]); //Swap it with the least position
    }
}

//Now the smallest elements have been moved to the least positions. Now we will place the pivot after them.
//The lastmost smallest element is at position[i]. So will place pivot at position[i+1].

    swap(&array[i+1], &array[high]);
    return (i+1); //Give the position of pivot
}

void quicksort(int array[], int low, int high){
//Got array, array beg position and array end position(array length)

if(low < high){//Base case. If low !< high = Sub-array has 0 or 1 element & therefore is already sorted

    int pi = partition(array, low, high);//Calling Partition() now. Gets the position of Pivot in return. pi = existing pivot.
    quicksort(array, low, pi-1); //Sort elements before Pivot. The new high will be the pos bfr pivot.
    quicksort(array, pi+1, high); //Sort elements after Pivot. The new low will be pos aft pivot.
}
}

int main(){ //We have just declared an array here and called Quicksort()

int arr[len] = {1, 4, 6, 3, 8, 5, 2, 7};

quicksort(arr, 0, len-1); //Passing array, array beg position and array end position(array length)

printf("\nPRINTING SORTED ARRAY....\n");

for(int i = 0; i<len; i++){

    printf("\t%d", arr[i]);
}

printf("\n\n");
return 0;

}

/*1, 4, 6, 3, 8, 5, 2, 7
7 is pivot

1st partition: 1,4,6,3,5,2,"7",8
Now lft array: 1,4,6,3,5,2,(7, 8)

2 is pivot

2nd partition: 1,"2",4,6,3,5
Lft case fail
Rght array : (1, 2,) 4,6,3,5, (7, 8)

5 is pivot

3rd partition: 4,3,"5",6
Lft array: (1,2,) 4,"3" (5,6,7,8)

3 is pivot. if will not run. so swap low and high. New array : 3, 4

Rgh array case fail as already in order 5, 6

Final array : 1,2,3,4,5,6,7,8*/



