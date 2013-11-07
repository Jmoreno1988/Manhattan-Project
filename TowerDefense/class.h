/***
   *  Project TowerDefense
   * 
   *  Class definition
   *
   ***/

/*****CLASE MAP*****/
class map{
public:
    map(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]);
    ~map();
    void generar_mapa(int tablero[][50]);
    void pintar_mapa(int fila, int columna, int posicion);
private:
    void inicializar(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]);

private:
    int filas;
    int columnas;
    char repre_blanco;
    char repre_muroH;
    char repre_muroV;
public:
    int mapa[10][50];
//    int array_enemigos[];
//    int array_torres[];
};
/*****FIN CLASE MAP****/

/*****CLASE ENEMY****/
class enemy{
public:
    enemy(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion);
    ~enemy();

    //Metodos getter
    int getVida() const;
    char getRepresentacion();
    int getFila();
    int getColumna();
    int getPosicion();

    //Metodos setter
    void setVida(int value);
    void setRepresentacion(char value);
    void setFila(int value);
    void setColumna(int value);
    void setPosicion(int value);

    void movimiento(int mapa[][50]);

private:
    void inicializar(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion);

private:
    int m_vida;
    char m_representacion;
    int m_fila;
    int m_columna;
    int m_posicion;
};
/*****FIN CLASE ENEMY*****/

/*****CLASE TOWER*****/
class tower{
tower(int tipo_torre, int posicion_fila, int posicion_columna, int posicion, int disparo, int rango, char representacion);//tipo_torre array con 1 --> torre W, 2 --> torre V "ejemplo"

};
/*****FIN CLASE TOWER*****/



/*****CLASE CASTILLO*****/

class castillo{
castillo(int vidas, int num_torres_posibles );//num_torres_posibles para los espacios en blanco en el que puedes colocar una torre

};

/*****FIN CLASE CASTILLO*****/

