/*************************************************************
ASSIGNMENT NO.: 4
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

*************************************************************/

#include<stdio.h>
#define MAX 30

struct student
{
   int roll;
   char name[20];
   int marks;
};
typedef struct student stud;

int create_database(stud A[])
{
   int i,n;
   printf("\nEnter the no. of records : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter details of %d record (roll,name,marks): ",i+1);
      scanf("%d%s%d",&A[i].roll,A[i].name,&A[i].marks);
   }
    return(n);
}

void display_database(stud A[],int n)
{
   int i;
   printf("\nTotal no. of records :  %d",n);
   for(i=0;i<n;i++)
   {
      printf("\n\nRecord %d Details ==> %d\t%s\t%d ",i,A[i].roll,A[i].name,A[i].marks);
   }
}

int search(stud A[],int n,int key)
{
   int i;
   for(i=0;i<n;i++)
   {
      if(A[i].roll==key)
	return(i);
   }
   return(-1);
}
void search_database(stud A[],int n)
{
    int key,f;
    printf("\nEnter the roll to be searched : ");
    scanf("%d",&key);
    f = search(A,n,key);
    if(f==-1)
       printf("\n%d roll to be searched is not present in the database",key);
    else
    {
       printf("\n%d roll found at %d location ",key,f+1);
       printf("\nDetails of the record are : ");
       printf("\n\tRoll No = %d",A[f].roll);
       printf("\n\tName = %s",A[f].name);
       printf("\n\tMarks= %d",A[f].marks);
    }
}

void modify_database(stud A[],int n)
{
    int key,f;
    printf("\nEnter the roll to be modified : ");
    scanf("%d",&key);
    f=search(A,n,key);
    if(f==-1)
       printf("\n%d roll to be modified is not present in the database",key);
    else
    {
       printf("\n%d roll found at %d location ",key,f+1);
       printf("\nEnter new details (roll, name, marks) for modification : ");
       scanf("%d%s%d",&A[f].roll,A[f].name,&A[f].marks);
       printf("\n\nRecord modified successfully");
    }
}

void delete_database(stud A[],int *n)
{
    int key,f,i;
    printf("\nEnter the roll to be deleted :");
    scanf("%d",&key);
    f = search(A,*n,key);
    if(f == -1)
       printf("\n%d roll to be deleted is not present in the database",key);
    else
    {
       printf("\n%d roll found at %d location ",key,f+1);
       for(i=f;i<= *n-2;i++)
       {
	  A[i] = A[i+1];
       }
       *n = *n - 1;
       printf("\n\nRecord deleted successfully");
    }
}

int insert_database(stud A[],int n)
{
   int pos,i;
   stud B;
   if(n==MAX)
     printf("\nDatabase is full");
   else
   {
     printf("\nEnter the position where to insert(1 to %d):",n+1);
     scanf("%d",&pos);
     printf("\nEnter the record to be inserted(roll, name, marks):");
     scanf("%d%s%d",&B.roll,B.name,&B.marks);

     for(i=n;i>=pos;i--)
     {
	A[i]=A[i-1];
     }
     A[pos-1]=B;
     n=n+1;
     printf("\n\nRecord inserted successfully");
   }
   return(n);
}


int main()
{
   int ch;
   stud A[MAX];
   int na=0;

   do
   {

      printf("\n\t\tChoice 1 : Create");
      printf("\n\t\tChoice 2 : Display");
      printf("\n\t\tChoice 3 : Search");
      printf("\n\t\tChoice 4 : Modify");
      printf("\n\t\tChoice 5 : Delete");
      printf("\n\t\tChoice 6 : Insert");
      printf("\n\t\tChoice 7 : Exit");
      printf("\n\nEnter ur Choice :");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1 :  na=create_database(A);
		   break;
	 case 2 :  display_database(A,na);
		   break;
	 case 3 :  search_database(A,na);
		   break;
	 case 4 :  modify_database(A,na);
		   break;
	 case 5 :  delete_database(A,&na);
		   break;
	 case 6 :  na = insert_database(A,na);
		   break;
	 case 7 :  printf("\nEnd");
		   break;
	 default:  printf("\nyou have given an incorrect choice !!!");
      }

   }while(ch!=7);
}

/*Output:
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :1

Enter the no. of records : 3

Enter details of 1 record (roll,name,marks): 1 sachin 45

Enter details of 2 record (roll,name,marks): 2 rahul 56

Enter details of 3 record (roll,name,marks): 3 satish 67

		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :2

Total no. of records :  3

Record 0 Details ==> 1	sachin	45 

Record 1 Details ==> 2	rahul	56 

Record 2 Details ==> 3	satish	67 
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :3

Enter the roll to be searched : 2

2 roll found at 2 location 
Details of the record are : 
	Roll No = 2
	Name = rahul
	Marks= 56
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :6

Enter the position where to insert(1 to 4):4

Enter the record to be inserted(roll, name, marks):4 ramesh 65


Record inserted successfully
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :2

Total no. of records :  4

Record 0 Details ==> 1	sachin	45 

Record 1 Details ==> 2	rahul	56 

Record 2 Details ==> 3	satish	67 

Record 3 Details ==> 4	ramesh	65 
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Exit

Enter ur Choice :7

*/
