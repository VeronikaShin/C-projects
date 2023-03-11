#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int data[NMAX], n;
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

int min(int *a, int n) {
    int min_v = a[0];
    for (int *p = a; p - a < n; p++) {
        if (min_v > *p) {
            min_v = *p;
        }
    }
    return min_v;
}

int max(int *a, int n) {
    int max_v = a[0];
    for (int *p = a; p - a < n; p++) {
        if (max_v < *p) {
            max_v = *p;
        }
    }
    return max_v;
}

double mean(int *a, int n) {
    double sum;
    sum = 0.0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    return sum/n;
}

double variance(int *a, int n) {
    double sum = 0.0;
    for (int *p = a; p - a < n; p++) {
        sum += (*p - mean(a, n)) * (*p - mean(a, n));
    }
    return sum/n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %0.6lf %0.6lf", min_v, max_v, mean_v, variance_v);
}
