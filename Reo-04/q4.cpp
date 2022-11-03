#include <iostream>
using namespace std;

class no {
	friend class abb;
	private:
		no* esq;
		no* dir;
		no* pai;
		int num;
	public:
		no(int dado);
};

no::no(int dado){
	num = dado;
	esq = NULL;
	dir = NULL;
	pai = NULL;
}

class abb {
	private:
		int qtd_no(no*no_aux);
		no* raiz;
	public:
		abb();
		~abb();
		void insere(int dado);
		int qtd_nos();
		int diferenca();
};

abb::abb(){
	raiz = NULL;
}

abb::~abb(){
	delete raiz;
}

void abb::insere(int dado) {
	no* novo = new no(dado);
	
	if(raiz == NULL) raiz = novo;
	else{
		no* atual = raiz;
		no* anterior;
		
		while(atual != NULL){
			anterior = atual;
			if(atual->num > dado) atual = atual->esq;
			else atual = atual->dir;
		}
		novo->pai = anterior;
		if(anterior->num > novo->num) anterior->esq = novo;
		else anterior->dir = novo;
	}
}

int abb::qtd_no(no*no_aux){
	if(no_aux == NULL) return 0;
	else return 1 + qtd_no(no_aux->esq) + qtd_no(no_aux->dir);
}

int abb::qtd_nos(){
	return qtd_no(raiz);
}

int abb::diferenca(){
	return qtd_no(raiz->esq) - qtd_no(raiz->dir);
}

int main () {
	abb arvore;
	
	int dado;
	cin >> dado;
	
	while(dado != -1){
		arvore.insere(dado);
		cin >> dado;
	}
	cout << arvore.qtd_nos() << " " << arvore.diferenca() << endl;
	return 0;
}
