#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cubo.h"
#include "resolvercubo.h"

int eDaCor(char * quadradinho, char * cor){

	if(!strcmp(quadradinho,cor)){

		return 1;
	}

		return 0;
}

int encontrarFace(Cubo * cubo, char * cor){

	int i;

	for(i=0; i < 6; i++){
		if(!strcmp(cubo->faces[i][4],cor)){

			return i;

		}
	}

}


void passo1(Cubo * cube){


	int face;
	face = encontrarFace(cube,"am");
	if(face==4){

		girarCuboBaixo(cube);

	}else if(face==1) {
		girarCuboDireita(cube);

	}else if(face==3){
		girarCuboEsquerda(cube);

	}else if(face==2){
		girarCuboBaixo(cube);
		girarCuboBaixo(cube);

	}else if(face==5){
		girarCuboCima(cube);

	}

	branco1(cube);


}

void branco1(Cubo * cube){

	if(!eDaCor(cube->faces[0][1],"br")){

		if(eDaCor(cube->faces[4][1],"br")){

			girarLinhaEsquerda(cube,2);
			girarColunaBaixo(cube,2);
			girarFaceEsquerda(cube);

		}else if(eDaCor(cube->faces[4][3],"br")){

			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);

		}else if(eDaCor(cube->faces[4][5],"br")){

			girarColunaBaixo(cube,2);
			girarFaceEsquerda(cube);

		}else if(eDaCor(cube->faces[4][7],"br")){

			girarLinhaEsquerda(cube,2);
			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);
			
/*face1*/}else if(eDaCor(cube->faces[1][3],"br")){

			girarColunaBaixo(cube,0);
			girarLinhaDireita(cube,2);
		}else if(eDaCor(cube->faces[1][1],"br")){

			girarLinhaDireita(cube,2);
	

		}else if(eDaCor(cube->faces[1][5],"br")){

			girarColunaCima(cube,0);
			girarLinhaDireita(cube,2);
	

		}else if(eDaCor(cube->faces[1][7],"br")){
			girarColunaCima(cube,0);
			girarColunaCima(cube,0);
			girarLinhaDireita(cube,2);		
		
/*face2*/}else if(eDaCor(cube->faces[2][3],"br")){

			girarFaceDireita(cube);
			girarColunaBaixo(cube,2);
			girarColunaBaixo(cube,2);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[2][1],"br")){

			girarLinhaDireita(cube,2);
			girarLinhaDireita(cube,2);
	

		}else if(eDaCor(cube->faces[2][5],"br")){

			girarFaceEsquerda(cube);
			girarColunaCima(cube,2);
			girarColunaCima(cube,2);
			girarFaceDireita(cube);
	

		}else if(eDaCor(cube->faces[2][7],"br")){
		
			girarFaceDireita(cube);
			girarFaceDireita(cube);
			girarLinhaDireita(cube,0);
			girarFaceEsquerda(cube);
			girarFaceEsquerda(cube);
		}else if(eDaCor(cube->faces[3][3],"br")){

		girarColunaCima(cube,2);
		girarLinhaEsquerda(cube,2);
	
		
	}else if(eDaCor(cube->faces[3][1],"br")){

		girarLinhaEsquerda(cube,2);
	

	}else if(eDaCor(cube->faces[3][5],"br")){

		girarColunaBaixo(cube,2);
		girarLinhaEsquerda(cube,2);

	

	}else if(eDaCor(cube->faces[3][7],"br")){

		girarColunaCima(cube,2);
		girarColunaCima(cube,2);
		girarLinhaEsquerda(cube,2);

	}else if(eDaCor(cube->faces[5][3],"br")){

		girarColunaBaixo(cube,0);
		girarFaceEsquerda(cube);
		girarColunaBaixo(cube,0);
		girarColunaBaixo(cube,0);
		girarFaceDireita(cube);	
		
	}else if(eDaCor(cube->faces[5][1],"br")){

		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,0);
		girarFaceDireita(cube);

	}else if(eDaCor(cube->faces[5][5],"br")){

		girarColunaCima(cube,2);
		girarFaceEsquerda(cube);


	

	}else if(eDaCor(cube->faces[5][7],"br")){

		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,2);
		girarFaceEsquerda(cube);

	}		



	}

}

void branco3(Cubo * cube){

	if(!eDaCor(cube->faces[0][3],"br")){
		if(eDaCor(cube->faces[4][3],"br")){

			girarColunaBaixo(cube,0);

		}else if(eDaCor(cube->faces[4][1],"br")){

			girarLinhaDireita(cube,2);
			girarColunaBaixo(cube,0);
			girarLinhaEsquerda(cube,2);
			
		}else if(eDaCor(cube->faces[4][5],"br")){
			girarLinhaDireita(cube,2);
			girarLinhaDireita(cube,2);
			girarColunaBaixo(cube,0);
			girarLinhaEsquerda(cube,2);
			girarLinhaEsquerda(cube,2);
			
			
		}else if(eDaCor(cube->faces[1][3],"br")){
			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);
			girarLinhaDireita(cube,2);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[1][1],"br")){
			girarFaceDireita(cube);
			girarLinhaDireita(cube,2);
			girarFaceEsquerda(cube);

			
		}else if(eDaCor(cube->faces[1][5],"br")){
			girarColunaCima(cube,0);
			girarFaceDireita(cube);
			girarLinhaDireita(cute,2);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[1][7],"br")){
			girarColunaCima(cube,0);
			girarColunaCima(cube,0);
			girarFaceDireita(cube);
			girarLinhaDireita(cube,2);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[2][1],"br")){
			girarLinhaDireita(cube,2);
			girarColunaBaixo(cube,0);
			girarLinhaEsquerda(cube,2);
			girarColunaCima(cube,0);
			girarFaceDireita(cube);
			girarLinhaEsquerda(cube,2);
			girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[2][3],"br")){
			girarLinhaEsquerda(cube,2);
			girarColunaBaixo(cube,2);
			girarLinhaDireita(cube,2);
			girarLinhaDireita(cube,2);
			girarColunaBaixo(cube,0);
			girarLinhaEsquerda(cube,2);

	}else if(eDaCor(cube->faces[2][5],"br")){
			
			girarColunaBaixo(cube,0);
			girarColunaBaixo(cube,0);

	}else if(eDaCor(cube->faces[2][7],"br")){
		
			girarLinhaDireita(cube,0);
			girarColunaBaixo(cube,0);
			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);
			girarLinhaDireita(cube,2);
			girarFaceEsquerda(cube);			

	}else if(eDaCor(cube->faces[3][1],"br")){
		
		girarColunaCima(cube,2);
		girarColunaCima(cube,2);
		girarLinhaDireita(cube,0);
		girarLinhaDireita(cube,0);
		girarColunaBaixo(cube,0);
		girarColunaBaixo(cube,0);
		girarFaceDireita(cube);
		girarLinhaDireita(cube,2);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][3],"br")){
		
		girarColunaCima(cube,2);
		girarLinhaDireita(cube,0);
		girarLinhaDireita(cube,0);
		girarColunaBaixo(cube,0);
		girarColunaBaixo(cube,0);
		girarFaceDireita(cube);
		girarLinhaDireita(cube,2);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][5],"br")){
		
		girarColunaBaixo(cube,2);
		girarLinhaDireita(cubo,0);
		girarLinhaDireita(cubo,0);
		girarColunaCima(cube,2);
		girarColunaCima(cube,2);
		girarFaceDireita(cube);
		girarLinhaDireita(cube,2);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][7],"br")){
		
		girarLinhaDireita(cube,0);
		girarLinhaDireita(cube,0);
		girarColunaCima(cube,0);
		girarColunaCima(cube,0);
		girarFaceDireita(cube);
		girarLinhaDireita(cube,2);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[5][1],"br")){
		
		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,0);

	}else if(eDaCor(cube->faces[5][3],"br")){
		
		girarColunaCima(cube,0);

	}else if(eDaCor(cube->faces[5][5],"br")){
		
		girarLinhaEsquerda(cube,0);
		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,0);

	}else if(eDaCor(cube->faces[5][7],"br")){
		
		girarLinhaDireita(cube,0);
		girarColunaCima(cube,0);

	}

	}
}//novo

void branco5(Cubo * cube){

	if(!eDaCor(cube->faces[0][5],"br")){
		if(eDaCor(cube->faces[4][3],"br")){

			girarFaceEsquerda(cube);
			girarFaceEsquerda(cube);
			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);
			girarFaceDireita(cube);

		}else if(eDaCor(cube->faces[4][1],"br")){

			girarLinhaEsquerda(cube,2);
			girarColunaBaixo(cube,2);
			girarLinhaDireita(cube,2);
			
		}else if(eDaCor(cube->faces[4][5],"br")){
			
			girarColunaBaixo(cube,2);
			
			
		}else if(eDaCor(cube->faces[1][3],"br")){
			girarFaceDireita(cube);
			girarColunaCima(cube,0);
			girarLinhaEsquerda(cube,0);
			girarLinhaEsquerda(cube,0);
			girarLinhaEsquerda(cube,0);
			girarFaceEsquerda(cube);

			
		}else if(eDaCor(cube->faces[1][1],"br")){
			
			girarFaceDireita(cube);
			girarColunaCima(cube,0);
			girarColunaCima(cube,0);
			girarLinhaDireita(cube,0);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[1][7],"br")){
			girarFaceDireita(cube);
			girarLinhaDireita(cube,0);
			girarFaceEsquerda(cube);
			
		}else if(eDaCor(cube->faces[2][1],"br")){
			girarLinhaEsquerda(cube,2);
			girarColunaCima(cube,2);
			girarColunaCima(cube,2);
			girarLinhaDireita(cube,2);
			girarFaceDireita(cube);
			girarLinhaEsquerda(cube,0);
			girarFaceEsquerda(cube);

		}else if(eDaCor(cube->faces[2][3],"br")){

			girarColunaBaixo(cube,2);
			girarColunaBaixo(cube,2);

	}else if(eDaCor(cube->faces[2][5],"br")){
			
			girarFaceEsquerda(cube);
			girarFaceEsquerda(cube);
			girarColunaBaixo(cube,0);
			girarFaceDireita(cube);
			girarFaceDireita(cube);

			
	}else if(eDaCor(cube->faces[2][7],"br")){
		
			girarFaceDireita(cube);
			girarLinhaEsquerda(cube,0);
			girarLinhaEsquerda(cube,0);
			girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][1],"br")){
		
		girarColunaCima(cube,2);
		girarColunaCima(cube,2);
		girarFaceDireita(cube);
		girarLinhaEsquerda(cube,0);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][3],"br")){
		
		girarColunaBaixo(cube,2);
		girarFaceDireita(cube);
		girarLinhaEsquerda(cube,0);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[3][5],"br")){
		
		girarFaceDireita(cube);
		girarFaceDireita(cube);
		girarColunaBaixo(cube,0);
		girarColunaBaixo(cube,0);
		girarFaceDireita(cube);
		girarFaceDireita(cube);


	}else if(eDaCor(cube->faces[3][7],"br")){
		
		girarFaceDireita(cube);
		girarLinhaEsquerda(cube,0);
		girarLinhaEsquerda(cube,0);
		girarFaceEsquerda(cube);

	}else if(eDaCor(cube->faces[5][1],"br")){
		
		girarLinhaDireita(cube,0);
		girarColunaCima(cube,2);
		

	}else if(eDaCor(cube->faces[5][3],"br")){
		
		girarLinhaEsquerda(cube,0);
		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,2);
		girarColunaCima(cube,2);

	}else if(eDaCor(cube->faces[5][5],"br")){
		
		girarColunaCima(cube,2);

	}else if(eDaCor(cube->faces[5][7],"br")){
		
		girarLinhaEsquerda(cube,0);
		girarColunaCima(cube,2);

	}

	}
}








