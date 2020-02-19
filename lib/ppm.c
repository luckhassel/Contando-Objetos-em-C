/** Pr� Compilador **/
#include <stdio.h>
#include <string.h>
#include "ppm.h"

/** Defini��o das fun��es de PPM **/

/** Defini��o de fun��es **/
/** Acessa um arquivo salvo e carrega na mem�ria como um tBitmap **/
void arquivo_pra_bitmap(char diretorio[], tBitmap *area)
{
	/* Inicializa */
	char *buffer, *token /*, *a, *b */;
	long i,j, N;
	FILE * arquivo;
	
	/* Carrega o arquivo como um Buffer */
	arquivo = fopen(diretorio, "rb");
	if (arquivo == NULL)
	{
		printf("Erro: O arquivo \"%s\" n�o pode ser encontrado.\n", diretorio);
		exit(1);
	}
	
	fseek(arquivo, 0, SEEK_END);
	N = ftell(arquivo);
	fseek(arquivo, 0, SEEK_SET);
	buffer = malloc((N+1)*sizeof(char));
	if(buffer==NULL)
	{
		printf("Erro: o sistema n�o tem mais espa�o disponivel.\n");
		exit(1);
	}
	
	fread(buffer, N, 1, arquivo);
	buffer[N]='\0';
	fclose(arquivo);
	
	
	
	/* Le o cabe�alho e testa as informa��es */
	token = strtok(buffer, " \t\n\r\v\f");
	
	if(strcmp(token, "P6"))
	{
		printf("Erro: O arquivo n�o est� no formato PPM.\n");
		exit(1);
	}
	
	token=strtok(NULL, " \t\n\r\v\f");
	area->largura=atoi(token);
	token=strtok(NULL, " \t\n\r\v\f");
	area->altura=atoi(token);
	
	token=strtok(NULL, " \t\n\r\v\f"); /* O exercicio especifica que aqui o valor sempre ser� 255 */
	
	while(*token++!='\0') /* STRTOK pode ter dificuldades em pegar o resto do c�digo, que pode incluir \0's por ser binario, por isso uso essa linha aqui */
		;
	
	/* Carrega os valores na matriz */
	area->matriz=malloc(area->altura*sizeof(*area->matriz));
	if (area->matriz==NULL)
	{
		printf("Erro: N�o h� mais mem�ria disponivel.\n");
		exit(1);
	}
	for(i=0; i<area->altura; ++i)
	{
		area->matriz[i]=malloc(area->largura*sizeof(**area->matriz));
		if (area->matriz[i]==NULL)
		{
			printf("Erro: N�o h� mais mem�ria disponivel.\n");
			exit(1);
		}
	}
	
	for(i=0; i<area->altura; ++i)
		for(j=0; j<area->largura; ++j)
		{
			area->matriz[i][j].r=*token++;
			area->matriz[i][j].g=*token++;
			area->matriz[i][j].b=*token++;
		}
	
	free(buffer);
}


/* Compara dois tPixels */
int mesmoPixel(tPixel A, tPixel B)
{
	if(A.r==B.r && A.g == B.g && A.b == B.b)
		return 1;
	return 0;
}
