#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int dynamic_1(int n, int m);
int dynamic_2(int n, int m);
int dynamic_3(int n, int m);

int main() {
    int m, h, w, data[NMAX][NMAX];
    // int scan = scanf("%d", &m);
    if (scanf("%d", &m) == 1 && m >= 1 && m <= 4) {
        if (scanf("%d %d", &h, &w) == 2) {
            if (m == 1) {
                int flag = 0;
                for (int i = 0; i < w; i++)
                    for (int j = 0; j < h; j++) {
                        if (scanf("%d", &data[i][j]) != 1) {
                            flag = 1;
                        }
                    }
                if (flag == 0) {
                    for (int i = 0; i < w; i++) {
                        for (int j = 0; j < h; j++) {
                            printf("%d", data[i][j]);
                            if (j < h - 1) printf(" ");
                        }
                        if (i < w - 1) printf("\n");
                    }
                } else {
                    printf("n/a");
                }
            }
            if (m == 2) {
                if (dynamic_1(h, w) == 1) {
                    printf("n/a");
                }
            }
            if (m == 3) {
                if (dynamic_2(h, w) == 1) {
                    printf("n/a");
                }
            }

            if (m == 4) {
                if (dynamic_3(h, w) == 1) {
                    printf("n/a");
                }
            }

            return 0;
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

int dynamic_1(int n, int m) {
    int flag = 0;
    int** pointer_array = malloc(n * sizeof(int*));
    for (int s = 0; s < n; s++) {
        pointer_array[s] = malloc(m * sizeof(int));
    }

    for (int s = 0; s < m; s++) {
        for (int e = 0; e < n; e++) {
            if (scanf("%d", &pointer_array[s][e]) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int s = 0; s < m; s++) {
            for (int e = 0; e < n; e++) {
                printf("%d", pointer_array[s][e]);
                if (e < n - 1) printf(" ");
            }
            if (s < m - 1) printf("\n");
        }
    }

    for (int s = 0; s < n; s++)

    {
        free(pointer_array[s]);
    }

    free(pointer_array);
    return flag;
}

int dynamic_2(int n, int m) {
    int flag = 0;
    int** pointer_array = malloc(n * sizeof(int*));
    int* value_array = malloc(n * m * sizeof(int));

    for (int s = 0; s < n; s++) {
        pointer_array[s] = value_array + m * s;
    }

    for (int s = 0; s < n; s++) {
        for (int e = 0; e < m; e++) {
            if (scanf("%d", &pointer_array[s][e]) != 1) {
                flag = 1;
            }
        }
    }
    if (flag != 1) {
        for (int s = 0; s < m; s++) {
            for (int e = 0; e < n; e++) {
                printf("%d", pointer_array[s][e]);
                if (e < n - 1) printf(" ");
            }
            if (s < m - 1) printf("\n");
        }
    }

    free(value_array);
    free(pointer_array);
    return flag;
}

int dynamic_3(int n, int m) {
    int flag = 0;
    int** single_array_matrix = malloc(n * m * sizeof(int) + n * sizeof(int*));
    int* ptr = (int*)(single_array_matrix + n);

    for (int s = 0; s < n; s++) {
        single_array_matrix[s] = ptr + m * s;
    }
    for (int s = 0; s < n; s++) {
        for (int e = 0; e < m; e++) {
            if (scanf("%d", &single_array_matrix[s][e]) != 1) {
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int s = 0; s < n; s++) {
            for (int e = 0; e < m; e++) {
                printf("%d", single_array_matrix[s][e]);
                if (e < m - 1) printf(" ");
            }
            if (s < n - 1) printf("\n");
        }
    }
    free(single_array_matrix);
    return flag;
}