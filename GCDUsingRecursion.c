#include <stdio.h>

int gcd(int n1, int n2) {

    if (n2 == 0){
            return n1; // base case
    }

    return gcd(n2, n1 % n2); // recursive step
}

int main(){
    int n1, n2;

printf("ENTER A NUMBER:\n");
scanf("%d", &n1);

printf("\nENTER ANOTHER NUMBER: (THIS SHOULD BE LESS THAN THE NUMBER ENTERED EARLIER)\n");
scanf("%d", &n2);

int res = gcd(n1, n2);

printf("\n\nTHIS IS THE GREATEST COMMON DIVISOR BY USING EUCLIDEAN ALGO: %d\n\n", res);

return 0;
}
