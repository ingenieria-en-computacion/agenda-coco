#include <stdio.h>
#include "agenda.h"

int main(){
    Agenda agenda;
    iniciar_agenda(&agenda);

    char archivo[] = "contactos.txt";
    cargar_contactos(archivo,&agenda);

    int opcion;
    do{
        printf("\n=== MENU ===\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar agenda\n");
        printf("3. Buscar contacto\n");
        printf("4. Ordenar A-Z\n");
        printf("5. Ordenar Z-A\n");
        printf("6. Guardar contactos\n");
        printf("0. Salir\n");
        printf("Elige una opcion: "); scanf("%d",&opcion);

        switch(opcion){
            case 1:{
                Contacto c;
                leer_contacto(&c);
                agregar_contacto(&agenda,c);
                break;
            }
            case 2:
                imprimir_agenda(agenda);
                break;
            case 3:{
                char nombre[30];
                printf("Nombre a buscar: "); scanf("%s",nombre);
                int idx = buscar_contacto(&agenda,nombre);
                if(idx>=0) mostrar_contacto(agenda.contactos[idx]);
                else printf("No encontrado.\n");
                break;
            }
            case 4:
                ordenar_contactos(&agenda);
                printf("Contactos ordenados A-Z.\n");
                break;
            case 5:
                ordenar_contactos_inv(&agenda);
                printf("Contactos ordenados Z-A.\n");
                break;
            case 6:
                guardar_contactos(archivo,agenda);
                printf("Contactos guardados.\n");
                break;
            case 0:
                guardar_contactos(archivo,agenda);
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    }while(opcion!=0);

    return 0;
}
