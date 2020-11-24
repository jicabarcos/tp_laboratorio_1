#ifndef FUNCIONESADICIONALES_H_INCLUDED
#define FUNCIONESADICIONALES_H_INCLUDED

typedef struct{

    int id;
    char marca[50];
    int modelo;
    int precio;

}eAuto;

#endif // FUNCIONESADICIONALES_H_INCLUDED

#include "../inc/LinkedList.h"

int menuDeOpciones(int tipoDeMenu);
void mostrarAuto(eAuto* unAuto);
void mostrarAutos(LinkedList* lista);
int eliminarAuto(LinkedList* lista);
int vaciarLista(LinkedList* lista);
int eliminarLista(LinkedList* lista);
int lastId(int idLista);
eAuto generarElemento(LinkedList* lista);
int agregarElemento(LinkedList* lista, eAuto autoNuevo);
void* eliminarYGuardar(LinkedList* lista);
int compararListas(LinkedList* lista1, LinkedList* lista2);
LinkedList* crearSubLista(LinkedList* lista);
int ordenarAutoPorPrecio(void* auto1, void* auto2);
int auto_getPrecio(eAuto* unAuto, int* precio);
int filtrarAutosNuevos(void* unAuto);
eAuto* modificarAuto(LinkedList* lista);
