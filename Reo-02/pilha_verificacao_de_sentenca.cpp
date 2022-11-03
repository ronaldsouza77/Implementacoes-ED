#include <iostream>
using namespace std;

class no{
	friend class pilha;
	private:
		char caracter;
		no *proximo;
	public:
		no(char letra);
};

no::no(char letra){
	caracter = letra;
	proximo = NULL;
}

class pilha{
	private:
		no *topo;
		int tam;
	public:
		pilha();
		int tamanho();
		void empilha(char letra);
		char desempilha();
};

pilha::pilha(){
	topo = NULL;
	tam = 0;
}

int pilha::tamanho(){
	return tam;
}

void pilha::empilha(char letra){
	no* novo = new no(letra);
	novo->proximo = topo;
	topo = novo;
	tam++;
}

char pilha::desempilha(){
	char aux_letra = topo->caracter;
	no *aux_temp = topo;
	topo = topo->proximo;
	delete aux_temp;
	tam--;
	return aux_letra;
}

int main (){
	
	pilha p1,p2;
	char letra;
	int cont_a = 0,cont_b = 0,cont_c = 0,cont_outras = 0;
	bool nao_pertence = false;
	
	cin >> letra;
	while((letra != 'X') and (nao_pertence == false)){
		if(letra == 'A'){
			p1.empilha(letra);
			cont_a++;
		}
		else if(letra == 'B'){
			cont_b++;
			if(cont_b> 1){
				nao_pertence = true;
			}
		}
		else if(letra == 'C'){
			if(cont_b == 0){
				nao_pertence = true;
			}
			p2.empilha(letra);
			cont_c++;
		}
		else{
			cont_outras++;
			nao_pertence = true;
		}
		cin >> letra;
	}
	if((cont_b == 1) and (cont_a == float(cont_c)/2) and (cont_outras == 0))
	cout << "sim";
	else cout << "nao";
	
	while((cont_a > 0) and (cont_c > 0)){
		cont_a--;
		p1.desempilha();
		cont_c--;
		if(cont_c >= 0){
			p2.desempilha();
		}
		cont_c--;
		if(cont_c >= 0){
			p2.desempilha();
		}
	}
	
	cout << " " << p1.tamanho() << " " << p2.tamanho() << endl;

	return 0;
}
