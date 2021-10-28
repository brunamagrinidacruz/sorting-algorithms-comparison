#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include <string.h>
#include "ordenacoes.h"
#include "vetores.h"

//https://www.cprogressivo.net/2013/10/Operacoes-com-arquivos-FILE-fopen-modos-de-abertura-fechamento-modo-texto-binario-EOF-fclose-fcloseall.html

#define QUANTIDADE_VALORES_ANALISADOS 4

/*!<
      Recebe ordenacao que indica o nome da pasta em ./resultados que o .dat será salvo
      Recebe tipo_de_vetor que indica parte do nome do arquivo .dat
      Retorna arquivo FILE como ./resultados/[nome da ordenacao]/[nome_da_ordenacao-nome_tipo_de_vetor].dat
*/
FILE* cria_arquivo_dat(int ordenacao, int tipo_de_vetor);

/*!< 
      Recebe o arquivo .dat
      Os valores salvos no arquivo serão quantidade_de_elementos e media_de_tempo
*/
void escrever_dat(FILE* arquivo, int quantidade_de_elementos, long double media_de_tempo);

void imprimir_tabela_media(int n, int quantidade_de_testes, long double medias_ordenacao1[][QUANTIDADE_VALORES_ANALISADOS], long double medias_ordenacao2[][QUANTIDADE_VALORES_ANALISADOS], long double medias_ordenacao3[][QUANTIDADE_VALORES_ANALISADOS]);

#endif