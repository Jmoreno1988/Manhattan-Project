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
	
	//Creacion de objetos	
	map mapa1(10,50,' ','-','|', A);
	enemy malos[8] = {
		//enemy(vida, repre, fila_ini, columna_ini, posicion_camino, turno_salida)
		enemy(1,'X',2,0,3,1), enemy(1,'X',2,0,3,2),
		enemy(1,'X',2,0,3,10), enemy(1,'X',2,0,3,16),
		enemy(1,'X',2,0,3,20), enemy(1,'X',2,0,3,23),
		enemy(1,'X',2,0,3,30), enemy(1,'X',2,0,3,35),		
	};

	mapa1.setTotalEnemigos(length(malos));//Saber total de enemigos

	//Game loop
	while(1){
		usleep(200000);
		system("clear");
		fflush(stdout);

                // Controlador de la salida de los enemigos --> meterlo dentro de una clase!!        
                for(int i=0; i<length(malos); i++){
                        malos[i].setTurno(malos[i].getTurno()-1);
                }

		// Movimiento de todos los enmigos
		for(int i=0; i<mapa1.getTotalEnemigos(); i++){
			malos[i].movimiento(mapa1.mapa);
		}		
 
		mapa1.pintar_mapa(malos);

		}
	return EXIT_SUCCESS;
}

