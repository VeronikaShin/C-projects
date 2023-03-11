#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
int compare(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
double sigm(int *a, int n);

/*   Search module for the desired value from data array.

   Returned value must be:
       - "even"
       - ">= mean"
       - "<= mean + 3 * sqrt(variance)"
       - "!= 0"

       OR

       0
*/
int main() {
    int data[NMAX], n;
    if (input(data, &n)) {
        printf("%d", compare(data, n));

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

double mean(int *a, int n) {
    double mean;
    mean = 0;
    for (int *p = a; p - a < n; p++) {
        mean += *p;
    }
    return mean / n;
}

double variance(int *a, int n) {
    double sum = 0.0;
    for (int *p = a; p - a < n; p++) {
        sum += (*p - mean(a, n)) * (*p - mean(a, n));
    }
    return sum / n;
}

double sigm(int *a, int n) { return (mean(a, n) + 3 * sqrt(variance(a, n))); }

int compare(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (((double)*p >= mean(a, n)) && (*p % 2 == 0) && ((double)*p != 0) && ((double)*p <= sigm(a, n))) {
            return *p;

            break;
        }
    }
    return 0;
}
