#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsável por cuidar das string

int cadastro() //Fun��o respons�vel por cadastar os usu�rios no sistema
{
 
	//inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings

	printf("Digite o CPF a ser cadastrado: "); //coletando inform��es do usu�rio
	scanf("%s", cpf); // %s (percent) refere-se a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir e acrescentar um arquivo
	fprintf(file, ","); //acrescenta "," entre as inform��es a serem mostradas
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //procura em uma string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause"); //cria uma pausa na escolha da op��o
  
}
int consultar()
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
   char cpf[40];
   char conteudo[100];
	
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
  	
   FILE *file;
   file = fopen(cpf,"r");
  	
   if(file == NULL) //quando se digita um usu�rio inexistente
  {
	  printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
  }
	
  while(fgets(conteudo, 200, file) != NULL) //repete c�digos v�rias vezes
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
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf); //remove o arquivo requerido
	
	FILE *file;
	file = fopen(cpf ,"r"); // "r" significa ready , ler as inform�oes do arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main() //ponto de partida para a execu��o do programa
{
    int opcao=0; //definindo vari�veis
    int laco=1;

    for(laco=1;laco=1;) //repete o c�digo v�rias vezes
    {
       
       system("cls"); //respons�vel por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n"); //inicio do meu
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1-  Cadastro de Nomes\n");
	   printf("\t2-  Consultar Nomes\n");
	   printf("\t3-  Deletar Nomes\n\n");
	   printf("\t4-  Sair do Sistema\n\n");
	   printf("op��o: "); //fim do menu
	
	   scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
	   system("cls");
	   
	   switch(opcao) //simplifica a maneira de utilizar o "if-else" (inicio da sele��o do menu)
	   {
	   	   case 1:
	   	   cadastro(); //chamada das fun��es
           break;
           
		   case 2:
		   consultar();
    	   break;
    	   
    	   case 3:
    	   deletar();
		   break;
		   
		   case 4:
		   printf("Obrigado por utilizar o sistema!\n");
		   return 0;
		   break;
		   
		   default:
		   printf("Esta op��o est� indispon�vel!\n");
		   system("pause");
		   break;
		   
	   } //fim da sele��o

       
    }










	
}
