#include <iostream>
#include <string>

using namespace std;

class elemento{
    friend class lista;
    private:
        int chave;
        elemento *proximo;
        elemento *anterior;
    public:
        elemento (int c){
            chave = c;
            proximo = NULL;
            anterior = NULL;
        }
};

class lista{
    private:
        elemento *inicio;
        elemento *fim;
        int tamanho;
    public:
        lista();
        ~lista();        
        void insereInicio(int c);
        void insereFim (int c);
        int removeRepetidos();//retorna a quantidade de elementos restantes na lista
        void imprimeLista();
};
    
lista::lista(){
	tamanho = 0;
    inicio = NULL;
    fim = NULL;
}
        
lista::~lista(){
	elemento* aux = inicio;
	elemento* temp;
	
	while(aux != NULL){
		temp = aux;
		aux = aux->proximo;
		delete temp;
	}
	tamanho = 0;
	inicio = NULL;
	fim = NULL;
}  

void lista::insereInicio (int c){
	elemento* novo = new elemento(c);
	
	if( inicio == NULL ){
		inicio = novo;
		fim = novo;
	}
	else{
		novo->proximo = inicio;
		inicio->anterior = novo;
		inicio = novo;
	}
	tamanho++;
}
        
void lista::insereFim (int c){
	elemento* novo = new elemento(c);
	
	if( inicio == NULL ){
		inicio = novo;
		fim = novo;
	}
	else{
		fim->proximo = novo;
		novo->anterior = fim;
		fim = novo;
	}
	tamanho++;
}
        
int lista::removeRepetidos(){
	elemento *aux = inicio;
	elemento *aux2;
	elemento *anterior;
	elemento *proximo;

	if(aux != NULL){
		while (aux->proximo != NULL){
			aux2 = aux->proximo;
			if (aux2->proximo == NULL){
				if (aux->chave == aux2->chave){
					anterior = aux2->anterior;
					anterior->proximo = NULL;
					fim = anterior;
					tamanho--;
				}
			}
			while (aux2->proximo != NULL){
				if (aux->chave == aux2->chave){
					anterior = aux2->anterior;
					proximo = aux2->proximo;
					anterior->proximo = proximo;
					proximo->anterior = anterior;
					tamanho--;
					aux2 = anterior;
				}
				aux2 = aux2->proximo;
				if (aux2->proximo == NULL){
					if (aux->chave == aux2->chave){
						anterior = aux2->anterior;
						anterior->proximo = NULL;
						fim = anterior;
						tamanho--;
					}
				}
			}
			if (aux->proximo != NULL){
				aux = aux->proximo;
			}
		}
	}
	return tamanho;
}

void lista::imprimeLista(){
    if (inicio != NULL){
        elemento *auxiliar = inicio;
        while (auxiliar->proximo != NULL){
            cout<<"("<<auxiliar->chave<<") ";
            auxiliar =  auxiliar->proximo;
        }
        cout<<"("<<auxiliar->chave<<")"<<endl;
    } else {
            cout<<"VAZIA";
    }
}       
    
int main(){
    
    lista listaD;
    
    int chave;
    string dado;
    
    cin>>chave;
    
    while (chave != -1){
        listaD.insereFim(chave);        
        cin>>chave;  
    }
    cout<<listaD.removeRepetidos()<<endl;
    listaD.imprimeLista();
    
    
    return 0;
}

