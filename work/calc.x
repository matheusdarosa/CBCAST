/**

Pontificia Universidade Católica do RGS - PUCRS
Curso de Engenharia da Computação
Trabalho T1 da Disciplina de Programacao Paralela e distrinbuída


Alunos: Carolina Toscani e Matheus da Rosa

Data:16.09.2013



Arquivo de definição de interface (IDF)

Contém a definição das funções remotas

para compilar: no terminal ir até a pasta que contém
os arquivos e dar o comando Make

após executar ./server
abrir outra janela e ./client seuip 


**/

program CALCULA{
	version CALCVERSION{
	    int START_SERVERS(int)		= 1;
		int PASS_TOKEN(void)	= 2;
		int P(void)      = 3;	
		int V(void) = 4;
	} =1;
} = 0x20000003;
	
