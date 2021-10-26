#include "header.h"

/**
 * crea un nuevo nodo con su datos
 * @param id = identificador unico del nodo
 * @param tipo = que tipo de regalo es
 * @param descripcion = descripcion del regalo
 * @return
 */
Nodo * crearPremio(int id,string  tipo,string descripcion){
    Nodo * nuevoPremio = NULL;
    nuevoPremio = new Nodo;
    if(nuevoPremio != NULL){
        nuevoPremio->id = id;
        nuevoPremio->regalo.descripcion = descripcion;
        nuevoPremio->regalo.tipo = tipo;
        nuevoPremio->sig = NULL;
    } else {
        return NULL;
    }

    return nuevoPremio;
}
/**
 * inserta nuevos elementos a la lista sin importar el orden, solo valida id no repetido
 * @param header = el puntero de la cabecera de la lista
 * @param nuevoPremio = el nuevo nodo a insertar
 * @return
 */
bool insertarPremio(Nodo ** header,Nodo * nuevoPremio){
    // en el caso de que lista esta vacia
    if(*header == NULL){
        *header = nuevoPremio;
        nuevoPremio->sig = nuevoPremio;
        return true;
    }
    // en el caso de que halla mas nodos
    // nos colocamos que hasta al final de los nodos y vericamos que no se repita el id
    Nodo * nav = *header; // si solo fuera un nodo se queda en el mismo
    while (nav->sig != *header && nav->id != nuevoPremio->id){
        // recorremos el puntero
        nav = nav->sig;
    }
    // si hay un ID repitido no insertamos el nodo
    if(nav->id == nuevoPremio->id)
        return false;
    // agregamos el nodo al final de la lista
    // como sig del ultimo siempre apunta a la cabecera
    nuevoPremio->sig = nav->sig;
    nav->sig = nuevoPremio;
    return true;
}

void imprimirPremio(Nodo * premio){
    cout << "\n--- premido con ID " << premio->id << "-----" << endl;
    cout << "tipo: " << premio->regalo.tipo << endl;
    cout << "descripcion: " << premio->regalo.descripcion << endl;
}

/**
 * pinta los elementos de una lista
 * @param nav = el puntero de la lista a recorrer
 */
void mostrarPremios(Nodo * nav){
    if(nav == NULL){
        cout << "la lista esta vacia" << endl;
        return;
    }
    Nodo * aux = nav;
    do {
        imprimirPremio(nav);
        nav = nav->sig;
    } while(nav != aux);
}

/**
 * retorna la cantida de elementos en una lista
 * @param nav
 * @return
 */
int cantidad(Nodo * nav){
    int contador = 0;
    if(nav == NULL)
        return contador;
    Nodo * aux = nav;
    do {
        contador++;
        nav = nav->sig;
    } while(nav != aux);

    return contador;
}

/**
 * retorna un numero aleatorio entre 1 y 50
 * @return
 */
int hacerTurno(){
    // iniciamos una semilla para el random
    srand(time(NULL));
    int num = rand() % 51;
    if(num ==0)
        num = 1;
    return num;
}

/**
 * retorna el nodo identificado por un id
 * @param nav = el puntero de la lista a buscar el nodo
 * @param id = el indetificador del nodo a buscar
 * @return
 */
Nodo * buscarPremio(Nodo * nav,int id){
    if(nav == NULL)
        return NULL;
    Nodo * aux = nav;
    do {
        if(nav->id == id)
            return nav;
        nav = nav->sig;
    } while(nav != aux);
    return NULL;
}

