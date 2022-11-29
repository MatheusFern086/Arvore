struct No
{
	/*parte de informa??o
	 a ser armazenada*/
	int valor;

	struct No *esq;
	struct No *dir;
};

struct No *raiz = NULL;

#define REMOVE_FOLHA(r) \
	free(*r);           \
	*r = NULL;

#define FOLHA(r) \
	(r->dir == NULL && r->esq == NULL)

// percurso em pr?- ordem :
// 1-imprime Raiz-
// 2-Navega para esq-
// 3-Navega para direita
void preOrdem(struct No *raiz)
{

	// Passo 1
	if (raiz != NULL)
	{

		printf("%d\n", raiz->valor);

		// Passo 2
		preOrdem(raiz->esq);

		// Passo 3
		preOrdem(raiz->dir);
	}
}

// percurso em in- ordem :
// 1-Navega para esq-
// 2-imprime Raiz-
// 3-Navega para direita
void inOrdem(struct No *raiz)
{

	// Passo 1
	if (raiz != NULL)
	{

		// Passo 1
		if (raiz->esq != NULL)
			inOrdem(raiz->esq);

		// Passo 2
		printf("%d\n", raiz->valor);

		// Passo 3
		if (raiz->dir != NULL)
			inOrdem(raiz->dir);
	}
}

// percurso em pos- ordem :
// 1-Navega para esq-
// 2-Navega para direita
// 3-imprime Raiz
void posOrdem(struct No *raiz)
{

	// Passo 1
	if (raiz != NULL)
	{

		// Passo 1
		posOrdem(raiz->esq);

		// Passo 2
		inOrdem(raiz->dir);

		// Passo 3
		printf("%d\n", raiz->valor);
	}
}

void insereArvoreDeBusca(int valor, struct No **raiz)
{
	// novo ter que ser raiz, se a arvore estiver vazia
	if ((*raiz) == NULL)
	{

		// alocar o no para o valor
		struct No *novo = (struct No *)malloc(sizeof(struct No));
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;

		(*raiz) = novo;
	}
	// senão, deve chamar a fun??o recursivamente para a direita
	// ou para a esquerda, comparando o valor com o que
	// estiver guardado na raiz.
	else if (valor > (*raiz)->valor)
	{
		insereArvoreDeBusca(valor, &((*raiz)->dir));
	}
	else
	{
		insereArvoreDeBusca(valor, &((*raiz)->esq));
	}
}

void buscaArvoreBusca(int valor, struct No *raiz)
{

	if (raiz != NULL)
	{
		if (valor < raiz->valor)
		{
			buscaArvoreBusca(valor, raiz->esq);
		}
		if (valor > raiz->valor)
		{
			buscaArvoreBusca(valor, raiz->dir);
		}
		if (valor == raiz->valor)
		{
			printf("O valor %d se encontra na arvore!", raiz->valor);
		}
	}
	else
	{
		printf("Raiz nãoo encontrada!");
	}
}

void imprimeDecrescente(struct No *raiz)
{

	// Passo 1
	if (raiz != NULL)
	{

		// Passo 1
		imprimeDecrescente(raiz->dir);

		// Passo 2
		printf("%d\n", raiz->valor);

		// Passo 3
		imprimeDecrescente(raiz->esq);
	}
}

int somaArvore(struct No *raiz)
{
	int resultado = 0;

	if (raiz != NULL)
	{

		resultado = resultado + somaArvore(raiz->esq);

		resultado = resultado + raiz->valor;

		resultado = resultado + somaArvore(raiz->dir);
	}
	return resultado;
}

int contaArvore(struct No *raiz)
{
	int cont = 0;

	if (raiz != NULL)
	{
		cont = cont + contaArvore(raiz->esq);

		cont = cont + 1;

		cont = cont + contaArvore(raiz->dir);
	}
	return cont;
}

void maiorElemento(struct No *raiz)
{
	if (raiz != NULL)
	{
		if (raiz->dir == NULL)
		{
			printf("O maior elemento ?: %d\n", raiz->valor);
		}
		else // continuar a busca pelo mauir, se a raiz tiver filho
			maiorElemento(raiz->dir);
	}
}

void menorElemento(struct No *raiz)
{
	if (raiz != NULL)
	{
		if (raiz->esq == NULL)
		{
			printf("O menor elemento ?: %d\n", raiz->valor);
		}
		else // continuar a busca pelo mauir, se a raiz tiver filho
			maiorElemento(raiz->esq);
	}
}

/*@input raiz da arvore ou da sub-rvore / @output: null, caso n?o haja antecessor
	ou nó que aponta para o npo que armazena
	o valor que antecede o valor de armazenamento na raiz*/

/* CORREÇÃO DA CRIS */
struct No *antecessor(struct No *raiz)
{

	// o nó antecessor é aqueLe que está mais à direita do ramo da esquerda
	struct No *antecede = NULL;

	// Passo 1: avaliar se h? antecessor
	if (raiz->esq != NULL)
	{

		// provável antecessor, se não tiver filho a direita
		antecede = raiz->esq;

		// Passo 2 procurar o filho mais a direita
		while (antecede->dir != NULL)
		{
			antecede = antecede->dir;
		}
		return antecede;
	}
	return NULL; // caso do if no->esq falhar, ou seja não há antecessor
}

/*@input raiz da arvore ou da subárvore / @output: null, caso não haja sucessor
	ou nó que aponta para o npo que armazena
	o valor que sucede o valor de armazenamento na raiz*/

/* CORREÇÃO DA CRIS */
struct No *sucessor(struct No *raiz)
{

	// o nó sucessor é aqueLe que está mais à esquerda do ramo da direita
	struct No *sucede = NULL;

	// Passo 1: avaliar se há antecessor
	if (raiz->dir != NULL)
	{

		// provável sucessor, se não tiver filho a direita
		sucede = raiz->dir;

		// Passo 2 procurar o filho mais a esquerda
		while (sucede->esq != NULL)
		{
			sucede = sucede->esq;
		}
		return sucede;
	}
	return NULL; // caso do if no->dir falhar, ou seja não há sucessor
}

/*função que dado um valor numperico, retorna o nó que o contém
@input: numero a ser procurado e a raiz da árvore ou da subárvore
@output: null, se a busca falhar ou o nó aponta para o valor na árvore*/
struct No *busca(struct No *raiz, int numero)
{

	struct No *resp = NULL;

	// falha se a árvore ou subárvore for vazia
	if (raiz == NULL)
		return NULL;

	// Procurar na raiz o n?mero
	if (raiz->valor == numero)
	{
		return raiz;
	}

	// Procurar no nó a esquerda
	resp = busca(raiz->esq, numero);

	// se não tiver a esquerda, procurar a direita
	if (resp == NULL)
	{
		return busca(raiz->dir, numero);
	}

	return resp;
}

struct No **encontraPai(struct No *r, struct No *filho)
{
	struct No **pai = calloc(1, sizeof(struct No *));
	*pai = r;
	if(filho == NULL) {
		return NULL;
	}
	while ((*pai)->dir || (*pai)->esq)
	{
		if ((*pai)->esq == filho || (*pai)->dir == filho)
			return pai;
		if(filho->valor == (*pai)->valor) {
			return NULL;
		}
		if (filho->valor < (*pai)->valor)
		{
			*pai = (*pai)->esq;
		}
		else if (filho->valor > (*pai)->valor)
		{
			*pai = (*pai)->dir;
		}
	}
	return NULL;
}

// remove um nó que não seja folha, captando o valor do antecessor
void removePorCopia(struct No **raiz)
{
	struct No **aux = (struct No **)calloc(1, sizeof(struct No*));
	int valor=0;
	// Passo 1: verificar se a raiz tem antecessor - chamar a antecessor
	aux = encontraPai(*raiz, antecessor(*raiz));
	if (aux != NULL)
	{
		// Passo 1.1: caso tenha, colocar na raiz, o valor do antecessor
		// trocar o valor da raiz pelo que está no antecessor
		// Passo 1.1.1: verificar se o antecessor é um nó folha
		if (antecessor(*raiz)->valor < (*aux)->valor)
		{
			valor = (*aux)->esq->valor;
			if (FOLHA((*aux)->esq))
			{
				REMOVE_FOLHA(&((*aux)->esq));
			}
			else
			{
				removePorCopia(&((*aux)->esq));
			}
		}
		else if (antecessor(*raiz)->valor > (*aux)->valor)
		{
			valor = (*aux)->dir->valor;
			// Caso seja, chamar a funcao REMOVE_FOLHA e encerrar a função
			if (FOLHA((*aux)->dir))
			{
				REMOVE_FOLHA(&((*aux)->dir));
			}
			else
			{
				removePorCopia(&((*aux)->dir));
			}
		}
		(*raiz)->valor = valor;
		free(aux);
		return;
	}

	aux = encontraPai(*raiz, sucessor(*raiz));
	if(aux) {
		if (sucessor(*raiz)->valor < (*aux)->valor)
		{
			valor = (*aux)->esq->valor;
			if (FOLHA((*aux)->esq))
			{
				REMOVE_FOLHA(&((*aux)->esq));
			}
			else
			{
				removePorCopia(&((*aux)->esq));
			}
		}
		else if (sucessor(*raiz)->valor > (*aux)->valor)
		{
			valor = (*aux)->dir->valor;
			// Caso seja, chamar a função REMOVE_FOLHA e encerrar a função
			if (FOLHA((*aux)->dir))
			{
				REMOVE_FOLHA(&((*aux)->dir));
			}
			else
			{
				removePorCopia(&((*aux)->dir));
			}
		}
		(*raiz)->valor = valor;
		free(aux);
		return;
	}
}
