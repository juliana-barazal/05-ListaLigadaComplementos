#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
		NO* novo = (NO*)malloc(sizeof(NO));
		if (novo == NULL)
		{
			return;
		}

		cout << "Digite o elemento: ";
		cin >> novo->valor;
		novo->prox = NULL;


		if (primeiro == NULL)
		{
			primeiro = novo;
			cout << "Elemento inserido" << endl;
		}

		else if (novo->valor <= (primeiro->valor)) {
			if (novo->valor == primeiro->valor) {
				cout << "O elemento já está na lista. Insira outro valor." << endl;
				return;
			}

			if (novo->valor < primeiro->valor) {
				novo->prox = primeiro;
				primeiro = novo;
				cout << "Elemento inserido" << endl;
			}
		}

		else {
			NO* aux = primeiro;
			while (aux->prox != NULL && novo->valor >= aux->prox->valor) {

				if (novo->valor == aux->prox->valor) {
					cout << "O elemento já está na lista. Insira outro valor." << endl;
					return;
				}

				if (novo->valor > aux->valor) {
					aux = aux->prox;
				}

			}

			novo->prox = aux->prox;
			aux->prox = novo;
			cout << "Elemento inserido." << endl;

		}
}

void excluirElemento()
{
	NO* aux = primeiro;
	NO* ant=aux;
	int excluir;

	if (primeiro == NULL) {
		cout << "A listá está vazia, não é possível excluir elementos" << endl;
	}

	cout << "Digite o elemento que deseja excluir na lista." << endl;
	cin >> excluir;

	if (primeiro != NULL) {

		if (excluir == primeiro->valor) {
			primeiro = aux->prox;
			free(aux);
			cout << "Elemento excluído." << endl;
			return;
		}

		while (excluir > aux->valor && aux->prox != NULL || aux == NULL) {
			ant = aux;
			aux = aux->prox;
		}

		if (excluir == aux->valor) {
			ant->prox = aux->prox;
			free(aux);
			cout << "Elemento excluído." << endl;
			return;
		}

		if (excluir > aux->valor || excluir < aux->valor) {
			cout << "O elemento não está presente na lista. Busque outro valor." << endl;
			return;
		}
	}

}

void buscarElemento()
{
	NO* aux = primeiro;
	int busca;

	if (primeiro == NULL) {
		cout << "A listá está vazia, não é possível buscar elementos" << endl;
	}

	cout << "Digite o elemento que deseja buscar na lista." << endl;
	cin >> busca;

	if (primeiro != NULL) {
		while (busca > aux->valor && aux->prox != NULL || aux == NULL) {
			aux = aux->prox;
		}

			if (busca == aux->valor) {
				cout << "Encontrei o elemento!" << endl;
			}

			if (busca > aux->valor || busca < aux->valor) {
				cout << "O elemento não está presente na lista. Busque outro valor." << endl;
			}
		}

}


