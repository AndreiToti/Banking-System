void adauga_bani(char path[],char *iban)
{
    FILE *p;
    char mat[100][100],*string=(char*) malloc(33*sizeof (char));
    p= fopen(path,"r");

    int i=0;

    if(p==NULL)
    {
        printf("Fisierul nu a putut fi accesat");
    }
    else
    {

        while(fgets(string,50,p)!=NULL)
        {
            string[strlen(string)-1]='\0';
            strcpy(mat[i],string);
            i++;
        }
    }

    fclose(p);
    int index=0;
    for (int j = 0; j < i; j++) {
        if(strstr(mat[j],iban))
            index=j;

    }

    float suma,suma_actuala;
    sscanf(mat[index+2],"Balanta:%f",&suma_actuala);

    printf("\n");
    printf("1.Retragere numerar!\n");
    printf("2.Adaugare numerar!\n");
    printf("Alegeti operatie:");

    int optiune;

    scanf("%i",&optiune);
    printf("\n");


    if(optiune==1)
    {
        printf("\n");
        printf("Alegeti suma pe care vreti sa o retrageti:");
        scanf("%f",&suma);

        if(suma_actuala-suma<0)
        {
            printf("\nFonduri insuficiente!\n");
            return ;
        }
        else
        {
            suma_actuala=suma_actuala-suma;
        }

    }
    else if (optiune==2)
    {
        printf("\n");
        printf("Alegeti suma pe care vreti sa o adaugati:");
        scanf("%f",&suma);

        suma_actuala=suma_actuala+suma;
    }

    char aux[10];
    strcpy(string,"Balanta:");
    sprintf(aux,"%.2f",suma_actuala);
    strcat(string,aux);
    strcpy(mat[index+2],string);

    free(string);

    FILE *ac;
    ac= fopen(path,"w");

    for (int j = 0; j < i; j++) {
        fprintf(ac,"%s\n",mat[j]);

    }
    fclose(ac);
    printf("\nTranzactia a avut loc cu succes!\n");
}
