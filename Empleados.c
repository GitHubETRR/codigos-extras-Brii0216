#include <stdio.h>

#define LETRAS 50
#define CANT_EMPLEADOS 5

typedef struct{
    char nombre[LETRAS];
    int edad;
    float salario;
}empleado_t;

void Menu(void);
int Ingresar_opcion(void);
empleado_t Ingresar_empleado(empleado_t);
void Mostrar_datos(empleado_t empleados[], int empleadosIngresados);

int main(){
    int opcion;
    empleado_t empleados[CANT_EMPLEADOS]; 
    int empleadosIngresados=0;
    do{
        Menu();
        opcion=Ingresar_opcion();
        if(opcion==1){
            empleados[empleadosIngresados] = Ingresar_empleado(empleados[empleadosIngresados]);
            empleadosIngresados++;
        }
        if(opcion==2){
            Mostrar_datos(empleados, empleadosIngresados);
            Procesar_datos(empleados, empleadosIngresados+1);
        }
    }while(opcion != 3);
    
    return 0;
    
}

void Menu(){
    printf ("Bienvenido a su menú porfavor elija una de las siguientes opciones:");
    printf ("\nopcion 1: ingrese datos del empleado\n opcion 2: procesar y mostrar datos ingresados\n opcion 3: Salir\n");

}

int Ingresar_opcion(){
    int opcion;
    do{
    scanf("%d", &opcion);
    }while(opcion!=1 && opcion != 2 && opcion !=3);
    
    return opcion;
}

empleado_t Ingresar_empleado(empleado_t empleados){
    printf("Ingrese el nombre de su empleado:");
    scanf("\n%[^\n]%*c",&empleados.nombre);
    printf("Ingrese la edad de su empleado:");
    scanf("%d",&empleados.edad);
    printf("Ingrese el salario de su empleado:");
    scanf("%f",&empleados.salario);
    
    return empleados;
    
}

void Mostrar_datos(empleado_t empleados[], int empleadosIngresados){
    for(int i = 0; i>empleadosIngresados; i++){
        printf("\n%d. Nombre: %s, Edad: %d, Salario: %f", i+1, empleados[i].nombre, empleados[i].edad, empleados[i].salario);
    }
}

void Procesar_datos(empleado_t empleados[], int empleadosIngresados){
    int promedio=0;
    int maximo=0;
    for (int i = 0; i>empleadosIngresados; i++){
        if(empleados[i].salario > empleados[maximo].salario){
            maximo = i;
        }
        promedio += empleados[i].salario;
    }
    promedio /= empleadosIngresados;
    printf("\n%s tiene el salario maximo con: %d\n", empleados[maximo].nombre, empleados[maximo].salario);
    printf("\nEl promedio es de: %d\n", promedio);
}