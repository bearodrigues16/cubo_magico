#ifndef CUBO_H
#define CUBO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	char *** faces;				

} Cubo;

void imprimirCubo(Cubo * cube);

Cubo * lerCubo(FILE * in);

char * copiaQuadrado(char * quadrado);

void transposta(char ** matriz);

void girarLinhaEsquerda(Cubo * cube, int linha);

void girarLinhaDireita(Cubo * cube, int linha);

void girarColunaCima(Cubo * cube, int coluna);

void girarColunaBaixo(Cubo * cube, int coluna);

void girarCuboEsquerda(Cubo * cube);

void girarCuboDireita(Cubo * cube);

void girarCuboCima(Cubo * cube);

void girarCuboBaixo(Cubo * cube );

void girarFaceDireita(Cubo * cube);

void girarFaceEsquerda(Cubo * cube);

void executarOperacao(Cubo * cube, char * operacao);

void executarOperacoes(Cubo ** cubes, char * arquivo);

int contarLinhas(char * arquivo);

#endif