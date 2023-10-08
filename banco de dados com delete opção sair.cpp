#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema 
{
	//Início da criação de variáveis / string 
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variveis / string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário, que neste caso é o CPF 
    scanf("%s", &cpf); // %s refere-se a string que agente estamos armazenando 
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    FILE *file; //cria o arquivo 
    
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" sgnifica escrever 
	 fprintf(file,", CPF: ");
    fprintf(file, cpf); //salvo o valor da variavel
    fclose(file); // fecha o arquivo	
    
    file = fopen(arquivo, "a");
    fprintf(file,",\nNOME: ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n ");
    scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",\nCARGO: "); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
			
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{ 
	   printf("\nEssas são as informações do usuário: ");
	   printf("%s", conteudo);
	   printf("\n\n");
	}
		
	system("pause");

		
}
    
int deletar()
{
	char cpf[40];
		
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
		
	if(file == NULL)
	{
	    printf("O usuário não se encontra no sistema!.\n");
	    system("pause");
	}
		
} 



int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
     	system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu 
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("opcao \t1 - Registrar nomes\n");
	    printf("opcao \t2 - Consultar nomes\n");
	    printf("opcao \t3 - Deletar nomes\n\n"); 
	    printf("opcao \t4 - Sair do sistema\n\n");
     	printf("Escolha a opcao desejada: "); //fim do menu 
	
      	scanf("%d", &opcao); //armazenando a escolha do usuário  
    
        system("cls"); //É o responsavel por limpar a tela, começando assim uma nova página
    
        switch(opcao) //Inicio da seleção do menu
        {
            case 1:
            registro(); //Chamada de funções, por que é ele quem vai fazer a chamada da sua variavel, ou seja, registro, consulta e etc.
            break;
       
            case 2: 
            consulta();
       	    break;
	   
       	    case 3: 
	        deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!\n");
	        return 0; //Agente o coloca para o computador retornar para o valor zero, ou seja, agente quer dá laço e, com isso, agente quebra tudo e ele sai do sistema. 
	        break; 
	   
	        default:
	        printf("Essa opção não está disponivel!\n");
	        system("pause");
	        break;
        } //fim da seleção
    }  
}
