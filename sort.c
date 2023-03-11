#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int *n);
void output(int *arr, int n);
void bubble_sort(int *arr, int n);

int main() {
    int n;
    char c;
    if ((scanf("%d%c", &n, &c) == 2) || (c == '\n')) {
        int *arr;
        arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("n/a");
        }
        if (input(arr, &n) == 0) {
            bubble_sort(arr, n);
            output(arr, n);
            free(arr);
        } else {
            printf("n/a");
        }
    }
    return 0;
}

int input(int *arr, int *n) {
    int flag = 0;
    for (int *p = arr; p - arr < *n; p++) {
        int s = scanf("%d", p);
        if (s != 1) {
            flag = 1;
        }
    }
    if (getchar() != '\n') {
        flag = 1;
    }

    return flag;
}

void output(int *arr, int n) {
    for (int *p = arr; p - arr < n; p++)
        if (p == arr)
            printf("%d", *p);
        else
            printf(" %d", *p);
}

//по возрастанию
void bubble_sort(int *arr, int n) {
    int *p = arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(p + j) > *(p + j + 1)) {
                int tmp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = tmp;
            }
        }
    }
}
