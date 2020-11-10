#include <time.h>
#include <conio.h>
#include <stdio.h>

// CABEÇALHO

int main() {

    // ponteiro para struct que guarda data e hora
    struct tm *atual;

    // variável do tipo time_t para armazenar o tempo em t
    time_t t;

    // obtendo o tempo em segundos
    t = time(NULL);

    // para converter de segundos para o tempo local utilizamos a função localtime
    atual = localtime(&t);

    // prints do tempo atual, data atual, dia da semana e do ano atuais
    printf("\n============================================================");
    printf("\nTEMPO ATUAL --> %d:%d:%d", atual->tm_hour, atual->tm_min, atual->tm_sec);
    printf("\nDATA  ATUAL --> %d/%d/%d", atual->tm_mday, atual->tm_mon + 1, atual->tm_year + 1900);
    printf("\n============================================================");
    printf("\nEstamos no %d dia da semana, completando %d dias no ano", atual->tm_wday + 1,atual->tm_yday);
    printf("\n============================================================\n");

    return 0;
}