/*
Grupo 4:
 - Beatriz Fernandes Teixeira
 - Dênis de Souza Cordeiro
 - Ronald de Souza Galdino

----------- data_athlete_game.7z ------------

*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

ifstream arquivo_csv("data_athlete_game copy.csv");
fstream arquivo_bin("data_athlete_game.bin", ios::in | ios::binary |ios::out |ios::trunc);

struct jogador_string{
	//Id,Name,Team,Games,Year,Season
	char id[6],nome[65],time[20],jogos[20],ano[4],temporada[10];
};

// Função de conversão string p/ char
jogador_string escritor(string dados[]){
	
	jogador_string estrutura;
	
	strcpy(estrutura.id,dados[0].c_str());
		
	strcpy(estrutura.nome,dados[1].c_str());

	strcpy(estrutura.time,dados[2].c_str());
		
	strcpy(estrutura.jogos,dados[3].c_str());
		
	strcpy(estrutura.ano,dados[4].c_str());
		
	strcpy(estrutura.temporada,dados[5].c_str());

	return estrutura;
}

void conversao (){ // funcao para converter csv para binario
	string *dados;
	jogador_string estrutura;
	//271117
	dados = new string[6];
	string line ="";
	arquivo_csv.seekg(31); // começar 31 bytes a frente para nao ler a descrição dos campos
	while(getline(arquivo_csv, line)){
		//cout << "a linha eh " << line << endl;
			stringstream inputstring (line);
			for(int j = 0; j < 6; j++){
				getline(inputstring, dados[j],',');
			}
			estrutura = escritor(dados);
			arquivo_bin.write((char *)&estrutura,sizeof(jogador_string)) << endl;
			line = "";
	
	}
	arquivo_csv.close();
}

int retorna_tamanho() {
	int tam;
	arquivo_bin.seekg (0, ios::end);
	tam = arquivo_bin.tellg();
	arquivo_bin.seekg (0, ios::beg);
	return tam;
}


// Função para imprensão de resgarquivo_bintros
void imprimir_registros(){
	jogador_string objts_jgd;
	int i=0;
	while(i<retorna_tamanho()){
		//cout << "a posicao eh " << i << endl;
		arquivo_bin.seekg(i); // funcao para posicionar a leitura dos objetos
		arquivo_bin.read((char*) (&objts_jgd), sizeof(jogador_string));
		cout << "Id: "<<objts_jgd.id << " Nome:"<< " " << objts_jgd.nome  
		<< "\n" << "Jogos:"<<" " << objts_jgd.jogos << "\n" << "Time:" 
		<<" " << objts_jgd.time << "\n" << "Temporada:" << " " << objts_jgd.temporada << " Ano:" << " " << objts_jgd.ano << endl;
		cout << endl;
		i= i + 126; // 126 = tamanho da struct jogador_string
	}
}

// Função que altera os dados de um registro
void alterar_registro(jogador_string atleta, int pos){
	arquivo_bin.seekg(pos*(sizeof(jogador_string)+1));
	cout << "alterando posicao " << pos*(sizeof(jogador_string)+1) << endl;
	arquivo_bin.write((char*) (&atleta), sizeof(jogador_string)+1); // substituindo o registro com valores de campo alterados.
}

// Função que lista os atletas
void listar_atletas(int pos1, int pos2){
	int pos_inicio = (sizeof(jogador_string)+1)*(pos1+2);
	jogador_string objts_jgd;
	int tam = pos2 - pos1;
	if (tam<0) tam = tam*(-1);
	int i=1;
	pos1= pos_inicio;
	while (i < tam){
		arquivo_bin.seekg(pos1); 
		arquivo_bin.read((char*) (&objts_jgd), sizeof(jogador_string));
		cout << "Id: "<<objts_jgd.id << " Nome:"<< " " << objts_jgd.nome  
		<<" " << objts_jgd.time << "\n" << "Temporada:" << " " << objts_jgd.temporada << " Ano:" << " " << objts_jgd.ano << endl;
	cout << endl;
	pos1 = pos_inicio + ( (sizeof(jogador_string)+1))*i;
	i++;
	}

}

// Função para trocar os atletas
void trocar_atletas(int pos1, int pos2){
	int pos1_bin = pos1*(sizeof(jogador_string)+1); // 126*5=630
	int pos2_bin = pos2*(sizeof(jogador_string)+1);
	jogador_string pos1_atlet, pos2_atlet; 
	arquivo_bin.seekg(pos1_bin);
	arquivo_bin.read((char*)&pos1_atlet, sizeof(jogador_string));
	arquivo_bin.seekg(pos2_bin);
	arquivo_bin.read((char*)&pos2_atlet, sizeof(jogador_string));
	// trocar
	arquivo_bin.seekg(pos1_bin); // buscar a posicao 1
	arquivo_bin.write((char*)&pos2_atlet, sizeof(jogador_string));
	arquivo_bin.seekg(pos2_bin); // buscar a posicao 2
	arquivo_bin.write((char*)&pos1_atlet, sizeof(jogador_string));
  cout << "Trocado com sucesso!" << endl;
}
void inserir_atleta(jogador_string meuJgdr, long long pos){
	pos = pos*(sizeof(jogador_string) + 1);
	long long i = 2;
	long long pos_anterior = 0;
	jogador_string copia;
	//inserir na ultima posicao
	arquivo_bin.seekg(retorna_tamanho());
	arquivo_bin.write((char*) &meuJgdr, sizeof(jogador_string)) << endl;
	while(retorna_tamanho()-(sizeof(jogador_string)*i +i)+sizeof(jogador_string)+1 != pos){
	// ir copiando e colando os arquivos de trás para frente
		arquivo_bin.seekg(retorna_tamanho()-(sizeof(jogador_string)*i +i)); // penultima posicao
		arquivo_bin.read((char*) &copia, sizeof(jogador_string));
		arquivo_bin.seekg(retorna_tamanho()-pos_anterior);
		arquivo_bin.write((char*) &copia, sizeof(jogador_string)) << endl;
		arquivo_bin.seekg(retorna_tamanho()-((sizeof(jogador_string)*i +i)));
		arquivo_bin.write((char*) &meuJgdr, sizeof(jogador_string)) << endl;
		pos_anterior = sizeof(jogador_string)*i +i;
		i++;
	}
    arquivo_bin.seekg(0);

}

int main() {
	conversao(); // Chamar p/ converter arquivo csv -> bin

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
				cout << "Digite duas posicoes para listar os registros contidos: ";
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
					while(getline(cin, dados[j]))
					if(dados[j] != ""){
						break;
					}
				}

				meuJgdr = escritor(dados);
				alterar_registro(meuJgdr, pos+1);
				break;
			case 'p' :
				imprimir_registros();
				break;
			case 't' :
				cout << "Digite duas posicoes para trocar os registros de posicao: ";
				cin >> pos1;
				cin >> pos2;
				trocar_atletas(pos1+1, pos2+1);
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

	arquivo_bin.close();
	delete[] dados;
	return 0;
}
