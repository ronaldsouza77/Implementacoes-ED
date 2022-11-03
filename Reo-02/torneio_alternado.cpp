#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int INVALIDO = -1;

class torneio{
	private:
		int *heap;
		int capacidade;
		int tamanho;
		int iniciadados;
		inline int esquerda(int i);
		inline int direita(int i);
		void arruma();
		void copiamaior(int i,int cont);
	public:
		torneio( int vet[], int tam);
		~torneio();
		void imprime();
	
};

torneio::torneio(int vet[],int tam){
	capacidade = 1;
	while(capacidade < tam){
		capacidade *= 2;
	}
	capacidade = capacidade - 1 + tam;
	heap = new int[capacidade];
	
	iniciadados = capacidade - tam;
	
	memcpy(&heap[iniciadados], vet, tam*sizeof(int));

	tamanho = tam;
	arruma();
}

torneio::~torneio(){
	delete[] heap;
}

void torneio::arruma(){
	int cont = 0,aux = iniciadados;
	for(int i = iniciadados-1; i >= 0; i--){
		if((ceil(aux/2) == i+1)){
			aux = i;
			cont++;
		}
		copiamaior(i,cont);
	}
	cont = 0;
}

int torneio::esquerda(int i){
	return 2*i+1;
}

int torneio::direita(int i){
	return 2*i+2;
}

void torneio::copiamaior(int i, int cont){
	int esq = esquerda(i);
	int dir = direita(i);
	int maior = INVALIDO;
	
	if(esq < capacidade){
		if(cont%2 == 0){
			if((dir < capacidade) and (heap[dir] > heap[esq])){
				maior = dir;
			}
			else{
				maior = esq;
			}
			heap[i] = heap[maior];
		}
		else{
			if((dir < capacidade) and (heap[dir] > heap[esq])){
				maior = esq;
			}
			else{
				maior = dir;
			}
			heap[i] = heap[maior];
		}
	}
	else{
		heap[i] = INVALIDO;
	}
}

void torneio::imprime(){
	cout << heap[0] << endl;
}

int main(){
	
	int tam;
	cin >> tam;
	int vet[tam];
	for(int i =0; i<tam; i++){
		cin >> vet[i];
	}
	torneio *h = new torneio(vet,tam);
	h->imprime();
	delete h;
	
	return 0;
}
