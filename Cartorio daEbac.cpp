#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação em memória
#include<locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar de string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s = strings
	

	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w"= escrever
	fprintf(file,cpf ); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", Nome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Sobrenome: ");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadrastado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o Cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! .n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n");
	}
	system("pause");
}
int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Usuário deletado.\n");
		system("pause");
	}
}
int defaulto()
{
	printf("essa opção não está disponivel!\n");
}
int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //final do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //para apagar as coisas
		
		switch(opcao) //opções
		{
			case 1:
			printf("Você escolheu registrar os nomes!\n");
			registro(); //chamada de funções
			break;
			
			case 2:
			printf("Você escolheu consultar os nomes!\n");
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa opção não está disponivel!\n");
			system("pause");
			break;
			//fim da seleção
		}
		
	}
	
}
