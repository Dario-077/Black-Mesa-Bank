#ifndef PRELOGIN_H
#define PRELOGIN_H

#include <stdio.h>
#include <string.h>

typedef struct { // Estructura para almacenar datos del usuario
    char username[50]; // Nombre de usuario maximo 49 caracteres
    char pin[5]; // PIN de 4 digitos + '\0'
    float saldo; // Saldo en dolares
    int numero_cuenta; // Numero de cuenta unico
} Usuario;
//Declarador de un arreglo global de usuarios
extern Usuario usuarios[10000]; // Arreglo para almacenar hasta 10,000 usuarios
extern int usercount; // Contador de usuarios registrados


void registrar_usuario(Usuario usuarios[], int *usercount);
void iniciarSesion(Usuario usuarios[], int usercount);
void mostrarUsuarios(Usuario usuarios[], int usercount);

#endif






