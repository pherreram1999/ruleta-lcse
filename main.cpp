#include "header.h"

// initial data

Regalo regalos[2] = {
        {
            "automovil",
            "Dogde Dart 1980"
        },
        {
            "consola",
            "PlayStation 5"
        }
};


int main() {
    // varaibles globales
    string descripcion,tipo;
    int id,res;

    // inciamos nuestra lista
    Nodo * header = NULL;

    // llenamos nuestros dos primeros nodos
    for(int i = 0; i < 2; i++){
        Nodo * nuevoNodo = crearPremio(i+1,regalos[i].tipo,regalos[i].descripcion);
        if(!insertarPremio(&header,nuevoNodo)){
            cout << "no fue posible insertar el nodo con id " << i +1 << endl;
        }
    }

    cout << "Bienvenido a la ruleta" << endl;
    cout << "----------------------" << endl;
    cout << "los premios cargados son: " << endl;
    mostrarPremios(header);
    do {
        cout << "\n¿Desea ingresar otro premio?:" << endl;
        cout << "1.-si 2.-no" << endl;
        cout << "res: "; cin >> res;
        if(res == 1){
            cout << "----------------------" << endl;
            cout << "Datos del nuevo premio" << endl;
            cout << "Favor de ingresar un ID para el premio" << endl;
            cout << "ID: "; cin >> id;
            cout << "Favor de proporcionar el tipo del regalo" << endl;
            cout << "tipo: "; cin >> tipo;
            cout << "Favor de proporcionar la descripcion del regalo" << endl;
            cout << "Descripcion: "; cin >> descripcion;
            // creamos el nodo
            Nodo * premioNodo = crearPremio(id,tipo,descripcion);
            if(premioNodo != NULL){
                if(!insertarPremio(&header,premioNodo)){
                    cout << "no se pudo insertar el nodo con id " << id << endl;
                }
            } else {
                cout << "Hubo un problema al crear el nodo" << endl;
            }
        }
    } while(res == 1);

    if(cantidad(header) > 2){
        // significa que ha agregado nuevos nodos
        cout << "-------------------------------------------------" << endl;
        cout << "La lista con los nuevos nodos esta compuesta por:" << endl;
        mostrarPremios(header);
    }
    cout << "La lista tiene " << cantidad(header) << " elementos en la lista" << endl;

    cout << "-----------------" << endl;
    cout << "busqueda del premio" << endl;
    cout << "¿Desea editar un premio" << endl;
    cout << "1.- si 2.- no" << endl;
    cout << "res: "; cin >> res;
    if(res == 1){
        cout << "ID del premio a editar " << endl;
        cout << "ID: "; cin >> id;
        cout << "---- buscando regalo -----" << endl;
        Nodo * premioBuscado = buscarPremio(header,id);
        if(premioBuscado != NULL){
            cout << "Nodo encotrado :D\n" << endl;
            imprimirPremio(premioBuscado);
            string tipoTmp, descripcionTmp;
            cout << "\n---- editando el nodo con id " << premioBuscado->id << "----" << endl;
            cout << "Favor de proporcionar el tipo" << endl;
            cout << "tipo: "; cin >> tipoTmp;
            cout << "Favor de proporcionar la descripcion" << endl;
            cout << "descripcion: "; cin >> descripcionTmp;
            editarPremdio(premioBuscado,tipoTmp,descripcionTmp);
            cout << "---- premio editado ----" << endl;
            cout << "--- mostrando de nuevo los premios" << endl;
            mostrarPremios(header);
        } else {
            cout << "Premio con ID " << id << " no econtrado" << endl;
        }
    }

    // generamos el turno

    int turno = hacerTurno();

    cout << "Tu turno es " << turno;

    return 0;
}
