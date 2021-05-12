#include<stdio.h>
#include<stdlib.h>
#include"TDLinkedList.h"

typedef struct DLNode DLNode;

struct DLNode{
    aluno data;
    DLNode *prev;
    DLNode *next;
};

struct TDLinkedList{
    DLNode *begin;
    DLNode *end;
    int size;
};

DLlist* list_creat(){
    DLlist *list;

    list = malloc(sizeof(DLlist));

    if(list!=NULL){
        list->begin=NULL;
        list->end=NULL;
        list->size=0;
    }
    return list;
}

int list_free(DLlist *l){
    if(l==NULL)
        return INVALID_NULL_POINTER;
    
    else{
        DLNode *atu, *prox;

        atu=l->begin;

        while(atu != NULL){
            prox=atu->next;
            free(atu);
            atu=prox;
        }

        free(l);
        return SUCCESS;
    }
}

int list_push_front(DLlist *l, aluno a){
    if(l==NULL)
        return INVALID_NULL_POINTER;
    else{
        DLNode *n;

        n = malloc(sizeof(DLNode));

        if(n==NULL)
            return OUT_OF_MEMORY;
        
        else{
            n->data=a;
            n->prev=NULL;
            n->next=l->begin;

            if(l->begin==NULL){
                l->begin=n;
                l->end=n;
                l->size=1;
            }
            else{
                l->begin->prev=n;
                l->begin=n;
                l->size++;
            }
            return SUCCESS;
        }
    }

}

int list_insert(DLlist *l, int pos, aluno a){
    if(l == NULL)
        return INVALID_NULL_POINTER;
    if(pos<1 || pos>l->size+1)
        return OUT_OF_RANGE;

    else{
        DLNode *n;
        n=malloc(sizeof(DLNode));

        if(n==NULL)
            return OUT_OF_MEMORY;

        else{
            n->data=a;

            if(l->size==0){
                n->prev=NULL;
                n->next=NULL;
                l->begin=n;
                l->end=n;
                l->size++;
            }
            else if(pos==1){
                n->prev=NULL;
                n->next=l->begin;
                l->begin->prev=n;
                l->begin=n;
                l->size++;
            }
            else if(pos==l->size+1){
                n->next=NULL;
                n->prev=l->end;
                l->end->next=n;
                l->end=n;
                l->size++;
            }
            else{
                int cont=1;
                DLNode *aux;

                aux=l->begin;
                while (cont<pos-1){
                   aux=aux->next;
                   cont++;
                }
                n->prev=aux;
                n->next=aux->next;
                aux->next->prev=n;
                aux->next=n;
                l->size++;
            }
            return SUCCESS;
        }
    }
}

int list_print_forward(DLlist *l){
    if(l == NULL)
        return INVALID_NULL_POINTER;

    else{
        DLNode *aux;
        aux = l->begin;

        printf("\nImprimindo a lista\n");
        while(aux!=NULL){
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %.1f; %.1f; %.1f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        return SUCCESS;

    }
}


int list_print_reverse(DLlist *l){
    if(l == NULL)
        return INVALID_NULL_POINTER;
        
    else{
        DLNode *aux;
        aux = l->end;

        printf("\nImprimindo a lista - Reverso\n");
        while(aux!=NULL){
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %.1f; %.1f; %.1f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->prev;
        }
        return SUCCESS;

    }
}