#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef int dado;
const int INVALIDO = -1;

class torneio{
	private:
		dado* heap;
		int capacidade;
		int tamanho;
		int iniciadados;
		inline int pai(int i);
		inline int esquerda(int i);
		inline int direita(int i);
		void arruma();//heapify()
		void copiamaior(int i);
		void copiasubindo(int i);
		
	public:
		torneio( dado vet[], int tam);
		torneio(int numfolhas);
		~torneio();
		void imprime();
		void insere(dado d);
	
};

torneio::torneio(dado vet[],int tam){
	//determinando a capacidade
	//numero de possiveis de pais e uma potencia de 2 menos 1
	//capacidade e possiveis pais mais tam do vetor
	//comecamos com 1 pai e vamos dobrando a cada caso
	capacidade = 1;
	while(capacidade < tam){
		capacidade *= 2;
	}
	//potencia de 2 menos 1 mais tamanho.
	capacidade = capacidade - 1 + tam;
	heap = new dado[capacidade];
	
	iniciadados = capacidade - tam;
	
	cout << "Inicio dados vet:" << iniciadados << endl;
	cout << "Capacidade vet:" << capacidade << endl;
	
	//equivalente ao for(copia uma regiao de memoria).
	//mais eficiente.
	memcpy(&heap[iniciadados], vet, tam*sizeof(dado));
	/*for(int i = 0; i < tam; i++){
		heap[i] = vet[i];
	}*/
	tamanho = tam;
	arruma();
}

torneio::torneio(int numfolhas){
	//determinando a capacidade
	//numero de possiveis de pais e uma potencia de 2 menos 1
	//capacidade e possiveis pais mais num folhas
	//comecamos com 1 pai e vamos dobrando a cada caso
	capacidade = 1;
	while(capacidade < numfolhas){
		capacidade *= 2;
	}
	//potencia de 2 menos 1 mais tamanho.
	capacidade = capacidade - 1 + numfolhas;
	heap = new dado[capacidade];
	
	iniciadados = capacidade - numfolhas;
	
	cout << "Inicio dados folha:" << iniciadados << endl;
	cout << "Capacidade folha:" << capacidade << endl;
	
	for(int i = 0; i < capacidade; i++){
		heap[i] = INVALIDO;
	}
}

torneio::~torneio(){
	delete[] heap;
	cout << "apos delete" << endl;
	imprime();
	cout << " fim delete" << endl;
}

void torneio::arruma(){
	cout << "arruma:" << iniciadados-1 << endl;
	for(int i = iniciadados-1; i >= 0; i--){
		copiamaior(i);
	}
}

int torneio::pai(int i){
	return (i-1)/2;
}

int torneio::esquerda(int i){
	return 2*i+1;
}

int torneio::direita(int i){
	return 2*i+2;
}

void torneio::copiamaior(int i){
	int esq = esquerda(i);
	int dir = direita(i);
	cout << "I:" << i << " " << "E:" << esq << " " << "D:" << dir << " ";
	int maior = INVALIDO;
	//cout << "ESQ:" << esq << " " << "DIR:" << dir;
	
	if(esq < capacidade){
		if((dir < capacidade) and (heap[dir] > heap[esq])){
			maior = dir;
		}
		else{
			maior = esq;
		}
		//cout << maior << endl;
		heap[i] = heap[maior];
	}
	else{
		heap[i] = INVALIDO;
	}
	cout << " " << "MAIOR:" << maior << " HEAP[MAIOR]:" << heap[maior] << endl;
}

void torneio::copiasubindo(int i){
	int p = pai(i);
	if(heap[i] > heap[p]){
		heap[p] = heap[i];
		copiasubindo(p);
	}
}

void torneio::imprime(){
	//for(int i = 0; i < tamanho; i++){
	cout << "HEAP:" << endl;
	for(int i = 0; i < capacidade; i++){
		cout << heap[i] << " ";
	}
	cout << endl;
}

void torneio::insere(dado d){
	if(tamanho == capacidade){
		cerr << "erro ao inserir" << endl;
		exit(EXIT_FAILURE);
	}
	heap[tamanho+iniciadados] = d;
	copiasubindo(tamanho+iniciadados);
	tamanho++;
}

int main(){
	int tam = 9;
	//;]çl~ppppl~plp~lppçlçlplp~pçlp~p~~pppint tam = 13;
	dado vet1[]={50,2,90,20,230,43,8,34,66};
	//dado vet1[]={11,5,3,4,2,15,7,9,10,8,12,6,16};
	torneio *h = new torneio(vet1,tam);
	h->imprime();
	delete h;
	
	tam = 13;
	dado vet2[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
	
	h = new torneio(vet2,tam);
	h->imprime();
	delete h;
	
	tam = 9;
	h = new torneio(9);
	for(int i = 0; i < tam; i++){
		h->insere(vet1[i]);
		h->imprime();
	}
	delete h;
	
	return 0;
}
