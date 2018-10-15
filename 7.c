/**************************************************************
ASSIGNMENT NO.: 7
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

**************************************************************/
#include<stdio.h>
#define MAX 30

int pass=1;
int accept_array(int a[])
{
    int i,n;
    printf("enter the length of the array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the %d element:",i+1);
        scanf("%d",&a[i]);
    }return(n);
}
void display_array(int a[],int s,int l)
{
   int i;
   for(i=s;i<l;i++)
   {
      printf("\t%d",a[i]);
   }
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int A[],int s,int l)
{
	int b,e;
	b=s+1;
	e=l;
	while(b<=e)
	{
		while(A[b] <= A[s] && b<=l)
		   b++;
		while(A[e]>A[s])
		  e--;
	if(b<e)
	  swap(&A[b],&A[e]);
	}
   swap(&A[s],&A[e]);
  return(e);
}

void quicksort(int A[],int s,int l)
{
    int p;
    if(s<l)
    {
	printf("\n Pass : %d",pass);
	p=partition(A,s,l);
	printf("\n Output Array is:\n");
	display_array(A,s,l);
	pass++;
	quicksort(A,s,p-1);
	quicksort(A,p+1,l);
    }

}

void main()
{
  int ch;
  int A[30],na=0;
  do
  {
     printf("\n\t\tChoice 1 : Accept");
     printf("\n\t\tChoice 2 : Display");
     printf("\n\t\tChoice 3 : Result");
     printf("\n\t\tChoice 4 : Exit");
     printf("\n\nEnter ur Choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 :  na=accept_array(A);
		  break;
	case 2 :  display_array(A,0,na);
		  break;
	case 3 :  pass=1;
		  printf("\n\n Before sorting :");
		  display_array(A,0,na);
		  quicksort(A,0,na-1);
		  printf("\n\n After sorting:  ");
		  display_array(A,0,na);
		  break;

	case 4 :  printf("\n\n Good Bye! End of the program.");
		  break;
    default:  printf("\nGive a correct choice!!");
     }
  }while(ch!= 4);
}

/*Output:
		Choice 1 : Accept
		Choice 2 : Display
		Choice 3 : Result
		Choice 4 : Exit

Enter ur Choice : 1
enter the length of the array5
enter the 1 element:10
enter the 2 element:20
enter the 3 element:40
enter the 4 element:35
enter the 5 element:25

		Choice 1 : Accept
		Choice 2 : Display
		Choice 3 : Result
		Choice 4 : Exit

Enter ur Choice : 2
	10	20	40	35	25
		Choice 1 : Accept
		Choice 2 : Display
		Choice 3 : Result
		Choice 4 : Exit

Enter ur Choice : 3


 Before sorting :	10	20	40	35	25
 Pass : 1
 Output Array is:
	10	20	40	35
 Pass : 2
 Output Array is:
	20	40	35
 Pass : 3
 Output Array is:
	25	35
 Pass : 4
 Output Array is:
	25

 After sorting:  	10	20	25	35	40
		Choice 1 : Accept
		Choice 2 : Display
		Choice 3 : Result
		Choice 4 : Exit

Enter ur Choice : 4


 Good Bye! End of the program
*/
