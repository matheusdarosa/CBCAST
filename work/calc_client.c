/* 	Client to start a thread in a RPC server.

	Author: Carolina Toscani e Matheus Rosa
   
	Date: 05.08.2013
    Modified: 16.08.2013
*/

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <rpc/rpc.h>
#include <math.h> //verificar se é necessário
#include <unistd.h>
#include "calc.h"

//escreve no arquivo que contém o numero a ser lido
void escreveArquivo(int num)
{
	FILE *arq;
    
	if ((arq = fopen(DATA_SRC, "a")) == NULL){
		printf("Erro ao abrir arquivo");
		exit(EXIT_FAILURE);
	}
	
    	//Escreve o resultado
    	fprintf(arq, "%d \n", num);
    	fclose(arq);
    	printf("Escrevendo: %d \n", num);
}

//Lê o numero do arquivo
int leNumArquivo(void){
	FILE *arq;
	char line[128];
	int currentN;
	currentN = 0;
	

	//abre um arquivo texto para leitura
	if ((arq = fopen(DATA_SRC, "r+")) == NULL){
		printf("Erro na abertura do arquivo");
		exit(EXIT_FAILURE);
	}

	//Le linha do arquivo
	while(fgets(line, sizeof(line), arq)!=NULL){}
    
    //transforma char para inteiro
	currentN = (int)atoi(line);
    
    //fecha arquivo
    fclose(arq);
    
    printf("Read number: %d \n", currentN);
	return currentN;
}

//realiza os calculos
int calcula(int i, int operacao){
	int result=0;
	int n=5;
	int num=0;
	
	num=leNumArquivo();
		switch (operacao){
			case 0:
			result = n-num;
				printf("Op %d: %d - %d = %d\n\n", i, n , num, result);
				break;				
			case 1:
				result = n+num;
				printf("Op %d: %d + %d  = %d\n\n", i, n, num, result);
				break;
			case 2:
				result = n*num;
				printf("Op %d: %d * %d = %d\n\n", i, n, num, result);
				break;
			case 3:
				result = num*num;
				printf("Op %d: %d * %d = %d\n\n", i, n , num,result);
				break;
			default:	
				result = n+5;
				printf("Op %d: %d + 5= %d\n\n", i, n, result);
				break;
		}
	
	return result;
}


int main(int argc, char *argv[]){
	
	CLIENT *cli= NULL;
	char *ipServ = NULL;
	int *resposta= NULL;
	void *pvoid	= NULL;
	int i=0;
	int result=0;
	int operacao;
	
	int number;
 
	//atribui ao ipServ o ip recebido
	ipServ = argv[1];
	number = atoi(argv[2]);

	//cliente conecta-se ao seu servidor
	if(!(cli=clnt_create(ipServ, CALCULA, CALCVERSION,"tcp"))){
		clnt_pcreateerror(ipServ);
		printf("Erro:clnt_create\n");
		return(1);
    }    
    
	//o seu servidor inicia o próprio servidor
	resposta = start_servers_1(&number, cli);
	if(resposta == (int *)NULL){
	   clnt_pcreateerror(ipServ);
	   printf("Error:start_servers_1!\n");
    }
       
	while(1)
	{	
		do{
			printf("Digite 0 para - , 1 para +, 2 para *, 3 para x² e 4 para +5\n");
			scanf("%d", &operacao);
		} while(operacao < 0 || operacao > 4);
			
		do{
			printf("Solicitando o Token!\n");
			resposta= p_1(pvoid,cli);			
			sleep(1);
		}
		while(*resposta == 0);
		
		printf("Recebi o Token\n");
		sleep(15);
		//result ira receber o resultado da operacao 
		result= calcula(i, operacao);
		
		//escreve de volta no arquivo
		escreveArquivo(result);
		
		//libera token
		printf("Liberando o Token\n");
		resposta= v_1(pvoid,cli);
		if(resposta == (int *)NULL){
			clnt_pcreateerror(ipServ);
			printf("Error:v_1!\n");
		}
		i++;
	}

}
	
	
