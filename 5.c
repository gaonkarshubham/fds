/*************************************************************
ASSIGNMENT NO.: 5
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

*************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX 30

int accept_array(char A[][20])
{
    int i,n;
    printf("enter the number of strings ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter string: %d",i+1);
        scanf("%s",A[i]);
    }return(n);
}
 void display_array(char A[][20],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("\nthe strings are ==> \t%s",A[i]);
   }
}

void bubble_sort(char A[][20],int n)
{ int pass,i;
   char temp[20];
    for(pass=1;pass<n;pass++)
    {
        for(i=0;i<(n-pass);i++)
        {
            if(strcmp(A[i],A[i+1])>0)
            {  strcpy(temp,A[i]);
	       strcpy(A[i],A[i+1]);
		strcpy(A[i+1],temp);
            }
        }
	printf("\n After Pass %d :",pass);
	display_array(A,n);
    }
printf("\n the sorted array is :");	
display_array(A,n);
}


void selection_sort(char A[][20],int n)
{  int i, j, k;
   char temp[20];
    for (i = 0; i < n-1; i++)
    {
	 k = i;
        for (j = i+1; j < n; j++)
         { if (strcmp(A[j],A[k])>0)
            {	k = j;
        	strcpy(temp,A[i]);
		strcpy(A[i],A[k]);
		strcpy(A[k],temp);
            }
        }printf("\n After Pass %d :",i+1);
	display_array(A,n);
     }
printf("\n the sorted array is :");	
display_array(A,n);
}

int main()
{
   int  ch,key;
   char A[MAX][20];
   int na=0;

   do
   {
      printf("\n\t\t 1 : Create");
      printf("\n\t\t 2 : Display");
      printf("\n\t\t 3 : bubble sort");
      printf("\n\t\t 4 : Selection sort");
      printf("\n\t\t 5 : Exit");
      printf("\n\nEnter ur Choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1 :  na = accept_array(A);
		       break;
	 case 2 :  display_array(A,na);
		       break;
     case 3:
     bubble_sort(A,na);
     break;
     case 4:
     selection_sort(A,na);
     break;
	case 5 :  printf("\nEnd");
		   break;
	default:  printf("\nGive a correct choice!!");
      }
   
   }while(ch!=5);
}

/*Output:
		 1 : Create
		 2 : Display
		 3 : bubble sort
		 4 : Selection sort
		 5 : Exit

Enter ur Choice : 1
enter the number of strings 3
enter string: 1ramesh
enter string: 2suresh
enter string: 3anurag

		 1 : Create
		 2 : Display
		 3 : bubble sort
		 4 : Selection sort
		 5 : Exit

Enter ur Choice : 2

the strings are ==> 	ramesh
the strings are ==> 	suresh
the strings are ==> 	anurag
		 1 : Create
		 2 : Display
		 3 : bubble sort
		 4 : Selection sort
		 5 : Exit

Enter ur Choice : 3

 After Pass 1 :
the strings are ==> 	ramesh
the strings are ==> 	anurag
the strings are ==> 	suresh
 After Pass 2 :
the strings are ==> 	anurag
the strings are ==> 	ramesh
the strings are ==> 	suresh
 the sorted array is :
the strings are ==> 	anurag
the strings are ==> 	ramesh
the strings are ==> 	suresh
		 1 : Create
		 2 : Display
		 3 : bubble sort
		 4 : Selection sort
		 5 : Exit

Enter ur Choice : 4

 After Pass 1 :
the strings are ==> 	suresh
the strings are ==> 	anurag
the strings are ==> 	ramesh
 After Pass 2 :
the strings are ==> 	suresh
the strings are ==> 	ramesh
the strings are ==> 	anurag
 the sorted array is :
the strings are ==> 	suresh
the strings are ==> 	ramesh
the strings are ==> 	anurag
		 1 : Create
		 2 : Display
		 3 : bubble sort
		 4 : Selection sort
		 5 : Exit

Enter ur Choice : 5

*/
