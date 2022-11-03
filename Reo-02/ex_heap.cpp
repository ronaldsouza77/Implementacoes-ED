#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef int dado;

class MaxHeap{
	private:
		dado* heap;
		int capacidade;
		int tamanho;
		inline int pai(int i);
		inline int esquerda(int i);
		inline int direita(int i);
		void arruma();//heapify()
		void corrigedescendo(int i);
		void corrigesubindo(int i);
		
	public:
		MaxHeap(int cap);
		MaxHeap( dado vet[], int tam);
		~MaxHeap();
		void imprime();
		dado espiaraiz();
		dado retiraraiz();
		void insere(dado d);
	
};

MaxHeap::MaxHeap(int cap){
	capacidade = cap;
	heap = new dado[cap];
	tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[],int tam){
	capacidade = tam;
	heap = new dado[capacidade];
	
	//equivalente ao for(copia uma regiao de memoria).
	//mais eficiente.
	memcpy(heap, vet, tam*sizeof(dado));
	/*for(int i = 0; i < tam; i++){
		heap[i] = vet[i];
	}*/
	tamanho = tam;
	arruma();
}

MaxHeap::~MaxHeap(){
	delete[] heap;
}

void MaxHeap::arruma(){
	for(int i = (tamanho/2-1); i >= 0; i--){
		corrigedescendo(i);
	}
}

int MaxHeap::pai(int i){
	return (i-1)/2;
}

int MaxHeap::esquerda(int i){
	return 2*i+1;
}

int MaxHeap::direita(int i){
	return 2*i+2;
}

void MaxHeap::corrigedescendo(int i){
	int esq = esquerda(i);
	int dir = direita(i);
	int maior = i;
	
	if((esq < tamanho) and (heap[esq] > heap[maior])){
		maior = esq;
	}
	if((dir < tamanho) and (heap[dir] > heap[maior])){
		maior = dir;
	}
	if(maior != i){
		swap(heap[i],heap[maior]);
		corrigedescendo(maior);
	}
}

void MaxHeap::corrigesubindo(int i){
	int p = pai(i);
	if(heap[i] > heap[p]){
		swap(heap[i],heap[p]);
		corrigesubindo(p);
	}
}

void MaxHeap::imprime(){
	//for(int i = 0; i < tamanho; i++){
	for(int i = 0; i < capacidade; i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}

dado MaxHeap::espiaraiz(){
	return heap[0];
}

dado MaxHeap::retiraraiz(){
	if(tamanho == 0){
		cerr << "erro ao retirar raiz" << endl;
		exit(EXIT_FAILURE);
	}
	dado aux = heap[0];
	swap(heap[0],heap[tamanho-1]);
	tamanho--;
	corrigedescendo(0);
	return aux;
}

void MaxHeap::insere(dado d){
	if(tamanho == capacidade){
		cerr << "erro ao inserir" << endl;
		exit(EXIT_FAILURE);
	}
	heap[tamanho] = d;
	corrigesubindo(tamanho);
	tamanho++;
}

int main(){
	int tam = 13;
	
	dado vet[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
	
	MaxHeap *h = new MaxHeap(vet,tam);
	h->imprime();
	
	for(int i = 0; i < tam; i++){
		cout << h->retiraraiz() << " :";
		h->imprime();
	}
	cout << endl;
	for(int i = 0; i < tam; i++){
		h->insere(vet[i]);
	}
	h->imprime();
	for(int i = 0; i < tam; i++){
		cout << h->retiraraiz() << " :";
		h->imprime();
	}
	cout << endl;
	
	delete h;
	
	return 0;
}
