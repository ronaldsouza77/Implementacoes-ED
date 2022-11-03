#include <iostream>
using namespace std;

class noh{
	friend class fila;
	private:
		int mvalor;
		noh* mproximo;
	public:
		noh(int valor);
};

noh::noh(int valor){
	mvalor = valor;
	mproximo = NULL;
}

class fila{
	private:
		noh* minicio;
		noh* mfim;
		unsigned mtamanho;
	public:
		fila();
		~fila();
		unsigned tamanho();
		void enfileira(int valor);
		int desenfileira();
		void limpafila();
		bool vazia();
};

fila::fila(){
	minicio = NULL;
	mfim = NULL;
	mtamanho = 0;
}

fila::~fila(){
	limpafila();
}

void fila::limpafila(){
	while(mtamanho > 0){
		desenfileira();
	}
}

unsigned fila::tamanho(){
	return mtamanho;
}

bool fila::vazia(){
	return (mtamanho == 0);
}

void fila::enfileira(int valor){
	noh* novo = new noh(valor);
	if(mtamanho == 0){
		minicio = novo;
	}
	else{
		mfim->mproximo = novo;
	}
	mfim = novo;
	mtamanho++;
}

int fila::desenfileira(){
	int aux_valor = minicio->mvalor;
	noh* aux_temp = minicio;
	minicio = minicio->mproximo;
	delete aux_temp;
	mtamanho--;
	if(mtamanho == 0){
		mfim = NULL;
	}
	return aux_valor;
}

int main(){
	
	fila f1;
	int num;
	cin >> num;
	
	while(num >= 0){
		f1.enfileira(num);
		cin >> num;
	}
	cout << "tamanho:" << f1.tamanho() << endl;
	
	cout << "Elementos:";
	
	while(not f1.vazia()){
		cout << f1.desenfileira() << " ";
	}
	cout << endl;

	return 0;
}
