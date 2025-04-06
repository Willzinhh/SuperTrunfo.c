
//************[ TRABALO SUPER TRUNFO ]*******************
//****************[ POKÉMON 1 GEN ]**********************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Carta {
    char cod;
    char nome[20];
    char trunfo;  
    
    int hp;    
    int atk;  
    int def;  
    int spd;  
    
    struct Carta *prox;
    
    
};
typedef struct Carta poke;

int jogo();
void menu();

//CRIAÇAO E IMPRESSAO DE BARALHO//
poke *criarpoke(poke *l);
poke *addBaralho(poke *l, char cod, char nome[20], char trunfo, int hp, int atk, int def, int spd);
void imprimir(poke *l);
void imprimirBaralho(poke *p1, poke *p2);

//GERENCIAMENTO DE JOGO//
poke *embaralha(poke *l);
poke *dividir(poke *l, poke *jogador, int total);
poke *batalha( poke *p1, poke *p2,int cont);

//ESCOLHA E COMPARAÇAO DE ATRIBUTOS//
int acao(int cont,poke *p1,poke *p2);
int comparar(int p1, int p2);

//ARRUMA BARALHO APÓS RODADA//
poke *vencedor(poke *pv, poke *pp);
poke *empate(poke *p);



//MENU PARA JOGAR E ENCERAR PROGHRAMA//
int main(){
	srand(time(NULL));
	int op;
	
	do{
	menu();
	scanf("%d", &op);
	
	if(op==1){
	jogo();
	}	
	
	}while(op!=2);
}

//FUNÇAO INICIO DE JOGO//

int jogo(){
	poke *l=NULL;
	poke *p1=NULL, *p2=NULL;
	
//FUNÇAO CRIA AS CARTAS//	
	l = criarpoke(l);
	
//FUNÇAO EMBARALHA A LISTA//	
	l = embaralha(l);
//	imprimir(l);
	
//DIVIDE AS CARTAS EMBARALHADAS PARA OS JOGADORES//	
	p1 = dividir(l,p1,0);
	p2 = dividir(l,p2,8);

//imprimirBaralho(p1,p2);

//INICIA BATALHA DE CARTAS EM RECURSIVIDADE//
	batalha(p1,p2,1);
	
	
}
//EXIBIR MENU//
void menu() {
    printf("\n[1] Jogar\n");
    
    printf("[2] Sair do programa\n");
}

//CRIAR AS CARTAS //
poke *criarpoke(poke *l) {
    l = addBaralho(l, 'a', "Pikachu", 'S', 1, 3, 1, 5);
    l = addBaralho(l, 'a', "Venusaur", 'N', 4, 3, 4, 1);
    l = addBaralho(l, 'a', "Charizard", 'N', 3, 4, 2, 4);
    l = addBaralho(l, 'a', "Blastoise", 'N', 4, 3, 5, 1);
    l = addBaralho(l, 'b', "Pidgeot", 'N', 3, 2, 3, 4);
    l = addBaralho(l, 'b', "Butterfre", 'N', 1, 3, 2, 2);
    l = addBaralho(l, 'b', "Beedrill", 'N', 1, 3, 1, 3);
    l = addBaralho(l, 'b', "Vileplume", 'N', 3, 2, 3, 2);
    l = addBaralho(l, 'c', "Arcanine", 'N', 4, 4, 3, 3);
    l = addBaralho(l, 'c', "Gyarados", 'N', 2, 4, 4, 3);
    l = addBaralho(l, 'c', "Golem", 'N', 2, 5, 4, 1);
    l = addBaralho(l, 'c', "Alakazam", 'N', 2, 5, 1, 5);
    l = addBaralho(l, 'd', "Gengar", 'N', 2, 4, 2, 5);
    l = addBaralho(l, 'd', "Mew", 'N', 4, 4, 4, 4);
    l = addBaralho(l, 'd', "Snorlax", 'N', 5, 3, 4, 1);
    l = addBaralho(l, 'd', "Nidoking", 'N', 3, 3, 2, 2);
    return l;
}

//ADICIONAR CARTAS A LISTA//
poke *addBaralho(poke *l, char cod, char nome[20], char trunfo, int hp, int atk, int def, int spd) {
	
    poke *novo = (poke *)malloc(sizeof(poke));
    novo->cod = cod;
    strcpy(novo->nome, nome);
    novo->trunfo = trunfo;
    novo->hp = hp;
    novo->atk = atk;
    novo->def = def;
    novo->spd = spd;
    

    if (l == NULL) {
        l = novo;
        novo->prox = NULL;
        
    
    } else {
        poke *laux = l;
        while (laux->prox != NULL){
			laux = laux->prox;
		}
		
        laux->prox = novo;
        novo->prox = NULL;
    
    }

    return l;
}

//FUNÇAO PARA IMPRIMIR BARALHO (OCULTA PARA TESTE)//
void imprimir(poke *l) {
    poke *p = l;
    do {
        printf("\n-----------------------\n");
        printf("COD: %c\n", p->cod);
        printf("NOME: %s\n", p->nome);
        printf("TRUNFO?: %c\n", p->trunfo);
        printf("HP: %d\n", p->hp);
        printf("ATK: %d\n", p->atk);
        printf("DEF: %d\n", p->def);
        printf("SPD: %d\n", p->spd);
        p = p->prox;
        
    } while (p != NULL);
}

//FUNÇAO PARA COMPARAR os 2 BARALHOS OCULTA EM JOGO//
void imprimirBaralho(poke *p1, poke *p2){
 
	  	
 	do{
 		printf("\n--------------------------------------------------------------------------\n");
		printf("COD: %c \t\t\t\t    COD: %c\n", p1->cod, p2->cod);
		printf("NOME: %s\t\t\t   NOME: %s\n", p1->nome, p2->nome);
		printf("TRUNFO?: %c \t\t\t    TRUNFO?: %c\n", p1->trunfo, p2->trunfo);
		printf("HP:  %d \t\t\t\t    HP:  %d\n", p1->hp, p2->hp);
		printf("ATK: %d \t\t\t\t    ATK: %d\n", p1->atk, p2->atk);
		printf("DEF: %d \t\t\t\t    DEF: %d\n", p1->def, p2->def);
		printf("SPD: %d \t\t\t\t    SPD: %d\n", p1->spd, p2->spd);
		
		p1=p1->prox;
		p2=p2->prox;

	}while(p1 != NULL && p2!= NULL);
	
	
		printf("********************************************************************");
		
		
 }
 
//FUNÇAO PARA EMBARALHAR LISTA ORIGINAL//
poke *embaralha(poke *l) {  
    poke *baralho[16];
    int i = 0;
    poke *aux = l;

//COPIA BARALHO lista PARA BARALHO VETOR COM MALLOC//
    do {
        baralho[i] = (poke *)malloc(sizeof(poke));
       

//COPIA OS DADOS DAS CRATAS(lista) PARA CARTAS(vetor)//
        baralho[i]->cod = aux->cod;
        strcpy(baralho[i]->nome, aux->nome);
        baralho[i]->trunfo = aux->trunfo;
        baralho[i]->hp = aux->hp;
        baralho[i]->atk = aux->atk;
        baralho[i]->def = aux->def;
        baralho[i]->spd = aux->spd;
        baralho[i]->prox = NULL;
        
		i++;
        aux = aux->prox;
    } while (aux != l && i < 16);

// EMBARALHA  VETOR 16 VEZES//
    srand(time(NULL)); 
    for (i = 0; i < 16; i++) {
    	
    	//ESCOLHE POSIÇAO ALEATORIA//
        int j = rand() % 8; 
        
        //TROCA CARTAS DA POSIÇAO i E j//
        poke *temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
        
    }

//CRIA BARALHO EMBARALHADO 
    poke *lembaralhado = NULL;

    for (i = 0; i < 16; i++) {
    	
			//UTILIZA COPIA FEITA No VETOR//
            poke *novaCarta = baralho[i];
           
            if (lembaralhado == NULL) {
                lembaralhado = novaCarta;
                novaCarta->prox=NULL;
                
                
            }
           	else{
           		poke *laux = lembaralhado;
           		
           		while(laux->prox!=NULL){
					laux=laux->prox;
				   }
			
       		
       		laux->prox=novaCarta;
       		novaCarta->prox=NULL;
        	
 		 }
    }
    
//RETORN LISTA EMBARALHADA//
    return lembaralhado; 
}

//FUNÇAO DIVIDE LISTA EMBARALHADA//
poke *dividir(poke *l, poke *jogador, int total) {
	//LISTA VAZIA//
    if (l == NULL) {
        return NULL;
    }

 
    poke *aux = l;
    int i=0;
    
    //ENQUANTO i MENOR Q TOTAL //
    //AUX PROX  PARA N REPETIR CARTAS/
    
    while(i<total){
    	aux=aux->prox;
    	i++;
	}

//COLOCA 8 CARAS A PARTIR DO TOTAL SELECIONADO A CIMA //
    for (i = 0; i < 8; i++) {
        poke *novaCarta = (poke *)malloc(sizeof(poke)); 
          
		//COPIA DADOS DAS CARTAS//		 
        novaCarta->cod = aux->cod;
        strcpy(novaCarta->nome, aux->nome);
        novaCarta->trunfo = aux->trunfo;
        novaCarta->hp = aux->hp;
        novaCarta->atk = aux->atk;
        novaCarta->def = aux->def;
        novaCarta->spd = aux->spd;
        
		aux=aux->prox;


        
        if (jogador == NULL) {
            jogador= novaCarta;
        }
        else{
        	poke *paux = jogador;
        	while(paux->prox!=NULL){
        		paux=paux->prox;
			}
			paux->prox=novaCarta;
			novaCarta->prox=NULL;
		}
    }

//RETORNA BARALHO DO JOGADOR CHAMADO [1] OU [2]//
    return jogador;
}

//FUNÇAO DE FUNCIONAMENTO DE JOGO//
poke *batalha( poke *p1, poke *p2,int cont){
	srand(time(NULL));
	poke *auxperdedor;
	
	//imprimirBaralho(p1,p2);
	
//VERIFICA SE JOGADOR ESTÁ COM A ULTIMA CARTA//	
	if(p1->prox==NULL){
		printf("\n\t\t  Ultima carta do jogador[1]\n");
	}
	if(p2->prox==NULL){
		printf("\n\t\t  Ultima carta do jogador[2]\n");
	}

//PRINTA AS DUAS CARTAS DO TOPO DOS BARALHOS DOS JOGADORES//	
		printf("\n----------------------------------------------------------------\n");
		printf("  Jogador[1] \t\t\t    Jogador[2]\n\n");
		printf("COD: %c \t\t\t\t    COD: %c\n", p1->cod,p2->cod);
		printf("NOME: %s\t\t\t   NOME: %s\n", p1->nome,p2->nome);
		printf("TRUNFO?: %c \t\t\t    TRUNFO?: %c\n", p1->trunfo,p2->trunfo);
		printf("HP:  %d \t\t\t\t    HP:  %d\n", p1->hp,p2->hp);
		printf("ATK: %d \t\t\t\t    ATK: %d\n", p1->atk,p2->atk);
		printf("DEF: %d \t\t\t\t    DEF: %d\n", p1->def,p2->def);
		printf("SPD: %d \t\t\t\t    SPD: %d\n", p1->spd,p2->spd);
		printf("----------------------------------------------------------------\n");
	
			
//VALIDAÇAO DE ESCOLHA DE ATRIBUTO//
			
			//CASO JOGADOR TENHA TRUNFO//				
			if(p1->trunfo=='S'&& p2->cod!='a'){
				printf("\n\t\t    Jogador 1 grita TRUNFO\n");
				auxperdedor = p2;
				p2=p2->prox;
				auxperdedor->prox=NULL;
				
				//VENCEDOR RECEBE CARTA PERDEDOR//
			    p1 = vencedor(p1,auxperdedor);
				cont=1;
				printf("\n\n\t\t\tJogador[1] Venceu!");
			}
			else if(p2->trunfo=='S'&& p1->cod!='a'){
				printf("\n\t\t    Jogador 2 grita TRUNFO\n");
				auxperdedor = p1;
				p1=p1->prox;
				auxperdedor->prox=NULL;
				
				//VENCEDOR RECEBE CARTA PERDEDOR//
				p2 = vencedor(p2,auxperdedor);
				cont=2;
				printf("\n\n\t\t\tJogador[2] Venceu!");
			}
			else if(p1->trunfo=='S'&& p2->cod=='a'){
				printf("\n\t\t    Jogador 1 grita TRUNFO\n");
				auxperdedor = p1;
				p1=p1->prox;
				auxperdedor->prox=NULL;
				
				//VENCEDOR RECEBE CARTA PERDEDOR//
				p2 = vencedor(p2,auxperdedor);
				cont=2;
				printf("\n\n\t\t\tJogador[2] Venceu!");
			}
			else if(p2->trunfo=='S'&& p1->cod=='a'){
				printf("\n\t\t    Jogador 2 grita TRUNFO\n");
				auxperdedor = p2;
				p2=p2->prox;
				auxperdedor->prox=NULL;
				
				//VENCEDOR RECEBE CARTA PERDEDOR//
				p1 = vencedor(p1,auxperdedor);
				cont=1;
				printf("\n\n\t\t\tJogador[1] Venceu!");
			}
			
			//CASO DUAS CARTAS != TRUNFO//
			else{
				
				//FUNÇAO PARA ESCOLHER MELHOR ATRIBUTO DO JOGADOR QUE ESCOLHE//
				//RETORNA [1] ou [2] ou [0] PARA DEFINIR QUEM FARA A PROXIMA ESCOLHA//
				//E DEFINIR VENCEDOR//
				cont = acao(cont, p1, p2);
					
				
				if(cont == 1){
					auxperdedor = p2;
					p2=p2->prox;
					auxperdedor->prox=NULL;
					p1 = vencedor(p1,auxperdedor);

					printf("\n\n\t\t\tJogador[1] Venceu!");
				}
				else if(cont == 2){
					auxperdedor = p1;
					p1=p1->prox;
					auxperdedor->prox=NULL;
					p2 = vencedor(p2,auxperdedor);
		
					printf("\n\n\t\t\tJogador[2] Venceu!");
				}
				else{
					printf("\n\n\t\t\tHouve um Empate!\n");
					
					// CASO EMPATE PASSA AS 2 CARTAS PARA TRÁS//
					p1 = empate(p1);
					p2 = empate(p2);
				}			
			}	
		
		getchar();
		system("cls");
		
//CASO EMPATE ALEATORIZA QUEM IRA ESCOLHER O ATRIBUTO NA RODADA//
		if(cont==0){
			cont=(rand()%2+1);
		}

//SE ENHUM DOS JOGADORES == NULL CHAMA FUNÇAO BATALHA NOVAMENTE//		
	if(p1 != NULL && p2 != NULL){
	 batalha(p1,p2,cont);
	 
	}
//SE ALGUM DOS BARALHOS == NULL DETERMINA VENCEDOR DA PARTIDA//
	if(p1==NULL){
		printf("\n\t\t\tJogador[2] VENCEU!\n");
		getchar();
	system("cls");
	}
	if(p2==NULL){
		printf("\n\t\t\tJogador[1] VENCEU!\n");
		getchar();
	system("cls");
	}
	
	return NULL;
}

//FUNÇAO PARA DEFINIR MELHOR ATIBUTO DA CARTA DO JOGADOR QUE FARA A AÇÃO//
int acao(int cont,poke *p1,poke *p2){
	poke *pacao;
	int resultado;
	int jogador;
	
	
	if(cont==1){
		pacao=p1;		
		jogador = 1;
	}
	
	if(cont==2){
		pacao=p2;
		jogador = 2;
	}


//VERIFICA SE ATRIBUTO > TODOS OUTROS ATRIBUTOS//
	 if(pacao->hp > pacao->atk && pacao->hp > pacao->def && pacao->hp > pacao->spd ){
		printf("\n\tJogador[%d] Escolheu HP! \t HP = %d", jogador, pacao->hp);
		resultado = comparar(p1->hp, p2->hp);
	}
	else if(pacao->atk > pacao->hp && pacao->atk > pacao->def && pacao->atk > pacao->spd ){
		printf("\n\tJogador[%d] Escolheu ATK! \t ATK = %d", jogador, pacao->atk);
		resultado = comparar(p1->atk, p2->atk);
	}
	else if(pacao->def > pacao->atk && pacao->def > pacao->hp && pacao->def > pacao->spd ){
		printf("\n\tJogador[%d] Escolheu DEF! \t DEF = %d", jogador, pacao->def);
		resultado = comparar(p1->def, p2->def);
}
	else if(pacao->spd > pacao->atk && pacao->spd > pacao->def && pacao->spd > pacao->hp ){
		printf("\n\tJogador[%d] Escolheu SPD! \t SPD = %d", jogador, pacao->spd);
		resultado = comparar(p1->spd, p2->spd);
	}
	
//SE TODOS ATRIBUTOS FOREM IGUAIS SORTEIA UM ATRIBUTO//	
	else if(pacao->hp == pacao->atk && pacao->hp == pacao->def && pacao->hp == pacao->spd ){
		int r = (rand()% 4 + 1);
		if(r == 1){
			printf("\n\tJogador[%d] Escolheu HP! \t HP = %d", jogador, pacao->hp);
			resultado = comparar(p1->hp, p2->hp);
		}
		else if(r == 2){
			printf("\n\tJogador[%d] Escolheu ATK! \t ATK = %d", jogador, pacao->atk);
			resultado = comparar(p1->atk, p2->atk);
		}
		else if(r == 3){
			printf("\n\tJogador[%d] Escolheu DEF! \t DEF = %d", jogador, pacao->def);
			resultado = comparar(p1->def, p2->def);
		}
		else if(r == 4){
			printf("\n\tJogador[%d] Escolheu SPD! \t SPD = %d", jogador, pacao->spd);
			resultado = comparar(p1->spd, p2->spd);
		}
	}
	
//SE 2 ATRIBUTOS FOREM IGUAIS SORTEIA UM DOS ATRIBUTOS//
	else {
		int d;
		d = (rand()%2 + 1);
		if(pacao->atk == pacao->def && pacao->atk > pacao->hp){
			if(d == 1){
				printf("\n\tJogador[%d] Escolheu DEF! \t DEF = %d", jogador, pacao->def);
				resultado = comparar(p1->def, p2->def);
			}
			else if(d == 2){
				printf("\n\tJogador[%d] Escolheu ATK! \t ATK = %d", jogador, pacao->atk);
				resultado = comparar(p1->atk, p2->atk);
			}
		}
		else if(pacao->hp == pacao->def && pacao->hp > pacao->atk){
			if(d == 1){
				printf("\n\tJogador[%d] Escolheu HP! \t HP = %d", jogador, pacao->hp);
				resultado = comparar(p1->hp, p2->hp);
			}
			else if(d == 2){
				printf("\n\tJogador[%d] Escolheu DEF! \t DEF = %d", jogador, pacao->def);
				resultado = comparar(p1->def, p2->def);
			}
		}
		else if(pacao->hp == pacao->atk && pacao->hp > pacao->def){
			if(d == 1){
				printf("\n\tJogador[%d] Escolheu HP! \t HP = %d", jogador, pacao->hp);
				resultado = comparar(p1->hp, p2->hp);
			}
			else if(d == 2){
				printf("\n\tJogador[%d] Escolheu ATK! \t ATK = %d", jogador, pacao->atk);
				resultado = comparar(p1->atk, p2->atk);
			}
		}
		else if(pacao->atk == pacao->spd && pacao->atk>pacao->hp){
					if(d==1){
				
				printf("\n\tJogador[%d] Escolheu ATK! \t ATK = %d",jogador,pacao->atk);
				 resultado = comparar(p1->atk,p2->atk);
			}
					
		else if(d==2){
						
				printf("\n\tJogador[%d] Escolheu SPD! \t SPD = %d",jogador,pacao->spd);
				 resultado = comparar(p1->spd,p2->spd);
				}
			}	
		}
	
	cont = resultado;	
	
	return cont;		
}


//FUNÇAO COMPARA OS ATRIBUTOS DAS CARTAS DO TOPO//
int comparar(int atributop1, int atributop2){
	
	//RETORNA VALOR REFERENTE A VENCEDOR//
	if(atributop1>atributop2){
		return 1;
	}
	else if(atributop1<atributop2){
		return 2;
	}
	else{
		return 0;
	}
}

//FUNÇAO PARA ARRUMAR BARALHO DO VENCEDOR//
poke *vencedor(poke *pv, poke *pp){
	poke *aux;
	
	poke *auxp;
	
	auxp=pp;
	poke *auxv = pv;
	
//SE JOGADOR -> PROX  != NULL ADD CARTA PERDEDOR NO FINAL E CARTA JOGADOR ATRAS DELA//	
	if(pv->prox!=NULL){
	aux = pv->prox;
	}
//SE JOGADOR PROX == NULL ASSUME CARAT DO PERDEDOR COMO NÓ CABECA E ADD A DELE NO FINAL//
	else{
	aux = pp;
	}
	
	
	while(auxv->prox!=NULL){
		auxv=auxv->prox;
	}
	
	auxv->prox=auxp;
	auxv->prox->prox=pv;
	pv->prox=NULL;
	
	
		

//RETORNA BARALHO PARA PROXIMA EXECUÇÃO DE BATALHA//	
	return aux;
}

//FUNÇAO PARA EMPATE//
poke *empate(poke *p){
	poke *auxp = p;
	poke *aux = p->prox;

	while(auxp->prox!=NULL){
		auxp=auxp->prox;
	}
	
//SE JOGADOR PROX != NULL ADD CARTA FINAL DO BARALHO//
	if(p->prox!=NULL){
		auxp->prox=p;
		p->prox=NULL;
	}
	
//SE JOGADOR PROX == NULL MANTEM A MESMA CARA NO TOPO DO BARALHO//
	else{
		aux = p;
	}
	
	
	
	return aux;
}



