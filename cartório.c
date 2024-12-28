#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memório
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das string
int registro()//função responsavel por cadastrar os usuários no sistema
{
	//inicio de criação de variáveis/string
		char arquivo [40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		//final de criação de variáveis/string
		printf("digite o CPF a ser cadastrado:");//coletando informação do usuário
		scanf("%s", cpf);//%s refere-se a string 
		
		strcpy(arquivo, cpf);//responsável por copiar os valores das string
		
		FILE *file;//cria o arquivo
		file = fopen(arquivo,"w");//cria o arquivo/ "w" refere-se a escrever
		fprintf(file,cpf);//salva a variavel 
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome do usuario a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("digite no sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);		
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);				
		
		system("´pause");//função de pausar a tela
}
int consulta()
{
		setlocale(LC_ALL, "portuguese");//definindo a lingugem
	
		char cpf[40];
		char conteudo[200];
		
		printf("digite o CPF o deseja consultar: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
		printf("não foi possivel abrir o arquivo, não localizado!.\n");
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
		
		printf("digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
		printf("o usuário não se encontra no sistema!.\n ");
		system("pause");
		}
}
int main()
{
	int opcao=8; //definindo variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");//responsavel por limpar a tela
		
		setlocale(LC_ALL, "portuguese");//definindo a lingugem
		printf("### cartório da EBAC ###\n\n");//inicio menu
		printf("escolha a opção do menu: \n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("opção: ");//fim do menu
 	
 		scanf("%d", &opcao);//armazenando a escolha do usuario
 	
 		system("cls");
		
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro();//chamada de funções
		    break;
			 
			case 2:
			consulta();
			break;	
			 
			case 3:
			deletar();
 		    break;
 	
 	        default:
			printf("essa opção não esta disponivel!\n\n");
			system("pause");  
			break;
			
 		}//fim da seleção	
	}
}
