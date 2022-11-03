#include <iostream>
using namespace std;

class no{
	friend class fila;
	private:
		string carro;
		no* proximo;
	public:
		no(string car);
};

no::no(string car){
	carro = car;
	proximo = NULL;
}

class fila{
	private:
		no* inicio;
		no* fim;
		int qtd;
		int tam;
	public:
		fila();
		void carro_removido(string car,string removido);
		void estacionar(string car);
		void retira_do_estacionamento(string car);
};

fila::fila(){
	inicio = NULL;
	fim = NULL;
	tam = 0;
	qtd = 0;
}

void fila::carro_removido(string car,string removido){
	if((car != removido) and (tam != qtd)){
		qtd++;
		estacionar(removido);
		retira_do_estacionamento(car);
	}
	else if ((tam == qtd) and (car != removido)) {
		cout << "NAO ENCONTRADO" << endl;
		if(removido != "!") estacionar(removido);
	}
	else {
		cout << ++qtd << endl;
		for(int i = 0; i<tam; i++){
			string aux_car = inicio->carro;
			inicio = inicio->proximo;
			cout << aux_car << endl;
			tam--;
			estacionar(aux_car);
		}
		qtd = 0;
	}
}

void fila::estacionar(string car){
	no* novo = new no(car);
	if(tam == 0) inicio = novo;
	else fim->proximo = novo;
	fim = novo;
	tam++;
}

void fila::retira_do_estacionamento(string car){
	string aux_car = inicio->carro;
	no* aux_temp = inicio;
	inicio = inicio->proximo;
	delete aux_temp;
	tam--;
	if(tam == 0) fim = NULL;
	carro_removido(car,aux_car);
}

int main(){
	
	fila f;
	char metodo;
	string carro;
	int cont = 0;
	
	cin >> metodo;
	while(metodo != 'S'){
		cin >> carro;
		if(metodo == 'E'){
			f.estacionar(carro);
			cont++;
		}
		else if(metodo == 'D'){
			if(cont > 0)f.retira_do_estacionamento(carro);
			else f.carro_removido(carro,"!");
		}
		cin >> metodo;
	}
	return 0;
}
