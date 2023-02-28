/*
Una tienda en línea permite mostrar y vender productos.
Para la práctica se debe crear una aplicación que simule una tienda en línea con mínimo 5
productos que permita realizar compras electrónicas (un carrito de compra). La aplicación
debe cumplir con las siguientes especificaciones:
• La función principal (main) sólo debe tener una llamada a la función menú.
• La función menú debe contener las opciones:
– Mostrar productos: Muestra el nombre y la descripción de los productos que
oferta la tienda en línea con sus precios y cantidad de productos disponibles.
– Agregar producto: Permite agregar el producto y la cantidad seleccionada al
carrito de compra. La cantidad se resta al stock de la tienda.
– Eliminar producto: Permite eliminar el producto y la cantidad seleccionada
del carrito de compra. La cantidad se regresa al stock de la tienda.

– Mostrar carrito: Muestra la cantidad de productos seleccionados, el costo par-
cial y el costo total de la compra.

– Comprar los productos: Genera un ticket de compra (con la información de
mostrar carrito) y lo guarda en un archivo de texto. Vacía el carrito de compras.
– Salir: Cierra el programa. Si el carrito tiene productos debe preguntar si en
realidad se desea salir de la aplicación sin realizar la compra.
• La función principal, la función menú y todas las opciones del menú deben estar
programadas en funciones separadas y en archivos diferentes.

EDAI: Práctica 1 Aplicaciones de arreglos

• La información de la tienda y del carrito deben estar almacenada en arreglos unidi-
mensionales o multidimensionales.

“There is no programming languaje – no matter how structured – that will prevent
programmers from making bad programs.”
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



struct producto{
    char nombre[20];
    char descripcion[50];
    int precio;
    int cantidad_disponible;
};



int mostrar_productos(struct producto *productos){
    int i;
    for(i=0; i<5; i++){
        printf("Nombre: %s", productos[i].nombre);
        printf("Descripcion: %s", productos[i].descripcion);
        printf("Precio: %d", productos[i].precio);
        printf("Cantidad disponible: %d", productos[i].cantidad_disponible);
    }
}



int agregar_producto(struct producto *productos, struct producto *carrito){
    int i;
    int opcion;
    int cantidad;
    printf("Que producto desea agregar?");
    scanf("%d", &opcion);
    printf("Cuantos productos desea agregar?");
    scanf("%d", &cantidad);
    if(cantidad > productos[opcion].cantidad_disponible){
        printf("No hay suficientes productos");
    }
    else{
        carrito[opcion].cantidad_disponible += cantidad;
        productos[opcion].cantidad_disponible -= cantidad;
    }
}



int eliminar_producto(struct producto *productos, struct producto *carrito){
    int i;
    int opcion;
    int cantidad;
    printf("Que producto desea eliminar?");
    scanf("%d", &opcion);
    printf("Cuantos productos desea eliminar?");
    scanf("%d", &cantidad);
    if(cantidad > carrito[opcion].cantidad_disponible){
        printf("No hay suficientes productos");
    }
    else{
        carrito[opcion].cantidad_disponible -= cantidad;
        productos[opcion].cantidad_disponible += cantidad;
    }
}



int mostrar_carrito(struct producto *carrito){
    int i;
    int total = 0;
    for(i=0; i<5; i++){
        printf("Nombre: %s", carrito[i].nombre);
        printf("Cantidad: %d", carrito[i].cantidad_disponible);
        printf("Precio: %d", carrito[i].precio);
        printf("Subtotal: %d", carrito[i].precio * carrito[i].cantidad_disponible);
        total += carrito[i].precio * carrito[i].cantidad_disponible;
    }
    printf("Total: %d", total);
}



int comprar_productos(struct producto *carrito){
    int i;
    FILE *archivo;
    archivo = fopen("ticket.txt", "w");
    for(i=0; i<5; i++){
        fprintf(archivo, "Nombre: %s", carrito[i].nombre);
        fprintf(archivo, "Cantidad: %d", carrito[i].cantidad_disponible);
        fprintf(archivo, "Precio: %d", carrito[i].precio);
        fprintf(archivo, "Subtotal: %d", carrito[i].precio * carrito[i].cantidad_disponible);
    }
    fclose(archivo);
}



int salir(){
 
   

    if(carrito[i].cantidad_disponible > 0){
        printf("Desea salir sin comprar los productos?");
        scanf("%d", &opcion);
        if(opcion == 1){
            exit(0);
        }
        else{
            menu();
        }
    }
    else{
        exit(0);
    }
}


int menu(){
    int opcion;
    printf("1. Mostrar productos");
    printf("2. Agregar producto");
    printf("3. Eliminar producto");
    printf("4. Mostrar carrito");
    printf("5. Comprar los productos");
    printf("6. Salir");
    scanf("%d", &opcion);

    
    while(1){
        switch(opcion){
            case 1:sdd
                mostrar_productos(productos);
                break;
            case 2:
                agregar_producto(productos, carrito);
                break;
            case 3:
                eliminar_producto(productos, carrito);
                break;
            case 4:
                mostrar_carrito(carrito);
                break;
            case 5:
                comprar_productos(carrito);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }

}
