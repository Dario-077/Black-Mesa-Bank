#ifndef PRELOGIN_H
#define PRELOGIN_H

#include <stdio.h>
#include <string.h>

// 1. PRIMERO LA ESTRUCTURA: Para que el compilador sepa qué es un "Usuario"
typedef struct { // Estructura para almacenar datos del usuario
    char username[50]; // Nombre de usuario maximo 49 caracteres
    char pin[5]; // PIN de 4 digitos + '\0'
    float saldo; // Saldo en dolares
    int numero_cuenta; // Numero de cuenta unico
} Usuario;

// 2. DECLARADOR DE VARIABLES GLOBALES: Usan el tipo 'Usuario' definido arriba
//Declarador de un arreglo global de usuarios
extern Usuario usuarios[10000]; // Arreglo para almacenar hasta 10,000 usuarios
extern int usercount; // Contador de usuarios registrados

// 3. PROTOTIPOS DE FUNCIONES: Ahora ya pueden usar 'Usuario' sin errores
void menu_inicio_sesion(Usuario *usuarios); // Función para mostrar el menú de inicio de sesión
void registrar_usuario(Usuario usuarios[], int *usercount);
void iniciarSesion(Usuario usuarios[], int usercount);
void mostrarUsuarios(Usuario usuarios[], int usercount);

#endif