#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end) {
    while (beg != end) {
        printf(" %d", *beg++);
    }
    printf("\n");
}

int main(void) {
    printf("the size of array: ");

    int n;
    scanf("%d", &n);

    int *dynArray = (int *)malloc(n * sizeof(int));
    if (dynArray == NULL) {
        printf("Not enough memory");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &dynArray[i]);
    }

    printArray(dynArray, dynArray + n);

    free(dynArray);
}