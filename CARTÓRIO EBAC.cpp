#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include<string.h> //biblioteca responsável por cuidar do string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string (salvar uma string)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //Salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separar o arquivo por virgula
	fclose(file); //Fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string (salvar uma string)
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,nome); //Salvo o valor da variável (escreve o nome do usuário)
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separar o arquivo por virgula
	fclose(file);	//Fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastado: "); //Coletar informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string (salvar uma string)
		
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,sobrenome); //Salvo o valor da variável (escrever o sobrenome do usuário)
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,","); //Separa o arquivo por virgula
	fclose(file); //Fechar o arquivo	
	
	printf("Digite o cargo a ser cadastado: "); //Coletar informação do usuário
	scanf("%s", cargo); //%s refere-se a string (salvar uma string)
	
	file = fopen(arquivo, "a"); //Abrir o arquivo desejado
	fprintf(file,cargo); //Salvar o valor da variável (salvar o cargo do usuário)
	fclose(file); //Fechar o arquivo
	
	system("pause"); //Parar o programa para não entrar em loop
	
}

int consulta() //Função para consulta do usuário
{
	setlocale(LC_ALL,  "Portuguese"); //Definindo a linguagem
	
	//Início da criação da variável / string
	char cpf[40];
	char conteudo[200];
	//Fim da criação da variável / string
	
	printf("Digite o CPF a ser consultado: "); //Coletar informação do usuário a ser consultado
	scanf("%s",cpf); //%s refere-se a string (salvar uma string)
	
	FILE *file; //Consultar o aruivo criado
	file = fopen(cpf,"r"); //Ler o arquivo "r" ("r" significa ler)
	
	if(file == NULL) //Acima do conteudo estipulado na string
	{
		printf("Não foi possível abrir o arquivo, no localizado!.\n"); //Mensagem de informação que não existe o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Quando conteudo do arquivo for maior que 200
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:"); //Coletar informação do usuário a ser deletado
	scanf("%s",cpf); //%s refere-se a string, "buscar o usuário a ser que está salvo no sistema	para deletar"
	
	remove(cpf); //Deletar o arquivo, muito cuidado ao criar	
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abrir o arquivo criado(Ex. CPF) e ler
	
	if(file == NULL) //Usuári inexistente no arquivo
	{
		printf("O usuario foi deletado com sucesso, O usuario não se encontra no sistema!.\n");	//Informou ao usuário que foi deletado com sucesso
		system ("pause"); //Volta ao menu inicial
		
	}		
		
}

int main()
{

	int opcao=0	; //Definindo variáveis	
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
		
		
	if(strcmp(senhadigitada, "admin") == 0)
	{
		system("cls");
		for(laco=1;laco==1;)
		{	
			system("cls");
					
			setlocale(LC_ALL,  "Portuguese"); //Definindo a linguagem
		
			//Início do menu
			printf("### Cartório da EBAC ###\n\n"); 
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registra nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("opcao: "); 
			//Fim do menu
		
			scanf("%d", &opcao); //Armazenamento a escolha do usuário
	
			system("cls"); //Responsável por limpar a tela
		
			switch(opcao) //Início da seleção do menu
			{	
					case 1:
					registro(); //Chamada de funções
					break;
		
					case 2:
					consulta(); //Chamada de funções
					break;
			
					case 3:
					deletar(); //Chamada de funções
					break;
			
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
			
					default:
					printf("Essa opção não esta disponível!\n"); 
					system("pause");
					break;	
			} //fim da seleção	
		}
	} 

	else
		
		printf("Senha incorreta!");
		
			
}
   

