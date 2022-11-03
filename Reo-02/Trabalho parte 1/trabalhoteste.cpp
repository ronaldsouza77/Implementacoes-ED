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
using namespace std;

struct jogador_string{
	//Id,Name,Team,Games,Year,Season
	//long id, ano;
	//char nome[65],time[20],jogos[20],secao[10];
	char id[6],nome[65],time[20],jogos[20],ano[4],secao[10];
};

jogador_string escritor(string dados[]){
	jogador_string estrutura;
	
	strcpy(estrutura.id,dados[0].c_str());
	cout << estrutura.id << " ";
		
	strcpy(estrutura.nome,dados[1].c_str());
	cout << estrutura.nome << " ";
		
	strcpy(estrutura.time,dados[2].c_str());
	cout << estrutura.time << " ";
		
	strcpy(estrutura.jogos,dados[3].c_str());
	cout << estrutura.jogos << " ";
		
	strcpy(estrutura.ano,dados[4].c_str());
	cout << estrutura.ano << " ";
		
	strcpy(estrutura.secao,dados[5].c_str());
	cout << estrutura.secao << " ";
		
	return estrutura;
}

int main() {

	ifstream arquivo_csv("data_athlete_game.csv");
	ofstream arquivo_bin("data_athlete_game.bin", ios::out | ios:: app |ios::binary);
	
	string Id,Name,Team,Games,Year,Season;
	
	getline(arquivo_csv, Id , ',');
	getline(arquivo_csv, Name, ',');
	getline(arquivo_csv, Team, ',');
	getline(arquivo_csv, Games, ',');
	getline(arquivo_csv, Year, ',');
	getline(arquivo_csv, Season, ',');
	
	string *dados;
	jogador_string estrutura;
	long contador_dados = 0;
	//271117
	
	while(arquivo_csv.good()){
		dados = new string[6];
		for(int j = 0; j < 6; j++){
			getline(arquivo_csv,dados[j],',');
		}
		estrutura = escritor(dados);
		arquivo_bin.write((char *)&estrutura,sizeof(jogador_string));
		
		contador_dados++;
		delete[] dados;
	}
	cout << endl << contador_dados << endl;
	arquivo_csv.close();
	arquivo_bin.close();
	return 0;
}
