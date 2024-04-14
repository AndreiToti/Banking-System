void regis() {

    char *nume = malloc(20 * sizeof(char));
    char *prenume = malloc(20 * sizeof(char));
    char *iban = (char*)malloc(33 * sizeof(char));
    char *moneda = malloc(4 * sizeof(char));
    char *balanta = malloc(4 * sizeof(char));

    printf("Nume:");
    scanf("%s", nume);

    while(nume[0]<'A' || nume[0]>'Z')
    {
        printf("\nNumele trebuie sa fie cu litera mare!\nIntroduceti un nume valid:");
        scanf("%s", nume);
    }
    printf("Prenume:");
    scanf("%s", prenume);

    while(prenume[0]<'A' || prenume[0]>'Z')
    {
        printf("\nPrenumele trebuie sa fie cu litera mare!\nIntroduceti un nume valid:");
        scanf("%s", prenume);
    }

    if(login(nume,prenume)==1)
    {
        system("cls");
        printf("Ati introdus un nume cu un cont existent!\nIntroduceti un nume de utilizator valid:\n\n");
        regis();
        return ;
    }
    printf("Iban:");
    scanf("%s", iban);

    while(verif_iban(iban)==0)
    {
        printf("\nIbanul nu este valid!\nInserati un iban valid:");
        scanf("%s", iban);
    }

    inserare_iban(iban);

    printf("Moneda:");
    scanf("%s", moneda);

    while((!(strstr("RONUSDEUR",moneda))) || strlen(moneda)!=3 )
    {
        system("cls");
        printf("Moneda a fost introdusa gresit!\nIntroduceti o moneda valida:");
        scanf("%s", moneda);
    }
    printf("Balanta:");
    scanf("%s", balanta);

    char s[50];
    strcpy(s,nume);
    strcat(s," ");
    strcat(s,prenume);
    strcat(s,".txt");

    FILE *f;
    f= fopen(s, "a");

    if (f == NULL) {
        printf("Fisierul nu poate fi accesat.");
    } else {
        fprintf(f, "Iban:%s\nMoneda:%s\nBalanta:%s\n",iban, moneda,balanta);
        fclose(f);
    }


    free(nume);
    free(prenume);
    free(iban);
    free(moneda);
    free(balanta);
}
