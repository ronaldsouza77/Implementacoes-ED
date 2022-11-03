#include <iostream>
using namespace std;

class noh{
	friend class pilha;
	private:
		int mvalor;
		noh* mproximo;
	public:
		noh(int valor);
};

noh::noh(int valor){
	mvalor = valor;
	mproximo = NULL;
	cout << "Noh criado:" << this << endl;
}

class pilha{
	private:
		noh* mtopo;
		unsigned mtamanho;
	public:
		pilha();
		~pilha();
		unsigned tamanho();
		void empilha(int valor);
		int desempilha();
		void limpapilha();
		bool vazia();

};

pilha::pilha(){
	mtopo = NULL;
	mtamanho = 0;
}

pilha::~pilha(){
	limpapilha();
}

void pilha::limpapilha(){
	while(mtamanho > 0){
		desempilha();
	}
}

unsigned pilha::tamanho(){
	return mtamanho;
}

bool pilha::vazia(){
	return (mtamanho == 0);
}

void pilha::empilha(int valor){
	cout << "topo antes:" << mtopo << endl;
	noh* novo = new noh(valor);
	novo->mproximo = mtopo;
	mtopo = novo;
	mtamanho++;
	cout << "topo depois:" << mtopo <<endl;
	cout << "proximo do topo:" << mtopo->mproximo << endl;
	
}

int pilha::desempilha(){
	int aux_valor = mtopo->mvalor;
	noh* aux_temp = mtopo;
	mtopo = mtopo->mproximo;
	delete aux_temp;
	mtamanho--;
	return aux_valor;
}

int main(){
	
	pilha p1;
	int num;
	cin >> num;
	
	while(num >= 0){
		p1.empilha(num);
		cin >> num;
	}
	cout << "tamanho:" << p1.tamanho() << endl;
	
	cout << "Elementos:";
	
	while(not p1.vazia()){
		cout << p1.desempilha() << " ";
	}
	cout << endl;

	return 0;
}
