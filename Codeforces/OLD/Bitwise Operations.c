#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.

    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (((i&j) > maxAnd) && ((i&j) < k)) {
                maxAnd = i&j;
            }
            if (((i|j) > maxOr) && ((i|j) < k)) {
                maxOr = i|j;
            }
            if (((i^j) > maxXor) && ((i^j) < k)) {
                maxXor = i^j;
            }
        }
    }

    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}









/*
O(1) This may be correct for large values of n and k,
but it breaks down for some small values.
For example, if n = k = 2, AND and XOR are 0 and OR has no solution (1 | 2 = 3 > 2).
This algorithm gives {0, 0, 1}.

void calculate_the_maximum(int n, int k) {
    printf("%d\n",((k-1)|k)<=n? (k-1):(k-2));
    printf("%d\n",((k-1)&(k-2))==0? (k==3?0:(k-2)) : (k-1) );
    printf("%d\n", k-1);
}
*/
