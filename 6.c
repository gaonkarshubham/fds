/*************************************************************
ASSIGNMENT NO.: 6
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 
*************************************************************/

#include <stdio.h>
typedef struct
{
    int usn;
    char name[25];
    int m1,m2,m3;
}STD;
STD s;
void display(FILE *);
int search(FILE *,int);
void main()
{
    int i,n,usn_key,opn;
    FILE *fp;
    printf(" How many Records ? ");
    scanf("%d",&n);
    fp=fopen("stud.dat","w");
    for(i=0;i<n;i++)
    {
        printf("Read the Info for Student: %d (usn,name,m1,m2,m3) \n",i+1);
        scanf("%d%s%d%d%d",&s.usn,s.name,&s.m1,&s.m2,&s.m3);
        fwrite(&s,sizeof(s),1,fp);
    }
    fclose(fp);
    fp=fopen("stud.dat","r");
    do
    {
        printf("Press 1- Display\t 2- Search\t 3- Exit\t Your Option?");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1: printf("\n Student Records in the File \n");
            display(fp);
            break;
        case 2: printf(" Read the USN of the student to be searched ?");
            scanf("%d",&usn_key);
            if(search(fp,usn_key))
            {
                printf("Success ! Record found in the file\n");
                printf("%d\t%s\t%d\t%d\t%d\n",s.usn,s.name,s.m1,s.m2,s.m3);
            }
            else
                printf(" Failure!! Record with USN %d not found\n",usn_key);
            break;
        case 3:  printf(" Exit!! Press a key . . .");
            break;
        default:  printf(" Invalid Option!!! Try again !!!\n");
            break;
        }
    }while(opn != 3);
    fclose(fp);
}   /* End of main() */
void display(FILE *fp)
{
    rewind(fp);
    while(fread(&s,sizeof(s),1,fp))
        printf("%d\t%s\t%d\t%d\t%d\n",s.usn,s.name,s.m1,s.m2,s.m3);
}
int search(FILE *fp, int usn_key)
{
    rewind(fp);
    while(fread(&s,sizeof(s),1,fp))
        if( s.usn == usn_key) return 1;
    return 0;
}

/*Output:
 How many Records ? 4
Read the Info for Student: 1 (usn,name,m1,m2,m3) 
1 asdf 12 13 14
Read the Info for Student: 2 (usn,name,m1,m2,m3) 
2 wert 23 24 25
Read the Info for Student: 3 (usn,name,m1,m2,m3) 
3 tyui 34 35 36
Read the Info for Student: 4 (usn,name,m1,m2,m3) 
4 vbmn 45 46 47
Press 1- Display	 2- Search	 3- Exit	 Your Option?1

 Student Records in the File 
1	asdf	12	13	14
2	wert	23	24	25
3	tyui	34	35	36
4	vbmn	45	46	47
Press 1- Display	 2- Search	 3- Exit	 Your Option?2
 Read the USN of the student to be searched ?3
Success ! Record found in the file
3	tyui	34	35	36
Press 1- Display	 2- Search	 3- Exit	 Your Option?2
 Read the USN of the student to be searched ?5
 Failure!! Record with USN 5 not found
Press 1- Display	 2- Search	 3- Exit	 Your Option?3
 Exit!! Press a key . . .
*/
