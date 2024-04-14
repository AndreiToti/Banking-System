int verif_iban(char *iban)
{

    FILE *g;
    g=fopen("Ibanuri.txt","r");

    char *string=(char*) malloc(33*sizeof (char));

    if(g==NULL)
    {
        printf("Fisierul nu a putut fi accesat!");
    }
    else{
        while(fgets(string,33*sizeof(char),g)!=NULL)
        {
            string[strlen(string)-1]='\0';
            if(strcmp(string,iban)==0)
            {
                free(string);
                fclose(g);
                return 0;
            }
        }

    }
    free(string);
    fclose(g);
    return 1;
}
void inserare_iban(char *iban){
    FILE *q;
    q= fopen("Ibanuri.txt","a");
    if (q== NULL) {
        printf("Fisierul nu poate fi accesat.");
        fclose(q);
    } else {
        fprintf(q, "%s\n", iban);
        fclose(q);
    }
}

void adauga_cont(char *nume,char *prenume)
{
    char *iban = (char*)malloc(33 * sizeof(char));
    char *moneda =(char*) malloc(4 * sizeof(char));
    char *balanta =(char*) malloc(4 * sizeof(char));
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

    free(iban);
    free(moneda);
    free(balanta);
}

int cont_iban(char s[],char *iban)
{

    FILE *p;
    p= fopen(s,"r");
    if(p==NULL)
    {
        printf("Fisierul nu a putut fi accesat");
    }
    else
    {

        char *string= (char*) malloc(50*sizeof(char));
        while(fgets(string,50,p)!=NULL)
        {
            string[strlen(string)-1]='\0';
            if(strstr(string,iban))
                return 1;
        }
    }
    fclose(p);
    return 0;
}