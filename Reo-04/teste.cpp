#include <iostream>
#include <stdexcept>

using namespace std;
#include <stdexcept>

struct dado {
    unsigned chave;
    string nomeCultivar;
    string marcaSemente;
    short anoFabricacao;
    int quantidadeDisponivel;
};

ostream& operator<<(ostream& saida, const dado& e) {
    saida << "(" << e.chave << "," << e.nomeCultivar << "," << e.marcaSemente << "," 
          << e.anoFabricacao << "," << e.quantidadeDisponivel << ")";
    return saida;
}

istream& operator>>(istream& entrada, dado& e) {
    entrada >> e.chave >> e.nomeCultivar >> e.marcaSemente 
            >> e.anoFabricacao >> e.quantidadeDisponivel;
    return entrada;
}

typedef unsigned tipoChave; // tipo da chave usada na comparação

class noh {
    friend class avl;
    private:
        dado elemento;
        noh* esq;
        noh* dir;
        unsigned altura;
    public:
        noh(const dado& umDado):
            elemento(umDado),  esq(NULL), dir(NULL), altura(1) { }
        ~noh() { }
        int fatorBalanceamento();
};

int noh::fatorBalanceamento() {
    #WARNING implemente
}

class avl {
    friend ostream& operator<<(ostream& output, avl& arvore);
    private:
        noh* raiz;
        // percorrimento em ordem da árvore
        void percorreEmOrdemAux(noh* atual, int nivel);
        // funções auxiliares para remoção
        noh* encontraMenor(noh* raizSub);
        noh* removeMenor(noh* raizSub);
        // funções auxiliares para inserção e remoção usando método recursivo
        // retorna o nó para ajustar o pai ou o raiz
        noh* insereAux(noh* umNoh, const dado& umDado);
        noh* removeAux(noh* umNoh, tipoChave chave);
        // métodos para manutenção do balanceamento
        noh* rotacaoEsquerda(noh* umNoh);
        noh* rotacaoDireita(noh* umNoh);
        noh* arrumaBalanceamento(noh* umNoh);
        // busca, método iterativo
        noh* buscaAux(tipoChave chave);
        // função auxiliar do destrutor, usa percorrimento pós-ordem
        void destruirRecursivamente(noh* umNoh);
        void imprimirDir(const std::string& prefixo, const noh* meuNoh);
        void imprimirEsq(const std::string& prefixo, const noh* meuNoh, bool temIrmao);
        int levantamentoAux(noh* umNoh, string cultivar, string  marca);
    public:
        avl() { raiz = NULL; }
        ~avl();
        void imprimir();
        // inserção e remoção são recursivos
        void insere(const dado& umDado);
        void remove(tipoChave chave);
        // inserção e remoção, métodos recursivos
        // busca retorna uma cópia do objeto armazenado
        dado busca(tipoChave chave);
        // efetua levantamento de quantas sementes de cultivares existem de uma dada marca
        int levantamento(string cultivar, string marca);
};

// destrutor
avl::~avl() {
    destruirRecursivamente(raiz);
}

// destrutor é recursivo, fazendo percorrimento pós-ordem
void avl::destruirRecursivamente(noh* umNoh) {
    #WARNING implemente
}

void avl::insere(const dado& umDado) {
    raiz = insereAux(raiz, umDado);
}

// inserção recursiva, devolve nó para atribuição de pai ou raiz
noh* avl::insereAux(noh* umNoh, const dado& umDado) {
    #WARNING implemente
}

// checa e arruma, se necessário, o balanceamento em umNoh,
// fazendo as rotações e ajustes necessários
noh* avl::arrumaBalanceamento(noh* umNoh) {
    #WARNING implemente
}


// rotação à esquerda na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoEsquerda(noh* umNoh) {
    #WARNING implemente
}


// rotação à direita na subárvore com raiz em umNoh
// retorna o novo pai da subárvore
noh* avl::rotacaoDireita(noh* umNoh) {
    #WARNING implemente
}


// método de busca auxiliar (retorna o nó), iterativo
noh* avl::buscaAux(tipoChave chave) {
    #WARNING implemente
}

// busca elemento com uma dada chave na árvore e retorna o registro completo
dado avl::busca(tipoChave chave) {
    noh* resultado = buscaAux(chave);
    if (resultado != NULL)
        return resultado->elemento;
    else
        throw runtime_error("Erro na busca: elemento não encontrado!");
}

// nó mínimo (sucessor) de subárvore com raiz em raizSub (folha mais à esquerda)
noh* avl::encontraMenor(noh* raizSub) {
    #WARNING implemente
}

// procedimento auxiliar para remover o sucessor substituíndo-o pelo
// seu filho à direita
noh* avl::removeMenor(noh* raizSub) {
    #WARNING implemente
}

// remoção recursiva
void avl::remove(tipoChave chave) {
    raiz = removeAux(raiz, chave);
}

noh* avl::removeAux(noh* umNoh, tipoChave chave) {
    #WARNING implemente
}


// utiliza o nó atual e seu nível na árvore (para facilitar visualização)
void avl::percorreEmOrdemAux(noh* atual, int nivel) {
    #WARNING implemente
}

ostream& operator<<(ostream& output, avl& arvore) {
    // arvore.percorreEmOrdemAux(arvore.raiz,0);
    arvore.imprimir();
    return output;
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirDir(const std::string& prefixo, const noh* meuNoh)
{
    if( meuNoh != nullptr )
    {
        std::cout << prefixo
                  << "└d─"
                  << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.nomeCultivar << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq( prefixo + "    " , meuNoh->esq , meuNoh->dir==nullptr );
        imprimirDir( prefixo + "    " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree as subarvores direitas de uma avl
void avl::imprimirEsq(const std::string& prefixo, const noh* meuNoh, bool temIrmao)
{
    if( meuNoh != nullptr )
    {
        std::cout << prefixo ;

        // A impressao da arvore esquerda depende da indicacao se existe o irmao a direita
        if (temIrmao)
            std::cout << "└e─" ;
        else
            std::cout << "├e─";

        std::cout << "(" << meuNoh->elemento.chave << "," << meuNoh->elemento.nomeCultivar << ")"
                  << std::endl;

        // Repassa o prefixo para manter o historico de como deve ser a formatacao e chama no filho direito e esquerdo
        imprimirEsq( prefixo + "│   " , meuNoh->esq, meuNoh->dir==nullptr );
        imprimirDir( prefixo + "│   " , meuNoh->dir );
    }
}

// imprime formatado seguindo o padrao tree uma avl
void avl::imprimir()
{
    if( this->raiz != nullptr )
    {
        std::cout << "(" << this->raiz->elemento.chave << "," << this->raiz->elemento.nomeCultivar << ")" << std::endl;
        // apos imprimir a raiz, chama os respectivos metodos de impressao nas subarvore esquerda e direita
        // a chamada para a impressao da subarvore esquerda depende da existencia da subarvore direita
        imprimirEsq( " " , this->raiz->esq, this->raiz->dir==nullptr );
        imprimirDir( " " , this->raiz->dir );
    } else
        std::cout << "*arvore vazia*" << std::endl;
}

int main() {
    avl arvore;
    tipoChave chave;
    dado umDado;
    string cultivar;
    string marca;
    int quantidade;

    char operacao;

    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // Inserir recursivamente
                    // objeto recebe chave, nome do cultivar, marca da semente, quantidade disponível
                    cin >> umDado;
                    arvore.insere(umDado);
                    break;
                case 'r': // Remover recursivamente
                    cin >> chave;
                    arvore.remove(chave);
                    break;
                case 'b': // Buscar
                    cin >> chave; // ler a chave
                    umDado = arvore.busca(chave); // escrever os dados do cultivar
                    cout << "Elemento buscado: " << umDado << endl;
                    break;
                case 'l': // Levantamento por cultivar e marca
                    cin >> cultivar >> marca; // ler os dados para levantamento
                    quantidade = arvore.levantamento(cultivar, marca);
                    cout << "Levantamento do cultivar " << cultivar << ": " << quantidade << endl;
                    break;
                case 'e': // Escrever tudo (em ordem)
                    cout << arvore;
                    break;
                case 'f': // Finalizar execução
                    break;
                default:
                    cout << "Comando invalido!\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (operacao != 'f');

    return 0;
}
