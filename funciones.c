#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void inicializar(aduana listas){
    listas[0]=NULL;
    listas[1]=NULL;
    listas[2]=NULL;
    listas[3]=NULL;
    listas[4]=NULL;
    listas[5]=NULL;
    listas[6]=NULL;
    listas[7]=NULL;
    listas[8]=NULL;
    listas[9]=NULL;
    listas[10]=NULL;
}/* en la función inicializar se le da a las listas el valor nulo */

void agregar(aduana listas){
    enlace p;
    int fecha,edad,dig;
    cadena rut;
    cadena destino;
    p=(enlace)malloc(sizeof(struct pasajero));
    printf("Ingrese rut: ");
    fflush(stdin);
    gets(rut);
    dig=validar_rut(rut);
    /* obtengo el digito verificador con la funcion si no es valido retorna el valor NULO */
    while(dig==-1){
        printf("El rut no es valido.\nIngrese rut del pasajero: ");
        fflush(stdin);
        gets(rut);
        dig=validar_rut(rut);
    }
    strcpy(p->rut,rut);
    /* copio el string de rut al nodo*/
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(p->nombre);
    edad=validar_edad();
    /* obtengo la edad por la funcion, si no es valida retorna un 0 */
    while(edad==0){
        printf("La edad no es valida.\n");
        edad=validar_edad();
    }
    /* si la edad es valida la edad del nodo sera el entero que cruza el ciclo while */
    p->edad=edad;
    printf("Ingrese fecha de salida (DD/MM/AA): ");
    scanf("%d",&fecha);
    while(validar_fecha(fecha)==0){
        printf("La fecha no es valida.\nIngrese fecha de salida (DD/MM/AA): ");
        scanf("%d",&fecha);
    }
    /* si la fecha no es del formato solicitado retorna un 0 desde la funcion */
    p->fechaSalida=fecha;
    printf("Ingrese fecha de Entrada (DD/MM/AA): ");
    scanf("%d",&fecha);
    while(validar_fecha(fecha)==0){
        printf("La fecha no es valida.\nIngrese fecha de entrada (DD/MM/AA): ");
        scanf("%d",&fecha);
    }
    /* misma funcion, misma variable usada */
    p->fechaEntrada=fecha;
    printf("Ingrese Destino: ");
    fflush(stdin);
    gets(destino);
    while(validar_destino(destino)==0){
        printf("destino no valido.\nPorfavor vuelva a ingresar destino: ");
        gets(destino);
    }
    /* si el destino es una cadena de caracteres sin nada mas que letras
    es valido si no es asi retorna 0 */
    strcpy(p->destino,destino);
    p->link=NULL;
    if(listas[dig]==NULL){
        listas[dig]=p;
    }
    else{
        p->link=listas[dig];
        listas[dig]=p;
    }
    /* si la lista esta vacia sera el nodo, si no esta vacia el nodo el primero de la lista */
}

void eliminar(aduana listas){
    int dig;
    cadena rut;
    enlace p,q;
    fflush(stdin);
    printf("Ingrese el rut del pasajero: ");
    gets(rut);
    dig=validar_rut(rut);
    while(dig==-1){
        printf("El rut no es valido.\nIngrese rut del pasajero: ");
        fflush(stdin);
        gets(rut);
        dig=validar_rut(rut);
    }
    q=NULL;
    p=listas[dig];
    while(p!=NULL){
        if(strcmp(rut,p->rut)==0){
            if(q==NULL){
                listas[dig]=p->link;
                free(p);
            }
            /* si el rut coincide con el ingresado y q es nulo el primer nodo es liberado */
            else{
                q->link=p->link;
                free(p);
            }
            /* si no esta al principio se enlazan los que estan antes y despues */
        }
        q=p;
        p=p->link;
    }
}

void buscar(aduana listas){
    int dig,sw=0;
    cadena rut;
    enlace p;
    printf("Ingrese rut del pasajero: ");
    fflush(stdin);
    gets(rut);
    dig=validar_rut(rut);
    while(dig==-1){
        printf("El rut es invalido.\nIngrese rut del pasajero: ");
        fflush(stdin);
        gets(rut);
        dig=validar_rut(rut);
    }
    p=listas[dig];
    while(p!=NULL && sw==0){
        if(strcmp(p->rut,rut)==0){
            system("cls");
            printf("AVISO: Pasajero encontrado!!\nnombre: %s\n",p->nombre);
            printf("edad: %d\n",p->edad);
            printf("Fecha de salida: %d\n",p->fechaSalida);
            printf("Fecha de entrada: %d\n",p->fechaEntrada);
            printf("destino: %s\n\n",p->destino);
            sw=1;
        }
        p=p->link;
    }
    if(sw==0){
        system("cls");
        printf("AVISO: No se ha encontrado a ningun pasajero con el rut ingresado\n\n");
    }
}

void liechteinstein(aduana listas){
    enlace p;
    int dig;
    float prom,c=0,edad=0;
    for(dig=0;dig<11;dig++){
        p=listas[dig];
        while(p!=NULL){
            if(strcmp(p->destino,"liechteinstein")==0){
                edad+=p->edad;
                c++;
            }
            p=p->link;
        }
    }
    if(c>0){
        prom=edad/c;
        system("CLS");
        printf("La edad promedio de las personas que viajaron a Liechteinstein es de: %.2f aÑos\n",prom);
    }
    else{
        system("cls");
        printf("AVISO: No se encuentra registro de personas que hayan viajado a Liechteinstein.\n");
    }
}

void lista_info(aduana listas){
    enlace p;
    cadena digc;
    int dig,len;
    printf("Ingrese el digito verificador: ");
    fflush(stdin);
    gets(digc);
    len=strlen(digc);
    dig=digc[0]-48;
    /* improvisada validacion dentro de la funcion para el digito de su longitud y el caso k y K */
    if(dig==27 || dig==59){
        dig=10;
    }
    while(dig<0 || dig>10 || (len>1)){
        printf("El digito ingresado no es valido.\nIngrese el digito verificador: ");
        fflush(stdin);
        gets(digc);
        len=strlen(digc);
        dig=digc[0]-48;
        if(dig==27 || dig==59){
            dig=10;
        }
    }
    p=listas[dig];
    if(p==NULL){
        system("cls");
        printf("AVISO: No existe registro de pasajeros con este digito.\n");

    }
    while(p!=NULL){
        printf("\nrut: %s\n",p->rut);
        printf("nombre: %s\n",p->nombre);
        printf("edad: %d\n",p->edad);
        printf("Fecha de salida: %d\n",p->fechaSalida);
        printf("Fecha de entrada: %d\n",p->fechaEntrada);
        printf("destino: %s\n",p->destino);
        p=p->link;
    }
    system("PAUSE");
}

void nombre_info(aduana listas){
        enlace p;
        cadena digc;
        int dig,len,dias,dia,mes,anho;
        printf("Ingrese el digito verificador: ");
        fflush(stdin);
        gets(digc);
        len=strlen(digc);
        dig=digc[0]-48;
        if(dig==27 || dig==59){
            dig=10;
        }
        while(dig<0 || dig>10 || (len>1)){
            printf("El digito ingresado no es valido.\nIngrese el digito verificador: ");
            fflush(stdin);
            gets(digc);
            len=strlen(digc);
            dig=digc[0]-48;
            if(dig==27 || dig==59){
            dig=10;
            }
        }
        p=listas[dig];
        if(p==NULL){
            system("cls");
            printf("AVISO: No hay registro de pasajeros con ese digito.\n");
        }
        system("cls");
        while(p!=NULL){
            dia=(p->fechaEntrada/1000000)-(p->fechaSalida/1000000);
            mes=((p->fechaEntrada/10000)%100)-((p->fechaSalida/10000)%100);
            anho=(p->fechaEntrada%10000)-(p->fechaSalida%10000);
            dias=anho*365+mes*31+dia;
            /* cálculo de los días */
            printf("nombre: %s\n",p->nombre);
            printf("Estuvo %d dia(s) fuera del pais.\n\n",dias);
            p=p->link;
        }
        system("PAUSE");
}

void brocas(aduana listas){
    enlace p;
    int dig,broca=0,dias,dia,mes,anho;
    for(dig=0;dig<11;dig++){
        p=listas[dig];
        while(p!=NULL){
            dia=(p->fechaEntrada/1000000)-(p->fechaSalida/1000000);
            mes=((p->fechaEntrada/10000)%100)-((p->fechaSalida/10000)%100);
            anho=(p->fechaEntrada%10000)-(p->fechaSalida%10000);
            dias=anho*365+mes*31+dia;
            /* cálculo de los días */
            if(p->edad<18 && dias>31){
                broca++;
            }
            p=p->link;
        }
    }
    system("cls");
    printf("La cantidad de menores de edad que estuvo mas de un mes fuera del pais es: %d\n",broca);
}

char validar_char(){
    char opcion[1024];
    char o1;
    int len;
    fflush(stdin);
    gets(opcion);
    len=strlen(opcion);
    if(len==1 && isalpha(opcion[0])){
        o1=opcion[0];
        o1=tolower(o1);
        return o1;
    }
    else{
        return opcion;
    }
}

int validar_edad(){
    int aux,len,s=0;
    float p=0;
    cadena numero;
    printf("Ingrese edad: ");
    gets(numero);
    len=strlen(numero)-1;
    for(len;len>=0;len--){
        if(isdigit(numero[len])){
            aux=numero[len]-48;
            s+=aux*pow(10,p);
            p++;
        }
        else{
            return 0;
        }
    }
    return s;
}/* esta funcion convierte caracteres a un numero entero sino retorna 0 */

int validar_rut(cadena rut){
    int aux,dig,s=0,mod,len,j=2;
    len=strlen(rut);
    dig=rut[len-1]-48;
    len-=3;
    if(dig==59){
        dig-=49;
    }
    if(dig==75){
        dig-=65;
    }
    for(len;len>=0;len--){
        if(j==8){
            j=2;
        }
        aux=rut[len]-48;
        s+=aux*j;
        j++;
    }
    mod=s%11;
    s=11-mod;
    if(s==11){
        s=0;
    }
    if(s==dig){
        return dig;
    }
    else{
        return -1;
    }
}/* método del módulo 11 hecho algoritmo ínluidos los casos del dígito caracter k */

int validar_destino(cadena destino){
    int len,i;
    len=strlen(destino);
    for(i=0;i<len;i++){
        if(isalpha(destino[i])){
            destino[i]=tolower(destino[i]);
        }
        else{
            return 0;
        }
    }
    return 1;
}/* convierte el destino a todo minúscula */

int validar_fecha(int fecha){
    int dia,mes,anho;
    dia=fecha/1000000;
    mes=(fecha/10000)%100;
    anho=fecha%10000;
    printf("%d/%d/%d... ",dia,mes,anho);
    if((dia>0 && dia<32) && (mes>0 && mes<13) && (anho>1900 && anho<2017)){
        return fecha;
    }
    else{
        return 0;
    }
}/* descompone el entero fecha y la retorna si es válida sino retorna 0 */
