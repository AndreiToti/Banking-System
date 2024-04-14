void tranzactii(char *nume,char *prenume,char *iban)
{
    system("cls");
    char s[50],p[50],*nume_dest,*prenume_dest,*iban_dest,pers[100][100],dest[100][100],string[50];
    strcpy(s,nume);
    strcat(s," ");
    strcat(s,prenume);
    strcat(s,".txt");

    nume_dest=(char*)malloc(30*sizeof(char));
    prenume_dest=(char*)malloc(30*sizeof(char));
    iban_dest=(char*)malloc(33*sizeof(char));

    printf("Introduceti:\nNume destinatar:");
    scanf("%s",nume_dest);
    printf("Prenume destinatar:");
    scanf("%s",prenume_dest);



    while(login(nume_dest,prenume_dest)==0 || strcmp(nume,nume_dest)==0 || strcmp(prenume_dest,prenume)==0)
    {
        system("cls");
        printf("Acest cont nu este unul validt!\nIntroduceti un cont valid\n");
        printf("Introduceti:\nNume destinatar:");
        scanf("%s",nume_dest);
        printf("Prenume destinatar:");
        scanf("%s",prenume_dest);
    }

    printf("Ibanul destinatarului:");
    scanf("%s",iban_dest);


    strcpy(p,nume_dest);
    strcat(p," ");
    strcat(p,prenume_dest);
    strcat(p,".txt");

    while(verif_iban(iban_dest)==1 || cont_iban(p,iban_dest)==0)
    {
        system("cls");
        printf("Ibanul nu este valid!\nIntroduceti un iban valid:");
        scanf("%s",iban_dest);
    }


    FILE *dir= fopen(p,"r");
    FILE *trans= fopen(s,"r");

    int i=0;

    if(dir==NULL)
    {
        printf("Fisierul nu a putut fi accesat");
    }
    else
    {

        while(fgets(string,50,dir)!=NULL)
        {
            string[strlen(string)-1]='\0';
            strcpy(dest[i],string);
            i++;
        }
    }

    int j=0,l;

    if(trans==NULL)
    {
        printf("Fisierul nu a putut fi accesat");
    }
    else
    {

        while(fgets(string,50,trans)!=NULL)
        {
            string[strlen(string)-1]='\0';
            strcpy(pers[j],string);
            j++;
        }
    }

    fclose(trans);
    fclose(dir);

    //caut ibanul in matrice
    int index_pers=0,index_dest=0;

    for (l = 0; l < i; l++) {
        if(strstr(dest[l],iban_dest))
        {
            index_dest=l;
            break;
        }
    }

    for (l = 0; l < j; l++) {
        if(strstr(pers[l],iban))
        {
            index_pers=l;
            break;
        }
    }
    float suma,suma_dest,suma_pers;

    sscanf(dest[index_dest+2],"Balanta:%f",&suma_dest);
    sscanf(pers[index_pers+2],"Balanta:%f",&suma_pers);



    printf("Introduceti suma pe care vreti sa o transferati:");
    scanf("%f",&suma);
    if(strstr(pers[index_pers+1],"RON"))
    {

        if(strstr(dest[index_dest+1],"RON"))
        {
            if(suma_pers-suma<0)
            {
                printf("Fonduri insuficiente!");
                return ;
            }
            else
            {
                suma_pers=suma_pers-suma;
                suma_dest=suma_dest+suma;
            }
        }
        else if(strstr(dest[index_dest+1],"USD") || strstr(dest[index_dest+1],"EUR"))
        {
            if(suma_pers-suma<0)
            {
                printf("Fonduri insuficiente!");
                return ;
            }
            else
            {
                suma_pers=suma_pers-suma;
                suma=suma/5;
                suma_dest=suma_dest+suma;
            }

        }


    }
    else if((strstr(pers[index_pers+1],"USD")) || (strstr(pers[index_pers+1],"EUR")))
    {
        if((strstr(dest[index_dest+1],"USD")) || (strstr(dest[index_dest+1],"EUR")))
        {
            
            if(suma_pers-suma<0)
            {
                printf("Fonduri insuficiente!");
                return ;
            }
            else
            {
                suma_pers=suma_pers-suma;
                suma_dest=suma_dest+suma;
            }
        }
        else if(strstr(dest[index_dest+1],"RON"))
        {
            if(suma_pers-suma<0)
            {
                printf("Fonduri insuficiente!");
                return ;
            }
            else
            {
                suma_pers=suma_pers-suma;
                suma=suma*5;
                suma_dest=suma_dest+suma;
            }

        }

    }

    char linie_dest[20],linie_pers[20],char_pers[10],char_dest[10];

    strcpy(linie_pers,"Balanta:");
    sprintf(char_pers,"%.2f",suma_pers);
    strcat(linie_pers,char_pers);

    strcpy(linie_dest,"Balanta:");
    sprintf(char_dest,"%.2f",suma_dest);
    strcat(linie_dest,char_dest);

    strcpy(dest[index_dest+2],linie_dest);
    strcpy(pers[index_pers+2],linie_pers);

    FILE *inapoi_dest,*inapoi_pers;
    inapoi_dest= fopen(p,"w");
    inapoi_pers= fopen(s,"w");

    for (int k = 0; k < j; k++) {
        fprintf(inapoi_pers,"%s\n",pers[k]);
    }
    fclose(inapoi_pers);

    for (int k = 0; k < i; ++k) {
        fprintf(inapoi_dest,"%s\n",dest[k]);
    }
    fclose(inapoi_dest);
    free(iban_dest);
    free(nume_dest);
    free(prenume_dest);
    printf("\nTranzactia a avut loc cu succes!\n");

}