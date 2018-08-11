
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_SOLDADOS = 7
typedef struct {
    int id;
    int type;
    char* name;
    struct Soldados *prox;
    
} Soldados;

int QNTSOLDADOS = 0;
Soldados* startList() {
    return NULL;
}

/*Soldados* insert(Soldados *lista, int num, char* n) {
    Soldados* novo_no = (Soldados*) malloc(sizeof(Soldados));
    novo_no->id = num;
    novo_no->name = n;
   
    if(lista == NULL){ novo_no->type=2;novo_no->prox = novo_no;} else {
        novo_no->prox=lista;
         novo_no->type=0;
    }
    Soldados *p;
    while (1!=1) {
        if(p->type == 2) {p->prox = novo_no; break;}
        p=p->prox;
    }
    
    return novo_no;
}*/
int count(Soldados *l) {
    int firstID=l->id;
    int i=0;
    Soldados* p;
    for (p=l->prox; p != NULL; p=p->prox) {
        if(i==QNTSOLDADOS){break;}
        i++;
    }
    return i;
}

Soldados* insert(Soldados *lista, int num, char* n) {
    Soldados* novo_no = (Soldados*) malloc(sizeof(Soldados));
    novo_no->id = num;
    novo_no->name = n;
    
    if(lista == NULL){novo_no->prox = novo_no; QNTSOLDADOS++; return novo_no;} else {
        novo_no->prox=lista;
        QNTSOLDADOS++;
    }
    Soldados *p, *aux;
    p=novo_no;
    int i=1;
    while (2>1) {
        if(i == QNTSOLDADOS) {p->prox = novo_no; break;}
        p=p->prox;
        i++;
    }
    aux=p->prox;
    
    return aux;
}

void imprime (Soldados* l) {
    int i=0;
    Soldados* p;
    for (p=l; p != NULL; p=p->prox) {
        printf(" I: %d %s - %d\n",i, p->name, p->id);
        if(p->type==2){break;}
        i++;
    }
}


Soldados *returnFirst (Soldados *l) { //ok
    Soldados* p;
    for (p=l; p != NULL; p=p->prox) {
        if(p->type==2){break;}
    }
    return p->prox;
}

/*
Soldados *RM (Soldados *lista, int id) {
    Soldados *p, *aux, *retorno, *percoreAuxiliar;
    int i=0;
    p=lista;
    for (p=lista; p != NULL; p=p->prox) {
        if(p->id == id) {
            //encontrou
            if(p->type == 2) {
                //ultimo - OK
                
                aux->type=2;
                aux->prox = lista;
                retorno = aux->prox;
                break;
            } else {
                if(i==0) {
                    //primeiro nó
                    //printf("PRIMEIRO");
                    for (percoreAuxiliar=lista; percoreAuxiliar != NULL;percoreAuxiliar=percoreAuxiliar->prox) {
                        if(percoreAuxiliar->type==2) {break;}
                        aux = percoreAuxiliar;
                    }
                    //aux->prox = percoreAuxiliar->prox;
                    percoreAuxiliar->prox = lista->prox;
                    //printf("       %d         ",aux->type);
                    retorno = percoreAuxiliar;
                    retorno=returnFirst(retorno);
                    break;
                    
                } else {
                    //printf("MEIO");
                    percoreAuxiliar = p->prox;
                    aux->prox = percoreAuxiliar;
                    retorno = aux;
                    //printf("       %d      ", retorno->id);
                    break;
                }
            }
        }
        aux = p;
        i++;
    }
    return retorno;
}
 */

Soldados *RM (Soldados *lista, int id) {
    Soldados *p, *ant, *aux, *retorno, *percoreAuxiliar;
    ant=NULL;
    p=lista;
    while(1>0) {
        if(p->id == id) {
            if(ant==NULL) {
                //primeiro, logo n existe o ant
                aux = lista->prox;
                ant=lista;
                while(1>0) {
                    printf("%d \n", aux->id);
                    if(aux->id == id) {
                        printf("REMOVEU O %d \n", id);
                        ant->prox = aux->prox;
                        retorno=ant;
                        break;
                    }
                    ant=aux;
                    aux=aux->prox;
                }
            }else {
                printf("REMOVEU O %d \n", id);
                ant->prox = p->prox;
                retorno=ant;
            }
            
            break;
        }
        ant=p;
        p=p->prox;
    }
    QNTSOLDADOS--;
    return retorno;
}








Soldados *josefo(Soldados *lista, int M) {
    if(lista == NULL){
        printf("Lista vazia");
        return lista;
    }
    
    if(count(lista) == 1) {
        printf("12");
        return lista;
    }
    
    //inicia a contagem
    int i=0;
    Soldados *p, *retorno;
    p=lista;
    
    while(1>0) {
        if(i == M) {break;}
        i++;
        p=p->prox;
    }
    
    printf(" Escolheu %s \n", p->name);
    lista = RM(lista, p->id);
    if(QNTSOLDADOS > 1) {
        lista = josefo(lista, rand());
    } else {
        return lista;
    }
    /*while(count(lista) > 1) {
        
        for(p=lista;p!=NULL;p=p->prox) {
            if(i==num) {printf("REMOVEU O %d \n", p->id);lista = RM(lista, p->id); break;}
            i++;
        }
        //imprime(lista); printf("\n\n");
    }*/
    
    /*for (p=lista; p != NULL; p=p->prox) {
        
        if(M == i) {
            //remove o mesimo
            printf("REMOVEU O %d \n", p->id);
            lista = RM(lista, p->id); //remove
            if(count(lista) > 1){
                int num = rand() %100;
                printf("%d \n", num);
                return josefo(lista, num);
            } else {
                return lista;
            }
        }
        i++;
    }*/
    //QNTSOLDADOS--;
    return lista;
}



int main(int argc, const char * argv[]) {
    Soldados* t;
    int i= 0;
    //insert list
   
    t = startList();
    t = insert(t, 7, "Joao");
    t = insert(t, 6, "Jose");
    t = insert(t, 5, "Augusto");
    t = insert(t, 4, "Flavio");
    t = insert(t, 3, "Alexandre");
    t = insert(t, 2, "Camolesi");
    t = insert(t, 1, "Martins");
    
    //sortei o primeiro
    int numFirst = rand(); //sortei entre 0-6
    /*while(1>0) {
        if(i == numFirst) {break;}
        i++;
        t=t->prox;
        printf("%s \n", t->name);
    }*/
    int num = rand();
    
    //t=RM(t, 7);
    
    t=josefo(t, num);
    //imprime(t);
    
    printf("O SOLDADO SORTUDO E O %s DE ID: %d", t->name, t->id);
    /*while(1>0) {
        //printf("%s \n", t->name);
        t=t->prox;
        if(i==QNTSOLDADOS+6) {break;}
        i++;
    }*/
    return 0;
}



