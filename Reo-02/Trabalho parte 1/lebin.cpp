#include <iostream>
#include <fstream>
using namespace std;

struct jogador_string{
	//Id,Name,Team,Games,Year,Season
	//int id, ano;
	//char nome[65],time[20],jogos[20],secao[10];
	char id[6],nome[65],time[20],jogos[20],ano[4],temporada[10];
};


int main(){
	ifstream arquivo_bin("data_athlete_game.bin",ios::binary);
	
	jogador_string objts_jgd;
	int i=0;
	arquivo_bin.seekg(31);
	while(arquivo_bin){
		arquivo_bin.seekg(i); // funcao para posicionar a leitura dos objetos
		arquivo_bin.read((char*) (&objts_jgd), sizeof(jogador_string));
		cout << "Id: "<<objts_jgd.id << " Nome:"<< " " << objts_jgd.nome  
		<< "\n" << "Jogos:"<<" " << objts_jgd.jogos << "\n" << "Time:" 
		<<" " << objts_jgd.time << "\n" << "Temporada:" << " " << objts_jgd.temporada << " Ano:" << " " << objts_jgd.ano << endl;
		cout << endl;
		i= i + 126; // 126 = tamanho da struct jogador_s
	}
	/*jogador_string estrutura;
		
	while(arquivo_bin.read((char*)&estrutura, sizeof(jogador_string))){
	cout << estrutura.id << " " << estrutura.nome << " " << estrutura.time
	 << " " << estrutura.jogos << " " << estrutura.ano << " " << estrutura.secao << " ";
	}*/
	arquivo_bin.close();
	
	return 0;
}
