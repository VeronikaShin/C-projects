#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define h 25
#define w 80
#define dead ' '
#define life '¤'

void draw(int matrix[h][w]);                         //рисует матрицу
void second_draw(int matrix[h][w], int next[h][w]);  //рисуем новое поколение
int cnt_neighbors(int matrix[h][w], int x, int y);   //считаем соседей
int final_stage(int matrix[h][w]);  //учитываем есть ли живые клетки
int is_equal_matrix(int matrix[h][w], int next[h][w]);  //сравниваем две матрицы
void copy_matrix(int matrix[h][w],
                 int next[h][w]);  //копируем 2 матрицу в 1, и 2 обнуляем

int main() {
    int M[h][w];
    int speed;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)

            scanf("%d", &(M[i][j]));
    }

    printf("Выберите скорость от 1: ");
    if (freopen("/dev/tty", "r", stdin) != NULL) {
        int next[h][w];
        int step = 0;
        scanf("%d", &speed);

        printf("Поколение №%d\n", step);
        draw(M);
        while (1) {
            step++;
            if (final_stage(M) == 0) break;
            usleep(1000000 / speed);
            printf("\e[H\e[2J\e[3J");
            printf("Поколение №%d\n", step);
            second_draw(M, next);
            if (is_equal_matrix(M, next) == 1) break;
            copy_matrix(M, next);
        }
    }
    return 0;
}

void draw(int matrix[h][w]) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] == 1)
                printf("¤");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void second_draw(int matrix[h][w],
                 int next[h][w]) {  //нужно создать вторую матрицу и передать в
                                    //нее новые клетки
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int state = matrix[i][j];  //создаем временную переменную в которую кладем
                                       //значения из ячейки
            int neighbors = cnt_neighbors(matrix, i, j);  //функция подсчета соседей
            if (state == 0 && neighbors == 3)             
                next[i][j] = 1;
            else if (state == 1 && (neighbors < 2 || neighbors > 3))
                next[i][j] = 0;

            else
                next[i][j] = state;
        }
    }
    draw(next);
}

//подсчитываю количество соседей
int cnt_neighbors(int matrix[h][w], int x, int y) {
    int sum = 0;
    //проверяем по 3 ячейки
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            // обработка крайних ситуаций (поле замкнуто само на себе)
            int x2 = (x + i + h) % h;
            int y2 = (y + j + w) % w;
            sum += matrix[x2][y2];
        }
    }
    sum -= matrix[x][y];  //удаляем саму нашу клетку из подсчета ее соседей
    return sum;
}

int final_stage(int matrix[h][w]) {  //если сумма всех клеток 0, то все мертвы
    int sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int is_equal_matrix(int matrix[h][w],
                    int next[h][w])  //если 2 матрицы равны то флаг 1
{
    int equal_flag = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] != next[i][j]) {
                equal_flag = 0;
                break;
            }
        }
    }
    return equal_flag;
}

void copy_matrix(int matrix[h][w], int next[h][w]) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            matrix[i][j] = next[i][j];
            next[i][j] = 0;
        }
    }
}
