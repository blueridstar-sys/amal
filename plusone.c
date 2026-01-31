#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = malloc((digitsSize + 1) * sizeof(int));
    int carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    }

    *returnSize = digitsSize;
    return result + 1;  
}

int main() {
    int digitsSize;
    printf("Enter number of digits: ");
    scanf("%d", &digitsSize);

    int* digits = malloc(digitsSize * sizeof(int));
    printf("Enter the digits: ");
    for (int i = 0; i < digitsSize; i++) {
        scanf("%d", &digits[i]);
    }

    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

   

    return 0;
}

