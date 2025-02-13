# Generador de Números Primos

Este programa en C permite generar, almacenar y mostrar números primos utilizando memoria dinámica y almacenamiento en archivos binarios.

## Características
- Generación de números primos utilizando el Teorema del Divisor Primo.
- Uso de memoria dinámica para almacenar los números generados.
- Almacenamiento de los números primos en un archivo binario.
- Menú interactivo para realizar las operaciones.

> [!NOTE]
> El programa trabaja con variables del tipo unsigned long int (32 bits), por lo cual el numero mas grande que se puede usar es el 4.294.967.295.
>
>  La carpeta `bin` contiene un archivo con el primer millon de numeros primos, y un ejecutable del programa. 

Explicacion del algoritmo [Algoritmo de la división por tentativa](https://es.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/a/trial-division).

## Requisitos
Para compilar y ejecutar el programa, se necesita un compilador de C, como `gcc`.

## Compilación
Para compilar el programa, ejecute el siguiente comando en la terminal:

```sh
gcc main.c -o primos
```

## Uso
Ejecute el programa con:

```sh
./primos
```

### Menú de Opciones
El programa presenta las siguientes opciones:
1. **Llenar vector**: Genera números primos y los almacena en memoria.
2. **Mostrar vector**: Muestra en pantalla los números primos almacenados.
3. **Almacenar vector**: Guarda los números primos en un archivo binario (`PrimeNumbers.bin`).
4. **Salir**: Libera la memoria y termina la ejecución del programa.

## Estructura del Código

### Funciones Principales

- **`isPrime(n)`**: Verifica si un número es primo.
- **`VectorNumPrime(ptr, TotalNumPrime)`**: Genera números primos y los almacena en memoria dinámica.
- **`MostrarVector(ptr, contador)`**: Muestra los números primos almacenados en memoria.
- **`AlmacenarVector(ptr, contador)`**: Guarda los números primos en un archivo binario.
- **`Menu()`**: Muestra el menú de opciones y retorna la opción seleccionada.

### Archivo Binario
El programa almacena los números primos en un archivo binario llamado `PrimeNumbers.bin` para su posterior recuperación.

## Consideraciones
- Se usa `realloc()` para ajustar dinámicamente el tamaño del almacenamiento de números primos.
- Se verifica la entrada del usuario para evitar errores al leer valores inválidos.
- Se utiliza `fflush(stdout)` para actualizar la barra de progreso de generación de números primos.
- Se implementa un sistema de gestión de memoria para evitar fugas de memoria.

## Proximamente
Dado que el programa limita al usuario a trabajar con 32 bits, en poco tiempo espero poder realizar un nuevo repositorio usando `gmp.h` para que el unico limitante sea la memoria a disposicion.

## Licencia
MIT License © 2025 Sebastián Vaccaro
