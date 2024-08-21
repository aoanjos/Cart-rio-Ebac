#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include<string.h> //biblioteca respons�vel por cuidar do string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string (salvar uma string)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //Salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separar o arquivo por virgula
	fclose(file); //Fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string (salvar uma string)
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,nome); //Salvo o valor da vari�vel (escreve o nome do usu�rio)
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separar o arquivo por virgula
	fclose(file);	//Fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastado: "); //Coletar informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string (salvar uma string)
		
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,sobrenome); //Salvo o valor da vari�vel (escrever o sobrenome do usu�rio)
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separa o arquivo por virgula
	fclose(file); //Fechar o arquivo	
	
	printf("Digite o cargo a ser cadastado: "); //Coletar informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string (salvar uma string)
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,cargo); //Salvar o valor da vari�vel (salvar o cargo do usu�rio)
	fclose(file); //Fechar o arquivo
	
	system("pause"); //Parar o programa para n�o entrar em loop
	
}

int consulta() //Fun��o para consulta do usu�rio
{
	setlocale(LC_ALL,  "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o da vari�vel / string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o da vari�vel / string
	
	printf("Digite o CPF a ser consultado: "); //Coletar informa��o do usu�rio a ser consultado
	scanf("%s",cpf); //%s refere-se a string (salvar uma string)
	
	FILE *file; //Consultar o aruivo criado
	file = fopen(cpf,"r"); //Ler o arquivo "r" ("r" significa ler)
	
	if(file == NULL) //Acima do conteudo estipulado na string
	{
		printf("N�o foi poss�vel abrir o arquivo, no localizado!.\n"); //Mensagem de informa��o que n�o existe o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Quando conteudo do arquivo for maior que 200
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:"); //Coletar informa��o do usu�rio a ser deletado
	scanf("%s",cpf); //%s refere-se a string, "buscar o usu�rio a ser que est� salvo no sistema	para deletar"
	
	remove(cpf); //Deletar o arquivo, muito cuidado ao criar	
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abrir o arquivo criado(Ex. CPF) e ler
	
	if(file == NULL) //Usu�ri inexistente no arquivo
	{
		printf("O usuario foi deletado com sucesso, O usuario n�o se encontra no sistema!.\n");	//Informou ao usu�rio que foi deletado com sucesso
		system ("pause"); //Volta ao menu inicial
		
	}		
		
}

int main()
{

	int opcao=0	; //Definindo vari�veis	
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
		
		
	if(strcmp(senhadigitada, "admin") == 0)
	{
		system("cls");
		for(laco=1;laco==1;)
		{	
			system("cls");
					
			setlocale(LC_ALL,  "Portuguese"); //Definindo a linguagem
		
			//In�cio do menu
			printf("### Cart�rio da EBAC ###\n\n"); 
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registra nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("opcao: "); 
			//Fim do menu
		
			scanf("%d", &opcao); //Armazenamento a escolha do usu�rio
	
			system("cls"); //Respons�vel por limpar a tela
		
			switch(opcao) //In�cio da sele��o do menu
			{	
					case 1:
					registro(); //Chamada de fun��es
					break;
		
					case 2:
					consulta(); //Chamada de fun��es
					break;
			
					case 3:
					deletar(); //Chamada de fun��es
					break;
			
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
			
					default:
					printf("Essa op��o n�o esta dispon�vel!\n"); 
					system("pause");
					break;	
			} //fim da sele��o	
		}
	} 

	else
		
		printf("Senha incorreta!");
		
			
}
   

