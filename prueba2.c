#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>





struct producto{
    char nombre[20];
    char descripcion[100];
    int precio;
    int cantidad;
    int id;
};

struct producto *llenar_producto(struct producto *productos){
    
    productos[0].id = 1;
    strcpy(productos[0].nombre, "Chocolate");
    strcpy(productos[0].descripcion, "Chocolate con leche");
    productos[0].precio = 10.0;
    productos[0].cantidad = 10;
    productos[1].id = 2;
    strcpy(productos[1].nombre, "Pizza");
    strcpy(productos[1].descripcion, "Pizza de pepperoni");
    productos[1].precio = 20.0;
    productos[1].cantidad = 10;
    productos[2].id = 3;
    strcpy(productos[2].nombre, "Agua");
    strcpy(productos[2].descripcion, "Agua mineral");
    productos[2].precio = 5.0;
    productos[2].cantidad = 10;
    productos[3].id = 4;
    strcpy(productos[3].nombre, "Onigiri");
    strcpy(productos[3].descripcion, "Onigiri de atún");
    productos[3].precio = 15.0;
    productos[3].cantidad = 10;
    productos[4].id = 5;
    strcpy(productos[4].nombre, "Galletas");
    strcpy(productos[4].descripcion, "Galletas de chocolate");
    productos[4].precio = 10.0;
    productos[4].cantidad = 10;
}

void *mostrar_productos(struct producto *productos){
    
    for(int i = 0; i < 5; i++){

        printf("Nombre: %s\n", productos[i].nombre);
        printf("Descripcion %s\n", productos[i].descripcion);
        printf("Precio: %f\n", productos[i].precio);
        printf("Cantidad disponible: %d\n", productos[i].cantidad);
        printf("Id: %d\n", productos[i].id);
    }
}

int *agregar_producto(struct producto *productos, int *carrito[6][2]){
    printf("¿Digite el id del producto que desea agregar");
    int id;
    scanf("%d", &id);
    printf("¿Cuantos productos desea agregar?");
    int cantidad;
    scanf("%d", &cantidad);
    if (cantidad > productos[id].cantidad){
        printf("No hay suficientes productos");
        return 0;
    }
    productos[id].cantidad -= cantidad;
    carrito[id][1] += cantidad;
    return 1;
}

int *eliminar_producto(struct producto *productos, int *carrito[6][2]){
    printf("¿Digite el id del producto que desea eliminar");
    int id;
    scanf("%d", &id);
    printf("¿Cuántos productos desea eliminar?");
    int cantidad;
    scanf("%d", &cantidad);
    if (cantidad > carrito[id][1]){
        printf("No hay suficientes productos en el carrito");
        return 0;
    }
    productos[id].cantidad += cantidad;
    carrito[id][1] -= cantidad;
    return 1;
}

int *mostrar_carrito(struct producto *productos, int *carrito[6][2]){
    for(int i = 0; i < 6; i++){
        if (carrito[i][1] != 0){
            printf("Nombre: %s", productos[i].nombre);
            printf("Costo: %f", productos[i].precio*carrito[i][1]);
        }
    }

    float costo_total = 0;

    for(int i = 0; i < 6; i++){
        if (carrito[i][1] != 0){
            costo_total += productos[i].precio*carrito[i][1];
        }
    }

    printf("Costo total: %f", costo_total);

    return 0;

}

void comprar_productos(struct producto *productos, int *carrito[6][2]){
    FILE *fp;
    fp = fopen("recibo.txt", "w");
    fprintf(fp, "Factura de compra\n");
    for(int i = 0; i < 6; i++){
        if (carrito[i][1] != 0){
            fprintf(fp, "Nombre: %s", productos[i].nombre);
            fprintf(fp, "Costo: %f", productos[i].precio*carrito[i][1]);
        }
    }

    float costo_total = 0;

    for(int i = 0; i < 6; i++){
        if (carrito[i][1] != 0){
            costo_total += productos[i].precio*carrito[i][1];
        }
    }

    fprintf(fp, "Costo total: %f", costo_total);
    fclose(fp);


    for(int i = 0; i < 6; i++){
        carrito[i][1] = 0;
    }

}

void salir(struct producto *productos, int *carrito[6][2]){
    if (carrito[1][1] != 0 || carrito[2][1] != 0 || carrito[3][1] != 0 || carrito[4][1] != 0 || carrito[5][1] != 0 || carrito[6][1] != 0){
        printf("¿Desea comprar los productos en el carrito? (s/n)");
        char respuesta;
        scanf("%c", &respuesta);
        if (respuesta == 's'){
            comprar_productos(&productos, &carrito);
        }
        else{
            exit(0);

        }
    }
    else{
        exit(0);
    }

}

void menu(){

    int opcion;
    printf("Buenos dias ¿Que desea hacer? \n");

    printf("¿Que desea hacer? \n");
    printf("1. Mostrar productos\n");
    printf("2. Agregar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Mostrar carrito\n");
    printf("5. Comprar productos\n");
    printf("6. Salir\n");

    scanf("%d", &opcion);

    int a = -1;

    int *carrito[6][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

    struct producto productos[5];
    llenar_producto(&productos);

    switch(opcion){
        case 1:
            mostrar_productos(&productos);
            break;
        case 2:
            a = agregar_producto(&productos, &carrito);
            if (a == 0){
                printf("No se pudo agregar el producto");
            }
            else{
                printf("Producto agregado");
            }
            break;
        case 3:
            a = eliminar_producto(&productos, &carrito);
            if (a == 0){
                printf("No se pudo eliminar el producto");
            }
            else{
                printf("Producto eliminado");
            }
            break;
        case 4:
            mostrar_carrito(&productos, &carrito);
            break;
        case 5:
            comprar_productos(&productos, &carrito);
            break;
        case 6:
            salir(&productos, &carrito);
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }
}

int main(){
    menu();
    return 0;
}
