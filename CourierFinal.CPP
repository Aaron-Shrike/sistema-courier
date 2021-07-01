#include<stdio.h>
#include<conio.h>
#define max 60
struct paquetes
{
	int codigo;
   char descrip[10];
   float peso;
   float pago;
   int estado;
   char nombre[10];
   int dnides;
};
struct clientes
{
	int dni;
   char nombc[10];
   int npaq;
   float subt;
   paquetes P[max];
};
struct courier
{
   char nombco[20];
   float total;
   float pmax;
   float ppk;
   int ncli;
   clientes C[max];
};

void menu();
int leeposint(char msg[]);
float leeposfloat(char msg[]);
int leerangoint(char msg[],int a,int b);
float leerangofloat(char msg[],int a,int b);
void inicializar(courier &O);
void deposito(courier &O);
void recepcion(courier &O);
void alinear(char x[]);
void upestado(courier &O);
void balance(courier O);
void consulta(courier O);
void reporte(courier O);

main()
{
	courier O;
   int op,flag1=0,flag2=0,flag3=0;
   do
   {
      clrscr();
   	menu();
      op=leerangoint("\nIngrese opcion: ",1,8);
      switch(op)
      {
      	case 1:

               inicializar(O);
               flag1=1;
         		break;

         case 2:

               if(flag1==1)
               {
         			deposito(O);
                  flag2=1;
               }
               else
					{
               	printf("\nIngrese a la opcion 1.");
               }
         		break;

         case 3:

         		if(flag2==1)
               {
               	recepcion(O);
						flag3=1;
               }
               else
               {
               	printf("\nIngrese a la opcion 2.");
               }
         		break;

         case 4:

         		if(flag3==1)
               {
                 	upestado(O);
               }
               else
               {
               	printf("\nIngrese a la opcion 3.");
               }
         		break;

         case 5:

         		if(flag3==1)
               {
               	consulta(O);
               }
               else
               {
               	printf("\nIngrese a la opcion 3.");
               }
         		break;

         case 6:

         		if(flag3==1)
               {
               	reporte(O);
               }
               else
               {
               	printf("\nIngrese a la opcion 3.");
               }
         		break;

         case 7:

         		if(flag3==1)
               {
               	balance(O);
               }
               else
               {
               	printf("\nIngrese a la opcion 3.");
               }
         		break;

         case 8:

               printf("\n*** Fin del sistema. ***");
         		break;

      }
      getch();
   }while(!(op==8));
   getch();
}

void menu()
{
	printf("\n*** Sistema courier ***\n");
   printf("1.Inicializar\n");
   printf("2.Deposito\n");
   printf("3.Recepcion de encomiendas\n");
   printf("4.Actualizacion de estado\n");
   printf("5.Consulta\n");
   printf("6.Reporte general\n");
   printf("7.Balance del dia\n");
   printf("8.Salir\n");
}

int leeposint(char msg[])
{
	int num;
   do
   {
   	printf("%s",msg);
      scanf("%d",&num);
      if(num<=0)
      	printf("*ERROR*");
   }while(!(num>0));
   return num;
}

float leeposfloat(char msg[])
{
	float num;
   do
   {
   	printf("%s",msg);
      scanf("%f",&num);
      if(num<=0)
      	printf("*ERROR*");
   }while(!(num>0));
   return num;
}

int leerangoint(char msg[],int a,int b)
{
	int num;
   do
   {
   	printf("%s",msg);
      scanf("%d",&num);
      if(num<a || num>b)
      	printf("*ERROR*");
   }while(!(num>=a && num<=b));
   return num;
}

float leerangofloat(char msg[],int a,int b)
{
	float num;
   do
   {
   	printf("%s",msg);
      scanf("%f",&num);
      if(num<a || num>b)
      	printf("*ERROR*");
   }while(!(num>=a && num<=b));
   return num;
}

void inicializar(courier &O)
{
   int i,j;
	O.nombco[0]=NULL;
   O.total=0;
   O.pmax=0;
   O.ppk=0;
   O.ncli=0;
   for(i=0;i<max;i++)
   {
      O.C[i].dni=0;
      O.C[i].nombc[0]=NULL;
      O.C[i].npaq=0;
      O.C[i].subt=0;
   	for(j=0;j<max;j++)
      {
      	O.C[i].P[j].codigo=0;
       	O.C[i].P[j].descrip[0]=NULL;
         O.C[i].P[j].peso=0;
         O.C[i].P[j].pago=0;
         O.C[i].P[j].estado=0;
         O.C[i].P[j].nombre[0]=NULL;
         O.C[i].P[j].dnides=0;
      }
   }
   printf("\nInicializacion exitosa. :)\n");
}

void deposito(courier &O)
{
   printf("\nIngrese nombre de la courier: ");
   scanf("%s",&O.nombco);
	O.pmax=leeposfloat("Ingrese peso maximo del dia: ");
   O.ppk=leeposfloat("Ingrese precio por kilogramo: ");
}

void recepcion(courier &O)
{
	int j,k,rpta;
   if(O.pmax>0)
   {
   	printf("\n*Cliente %d*",O.ncli+1);
   	printf("\n");
      O.C[O.ncli].dni=leerangoint("\nIngrese numero de DNI: ",10000000,99999999);
      printf("Ingrese nombre: ");
      scanf("%s",&O.C[O.ncli].nombc);
      O.C[O.ncli].npaq=leeposint("Ingrese cantidad de paquetes: ");
      for(j=0;j<O.C[O.ncli].npaq;j++)
      {
      	printf("\nPaquete %d",j+1);
         /*Generacion de codigo*/
         O.C[O.ncli].P[j].codigo=0;
         if(O.ncli==0)
         {
         	O.C[O.ncli].P[j].codigo=100+j;
         }
         else
         {
         	for(k=0;k<O.ncli;k++)
            {
            	O.C[O.ncli].P[j].codigo=O.C[O.ncli].P[j].codigo+O.C[k].npaq;
            }
            O.C[O.ncli].P[j].codigo=O.C[O.ncli].P[j].codigo+100+j;
         }
         printf(" - Codigo de envio: %d",O.C[O.ncli].P[j].codigo);
         printf("\nIngrese descripcion: ");
         scanf("%s",&O.C[O.ncli].P[j].descrip);
         printf("Ingrese nombre del destinatario: ");
         scanf("%s",&O.C[O.ncli].P[j].nombre);
         O.C[O.ncli].P[j].dnides=leerangoint("Ingrese numero de DNI del destinatario: ",10000000,99999999);
         O.C[O.ncli].P[j].peso=leeposfloat("Ingrese peso en kilogramos: ");
         O.C[O.ncli].P[j].pago=O.C[O.ncli].P[j].peso*O.ppk;
         if(O.pmax-O.C[O.ncli].P[j].peso>=0)
         {
         	O.pmax=O.pmax-O.C[O.ncli].P[j].peso;
            printf("\nEl paquete se enviara hoy.");
            printf("\nEl precio de envio del paquete es de %.2f soles.\n",O.C[O.ncli].P[j].pago);
            O.C[O.ncli].subt=O.C[O.ncli].subt+O.C[O.ncli].P[j].pago;
            O.C[O.ncli].P[j].estado=1;
         }
         else
         {
         	printf("\nSu paquete no podra salir el dia de hoy, sino manhana\n");
         	printf("Desea enviar de todos modos?");
            printf("\n1.Si");
            printf("\n2.No");
            rpta=leerangoint("\nIngrese respuesta: ",1,2);
            if(rpta==1)
            {
            	printf("\nEl paquete se enviara manhana.");
               printf("\nEl precio de envio del paquete es de %.2f soles\n",O.C[O.ncli].P[j].pago);
               O.C[O.ncli].subt=O.C[O.ncli].subt+O.C[O.ncli].P[j].pago;
               O.C[O.ncli].P[j].estado=1;
            }
            else
            {
            	printf("\nNo lo podemos atender\n");
            }
         }
      }
		printf("\nEl total a pagar por el cliente es de %.2f soles\n",O.C[O.ncli].subt);
      O.total=O.total+O.C[O.ncli].subt;
      O.ncli=O.ncli+1;
   }
   else
   {
   	printf("\nSu(s) paquete(s) no podra(n) salir el dia de hoy, sino manhana\n");
      printf("Desea enviar de todos modos?");
      printf("\n1.Si");
   	printf("\n2.No");
      rpta=leerangoint("\nIngrese respuesta: ",1,2);
      if(rpta==1)
      {
      	printf("\n*Cliente %d*",O.ncli+1);
         printf("\n");
      	O.C[O.ncli].dni=leerangoint("\nIngrese numero de DNI: ",10000000,99999999);
         printf("Ingrese nombre: ");
         scanf("%s",&O.C[O.ncli].nombc);
         O.C[O.ncli].npaq=leeposint("Ingrese cantidad de paquetes: ");
         for(j=0;j<O.C[O.ncli].npaq;j++)
         {
         	printf("\nPaquete %d",j+1);
            /*Generacion de codigo*/
         	O.C[O.ncli].P[j].codigo=0;
         	if(O.ncli==0)
         	{
         		O.C[O.ncli].P[j].codigo=100+j;
         	}
         	else
         	{
         		for(k=0;k<O.ncli;k++)
            	{
            		O.C[O.ncli].P[j].codigo=O.C[O.ncli].P[j].codigo+O.C[k].npaq;
            	}
            	O.C[O.ncli].P[j].codigo=O.C[O.ncli].P[j].codigo+100+j;
         	}
         	printf(" - Codigo de envio: %d",O.C[O.ncli].P[j].codigo);
            printf("\nIngrese descripcion: ");
         	scanf("%s",&O.C[O.ncli].P[j].descrip);
         	printf("Ingrese nombre del destinatario: ");
         	scanf("%s",&O.C[O.ncli].P[j].nombre);
            O.C[O.ncli].P[j].dnides=leerangoint("Ingrese numero de DNI del destinatario: ",10000000,99999999);
            O.C[O.ncli].P[j].peso=leeposfloat("Ingrese peso en kilogramos: ");
            O.C[O.ncli].P[j].pago=O.C[O.ncli].P[j].peso*O.ppk;
            printf("\nEl paquete se enviara manhana.");
            printf("\nEl precio de envio del paquete es de %.2f soles\n",O.C[O.ncli].P[j].pago);
            O.C[O.ncli].subt=O.C[O.ncli].subt+O.C[O.ncli].P[j].pago;
            O.C[O.ncli].P[j].estado=1;
         }
         printf("\nEl total a pagar por el cliente es de %.2f soles\n",O.C[O.ncli].subt);
         O.total=O.total+O.C[O.ncli].subt;
         O.ncli=O.ncli+1;
      }
      else
      {
      	printf("\nNo lo podemos atender\n");
      }
   }
}

void alinear(char x[])
{
	int i;
	for(i=0;i<10;i++)
   {
   	if(x[i]==NULL)
      {
      	printf(" ");
      }
   }
}

void upestado(courier &O)
{
   int i,j,rpta,n;
   n=leeposint("\nIngrese codigo de paquete: ");
   for(i=0;i<O.ncli;i++)
   {
   	for(j=0;j<O.C[i].npaq;j++)
      {
      	if(n==O.C[i].P[j].codigo)
         {
         	printf("\nActualizacion de estado: ");
   			printf("\n1.Pendiente.");
   			printf("\n2.En viaje.");
   			printf("\n3.En destino.");
   			printf("\n4.Entregado.");
   			rpta=leerangoint("\nIngrese opcion: ",1,4);
				O.C[i].P[j].estado=rpta;
         }
      }
   }
}

void balance(courier O)
{
	printf("\nEl total recaudado del dia es: S/%.2f",O.total);
}

void consulta(courier O)
{
	int i,j,n;
   n=leeposint("\nIngrese codigo de paquete: ");
   for(i=0;i<O.ncli;i++)
   {
   	for(j=0;j<O.C[i].npaq;j++)
      {
      	if(n==O.C[i].P[j].codigo)
         {
         	printf("\nRemitente (DNI)       Destinatario (DNI)       Descripcion     Peso       Costo      Estado");
   			printf("\n===============================================================================================");
            printf("\n");
            printf("%s",O.C[i].nombc);
         	alinear(O.C[i].nombc);
         	printf("(%d)  ",O.C[i].dni);
         	printf("%s",O.C[i].P[j].nombre);
         	alinear(O.C[i].P[j].nombre);
         	printf("   (%d)  ",O.C[i].P[j].dnides);
         	printf("%s",O.C[i].P[j].descrip);
         	alinear(O.C[i].P[j].descrip);
         	if(O.C[i].P[j].peso<10)
         	{
         		printf("      0%.2fKg",O.C[i].P[j].peso);
         	}
         	else
         	{
            	printf("      %.2fKg",O.C[i].P[j].peso);
         	}
         	printf("    S/%.2f    ",O.C[i].P[j].pago);
         	switch(O.C[i].P[j].estado)
         	{
         		case 1: printf("Pendiente \n");
            		break;
         		case 2: printf("En viaje  \n");
            		break;
            	case 3: printf("En destino\n");
            		break;
            	case 4: printf("Entregado \n");
            		break;
         	}
         }
      }
   }
}

void reporte(courier O)
{
   int i,j;
   printf("\nNombre de la courier: %s",O.nombco);
   printf("\nNumero de clientes atendidos: %d",O.ncli);
   printf("\n");
   printf("\nCodigo    Remitente (DNI)       Destinatario (DNI)       Descripcion     Peso       Costo      Estado");
   printf("\n=========================================================================================================");
   printf("\n");
	for(i=0;i<O.ncli;i++)
   {
   	for(j=0;j<O.C[i].npaq;j++)
      {
         printf(" %d      ",O.C[i].P[j].codigo);
         printf("%s",O.C[i].nombc);
         alinear(O.C[i].nombc);
         printf("(%d)  ",O.C[i].dni);
         printf("%s",O.C[i].P[j].nombre);
         alinear(O.C[i].P[j].nombre);
         printf("   (%d)  ",O.C[i].P[j].dnides);
         printf("%s",O.C[i].P[j].descrip);
         alinear(O.C[i].P[j].descrip);
         if(O.C[i].P[j].peso<10)
         {
         	printf("      0%.2fKg",O.C[i].P[j].peso);
         }
         else
         {
            printf("      %.2fKg",O.C[i].P[j].peso);
         }
         printf("    S/%.2f    ",O.C[i].P[j].pago);
         switch(O.C[i].P[j].estado)
         {
         	case 1: printf("Pendiente \n");
            	break;
         	case 2: printf("En viaje  \n");
            	break;
            case 3: printf("En destino\n");
            	break;
            case 4: printf("Entregado \n");
            	break;
         }
      }
   }
}
