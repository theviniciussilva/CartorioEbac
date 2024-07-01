#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca das strings 

int registro() //fun��o para registrar usu�rios;
{
	setlocale(LC_ALL, "portuguese");
	
	//in�cio cria��o de var/strings;
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim cria��o de var/string;
	
	
	printf("Digite o CPF para cadastro: ");	//coletando informa��o do usu�rio;
	scanf("%s" , cpf);						// %s guarda string na var cpf
	
	strcpy(arquivo, cpf);					// responsavel por copiar os valores da string cpf para arquivo;
	
	//cria o arquivo
	FILE *file;								// " FILE " � a fun��o e  "file" � o comando 
	file = fopen(arquivo, "w"); 			// "w" � de write/ escrever
	fprintf(file,cpf); 						// salvo o valor da vari�vel
	fclose(file); 							// fecho o arquivo 
	
	file = fopen(arquivo,"a"); 				// "a" � de atualizar 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);						//salvando string em nome
	file = fopen(arquivo, "a");				//abrindo arquivo e atualizando 	
	fprintf(file,nome);						//escrevendo dentro de file a variavel nome
	fprintf(file,",");						//escrevendo uma virgula 
	fclose(file);							//fechando arquivo
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf (file, sobrenome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL,"portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo!\n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("Essa s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}
int deletar()
{
	char cpf [40];
	printf("Qual usu�rio voc� deseja deletar: ");
	scanf("%s", cpf);
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" read
	if(file == NULL)
	{
		printf("Este arquivo n�o existe mais!\n");
		system("pause");
	}
}

int main() // chama menu aplica��o do Cart�rio ebac
{		
	// definindo vari�veis 
	int opcao=0; 
	int rep=1;	
	
	for(rep=1; rep=1;)	// enquanto rep for igual a um at� um execute abaixo
	{
		system("cls"); //  limpando console
		
		setlocale(LC_ALL, "portuguese"); // definindo a linguagem 
		
		//inicio do menu
		printf("### Cart�rio da Ebac ### \n \n");		
		printf("Escolha a op��o desejada do menu: \n \n"); 
		printf("1 - Registrar nomes");
		printf("\t2 - Consultar nomes");
		printf("\t3 - Deletar nomes");
		printf("\t4 - Sair do menu \n");
		printf("\nOp��o: ");
		//fim do menu
		
		scanf("%d", &opcao); // armazenando informa��es do usu�rio
	
		system("cls");
		
		//inicio da sele��o
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema \n");
			return 0;
			break;	
				
			default:
			printf("Essa opc�o n�o est� disponivel\n");
			system("pause");
			break;				
		}
		//fim da sele��o
	}	

}
