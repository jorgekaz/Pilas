#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL,"");
    int opt;
    do{
        printf("\n==============================\n");
        printf(" TRABAJO PRACTICO N° 1: PILAS\n");
        printf("==============================\n\n");
        printf(" 1.Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas. \n\n");
        printf(" 2.Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO. \n\n");
        printf(" 3.Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8. \n\n");
        printf(" 4.Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden. \n\n");
        printf(" 5.Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso. \n\n");
        printf(" 6.Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden. \n\n");
        printf(" 7.Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden. \n\n");
        printf(" 8.Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa. \n\n");
        printf(" 9.Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado. \n\n");
        printf(" 10.Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n\n");
        printf(" 11.Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO. \n\n");
        printf(" 12.Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO. \n\n");
        printf(" 13.Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES. \n\n");
        printf(" 14.Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. \n\n");
        printf(" 15.SALIR\n\n");
        printf("\n ELIJA UNA OPCIÓN: ");
        fflush(stdin);
        scanf("%i", &opt);
        system("cls");
        switch(opt){
        case 1:{
                printf(" 1.Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas. \n\n");
                Pila dada;
                inicpila(&dada);
                Pila aux1;
                inicpila(&aux1);
                Pila aux2;
                inicpila(&aux2);

                leer(&dada);
                leer(&dada);
                leer(&dada);
                leer(&dada);
                leer(&dada);

                printf("\nPila DADA\n");
                mostrar(&dada);
                apilar (&aux1, desapilar(&dada));
                apilar (&aux1, desapilar(&dada));
                apilar (&aux1, desapilar(&dada));
                printf("Pila Auxiliar Uno\n");
                mostrar(&aux1);
                apilar (&aux2, desapilar(&dada));
                apilar (&aux2, desapilar(&dada));
                printf("Pila Auxiliar Dos\n");
                mostrar(&aux2);
                system("pause");
                system("cls");
            }
            break;
        case 2:{
            printf(" 2.Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO. \n\n");
            Pila origen;
            Pila destino;
            inicpila (&origen);
            inicpila (&destino);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            printf("\nPILA ORIGEN\n");
            mostrar(&origen);

            while (!pilavacia (&origen)){
                apilar(&destino, desapilar(&origen));
            }
            printf ("\nPILA DESTINO\n");
            mostrar(&destino);
            system("pause");
            system("cls");
        }
        break;
        case 3:{
            printf(" 3.Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8. \n\n");
            Pila dada;
            inicpila (&dada);
            Pila distintos;
            inicpila (&distintos);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&dada,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            mostrar(&dada);
            while (!pilavacia(&dada)){
                if (tope(&dada) != 8){
                    apilar(&distintos, desapilar(&dada));
                }
                else{
                    desapilar(&dada);
                }
            }
            mostrar(&distintos);
            system("pause");
            system("cls");
        }
        break;
        case 4:{
            printf(" 4.Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden. \n\n");
            Pila origen;
            Pila destino;
            inicpila (&origen);
            inicpila (&destino);
            Pila aux;
            inicpila(&aux);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&origen,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            printf("\nPILA ORIGEN\n");
            mostrar(&origen);
            while(!pilavacia(&origen)){
                apilar(&aux, desapilar(&origen));
            }
            while(!pilavacia(&aux)){
                apilar(&destino, desapilar(&aux));
            }
            printf("PILA DESTINO\n");
            mostrar(&destino);
            system("pause");
            system("cls");
        }
        break;
        case 5:{
            printf(" 5.Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso. \n\n");
            Pila dada;
            Pila aux;
            inicpila(&dada);
            inicpila(&aux);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&dada,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            printf("\nPILA DADA\n");
            mostrar(&dada);
            while(!pilavacia(&dada)){
                apilar(&aux, desapilar(&dada));
            }
            while(!pilavacia(&aux)){
                apilar(&dada, tope(&aux));
                desapilar(&aux);
            }
            printf("\nPILA DADA INVERSA\n");
            mostrar(&dada);
            system("pause");
            system("cls");
        }
        break;
        case 6:{
            printf(" 6.Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden. \n\n");
            Pila dada;
            inicpila(&dada);
            Pila aux1;
            inicpila(&aux1);
            Pila aux2;
            inicpila(&aux2);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&dada,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            printf("\nPILA DADA\n");
            mostrar(&dada);
            apilar(&aux2, desapilar(&dada));
            while(!pilavacia(&dada)){
                apilar(&aux1, desapilar(&dada));
            }
            apilar(&dada, desapilar(&aux2));
            while(!pilavacia(&aux1)){
                apilar(&dada, desapilar(&aux1));
            }
            printf("\nPILA DADA TOPE EN BASE\n");
            mostrar(&dada);
            system("pause");
            system("cls");
        }
        break;
        case 7:{
            printf(" 7.Pasar el último elemento (base) de la pila DADA a su primera posición (tope), dejando los restantes elementos en el mismo orden. \n\n");
            Pila dada;
            inicpila(&dada);
            Pila aux1;
            inicpila(&aux1);
            Pila aux2;
            inicpila(&aux2);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&dada,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');

            printf("\nPILA DADA\n");
            mostrar(&dada);
            while(!pilavacia(&dada)){
                apilar(&aux1, desapilar(&dada));
            }
            apilar(&aux2, desapilar(&aux1));
            while(!pilavacia(&aux1)){
                apilar(&dada, desapilar(&aux1));
            }
            apilar(&dada, desapilar(&aux2));
            printf("PILA DADA FINAL\n");
            mostrar(&dada);
            system("pause");
            system("cls");
        }
        break;
        case 8:{
            printf(" 8.Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa. \n\n");
            Pila mazo;
            inicpila(&mazo);
            Pila player1;
            inicpila(&player1);
            Pila player2;
            inicpila(&player2);

            char opt;
            int valor;
            do{
                printf("INGRESE UN ELEMENTO\n");
                scanf("%i",&valor);
                apilar(&mazo,valor);
                printf("\nDESEA CARGAR UN NUEVO ELEMENTO? Y/N\n");
                fflush(stdin);
                scanf("%c", &opt);
                printf("\n");
            }
            while(opt=='Y'||opt=='y');
            int flag=1;
            do{
                if(!pilavacia(&mazo)){
                    apilar(&player1, desapilar(&mazo));
                    apilar(&player2, desapilar(&mazo));
                }
                else{
                    printf("No quedan mas cartas para repartir\n");
                    flag=0;
                }
            }
            while(flag==1);
            printf("CARTAS DEL JUGADOR 1\n");
            mostrar(&player1);
            printf("CARTAS DEL JUGADOR 2\n");
            mostrar(&player2);
            system("pause");
            system("cls");
        }
        break;
        case 9:{
            printf(" 9.Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado. \n\n");
            Pila pilaA;
            Pila pilaB;
            Pila auxA;
            Pila auxB;
            inicpila(&auxB);
            inicpila(&auxA);
            inicpila(&auxB);
            inicpila(&pilaA);
            inicpila(&pilaB);

            apilar(&pilaA, 1);
            apilar(&pilaA, 2);
            apilar(&pilaB, 5);
            apilar(&pilaA, 3);
            apilar(&pilaB, 4);
            printf("PILA A\n");
            mostrar(&pilaA);
            printf("PILA B\n");
            mostrar(&pilaB);

            while(!pilavacia(&pilaA)&&!pilavacia(&pilaB)){
                apilar (&auxA, desapilar (&pilaA));
                apilar (&auxB, desapilar (&pilaB));
            }
            if(pilavacia(&pilaA)&&pilavacia(&pilaB)){
                printf("AMBAS PILAS SON IGUALES\n");
            }
            else if(pilavacia(&pilaA)){
                printf("PILA A ES MAS CHICA\n");
            }
            else{
                printf("PILA B ES MAS CHICA\n");
            }
            while(!pilavacia(&auxA)&&!pilavacia(&auxB)){
                apilar(&pilaA, desapilar(&auxA));
                apilar(&pilaB, desapilar(&auxB));
            }
            system("pause");
            system("cls");

        }
        break;
        case 10:{
            printf(" 10.Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado. \n\n");
            Pila pilaA;
            Pila pilaB;
            Pila tempA;
            Pila tempB;
            inicpila(&pilaA);
            inicpila(&pilaB);
            inicpila(&tempA);
            inicpila(&tempB);

            int flagLongitudA,flagLongitudB=0;
            int flagMismosElementos=1;

            apilar(&pilaA,20);
            apilar(&pilaA,30);
            apilar(&pilaA,40);
            apilar(&pilaA,50);
            apilar(&pilaA,35);

            apilar(&pilaB,20);
            apilar(&pilaB,30);
            apilar(&pilaB,40);
            apilar(&pilaB,50);
            apilar(&pilaB,35);

            mostrar(&pilaA);
            mostrar(&pilaB);

            while(flagLongitudA==0 && flagLongitudB==0){
                if(flagLongitudA==0 && flagLongitudB==0){
                    if(!pilavacia(&pilaA)||!pilavacia(&pilaB)){
                        if(tope(&pilaA)!=tope(&pilaB)){
                            flagMismosElementos=0;
                        }
                    }
                }
                if(!pilavacia(&pilaA)){
                    apilar(&tempA,desapilar(&pilaA));
                }
                else{
                    flagLongitudA=1;
                }
                if(!pilavacia(&pilaB)){
                    apilar(&tempB,desapilar(&pilaB));
                }
                else{
                    flagLongitudB=1;
                }
            }
            while(!pilavacia(&tempA)){
                apilar(&pilaA,desapilar(&tempA));
            }
            while(!pilavacia(&tempB)){
                apilar(&pilaB,desapilar(&tempB));
            }
            if(flagLongitudA==flagLongitudB){
                printf("Las pilas A y B poseen la misma longitud \n");
                if(flagMismosElementos==1){
                    printf("Contienen la misma cantidad de elementos y en el mismo orden \n");
                }
                else{
                    printf("No contienen los mismos elementos \n");
                }
            }
            else if(flagLongitudA==1 && flagLongitudB==0){
                printf("La pila B es mas grande que la pila A \n");
            }
            else{
                printf("La pila A es mas grande que la pila B \n");
            }
            system("pause");
            system("cls");
        }
        break;
        case 11:{
            printf(" 11.Suponiendo la existencia de una pila MODELO que no esté vacía, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO. \n\n");
            Pila modelo;
            Pila dada;
            Pila auxModelo;
            Pila auxDada;

            inicpila(&modelo);
            inicpila(&dada);
            inicpila(&auxModelo);
            inicpila(&auxDada);

            apilar(&modelo,10);
            apilar(&modelo,30);
            apilar(&modelo,50);
            apilar(&dada,10);
            apilar(&dada,20);
            apilar(&dada,50);
            apilar(&dada,40);
            apilar(&dada,50);
            apilar(&dada,60);
            apilar(&dada,75);

            printf("PILA MODELO\n");
            mostrar(&modelo);
            printf("PILA DADA\n");
            mostrar(&dada);

            while(!pilavacia(&dada)){
                if(tope(&modelo)==tope(&dada)){
                    apilar(&auxModelo, desapilar(&dada));
                }
                else{
                    apilar(&auxDada, desapilar(&dada));
                }
            }
            while(!pilavacia(&auxDada)){
                apilar(&dada, desapilar(&auxDada));
            }
            printf("PILA DADA\n");
            mostrar(&dada);
            system("pause");
            system("cls");
        }
        break;
        case 12:{
            printf(" 12.Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO. \n\n");
            Pila modelo;
            inicpila(&modelo);
            Pila dada;
            inicpila(&dada);
            Pila auxModelo;
            inicpila(&auxModelo);
            Pila auxDada;
            inicpila(&auxDada);

            apilar(&modelo,10);
            apilar(&modelo,30);
            apilar(&modelo,50);
            apilar(&dada,10);
            apilar(&dada,20);
            apilar(&dada,30);
            apilar(&dada,40);
            apilar(&dada,50);
            apilar(&dada,60);

            printf("PILA MODELO\n");
            mostrar(&modelo);
            printf("PILA DADA\n");
            mostrar(&dada);

            while(!pilavacia(&modelo)){
                while(!pilavacia(&dada)){
                    if(tope(&modelo)==tope(&dada)){
                        desapilar(&dada);
                    }
                    else{
                        apilar(&auxDada, desapilar(&dada));
                    }
                }
                if(pilavacia(&dada)){
                    while(!pilavacia(&auxDada)){
                        apilar(&dada, desapilar(&auxDada));
                    }
                }
                apilar(&auxModelo, desapilar(&modelo));
            }
            printf("PILA DADA\n");
            mostrar(&dada);
            system("pause");
            system("cls");
        }
        break;
        case 13:{
            printf(" 13.Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES. \n\n");
            Pila limite;
            Pila dada;
            Pila mayores;
            Pila menores;
            inicpila(&limite);
            inicpila(&dada);
            inicpila(&mayores);
            inicpila(&menores);

            apilar(&limite, 10);
            apilar(&limite, 20);
            apilar(&limite, 30);
            apilar(&dada, 10);
            apilar(&dada, 20);
            apilar(&dada, 70);
            apilar(&dada, 30);
            apilar(&dada, 60);
            apilar(&dada, 40);

            printf("LIMITE\n");
            mostrar(&limite);
            printf("DADA\n");
            mostrar(&dada);
            while(!pilavacia(&dada)&&!pilavacia(&limite)){
                if(tope(&dada)>=tope(&limite)){
                    apilar(&mayores, desapilar(&dada));
                }
                else{
                    apilar(&menores, desapilar(&dada));
                }
            }
            printf("LIMITE\n");
            mostrar(&limite);
            printf("MAYOR\n");
            mostrar(&mayores);
            printf("MENOR\n");
            mostrar(&menores);
            system("pause");
            system("cls");
        }
        break;
        case 14:{
            printf(" 14.Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. \n\n");
            Pila dada;
            Pila aux;
            Pila par;
            Pila par2;
            Pila impar;
            Pila impar2;
            inicpila(&dada);
            inicpila(&aux);
            inicpila(&par);
            inicpila(&par2);
            inicpila(&impar);
            inicpila(&impar2);
            int flag;

            apilar(&dada,1);
            apilar(&dada,2);
            apilar(&dada,3);
            apilar(&dada,4);
            apilar(&dada,5);
            apilar(&dada,6);

            printf("PILA DADA\n");
            mostrar(&dada);

            while(!pilavacia(&dada)){
                flag = 0;
                apilar(&aux, desapilar(&dada));
                if(!pilavacia(&dada)){
                    flag = 1;
                    apilar(&aux, desapilar(&dada));
                }
            }
            while(!pilavacia(&aux)){
                apilar(&dada, desapilar(&aux));
            }

            if(flag==1){
                printf("La Pila es par.\n\n");
                apilar(&par, desapilar(&dada));
                mostrar(&par);
            }
            else
            {
                printf("La Pila es impar.\n\n");
                apilar(&impar, desapilar(&dada));
                mostrar(&impar);
            }
            system("pause");
            system("cls");
        }
        break;
        default:
            printf("\n OPCION INCORRECTA\n\n");
            system("pause");
            system("cls");
            break;
        }
    }while (opt!='15');
    printf("\n FIN DEL PROGRAMA\n\n");
    system("pause");
}
/////EJERCICIO 1 - PILAS
//    Pila dada;
//    inicpila(&dada);
//    Pila aux1;
//    inicpila(&aux1);
//    Pila aux2;
//    inicpila(&aux2);
//
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//
//    printf("\nPila DADA\n");
//    mostrar(&dada);
//    sleep(3);
//    apilar (&aux1, desapilar(&dada));
//    apilar (&aux1, desapilar(&dada));
//    apilar (&aux1, desapilar(&dada));
//    printf("Pila Auxiliar Uno\n");
//    mostrar(&aux1);
//    sleep(3);
//    apilar (&aux2, desapilar(&dada));
//    apilar (&aux2, desapilar(&dada));
//    printf("Pila Auxiliar Dos\n");
//    mostrar(&aux2);
//    sleep(3);*/
/////EJERCICIO 2 - PILAS
//    Pila origen;
//    Pila destino;
//    inicpila (&origen);
//    inicpila (&destino);
//
//  	char control='s';
//    while (control=='s')
//    {
//        printf("PILA ORIGEN\n");
//        leer (&origen);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//    printf("\nPILA ORIGEN\n");
//    mostrar(&origen);
//    sleep(3);
//
//    while (!pilavacia (&origen))
//    {
//        apilar(&destino , desapilar(&origen));
//    }
//    printf ("\nPILA DESTINO\n");
//    mostrar(&destino);*/
/////EJERCICIO 3 - PILAS
//    Pila dada;
//    inicpila (&dada);
//    Pila distintos;
//    inicpila (&distintos);
//
//    char control='s';
//    while (control=='s')
//    {
//        printf("PILA DADA\n");
//        leer (&dada);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//    while (!pilavacia(&dada))
//    {
//        if (tope(&dada) != 8)
//        {
//            apilar(&distintos, desapilar(&dada));
//            mostrar(&distintos);
//            mostrar(&dada);
//            sleep (3);
//        }
//        else
//        {
//            desapilar(&dada);
//            mostrar(&distintos);
//            mostrar(&dada);
//        }
//     }
/////EJERCICIO 4 - PILAS
//    Pila origen;
//    inicpila(&origen);
//    Pila destino;
//    inicpila(&destino);
//    Pila aux;
//    inicpila(&aux);
//
//    char control='s';
//    while (control=='s')
//    {
//        printf("PILA ORIGEN\n");
//        leer (&origen);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//    printf("\nPILA ORIGEN\n");
//    while(!pilavacia(&origen))
//    {
//        mostrar(&origen);
//        apilar(&Aux, desapilar(&origen));
//        sleep(1);
//    }
//    printf("PILA DESTINO\n");
//    while(!pilavacia(&Aux))
//    {
//        apilar(&destino, desapilar(&aux));
//        mostrar(&destino);
//        sleep(1);
//    }
/////EJERCICIO 5 - PILAS
//    Pila dada;
//    Pila aux;
//    inicpila(&dada);
//    inicpila(&aux);
//
//    char control='s';
//    while (control=='s')
//    {
//        printf("PILA DADA\n");
//        leer (&dada);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//
//    printf("\nPILA DADA\n");
//    while(!pilavacia(&dada))
//    {
//        mostrar(&dada);
//        apilar(&aux, desapilar(&dada));
//        mostrar(&aux);
//        sleep(1);
//    }
//        printf("\nPILA DADA INVERSA\n");
//        mostrar(&aux);
/////EJERCICIO 6 - PILAS
//    Pila dada;
//    inicpila(&dada);
//    Pila aux1;
//    inicpila(&aux1);
//    Pila aux2;
//    inicpila(&aux2);
//
//    char control='s';
//    while (control=='s')
//    {
//        printf("PILA DADA\n");
//        leer (&dada);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//
//    printf("\nPILA DADA\n");
//    mostrar(&dada);
//    apilar(&aux2, desapilar(&dada));
//    sleep(2);
//    while(!pilavacia(&dada))
//    {
//        apilar(&aux1, desapilar(&dada));
//    }
//    printf("\nPILA DADA TOPE EN BASE\n");
//    while(!pilavacia(&aux1))
//    {
//        apilar(&aux2, desapilar(&aux1));
//        mostrar(&aux2);
//        sleep(2);
//    }
/////EJERCICIO 7 - PILAS
//   Pila dada;
//    inicpila(&dada);
//    Pila aux1;
//    inicpila(&aux1);
//    Pila aux2;
//    inicpila(&aux2);
//
//    char control='s';
//    while (control=='s')
//    {
//        printf("PILA DADA\n");
//        leer (&dada);
//        printf ("desea cargar mas datos? Aprete 's'\n");
//        fflush (stdin);
//        scanf ("%c", &control);
//    }
//
//    printf("\nPILA DADA\n");
//    mostrar(&dada);
//    while(!pilavacia(&dada))
//    {
//        apilar(&aux1, desapilar(&dada));
//        mostrar(&aux1);
//        sleep(2);
//    }
//    apilar(&aux2, desapilar(&aux1));
//    while(!pilavacia(&aux1))
//    {
//        apilar(&dada, desapilar(&aux1));
//        mostrar(&dada);
//        sleep(2);
//    }
//    apilar(&dada, desapilar(&aux2));
//    printf("PILA DADA FINAL\n");
//    mostrar(&dada);
/////EJERCICIO 8 - PILAS
//    Pila mazo;
//    inicpila(&mazo);
//    Pila player1;
//    inicpila(&player1);
//    Pila player2;
//    inicpila(&player2);
//
//    char control='s';
//    while(control=='s')
//    {
//        printf("PILA MAZO\n");
//        leer(&mazo);
//        printf("desea cargar mas datos? Aprete 's'\n");
//        fflush(stdin);
//        scanf("%c", &control);
//    }
//    int flag=1;
//    do
//    {
//        if(!pilavacia(&mazo))
//        {
//            apilar(&player1, desapilar(&mazo));
//            apilar(&player2, desapilar(&mazo));
//        }
//        else
//        {
//            printf("No quedan mas cartas para repartir\n");
//            flag=0;
//        }
//    }
//    while(flag==1);
//    printf("CARTAS DEL JUGADOR 1\n");
//    mostrar(&player1);
//    printf("CARTAS DEL JUGADOR 2\n");
//    mostrar(&player2);
//
/////EJERCICIO 9 - PILAS
//
//int main()
//{
//    Pila pilaA;
//    Pila pilaB;
//    Pila auxA;
//    Pila auxB;
//    inicpila(&auxB);
//    inicpila(&auxA);
//    inicpila(&auxB);
//    inicpila(&pilaA);
//    inicpila(&pilaB);
//
//    apilar(&pilaA, 1);
//    apilar(&pilaA, 2);
//    apilar(&pilaB, 5);
//    apilar(&pilaA, 3);
//    apilar(&pilaB, 4);
//    printf("PILA A\n");
//    mostrar(&pilaA);
//    printf("PILA B\n");
//    mostrar(&pilaB);
//
//    while(!pilavacia(&pilaA)&&!pilavacia(&pilaB))
//    {
//        apilar (&auxA, desapilar (&pilaA));
//        apilar (&auxB, desapilar (&pilaB));
//    }
//    if(pilavacia(&pilaA)&&pilavacia(&pilaB))
//    {
//        printf("AMBAS PILAS SON IGUALES\n");
//    }
//    else if(pilavacia(&pilaA))
//    {
//        printf("PILA A ES MAS CHICA\n");
//    }
//    else
//    {
//        printf("PILA B ES MAS CHICA\n");
//    }
//    while(!pilavacia(&auxA)&&!pilavacia(&auxB))
//    {
//        apilar(&pilaA, desapilar(&auxA));
//        apilar(&pilaB, desapilar(&auxB));
//    }
//    return 0;
//}

/// EJERCICIO 10 - Pilas

//int main()
//{
//    Pila pilaA;
//    Pila pilaB;
//    Pila tempA;
//    Pila tempB;
//    inicpila(&pilaA);
//    inicpila(&pilaB);
//    inicpila(&tempA);
//    inicpila(&tempB);
//
//    int flagLongitudA,flagLongitudB=0;
//    int flagMismosElementos=1;
//
//    apilar(&pilaA,20);
//    apilar(&pilaA,30);
//    apilar(&pilaA,40);
//    apilar(&pilaA,50);
//    apilar(&pilaA,35);
//
//    apilar(&pilaB,20);
//    apilar(&pilaB,30);
//    apilar(&pilaB,40);
//    apilar(&pilaB,50);
//    apilar(&pilaB,35);
//
//    mostrar(&pilaA);
//    mostrar(&pilaB);
//
//    while(flagLongitudA==0 && flagLongitudB==0)
//    {
//        if(flagLongitudA==0 && flagLongitudB==0)
//        {
//            if(!pilavacia(&pilaA)||!pilavacia(&pilaB))
//            {
//                if(tope(&pilaA)!=tope(&pilaB))
//                {
//                    flagMismosElementos=0;
//                }
//            }
//        }
//        if(!pilavacia(&pilaA))
//        {
//            apilar(&tempA,desapilar(&pilaA));
//        }
//        else
//        {
//            flagLongitudA=1;
//        }
//        if(!pilavacia(&pilaB))
//        {
//            apilar(&tempB,desapilar(&pilaB));
//        }
//        else
//        {
//            flagLongitudB=1;
//        }
//    }
//    while(!pilavacia(&tempA))
//    {
//        apilar(&pilaA,desapilar(&tempA));
//    }
//    while(!pilavacia(&tempB))
//    {
//        apilar(&pilaB,desapilar(&tempB));
//    }
//    if(flagLongitudA==flagLongitudB)
//    {
//        printf("Las pilas A y B poseen la misma longitud \n");
//        if(flagMismosElementos==1)
//        {
//            printf("Contienen la misma cantidad de elementos y en el mismo orden \n");
//        }
//        else
//        {
//            printf("No contienen los mismos elementos \n");
//        }
//    }
//    else if(flagLongitudA==1 && flagLongitudB==0)
//    {
//        printf("La pila B es mas grande que la pila A \n");
//    }
//    else
//    {
//        printf("La pila A es mas grande que la pila B \n");
//    }
//    return 0;
//}

/// EJERCICIO 11 - Pilas

//int main()
//{
//    Pila modelo;
//    Pila dada;
//    Pila auxModelo;
//    Pila auxDada;
//
//    inicpila(&modelo);
//    inicpila(&dada);
//    inicpila(&auxModelo);
//    inicpila(&auxDada);
//
//    apilar(&modelo,10);
//    apilar(&modelo,30);
//    apilar(&modelo,50);
//    apilar(&dada,10);
//    apilar(&dada,20);
//    apilar(&dada,30);
//    apilar(&dada,40);
//    apilar(&dada,50);
//    apilar(&dada,60);
//    apilar(&dada,75);
//
//    printf("PILA MODELO\n");
//    mostrar(&modelo);
//    printf("PILA DADA\n");
//    mostrar(&dada);
//
//    while(!pilavacia(&dada))
//    {
//        if(tope(&modelo)==tope(&dada))
//        {
//            apilar(&auxModelo, desapilar(&dada));
//        }
//        else
//        {
//            apilar(&auxDada, desapilar(&dada));
//        }
//    }
//    while(!pilavacia(&auxDada))
//    {
//        apilar(&dada, desapilar(&auxDada));
//    }
//    printf("PILA DADA\n");
//    mostrar(&dada);
//
//    return 0;
//}

/// Ejercicio 12 - Pilas

//int main()
//{
//    Pila modelo;
//    inicpila(&modelo);
//    Pila dada;
//    inicpila(&dada);
//    Pila auxModelo;
//    inicpila(&auxModelo);
//    Pila auxDada;
//    inicpila(&auxDada);
//
//    apilar(&modelo,10);
//    apilar(&modelo,30);
//    apilar(&modelo,50);
//    apilar(&dada,10);
//    apilar(&dada,20);
//    apilar(&dada,30);
//    apilar(&dada,40);
//    apilar(&dada,50);
//    apilar(&dada,60);
//
//    printf("PILA MODELO\n");
//    mostrar(&modelo);
//    printf("PILA DADA\n");
//    mostrar(&dada);
//
//    while(!pilavacia(&modelo))
//    {
//        while(!pilavacia(&dada))
//        {
//            if(tope(&modelo)==tope(&dada))
//            {
//                desapilar(&dada);
//            }
//            else
//            {
//                apilar(&auxDada, desapilar(&dada));
//            }
//        }
//        if(pilavacia(&dada))
//        {
//            while(!pilavacia(&auxDada))
//            {
//                apilar(&dada, desapilar(&auxDada));
//            }
//        }
//        apilar(&auxModelo, desapilar(&modelo));
//    }
//    printf("PILA DADA\n");
//    mostrar(&dada);
//
//    return 0;
//}

/// EJERCICIO 13 - Pilas

//int main()
//{
//    Pila limite;
//    Pila dada;
//    Pila mayores;
//    Pila menores;
//    inicpila(&limite);
//    inicpila(&dada);
//    inicpila(&mayores);
//    inicpila(&menores);
//
//    apilar(&limite, 10);
//    apilar(&limite, 20);
//    apilar(&limite, 30);
//    apilar(&dada, 10);
//    apilar(&dada, 20);
//    apilar(&dada, 70);
//    apilar(&dada, 30);
//    apilar(&dada, 60);
//    apilar(&dada, 40);
//
//    printf("LIMITE\n");
//    mostrar(&limite);
//    printf("DADA\n");
//    mostrar(&dada);
//    while(!pilavacia(&dada)&&!pilavacia(&limite))
//    {
//        if(tope(&dada)>=tope(&limite))
//        {
//           apilar(&mayores, desapilar(&dada));
//        }
//        else
//        {
//        apilar(&menores, desapilar(&dada));
//        }
//    }
//    printf("LIMITE\n");
//    mostrar(&limite);
//    printf("MAYOR\n");
//    mostrar(&mayores);
//    printf("MENOR\n");
//    mostrar(&menores);
//
//    return 0;
//}

/// EJERCICIO 14 - Pila

//int main()
//{
//    Pila dada;
//    Pila aux;
//    Pila par;
//    Pila impar;
//    inicpila(&dada);
//    inicpila(&aux);
//    inicpila(&par);
//    inicpila(&impar);
//
//    apilar(&dada,1);
//    apilar(&dada,2);
//    apilar(&dada,3);
//    apilar(&dada,4);
//    apilar(&dada,5);
//    apilar(&dada,6);
//
//    printf("PILA DADA\n");
//    mostrar(&dada);
//
//    while (!pilavacia(&dada))
//    {
//        apilar(&aux,desapilar(&dada));
//        if (pilavacia(&dada))
//        {
//            printf ("ES IMPAR\n");
//            apilar(&impar,desapilar(&aux));
//            printf("PILA IMPAR\n");
//            mostrar(&impar);
//        }
//        else
//        {
//            apilar(&aux,desapilar(&dada));
//            if (pilavacia(&dada))
//            {
//                printf ("ES PAR\n\n");
//                apilar(&par,desapilar(&aux));
//                printf("PILA PAR\n");
//                mostrar(&par);
//            }
//        }
//    }
//    printf("PILA AUX\n");
//    mostrar(&aux);
//    return 0;
//}

/// EJERCICIO 15 - Pila
///La condicion del ciclo es que la Pila1 no este vacia.
///El ciclo finaliza cuando la Pila1 se vacie.

/// EJERCICIO 16 - Pila
/// Mientras la Pila1 no este vacia, compara el tope de Pila1 con 5, desapila la Pila1 en Aux y despues apila en Result lo que apilo en Aux.

/// EJERCICIO 17 - Pila
/// a) Si resuelve el problema planteado
/// b) La sintaxis de !pilavacia

//int main()
//{
//    Pila Origen, Distinto;
//    inicpila(&Origen);
//    inicpila(&Distinto);
//    apilar(&Origen, 1);
//    apilar(&Origen, 2);
//    apilar(&Origen, 5);
//    apilar(&Origen, 3);
//    apilar(&Origen, 4);
//    apilar(&Origen, 6);
//    apilar(&Origen, 7);
//    apilar(&Origen, 8);
//    apilar(&Origen, 9);
//    mostrar(&Origen);
//    if (!pilavacia(&Origen))
//    {
//        while(tope(&Origen)!=5)
//        {
//            apilar(&Distinto, desapilar(&Origen));
//        }
//    }
//    printf("PILA ORIGEN\n");
//    mostrar(&Origen);
//    printf("PILA DISTINTO\n");
//    mostrar(&Distinto);
//    return 0;
//}

/// EJERCICIO 18 - PILAS
/// a) la condicion del ciclo es que mientras la pila1 y la pila2 no esten vacias vayan apilando su contenido en la pila Descarte
/// b) Es posible que ambas pilas (Pila1 y Pila2) queden vacias o que solamente una de ellas quede vacia.

