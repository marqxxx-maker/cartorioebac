#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocação deespaço 
#include <locale.h> //biblioteca da alocaçao de texto por região
#include <string.h> //biblioteca responsavel por string

int registro() //funçao responsavel por cadastra os usuarios no sistema
{
  //inicio criaços de variaveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final criaços de variaveis/string
  
   printf("digite o cpf a ser cadastrado: "); //coletando informaçoes do usuario
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
    	printf("não foi posivel abrir o arquivo, não localizado!.\n");
	}
    
    while(fgets(conteudo, 250,file)!= NULL)
    {
    	printf("\nessas são as informaçoesdo usuario: ");
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
		printf("o uduario não se encontra no sistema!.\n");
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
	
    	printf("### CARTÓRIO DO MARCOS ###\n\n"); //inicio do menu
     	printf("escolha a opção desejada do menu:\n\n");
    	printf("\t1-registra nomes\n");
    	printf("\t2-consultar nomes\n");
    	printf("\t3-deletar nomes\n\n");
    	printf("\t4-sair do sistema\n\n");
    	
	    printf("opçao: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando aescolha do usuario

    	system("cls"); //responsavel por linpar a tela
	
    switch(opcao) //inicio da seleção
      {
    	case 1:
    	registro(); //chamada de função
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
    	printf("Essa opção não está disponivel!\n");
   	    system("pause");
     	break;
      } //fim da seleçõ 
   }
}
