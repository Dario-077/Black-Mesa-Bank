#include <stdio.h> //libreria estandar de entrada y salida
#include <string.h> //libreria para manejo de cadenas
#include <stdlib.h> //libreria estandar para funciones de exit
#include "preLogin.h"






int main(void) {
    int registros; // Variable para la opción del menú

    do {
        printf("\nBlack Mesa Bank\n");
        printf("----------------\n");
        printf("1. Crear nuevo usuario\n");
        printf("2. Iniciar sesion\n");
        printf("3. Mostrar usuarios\n");
        printf("4. Cerrar programa\n");
        printf("----------------\n");
        printf("Seleccione una opcion (1-4): ");
        scanf("%d", &registros); // lee la opcion y almacena en "registros"
        getchar();

        switch (registros) { // Estructura de control para manejar las opciones del menú
            case 1:
                registrar_usuario(usuarios, &usercount); // Llama a la función para registrar un nuevo usuario
                break;
            case 2:
                iniciarSesion(usuarios, usercount); // Llama a la función para iniciar sesión
                break;
            case 3:
                mostrarUsuarios(usuarios, usercount); // Llama a la función para mostrar todos los usuarios registrados
                break;
            case 4:
                printf("Cerrar programa seleccionado.\n"); 
                exit(0); // Sale del programa
            default:
                printf("¡Error!, seleccione una opcion valida (1-4).\n"); // Mensaje de error para opción inválida
        }
    } while (1); 
}