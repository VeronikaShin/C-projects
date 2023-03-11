#include <stdio.h>
#define NMAX 10
int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int data[NMAX], n;
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char c;
    if (scanf("%d%c", n, &c) == 2 && c == '\n' && *n<=NMAX && * n> 0) {
        for (int *p = a; p - a < *n; p++) {
            int s = scanf("%d%c", p, &c);
            if ((s != 2) && (p - a != *n - 1)) {
                return 0;
            }
        }

        if (c != '\n') {
            return 0;
        }
        return 1;
    } else {
        return 0;
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++)
        if (p == a)
            printf("%d", *p);
        else
            printf(" %d", *p);
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = *p * *p;
    }
}