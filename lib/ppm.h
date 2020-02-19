/**
  *	Suporte para trabalhar com imagens do tipo PPM (especificamente o padr�o P6):
  *	Define o tipo tPixel que armazena um trio de inteiros RGB e o tipo tBitmap que cria uma matriz bidimensional de tPixels e armazena informa��o de largura e altura.
  *	Define a fun��o arquivo_pra_bitmap que carrega um arquivo do disco para a mem�ria como um tBitmap.
  *	Define outras fun��es auxiliares tamb�m.
 **/
 
#ifndef PPM_H /* Prote��o de Header que impede de rodar o c�digo duas vezes */
#define PPM_H /* quando multiplos arquivos chamam esse header */
/** Instru��es para o compilador **/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "stacks.h"

/** Declara��o de estruturas, fun��es, etc **/
typedef struct sPixel
{
	int r; /* "Red" - Vermelho */ 
	int g; /* "Green" - Verde */
	int b; /* "Blue" - Azul*/
} tPixel;

typedef struct sBitmap
{
	long largura;
	long altura;
	tPixel ** matriz;
} tBitmap;

int mesmoPixel(tPixel A, tPixel B);
void arquivo_pra_bitmap(char diretorio[], tBitmap *area); /** IMPORTANTE! matriz � carregada como matriz[altura][largura]!!! **/

#endif
