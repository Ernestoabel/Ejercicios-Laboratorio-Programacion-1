#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmpleado;
int menu(char* mensajeUno,char* mensajeDos,char* mensajeTres,char* mensajeCuatro,char* mensajeCinco,char* mensajeSeis)
{
    int opcion;
    printf("%s",mensajeUno);
    printf("%s",mensajeDos);
    printf("%s",mensajeTres);
    printf("%s",mensajeCuatro);
    printf("%s",mensajeCinco);
    printf("%s",mensajeSeis);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int subMenu(char* mensajeUno,char* mensajeDos,char* mensajeTres,char* mensajeCuatro,char* mensajeCinco)
{
    int opcion;
    printf("%s",mensajeUno);
    printf("%s",mensajeDos);
    printf("%s",mensajeTres);
    printf("%s",mensajeCuatro);
    printf("%s",mensajeCinco);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int menuListado(char* mensajeUno,char* mensajeDos,char* mensajeTres)
{
    int opcion;
    printf("%s",mensajeUno);
    printf("%s",mensajeDos);
    printf("%s",mensajeTres);
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int inicializarEmpleados(eEmpleado* empleados,int cantidad,int estado)
{
	int retorno=-1,i;
	if(empleados != NULL && cantidad > 0 ){
		for(i = 0; i<cantidad; i++){
			empleados[i].isEmpty = estado;
		}
		retorno = 0;
	}

	return retorno;
}
int inicializarId(eEmpleado* empleados,int cantidad)
{
	int retorno=-1,i;
	if(empleados != NULL && cantidad > 0 ){
		for(i = 0; i<cantidad; i++){
			empleados[i].id = 0;
		}
		retorno = 0;
	}

	return retorno;
}
eEmpleado cargarEmpleado(int estado, int* id)
{
    eEmpleado carga;
	if(id != NULL){
		printf("Ingrese nombre empleado \n");
		fflush(stdin);
		scanf("%s", carga.name);
		printf("Ingrese apellido empleado \n");
		fflush(stdin);
		scanf("%s", carga.lastName);
		printf("Ingrese salario empleado \n");
		scanf("%f",&carga.salary);
		printf("Ingrese sector empleado \n");
		scanf("%d",&carga.sector);
		carga.id = *id;
		(*id)++;
		carga.isEmpty = estado;
	}
	return carga;
}
int buscarEspacioLibre(eEmpleado* empleados,int cantidad, int estado, int* id)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL&&id!=NULL)
    {
    	for(i=0;i<cantidad;i++){
    		if(empleados[i].isEmpty==estado){
    			retorno = i;
    			break;
    		}
        }
    }
    return retorno;
}
int continuarCarga(char mensaje[], char mensajeOpcion[])
{
    int opcion;
    printf("%s",mensaje);
	printf("%s",mensajeOpcion);
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int ingresarIdParaModificar(eEmpleado* empleados,int cantidad)
{
    int modificar,i,retorno=-1,entro=0;
    if(empleados!=NULL){
        do{
        	printf("\nIngrese id a modificar: ");
            scanf("%d",&modificar);
            for(i=0;i<cantidad;i++){
                if(empleados[i].isEmpty==0){
                    if(empleados[i].id==modificar){
                        modificar=i;
                        return modificar;
                        entro=1;
                        break;
                    }
                }
            }
            printf("\nEl numero de id no corresponde a un empleado\n");
        }while(entro!=1);
        retorno=0;
    }
    return retorno;
}
int mostrarEmpleados(eEmpleado* empleados,int cantidad)
{
    int retorno=-1;
    int i;
    if(empleados!=NULL)
    {
        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].isEmpty==0)
            {
                printf("\n%d\n%s\n%s\n%.2f\n%d\n",empleados[i].id,empleados[i].name,empleados[i].lastName,empleados[i].salary,empleados[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}
int modificarEmpleado(eEmpleado* modificar, int opcion,int posicion)
{
    int retorno = -1;
	if(modificar != NULL){
	    if(opcion==1){
    		printf("Ingrese nombre empleado \n");
    		fflush(stdin);
    		scanf("%s", modificar[posicion].name);
	    }
	    if(opcion==2){
    		printf("Ingrese apellido empleado \n");
    		fflush(stdin);
    		scanf("%s", modificar[posicion].lastName);
	    }
	    if(opcion==3){
    		printf("Ingrese salario empleado \n");
    		scanf("%f",&modificar[posicion].salary);
	    }
	    if(opcion==4){
    		printf("Ingrese sector empleado \n");
    		scanf("%d",&modificar[posicion].sector);
	    }
		retorno = 0;
	}
	return retorno;
}
int darDeBajaEmpleado(eEmpleado* modificar,int posicion,int estado)
{
    int retorno = -1;
    int baja;
	if(modificar != NULL){
	    printf("\nPrecione 1 para confirmar la baja del empleado: ");
	    scanf("%d",&baja);
	    if(baja==1){
	        modificar[posicion].isEmpty=estado;
	    }
	    else{
	        printf("\nBaja cancelada\n");
	    }
		retorno = 0;
	}
	return retorno;
}
int ordenarPorApellido(eEmpleado* ordenar,eEmpleado ordenador,int cantidad)
{
    int retorno=-1;
    int i,j;
    if(ordenar!=NULL){
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if (strcmp(ordenar[i].lastName,ordenar[j].lastName)<0){
                    ordenador=ordenar[i];
                    ordenar[i]=ordenar[j];
                    ordenar[j]=ordenador;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
int ordenarPorSector(eEmpleado* ordenar,eEmpleado ordenador,int cantidad)
{
    int retorno=-1;
    int i,j;
    if(ordenar!=NULL){
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if (ordenar[i].sector>ordenar[j].sector){
                    ordenador=ordenar[i];
                    ordenar[i]=ordenar[j];
                    ordenar[j]=ordenador;
                }
            }
        }
        retorno=0;
    }
    return retorno;
}
int sacarPromedioEstructuras(eEmpleado* calcular,int cantidad,float* resultado)
{
    int contadorEmpleados=0,i;
    float totalSueldos=0;
    if(calcular!=NULL){
        for(i=0;i<cantidad;i++){
            if(calcular[i].isEmpty==0){
                contadorEmpleados++;
                totalSueldos+=calcular[i].salary;
            }
        }
        *resultado=totalSueldos/contadorEmpleados;
    }
    return totalSueldos;
}
int calcularEmpleadosMejorPromedio(eEmpleado* calcular,int cantidad, float promedio)
{
    int contadorEmpleados=0,i;
    if(calcular!=NULL){
        for(i=0;i<cantidad;i++){
        	if(calcular[i].isEmpty==0){
				if(calcular[i].salary>promedio){
					contadorEmpleados++;
				}
        	}
        }
    }
    return contadorEmpleados;
}
