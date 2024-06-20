#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsÃ¡vel por cuidar das string

int cadastro() //Função responsável por cadastar os usuários no sistema
{
 
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings

	printf("Digite o CPF a ser cadastrado: "); //coletando informções do usuário
	scanf("%s", cpf); // %s (percent) refere-se a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrir e acrescentar um arquivo
	fprintf(file, ","); //acrescenta "," entre as informções a serem mostradas
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
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
	
    system("pause"); //cria uma pausa na escolha da opção
  
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
  	
   if(file == NULL) //quando se digita um usuário inexistente
  {
	  printf("Não foi possivel abrir o arquivo, não localizado!.\n");
  }
	
  while(fgets(conteudo, 200, file) != NULL) //repete códigos várias vezes
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
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf); //remove o arquivo requerido
	
	FILE *file;
	file = fopen(cpf ,"r"); // "r" significa ready , ler as informçoes do arquivo
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main() //ponto de partida para a execução do programa
{
    int opcao=0; //definindo variáveis
    int laco=1;

    for(laco=1;laco=1;) //repete o código várias vezes
    {
       
       system("cls"); //responsável por limpar a tela
	
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("### Cartório da EBAC ###\n\n"); //inicio do meu
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1-  Cadastro de Nomes\n");
	   printf("\t2-  Consultar Nomes\n");
	   printf("\t3-  Deletar Nomes\n\n");
	   printf("\t4-  Sair do Sistema\n\n");
	   printf("opção: "); //fim do menu
	
	   scanf("%d" , &opcao); //armazenando a escolha do usuário
	
	   system("cls");
	   
	   switch(opcao) //simplifica a maneira de utilizar o "if-else" (inicio da seleção do menu)
	   {
	   	   case 1:
	   	   cadastro(); //chamada das funções
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
		   printf("Esta opção está indisponível!\n");
		   system("pause");
		   break;
		   
	   } //fim da seleção

       
    }










	
}
