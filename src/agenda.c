#include "agenda.h"
#include <stdio.h>
#include <string.h>

char *mesesStr[] = {
    "Enero","Febrero","Marzo","Abril","Mayo","Junio",
    "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"
};

char *tiposTelStr[] = {"Casa","Movil","Oficina","Otro"};
char *tiposContStr[] = {"Amigo","Conocido","Laboral"};

void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}

void agregar_contacto(Agenda *agenda, Contacto c){
    if(agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos++] = c;
    }
}

int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i=0;i<agenda->num_contactos;i++){
        if(strcmp(agenda->contactos[i].nombre,nombre)==0) return i;
    }
    return -1;
}

void ordenar_contactos(Agenda *a){
    for(int i=0;i<a->num_contactos-1;i++){
        for(int j=i+1;j<a->num_contactos;j++){
            if(strcmp(a->contactos[i].nombre,a->contactos[j].nombre)>0){
                Contacto tmp=a->contactos[i];
                a->contactos[i]=a->contactos[j];
                a->contactos[j]=tmp;
            }
        }
    }
}

void ordenar_contactos_inv(Agenda *a){
    for(int i=0;i<a->num_contactos-1;i++){
        for(int j=i+1;j<a->num_contactos;j++){
            if(strcmp(a->contactos[i].nombre,a->contactos[j].nombre)<0){
                Contacto tmp=a->contactos[i];
                a->contactos[i]=a->contactos[j];
                a->contactos[j]=tmp;
            }
        }
    }
}

void mostrar_contacto(Contacto c){
    printf("%s %s | %d/%s | %s | %s\n",
        c.nombre,
        c.apellido,
        c.diaNacimiento,
        mesesStr[c.mesNacimiento],
        c.telefono,
        tiposContStr[c.tipoContacto]);
}

void leer_contacto(Contacto *c){
    int mes,tipoTel,tipoCont;
    printf("Nombre: "); scanf("%s",c->nombre);
    printf("Apellido: "); scanf("%s",c->apellido);
    printf("Dia de nacimiento: "); scanf("%d",&c->diaNacimiento);
    printf("Mes de nacimiento (1-12): "); scanf("%d",&mes);
    c->mesNacimiento = mes-1;
    printf("Telefono: "); scanf("%s",c->telefono);
    printf("Tipo de telefono (0=Casa,1=Movil,2=Oficina,3=Otro): "); scanf("%d",&tipoTel);
    c->tipoTelefono = tipoTel;
    printf("Tipo de contacto (0=Amigo,1=Conocido,2=Laboral): "); scanf("%d",&tipoCont);
    c->tipoContacto = tipoCont;
}

void imprimir_agenda(Agenda agenda){
    printf("\nPersona | Cumpleaños | Telefono | Tipo de contacto\n");
    printf("---------------------------------------------------\n");
    for(int i=0;i<agenda.num_contactos;i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename,"r");
    if(!f) return;
    while(!feof(f)){
        Contacto c;
        int mes,tel,cont;
        if(fscanf(f,"%29[^|]|%29[^|]|%d|%d|%19[^|]|%d|%d\n",
            c.nombre,c.apellido,
            &c.diaNacimiento,&mes,
            c.telefono,&tel,&cont) == 7){
                c.mesNacimiento = mes;
                c.tipoTelefono = tel;
                c.tipoContacto = cont;
                agenda->contactos[agenda->num_contactos++] = c;
            }
    }
    fclose(f);
}

void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename,"w");
    if(!f) return;
    for(int i=0;i<agenda.num_contactos;i++){
        Contacto c = agenda.contactos[i];
        fprintf(f,"%s|%s|%d|%d|%s|%d|%d\n",
            c.nombre,c.apellido,c.diaNacimiento,c.mesNacimiento,
            c.telefono,c.tipoTelefono,c.tipoContacto);
    }
    fclose(f);
}
