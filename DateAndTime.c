#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>


// CABEÇALHO
void calendario(int ano);
char *NomeMes(int mes);
int calcularDiasMes(int ano, int mes);
bool Bissexto(int ano);
int zeller(int ano, int mes);

int main() {
    int ano;

    printf("Digite o ano desejado\n");
    printf(">> ");
    scanf("%d", &ano);

    calendario(ano);
    return 0;
}

void calendario(int ano) {
    int dia, mes, i;
    
    for (mes = 1; mes <= 12; mes++) {
        printf("Mes: %c\n", *NomeMes(mes));
        printf("Dom Seg Ter Qua Qui Sex Sab\n");
        
        int z = zeller(ano, mes);
        for (i = 0; i < z; i++) {
            printf("    ");
        } 

        int diasMes = calcularDiasMes(ano, mes);

        for (dia = 1; dia <= diasMes; dia ++) {
            printf("%3d ", dia);
            z++;

            if (z % 7 == 0) {
                printf("\n");
            }
        }
        
        printf("\n\n");
    }
}

int calcularDiasMes(int ano, int mes) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    }
    if (mes == 2) {
        if (Bissexto(ano)) return 29;
        return 28;
    }
    return 30;
}

bool Bissexto(int ano) {
    if (ano % 4 != 0) {
        return false;
    }
    if (ano % 100 != 0) {
        return true;
    }
    if (ano % 400 != 0) {
        return false;
    }
    return true;
}

int zeller(int ano, int mes) {
    int a, y, m, dia, d;

    a = (14 - mes) / 12;
    y = ano - a;
    m = mes + 12 * a - 2;
    dia = 1;
    d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    
    return d;
}

char *NomeMes(int mes) {

    switch (mes) {
        case 1:
            return "Janeiro";
        case 2:
            return "Fevereiro";
        case 3:
            return "Março";
        case 4:
            return "Abril";
        case 5:
            return "Maio";
        case 6:
            return "Junho";
        case 7:
            return "Julho";
        case 8:
            return "Agosto";
        case 9:
            return "Setembro";
        case 10:
            return "Outubro";
        case 11:
            return "Novembro";
        default:
            return "Dezembro";
        }
}
