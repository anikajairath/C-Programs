#include<stdio.h>
#include<stdbool.h>

int main() {

    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int key = 0;

    int left = 0;
    int right = 9;

    bool isAvailable = false;

    printf("ENTER THE NUMBER TO SEARCH IN ARRAY: ");
    scanf("%d", &key);

   while(left <= right)
    {
       int mid = (left + right) / 2; //At the mid of the array

       if(arr[mid] == key)
       {
           printf("\nElement found at location %d \n", (mid+1));
           isAvailable = true;
           break;
       }

       else if(arr[mid] < key){ //Move to right half in case of '<'
        left = mid + 1;
        }

       else{
        right = mid - 1;} //Move to left half in case of '>'
    }

if(isAvailable == false){

    printf("\nElement not found in array\n");
}
}
