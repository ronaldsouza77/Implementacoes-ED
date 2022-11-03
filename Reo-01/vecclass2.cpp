/* Exemplo de uso da classe vectorx, 
 * um vetor dinâmico de inteiros
 * 
 * by Joukim, 2016-2018, Estruturas de Dados
 * 
 */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class vectorx {
    private:
        int* vetor;
        int tam;
        
    public:
        vectorx();
        vectorx(int n);
        vectorx(const vectorx& vec);
        ~vectorx();
        /* 
         * Referências para sobrecarga de operadores:
         * http://www.hardware.com.br/comunidade/sobrecarga-operadores/1150421/
         * http://users.cms.caltech.edu/~donnie/cs11/cpp/cpp-ops.html
         * http://en.cppreference.com/w/cpp/language/operators
         * https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
         */
        vectorx& operator+(const vectorx& vec); 
        vectorx& operator=(const vectorx& vec);  
        
        void preenche();
        void imprimir();
        int getTam();
        //int& getElemento(int pos);
        
        // para implementar
        int operator*(const vectorx& vec); // produto interno
        vectorx operator*(const int& n); // produto de vetor por um inteiro
        /* http://stackoverflow.com/questions/11704729/operand-order-in-operator-overload */
        friend vectorx operator*(const int& n, vectorx& vec); // produto de inteiro por vetor
        int& operator[](int pos);
        friend ostream& operator<<( ostream& output, const vectorx& vec);  
};

vectorx::vectorx( ) {
    vetor = new int[10];
    tam = 10;
}

vectorx::vectorx(int n) {
    vetor = new int[n];
    tam = n;
}

vectorx::vectorx(const vectorx& vec) {
    cout << "construtor de cópia" << endl;
    tam = vec.tam;
    vetor = new int[tam];
    for (int i = 0; i < tam; i++) {
        vetor[i] = vec.vetor[i];
    }
}

vectorx::~vectorx() {
    cout << "morri" << endl;
    delete[] vetor;
    tam = 0;
}

vectorx& vectorx::operator=(const vectorx& vec) {
    cout << "atribuição" << endl;
    delete[] vetor;
    tam = vec.tam;
    vetor = new int[tam];
    for (int i = 0; i < tam; i++) {
        vetor[i] = vec.vetor[i];
    }
    return *this;
}

vectorx& vectorx::operator+(const vectorx& vec){
    vectorx* result;
    int tam1 = tam;
    int tam2 = vec.tam;

    result = new vectorx(tam1+tam2);
        
    for (int i = 0; i < tam1; i++){
        result->vetor[i] = vetor[i];
    }

    for (int i = 0; i < tam2; i++){
        result->vetor[i+tam1] = vec.vetor[i];
    }   
        
    return *result;             
} 

int vectorx::operator*(const vectorx& vec){
    int result = 0;
    
    if (tam != vec.tam) {
        cerr << "tamanhos diferentes de vetores" << endl;
        exit(EXIT_FAILURE);
    } else {
        for (int i = 0; i < tam; i++) {
            result += vetor[i]*vec.vetor[i];
        }
    }
    // cout << result << endl;
    return result;
}

vectorx vectorx::operator*(const int& n){
    vectorx v = *this;
    
    for (int i = 0; i < tam; i++) {
        v.vetor[i] = n * v.vetor[i];
    }

    return v;
}

vectorx operator*(const int& n, vectorx& vec){
    return vec*n;
}

void vectorx::preenche() {
    for (int i = 0; i < tam; i++){
        vetor[i] = rand() % 100;
    }       
}

ostream& operator<<( ostream& output, const vectorx& vec) {
    for (int i = 0; i < vec.tam; i++){
        output << vec.vetor[i] << " ";
    }   
    output << endl;
    return output;
}

int vectorx::getTam() {
    return tam;
}

int& vectorx::operator[](int pos){
    if ((pos < 0) or (pos >= tam)){
        cerr << "posição inválida" << endl;
        exit(EXIT_FAILURE);
    } else {
        return vetor[pos];
    }
}


int main() {
    int tam1, tam2;

    cin >> tam1 >> tam2;
    
    // inicialiando gerador de n. aleat.
    srand(time(NULL));
    
    // criação dos vetores
    vectorx teste1;
    vectorx vec1(tam1);
    vectorx vec2(tam2);

    vectorx vec3;
    //vec3 = (tam1+tam2);
    vectorx *ptrVecx;
    ptrVecx = new vectorx;
    
    // preenchimento dos dados
    vec1.preenche();
    vec2.preenche();
    
    // pode dar erro se acessar posição inexistente
    vec2[5] = 10;
    // pode dar erro se forem de tamanhos diferentes
    cout << vec1*vec2 << endl;   
    
    teste1.preenche();
    ptrVecx->preenche();
    cout << "ok" << endl;
    //vec3.concatena(vec1, vec2);
    vec3 = vec1 + vec2;
    
    // usando construtor de cópia
    vectorx teste2 = teste1;
    
    // sobrecarga de operador (=)
    vectorx teste3;
    teste3 = teste1;
    
    // imprimindo os vetores
    cout << vec1 << vec2 << vec3;
    cout << "teste1" << endl;
    cout << teste1;
    teste1 = teste1 * 2;
    cout << teste1;
    teste1 = 3 * teste1;
    cout << teste1 << teste2 << *ptrVecx;
    

    delete ptrVecx;

    return 0;
}
