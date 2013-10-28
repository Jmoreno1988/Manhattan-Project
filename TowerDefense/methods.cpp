/***
   *  Project TowerDefense
   * 
   *  Methods definition
   *
   ***/

/*****METODOS MAP*****/

//Constructor
map::map(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]){
	inicializar(filas, columnas, repre_blanco, repre_muroH, repre_muroV, tablero);
}

void map::inicializar(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]){
	filas = filas;
	columnas = columnas;
	repre_blanco = repre_blanco;
	repre_muroH = repre_muroH;
	repre_muroV = repre_muroV;
	generar_mapa(tablero);
	
}

//Destructor
map::~map(){};


//Generar mapa(mapa a generar)
void map::generar_mapa(int tablero[][50]){
	for(int i=0; i<10; i++){
                for(int a=0; a<50; a++){
                        mapa[i][a]= tablero[i][a];
                }
        }
	
}

//Pintar mapa(fila, columna y posicion de los enemigos)
void map::pintar_mapa(int fila, int columna, int posicion)
{
	mapa[fila][columna] = 101;
	for(int x=0; x<10; x++){
        	for(int i = 0; i<50; i++){
                	if(mapa[x][i]==0)
                        	printf(" ");
                       	else if (mapa[x][i]==1)
                        	printf("-");
                       	else if (mapa[x][i]==2)
                       		printf("|");
                     	else if (mapa[x][i]>=3 && mapa[x][i]<=61)
                            	printf(" ");
                      	else if (mapa[x][i]==101)
               			printf("X");
             	}
    		printf("\n");
    	}
	mapa[fila][columna] = posicion;

}
/*****FIN METODOS MAP*****/

/*****METODOS ENEMY*****/


//Constructor 
enemy::enemy(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion){
	inicializar(vida, representacion, posicion_fila, posicion_columna, posicion);
}

void enemy::inicializar(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion){
	m_vida = vida;
  	m_representacion = representacion;
  	m_fila = posicion_fila;
  	m_columna = posicion_columna;
  	m_posicion = posicion;
}


//Destructor 
enemy::~enemy(){};

//Movimiento(mapa sobre el que esta moviendose)
void enemy::movimiento(int mapa[][50]){
	if(mapa[m_fila][m_columna+1] == m_posicion+1){
       		m_columna+=1;
      		m_posicion+=1;
      	}

      	if(mapa[m_fila][m_columna-1] == m_posicion+1){
       		m_columna-=1;
              	m_posicion++;
      	}
      	if(mapa[m_fila+1][m_columna] == m_posicion+1){
     		m_fila+=1;
            	m_posicion++;
      	}
      	if(mapa[m_fila-1][m_columna] == m_posicion+1){
             	m_fila-=1;
        	m_posicion++;
     	}
}

//Metodos Getter
int enemy::getVida() const
{
    return m_vida;
}

int enemy::getFila()
{
   return m_fila;
}

int enemy::getColumna()
{
   return m_columna;
}


int enemy::getPosicion()
{
   return m_posicion;
}

//Metodos Setter
void enemy::setVida(int value)
{
    m_vida=value;
}
/*****FIN METODOS ENEMY*****/
