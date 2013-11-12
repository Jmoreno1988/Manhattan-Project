/***
   *  Project TowerDefense
   * 
   *  Class definition
   *
   ***/

/*****CLASE ENEMY****/
// Es imprescindible que la clase enemy se coloque antes de la clase map!!!!
class enemy{
public:
    enemy(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion, int turno);
    ~enemy();

    //Metodos getter
    int getVida() const;
    char getRepresentacion();
    int getFila();
    int getColumna();
    int getPosicion();
    int getTurno();

    //Metodos setter
    void setVida(int value);
    void setRepresentacion(char value);
    void setFila(int value);
    void setColumna(int value);
    void setPosicion(int value);
    void setTurno(int value);

    void movimiento(int mapa[][50]);

private:
    void inicializar(int vida, char representacion, int posicion_fila, int posicion_columna, int posicion, int turno);

private:
    int m_vida;
    char m_representacion;
    int m_fila;
    int m_columna;
    int m_posicion;
    int m_turno;
};
/*****FIN CLASE ENEMY*****/


/*****CLASE MAP*****/
class map{
public:
    map(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]);
    ~map();
    void generar_mapa(int tablero[][50]);
    void pintar_mapa(enemy malos[]);

    // Metodos getter
    int getTotalEnemigos();

    // Metodos setter
    void setTotalEnemigos(int value);

private:
    void inicializar(int filas, int columnas, char repre_blanco, char repre_muroH, char repre_muroV, int tablero[][50]);

private:
    int filas;
    int columnas;
    char repre_blanco;
    char repre_muroH;
    char repre_muroV;
    int total_enemigos;
public:
    int mapa[10][50];
//    int array_enemigos[];
//    int array_torres[];
};
/*****FIN CLASE MAP****/
