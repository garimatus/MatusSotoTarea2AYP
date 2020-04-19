#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

/* autores: Edgar I. Matus Soto / Nicolás Jimenez J. 9/27/2016.
Descripción: Tarea N°2 de Algoritmos Y Programación sección 412 Profesora Laura Setti Duque.
Ayudante Pablo Jesus Salas Miranda. */

int main(){
    char o;
    int sw=0;
    aduana listas;
    do{
        printf("MENU\n¯¯¯¯\n\na) Inicializar una aduana (si hay datos se perderan).\nb) Agregar un pasajero segun su rut.\nc) Eliminar un pasajero segun su rut.\nd) Buscar un pasajero segun su rut.\ne) Obtener la edad promedio de los pasajeros que viajaron a Liechtenstein.\nf) Desplegar la informacion de todos los pasajeros cuyo digito verificador se solicita por teclado.\ng) Desplegar nombre y cantidad de dias fuera del pais para aquellos pasajeros cuyo digito verificador se solicita por teclado.\nh) Obtener el numero de menores de edad que estuvieron mas de un mes fuera del pais.\ni) Salir.\nIngrese una opcion : ");
        o=validar_char();/* 'o' es validado en la funcion para ser de longitud 1 en una cadena de caracteres donde sera el caracter de indice 0*/
        switch(o){
            case 'i':
                system("cls");
                printf("Hasta Luego!!");
                break;
            case 'a':
                inicializar(listas);
                sw=1;
                /* la aduana ha sido inicializada por lo que las listas se puede ocupar y el switch
                es igual a 1 ahora */
                system("cls");
                printf("AVISO: ADUANA INICIALIZADA.\n");
                break;
            case 'b':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                    /* si el switch es 0 no se puede ingresar a ninguna función */
                }
                else{
                    agregar(listas);
                }
                break;
            case 'c':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    eliminar(listas);
                }
                break;
            case 'd':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    buscar(listas);
                }
                break;
            case 'e':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    liechteinstein(listas);
                }
                break;
            case 'f':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    lista_info(listas);
                }
                break;
            case 'g':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    nombre_info(listas);
                }
                break;
            case 'h':
                if(sw==0){
                    system("cls");
                    printf("AVISO: LA ADUANA NO HA SIDO INICIALIZADA.\n");
                }
                else{
                    brocas(listas);
                }
                break;
            default:
                system("cls");
                printf("AVISO: La opcion ingresada no existe.\n");
        }
    }while(o!='i');
    /* el menu se sostiene con un do mientras la opción sea diferente del caracter i */
    return 0;
}

