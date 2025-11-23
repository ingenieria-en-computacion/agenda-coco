#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

typedef enum { CASA, MOVIL, OFICINA, OTRO } TipoTelefono;
typedef enum { AMIGO, CONOCIDO, LABORAL } TipoContacto;
typedef enum { ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO,
               AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE } Mes;

typedef struct {
    char nombre[30];
    char apellido[30];
    int diaNacimiento;
    Mes mesNacimiento;
    char telefono[20];
    TipoTelefono tipoTelefono;
    TipoContacto tipoContacto;
} Contacto;

typedef struct {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
int buscar_contacto(Agenda *agenda, char *nombre);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);
void imprimir_agenda(Agenda agenda);
void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif
