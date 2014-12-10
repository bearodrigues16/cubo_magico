#include "cubo.h"

#define DEBUG 1

void imprimirCubo(Cubo * cube) {
	int i;

	printf("== Cubo ==\n");

	for(i=0;i<6;i++){

		printf("%s %s %s\n", cube->faces[i][0], cube->faces[i][1], cube->faces[i][2]);
		printf("%s %s %s\n", cube->faces[i][3], cube->faces[i][4], cube->faces[i][5]);
		printf("%s %s %s\n", cube->faces[i][6], cube->faces[i][7], cube->faces[i][8]);
		printf("\n");
	}	
	printf("== Fim cubo ==\n");
}

Cubo * lerCubo(FILE * in) {

	
	Cubo * cube; // só posso retornar não ponteiros de tipos primitivos. ;D

	int i,j;

	cube = (Cubo *) malloc(sizeof(Cubo));

	cube->faces =  (char***) malloc(sizeof(char **)*6);

	for (i=0;i<6;i++){

		cube->faces[i] = (char **) malloc(sizeof(char *)*9);

			for(j=0;j<9;j++){

				cube->faces[i][j] = (char *) malloc(sizeof(char)*3);


			}



	}

	fscanf(in, "%s", cube->faces[0][0]);
	for(i=0;i<6;i++){

		for(j=0;j<9;j++){
			fscanf(in, "%s", cube->faces[i][j]);
		}
	}

	return cube;

}

char * copiaQuadrado(char * quadrado) {

	int i;
 
	char * retorno = malloc(sizeof(char)*3);

	for(i=0;i<3;i++){

		retorno[i] = quadrado[i];

	}
	
	return retorno;


}

void transposta(char ** matriz) {

	int i, j;
	char ** m = malloc(9 * sizeof(char*));

	for (i = 0; i < 9; ++i){
		m[i] = malloc(3 * sizeof(char));
	}

	m[(0 *3) + 2] = matriz[(0 * 3) + 0];
	m[(1 *3) + 2] = matriz[(0 * 3) + 1];
	m[(2 *3) + 2] = matriz[(0 * 3) + 2];
	m[(0 *3) + 1] = matriz[(1 * 3) + 0];
	m[(1 *3) + 1] = matriz[(1 * 3) + 1];
	m[(2 *3) + 1] = matriz[(1 * 3) + 2];
	m[(0 *3) + 0] = matriz[(2 * 3) + 0];
	m[(1 *3) + 0] = matriz[(2 * 3) + 1];
	m[(2 *3) + 0] = matriz[(2 * 3) + 2];


	for(i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++){
			matriz[(i * 3) + j] = m[(i * 3) + j];
		}
	}


}

void girarLinhaEsquerda(Cubo * cube, int linha) { //mudei

	if(DEBUG) {
		printf("Linha %d esquerda\n", linha);
	}

	char ** auxiliar = (char **) malloc(sizeof(char *)*3);
	int i,j;


	for(i=2;i>=0;i--){

	auxiliar[i] = copiaQuadrado(cube->faces[3][linha*3+i]);

	}
	for(i=2;i>=0;i--){
		for(j=2;j>=0;j--){
		
		cube->faces[i+1][linha*3+j] = copiaQuadrado(cube->faces[i][linha*3+j]);

		}

	}
	for(j=2;j>=0;j--){
		cube->faces[0][linha*3+j] = copiaQuadrado(auxiliar[j]);
	}

	if(linha == 0){

		transposta(cube->faces[5]);
		transposta(cube->faces[5]);
		transposta(cube->faces[5]);


	}
	if(linha == 2){

		transposta(cube->faces[4]);


	}



}

void girarLinhaDireita(Cubo * cube, int linha) { //mudei

	if(DEBUG) {
		printf("Linha %d direita\n", linha);
	}

	char ** auxiliar = (char **) malloc(sizeof(char *)*3);
	int i,j;


	for(i=2;i>=0;i--){

	auxiliar[i] = copiaQuadrado(cube->faces[0][linha*3+i]);

	}
	for(i=0;i<3;i++){ //mudei aqui
		for(j=2;j>=0;j--){
		
		cube->faces[i][linha*3+j] = copiaQuadrado(cube->faces[i+1][linha*3+j]);

		}

	}
	for(j=2;j>=0;j--){
		cube->faces[3][linha*3+j] = copiaQuadrado(auxiliar[j]);
	}

	if(linha == 0){

		transposta(cube->faces[5]);

	}
	if(linha == 2){
		transposta(cube->faces[4]);
		transposta(cube->faces[4]);
		transposta(cube->faces[4]);
	}

}

void girarColunaCima(Cubo * cube, int coluna) {

	if(DEBUG) {
		printf("Coluna %d cima\n", coluna);
	}

	char ** auxiliar = (char **) malloc(sizeof(char *)*3);
	int i;

	for(i=0;i<3;i++){
		auxiliar[i] = cube->faces[5][coluna+3*i];
	}
	for(i=0;i<3;i++){

		cube->faces[5][coluna+3*i] = copiaQuadrado(cube->faces[2][(2-coluna)+3*(2 - i)]);
		cube->faces[2][(2-coluna)+3*(2-i)] = copiaQuadrado(cube->faces[4][coluna+3*i]);
		cube->faces[4][coluna+3*i] = copiaQuadrado(cube->faces[0][coluna+3*i]);
		cube->faces[0][coluna+3*i] = copiaQuadrado(auxiliar[i]);		

	}

	if(coluna == 0){
		transposta(cube->faces[1]);
		transposta(cube->faces[1]);
		transposta(cube->faces[1]);

	}
	if(coluna == 2){
		transposta(cube->faces[3]);
	}

}

void girarColunaBaixo(Cubo * cube, int coluna) {

	if(DEBUG) {
		printf("Coluna %d baixo\n", coluna);
	}

	char ** auxiliar= (char **) malloc(sizeof(char *)*3);
	int i;

	for(i=0;i<3;i++){

		auxiliar[i] = cube->faces[0][coluna+3*i];

	}
	for(i=0;i<3;i++){

		cube->faces[0][coluna+3*i] = copiaQuadrado(cube->faces[4][coluna+3*i]);
		cube->faces[4][coluna+3*i] = copiaQuadrado(cube->faces[2][(2-coluna)+3*(2-i)]);
		cube->faces[2][(2 - coluna)+3*(2 - i)] = copiaQuadrado(cube->faces[5][coluna+3*i]);
		cube->faces[5][coluna+3*i] = copiaQuadrado(auxiliar[i]);


	}

	if(coluna == 0){
		transposta(cube->faces[1]);
	}
	if(coluna == 2){
		transposta(cube->faces[3]);
		transposta(cube->faces[3]);
		transposta(cube->faces[3]);
	}

}

void girarCuboEsquerda(Cubo * cube) {

	if(DEBUG) {
		printf("Girar cubo esquerda\n");
	}

	girarLinhaEsquerda(cube,0);
	girarLinhaEsquerda(cube,1);
	girarLinhaEsquerda(cube,2);



}

void girarCuboDireita(Cubo * cube) {

	if(DEBUG) {
		printf("Girar cubo direita\n");
	}

	girarLinhaDireita(cube,0);
	girarLinhaDireita(cube,1);
	girarLinhaDireita(cube,2);


}

void girarCuboCima(Cubo * cube) {

	if(DEBUG) {
		printf("Girar cubo cima\n");
	}

	girarColunaCima(cube,0);
	girarColunaCima(cube,1);
	girarColunaCima(cube,2);

}

void girarCuboBaixo(Cubo * cube ) {

	if(DEBUG) {
		printf("Girar cubo baixo\n");
	}

	girarColunaBaixo(cube,0);
	girarColunaBaixo(cube,1);
	girarColunaBaixo(cube,2);


}

void girarFaceDireita(Cubo * cube) {
	if(DEBUG) {
		printf("Girar face pra direita\n");
	}

	girarCuboDireita(cube);
	girarColunaCima(cube, 2);
	girarCuboEsquerda(cube);
}

void girarFaceEsquerda(Cubo * cube) {

	if(DEBUG) {
		printf("Girar face pra esquerda\n");
	}

	girarCuboEsquerda(cube);
	girarColunaCima(cube, 0);
	girarCuboDireita(cube);
			
}

void executarOperacoes(Cubo ** cubes, char * arquivoOperacoes) {

	FILE * op;
	FILE * saida;

	char * auxiliar = malloc(sizeof(char) * 3);

	int i, j;

	saida =  fopen("saidaoperacoes.txt", "w");
	op = fopen(arquivoOperacoes,"r");

	int cuboAtual;

	int c = 0;

	while(!feof(op)) {
		fscanf(op,"%s",auxiliar);
		if(auxiliar[0]=='1' || auxiliar[0]=='2' || auxiliar[0]=='3'
			|| auxiliar[0]=='4' || auxiliar[0]=='5' || auxiliar[0]=='6'
			|| auxiliar[0]=='7' || auxiliar[0]=='8' || auxiliar[0]=='9') {

			cuboAtual = strtol(auxiliar,NULL,10) - 1;
			fprintf(saida, "%d\n\n", cuboAtual);

		} else {
			fprintf(saida, "Operação: %s\n\n", auxiliar);

			executarOperacao(cubes[cuboAtual], auxiliar);

			for(i=0;i < 6;i++){

				for(j=0;j < 9;j++) {
					fprintf(saida, "%s\n", cubes[cuboAtual]->faces[i][j]);
				}
				fprintf(saida, "\n");
			}

			fprintf(saida, "\n----------\n\n");
		}
	}

	free(auxiliar);

	fclose(saida);
	fclose(op);

}

void executarOperacao(Cubo * cube, char * operacao) {

	int linha,coluna; 

	if(operacao[0] == 'L' && operacao[1]=='i'){

		linha = (operacao[2] - '0'); //0, distancia que esta do char 0
		
		if(operacao[3]=='E' && operacao[4]=='s'){

			girarLinhaEsquerda(cube,linha);
			return;

		}
		girarLinhaDireita(cube,linha);
		return;

	}
	if(operacao[0] == 'C' && operacao[1]=='l'){
		coluna = (operacao[2] - '0');
		if(operacao[3] == 'C' && operacao[4] == 'i'){

			girarColunaCima(cube,coluna);
			return;
		}
		girarColunaBaixo(cube,coluna);
		return;
	}
	if(operacao[0] == 'F' && operacao[1]=='a'){

		if(operacao[2] == 'E' && operacao[3] == 's'){

			girarFaceEsquerda(cube);
			return;

		}
		girarFaceDireita(cube);
		return;

	}
	if(operacao[0] == 'C' && operacao[1]=='b'){

		if(operacao[2]=='E' && operacao[3]=='s'){

			girarCuboEsquerda(cube);
			return;
		}
		if(operacao[2]=='D' && operacao[3]=='i'){

			girarCuboDireita(cube);
			return;
		}
		if(operacao[2]=='C' && operacao[3]=='i'){

			girarCuboCima(cube);
			return;
		}
		girarCuboBaixo(cube);

	}

}

int contarLinhas(char * arquivo) {

	FILE *fp;
	char ch;
	int linhas=0;

	fp = fopen(arquivo,"r");


	while(!feof(fp)){
  	ch = fgetc(fp);
 	 if(ch == '\n'){
    	linhas++;
  		}
	}

	fclose(fp);

	return linhas;

}