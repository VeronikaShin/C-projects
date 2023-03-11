#include <stdio.h>

//отрисовка игрового поля + ракеток
void pole_display(int width_pole, int height_menu, int height_pole, int pos_r_1, int pos_r_2, int sc_pl_1,
                  int sc_pl_2, int ball_x, int ball_y, int pos_x_1, int pos_x_2);
//функция движения ракеток
int raketka_move(int pos_r_1, int pos_r_2, char input_char, int height_pole);

int main() {
    int width_pole = 81;   //ширина поля считаем с 0
    int height_menu = 5;   //высота меню
    int height_pole = 26;  //высота поля

    int pos_r_1 = 13;  //стартовая позиция ракетки 1
    int pos_r_2 = 14;  //стартовая позиция ракетки 2

    int sc_pl_1 = 0, sc_pl_2 = 0;  //, max_score = 0;

    int ball_x = 46;  //начальная позиция мяча по х
    int ball_y = 18;  //начальная позиция мяча по у

    int vec_x = 1;  //вектор изменения движения для х
    int vec_y = 1;  //вектор изменения движения для у

    int move_res;  // переменная для результата функции перемещения ракетки

    int pos_x_1 = 3, pos_x_2 = 78;

    while ((sc_pl_1 <= 20) || (sc_pl_2 <= 20)) {
        //рисуем поле и все все все
        pole_display(width_pole, height_menu, height_pole, pos_r_1, pos_r_2, sc_pl_1, sc_pl_2, ball_x, ball_y,
                     pos_x_1, pos_x_2);

        char move = getchar();  //создаем переменную для вводимого символа

        //условие чтобы enter не считывался за дейтсвие
        if (move != '\n') {
            move_res = raketka_move(pos_r_1, pos_r_2, move,
                                    height_pole);  //записываем в переменную move_res новую позицию ракетки
            if ((move == 'a' || move == 'z') &&
                move_res != 0)  //проверка на ввод нужных нам букв. Переменная не может равняться 0, тк
                                //учитывается верхняя граница поля
            {
                pos_r_1 = move_res;
            }
            if ((move == 'm' || move == 'k') && move_res != 0) {
                pos_r_2 = move_res;
            }

            if (ball_x == 2) {  //если мячик проходит за ракетку по левому краю
                sc_pl_2 = sc_pl_2 + 1;  // прибавь очко
                pos_r_1 = 13;  //ракетка и мячик возвращаются на начальные позиции
                pos_r_2 = 14;
                ball_x = pos_x_1 + 2;  //мячик ставим перед ракеткой
                ball_y = 12;
                vec_x = 1;  //вектора обнуляются
                vec_y = 1;
            }

            if (ball_x == 79) {
                sc_pl_1 = sc_pl_1 + 1;  //тоже самое для правого края
                pos_r_1 = 13;
                pos_r_2 = 14;
                ball_x = pos_x_2 - 2;
                ball_y = 15;
                vec_x = -1;
                vec_y = -1;
            }

            if ((ball_x == pos_x_1 + 1) && ((ball_y == pos_r_1) || (ball_y == pos_r_1 - 1) ||
                                            (ball_y == pos_r_1 - 2))) {  //если мячик отбивается
                vec_x = vec_x * -1;
            }
            if ((ball_x == pos_x_2 - 1) &&
                ((ball_y == pos_r_2) || (ball_y == pos_r_2 - 1) || (ball_y == pos_r_2 - 2))) {
                vec_x = vec_x * -1;  //поменяй вектор
            }

            if (ball_y == height_pole - 1) {  //если ударилось об нижнее поле
                vec_y = -1;
            }
            if (ball_y == 2) {  //если ударилось об верхнее
                vec_y = 1;
            }

            ball_x = ball_x + vec_x;  // двигаем мячик на 1 по 2 направлениям
            ball_y = ball_y + vec_y;
        }
    }
    if ((sc_pl_1 == 21)) {
        printf("Победил игрок 1! \n Игра закончена");
    }

    else {
        printf("Победил игрок 2! /n Игра закончена");
    }
    return 0;
}

//функция прорисовки поля
void pole_display(int width_pole, int height_menu, int height_pole, int pos_r_1, int pos_r_2, int sc_pl_1,
                  int sc_pl_2, int ball_x, int ball_y, int pos_x_1, int pos_x_2) {
    int b = 0;  //ряд
    int y = 0;  //столбец

    while (b != height_menu + 1) {
        b = b + 1;
        for (int i = 0; width_pole >= i; i++) {
            if ((b == 1) || (b == height_menu)) {  //рисуем верхнюю и нижнюю черту поля счета
                printf("-");
            } else if (b == height_menu + 1) {  //рисуем пустое поле между полем счета и полем для понга{
                printf(" ");
            } else if ((b == 3) && (i == 20)) {  //если мы находимся на 3 ряду на 20 символе то )
                printf("\b\b\b\b\b\b\b\bИгрок 1: %d", sc_pl_1);  // Сюда добавляем значение счетчика 1.
            } else if ((b == 3) && (i == 62)) {  //если мы находимся на 3 ряду на 62 символе то
                printf("\b\b\b\b\b\b\b\bИгрок 2: %d", sc_pl_2);  // Сюда добавляем значение
                // счетчика 2.
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    while (y != height_pole) {
        y = y + 1;
        for (int i = 0; width_pole >= i; i++) {
            if ((y == 1) || (y == height_pole)) {
                printf("-");
            } else if (((i == 0) || (i == 40) || (i == 81)))

            {
                printf("|");  //
            }

            else if ((i == pos_x_1) && ((y == pos_r_1) || (y == pos_r_1 - 1) || (y == pos_r_1 + 1))) {
                printf("|");  //
            }

            else if ((i == pos_x_2) && ((y == pos_r_2) || (y == pos_r_2 - 1) || (y == pos_r_2 + 1))) {
                printf("|");  //
            } else if ((i == ball_x) && (y == ball_y)) {
                printf("*");
            }

            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

//функция движения ракетки. оперируем средней чертой в ракетке
int raketka_move(int pos_r_1, int pos_r_2, char input_char, int height_pole) {
    //вводим наши буквы и сохраняем в переменную.
    if ((input_char == 'a') && (pos_r_1 - 3) != 0) {  //учитываем верхние границы поля
        pos_r_1--;
        return pos_r_1;
    }

    if ((input_char == 'z') && (pos_r_1 + 2) != height_pole) {  //учитываем нижние границы
        pos_r_1++;
        return pos_r_1;
    }

    if ((input_char == 'k') && (pos_r_2 - 3) != 0) {
        pos_r_2--;
        return pos_r_2;
    }

    if ((input_char == 'm') && (pos_r_2 + 2) != height_pole) {
        pos_r_2++;
        return pos_r_2;
    }

    return 0;
}
