#ifndef RESCUBO_H
#define RESCUBO_H
	int eDaCor(char * quadradinho, char * cor);
	int encontrarFace(Cubo * cubo, char * cor);
	void branco1(Cubo * cube);
	void branco3(Cubo * cube);
	void branco5(Cubo * cube);
	void branco7(Cubo * cube);
	void passo1(Cubo * cube);
	void passo2( Cubo * cube);
	void descerCantoBranco(Cubo * cube);
	int faceEdaCor(char ** face, char * cor);
#endif