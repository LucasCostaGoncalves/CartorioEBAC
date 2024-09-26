#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o 
#include <string.h> //Biblioteca respons�vel pelas strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{ 
	//inicio de cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de cria��o de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file, cpf); // salvo o valor da variavel/string
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //criando o arquivo e o "a" significa atualizar
	fprintf(file, ","); //adicionando uma virgula entre os arquivos para manter organizado
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando info do usuario
	scanf("%s",nome); //aguardando resposta do usuario e o "%s" refere-se a string
	
	file = fopen(arquivo, "a"); //criando um arquivo e o "a" significa atualizar
	fprintf(file,nome); //salva o valor da variavel/string
	fclose(file); //fecha o arquivo
	
    file = fopen(arquivo, "a"); //criando um arquivo e o "a" significa atualizar
	fprintf(file, ","); //adicionando uma virgula entre os arquivos para manter organizado
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando info do usuario
	scanf("%s",sobrenome); //aguardando resposta do usuario e o "%s" refere-se a string
	
	file = fopen(arquivo, "a"); //criando um arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salvando o valor da variavel/string
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //criando um arquivo e o "a" significa atualizar
	fprintf(file, ","); //adicionando uma virgula entre os arquivos para manter organizado
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadstrado: "); //coletando info do usuario
	scanf("%s",cargo); //aguardando resposta do usuario e o "%s" refere-se a string
	
	file = fopen(arquivo, "a"); //criando um arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salvando o valor da variavel/string
	fclose(file); //fecha o arquivo
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria�ao de variaveis/string
	char cpf[40];
	char conteudo[200];
	//fim da cria�ao de variaveis/string
	
	printf("Digite o CPF que deseja consultar: "); //coletando info do usuario
	scanf("%s",cpf); //aguardando resposta do usuario
	
	FILE *file; //criando um arquivo
	file = fopen(cpf,"r"); //criando um arquivo e o "r" significa ler
	
	if(file == NULL) //caso do cpf nao ser encontrado
	{
		printf("N�o foi possivel abrir o arquivo, CPF n�o localizado!.\n"); //informando o usuario q o cpf nn existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //la�o de repeticao para localizar um arquivo e o !=NULL � para parar de localizar o arquivo caso ele nao exista
	{
		printf("\nEssas s�o as informa��es do usuario: "); //informando o usuario o cpf a ser consultado
		printf("%s", conteudo); //salvando o conteudo da variavel/string
		printf("\n\n"); //dando espa�amento para deixar agradavel (questoes de estetica)
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPf do usu�rio a ser deletado: "); //coletando info do usuario
	scanf("%s",cpf); //aguardando resposta do usuario 
	
	FILE *file; //criando um arquivo
	file = fopen(cpf,"r"); //abrindo o arquivo para fazer a leitura (o "r" significa ler)
	
	if(file == NULL) //caso o usuario nao esteja cadastrado no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //informando o usuario
		system("pause");
	}
	
	else 
	{
		fclose(file); //fechando o arquivo pois ele existe
		remove(cpf); //removendo o usuario apos localiza-lo
		printf("O usuario foi deletado com sucesso!.\n"); //informando o usuario 
		system("pause");
	}
	
}


int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela apagando tudo q foi escrito
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("op��o:"); //Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usuario
	
		system("cls"); //respons�vel por limpar a tela apagando tudo q foi escrito
		
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o existe!\n");
			system("pause");
			break;
		}
	}
}
