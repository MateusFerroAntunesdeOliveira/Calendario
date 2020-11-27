// NOME DOS INTEGRANTES: CARLOS EDUARDO MARQUES ASSUNÇÃO TORRES
//                       MATEUS FERRO ANTUNES DE OLIVEIRA
//                       RICARDO GODOI KURASHIKI

// LINK DO VIDEO: https://www.youtube.com/watch?v=5TPiydsewxM&feature=youtu.be

// TMJ PROFESSOR ;D

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CABEÇALHO
void primeiro();
void segundo(int mes_esc);
void terceiro(int ano_sel);

int numero_dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *nome_mes[] = {"Janeiro", "Fevereiro", "Marco", "Abril",
                    "Maio", "Junho", "Julho", "Agosto", "Setembro",
                    "Outubro", "Novembro", "Dezembro"};

int main() {
    int resposta, ano_escolhido, mes_escolhido;

    inicio:
    system("cls");
    printf("================================================\n");
    printf("                Escolha uma opcao               \n");
    printf("                                                \n");
    printf(" (1) Calendario do mes corrente                 \n");
    printf(" (2) Escolha um mes do ano corrente             \n");
    printf(" (3) Escolhe um ano (mostra os 12 meses do ano) \n");
    printf(" (0) Sair do programa                           \n");
    printf("                                                \n");
    printf("================================================\n");
    printf(">> ");
    scanf("%d", &resposta);

    switch (resposta) {
    case 0:
        system("cls");
        printf("Encerrando o programa, aguarde...\n\n");
        return 0;
        break;
    case 1:
        system("cls");
        primeiro();
        printf("\n\n");
        system("pause");
        break;
    case 2:
        system("cls");
        printf("--- Escolha um mes ---\n");
        printf(">> ");
        scanf("%d", &mes_escolhido);
        segundo(mes_escolhido);
        printf("\n\n");
        system("pause");
        break;
    case 3:
        system("cls");
        printf("--- Escolha um ano ---\n");
        printf(">> ");
        scanf("%d", &ano_escolhido);
        terceiro(ano_escolhido);
        printf("\n\n");
        system("pause");
        break;
    default:
        printf("Digite uma opcao entre <0>...<3>");
        break;
    }
    goto inicio;
}

void primeiro() {
    int i, ano, mes, dias_mes, d, resposta, resposta2;
    char nomeArq[50];
    FILE *fin, *fout;

    // variável do tipo time_t para armazenar o tempo em t
    time_t t;

    // ponteiro para struct que guarda data e hora
    struct tm *atual;
    struct tm primeiro_dia;

    // pega tempo corrente e preenche na struct tm
    // t = time(NULL);
    time(&t);
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
    primeiro_dia.tm_hour = 12;
    primeiro_dia.tm_min = 0;
    primeiro_dia.tm_sec = 0;

    // Cria uma data pegando campos da struct tm
    mktime(&primeiro_dia);

    printf("\n%s - %d\n", nome_mes[mes], ano + 1900);

    printf("DOM SEG TER QUA QUI SEX SAB\n");
    for (i = 0; i < primeiro_dia.tm_wday; i++) {
        printf("    ");
    }

    for (d = 1; d <= dias_mes; d++) {
        printf("%3d ", d);
        i++;
        if (i % 7 == 0)
        {
            printf("\n");
        }
    }
    selec:
    printf("\n\nVoce quer salvar este resultado em um arquivo .txt? \n");
    printf(">> [1] - sim\n>> [2] - nao");
    printf("\n>> ");
    scanf("%d", &resposta2);

    switch(resposta2){
    case 1:
        printf("Qual o nome do arquivo que voce quer salvar (com extensao e sem espacos)\n");
        printf(">> ");
        scanf("%s", &nomeArq);
        fout = fopen(nomeArq,"w");
        if (fout == NULL) {
            printf ("\nNao foi possivel criar o arquivo de saida <%s>", nomeArq);
        } else {
            fprintf(fout, "\n%s - %d\n", nome_mes[mes], ano + 1900);

            fprintf(fout, "DOM SEG TER QUA QUI SEX SAB\n");
            for (i = 0; i < primeiro_dia.tm_wday; i++) {
                fprintf(fout, "    ");
            }

            for (d = 1; d <= dias_mes; d++) {
                fprintf(fout, "%3d ", d);
                i++;
                if (i % 7 == 0)
                {
                    fprintf(fout, "\n");
                }
            }                
            fclose (fout);
            printf("\nArquivo gerado com sucesso! ;D");
        }
        break;
    case 2:
        break;
    default:
        printf("\nDigite uma opcao valida...");
        goto selec;
    }
}

void segundo(int mes_esc) {
    int i, ano, mes, dias_mes, d, resposta, resposta3;
    char nomeArq[50];
    FILE *fin, *fout;

    // variável do tipo time_t para armazenar o tempo em t
    time_t t;

    // ponteiro para struct que guarda data e hora
    struct tm *atual;
    struct tm primeiro_dia;

    // pega tempo corrente e preenche na struct tm
    // t = time(NULL);
    time(&t);
    atual = localtime(&t);

    mes = (mes_esc - 1);
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
    for (i = 0; i < primeiro_dia.tm_wday; i++) {
        printf("    ");
    }

    for (d = 1; d <= dias_mes; d++) {
        printf("%3d ", d);
        i++;
        if (i % 7 == 0)
        {
            printf("\n");
        }
    }
    selec2:
    printf("\n\nVoce quer salvar este resultado em um arquivo .txt? \n");
    printf(">> [1] - sim\n>> [2] - nao");
    printf("\n>> ");
    scanf("%d", &resposta3);

    switch(resposta3){
    case 1:
        printf("Qual o nome do arquivo que voce quer salvar (com extensao e sem espacos)\n");
        printf(">> ");
        scanf("%s", &nomeArq);
        fout = fopen(nomeArq,"w");
        if (fout == NULL) {
            printf ("\nNao foi possivel criar o arquivo de saida <%s>", nomeArq);
        } else {
            fprintf(fout, "\n%s - %d\n", nome_mes[mes], ano + 1900);

            fprintf(fout, "DOM SEG TER QUA QUI SEX SAB\n");
            for (i = 0; i < primeiro_dia.tm_wday; i++) {
                fprintf(fout, "    ");
            }

            for (d = 1; d <= dias_mes; d++) {
                fprintf(fout, "%3d ", d);
                i++;
                if (i % 7 == 0)
                {
                    fprintf(fout, "\n");
                }
            }                
            fclose (fout);
            printf("\nArquivo gerado com sucesso! ;D");
        }
        break;
    case 2:
        break;
    default:
        printf("\nDigite uma opcao valida...");
        goto selec2;
    }
}

void terceiro(int ano_sel) {
    char nomeArq[50];
    FILE *fin, *fout;

    time_t t;
    struct tm *atual;
    struct tm primeiro_dia;

    int i, mes, dias_mes, d, j, resposta4;

    time(&t);
    atual = localtime(&t);
    for (j = 0; j < 12; j++) {
        mes = j;

        // Bissexto
        if (ano_sel % 4 == 0 && (ano_sel % 400 || ano_sel % 100 != 0)) {
            numero_dias[1] = 29;
        }

        dias_mes = numero_dias[mes];

        primeiro_dia.tm_mday = 1;
        primeiro_dia.tm_mon = mes;
        primeiro_dia.tm_year = ano_sel - 1900;
        primeiro_dia.tm_hour = 12;
        primeiro_dia.tm_min = 0;
        primeiro_dia.tm_sec = 0;

        mktime(&primeiro_dia);

        printf("%s - %d\n", nome_mes[mes], ano_sel);
        printf("Dom Seg Ter Qua Qui Sex Sab\n");

        for (i = 0; i < primeiro_dia.tm_wday; i++) {
            printf("    ");
        }

        for (d = 1; d <= dias_mes; d++) {
            printf("%3d ", d);
            i++;
            if (i % 7 == 0)
                printf("\n");
        }

        printf("\n\n\n");
    }
    selec3:
    printf("\n\nVoce quer salvar este resultado em um arquivo .txt? \n");
    printf(">> [1] - sim\n>> [2] - nao");
    printf("\n>> ");
    scanf("%d", &resposta4);

    switch(resposta4){
    case 1:
        printf("Qual o nome do arquivo que voce quer salvar (com extensao e sem espacos)\n");
        printf(">> ");
        scanf("%s", &nomeArq);
        fout = fopen(nomeArq,"w");
        if (fout == NULL) {
            printf ("\nNao foi possivel criar o arquivo de saida <%s>", nomeArq);
        } else {
            for (j = 0; j < 12; j++) {
                mes = j;

                // Bissexto
                if (ano_sel % 4 == 0 && (ano_sel % 400 || ano_sel % 100 != 0)) {
                    numero_dias[1] = 29;
                }

                dias_mes = numero_dias[mes];

                primeiro_dia.tm_mday = 1;
                primeiro_dia.tm_mon = mes;
                primeiro_dia.tm_year = ano_sel - 1900;
                primeiro_dia.tm_hour = 12;
                primeiro_dia.tm_min = 0;
                primeiro_dia.tm_sec = 0;

                mktime(&primeiro_dia);

                fprintf(fout, "%s - %d\n", nome_mes[mes], ano_sel);
                fprintf(fout, "Dom Seg Ter Qua Qui Sex Sab\n");

                for (i = 0; i < primeiro_dia.tm_wday; i++) {
                    fprintf(fout, "    ");
                }
                for (d = 1; d <= dias_mes; d++) {
                    fprintf(fout, "%3d ", d);
                    i++;
                    if (i % 7 == 0)
                        fprintf(fout, "\n");
                }
                fprintf(fout, "\n\n\n");
            }
            fclose (fout);
            printf("\nArquivo gerado com sucesso! ;D");
        }
        break;
    case 2:
        break;
    default:
        printf("\nDigite uma opcao valida...");
        goto selec3;
    }
}
