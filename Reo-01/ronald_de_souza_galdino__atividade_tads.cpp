#include <iostream>
#include <string>
using namespace std;

/*
 * Nome: Ronald de Souza Galdino
 * Turma: 14a
 * enunciado 05
 * Obs:Como no foi especificado quantos atletas e patrocinadores podem 
 * ser cadastrados para cada atividade,defini um limite de 100 atletas e
 * 50 patrocinadores para cada uma.
*/
struct atletas{

	string nacionalidade;
	float altura;
	float peso;
	string nome;
	string dt_nascimento;
	
};

struct patrocinadores{
	
	string nome;
	string setor;
	string pais_sede;
	string valor_investido;
	string inicio_contrato;
	string prazo_contrato;
};

struct atividade_especifica{
	
	string nome_geral;
	string atividade_esp;
	string data;
	string hora;
	atletas Atletas[100];
	patrocinadores Patrocinio[50];
};
	
class esporte{
	private:
		atividade_especifica *atividade;
		int qtd_esportes;
		int qtd_atletas_esporte;
		int qtd_patrocinadores_esporte;
		
	public:
		esporte(int tesportes, int tat_esporte, int tpa_esporte);
		~esporte();
		void cadastrar_esporte();
		int busca_esporte(string esporte_buscado);
		int busca_informacoes_atletas(string busca,int posicao);
		void listar_dados_atletas(int posicao, int pos);
		
		int busca_informacoes_patrocinadores(string busca,int posicao);
		void listar_dados_patrocinadores(int posicao, int pos);
};

esporte::esporte(int tesportes, int tat_esporte, int tpa_esporte){
	qtd_esportes = tesportes;
	qtd_atletas_esporte = tat_esporte;
	qtd_patrocinadores_esporte = tpa_esporte;
	atividade = new atividade_especifica[qtd_esportes];
	cout << endl << "Alocado!" << endl;
}

esporte::~esporte(){
	delete[] atividade;
	qtd_esportes = 0;
	qtd_atletas_esporte = 0;
	qtd_patrocinadores_esporte = 0;
	cout << endl << "Desalocado!" << endl;
}

void esporte::cadastrar_esporte(){
	for (int i = 0; i < qtd_esportes; i++){
		cout << "Cadastrar esporte" << endl;
		cout << "Nome do esporte:";
		cin. ignore();
		getline(cin,atividade[i].nome_geral);
		cout << endl;
		cout << "Nome da atividade:";
		getline(cin,atividade[i].atividade_esp);
		cin. ignore ( 0 );
		cout << endl;
		cout << "Dia(ex: 10/12/2022):";
		cin >> atividade[i].data;
		cout << endl;
		cout << "Hora(ex: 02:30):";
		cin >> atividade[i].hora;
		cout << endl;
		int x = 0; 
		while( x < qtd_atletas_esporte and x < 100){
			cout << "Insira os dados dos atletas desta atividade!" << endl << endl;
			cout << "Atleta" << x+1 << ":" << endl;
			cout << "Nacionalidade:";
			cin.ignore();
			getline(cin,atividade[i].Atletas[x].nacionalidade);
			cout << endl;
			cout << "Altura(ex: 1.70):";
			cin >> atividade[i].Atletas[x].altura;
			cout << endl;
			cout << "Peso(ex: 58.4):";
			cin >> atividade[i].Atletas[x].peso;
			cout << endl;
			cout << "Nome:";
			cin.ignore();
			getline(cin,atividade[i].Atletas[x].nome);
			cout << endl;
			cout << "Data de nascimento(ex: 10/12/2022):";
			cin >> atividade[i].Atletas[x].dt_nascimento;
			cout << endl;
			x++;
		}
		for( int y = 0; y < qtd_patrocinadores_esporte and y < 50; y++){
			cout << "Insira os dados dos patrocinadores" << endl << endl;
			cout << "Patrocinador" << y+1 << ":" << endl;
			cout << "Nome:";
			cin.ignore();
			getline(cin,atividade[i].Patrocinio[y].nome);
			cout << endl;
			cout << "Setor:";
			getline(cin,atividade[i].Patrocinio[y].setor);
			cin. ignore ( 0 );
			cout << endl;
			cout << "Pais sede:";
			getline(cin,atividade[i].Patrocinio[y].pais_sede);
			cin. ignore ( 0 );
			cout << endl;
			cout << "Valor investido:";
			cin >> atividade[i].Patrocinio[y].valor_investido;
			cout << endl;
			cout << "Prazo do contrato:";
			cin.ignore();
			getline(cin,atividade[i].Patrocinio[y].prazo_contrato);
			cout << endl;
			cout << "Inicio do contrato(ex:20/10/2022):";
			cin >> atividade[i].Patrocinio[y].inicio_contrato;
			cout << endl;
		}
	}		
		
}

int esporte::busca_esporte(string esporte_buscado){
	for ( int i = 0 ; i < qtd_esportes; i++){
		if (esporte_buscado == atividade[i].nome_geral){
			return i;
		}
	}
	return -1;
	
}

int esporte::busca_informacoes_atletas(string busca,int posicao){
		for ( int i = 0 ; i < qtd_atletas_esporte; i++){
			if (busca == atividade[posicao].Atletas[i].nome){
				return  i;
			}
	}
	return -1;
}

void esporte::listar_dados_atletas(int posicao, int pos){
	cout << "Atleta" << ":" << endl;
	cout << "Nacionalidade:";
	cout << atividade[posicao].Atletas[pos].nacionalidade << endl;
	cout << "Altura:";
	cout << atividade[posicao].Atletas[pos].altura << endl;
	cout << "Peso:";
	cout << atividade[posicao].Atletas[pos].peso << endl;
	cout << "Nome:";
	cout << atividade[posicao].Atletas[pos].nome << endl;
	cout << "Data de nascimento:";
	cout << atividade[posicao].Atletas[pos].dt_nascimento << endl << endl;
	
}

int esporte:: busca_informacoes_patrocinadores(string busca,int posicao){
	for ( int i = 0 ; i < qtd_patrocinadores_esporte; i++){
		if (busca == atividade[posicao].Patrocinio[i].nome){
			return i;
		}
	}
	return -1;
}

void esporte::listar_dados_patrocinadores(int posicao, int pos){
	cout << "Patrocinador" << ":" << endl;
	cout << "Nome:";
	cout << atividade[posicao].Patrocinio[pos].nome << endl;
	cout << "Setor:";
	cout << atividade[posicao].Patrocinio[pos].setor << endl;
	cout << "Pais sede:";
	cout << atividade[posicao].Patrocinio[pos].pais_sede << endl;
	cout << "Valor investido:";
	cout << atividade[posicao].Patrocinio[pos].valor_investido << endl;
	cout << "Inicio do contrato:";
	cout << atividade[posicao].Patrocinio[pos].inicio_contrato << endl;
	cout << "Prazo do contrato:";
	cout << atividade[posicao].Patrocinio[pos].prazo_contrato << endl << endl;
	
}

class gerais_atletas{
	private:
		atletas *Atletas;
		int qtd_atletas;
	
	public:
		gerais_atletas(int tatletas);
		~gerais_atletas();
		void cadastrar_atletas();
		int buscar_informacoesatletas(string busca);
		void listar_dados_atletas(int posicao);
	
};

gerais_atletas::gerais_atletas(int tatletas){
	qtd_atletas = tatletas;
	Atletas = new atletas[qtd_atletas];
	cout << endl << "Alocado!" << endl;
}

gerais_atletas::~gerais_atletas(){
	delete[] Atletas;
	qtd_atletas = 0;
	cout << endl << "Desalocado!" << endl;
}
	
void gerais_atletas::cadastrar_atletas(){
	if (qtd_atletas >= 0){
		cout << "Insira os dados dos atletas desta atividade!" << endl;
	}
	int x = 0; 
	while( x < qtd_atletas){
		cout << "Atleta" << x+1 << ":" << endl;
		cout << "Nacionalidade:";
		cin.ignore();
		getline(cin, Atletas[x].nacionalidade);
		cout << endl;
		cout << "Altura(ex: 1.70):";
		cin >> Atletas[x].altura;
		cout << endl;
		cout << "Peso(ex: 58.4):";
		cin >> Atletas[x].peso;
		cout << endl;
		cout << "Nome:";
		cin.ignore();
		getline(cin,Atletas[x].nome);
		cout << endl;
		cout << "Data de nascimento(ex: 10/12/2022):";
		cin >> Atletas[x].dt_nascimento;
		cout << endl;
		x++;
	}
}

int gerais_atletas:: buscar_informacoesatletas(string busca){
	int posicao= -1;
	for ( int i = 0 ; i < qtd_atletas; i++){
		if (busca == Atletas[i].nome){
			posicao = i;
			i = qtd_atletas;
		}
	}
	return posicao;
}

void gerais_atletas::listar_dados_atletas(int posicao){
	cout << "Atleta" << ":" << endl;
	cout << "Nacionalidade:";
	cout << Atletas[posicao].nacionalidade << endl;
	cout << "Altura:";
	cout << Atletas[posicao].altura << endl;
	cout << "Peso:";
	cout << Atletas[posicao].peso << endl;
	cout << "Nome:";
	cout << Atletas[posicao].nome << endl;
	cout << "Data de nascimento:";
	cout << Atletas[posicao].dt_nascimento << endl << endl;
}

class gerais_patrocinadores{
	private:
		patrocinadores *Patrocinio;
		int qtd_patrocinadores;
	
	public:
		gerais_patrocinadores(int tpatrocinadores);
		~gerais_patrocinadores();
		void cadastrar_patrocinadores();
		int buscar_informacoespatrocinadores(string busca);
		void listar_dados_patrocinadores(int posicao);
};

gerais_patrocinadores::gerais_patrocinadores(int tpatrocinadores){
	qtd_patrocinadores = tpatrocinadores;
	Patrocinio = new patrocinadores[qtd_patrocinadores];
	cout << endl << "Alocado!" << endl;
}

gerais_patrocinadores::~gerais_patrocinadores(){
	delete[] Patrocinio;
	qtd_patrocinadores = 0;
	cout << endl << "Desalocado!" << endl;
}

void gerais_patrocinadores::cadastrar_patrocinadores(){
	if ( qtd_patrocinadores >= 0){
		cout << "Insira os dados dos patrocinadores" << endl;
	}
	for( int y = 0; y < qtd_patrocinadores; y++){
		cout << "Patrocinador" << y+1 << ":" << endl;
		cout << "Nome:";
		cin.ignore();
		getline(cin,Patrocinio[y].nome);
		cout << endl;
		cout << "Setor:";
		getline(cin,Patrocinio[y].setor);
		cin. ignore ( 0  );
		cout << endl;
		cout << "Pais sede:";
		getline(cin,Patrocinio[y].pais_sede);
		cin. ignore ( 0  );
		cout << endl;
		cout << "Valor investido:";
		cin >> Patrocinio[y].valor_investido;
		cout << endl;
		cout << "Prazo do contrato:";
		cin.ignore();
		getline(cin,Patrocinio[y].prazo_contrato);
		cout << endl;
		cout << "Inicio do contrato(ex:20/10/2022):";
		cin >> Patrocinio[y].inicio_contrato;
		cout << endl;
	}
}

int gerais_patrocinadores:: buscar_informacoespatrocinadores(string busca){
	int posicao = -1;
	for ( int i = 0 ; i < qtd_patrocinadores; i++){
		if (busca == Patrocinio[i].nome){
			posicao = i;
			i = qtd_patrocinadores;
		}
	}
	return posicao;
}

void gerais_patrocinadores::listar_dados_patrocinadores(int posicao){
	cout << "Patrocinador" << ":" << endl;
	cout << "Nome:";
	cout << Patrocinio[posicao].nome << endl;
	cout << "Setor:";
	cout << Patrocinio[posicao].setor << endl;
	cout << "Pais sede:";
	cout << Patrocinio[posicao].pais_sede << endl;
	cout << "Valor investido:";
	cout << Patrocinio[posicao].valor_investido << endl;
	cout << "Inicio do contrato:";
	cout << Patrocinio[posicao].inicio_contrato << endl;
	cout << "Prazo do contrato:";
	cout << Patrocinio[posicao].prazo_contrato << endl << endl;
}

void menu(){
	cout << "1-cadastrar esporte" << endl;
	cout << "2-cadastrar atletas gerais" << endl;
	cout << "3-cadastrar patrocinadores gerais" << endl;
	cout << "4-buscar dados de atletas" << endl;
	cout << "5-buscar dados de patrocinadores" << endl;
	cout << "6-sair" << endl;
}

	int main (){
		
	int qtdes,qtdat,qtdpa;
	
	int qtdat_esporte,qtdpa_esporte;
	
	esporte *olimpiada;
	gerais_atletas *olimpiada_atletas;
	gerais_patrocinadores *olimpiada_patrocinadores;
	
	bool aloc1 = false,aloc2 = false,aloc3 = false;
	
	int procedimento,tipo_busca;
	
	string busca,esporte_buscado;
	
	do{
		cout<<"Qual procedimento deseja realizar?"<<endl;
		
		menu();
		
		cin >> procedimento;
		
		if(procedimento == 1){
	
			cout << "Quantos esportes deseja cadastrar?" << endl;
			cin >> qtdes;
	
			cout << "Quantos atletas por esporte deseja cadastrar?" << endl;
			cin >> qtdat_esporte;
	
			cout << "Quantos patrocinadores por esporte deseja cadastrar?" << endl;
			cin >> qtdpa_esporte;
			olimpiada = new esporte (qtdes,qtdat_esporte,qtdpa_esporte);
			aloc1 = true;
			olimpiada-> cadastrar_esporte();
		}
		else if(procedimento == 2){
			cout << "Quantos aletas gerais deseja cadastrar?" << endl;
			cin >> qtdat;
			olimpiada_atletas = new gerais_atletas(qtdat);
			aloc2 = true;
			olimpiada_atletas-> cadastrar_atletas();
		}
		else if(procedimento == 3){
			cout << "Quantos patrocinadores gerais deseja cadastrar?" << endl;
			cin >> qtdpa;
			olimpiada_patrocinadores = new gerais_patrocinadores (qtdpa);
			aloc3 = true;
			olimpiada_patrocinadores-> cadastrar_patrocinadores();
		}
		else if(procedimento == 4){
			cout << "Voce deseja buscar atletas de um esporte especifico ou gerais?" << endl;
			cout << "1-De um esporte especifico" << endl;
			cout << "2-Gerais" << endl;
			cin >> tipo_busca;
			
			if(tipo_busca == 1){
				int posicao = -1;
				cout << "De qual esporte voce deseja buscar atletas?" << endl;
				cin.ignore();
				getline(cin, esporte_buscado);
				posicao = olimpiada->busca_esporte(esporte_buscado);
				if (posicao != -1){
					int pos = -1;
					cout << "De qual atleta voce deseja buscar dados?" << endl;
					getline(cin, busca);
					cin. ignore ( 0 );
					pos = olimpiada-> busca_informacoes_atletas(busca,posicao);
					if (pos == -1){
						cout << "Atleta nao inscrito" << endl;
					}
					else{
						olimpiada-> listar_dados_atletas(posicao,pos);
					}
				}
				else{
					cout << "Esporte nao encontrado" << endl;
				}
			}
			else if(tipo_busca == 2){
				cout << "De qual atleta voce deseja buscar dados?" << endl;
				cin.ignore();
				getline(cin, busca);
				int posicao = -1;;
				posicao = olimpiada_atletas-> buscar_informacoesatletas(busca);
				if(posicao != -1){
					olimpiada_atletas-> listar_dados_atletas(posicao);
				}
				else{
					cout << "Atleta nao inscrito" << endl;
				}
			}
		}
		else if(procedimento == 5){
			cout << "Voce deseja buscar patrocinadores de um esporte especifico ou gerais?" << endl;
			cout << "1-De um esporte especifico" << endl;
			cout << "2-Gerais" << endl;
			cin >> tipo_busca;
			
			if(tipo_busca == 1){
				int posicao = -1;
				cout << "De qual esporte voce deseja buscar patrocinadores?" << endl;
				cin.ignore();
				getline(cin, esporte_buscado);
				posicao = olimpiada->busca_esporte(esporte_buscado);
				if (posicao != -1){
					int pos = -1;
					cout << "De qual patrocinador voce deseja buscar dados?" << endl;
					getline(cin, busca);
					cin. ignore ( 0 );
					pos = olimpiada-> busca_informacoes_patrocinadores(busca,posicao);
					if (pos == -1){
						cout << "Patrocinador nao encontrado" << endl;
					}
					else{
						olimpiada-> listar_dados_patrocinadores(posicao,pos);
					}
				}
				else{
					cout << "Esporte nao encontrado" << endl;
				}
			}
			else if(tipo_busca == 2){
				cout << "De qual patrocinador voce deseja buscar dados?" << endl;
				cin.ignore();
				getline(cin, busca);
				int posicao = -1;
				posicao = olimpiada_patrocinadores-> buscar_informacoespatrocinadores(busca);
				if(posicao != -1){
					olimpiada_patrocinadores-> listar_dados_patrocinadores(posicao);
				}
				else{
					cout << "Patrocinador nao encontrado" << endl;
				}
			}
		}
	}while(procedimento != 6);
	
	if (aloc1 == true) olimpiada-> ~esporte();
	if (aloc2 == true) olimpiada_atletas-> ~gerais_atletas();
	if (aloc3 == true) olimpiada_patrocinadores-> ~gerais_patrocinadores();
	/*if (aloc1 == true) delete[]olimpiada;
	if (aloc2 == true) delete[] olimpiada_atletas;
	if (aloc3 == true) delete[]olimpiada_patrocinadores;*/


	return 0;
}
