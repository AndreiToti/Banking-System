#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "iban.h"
#include "meniu.h"
#include "afisare.h"
#include "register.h"
#include "adauga_bani.h"
#include "tranzactii.h"
#include "edit.h"
#include "after_log.h"



int main(int argc,char* argv[])
{
    char *nume= malloc(20*sizeof(char));
    char *prenume= malloc(20*sizeof(char));
    strcpy(nume,argv[1]);
    strcpy(prenume,argv[2]);
    if(login(nume,prenume)==0)
    {
        printf("Acest cont nu exista!\nInregistreaza-ti un cont!\n\n");
        regis();
        printf("\n");
    }
    if(login(nume,prenume)==1)
    {
        printf("\n");
        after_log(nume,prenume);
    }

    printf("\nO zi buna!<3");

    return 0;
}
