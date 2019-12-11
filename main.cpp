#include<iostream>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<cstdlib>
using namespace std;
struct Tpersona
{
    char nombre[40];
    int dni;
    int sueldo;

};
struct Tnodo
{
    Tpersona informacion;

    Tnodo *sgt;
};

void leerDatos(Tpersona &info)
{
    fflush(stdin);
    cout<<"Ingrese el nombre: ";
    cin.getline(info.nombre,40,'\n');
    cout<<"Ingrese su dni: ";
    cin>>info.dni;
    cout<<"Ingrese su sueldo: ";
    cin>>info.sueldo;
}

void mostrarDatos(Tpersona &info)
{
    cout<<"Nombre: "<<info.nombre<<endl;
    cout<<"Dni: "<<info.dni<<endl;
    cout<<"Sueldo: "<<info.sueldo<<endl;
}

void crearInicio(Tnodo *&pI)
{
    char res[5];
    Tnodo *nuevoN;
    pI=new Tnodo;
    leerDatos(pI->informacion);
    pI->sgt=NULL;
    fflush(stdin);
    cout<<"¿Desea ingresar un nuevo nodo al inicio de la lista?: ";
    cin.getline(res,5,'\n');
    while((strcmp(res,"si")==0)||(strcmp(res,"SI")==0))
    {
        nuevoN =new Tnodo;
        leerDatos(nuevoN->informacion);
        nuevoN->sgt=pI;
        pI=nuevoN;
        fflush(stdin);
        cout<<"¿Desea ingresar un nuevo nodo al inicio de la lista?: ";
        cin.getline(res,5,'\n');
    }
}

void crearFinal(Tnodo *&pI)

{
    char res[5];
    Tnodo *nuevoN;
    Tnodo *aux;
    pI= new Tnodo;
    leerDatos(pI->informacion);
    pI->sgt=NULL;
    aux=pI;
    fflush(stdin);
    cout<<"¿Desea Ingresar un nuevo nodo al final de la lista?: ";
    cin.getline(res,5,'\n');
    while((strcmp(res,"si")==0)||(strcmp(res,"SI")==0))
    {
       nuevoN=new Tnodo;
       leerDatos(nuevoN->informacion);
       nuevoN->sgt=NULL;
       aux->sgt=nuevoN;
       aux=nuevoN;
        fflush(stdin);
    cout<<"¿Desea Ingresar un nuevo nodo al final de la lista?: ";
    cin.getline(res,5,'\n');
    }

}

void insertarInicio(Tnodo *&pI)
{
    Tnodo *nuevoN;
    nuevoN=new Tnodo;
    leerDatos(nuevoN->informacion);
    nuevoN->sgt=pI;
    pI=nuevoN;
}

void insertarFinal(Tnodo *&pI)
{
    Tnodo *aux;
    Tnodo *nuevoN;
    aux=pI;
    while(aux->sgt!=NULL)
    {
        aux=aux->sgt;
    }
    nuevoN=new Tnodo;
    leerDatos(nuevoN->informacion);
    nuevoN->sgt=NULL;
    aux->sgt=nuevoN;
}
void insertarAntes(Tnodo *&pI, int x)
{

    Tnodo *q;
    Tnodo *aux2;
    Tnodo *nuevoN;
    q=pI;
    int band=1;
    while((q->informacion.dni!=x)&&(band==1))
    {
        if (q->sgt!=NULL)
        {
            aux2=q;
            q=q->sgt;
        }
        else
        {
            band=0;
        }
    }

    if (band==1)
    {
       nuevoN= new Tnodo;
       leerDatos(nuevoN->informacion);
       if(pI->informacion.dni==q->informacion.dni)
            {
                nuevoN->sgt=pI;
                pI=nuevoN;
            }
       else
            {
                aux2->sgt=nuevoN;
                nuevoN->sgt=q;
            }

    }
    else
    {
            cout<<"error";
    }
}


void insertarDespues(Tnodo *&pI,int x)
{

    Tnodo *q;
    Tnodo *aux;
    q=pI;
    int band=1;
    while((q->informacion.dni!=x)&&(band==1))
    {
        if(q->sgt!=NULL)
        {
            q=q->sgt;
        }
        else
        {
            band==0;
        }
    }
    if(band==1)
    {
        aux=new Tnodo;
        leerDatos(aux->informacion);
        aux->sgt=q->sgt;
        q->sgt=aux;
    }
    else
    {
        cout<<"Error";
    }

}


void buscarNodo(Tnodo *&pI,int x)
{
    Tnodo *aux;
    aux=pI;
    while((aux!=NULL)&&(aux->informacion.dni!=x))
    {
        aux=aux->sgt;
    }
    if(aux==NULL)
    {
        cout<<"***********************************************"<<endl;
        cout<<"EL NODO NO SE ENCUENTRA EN LA LISTA"<<endl;
        cout<<"***********************************************"<<endl;
    }
    else
    {
        cout<<"***********************************************"<<endl;
        cout<<"EL NODO SI SE ENCUENTRA EN LA LISTA"<<endl;
        cout<<"***********************************************"<<endl;
    }

}

void eliminarNodo(Tnodo *&pI,int x)
{
    Tnodo *q;
    Tnodo *aux;
    int band=1;
    q=pI;
    while((q->informacion.dni!=x)&&(band==1))
    {
        if(q->sgt!=NULL)
        {
            aux=q;

            q=q->sgt;
        }
        else
        {
            band=0;
        }
    }

    if(band==0)
    {
        cout<<"El elemento con esa información no se encuentra en la lista. ";
    }
    else
    {
        if(pI->informacion.dni==q->informacion.dni)
        {
            pI=q->sgt;
        }
        else
        {
            aux->sgt=q->sgt;
        }
        delete q;
    }



}


void recorreIterativo(Tnodo *&pI)
{
    cout<<"\n<<MOSTRANDO DATOS>>"<<endl;
    Tnodo *q;
    q=pI;
    while(q!=NULL)
    {
        cout<<"**************************************"<<endl;
        mostrarDatos(q->informacion);
        q=q->sgt;
        cout<<"**************************************"<<endl;
    }
}


void menu()
{
    cout<<"\t\t\t\t\t\t\tMENU-LISTAS"<<endl;
    cout<<"\t\t\t\t\t**************************************"<<endl;
    cout<<"\t\t\t\t\t1.CREAR NODOS AL INICIO."<<endl;
    cout<<"\t\t\t\t\t2.CREAR NODOS AL FINAL."<<endl;
    cout<<"\t\t\t\t\t3.INSERTAR NODOS AL INICIO."<<endl;
    cout<<"\t\t\t\t\t4.INSERTAR NODOS AL FINAL."<<endl;
    cout<<"\t\t\t\t\t5.MOSTRAR NODOS INGRESADOS."<<endl;
    cout<<"\t\t\t\t\t6.INSERTAR NODOS ANTES DE UN NODO."<<endl;
    cout<<"\t\t\t\t\t7.INSERTAR NODOS DESPUES DE UN NODO."<<endl;
    cout<<"\t\t\t\t\t8.BUSCAR UN NODO."<<endl;
    cout<<"\t\t\t\t\t9.ELIMINAR UN NODO."<<endl;
    cout<<"\t\t\t\t\t10.SALIR"<<endl;
    cout<<"\t\t\t\t\t**************************************"<<endl;
}

int main()
{
    int op;
    system("color A");
    int ant;
    int des;
    int bus;
    int elim;
    Tnodo *lista;

    setlocale(LC_CTYPE, "Spanish");
    do
    {
    menu();
    cout<<"Porfavor ingrese una opcion: ";
    cin>>op;
    system("cls");
    switch(op)
        {
        case 1: crearInicio(lista);
                cout<<"\n";
                break;
        case 2: crearFinal(lista);
                cout<<"\n";
                break;
        case 3: insertarInicio(lista);
                cout<<"\n";
                break;
        case 4: insertarFinal(lista);
                cout<<"\n";
                break;
        case 5: recorreIterativo(lista);
                cout<<"\n";
                system("pause");
                break;
        case 6:
                cout<<"Ingrese el dni del nodo que desea insertar antes: ";
                cin>>ant;
                insertarAntes(lista,ant);
                cout<<"\n";
                break;
        case 7:
                cout<<"Ingrese el dni del nodo que desea insertar despues: ";
                cin>>des;
                insertarDespues(lista,des);
                cout<<"\n";
                break;

        case 8: cout<<"Ingrese el dni del nodo que desea buscar: ";
                cin>>bus;
                buscarNodo(lista,bus);
                system("pause");
                cout<<"\n";
                break;

        case 9: cout<<"Ingrese el dni del nodo que desea eliminar: ";
                cin>>elim;
                eliminarNodo(lista,elim);
        }
        system("cls");

    }while(op!=10);






    return 0;
}
