void afisare_date(char *nume,char *prenume)
{
    FILE *p;
    char s[40];
    strcpy(s,nume);
    strcat(s," ");
    strcat(s,prenume);
    strcat(s,".txt");

    p=fopen(s,"r");
    char string[100];
    int nr=3,i=1;
    printf("Contul %i",i);
    printf("\n");
    while(fgets(string,sizeof(string),p)!=NULL)
    {
        if(nr==0)
        {
            printf("\n");
            i++;
            printf("Contul %i",i);
            printf("\n");
            nr=3;

        }
        printf("%s",string);
        nr--;
    }
    fclose(p);

}
int admin(char *password)
{
    if(strcmp(password,"totobank")==0)
        return 1;
    else return 0;
}