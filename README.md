O projeto foi desenvolvido utilizando a
t�cnica RPC (Remote Procedure Call) e a linguagem de
programa��o C para a implementa��o do algoritmo de acesso �
Se��o Cr�tica (SC) distribu�da, baseado na passagem de um
token.

Projeto desenvolvido como parte da disciplina Programa��o Paralela e Distribu�da da PUCRS(http://www.pucrs.br/).

#Instala��o
Deve se alterar o arquivo header.h com os IPs de cada n�. Ap�s isso deve descomentar o bloco de if/else na fun��o **start_servers_1_svc** no arquivo do servidor.

#Cria��o do arquivo
O c�digo busca por aqui um arquivo chamado data.txt. Para que o c�digo funcione corretamente basta criar um link simb�lico na pasta do trabalho para um arquivo em uma pasta compartilhada em rede. O comando a seguir deve ser executado pelo terminal dentro da pasta do trabalho:
```
ln -s <arquivo em pasta compartilhada> data.txt
```
#Exemplo:

```
ln -s /pastacompartilhadanarede/data.txt data.txt
```
#Compila��o

Existe um makefile dentro da pasta. Basta digitar make no terminal.

#Execu��o

Para execu��o o formato �:
```
./client <IP do meu servidor> <numero do meu servidor no anel>
```
*Na pr�tica o IP passado � o da pr�pria m�quina.*

Passos para execu��o:
1. Compila
2. Dispara o servidor em todas as m�quinas
3. Dispara o client em cada m�quina(o n�mero 1 ir� esperar 15 segundos para iniciar a passagem do token)