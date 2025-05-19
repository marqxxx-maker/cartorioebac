#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca��o deespa�o 
#include <locale.h> //biblioteca da aloca�ao de texto por regi�o
#include <string.h> //biblioteca responsavel por string

int registro() //fun�ao responsavel por cadastra os usuarios no sistema
{
  //inicio cria�os de variaveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final cria�os de variaveis/string
  
   printf("digite o cpf a ser cadastrado: "); //coletando informa�oes do usuario
   scanf("%s",cpf); //%s refere-se a string
  
   strcpy(arquivo,cpf); //responsavel por copia valores dos string
  
   FILE *file; //cria arquivo
   file = fopen(arquivo,"w"); //cria arquivo e o "w" significa escrever
   fprintf(file,cpf); //salvo o valor da variavel
   fclose(file); //fecha o arquivo
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
  
   printf("digite o nome a ser cadastrado: ");
   scanf("%s",nome);
  
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
  
   printf("digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
  
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
  
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
  
   printf("digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
  
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
  
  
   system("pause");
  
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[250];
    
    printf("digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    if(file == NULL)
    {
    	printf("n�o foi posivel abrir o arquivo, n�o localizado!.\n");
	}
    
    while(fgets(conteudo, 250,file)!= NULL)
    {
    	printf("\nessas s�o as informa�oesdo usuario: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
	
	system("pause");
    
}

    int deletar()
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o uduario n�o se encontra no sistema!.\n");
		system("pause");
	}
		
}


int main() 
    {
    int opcao=0; //definindo variaveis
	int laco=1;
   
    for(laco=1;laco<10;)
    {
   
        system("cls");    
	
    	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
    	printf("### CART�RIO DO MARCOS ###\n\n"); //inicio do menu
     	printf("escolha a op��o desejada do menu:\n\n");
    	printf("\t1-registra nomes\n");
    	printf("\t2-consultar nomes\n");
    	printf("\t3-deletar nomes\n\n");
    	printf("\t4-sair do sistema\n\n");
    	
	    printf("op�ao: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando aescolha do usuario

    	system("cls"); //responsavel por linpar a tela
	
    switch(opcao) //inicio da sele��o
      {
    	case 1:
    	registro(); //chamada de fun��o
    	break;
		
    	case 2:
    	consulta();
    	break;
		
    	case 3:
    	deletar(); 
    	break;
    	
    	case 4:
        printf("obrigado por utilizar o sistema\n");
        return 0;
        break;
    	
    	
		
    	default:
    	printf("Essa op��o n�o est� disponivel!\n");
   	    system("pause");
     	break;
      } //fim da sele�� 
   }
}
