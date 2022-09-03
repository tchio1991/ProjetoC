#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 200

// varieveis globais, matrizes
char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;

// Funções declaradas 
void cadastro();
void pesquisa();
void lista();
int main(void) {
    // comando para aceitar acentuação grafica 
    setlocale(LC_ALL, "Portuguese");

	do{
		// função que limpar a tela do prompt de comando ao sair do menu
		system("cls");
		printf("\n----Menu-----\n1 - Cadastrar\n2 - Listar Todos\n3 - Pesquisar\n4 - Sair ");
		scanf("%d",&op);
		switch(op) {
			case 1:
				cadastro();
				break;
			case 2:
			    lista();
			    break;
			case 3:
			    pesquisa();
			    break;
		    case 4:
		    	system("exit");
		    	break;
			default:
			    printf("\nOpção invalida\n");
			    getchar();
			    getchar();
			    break;				
		}
	}while(op!=4);
}

// Inicio da função lista
void lista() {
	setlocale(LC_ALL, "Portuguese");
	int i;
	for(i=0;i<SIZE;i++) {
		if(cpf[i]>0) {
			printf("\nNome: %s\nEmail: %s\nCPF: %d",nome[i],email[i],cpf[i]);
	    }else{
	    	break;
		}
	}
	getchar();
	getchar();
}
// Inicio da função
void cadastro() {
	setlocale(LC_ALL, "Portuguese");
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		printf("\nDigite o email: ");
		scanf("%s",&email[linha]);
		printf("\nDigite o cpf: ");
		scanf("%d",&cpf[linha]);
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d",&op);
		linha++;
	}while(op==1);
} // Fim da função cadastro

// Inicio da função pesquisa
void pesquisa() {
	setlocale(LC_ALL, "Portuguese");
	int cpfPesquisa;
	char emailPesquisa[50];
	int i;
	do{
		printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar por email ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("\nDigite o CPF: ");
				scanf("%d", &cpfPesquisa);
				for(i=0;i<SIZE;i++) {
					if(cpf[i]==cpfPesquisa) {
						printf("\nNome: %s\nEmail: %s\nCPF: %d",nome[i],email[i],cpf[i]);
					}
				}
				break;
			case 2:
			    printf("\nDigite o E-mail: ");
			    scanf("%s",emailPesquisa);
			    for(i=0;i<SIZE;i++) {
					if(strcmp(email[i], emailPesquisa)==0) {
						printf("\nNome: %s\nEmail: %s\nCPF: %d",nome[i],email[i],cpf[i]);
					}
				}
			    break;
			default:
			    printf("\nOpcão invalida\n");
			    break;		
		}
		printf("\nDigite 1 para continuar pesquisando ");
		scanf("%d",&op);
	}while(op==1);
	
} // Fim da função pesquisa



