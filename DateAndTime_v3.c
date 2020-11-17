#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

int main() {

    int i, ano, mes, dias_mes, d;
    int numero_dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *nome_mes[] = {"Janeiro", "Fevereiro", "Março", "Abril", 
                        "Maio", "Junho", "Julho", "Agosto", "Setembro", 
                        "Outubro", "Novembro", "Dezembro"};

    // variável do tipo time_t para armazenar o tempo em t
    time_t t;

    // ponteiro para struct que guarda data e hora
    struct tm *atual;
    struct tm primeiro_dia;

    // pega tempo corrente e preenche na struct tm
    t = time(NULL);
    // time(&atual);
    atual = localtime(&t);

    mes = atual->tm_mon;
    ano = atual->tm_year;

    // Bissexto
    if (ano % 4 == 0 && (ano % 400 || ano % 100 != 0)) {
        numero_dias[1] = 29;
    }

    dias_mes = numero_dias[mes];

    primeiro_dia.tm_mday = 1;
    primeiro_dia.tm_mon = mes;
    primeiro_dia.tm_year = ano;

    mktime(&primeiro_dia);

    printf("\n%s - %d\n", nome_mes[mes], ano + 1900);

    printf("DOM SEG TER QUA QUI SEX SAB\n");

    for (i = 0; i<primeiro_dia.tm_wday; i++) {
        printf("    ");
    }

    for (d = 1; d <= dias_mes; d++) {
        printf("%3d ", d);
        i++;
        if (i % 7 == 0) {
            printf("\n");
        }
    }

    return 0;
}