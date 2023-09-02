#include <stdio.h> // biblioteca de comunicação com o usuario 
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //Função responsavel por cadastrar os usuarios no sistema
{
    //Inicio criação de variaves/string
    char arquivo[40]; // Variavel criada com o intuito de salvar as informações para se tornar algo mais intuitivo. Sendo assim para salvar cada informação de dados do usuario
	char cpf[40];  
    char nome[40];
    char sobrenome[40];
    char cargo[40]; 
    //final criação de variaves/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
    scanf("%s", cpf);  // %s = String. Code de save de arquivo.
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
    FILE *file; //FILE=Comando do proprio sistema para criar um arquivo. *file= é o arquivo ja criado e nomeado. 
    file = fopen(arquivo, "w"); // cria o arquivo , W= Write/ escrever
    fprintf(file,cpf); // fprintf: salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); 
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); 
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); // a = atualizar a informação dentro do arquivo
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // a=atualizar a informação dentro do arquivo
    fprintf(file,","); // , = para deixar o programa mais visualmente organizado na visualização para o usuario. separando as informações na tela de resultado de busca.
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen (arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
     
     file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); // Tela de espera de resposta para o Usuario. 
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);  
    
    FILE *file;
    file = fopen(cpf,"r"); // r = Read : Ler 
    
    if(file == NULL) // Code de condição. if = Se. "Se o arquivo for ==(Igual) a NULL(NULO)
    {
    	printf("Não foi possivel abrir o arquivo , não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //While = enquanto , fgets = Pesquisa , NULL= Nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
   char cpf [40];
   
   printf("Digite o CPF do usuario a ser deletado: ");
   scanf ("%s", cpf);
   
   remove(cpf); //remove: remove a informação do sistema
   
   FILE *file;
   file = fopen(cpf,"r"); // r = read/Ler 
   
   if(file == NULL) // Momento de decisão no sistema, Se o arquivo for == (Igual) a NULL (Nulo)
   {
   	   printf("O usuário não se encontra no sistema!.\n" ); // Irá ser essa resposta que o usuario verá em sistema
   	   system("pause");
   }

}

int main()
{
   int opcao=0; //Definindo variaveis
   int laco=1;
     
   for(laco=1;laco=1;)  // for= Faça/repita quantas vezes eu solicitar.
   {
   
     system("cls");
   
      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
  
  
   printf("### Cartório da EBAC ####\n\n"); //Inicio do menu
   printf("Escolha a opção desejada do menu\n\n");
   printf("\t1 - Registrar nomes\n");
   printf("\t2 - Consultar nomes\n");
   printf("\t3 - Deletar nomes\n"); 
   printf("\t4 - Sair do Sistema\n");
   printf("Opção: "); //Fim do menu
   
   scanf("%d", &opcao); //Armazenando a escolha de Usuario
   
   system("cls"); // Responsavel por limpar a tela 
   
   switch(opcao) //Inicio de seleção de menu
   {
   	 case 1:
	registro(); //chamada de funções
   	break;
	   
	 case 2:
	consulta();
	break;
	
	 case 3:
	deletar();
   	  break;
   		 
   	 case 4:
   	 printf("Obrigado por utilzar nosso sistema!");
   	 return 0;
   	 break;
   		 
   	  default:
    printf("Essa opcao nao esta disponivel!");
   	    system("pause");
   	  break;  
   } //fim da seleção
   
   }
}

