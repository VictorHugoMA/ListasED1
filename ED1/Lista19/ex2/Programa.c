#include<stdio.h>
#include"TCircList.h"

    int main(){
        aluno a[10]={
        {120, "Victor", 10, 10, 10},
        {110, "Pedro", 10, 10, 10},
        {130, "Joao", 7, 8, 10},
        {105, "Maria", 7.5, 9.1, 10},
        {150, "Guilherme", 6.5, 9.0, 8},
        {100, "Alisson", 10, 10, 10},
        {170, "Felipe", 10, 10, 10},
        {200, "Carolina", 7, 8, 10},
        {115, "Jorge", 7.5, 9.1, 10},
        {195, "Ana", 6.5, 9.0, 8}
        }, aC;
        int aux, pos, mat;

        CircList *c;

        c = list_creat();

        list_push_back(c, a[3]);
        list_push_back(c, a[1]);

        list_push_front(c, a[0]);
        list_push_front(c, a[2]);
        

        list_print(c);

        printf("\nRemovendo um elemento:\n");
        list_pop_front(c);
        list_print(c);

        aux = list_size(c);
        printf("\n%d\n", aux);

        printf("Imprimindo o proximo aluno:");
        print_next(c);




        list_free(c);
        return 0;
    }