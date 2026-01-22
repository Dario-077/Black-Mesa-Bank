#include <stdio.h> //libreria estandar de entrada y salida
#include <string.h> //libreria para manejo de cadenas
#include <stdlib.h> //libreria estandar para funciones de exit

typedef struct { // Estructura para almacenar datos del usuario
    char username[50]; // Nombre de usuario maximo 49 caracteres
    char pin[5]; // PIN de 4 digitos + '\0'
    float saldo; // Saldo en dolares
    int numero_cuenta; // Numero de cuenta unico
} Usuario;
//Declarador de un arreglo global de usuarios
Usuario usuarios[10000]; // Arreglo para almacenar hasta 10,000 usuarios 
int usercount = 0; // Contador de usuarios registrados

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

void registrar_usuario(Usuario usuarios[], int *usercount) { // Función para registrar un nuevo usuario
    char nombre[50]; // Nombre de usuario maximo 49 caracteres
    char pin[5]; // 4 dígitos + '\0'
    float saldo; // Saldo inicial en dolares

    printf("Ingrese su nombre de usuario: ");
    scanf("%49s", nombre); // lee como cadena y almacena en "nombre"
    getchar();

    printf("Ingrese su clave (PIN de 4 digitos): ");
    scanf("%4s", pin); // lee como cadena y almacena en "pin"
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
    char pin[5]; // PIN de 4 digitos + '\0'

    printf("Ingrese numero de cuenta: ");
    scanf("%d", &cuenta);  // lee el numero de cuenta y almacena en "cuenta"
    getchar();

    printf("Ingrese PIN: ");
    scanf("%4s", pin); // lee como cadena y almacena en "pin"
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