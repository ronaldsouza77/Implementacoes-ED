#include <iostream>
#include <cstdlib>
using namespace std;

// para facilitar a troca de int para outro tipo
// estamos criando um apelido para int chamado dado
// com issso, destaca-se que a lista pode ser uma lista
// de qualquer objeto, não apenas inteiros...
// ou seja, é uma lista de dados.
typedef int Dado; //typedef permite criar novos tipos a partir de outros

class noh{
	friend class lista;
	private:
		// dado está como constante para não permitir alteração//
		const Dado dado;
		noh* proximo;
	public:
		//noh();
		noh(Dado d = 0);
};

// construindo dado chamando seu construtor
// note que o uso de inicialização em lista, já que dado é atributo constante
noh::noh(Dado d) : dado(d){
	proximo = NULL;
}

// lista dinamicamente encadeada
class lista{
private:
	noh* primeiro;
	noh* ultimo;
	int tamanho;
	void removetodos();// remove todos os elementos da lista
	 // imprime reverso a aprtir de um nó -> exemplo de uso de recursão
	void imprimereversoaux(noh* umnoh);
public:
	// construtores e destrutores
	lista();
	lista(const lista& umalista);
	~lista();
	// sobrecarga do operador de atribuição
	lista& operator=(const lista& umalista);
	// inserção, remoção e procura
	inline void insere(Dado dado);
	void inserenofim(Dado dado);
	void inserenoinicio(Dado dado);
	void inserenaposicao(int posicao, Dado dado);
	int procura (Dado valor); // retorna a posição do nó com va
	// métodos adicionais (impressão, vazia)
	void imprime();
	void imprimereverso();
	inline bool vazia();
	void removenofim();
	void removenoinicio();
};

// constrói uma lista inicialmente vazia
lista::lista(){
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;
}

// construtor de copia
lista::lista(const lista& umalista){
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;

	// percorre a lista recebida como parâmetro, copian do os dados
	noh* aux = umalista.primeiro;
	
	while(aux != NULL){
		inserenofim(aux->dado);
		aux = aux->proximo;
	}
}

// destrutor da lista (chama a função privada aux)
lista::~lista(){
	removetodos();
}

// remove todos os elementos da lista
void lista::removetodos(){
	noh* aux = primeiro;
	noh* temp;
	
	while(aux != NULL){
		temp = aux;
		aux = aux->proximo;
		delete temp;
	}
	// redirecionado ponteiros
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;
}

// sobrecarga do operador de atruibuição
lista& lista::operator =(const lista& umalista){
	// limpa a lista atual
	removetodos();
	// percorre a lista recebida como parâmetro, copiando os dados
	noh* aux = umalista.primeiro;
	
	while(aux != NULL){
		inserenofim(aux->dado);
		aux = aux->proximo;
	}
	return *this;
}

// insere por padrão no final da lista
void lista::insere(Dado dado){
	inserenofim(dado);
}

// insere no final da lista 
void lista::inserenofim(Dado dado){
	// *primeiro criamos o novo nó
	noh* novo = new noh(dado);
	
	// * agora inserioms o nó na lista
	// se a lista estiver vazia, inserimos o primeiro nó
	if( vazia() ){ // ou (primeiro == NULL) ou (tamanho == 0)
		primeiro = novo;
		ultimo = novo;
	}
	else{ // já tem elementos na lista, insere no final
		ultimo->proximo = novo;
		ultimo = novo;
	}
	tamanho++;
}

// insere no início da lista
void lista::inserenoinicio(Dado dado){
	// *primeiro criamos o novo nó
	noh* novo = new noh(dado);
	
	// * agora inserioms o nó na lista
	// se a lista estiver vazia, inserimos o primeiro nó
	if( vazia() ){ // ou (primeiro == NULL) ou (tamanho == 0)
		primeiro = novo;
		ultimo = novo;
	}
	else{ // já tem elementos na lista, insere no início
		novo->proximo = primeiro;
		primeiro = novo;
	}
	tamanho++;
}

// insere em uma determinada posição da lista
void lista::inserenaposicao(int posicao, Dado dado){
	// *primeiro criamos o novo nó
	noh* novo = new noh(dado);
	
	// *agora inserimos o nó na lista
	// verificamos antes se é possível inserir na posição
	if( (posicao <= tamanho) and (posicao >= 0) ){
		if( vazia() ){ // ou (primeiro == NULL) ou (tamanho == 0)
			primeiro = novo;
			ultimo = novo;
		}
		else if(posicao == 0){ // insere no início
			novo->proximo = primeiro;
			primeiro = novo;
		}
		else if( posicao == tamanho){ // insere no fim
			ultimo->proximo = novo;
			ultimo = novo;
		}
		else{ // insere no meio da lista
			noh* aux = primeiro;
			int posaux = 0;
			
			// chegando na posição da lista
			while( posaux < (posicao-1) ){
				aux = aux->proximo;
				posaux++;
			}
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
		tamanho++;
	}
	else{
		cerr << "Posicao inexistente!" << endl;
		exit(EXIT_FAILURE);
	}
}

int lista::procura(Dado valor){
	noh* aux = primeiro;
	int posaux = 0;
	
	while((aux != NULL) and (aux->dado != valor)){
		posaux++;
		aux = aux->proximo;
	}
	if(aux == NULL){
		posaux = -1;
	}
	return posaux;
}

// método básico que *percorre* uma lista, imprimindo seus elementos
// poderia percorrer fazendo outra ação (multiplicando valores, por exemplo)
void lista::imprime(){
	noh* aux = primeiro;
	
	while(aux != NULL){
		cout << aux->dado << " ";
		aux = aux->proximo;
	}
	cout << endl;
}

// usamos recursão( pilha de recursão ) para imprimir reverso
// para isso precisa de função auxiliar
void lista::imprimereverso(){
	imprimereversoaux(primeiro);
	cout << endl;
}

void lista::imprimereversoaux(noh* umnoh){
	if(umnoh != NULL){
		imprimereversoaux(umnoh->proximo);
		cout << umnoh->dado << " ";
	}
}

// verifica se está vazia
inline bool lista::vazia(){
	return (primeiro == NULL);
}

void lista::removenofim(){
	if ( vazia() ){
		cerr << "Remoção em lista vazia!" << endl;
		exit(EXIT_FAILURE);
	}
	noh* aux = primeiro;
	noh* anterior;
	
	while(aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}
	// parei no penúltimo
	delete ultimo;
	anterior->proximo = NULL;
	ultimo = anterior;
	
	tamanho--;
	if(tamanho == 0) primeiro = NULL;
}

void lista::removenoinicio(){
	if ( vazia() ){
		cerr << "Remoção em lista vazia!" << endl;
		exit(EXIT_FAILURE);
	}
	noh* removido = primeiro;
	primeiro = primeiro->proximo;
	delete removido;
	
	tamanho--;
	if( vazia() )ultimo = NULL;
}

int main (){
	lista minhalista;
	
	cout <<"***Teste da lista***"<< endl;
	cout << "Quantidade de valores a inserir: "<< endl;
	
	int valor;
	int num;
	cin >> num;
	
	for(int i = 0; i < num; i++){
		cin >> valor;
		minhalista.insere(valor);
	}
	minhalista.imprime();
	
	minhalista.inserenoinicio(18);
	minhalista.inserenaposicao(3,25);
	minhalista.imprime();
	minhalista.imprimereverso();
	
	cout << minhalista.procura(0) << endl;
	cout << minhalista.procura(50) << endl;
	cout << minhalista.procura(12) << endl;
	
	// construtor de cópia
	cout << "Sobrecarga do construtor de cópia" << endl;
	lista outralista(minhalista);
	outralista.imprime();
	outralista.imprimereverso();
	
	// sobrecarga de operador de atribuição
	cout << "Sobrecarga do operador de atribuição" << endl;
	lista maisumalista;
	maisumalista = outralista;
	
	maisumalista.imprime();
	maisumalista.imprimereverso();
	
	// testes de remoção
	cout << "Removeu no fim" << endl;
	maisumalista.removenofim();
	maisumalista.removenofim();
	maisumalista.imprime();
	maisumalista.imprimereverso();
	
	cout << "Removeu no início" << endl;
	maisumalista.removenoinicio();
	maisumalista.removenoinicio();
	maisumalista.imprime();
	maisumalista.imprimereverso();
	
	return 0;
}
