#include "arquivos.h"

FILE* cria_arquivo_dat(int ordenacao, int tipo_de_vetor) {
      FILE* arquivo;

      char nome_do_arquivo[100];

      //Definindo a pasta dentro do diretório raiz
      strcpy(nome_do_arquivo, "./resultados/"); 

      //Adicionando o nome da pasta do método de ordenação
      strcat(nome_do_arquivo, nome_ordenacao_por_codigo(ordenacao)); 
      strcat(nome_do_arquivo, "/");

      //Definindo nome do arquivo como [nome_da_ordenacao-nome_tipo_de_vetor]
      strcat(nome_do_arquivo, nome_ordenacao_por_codigo(ordenacao)); 
      strcat(nome_do_arquivo, "-");
      strcat(nome_do_arquivo, nome_tipo_de_vetor_por_codigo(tipo_de_vetor));

      //Adicionando extensão .dat
      strcat(nome_do_arquivo, ".dat"); 

      arquivo = fopen(nome_do_arquivo, "w"); 
      return arquivo;
}

void escrever_dat(FILE* arquivo, int quantidade_de_elementos, long double media_de_tempo) {
      fprintf(arquivo, "%d", quantidade_de_elementos);
      fprintf(arquivo, "%c", '\t');
      fprintf(arquivo, "%LF", media_de_tempo);
      fprintf(arquivo, "%c", '\n');
}

/*!< Template de arquivo .csv

,,Iteração,,,,,,,,,,
,,1,2,3,4,5,6,7,8,9,10,Média ± Desvio Padrão
n,25,0,0,0,0,0,0,0,0,0,0,0 ± 0
,100,0,0,0,0,0,0,0,0,0,0,0 ± 0
,1000,0,0,0,0,0,0,0,0,0,0,0 ± 0
,10000,0,0,0,0,0,0,0,0,0,0,0 ± 0
,100000,0,0,0,0,0,0,0,0,0,0,0 ± 0

*/

FILE* cria_arquivo_csv(int ordenacao, int tipo_de_vetor) {
      FILE* arquivo;

      char nome_do_arquivo[100];

      //Definindo a pasta dentro do diretório raiz
      strcpy(nome_do_arquivo, "./resultados/testes/"); 

      //Definindo nome do arquivo como [nome_da_ordenacao-nome_tipo_de_vetor]
      strcat(nome_do_arquivo, nome_ordenacao_por_codigo(ordenacao)); 
      strcat(nome_do_arquivo, "-");
      strcat(nome_do_arquivo, nome_tipo_de_vetor_por_codigo(tipo_de_vetor));

      //Adicionando extensão .dat
      strcat(nome_do_arquivo, ".csv"); 

      arquivo = fopen(nome_do_arquivo, "w"); 

      /*!< Escrevendo cabeçalho do .csv */
      fprintf(arquivo, ",,Iteração,,,,,,,,,,\n"); 
      fprintf(arquivo, ",,1,2,3,4,5,6,7,8,9,10,Média ± Desvio Padrão\n"); 
      return arquivo;
}

void escrever_csv(FILE* arquivo, int quantidade_de_elementos, 
                        long double *tempo_de_execucao_ordenacao, int quantidade_de_testes, 
                        long double media_ordenacao, long double desvio_padrao_ordenacao) {
      
      /*!< Por conta da primeira linha ter o "n" representando o dado */
      if(quantidade_de_elementos == 25) {
            fprintf(arquivo, "n,%d,", quantidade_de_elementos);  
      } else {
            fprintf(arquivo, ",%d,", quantidade_de_elementos);  
      }

      /*!< Armazenando para cada iteração */
      for(int teste = 0; teste < quantidade_de_testes; teste++) {
            fprintf(arquivo, "%Lfs,", tempo_de_execucao_ordenacao[teste]);
      }

      /*!< Armazenando a média e desvio padrão */
      fprintf(arquivo, "%Lfs ± %Lfs", media_ordenacao, desvio_padrao_ordenacao);

      fprintf(arquivo, "\n");  
}