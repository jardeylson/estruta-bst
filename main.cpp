#include <iostream>

using namespace std;

struct noarvore{
	int dado;
	noarvore* esq;
	noarvore* dir;
};

void inicializar(noarvore*&raiz){
	raiz = NULL;
}

void inserir_BST(noarvore*&raiz, int dado){
	if(raiz == NULL){
		raiz = new noarvore;
		raiz->dado = dado;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	else if(dado < raiz->dado)
		inserir_BST(raiz->esq,dado);
	else if(dado > raiz->dado)
		inserir_BST(raiz->dir, dado);
}

noarvore* buscar_BST(noarvore* raiz, int dado){
	if((raiz == NULL) || (dado == raiz->dado))
		return raiz;
	else if(dado < raiz->dado)
		return buscar_BST(raiz->esq,dado);
	else
		return buscar_BST(raiz->dir,dado);
}

void imprimir_pre_ordem(noarvore* raiz){
	if(raiz!=NULL){
        cout<<raiz->dado<<" - ";
		imprimir_pre_ordem(raiz->esq);
		imprimir_pre_ordem(raiz->dir);
	}
}

void imprimir_central(noarvore* raiz){
	if(raiz!=NULL){
		imprimir_central(raiz->esq);
		cout<<raiz->dado<<" - ";
		imprimir_central(raiz->dir);
	}
}

void imprimir_pos_ordem(noarvore* raiz){
	if(raiz!=NULL){
		imprimir_pos_ordem(raiz->esq);
		imprimir_pos_ordem(raiz->dir);
		cout<<raiz->dado<<" - ";
	}
}

int menu(){
    int numero_menu;
    do{
        cout << "\n";
        cout << "1-imprimir pre ordem" << endl;
        cout << "2-imprimir ordem central" << endl;
        cout << "3-imprimir pos ordem" << endl;
        cout << "4-inderir elemento na arvore" << endl;
        cout << "5-buscar elemento na arvore" << endl;
        cout << "6-sair" << endl;
        cin >> numero_menu;
    }while(numero_menu > 6 || numero_menu < 1);
    return numero_menu;

}

int main()
{
    noarvore *r;
    inicializar(r);
    int indice_menu,dado,dado_pesquisa;

    while(indice_menu != 6){
        indice_menu = menu();
        switch (indice_menu){
        case 1:
            imprimir_pre_ordem(r);
            break;
        case 2:
            imprimir_central(r);
            break;
        case 3:
            imprimir_pos_ordem(r);
            break;
        case 4:
            cout << "insira elemento: ";
            cin >> dado;
            inserir_BST(r,dado);
            break;
        case 5:
            cout << "qual o elemento que deseja buscar: ";
            cin >> dado_pesquisa;
            if(buscar_BST(r,dado_pesquisa)!= NULL)
                cout << "dado encontrado" << endl;
            else
                cout << "dado não encontrado" << endl;
            break;
        case 6:
            break;
        default:
            cout << "valor invalido";
        }
    }

    return 0;
}
