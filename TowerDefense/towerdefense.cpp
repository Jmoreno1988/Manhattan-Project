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
	enemy pepe(1, 'X', 2, 0, 3);

	//Game loop
	while(1){
		usleep(200000);
		system("clear");

		pepe.movimiento(mapa1.mapa);		

		mapa1.pintar_mapa(pepe.getFila(), pepe.getColumna(), pepe.getPosicion());
	}
	return EXIT_SUCCESS;
}

