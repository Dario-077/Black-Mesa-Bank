#include <stdio.h>
#include "preLogin.h"
#include "postLogin.h"

void estado_cuenta(Usuario *usuarios) { // Función para mostrar el estado de la cuenta
    printf("Estado de la cuenta\n"); // Encabezado del estado de cuenta
    printf("Usuario: %s\n", usuarios->username); // Muestra el nombre de usuario
    printf("Numero de cuenta: %d\n", usuarios->numero_cuenta); // Muestra el numero de cuenta
    printf("PIN: XXXX\n"); // no disponible el PIN por seguridad
    printf("Su saldo actual es: %.2f\n", usuarios->saldo); // Muestra el saldo actual
    printf("Gracias por usar Black Mesa Bank.\n"); // Mensaje de despedida
}

void deposito(Usuario *usuarios) { // Función para realizar un depósito
    float monto; // Variable para el monto a depositar
    printf("Ingrese el monto a depositar: ");
    scanf("%f", &monto); // lee el monto y almacena en "monto"
    getchar();
    if (monto <= 0) { // Verifica que el monto sea mayor a cero
        printf("Monto invalido. El monto debe ser mayor a cero.\n");
    } else { // Si el monto es valido, realiza el deposito
    usuarios->saldo += monto;
    printf("Deposito exitoso. Su nuevo saldo es: %.2f\n", usuarios->saldo);
    }
}

void retiro(Usuario *usuarios) { // Función para realizar un retiro
    float monto; // Variable para el monto a retirar
    printf("Ingrese el monto a retirar: ");
    scanf("%f", &monto); // lee el monto y almacena en "monto"
    getchar();
    if (monto > usuarios->saldo) { // Verifica que haya fondos suficientes
        printf("Fondos insuficientes. Su saldo actual es: %.2f\n", usuarios->saldo);
    } else if (monto <= 0) { // Verifica que el monto sea mayor a cero
        printf("Monto invalido. El monto debe ser mayor a cero.\n");
    } else { // Si hay fondos suficientes, realiza el retiro
        usuarios->saldo -= monto; // Resta el monto del saldo
        printf("Retiro exitoso. Su nuevo saldo es: %.2f\n", usuarios->saldo);
    }
}

void menu_inicio_sesion(Usuario *usuarios) { // Función para mostrar el menú de inicio de sesión
    int opcion; // Variable para la opción del menú

    do {
        printf("\nMenu de inicio de sesion:\n");
        printf("---Seleccione una opcion---\n");
        printf("1) Estado de cuenta\n");
        printf("2) Depositos\n");
        printf("3) Retiros\n");
        printf("4) Cerrar sesion\n");

        printf("\nIngrese su opcion: ");
        scanf("%d", &opcion); // lee la opcion y almacena en "opcion"
        getchar();

        while (opcion < 1 || opcion > 4) { // Verifica que la opcion sea valida
            printf("Opcion invalida. Por favor, ingrese una opcion valida (1-4): ");
            scanf("%d", &opcion);
            getchar();
        }
        switch (opcion) { // Estructura de control para manejar las opciones del menú
            case 1:
                estado_cuenta(usuarios); // Llama a la función para mostrar el estado de la cuenta
                break;
            case 2:
                deposito(usuarios); // Llama a la función para realizar un depósito
                break;
            case 3:
                retiro(usuarios); // Llama a la función para realizar un retiro
                break;
            case 4:
                return; // Cerrar sesion
                break;
            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida (1-4).\n"); // Mensaje de error para opción inválida
        }
    } while (1);
}