/***
   *  Project TowerDefense
   *  
   *  Main file
   *
   ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "class.h"
#include "methods.cpp"
#include "mapas.cpp"

int main(){	

	//Creacion de objetos	
	map mapa1(10,50,' ', '-', '|', A);
//	enemy pepe(1, 'X', 2, 0, 3);
	enemy malos[2] = {
		enemy(1, 'X', 2, 0, 3), enemy(1, 'X', 2, 0, 8)
	};

	//Game loop
	while(1){
		usleep(200000);
		system("clear");
		for(int i=0; i<=1; i++){
			malos[i].movimiento(mapa1.mapa);
		}	
//		pepe.movimiento(mapa1.mapa);		
		for(int i=0; i<=1; i++){
			mapa1.pintar_mapa(malos[i].getFila(), malos[i].getColumna(), malos[i].getPosicion());
		}
	}
	return EXIT_SUCCESS;
}

