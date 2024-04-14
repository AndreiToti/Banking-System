void edit(char *nume,char *prenume,char* iban){

    FILE *p;
    char mat[100][100],*string=(char*) malloc(33*sizeof (char)),path[50];
    strcpy(path,nume);
    strcat(path," ");
    strcat(path,prenume);
    strcat(path,".txt");
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

    float bani;
    sscanf(mat[index+2],"Balanta:%f",&bani);

    printf("1.Modoficare RON\n");
    printf("2.Modoficare USD\n");
    printf("3.Modoficare EUR\n");
    printf("-Alege operatia:");

    int operatie;
    scanf("%i",&operatie);

    if(operatie==1)
    {
        if((strstr(mat[index+1],"USD")) || (strstr(mat[index+1],"EUR")))
        {
            bani=bani*5;
            strcpy(mat[index+1],"Moneda:RON");

            char sir[40],aux[10];
            strcpy(sir,"Balanta:");
            sprintf(aux,"%.2f",bani);
            strcat(sir,aux);
            strcpy(mat[index+2],sir);
        }
    }

    if(operatie==2)
    {
        if(strstr(mat[index+1],"RON"))
        {
            strcpy(mat[index+1],"Moneda:USD");
            bani=bani/5;
            char sir[40],aux[10];
            strcpy(sir,"Balanta:");
            sprintf(aux,"%.2f",bani);
            strcat(sir,aux);
            strcpy(mat[index+2],sir);
        }
        else if(strstr(mat[index+1],"EUR"))
        {
            strcpy(mat[index+1],"Moneda:USD");
        }
    }
    if(operatie==3)
    {
        if(strstr(mat[index+1],"RON"))
        {
            strcpy(mat[index+1],"Moneda:EUR");
            bani=bani/5;
            char sir[40],aux[10];
            strcpy(sir,"Balanta:");
            sprintf(aux,"%.2f",bani);
            strcat(sir,aux);
            strcpy(mat[index+2],sir);
        }
        else if(strstr(mat[index+1],"USD"))
        {
            strcpy(mat[index+1],"Moneda:EUR");
        }

    }
    if(operatie>3)
    {
        printf("\nInput incorect!\n");
        return ;
    }

    FILE *ac;
    ac= fopen(path,"w");

    for (int k = 0; k < i; k++) {
        fprintf(ac,"%s\n",mat[k]);
    }

    fclose(ac);

    printf("\nEditarea contului a fost facuta cu succes\n");
}