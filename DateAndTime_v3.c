#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numero_dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *nome_mes[] = {"Janeiro", "Fevereiro", "Março", "Abril", 
                    "Maio", "Junho", "Julho", "Agosto", "Setembro", 
                    "Outubro", "Novembro", "Dezembro"};

int main() {

    int i, ano, mes, dias_mes, d;

    // variável do tipo time_t para armazenar o tempo em t
    time_t t;

    // ponteiro para struct que guarda data e hora
    struct tm *atual;
    struct tm primeiro_dia;

    // pega tempo corrente e preenche na struct tm
    // t = time(NULL);
    time(&t);
    atual = localtime(&t);

    mes = 1;
    ano = atual->tm_year;

    // Bissexto
    if (ano % 4 == 0 && (ano % 400 || ano % 100 != 0)) {
        numero_dias[1] = 29;
    }

    dias_mes = numero_dias[mes];

    primeiro_dia.tm_mday = 1;
    primeiro_dia.tm_mon = mes;
    primeiro_dia.tm_year = ano;
    primeiro_dia.tm_hour = 12;
    primeiro_dia.tm_min = 0;
    primeiro_dia.tm_sec = 0;

    // Cria uma data pegando campos da struct tm
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