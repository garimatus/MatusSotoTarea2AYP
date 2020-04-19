#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/*DEFINICION DEL ENUNCIADO*/
typedef char cadena[1024];
typedef struct pasajero{
    cadena rut;
    cadena nombre;
    int edad;
    int fechaSalida;
    int fechaEntrada;
    cadena destino;
    struct pasajero *link;
    }nodo;
typedef nodo *enlace;
typedef enlace aduana[11];

/* FUNCIONES */
char validar_char();
int validar_edad();
void inicializar(aduana listas);
void agregar(aduana listas);
void buscar(aduana listas);
void eliminar(aduana listas);
void liechteinstein(aduana listas);
void lista_info(aduana listas);
void nombre_info(aduana listas);
void brocas(aduana listas);
int validar_rut(cadena rut);

#endif // FUNCIONES_H_INCLUDED
