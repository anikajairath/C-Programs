#include <stdio.h>

/* void heapify(int arr[], int sz, int i)

If node stored at p
then lft child = 2*p+1 & rght child = 2*p+2
To derive parent node = (p-1)/2

Last element at (sz-1). then parent of this node = (sz-2)/2 or (sz/2) - 1
So from this node onwards there are only leaf nodes

Non Leaf Nodes = 0 to (sz/2)-1
Leaf Nodes = sz/2 to sz-1
*/

void swap(int *a, int *b){//JUST A FUNC TO SWAP TO NOS

int temp = *a;
*a = *b;
*b = temp;

}

void heapify(int arr[], int sz, int i){
/*In this func, in a given heap tree, we are looking for the Max value present in it and swapping it with the root. We compare
the root with both of it's child nodes and swap it with the largest value present. We keep on heapifying a given subtree till*/

int larg = i;//Initialize larg as root whatever it may be
int lft = 2*i+1; //Left child of curr node
int rgt = 2*i+2; //Rgt child of curr node

//If lft child > root and within bounds of array boundary
if(lft < sz && arr[lft] > arr[larg]){
    larg = lft;
}

//If rgt child > root and within bounds of array boundary
if(rgt < sz && arr[rgt] > arr[larg]){
    larg = rgt;
}

//If largest not the root, swap them
if(larg != i){
    swap(&arr[i], &arr[larg]);

//As now this subtree has been changed. Now again compare values with the new children. Recursively heapify the affected subtree.
    heapify(arr, sz, larg);
}


}

void heapSort(int arr[], int sz){ //Create a Max heap and take then remove the root node and create max heap again and on...

//First run from last non leaf node to root node. Rearranging and sorting them into max heap
for(int i = (sz/2 - 1); i >= 0; i--){

    heapify(arr, sz, i); //Create a Max heap

}
for(int i = sz-1; i>0; i--){ //Remove the largest elment from the array by swapping it with elmnt at end of array

    //Move curr node to end
    swap(&arr[0], &arr[i]);

    //Call Max heapify on the reduced heap
    heapify(arr, i, 0);
}


}

int main(){

    int arr[9] = {5,2,8,4,1,9,3,7,6};
    int sz = 9;

    heapSort(arr, sz); // CALLING HEAPSORT

    printf("\nPRINTING THE SORTED ARRAY...\n\n");

    for(int i = 0; i < sz; i++){

        printf("\t%d", arr[i]);
    }
    printf("\n\n");

return 0;}

/*Example:

Initial Array (Max-Heap): [10, 5, 3, 4, 1]

Swap root (10) with last element (1):
Array: [1, 5, 3, 4, 10]
Heapify root:

Heapified: [5, 4, 3, 1, 10]
Repeat:
Swap root (5) with last element (1).
Array: [1, 4, 3, 5, 10]

Heapify root: [4, 1, 3, 5, 10]
Swap root (4) with last element (1).
Array: [1, 4, 3, 5, 10]

Heapify root: [4, 1, 3, 5, 10]
Swap root (4) with last element (1).
Array: [1, 3, 4, 5, 10]

Heapify root: [3, 1, 4, 5, 10]
Swap root (3) with last element (1).
Array: [1, 3, 4, 5, 10]

Final Sorted Array: [1, 3, 4, 5, 10]*/
