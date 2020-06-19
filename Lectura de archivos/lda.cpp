/* Manejo de archivos en lenguaje C++ */
/* Lectura de archivos */
/* Flujo de datos FILE */

/* PROGRAMA -> CANAL -> DISCO_DURO -- ESCRITURA */
/* PROGRAMA <- CANAL (FLUJO DE DATOS) <- DISCO_DURO -- LECTURA */

/* MODOS DE APERTURA */
/*
	r = READ
	w = WRITE (SOBRESCRIBE EL ARCHIVO)
	a = WRITE (NO SOBRESCRIBE EL ARCHIVO)
	b = BINARY
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

	FILE * flujo = fopen("prueba.txt", "rb"); //fopen abre el archivo
//modo de lectura y modo binario.
/* se abre en modo binario ya que se va a trabajar con variables tipo char, esto lo hace más rápido */

	if (flujo == NULL){ //se verifica si flujo apunta a NULL
		cout << "Error con la apertura del archivo!!!" << endl;
		return 1;
	}


// Almacenar los datos del archivo en un array...

	fseek (flujo, 0, SEEK_END); //Mueve el flujo hasta el EOF
	int num_elementos = ftell(flujo); //cantidad total de caracteres que tiene el archivo
	rewind (flujo); //mueve el flujo al inicio

	char * cadena = (char *) calloc(sizeof(char), num_elementos); //array
	if (cadena == NULL){
		cout << "Error en reserva de memoria!!!" << endl;
		return 2;
	}

	int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, flujo); //lectura de los elementos totales
	if (num_elementos_leidos != num_elementos){
		cout << "Error leyendo el archivo!!!" << endl;
		return 3;
	}

	printf("%s", cadena);

	free (cadena);


/* Almacenar los datos del archivo en variables...

	int numero;
	char cadena[10];

	while (!feof(flujo)){
		fscanf(flujo, "%d%s", &numero, cadena);
		cout << ("%d", numero) << " ";
		cout << ("%s", cadena) << endl;
		
	}
*/



/*Solo lectura e impresión del archivo... 

	char caracter;

	while (feof(flujo) == 0){ //feof = funcion EndOfFile
		caracter =fgetc(flujo); //recibe el flujo y regresa un caracter en la posici[on actual del flujo de datos
		cout << ("%c", caracter);
	}
*/



	fclose(flujo); //Se debe cerrar el flujo que se abre para liberar la memomria usada.
	cout << "\n\nSe ha leido el archivo correctamente...\n" << endl;

	return 0;

}
