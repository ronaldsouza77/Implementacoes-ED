#include <iostream>
using namespace std;

class noh {
    friend class fila;  //apenas para acessar os campos privados
    private:
        int mValor;
        noh* mProximo;  //apontando para o próximo valor
    public:
        noh(int valor);
};

noh::noh(int valor){   //nós sendo construídos apontando para ninguém
    mValor = valor;
    mProximo = NULL;
}

class fila {
    private:
        noh* mInicio;  
        noh* mFim;
        unsigned mTamanho;
    public:
        fila();
        ~fila();
        unsigned tamanho();
        void enfileira(int valor);
        int desenfileira();
        void limpaFila();
        int espia();
        void exibe();
        bool vazia();
};

fila::fila() {
    mInicio = NULL;
    mFim = NULL;
    mTamanho = 0;
}

fila::~fila() {
    limpaFila();
};

void fila::limpaFila() {  //limpa todos os nós
    while (mTamanho > 0){
        desenfileira();
    };
}

unsigned fila::tamanho() {
    return mTamanho;
}

bool fila::vazia() {
    return (mTamanho == 0);
}

void fila::enfileira(int valor) {
    noh* novo = new noh(valor);
    
    if (mTamanho == 0){
        mInicio = novo;
    } else {
        mFim->mProximo = novo;
    }
    
    mFim = novo;
    mTamanho++;
}

int fila::desenfileira() {
    int valor = mInicio->mValor;
    noh* temp = mInicio;
    mInicio = mInicio->mProximo;
    delete temp;
    mTamanho--;
    
    if (mTamanho == 0){
        mFim = NULL;
    }
    return valor;
}

int fila::espia() {
    return mInicio->mValor;
}

void fila::exibe() {
    noh* aux = mInicio;
    
    for (unsigned i=0; i<mTamanho; i++){
        cout << aux->mValor << " ";
        aux = aux->mProximo;
    }
}

int main() {
    fila f1;
    fila f2;
    fila fAux;
    int tamF1, tamF2;
    int num, num2;
    int vaux = -1, q = -1;
    
    cin >> tamF1;
    for (int i=0; i<tamF1; i++){
        cin >> num;
        f1.enfileira(num);
    }
    
    cin >> tamF2;
    for (int i=0; i<tamF2; i++){
        cin >> num2;
        f2.enfileira(num2);
    }
    while ((f1.tamanho() + f2.tamanho()) != 0){
        if (f2.tamanho() == 0 or f1.tamanho() == 0){
            if (f2.tamanho() == 0){
                vaux = f1.desenfileira();
                if(vaux != q){
					 fAux.enfileira(vaux);
					 q = vaux;
				}
            } else {
                 vaux = f2.desenfileira();
                 if(vaux != q){
					 fAux.enfileira(vaux);
					 q = vaux;
				}
            }
        } else {
            if (f2.espia() < f1.espia() and f2.tamanho() != 0 and f1.tamanho() != 0){
				vaux = f2.desenfileira();
				if(vaux != q){
					 fAux.enfileira(vaux);
					 q = vaux;
				}
            } else if (f1.espia() < f2.espia() and f2.tamanho() != 0 and f1.tamanho() != 0){
				vaux = f1.desenfileira();
                if(vaux != q){
					 fAux.enfileira(vaux);
					 q = vaux;
				}
            } else if (f2.espia() == f1.espia() and f2.tamanho() != 0 and f1.tamanho() != 0){
                if (f2.tamanho() < f1.tamanho()){
					vaux = f2.desenfileira();
                    if(vaux != q){
						fAux.enfileira(vaux);
						q = vaux;
					}
                } else {
					vaux = f1.desenfileira();
                    if(vaux != q){
						fAux.enfileira(vaux);
						q = vaux;
					}
                }
            }
        }
    }
    
    fAux.exibe();
    
    return 0;
}
