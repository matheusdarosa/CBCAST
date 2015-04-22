O projeto foi desenvolvido utilizando a
técnica RPC (Remote Procedure Call) e a linguagem de
programação C para a implementação do algoritmo de acesso à
Seção Crítica (SC) distribuída, baseado na passagem de um
token.

Projeto desenvolvido como parte da disciplina Programação Paralela e Distribuída da PUCRS(http://www.pucrs.br/).

#Instalação
Deve se alterar o arquivo header.h com os IPs de cada nó. Após isso deve descomentar o bloco de if/else na função **start_servers_1_svc** no arquivo do servidor.

#Criação do arquivo
O código busca por aqui um arquivo chamado data.txt. Para que o código funcione corretamente basta criar um link simbólico na pasta do trabalho para um arquivo em uma pasta compartilhada em rede. O comando a seguir deve ser executado pelo terminal dentro da pasta do trabalho:
```
ln -s <arquivo em pasta compartilhada> data.txt
```
#Exemplo:

```
ln -s /pastacompartilhadanarede/data.txt data.txt
```
#Compilação

Existe um makefile dentro da pasta. Basta digitar make no terminal.

#Execução

Para execução o formato é:
```
./client <IP do meu servidor> <numero do meu servidor no anel>
```
*Na prática o IP passado é o da própria máquina.*

Passos para execução:
1. Compila
2. Dispara o servidor em todas as máquinas
3. Dispara o client em cada máquina(o número 1 irá esperar 15 segundos para iniciar a passagem do token)