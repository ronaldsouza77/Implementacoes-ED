#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "teste.cpp"
#include <cmath>
#define N 40
using namespace std;

fstream arquivo_binLer;
ofstream arquivoOrig;
struct arquivo {
    fstream f;
    int MAX, pos;
    jogador_string *buffer;
    bool estado;
    int tamanho, posBin;
};

int retorna_tamanhoOrd(char *nome) {
    arquivo_binLer.open(nome, ios::binary | ios::in);
	int tam;
	arquivo_binLer.seekg (0, ios::end);
	tam = arquivo_binLer.tellg();
	arquivo_binLer.seekg (0, ios::beg);
    arquivo_binLer.close();
    return tam;
}

char verificaAspas(string nome){
    char aspas = '\"';
    if (nome[0] == aspas){
        return toupper (nome[1]); // transforma a primeira letra em sua maiuscula
    }
    return toupper(nome[0]);
}

void intercala(jogador_string vetJogador[], int inicio, int meio, int fim) {
    int i = inicio, j = meio+1;
    //cout << "inicio=" << inicio << endl;
    int tamanho = fim - inicio + 1;
    char letraUm, letraDois;
    jogador_string auxVetJgdr[tamanho];       // vetor auxiliar
    for (int k=0; k < tamanho; k++) {
        if ((i <= meio) and (j <= fim)){
            //cout << "comparando: " << vetJogador[i].nome << " e " << j << vetJogador[j].nome << endl;
            letraUm = verificaAspas(vetJogador[i].nome); // verifica se o 1º char eh aspas
            letraDois = verificaAspas(vetJogador[j].nome);
            //cout << "comparando letras: " << letraUm << " " << letraDois << endl;
            if (letraUm < letraDois){
                auxVetJgdr[k] = vetJogador[i]; // copia trecho1 em aux[]
                i++; // avança em trecho1
            } 
            else if (letraUm == letraDois){
                if(vetJogador[i].id <= vetJogador[j].id){ // verifica o ID
                    auxVetJgdr[k] = vetJogador[i]; 
                    i++;
                    //cout << "eh menor "<< auxVetJgdr[k].nome << endl;
                }
                else {
                    auxVetJgdr[k] = vetJogador[j]; // copia trecho2 em aux[]
                    j++; // avanca em trecho2
                }
            }
            else { // se for maior
                auxVetJgdr[k] = vetJogador[j]; // copia trecho2 em aux[]
                j++; // avanca em trecho2
            }
        }
        else if (i > meio){
            auxVetJgdr[k] = vetJogador[j];
            j++;
        } else {
            auxVetJgdr[k] = vetJogador[i];
            i++;
        }
    }
    // terminando: copiar de aux[] em a[inicio:fim]
    for (int k=0; k < tamanho; k++){
        vetJogador[inicio + k] = auxVetJgdr[k];
    }
}

void mergesort(jogador_string vetJogador[], int inicio, int fim){ // 4 -> inic =0 fim = 3
    int meio;
    meio = (inicio + fim)/2;
    if (inicio < fim) {
        meio = (inicio + fim)/2;
        mergesort(vetJogador, inicio, meio);
        mergesort(vetJogador, meio+1, fim);
        intercala(vetJogador,inicio,meio,fim);
    }
}

void qsort(jogador_string vetJogador[], int total){
    mergesort(vetJogador, 0, total-1);
}

void salvaOrdenado(char *nome, jogador_string vetJogador[], int tam, bool primeiro){
    if (primeiro == false){
        arquivoOrig.open("data_athlete_game.bin", ios::binary | ios::out | ios::app);
        for (int i=0; i < tam; i++){
            arquivoOrig.write((char*) (&vetJogador[i]), sizeof(jogador_string)) << endl;
        }
        /*
        cout  << "salvando....." << endl;
        cout << vetJogador[0].nome << endl;
        cout  << vetJogador[1].nome << endl;
        cout  << vetJogador[2].nome << endl;
        */
    }
    else {
        arquivoOrig.open("data_athlete_game.bin", ios::binary | ios::out);
        for (int i=0; i < tam; i++){
            arquivoOrig.write((char*) (&vetJogador[i]), sizeof(jogador_string)) << endl;
        }
    }  
    arquivoOrig.close(); 
    
}


void salvaArquivo(char *nome, jogador_string vetJogador[], int tam, int mudaLinhaFinal){
    int i;
    if (mudaLinhaFinal != 1){
        fstream arquivoTemp;
        arquivoTemp.open(nome, ios::binary | ios::out);
        //cout << "salvarquivo: o nome eh " << vetJogador[0].nome << endl;
        for (i=0; i < tam-1; i++){
            arquivoTemp.write((char*) (&vetJogador[i]), sizeof(jogador_string)) << endl;
        }
        if (mudaLinhaFinal == 0){
            //cout << "salvando: " <<vetJogador[i].nome << endl;
          arquivoTemp.write((char*) (&vetJogador[tam-1]), sizeof(jogador_string));
        }
        else{
           arquivoTemp.write((char*) (&vetJogador[tam-1]), sizeof(jogador_string)) << endl ;
        }
        arquivoTemp.close();
    }
}


int criaArquivosOrdenados (string nome){ // quebra arquivos em partes menores e ordena
    int cont = 0, total = 0, i=0;
    jogador_string vetJogador[N];
    char novo[20];
    char nomeOrig[36] = "data_athlete_game.bin";
    int tamanho = retorna_tamanhoOrd(nomeOrig);
    arquivo_binLer.open(nome, ios::binary | ios::in);
    cout << "o tam" << tamanho << endl;
    while(i < tamanho){
        arquivo_binLer.seekp(i); // funcao para posicionar a leitura dos objetos
        arquivo_binLer.read((char*) (&vetJogador[total]), sizeof(jogador_string));
        total++;
        if (total == N){
            cont++;
            cout << "acabei" <<endl;
            //cout << vetJogador[0].nome[0] << endl;
            sprintf(novo, "Temp%d.bin", cont);
            qsort(vetJogador, total);
            salvaArquivo(novo, vetJogador, total, 0);
            total = 0;
            //cout << "chegay no fim de um buffer " << endl;
        }
        i= i + 126; // 126 = tamanho da struct jogador_string
    }
     // */
    
    if (total > 0){
        cout << "total eh " << total << endl;
        cont++;
        sprintf(novo, "Temp%d.bin", cont);
        qsort(vetJogador, total);
        salvaArquivo(novo, vetJogador, total, 0);
    }
    
    arquivo_binLer.close();
    return cont;
}


void preencheBuffer (struct arquivo* arq, int K){
    int posBin = arq->posBin;
    jogador_string registroJgdr;
    if (not (arq->f.is_open())){
        cout << "ta fechado" << endl;
        return;
    }
    cout << "ta aberto" << endl;
    arq->pos = 0;
    arq->MAX = 0;

    for (int i=0; i <K; i++){
        if(posBin <= arq->tamanho){ 
            cout << "a pos eh " << posBin << endl;
            arq->f.seekp(posBin);
            arq->f.read((char*) &registroJgdr, sizeof(jogador_string));
            arq->buffer[arq->MAX] = registroJgdr;
            //cout << "nome eh " << arq->buffer[arq->MAX].nome << endl;
            arq->MAX++;
        }
        else{
            arq->f.close();
        }
        posBin = posBin + 126;
    }
    arq->posBin = posBin; // atualiza a posicao no arquivo binário.
    //for (int j = 0; j < 3; j++){
     //   cout << "nomesss:" << arq->buffer[j].nome << endl;
  //  }
    
}


int procuraMenor(struct arquivo* arq, int numArqs, int K, jogador_string *menor){
    int i, idx = -1;
    //char idUm, idDois;
    char letraUm, letraDois; // comparar todos os primeiros registros 
    for (i=0; i<numArqs; i++){
        if (idx != -1){
            //cout << "comparando " << arq[i].buffer[arq[i].pos].nome << " e " << arq[idx].buffer[arq[idx].pos].nome << endl;
        }
        if (arq[i].pos < arq[i].MAX){ // comparacao de 0  e 3
            if (idx == -1){
                idx = i;
            }
            else{
                letraUm = verificaAspas(arq[i].buffer[arq[i].pos].nome); 
                letraDois = verificaAspas(arq[idx].buffer[arq[idx].pos].nome);
                //cout << "letra dois" << letraDois << endl;
                //idUm = arq[i].buffer[arq[i].pos].id;
                //indDois = arq[idx].buffer[arq[idx].pos].id;
                if (letraUm < letraDois or (letraUm == letraDois and arq[i].buffer[arq[i].pos].id < arq[idx].buffer[arq[idx].pos].id)){
                    idx = i;
                }
            }
        }
    }
    
    if (idx != -1){ // encontrou um menor
        *menor = arq[idx].buffer[arq[idx].pos];
                                //cout << "o menor eh " << menor->nome << endl;
        arq[idx].pos++; // passa para analisar os proximos registros.
        if (arq[idx].pos == arq[idx].MAX){ // percorreu os 3 primeiros registros.
            cout << " binbin:" << arq->posBin << endl;
            preencheBuffer(&arq[idx], K);
        }
        return 1;
    }
    else{
        return 0;
    }
}

void merge(string nome, int numArqs, int K){
    char novo[20];
    char novoNome [50] = "data_athlete_game.bin";
    int i=0;
    //posBin = 0;
    //jogador_string registroJgdr;
    jogador_string *buffer = new jogador_string[K]; // aloca memoria para o buffer;
    //cout << "num: " << numArqs << endl;
    struct arquivo *arq = new arquivo[numArqs];
    for (i=0; i<numArqs; i++){
        sprintf(novo, "Temp%d.bin", i+1);
        cout << "o nome do arq " << novo << endl;
        //fstream arqDois;
        //arqDois.open(novo, ios::binary | ios::in);
        arq[i].f.open(novo, ios::binary | ios::in);
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].tamanho = retorna_tamanhoOrd(novo);
        cout << "o tamanho eh " << arq[i].tamanho << endl;
        arq[i].posBin = 0;
        arq[i].buffer = new jogador_string [K];
        cout << "o numero de arquiv eh " << i << endl;
        preencheBuffer (&arq[i], K);
        
    }
    int qtdBuffer = 0;
    jogador_string menor;
    int quantRegistros = 0;
    bool primeiro = true;
    while (procuraMenor(arq, numArqs, K, &menor) == 1){
        //cout << "ENTREI NO WHILE" << endl;
        buffer[qtdBuffer] = menor;
       // cout << qtdBuffer << ": nome buffer eh " << buffer[qtdBuffer].nome << endl;
        qtdBuffer++;
        if (qtdBuffer == K){
            cout << "entrei no primeiro qtd" << endl;
            salvaOrdenado(novoNome, buffer, K, primeiro);
            primeiro = false;
            qtdBuffer = 0;
            quantRegistros++;
        }
        
    }
    if (qtdBuffer != 0){
        cout << "entrei no 2 qtd" << endl;
        salvaOrdenado(novoNome, buffer, qtdBuffer, primeiro);
    }
    cout << "quant: " << quantRegistros << endl;
/*
    for (i=0; i<numArqs; i++){
        free(arq[i].buffer);
    }
    free(arq);
    free(buffer);
*/
}


void mergeSortExterno(string nome){
    char novo[22] = "data_athlete_game.bin" ;
    
    int numArqs = criaArquivosOrdenados("data_athlete_game.bin");
    //int i;
    int k = ceil(N / ((float)numArqs + 2));
    cout <<"a quantidade de arquivps eh " << numArqs << endl;
    cout <<"a quantidade de K eh " << k << endl;
    //remove(nome);
    cout << "tamanho= " << retorna_tamanhoOrd(novo);
    merge("data_athlete_game.bin", numArqs, k);
    //for (i =0; i<numArqs; i++){
     //   sprintf(novo, "temp%d.txt", i+1);
        //remove (novo);
  //  }
    cout << "cabou" << endl;
}



int main() {

	conversao(); // Chamar p/ converter arquivo csv -> bin
    mergeSortExterno("data_athlete_game.bin");
    //criaArquivosOrdenados ("data_athlete_game.bin");
	/*
	
    cout << "Dados de atletas - arqBinario a Opcao:\n" // inicio menu
         << "i - inserir atleta em nova posicao\n"
         << "v - visualizar os registros entre 2 posicoes\n"
         << "a - alterar dados de um registro em uma posicao\n"
		 << "p - imprimir todos os registros\n"
         << "t - trocar registros de posicao\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
	jogador_string meuJgdr;
	int pos, pos1, pos2;
    cin >> opcaoDoMenu;
    char id_char[6];
    string *dados;
    dados = new string[6];
 
    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' :
                cout << "inserir atleta: digite uma posicao " << endl; // inserir atleta em uma posicao especifica
                cin >> id_char; // posicao
                pos = atoi (id_char); // converte char pra int
				cout << "inserir: nome, time, jogos, ano, temporada." << endl;
				dados[0] = strcpy(meuJgdr.id, id_char);
                for(int j = 1; j < 6; j++){
					while(getline(cin, dados[j]))
					if(dados[j] != ""){
						break;
					}
				}
                meuJgdr = escritor(dados);
				inserir_atleta(meuJgdr, pos); // falta implementar a funcao de adicionar entre duas posicoes
                break;
 
            case 'v' :
                cout << "digite duas posicoes para listar os registros contidos " << endl;
                cin >> pos1;
                cin >> pos2;
                listar_atletas(pos1, pos2);
                break;
 
            case 'a' :
                cout << "digite a posicao cujo registro vai ser alterado";
                cin >> id_char;
                pos = atoi (id_char); // converter para inteiro;
                cout << "inserir NOVOS: id, nome, time, jogos, ano, temporada." << endl;
                for(int j = 0; j < 6; j++){
	                while(getline(cin, dados[j])){
						if(dados[j] != ""){
							break;
						}
					}
				}
                meuJgdr = escritor(dados);
                alterar_registro(meuJgdr, pos);
                break;
            case 'p' :
                imprimir_registros();
                break;
            case 't' :
                cout << "digite duas posicoes para trocar os registros de posicao";
                cin >> pos1;
                cin >> pos2;
                trocar_atletas(pos1, pos2);
                break;
            case 's' : // não faz nada
                break;
 
            default:
                cout << "Opção invalida!" << endl;
                break;
 
        }
         cout << "Dados de atletas - arqBinario a Opcao:\n"
         << "i - inserir atleta em nova posicao\n"
         << "v - visualizar os registros entre 2 posicoes\n"
         << "a - alterar dados de um registro em uma posicao\n"
		 << "p - imprimir todos os registros\n"
         << "t - trocar registros de posicao\n"
         << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }
    delete[] dados;
    return 0;
    */
}
