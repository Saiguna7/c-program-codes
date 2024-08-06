#include <stdio.h>
#include <stdlib.h>

void bitonic_sort(int *arr, int n, int up) {
    if (n > 1) {
        int m = n / 2;
        bitonic_sort(arr, m, 1);
        bitonic_sort(arr + m, n - m, 0);
        bitonic_merge(arr, n, up);
    }
}

void bitonic_merge(int *arr, int n, int up) {
    if (n > 1) {
        int m = n / 2;
        for (int i = 0; i < m; i++) {
            compare_and_swap(arr + i, arr + i + m, up);
        }
        bitonic_merge(arr, m, up);
        bitonic_merge(arr + m, n - m, up);
    }
}

void compare_and_swap(int *a, int *b, int up) {
    if ((up && (*a > *b)) || (!up && (*a < *b))) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main() {
    int arr[] = { 2,  4,  6,  8,  9,  10,  12,  24,  22,  20,  18,  16,  14,  13,  11,  3  };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bitonic_sort(arr, n, 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}