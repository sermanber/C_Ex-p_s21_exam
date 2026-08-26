#include <fcgi_stdio.h>
#include <stdlib.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html; charset=utf-8\r\n");
        printf("Status: 200 OK\r\n\r\n");
    

        FILE *html_file = fopen("index.html", "r");

        if (html_file == NULL) {
            printf("<h1>Ошибка: Файл index.html не найден!</h1>");
        continue;
        }

        char c;
        while ((c = fgetc(html_file)) != EOF) {
            putchar(c);
        }

        fclose(html_file);
    }
    return 0;
}