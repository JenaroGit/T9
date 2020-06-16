#include <iostream>
using namespace std;
//Empezar codificacion y decodificacion
struct Nodo{//Estructura nodo
	char elemento;//Elemento char dentro del nodo
	struct Nodo *siguiente;//Puntero a siguiente
};
typedef struct Nodo nodo;
nodo *tope = NULL;//Tope de la pila es nulo porque esta vacia
bool isEmpty(){//Verifica si la lista esta vacia
	if (tope==NULL)
		return true;//Retorna true en el caso de estar vacia
	else
		return false;//Retorna false en caso de tener nodos
}
void Push(char element){//Ingresa un elemento a la pila
	nodo *nuevo_nodo = (nodo*) malloc(sizeof(nodo));//Reserva el espacio de un nuevo nodo en memoria
	nuevo_nodo->elemento = element;//Se ingresa el elemento al nuevo nodo
	nuevo_nodo->siguiente = tope;//El nuevo nodo apunta a el tope actual de la pila
	tope = nuevo_nodo;//El nuevo tope es el nuevo nodo
}
char Pop(){//Retorna y elimina el tope de la lista
	if (isEmpty()){//Si esta vacia retorna un mensaje de pila vacia
		cout << "Pila vacia" << endl;
		return ' ';
	}
	else{
		nodo *aux = tope;//Guarda el tope actual de la lista
		char valor = tope->elemento;//Adquiere el elemento del tope
		tope = tope->siguiente;//Cambia el tope por el nodo de abajo
		free(aux);//Libera el antiguo tope
		return valor;//Retorna el valor del elemento del tope anterior;
	}
}
void codificar(char num[],char abc[][4],char val,int cont){//Codifica el mensaje ingresado por teclado t9 en mensaje, para ello recibe un array de numeros, un array multidimencional de letras y simbolos, el numero a codificar y la cantidad de veces que se escribio dicho numero
	char code;//Char que guarda el dato codificado
	int pos;//Posicion en la primera dimension de el array multidimensional de caracteres
	for (int i = 0; i < 10; i++){
		if (num[i]==val){//Si encuentra el numero a codificar en el array de numeros
			pos=i;//Guarde la posicion
			break;
		}
	}
	code=abc[pos][cont-1];//Guarda el char equivalente al numero a codificar segun la posicion en el array de numeros y la candtidad de veces que se repetia
	while (cont>0){
		Pop();//Libera los numeros de la pila
		cont--;
	}
	Push(code);//Mete el caracter codificado en la pila
}
void decodificar(char num[],char abc[][4],char val){//Decodifica las palabras en el mensaje escrito en un teclado t9,recibe un array de numeros, un array ultidimensional de caracteres y un caracter
	int pos;//Posicion en el array de numeros
	int cant;//Cantidad de veces que se deben repetir
	for (int i = 0; i < 10;i++){
		for (int j = 0; j < 4; j++){
			if (abc[i][j]==val){//Si el valor es igual al caracter en esa posicion
				pos=i;//Guarde la posicion en el array de numeros
				cant=j+1;//Guarde la cantidad de repeticiones
				break;
			}
		}
	}
	while (cant!=0){//Ingresa a la pila el numero la cantidad necesaria de veces
		Push(num[pos]);
		cant--;
	}
	Push('1');//Indica un tiempo de reposo
}
void leer1(char num[],char abc[][4],string mensaje){//Lee el menaje dado caracter por caracter
	int cont=0;//contador de veces que aparece el mismo numero
	string mcod;//String que guarda el mensaje ya codificado
	for (int i = 0; i < mensaje.length(); i++){
		if (mensaje[i]!='1'){
			cont++;
			Push(mensaje[i]);//Si el caracter no es 1 el cual significa indicador de espera, guarde el numero en la fila
		}
		else{//Cuando se indica el tiempo de espera
			codificar(num,abc,mensaje[i-1],cont);//codifique los numeros ingresados en la pila
			cont=0;//Reinicie el contador
		}
	}
	while(tope!=NULL)//Construye el mensaje
		mcod=Pop()+mcod;
	cout << mcod << endl;//Imprime el mensaje
}
void leer2(char num[],char abc[][4],string mensaje){//Lee el menaje dado caracter por caracter
	string mcod;//String que guarda el mensaje ya descodificado
	for (int i = 0; i < mensaje.length(); i++){
		decodificar(num,abc,mensaje[i]);//Descodifica caracter por caracter
	}
	while(tope!=NULL)//Construye el mensaje
		mcod=Pop()+mcod;
	cout << mcod << endl;//Imprime el mensaje	
}
void menu(){//Despliega el menu
	cout << "1.Codificar" << endl;
	cout << "2.Descodificar" << endl;
	cout << "3.Diccionario predictivo" << endl;
	cout << "4.Salir" << endl;
	cout << "Digite la opcion que desee realizar:";
	
}
void elegir (){//Procesa la eleccion del usuario y crea las tablas de codificacion
	char num[10] = {'1','2','3','4','5','6','7','8','9','0'};
	char abc[10][4] = {{'|'},
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v'},
			{'w','x','y','z'},
			{' ','.','?','!'}};
	int opcion;
	string mensaje;
	cin >> opcion;
	switch(opcion){
		case 1:
			cout << "Digite el mensaje que desea codificar" << endl;
			cin >> mensaje;
			leer1(num,abc,mensaje);
			break;
		case 2:
			cout << "Digite el mensaje que desea descodificar" << endl;
			getline(cin,mensaje);
			getline(cin,mensaje);
			leer2(num,abc,mensaje);
			break;
		case 3:
			cout << "No se ha implementado" << endl;
			break;
		case 4:
			cout << "Saliendo del programa" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
	}
}
int main(){
	menu();
	elegir();
	return 0;
}
