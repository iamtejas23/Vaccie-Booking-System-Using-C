#include <stdio.h>
typedef struct
{
    int mob;
    char name[25], ph_id[20];
    int age,id_no;
}STD;
STD s;
void display(FILE *);
int search(FILE *,int);
void main()
{
    int i,n,mob_key,opn;

    FILE *fp;
    clrscr();
    printf(" How Many Registretions You Want? ");
    scanf("%d",&n);
    fp=fopen("stud.dat","w");
    for(i=0;i<n;i++)
    {
    printf("Fill Info For Vaccine Registretion: %d (Mobile No.,Name,Age,Photo ID,ID NO.) \n",i+1);
    scanf("%d%s%d%s%d",&s.mob,s.name,&s.age,&s.ph_id,&s.id_no);
    fwrite(&s,sizeof(s),1,fp);
    }
    fclose(fp);
    fp=fopen("stud.dat","r");
    do
    {
    printf("\nPress :: \n 1- Display\n 2- Search\n 3- Exit\n Your Option ? ");
    scanf("%d",&opn);
    switch(opn)
    {
    case 1: printf("\n Member Details: \n");
        display(fp);
        break;
    case 2:
    printf("\nPress 1- Center A");
    printf("\n\t                                             Covishield");
    printf("\n\t200 Slots     18+                               Free");
    printf("\n");
    printf("\n");

    printf("\nPress 2- Center B");
    printf("\n\t                                              Covishield");
    printf("\n\t200 Slots     18+                                Free");
    printf("\n");
    printf("\n");

    printf("Choose Center:");
    scanf("%d",&opn);


     printf("\nEnter Mobile No :");

        scanf("%d",&mob_key);
        if(search(fp,mob_key))
        {
    printf("\t___________________Congratulations!___________________\n");
    printf("\t-----------------Your Vaccine Booked.----------------\n");
    printf("\t============================================================\n");
    printf("\tMobile No:%d\t%d\n",s.mob,s.id_no);
    printf("\t  \t\t\tVaccine Dose : Covaxin\n");
    printf("\t Customer:%s\n",s.name);
    printf("\t\t\t                              Date      : 4-08-2020\n");
    printf("\t                                              Time      : 09:00pm\n");
    printf("\t                                              Age      : %d\n",s.age);
    printf("\t                                              Document To Carry. :%s\n",s.ph_id);
    printf("\t                                              price . :Free\n\n");

        }
        else
        printf(" Failure!! Record with id %d not found\n",mob_key);
        break;
    case 3:  printf(" Exit!! Press a key . . .");
        getch();
        break;
    default:  printf(" Invalid Option!!!! Try again !!!\n");
        break;
    }
    }while(opn != 3);
    fclose(fp);
}
   /* End of main() */

void display(FILE *fp)
{
    rewind(fp);
    printf("Mobile No.\tName\tAge\tPhoto ID\tID No.\n");
    while(fread(&s,sizeof(s),1,fp))

    printf("%d\t%s\t%d\t%s\t%d\n",s.mob,s.name,s.age,s.ph_id,s.id_no);
}
int search(FILE *fp, int mob_key)
{
    rewind(fp);
    while(fread(&s,sizeof(s),1,fp))
    if( s.mob == mob_key) return 1;
    getch();
    return 0;
}
