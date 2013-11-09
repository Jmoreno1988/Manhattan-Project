/***
   *  Project TowerDefense
   *  
   *  Main file
   *
   ***/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "class.h"
#include "methods.cpp"
#include "mapas.cpp"

#define length(x) (sizeof(x)/sizeof(x[0]))


int main(){	

	int posiciones_enemigos[50];
	int total_enemigos = 10;
	
	//Creacion de objetos	
	map mapa1(10,50,' ', '-', '|', A);
	enemy malos[10] = {
		//enemy(vida, repre, fila_ini, columna_ini, posicion_camino, turno_salida)
		enemy(1,'X',2,0,3,1), enemy(1,'X',2,0,3,2),
		enemy(1,'X',2,0,3,5), enemy(1,'X',2,0,3,6),
		enemy(1,'X',2,0,3,10), enemy(1,'X',2,0,3,13),
		enemy(1,'X',2,0,3,14), enemy(1,'X',2,0,3,17),
		enemy(1,'X',2,0,3,19), enemy(1,'X',2,0,3,25),
		
	};

	//Game loop
	while(1){

		usleep(300000);
		system("clear");
		fflush(stdout);

		for(int i=0; i<total_enemigos; i++){
			malos[i].movimiento(mapa1.mapa);
		}	

		for(int i=0; i<length(malos); i++){
			posiciones_enemigos[i] = malos[i].getPosicion();
		//	total_enemigos ++;
		}		
	
		// Controlador de salida	
		for(int i=0; i<length(malos); i++){
			malos[i].setTurno(malos[i].getTurno()-1);
		}		

		mapa1.pintar_mapa(malos, total_enemigos);
		}
	return EXIT_SUCCESS;
}

