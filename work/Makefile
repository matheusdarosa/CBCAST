# Makefile
# Alunos: Carolina Toscani e Matheus da Rosa

RPCGEN=rpcgen
CC=gcc -lm -pthread
RM=rm -f

CFLAGS =
RPCGENFLAGS = 

all: rpcgen server client

rpcgen:
	rpcgen calc.x

client:
	$(CC) calc_client.c calc_clnt.c -o client

server:
	$(CC) calc_svc.c calc_clnt.c calc_server.c -o server

clean:
	$(RM) calc_clnt.*
	$(RM) calc_svc.*
	$(RM) calc_xdr.*
	$(RM) calc.h
	$(RM) client
	$(RM) server
	$(RM) *~

