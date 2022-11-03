#include <iostream>
#include <string>

using namespace std;

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
		atletas *Atletas;
		patrocinadores *Patrocinio;
		int qtd_esportes;
		int qtd_atletas;
		int qtd_patrocinadores;
		int qtd_atletas_esporte;
		int qtd_patrocinadores_esporte;
		
	public:
		esporte(int tesportes, int tatletas, int tpatrocinadores, int tat_esporte, int tpa_esporte);
		~esporte();
		void cadastrar_esporte();
		void cadastrar_atletas();
		void cadastrar_patrocinadores();
		
		int busca_esporte(string esporte_buscado, int posicao);
		int busca_informacoes_atletas(string busca,int posicao);
		void listar_dados_atletas(int posicao, int pos);
		
		int buscar_informacoesatletas(string busca);
		void listar_dados_atletas(int posicao);
		
		int busca_informacoes_patrocinadores(string busca,int posicao);
		void listar_dados_patrocinadores(int posicao, int pos);
		
		int buscar_informacoespatrocinadores(string busca);
		void listar_dados_patrocinadores(int posicao);
		
		void listar_dados();
};

esporte::esporte(int tesportes, int tatletas, int tpatrocinadores, int tat_esporte, int tpa_esporte){
	qtd_esportes = tesportes;
	qtd_atletas = tatletas;
	qtd_patrocinadores = tpatrocinadores;
	qtd_atletas_esporte = tat_esporte;
	qtd_patrocinadores_esporte = tpa_esporte;
	atividade = new atividade_especifica[qtd_esportes];
	Atletas = new atletas[qtd_atletas];
	Patrocinio = new patrocinadores[qtd_patrocinadores];
	cout << endl << "Alocado!" << endl;
}

esporte::~esporte(){
	delete[] atividade;
	delete[] Atletas;
	delete[] Patrocinio;
	qtd_esportes = 0;
	qtd_atletas = 0;
	qtd_patrocinadores = 0;
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
		//cin. ignore ( 0 );
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
		if (qtd_atletas_esporte >= 0){
			cout << "Insira os dados dos atletas desta atividade!" << endl;
		}
		int x = 0; 
		while( x < qtd_atletas_esporte and x < 100){
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
		
		if ( qtd_patrocinadores_esporte >= 0){
			cout << "Insira os dados dos patrocinadores" << endl;
		}
		for( int y = 0; y < qtd_patrocinadores_esporte and y < 50; y++){
			cout << "Patrocinador" << y+1 << ":" << endl;
			cout << "Nome:";
			cin.ignore();
			getline(cin,atividade[i].Patrocinio[y].nome);
			//cin. ignore ( 0 );
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
void esporte::cadastrar_atletas(){
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
void esporte::cadastrar_patrocinadores(){
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
int esporte::busca_esporte(string esporte_buscado, int posicao){
	for ( int i = 0 ; i < qtd_esportes; i++){
		if (esporte_buscado == atividade[i].nome_geral){
			posicao = i;
		}
	}
	return posicao;
	
}
int esporte::busca_informacoes_atletas(string busca,int posicao){
	for ( int i = 0 ; i < qtd_atletas_esporte; i++){
		if (busca == atividade[posicao].Atletas[i].nome){
			posicao = i;
		}
	}
	return posicao;
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
int esporte:: buscar_informacoesatletas(string busca){
	int posicao= -1;
	for ( int i = 0 ; i < qtd_atletas; i++){
		if (busca == Atletas[i].nome){
			posicao = i;
		}
	}
	return posicao;
}
void esporte::listar_dados_atletas(int posicao){
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

int esporte:: busca_informacoes_patrocinadores(string busca,int posicao){
	for ( int i = 0 ; i < qtd_patrocinadores_esporte; i++){
		if (busca == atividade[posicao].Patrocinio[i].nome){
			posicao = i;
		}
	}
	return posicao;
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
int esporte:: buscar_informacoespatrocinadores(string busca){
	int posicao = -1;
	for ( int i = 0 ; i < qtd_patrocinadores; i++){
		if (busca == Patrocinio[i].nome){
			posicao = i;
		}
	}
	return posicao;
}
void esporte::listar_dados_patrocinadores(int posicao){
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
	
void esporte::listar_dados(){
	for (int i = 0; i < qtd_esportes; i++){
		cout << endl;
		cout << "Nome do esporte:";
		cout <<atividade[i].nome_geral << endl;
		cout << "Nome da atividade:";
		cout << atividade[i].atividade_esp << endl;
		cout << "Dia(ex 10/12/2022):";
		cout << atividade[i].data << endl;
		cout << "Hora(ex 02:30):";
		cout << atividade[i].hora << endl << endl;
		if ( qtd_atletas_esporte >= 0){
			cout << "Atletas incritos:" << endl;
		}
		for( int x = 0; x < qtd_atletas_esporte; x++){
			cout << "Atleta" << x+1 << ":" << endl;
			cout << "Nacionalidade:";
			cout << atividade[i].Atletas[x].nacionalidade << endl;
			cout << "Altura:";
			cout << atividade[i].Atletas[x].altura << endl;
			cout << "Peso:";
			cout << atividade[i].Atletas[x].peso << endl;
			cout << "Nome:";
			cout << atividade[i].Atletas[x].nome << endl;
			cout << "Data de nascimento:";
			cout << atividade[i].Atletas[x].dt_nascimento << endl << endl;
		}
		if ( qtd_patrocinadores_esporte >=0){
			cout << "Patrocinadores:" << endl;
		}
		for( int y = 0; y < qtd_patrocinadores_esporte; y++){
			cout << "Patrocinador" << y+1 << ":" << endl;
			cout << "Nome:";
			cout << atividade[i].Patrocinio[y].nome << endl;
			cout << "Setor:";
			cout << atividade[i].Patrocinio[y].setor << endl;
			cout << "Pais sede:";
			cout << atividade[i].Patrocinio[y].pais_sede << endl;
			cout << "Valor investido:";
			cout << atividade[i].Patrocinio[y].valor_investido << endl;
			cout << "Inicio do contrato:";
			cout << atividade[i].Patrocinio[y].inicio_contrato << endl;
			cout << "Prazo do contrato:";
			cout << atividade[i].Patrocinio[y].prazo_contrato << endl << endl;
		}
	}
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
	
	int procedimento,tipo_busca;
	
	string busca,esporte_buscado;
	
	do{
		cout<<"Qual procedimento deseja realizar?"<<endl;
		
		menu();
		
		cin >> procedimento;
		
		if(procedimento == 1){
	
			cout << "Quantos esportes deseja cadastrar?" << endl;
			cin >> qtdes;
	
			cout << "Quantos aletas por esporte deseja cadastrar?" << endl;
			cin >> qtdat_esporte;
	
			cout << "Quantos patrocinadores por esporte deseja cadastrar?" << endl;
			cin >> qtdpa_esporte;
			olimpiada = new esporte (qtdes,0,0,qtdat_esporte,qtdpa_esporte);
			olimpiada-> cadastrar_esporte();
			olimpiada-> listar_dados();
		}
		else if(procedimento == 2){
			cout << "Quantos aletas gerais deseja cadastrar?" << endl;
			cin >> qtdat;
			olimpiada = new esporte (0,qtdat,0,0,0);
			olimpiada-> cadastrar_atletas();
		}
		else if(procedimento == 3){
			cout << "Quantos patrocinadores gerais deseja cadastrar?" << endl;
			cin >> qtdpa;
			olimpiada = new esporte (0,0,qtdpa,0,0);
			olimpiada-> cadastrar_patrocinadores();
		}
		else if(procedimento == 4){
			cout << "Voce deseja buscar atletas de um esporte especifico ou gerais?" << endl;
			cout << "1-De um esporte especifico" << endl;
			cout << "2-Gerais" << endl;
			cin >> tipo_busca;
			
			if(tipo_busca == 1){
				int posicao = -1;;
				cout << "De qual esporte voce deseja buscar atletas?" << endl;
				cin.ignore();
				getline(cin, esporte_buscado);
				posicao = olimpiada->busca_esporte(esporte_buscado,posicao);
				if (posicao != -1){
					int pos = -1;
					cout << "De qual atleta voce deseja buscar dados?" << endl;
					cin.ignore();
					getline(cin, busca);
					//cin. ignore ( 0 );
					pos = olimpiada-> busca_informacoes_atletas(busca,posicao);
					if (pos != -1){
						olimpiada-> listar_dados_atletas(posicao,pos);
					}
					else{
						cout << "Atleta nao inscrito" << endl;
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
				//cin. ignore ( 0 );
				int posicao = -1;;
				posicao = olimpiada-> buscar_informacoesatletas(busca);
				if(posicao != -1){
					olimpiada-> listar_dados_atletas(posicao);
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
				posicao = olimpiada->busca_esporte(esporte_buscado,posicao);
				if (posicao != -1){
					int pos = -1;
					cout << "De qual patrocinador voce deseja buscar dados?" << endl;
					cin.ignore();
					getline(cin, busca);
					//cin. ignore ( 0 );
					pos = olimpiada-> busca_informacoes_patrocinadores(busca,posicao);
					if (pos != -1){
						olimpiada-> listar_dados_patrocinadores(posicao,pos);
					}
					else{
						cout << "Patrocinador nao encontrado" << endl;
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
				posicao = olimpiada-> buscar_informacoespatrocinadores(busca);
				if(posicao != -1){
					olimpiada-> listar_dados_patrocinadores(posicao);
				}
				else{
					cout << "Patrocinador nao encontrado" << endl;
				}
			}
		}
	}while(procedimento != 6);	
	
	
	olimpiada-> ~esporte();

	return 0;
}
