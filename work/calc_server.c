#include <pthread.h>
#include <math.h>
#include <rpc/rpc.h>
#include <time.h>
#include <stdio.h>
#include "calc.h"
#include <unistd.h>
#include "header.h"

pthread_t tid1;
int have_token = 0; //false
int client_wants_token = 0; //false
char nextHopeIP[30];
CLIENT *cli= NULL;
pthread_t tid1;
void *pvoid = NULL;

int myNumber = 0;

void *server_run()
{
	while(!(cli=clnt_create(nextHopeIP, CALCULA, CALCVERSION,"tcp"))){
		clnt_pcreateerror(nextHopeIP);
		printf("Error:clnt_create\n");
		sleep(2);
	}
 
	if (myNumber == 1)
	{
		printf("STATUS:I am the first computer! The token starts here!\n");
		have_token = 1;
		sleep(15);
	}
	
	while (1){
	sleep(2); //just to make more easy to see
		if (client_wants_token == 1 && have_token == 1){	
			printf("STATUS:Using the token!\n");
		}
		else if (client_wants_token == 1 && have_token == 0){	
			printf("STATUS:I need the token! Waiting...\n");
		}
		else if (client_wants_token == 0 && have_token == 1){	
			printf("STATUS:I dont need! Passing...\n");
			have_token = 0 ;
			if(pass_token_1(pvoid, cli) == 1)
			{
				sleep(4);
				printf("STATUS:Sent!\n");
			}
		}
		else{
			printf("STATUS:I dont have the token! Doing nothing!\n");
		}
	 }
}

int *start_servers_1_svc(int *number, struct svc_req *rqstp) {
    static int retorno = 0;

	myNumber = *number;

	printf("STATUS:I am #%d on the ring\n", myNumber);
	
	if (*number == 1)
		strcpy(nextHopeIP, &IP2);
	else if (*number == 2)
		strcpy(nextHopeIP, &IP1);
	/*else if (*number == 3) 
		strcpy(nextHopeIP, IP4);
	else if (*number == 4) 
		strcpy(nextHopeIP, IP5);
	else if (*number == 5) 
		strcpy(nextHopeIP, IP1);
	*/else
		return -1;

	printf("I am up at IP: %s\n", nextHopeIP);
	retorno = pthread_create(&tid1, NULL, server_run, NULL);
	return &retorno;
}

int *p_1_svc(void *p, struct svc_req *rqstp) {
	static int result = 0;	
	client_wants_token = 1;
	result = have_token;
	return &result;
}

int *v_1_svc(void *p, struct svc_req *rqstp) {
	client_wants_token = 0;	
	return &client_wants_token;
}
int *pass_token_1_svc(void *p, struct svc_req *rqstp) {
	printf("STATUS:Received!\n");
	have_token = 1;
	return &have_token;
}


