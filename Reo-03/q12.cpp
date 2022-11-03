#include <iostream>
using namespace std;

struct dados{
	int chave;
	string valor;
};

class hash{
	private:
		dados *tabela;
		int tam;
		int cap;
	public:
		hash(int capacidade);
		~hash();
		void inserir(dados chave);
		void recuperavalor(dados chave);
		void imprime();
};

hash::hash(int capacidade){
	cap = capacidade;
	tam = 0;
	dados tabela = new dados[cap];
}

hash::~hash(){
	delete[] tabela;
}

void hash::Inserir(){
	
	int pos = calculaHash(chave, capacidade);
	//vetor umVetor.colisoes[0] = tabela[pos];// <****
	if (Buscar(chave) == -1){
		InsereFim(chave, valor, pos);
	}else{
		cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
	}
}

int main (){
	int tam;
	
	cin >> tam;
	hash tabela(tam);
	
	cin >> tam;
	dados d[tam];
	for(int i = 0; i<tam; i++){
		cin >> d[i].chave >> d[i].valor;
		tabela.inserir(d);
	}
	
	return 0;
}
