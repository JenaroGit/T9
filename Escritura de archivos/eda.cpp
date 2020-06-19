/* Manejo de archivos en lenguaje C++ */
/* Escritura de archivos */
/* Flujo de datos FILE */
//Flujo de datos dirigido hacia el disco duro

/* PROGRAMA -> CANAL -> DISCO_DURO -- ESCRITURA */
/* PROGRAMA <- CANAL (FLUJO DE DATOS) <- DISCO_DURO -- LECTURA */

/* Funciones para manejar el ingreso al archivo */
/*
	fputc - escriba un caracter
	fputs - escriba una cadena de texto
	fprintf - equivalente a printf
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

	FILE * flujo = fopen ("datos.txt", "a"); //NO sobrescribe el archivo
	if (flujo == NULL){
		cout << "Error en la creaci[on del archivo!!!\n\n" << endl;
		return 1;
	}
	else {
		int i, j;



/* fputc -> Ingresa un caracter */

		for (i = 0; i < 10; i++){
			for (j = 0; j < 20; j++){

			/*Ingresa un caracter */
				fputc('s', flujo);
				fputc(' ', flujo);
				fputc(' ', flujo);
			}
			fputc('\n', flujo);
		}
		fputc('\n', flujo);



/* fputs -> Ingresa un String */

		for (i = 0; i < 10; i++){
			for (j = 0; j < 20; j++){

			/* Ingresa un String */
				fputs("T  ", flujo);			
			}
			fputc('\n', flujo);
		}
		fputc('\n', flujo);



/* fprintf -> Ingresa la salida */

		for (i = 0; i < 10; i++){
			for (j = 0; j < 20; j++){
			
			/* Funciona igual que printf */
				fprintf(flujo, "%d  ", j);//se usa el valor que tenga la J
			
			
			}
			fputc('\n', flujo);
		}
		fputc('\n', flujo);




		fflush(flujo);//limpia el canal de información que se usa
		fclose(flujo);

		cout << "\nEXITO!!!\n" << endl;	

	}

	return 0;
}
