/*=============================================
=            Aluna: Beatriz Rodrigues         =
=            RA: 2014.1.08.006                =
=            Professor: Flavio Gonzaga        =
=            Disciplina: P.E.                 =
=            Período: 2º                      =
=============================================*/


#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"
#include "resolvercubo.h"

int main(){
	Cubo ** cubes;
	FILE * in;	
	FILE * out;
	FILE * op;
	char * auxiliar = malloc(sizeof(char)* 15);
	int numCubos=0;
	int i,j,k;

	numCubos = (contarLinhas("cubo.txt")+1)/61;

	cubes = (Cubo **) malloc(sizeof(Cubo *)*numCubos);

	in = fopen("cubo_atual.txt", "r");

	out  = fopen("saida.txt","w");

	for(i=0;i<numCubos;i++){
		cubes[i] = lerCubo(in);
		fscanf(in, "\n");

	}

	fclose(in);

	passo1(cubes[0]);

	// op = fopen("operacoesparte.txt","r");

	// int cuboAtual;

	// int c = 0;

	// while(!feof(op)){
	// fscanf(op,"%s",auxiliar);
	// if(auxiliar[0]=='1' || auxiliar[0]=='2' || auxiliar[0]=='3'
	// 	|| auxiliar[0]=='4' || auxiliar[0]=='5' || auxiliar[0]=='6'
	// 	 || auxiliar[0]=='7' || auxiliar[0]=='8' || auxiliar[0]=='9'){

	// 	cuboAtual = strtol(auxiliar,NULL,10) - 1;

	// 	} else {
	// 		executarOperacao(cubes[cuboAtual], auxiliar);
	// 	}
	// }

	// fclose(op);

	for(k=0;k<numCubos;k++){

		fprintf(out, "%d\n", k+1 );

	for(i=0;i<6;i++){

		for(j=0;j<9;j++){
			fprintf(out, "%s\n", cubes[k]->faces[i][j]);
		}
		fprintf(out, "\n");
	}

	}

	fclose(out);

	for(i = 0; i < numCubos; i++) {
		free(cubes[i]);
	}

	free(cubes);
	free(auxiliar);

	return 0;



}