#include <iostream>

using namespace std;

int calculaHash(int chave, int capacidade){
	return chave % capacidade;
}

struct InfoHash{
	int chave;
	string valor;
};

class Hash{
public:
	Hash(int capacidade);
	~Hash();
	void Inserir(int chave, string valor);
	void InsereFim(int chave, string valor, int pos);
	bool Verificar(int verificaDado);
	void Imprimir();

private:
	int GetTamanho();
	int Buscar(int chave);
	InfoHash **tabela;
	InfoHash *dado;
	int capacidade;
	int tamanho;
};

Hash::Hash(int capacidade){
	this->capacidade = capacidade;
	tabela = new InfoHash*[capacidade];
	for (int i = 0; i < capacidade; i++){
		tabela[i] = new InfoHash[4];
	}

	for(int i = 0; i < capacidade; i++){
		for(int j = 0; j < 4; j++){
			tabela[i][j].chave = -1;
			tabela[i][j].valor = "";
		}
	}
	tamanho = 0;
}

Hash::~Hash(){
	delete[] tabela;
}

int Hash::Buscar(int chave){
	int pos = calculaHash(chave, capacidade);
	InfoHash dado[tamanho];

	for(int i = 0; i < capacidade; i++){
		if(dado[i].chave == chave){
			return i;
		}
	}

	return -1;// percorreu o vetor e não encontrou
}

void Hash::Inserir(int chave, string valor){
	
	int pos = calculaHash(chave, capacidade);
	//vetor umVetor.colisoes[0] = tabela[pos];// <****
	if (Buscar(chave) == -1){
		InsereFim(chave, valor, pos);
	}else{
		cout << "ITEM JÁ ESTÁ NA TABELA!" << endl;
	}
}

void Hash::InsereFim(int chave, string valor, int pos){
	
	//dado = tabela[pos][0];

	for(int i = 0; i < capacidade; i++){
		if(tabela[pos][i].chave == -1){
			tabela[pos][i].chave = chave;
			tabela[pos][i].valor = valor;
			i = capacidade;
		}
	}
	
	//capacidade--;
}

void Hash::Imprimir(){
	
	//dado = tabela[0][0];
	
	for(int i = 0; i < capacidade; i++){
		cout << i << ":";
		for(int j = 0; j < 4; j++){
			cout << '[' << tabela[i][j].chave << '/' << tabela[i][j].valor << ']' << " ";
		}
		cout << endl;
	}
}

int main(){
	
	int capacidadeHash;
	cin >> capacidadeHash;
	
	Hash Tabela(capacidadeHash);
	
	int quantidade_inserir;
	cin >> quantidade_inserir;
	
	//int chave;
	//string valor;
	InfoHash d[quantidade_inserir];
	
	for(int i = 0; i < quantidade_inserir; i++){
		cin >> d[i].chave >> d[i].valor;
		Tabela.Inserir(d[i].chave, d[i].valor);
	}
	bool achou = false;
	int chave[4];
	for(int i = 0; i < 4; i++){
		cin >> chave[i];
	}
	for(int j = 0; j < 4; j++){
		for(int i = 0; i < quantidade_inserir; i++){
			if( d[i].chave == chave[j]){
				 cout << d[i].valor << endl;
				 achou = true;
			}
		}
		if(achou == false){
		cout << "NÃO ENCONTRADO!" << endl;
		}
		achou = false;
	}
	Tabela.Imprimir();
	return 0;
}
