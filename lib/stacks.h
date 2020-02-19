/** 
  * 	Quando se trata da defini��o de Stacks e Queues n�o importa realmente a maneira
  * como estas estrutras est�o armazenadas na mem�ria, mas sim o interfaceamento usado.
  * 	� por isso que o prot�tipo abaixo cria um novo tipo (numStack) que � na verdade um
  * ponteiro duplo para uma strutura (struct s_numStack**). Essa caracteristica pode parecer meio
  * estranha a principio, mas acredito que � um jeito interessante de interfacear o c�digo.
  * 	Esse design "esconde" acesso dos elementos da estrutura do usuario final (o que
  * costuma ser considerado uma boa pr�tica), dando acesso apenas � push(), pop(), peek()
  *	e isEmpty() pra controle, al�m da macro novaStack pra inicializar as pilhas com 0.
  * 	A ideia original era usar uma static global aqui pra dizer onde o topo da stack est�
  * e s� deixar o usuario acessar esse topo. O problema � que ai eu s� teria uma variavel topo
  * ou teria que ter uma array e interfacear cada uma. O m�todo que eu usei aqui tem o mesmo
  * resultado final, mas permitindo o uso de pilhas individuas declaradas com struct s_numStack *.
  *		Pode n�o ser a melhor implementa��o, mas eu gostei assim.
  *
  *		GUSTAVO GODOY.
  **/
  
#ifndef STACKS_H /* Prote��o de Header que impede de rodar o c�digo duas vezes */
#define STACKS_H /* quando multiplos arquivos chamam esse header */
/** Pr�-compilador */
#include <stdio.h>
#include <stdlib.h>

/** Declara��o de estruturas, fun��es, variaveis globais, etc **/
struct s_numStack
{
	long elemento;
	struct s_numStack *proximo;
};

typedef struct s_numStack ** numStack;

void push(struct s_numStack **pilha, long valor);
long pop(struct s_numStack **pilha);
long peek(struct s_numStack **pilha);
int isEmpty(struct s_numStack **pilha);
struct s_numStack ** newStack(void);
#endif
