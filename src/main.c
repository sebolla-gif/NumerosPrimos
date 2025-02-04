#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(long unsigned int n)//Bool es lo que puede dar una respuesta binaria ocupando poco espacio.
{
    if (n < 2) return 0; //0 y 1 no son primos.
    for (int i = 2; i*i <= n; i++)//Teorema del divisor primo (sqrt(n)).
    {
        if (n % i == 0) return 0;
    }
    return 1;//Retornamos 1 en caso de ser primo.
}


long unsigned int VectorNumPrime(long unsigned int** ptr, long unsigned int* TotalNumPrime)
{
    static long unsigned int ultimo_primo = 2; //Estado persistente.
    long unsigned int contador = 0;
    float porc;
    printf("Ingrese la cantidad de numeros primos que desea almacenar:\n");
    if (scanf("%lu", TotalNumPrime) != 1)  // Verifica que se leyo 1 elemento
    {
        // Limpiar buffer en caso de entrada invalida
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada invalida. Se usara 0 por defecto.\n");
        *TotalNumPrime = 0;
        return 0;
    }
    if(*TotalNumPrime > 0)//revisamos que se almacene por lo menos un numero.
    {
        unsigned long int* temp = (long unsigned int*)realloc(*ptr, sizeof(long unsigned int)*(*TotalNumPrime));//Expandimos la memoria dinamica.
        if (!temp)
        {
            perror("Error al reasignar memoria");
            free(*ptr);
	    *ptr = NULL;
            exit(EXIT_FAILURE);
        }
        *ptr = temp;
        while(*TotalNumPrime > contador)
        {
            if(isPrime(ultimo_primo))
            {
                porc = ((float)(contador + 1) / (float)(*TotalNumPrime)) * 100;
                printf("Cargando %.2f %%\r", porc); // "\r" para sobrescribir la línea.
                fflush(stdout); // Asegura que el texto se muestre inmediatamente.
                *(*ptr + contador) = ultimo_primo;//Almacenamos valor con indirecciones en el puntero, arrancando desde 0.
                contador++;
            }
            ultimo_primo++;
        }
        printf("\n");
        return contador;
    }
    else
    {
        free(*ptr);
        *ptr = NULL;
        contador = 0;
    }
    return contador;
}
void MostrarVector(long unsigned int* ptr, long unsigned int contador)
{
    if(contador == 0)
    {
        printf("\nVector NULL\n");
        return;
    }
    for(long unsigned int i=0; i<contador; i++)//Mostramos por pantalla todos los numeros primos almacenados.
    {
        printf("%lu, ", *(ptr + i));
    }
    printf("\n");
    return;
}
int AlmacenarVector(long unsigned int* ptr, long unsigned int contador)
{
    if(contador == 0)
    {
        printf("\nVector NULL\n");
        return 0;
    }
    FILE* f;//Inicializamos un puntero FILE.
    f = fopen("PrimeNumbers.bin", "wb");//Creamos un archivo.
    if(f == NULL)//Comprobamos que el archivo se haya creado correctamente.
    {
        perror("\nError al abrir el archivo");
        return 1;
    }

    if (fwrite(ptr, sizeof(unsigned long), contador, f) != contador)//Almacenamos la informacion del vector dinamico en el archivo y comprobamos que la informacion se este almacenando correctamente.
    {
        perror("\nError al escribir el archivo");
        fclose(f);
        return 2;
    }
    if(fclose(f) != 0)//Cerramos el archivo y comprobamos que se cierre correctamente.
    {
        perror("\nError al cerrar el archivo");
        return 3;
    }
    printf("\nEl archivo se escribio correctamente\n");
    return 0;
}
int Menu()
{
    int op;
    printf("1.Llenar vector\n2.Mostrar vector\n3.Almacenar vector\n0.Salir\nIngrese una opcion:");
    scanf("%d",&op);
    return op;
}
int main(void)
{
    long unsigned int* ptr = NULL;//Uso de memoria dinamica para no depender de valores estaticos para en vector o el bucle.
    long unsigned int contador = 0;
    long unsigned int TotalNumPrime = 0;//Trabajamos con los valores positivos mas grandes posibles para no limitar al usuario.
    while(1)
    {
        switch(Menu())
        {
        case 1:
            contador = VectorNumPrime(&ptr,&TotalNumPrime);
            break;
        case 2:
            MostrarVector(ptr,contador);
            break;
        case 3:
            AlmacenarVector(ptr,contador);
            break;
        case 0:
            free(ptr);//Liberamos memoria.
            return 0;
        default:
            printf("opcion no valida");
            break;
        }
    }
}
