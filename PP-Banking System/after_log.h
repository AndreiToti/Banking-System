void after_log(char *nume,char*prenume)
{
    meniu();
    int optiune;
    scanf("%d",&optiune);
    printf("\n");
    while(optiune<=6)
    {
        if(optiune==1)
        {
            system(("cls"));
            stergere_cont(nume,prenume);
            printf("\nStergerea a fost facuta cu succes!\n\n");

        }
        if(optiune==2){
            system(("cls"));
            printf("%s %s,Acestea sunt/etse conturile/contul dumneavoastra:\n",nume,prenume);
            printf("\n");
            afisare_date(nume,prenume);
            printf("\n");
        }
        if(optiune==3){
            system(("cls"));
            char *iban = (char*)malloc(33 * sizeof(char)),o[50];
            strcpy(o,nume);
            strcat(o," ");
            strcat(o,prenume);
            strcat(o,".txt");
            printf("Introduceti ibanul contului dumneavoastra:");

            scanf("%s",iban);
            while(cont_iban(o,iban)==0 || verif_iban(iban)==1)
            {
                printf("\n");
                printf("Ibanul a fost introdus gresit:");
                scanf("%s",iban);
            }

            printf("\n");

            int operatie;

            printf("1.Transfer Bancar!\n");
            printf("2.Retragere/Adaugare numerar!\n");
            printf("Alege operatia:");
            scanf("%i",&operatie);

            if(operatie==1)
            {
                printf("\n");
                tranzactii(nume,prenume,iban);
            }
            if(operatie==2)
            {
                adauga_bani(o,iban);
            }
            if(operatie>2)
            {
                printf("\nInput incorect!\n");
            }
            free(iban);
            printf("\n");
        }
        if(optiune==4){
            char *iban = (char*)malloc(33 * sizeof(char)),o[50];
            strcpy(o,nume);
            strcat(o," ");
            strcat(o,prenume);
            strcat(o,".txt");
            printf("Introduceti ibanul contului dumneavoastra:");

            scanf("%s",iban);
            while(cont_iban(o,iban)==0 && verif_iban(iban)==0)
            {
                printf("\n");
                printf("Ibanul a fost introdus gresit:");
                scanf("%s",iban);
            }

            printf("\n");

            edit(nume,prenume,iban);
        }
        if(optiune==5)
        {
            system(("cls"));
            adauga_cont(nume,prenume);
        }
        if(optiune==6){
            printf("\n");
            return ;

        }
        meniu();
        scanf("%d",&optiune);

    }
}