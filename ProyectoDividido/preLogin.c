#include "preLogin.h"
#include "postLogin.h"

Usuario usuarios[10000]; // Arreglo para almacenar hasta 10,000 usuarios
int usercount = 0; // Contador de usuarios registrados

void registrar_usuario(Usuario usuarios[], int *usercount) { // Función para registrar un nuevo usuario
    char nombre[50]; // Nombre de usuario maximo 49 caracteres
    char pin[10]; // 4 dígitos + '\0'
    float saldo; // Saldo inicial en dolares

    printf("Ingrese su nombre de usuario: ");
    scanf("%49s", nombre); // lee como cadena y almacena en "nombre"
    getchar();

    printf("Ingrese su clave (PIN de 4 digitos): ");
    scanf("%9s", pin); // lee como cadena y almacena en "pin"
    getchar();

    while (strlen(pin) != 4 || strspn(pin, "0123456789") != 4) { //El strlen verifica la longitud del PIN y strspn verifica que todos los caracteres sean dígitos
        printf("PIN invalido. Ingrese un PIN de 4 digitos: ");
        scanf("%4s", pin); // lee como cadena y almacena en "pin"
        getchar();
    }

    do {
        printf("Ingrese su saldo inicial en dolares: ");
        scanf("%f", &saldo); // lee el saldo y almacena en "saldo"
        getchar();

        if (saldo < 0) // Verifica que el saldo no sea negativo
            printf("El saldo no puede ser negativo.\n");

    } while (saldo < 0); // Repite hasta que se ingrese un saldo valido

   // Guardar en la posición actual
    strcpy(usuarios[*usercount].username, nombre); // El strcpy copia el nombre al struct y el usercount es el contador de usuarios
    strcpy(usuarios[*usercount].pin, pin); // Copia el PIN al struct
    usuarios[*usercount].saldo = saldo; // Asigna el saldo al struct

    // Generar número de cuenta automático
    usuarios[*usercount].numero_cuenta = 1000 + *usercount; // Ejemplo: empieza en 1000

    printf("Usuario %s registrado correctamente.\n", nombre); // Mensaje de confirmación
    printf("Su numero de cuenta es: %d\n", usuarios[*usercount].numero_cuenta); // Mostrar número de cuenta

    (*usercount)++;  // aumentar contador global de usuarios
}

void iniciarSesion(Usuario usuarios[], int usercount) { // Función para iniciar sesión
    int cuenta; // Numero de cuenta del usuario
    char pin[4]; // PIN de 4 digitos + '\0'

    printf("Ingrese numero de cuenta: ");
    scanf("%d", &cuenta);  // lee el numero de cuenta y almacena en "cuenta"
    getchar();

    printf("Ingrese PIN: ");
    scanf("%5s", pin); // lee como cadena y almacena en "pin"
    getchar();

    for (int i = 0; i < usercount; i++) {
        if (usuarios[i].numero_cuenta == cuenta &&
            strcmp(usuarios[i].pin, pin) == 0) { // Verifica si el numero de cuenta y PIN coinciden, strcmp compara las cadenas
            printf("Inicio de sesion exitoso. Bienvenido %s!\n", usuarios[i].username); // Mensaje de bienvenida
            menu_inicio_sesion(&usuarios[i]); // Llama al menú de inicio de sesión pasando la dirección del usuario encontrado
            return; // Salir de la función después de iniciar sesión
        }
    }

    printf("Cuenta o PIN incorrectos. Por favor, intente nuevamente.\n"); // Mensaje de error si no se encuentra el usuario
}

void mostrarUsuarios(Usuario usuarios[], int usercount) { // Función para mostrar todos los usuarios registrados
    printf("Usuarios registrados:\n");
    for (int i = 0; i < usercount; i++) { // Itera sobre todos los usuarios registrados
        printf("%d. %s - Numero de Cuenta: %d\n", i+1, usuarios[i].username, usuarios[i].numero_cuenta); // Muestra el nombre de usuario y número de cuenta
    }
}
