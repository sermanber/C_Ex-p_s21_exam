#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------------------------------------------------------
Task 1 - Перевод в верхний регистр первого символа каждого слова

Написать программу, осуществляющую перевод в верхний регистр 
первого символа каждого слова, разделенного пробелами в строке.
Строка, заканчивающаяся символом новой строки \n, задается на 
стандартном потоке ввода stdin и состоит из букв латинского алфавита,
цифр и пробелов, которые разделяют слова между собой. Преобразованную
строку вывести на стандартный поток вывода stdout. В конце ответа не 
должно быть переноса на новую строку.

Пример:			
This is my time --> This Is My Time
area1234 --> Area1234
----------------------------------------------------------------------*/


int main() {
    char *str = NULL;
    size_t i = 0;
    char c;

    while (scanf("%c", &c) == 1 && c != '\n') {
        str = realloc(str, (i + 1) * sizeof(char));
        str[i] = c;
        i++;
    }

    if (str == NULL) {
        return 0;
    }

    str[i] = '\0';

    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }

    int j = 0;

    while (j < i) {
        if (str[j] == ' ' && str[j + 1] >= 'a' && str[j + 1] <= 'z') {
            str[j + 1] = str[j + 1] - 32;
        }
        j++;
    }

    printf("%s", str);
    free(str);
    return 0;
}

/* ---------------------------------------------------------------------
Task 2 - Каталог фильмов

Напишите программу, которая читает список фильмов, а затем выводит 
фильмы указанного режиссёра. Первая строка содержит целое число 
N (1 ≤ N ≤ 50) — количество фильмов. Затем следует N строк, каждая 
в формате: Название;Режиссёр;Год
Длина каждой строки не более 100 символов
Последняя строка содержит имя режиссёра для поиска
Выведите все фильмы указанного режиссёра в порядке их появления во 
входных данных. Каждый фильм в формате: Название (Год)
Если фильмов данного режиссёра нет, выведите строку: Not found
Вход:			
4
The Godfather;F. F. Coppola;1972
The Shawshank Redemption;F. Darabont;1994
The Godfather Part II;F. F. Coppola;1974
Pulp Fiction;Q. Tarantino;1994
F. F. Coppola
Выход:
The Godfather (1972)
The Godfather Part II (1974)
----------------------------------------------------------------------*/

// решение через scanf и strcpy

typedef struct {
    char name[100];
    char director[100];
    int year;
} Film;

void fill_film(Film *films, int n);
void get_director(char *str);
void print_res(Film *films, char *search, int n);

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    };
    getchar();

    Film films[n];
    fill_film(films, n);

    char search[100];
    get_director(search);
    
    print_res(films, search, n);
    
    return 0;
}

void fill_film(Film *films, int n) {
    for (int i = 0; i < n; i++) {
        char temp[100];
        char c;
        int j = 0;
        while (scanf("%c", &c) == 1 && c != '\n' && c != ';') {
            if (j < 99) temp[j++] = c;
        }
        temp[j] = '\0';
        strcpy(films[i].name, temp);

        memset(temp, 0, sizeof(temp));
        j = 0;
        while (scanf("%c", &c) == 1 && c != '\n' && c != ';') {
            if (j < 99) temp[j++] = c;
        }
        temp[j] = '\0';
        strcpy(films[i].director, temp);

        scanf("%d", &films[i].year);
        getchar();
    }
}

void get_director(char *str) {
    char c;
    int j = 0;
    while (scanf("%c", &c) == 1 && c != '\n') {
            str[j++] = c;
        }
    str[j] = '\0';
}

void print_res(Film *films, char *search, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(films[i].director, search) == 0) {
            printf("%s (%d)\n", films[i].name, films[i].year);
            found ++;
        }
    }
    if (found == 0) {
        printf("Not found");
    }
}

// решение через fgets и strtok

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    getchar();

    Film films[n];
    int flag = 0;

    for (int i = 0; i < n && flag == 0; i++) {
        char temp[1000];
        if (fgets(temp, sizeof(temp), stdin) == NULL) {
            flag = 1;
        };
        if (!flag) {
            char *token = strtok(temp, ";");
            if (token) strcpy(films[i].name, token);
            token = strtok(NULL, ";");
            if (token) strcpy(films[i].director, token);
            token = strtok(NULL, ";\n");
            if (token) films[i].year = atoi(token);
        }
    }

    char search[100];
    int found = 0;

    if (flag == 0 && fgets(search, sizeof(search), stdin) != NULL) {
        search[strlen(search) - 1] = '\0';
        for (int i = 0; i < n; i++) {
            if (strcmp(films[i].director, search) == 0) {
                printf("%s (%d)\n", films[i].name, films[i].year);
                found++;
            }
        }
    }
    else {
        flag = 1;
    }

    if (flag == 0 && found == 0) {
        printf("Not found");
    }
    
    return 0;
}