#include <stdio.h>
#include <stdlib.h>

struct nodo{
    char dato;
    nodo *izq;
    nodo *der;
};

void menu(nodo *&);
void insertar_nodo(nodo *&,char);
bool buscar_nodo(nodo *,char);
void mostrar_preorden(nodo *);
void mostrar_inorden(nodo *);
void mostrar_posorden(nodo *);
void modificar_nodo(nodo *&,char);

int main(){
    nodo *arbol=NULL;
    menu(arbol);
}

void menu(nodo *&arbol){
    int x, y;
    char a;

    system("cls");
    printf("******ARBOLES BINARIOS*********\n");
    printf("1. Insertar elementos\n");
    printf("2. Mostrar arbol\n");
    printf("3. Buscar nodo\n");
    printf("4. Modificar nodo\n");
    printf("5. Salir\n");
    printf("Digite opcion: ");
    scanf("%d",&x);

    switch(x){
        case 1:{
            do{
               printf("Ingrese caracter: ");
               scanf("%s",&a);
               insertar_nodo(arbol,a);
               printf("Ingresar mas caracteres 1.SI  2.NO: ");
               scanf("%d",&y);
            }while(y==1);
        }break;
        case 2:{
            system("cls");
            printf("1. Mostrar arbol en preorden\n");
            printf("2. Mostrar arbol en inorden\n");
            printf("3. Mostrar arbol en posorden\n");
            printf("Digite opcion: ");
            scanf("%d",&a);
            switch(a){
                case 1:{
                    mostrar_preorden(arbol);
                    printf("\n");
                }break;
                case 2:{
                    mostrar_inorden(arbol);
                    printf("\n");
                }break;
                case 3:{
                    mostrar_posorden(arbol);
                    printf("\n");
                }break;
                default: printf("Opcion incorrecta\n");
            }
        }break;
        case 3:{
            printf("Ingrese dato que desea buscar: ");
            scanf("%s",&a);
            if(buscar_nodo(arbol,a)==true){
                printf("Caracter encontrado\n");
            }else{
                printf("Caracter no encontrado\n");
            }
        }break;
        case 4:{
            printf("Ingrese dato que desea modificar: ");
            scanf("%s",&a);
            modificar_nodo(arbol,a);
        }break;
        case 5:{
            exit(5);
        }
    }
    system("pause");
    menu(arbol);
}

nodo *crear_nodo(char a){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=a;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

void insertar_nodo(nodo *&arbol, char a){
    int x=a;
    if(arbol==NULL){
        nodo *nuevo=crear_nodo(a);
        arbol=nuevo;
    }else{
        int y=arbol->dato;
        if(x<y){
            insertar_nodo(arbol->izq,a);
        }else{
            insertar_nodo(arbol->der,a);
        }
    }
}

bool buscar_nodo(nodo *arbol, char a){
    int x=a;
    if(arbol==NULL){
        return false;
    }else{
        if(arbol->dato==a){
            return true;
        }else{
            int y=arbol->dato;
            if(x<y){
                return buscar_nodo(arbol->izq,a);
            }else{
                return buscar_nodo(arbol->der,a);
            }
        }
    }
}

void mostrar_preorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        printf("%c",arbol->dato);
        mostrar_preorden(arbol->izq);
        mostrar_preorden(arbol->der);
    }
}

void mostrar_inorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_preorden(arbol->izq);
        printf("%c",arbol->dato);
        mostrar_preorden(arbol->der);
    }
}

void mostrar_posorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_preorden(arbol->izq);
        mostrar_preorden(arbol->der);
        printf("%c",arbol->dato);
    }
}

void modificar_nodo(nodo *&arbol, char a){
    int x=a;
    char c;
    if(arbol==NULL){
        return;
    }else{
        if(arbol->dato==a){
        printf("Ingrese nuevo dato: ");
        scanf("%s",&c);
        arbol->dato=c;
        }else{
            int y=arbol->dato;
            if(x<y){
                modificar_nodo(arbol->izq,a);
            }else{
                modificar_nodo(arbol->der,a);
            }
        }
    }
}






























































