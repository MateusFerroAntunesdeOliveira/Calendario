#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main ()
{
  char *nomeMes[] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
  int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  time_t agora;
  struct tm * tempo;
  struct tm primeiro_dia;
  int ano, mes;
  int i, diasNoMes, d;
  
  time (&agora); // pega o tempo corrente, data e hora da execucao
  tempo = localtime (&agora); // preenche a struct tm com os atributos corretos usando o time_t
  ano = tempo->tm_year;
  mes = 1; // para testar, coloca de 0 a 11 para testar outro mes

  // tem o dia, mes e ano na variavel agora
  // criar uma data no mesmo mes e ano, mas dia 1 (por exemplo, variavel primeiro_dia)
  primeiro_dia.tm_mday = 1;
  // fazer if para bissexto
  // se sim
  // diasPorMes[1] = 29
  primeiro_dia.tm_mon = mes; 
  
  primeiro_dia.tm_year = ano;
  primeiro_dia.tm_hour = 12;
  primeiro_dia.tm_min = 0;
  primeiro_dia.tm_sec = 0;
  // nesta variavel tm, preenche os campos e usa mktime
  mktime (&primeiro_dia);
  // ver entao o dia da semana que cai dia 1o. usando campo tm_wday
  //printf ("Dia primeiro cai em (comeca em 0): %d \n", primeiro_dia.tm_wday); // domingo eh 0 
  //printf ("\n");
  
  // imprime espacos antes do dia primeiro
  printf ("%s - %d\n", nomeMes[mes], ano+1900);
  printf ("Dom Seg Ter Qua Qui Sex Sab\n");
  // i pula os dias em branco antes do dia primeiro
  for (i=0; i<primeiro_dia.tm_wday; i++){
    printf ("    ");
  }
  diasNoMes = diasPorMes[mes]; // calcular usando a variavel mes como indice de um vetor de meses
  // depois imprime de 1 até ultimo dia do mês
  for (d=1; d<=diasNoMes; d++){
    printf ("%3d ", d);
    i++;  // i continua contando para pular a linha quando gastar 7 colunas
    if (i%7 == 0) printf ("\n");
  }
  
  // pegar antes os dados via parametros da main para saber qual o pedido do usuario
  // e opcionalmente salvar em arquivo texto conforme parametros
  return 0;
}
