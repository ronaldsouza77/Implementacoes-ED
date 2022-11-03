#include <iostream>
#include <string>

class Data {
    public:
        Data(int d, int m, int a = 0);
        void Alterar(int d, int m, int a = 0);
        int Ano() const { return ano; }
        int Dia() const { return dia; }
        unsigned Hash(int limite) const;
        int Mes() const { return mes; }
    protected:
        int dia;
        int mes;
        int ano;
};

class Funcionario {
    public:
        Funcionario() : nome(), nascimento(0, 0, 0) {}
        bool FazAniversarioEm(const Data& data);
        std::string nome;
        Data nascimento;
};

// Um Noh guarda um funcionário em uma tabela
class Noh {
    public:
        Noh(const Funcionario& func, Noh* proximo = NULL) :
            mValor(func), mProximo(proximo) {
        }
        Funcionario mValor;
        Noh* mProximo;
};

// Uma lista guarda todos os Nos cuja chave foi mapeada na mesma posição.
class ListaAux {
    friend class Hash;
    public:
        // construtor
        ListaAux() : mPrimeiro(NULL), mTamanho(0) {}
        // Adiciona um Noh a uma lista.
        void Adicionar(Noh* novoNoh);
    private:
        Noh* mPrimeiro; // primeiro nó da ListaAux
        short int mTamanho; // quantidade de valores na ListaAux
};

// Um hash guarda vários funcionários, considerando o seu nascimento como chave.
class Hash {
    public:
        Hash(int cap = 100);
        ~Hash();

        // Insere um funcionario.
        void Inserir(const Funcionario& func);
        // Retorna a porcentagem de uso das posições da tabela hash.
        float PorcentagemDeUso() const;
        // Retorna a quantidade de aniversariantes numa data (dia/mes).
        unsigned QtdeAniversariantes(const Data& d);
    private:
        // vetor de ponteiros para lista
        ListaAux* mElementos;
        // quantidade de posições na tabela hash
        int mNroPosicoes;
};

using namespace std;
// === Data ===================================================================
Data::Data(int d, int m, int a)
    : dia(d), mes(m), ano(a) {
}

void Data::Alterar(int d, int m, int a) {
    dia = d;
    mes = m;
    ano = a; // ano tem valor default
}

unsigned Data::Hash(int limite) const {
    return (unsigned(dia) * unsigned(mes) - 1) % unsigned(limite);
}

istream& operator>> (istream& entrada, Data& d) {
    int dia, mes, ano;
    entrada >> dia >> mes >> ano;
    d.Alterar(dia, mes, ano);
    return entrada;
}

ostream& operator<< (ostream& saida, Data& d) {
    saida << d.Dia() << '/' << d.Mes() << '/' << d.Ano();
    return saida;
}

// === Funcionario ============================================================
bool Funcionario::FazAniversarioEm(const Data& data) {
    return nascimento.Dia() == data.Dia() and nascimento.Mes() == data.Mes();
}

ostream& operator<< (ostream& saida, Funcionario& f) {
    saida << f.nome << ' ' << f.nascimento;
    return saida;
}

// === ListaAux ===============================================================
void ListaAux::Adicionar(Noh* novoNoh) {
    if(mTamanho == 0){
		mPrimeiro = novoNoh;
	}
	else{
		novoNoh->mProximo = mPrimeiro;
		mPrimeiro = novoNoh;
	}
	mTamanho++;
}

// === Hash ===================================================================
Hash::Hash(int cap) // cap tem valor default
    : mElementos(new ListaAux[cap]), // chama construtor em todos
      mNroPosicoes(cap) {
}

Hash::~Hash() {
    for (int i = 0; i < mNroPosicoes; ++i) {
        Noh* atual = mElementos[i].mPrimeiro;
        while (atual != NULL) {
            Noh* aux = atual;
            atual = atual->mProximo;
            delete aux;
        }
    }
    delete[] mElementos;
}

void Hash::Inserir(const Funcionario& func) {
	int pos = func.nascimento.Hash(mNroPosicoes);
	Noh *novo = new Noh(func);
	
	mElementos[pos].Adicionar(novo);
}

float Hash::PorcentagemDeUso() const {
	float pos_usadas = 0;
	
	for(int i = 0; i<mNroPosicoes; i++){
		Noh *aux = mElementos[i].mPrimeiro;
		if(aux != NULL) pos_usadas++;
	}
	return pos_usadas/mNroPosicoes;
}

unsigned Hash::QtdeAniversariantes(const Data& d) {
	int qtd = 0;
	
	for(int i = 0; i<mNroPosicoes; i++){
		Noh *aux = mElementos[i].mPrimeiro;
		while(aux != NULL){
			if(aux->mValor.FazAniversarioEm(d) != false) qtd++;
			aux = aux->mProximo;
		}
	}
	return qtd;
}

// === Programa ===============================================================
int main( ) {
    unsigned qtde;
    cin >> qtde; // quantidade de posições na tabela
    Hash tabela(qtde); // cria uma tabela com 10 endereços
    Funcionario funcionario;
    cin >> qtde; // quantidade de funcionários a inserir
    for (unsigned int i = 0; i < qtde; ++i) {
        cin >> funcionario.nome >> funcionario.nascimento;
        tabela.Inserir(funcionario);
    }
    int dia, mes;
    cin >> dia >> mes;
    Data hoje(dia, mes);
    cout << tabela.QtdeAniversariantes(hoje) << ' '
         << tabela.PorcentagemDeUso() << endl;
    return 0;
}
