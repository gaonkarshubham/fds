/*************************************************************
ASSIGNMENT NO.: 2
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

*************************************************************/

#include<stdio.h>

void accept(int A[10][10],int *r,int *c)
{
	int i,j;
	printf("\n  enter row n col (r,c)");
	scanf("%d%d",r,c);
	for (i=0;i<*r;i++)
	{
		for (j=0;j<*c;j++)
		{
			printf("\n enter %d,%d element",i,j);
			scanf("%d",&A[i][j]);
		}
	}
}

void display(int A[10][10],int *r,int *c,char x)
{
	int i,j;
	printf("\n\n\t:: matrix %c of order(%d,%d):: \n",x,*r,*c);

    for(i=0;i<*r;i++)
	{   printf("\n\t\t");
		for (j=0;j<*c;j++)
		{
          printf(" %d ",A[i][j]);
		}
	}
}

void addition(int A[10][10],int B[10][10],int C[10][10],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			C[i][j]=A[i][j]+B[i][j];

		}
	}
}

void multiplication(int C[10][10],int A[10][10],int B[10][10],int r,int c,int p)
{
	int i,j,k ;
	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
		    C[i][j]=0;
			for (k=0;k<p;k++)
			{
				C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
			}

		}
	}
}
int max(int A[10][10],int i,int c)
{
	int max1,j;
	max1=A[i][0];
	for (j=0;j<c;j++)
	{ 
	      if(A[i][j]>max1)
		max1=A[i][j];
	}
	return(max1);
}
int min(int A[10][10],int i,int r)
{
	int min1,j;
	min1=A[0][i];
	for (j=0;j<r;j++)
	{
	      if(A[j][i]<min1)
		min1=A[j][i];
	}
	return(min1);
}
void saddle_point(int A[10][10],int r,int c)
{
	int i,j,MAX[10],MIN[10],temp1,temp2;
	for(i=0;i<r;i++)
	{
		MAX[i]=max(A,i,c);
	}
	for(j=0;j<c;j++)
	{
		MIN[j]=min(A,j,r); 
	}
	temp1=MAX[0];
	temp2=MIN[0];
	for(i=0;i<r;i++)
	{
		if (MAX[i] < temp1)
			temp1=MAX[i];
		if (MIN[i] > temp2)
			temp2=MIN[i];
	}
	if (temp1==temp2)
		printf("\n Matrix has a saddle point");
	else
		printf("\n Matrix has no saddle point");
}
void main()
{
	int A1[10][10],r1,c1,A2[10][10],r2,c2,A3[10][10],r3,c3,ch;

 do
 {

    printf("\n\t choice 1: accept");
    printf("\n\t choice 2: display");
    printf("\n\t choice 3: addition");
    printf("\n\t choice 4: multiplication");
    printf("\n\t choice 5: saddle point");
    printf("\n\t choice 6: exit");
    printf("\nEnter ur choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1 :  accept(A1,&r1,&c1);
		 accept(A2,&r2,&c2);
		 break;
       case 2 :  display(A1,&r1,&c1,'A');
		 printf("\n");
		 display(A2,&r2,&c2,'B');
		 break;

       case 3 :  if(r1==r2&&c1==c2)
		 {
			r3=r1;
			c3=c1;
			addition(A1,A2,A3,r1,c1);
			display(A3,&r3,&c3,'C');
		 }
		 else
		 {
			printf("\n addition is not possible");
		 }
		 break;
       case 4 :	if(c1==r2)
		{
			multiplication(A3,A1,A2,r1,c2,c1);
			r3=r1;
			c3=c2;
			display(A3,&r3,&c3,'C');
		}
		else
		{
		    printf("\n multiplication is not possible");
		}
		      break;
       case 5:saddle_point(A1,r1,c1);
		      break;
       case 6:printf("\nEnd");
		      break;
	 default: printf("\nyou have given an incorrect choice !!!");
      }
   }while(ch!=6);
}

/*Output:
	 choice 1: accept
	 choice 2: display
	 choice 3: addition
	 choice 4: multiplication
	 choice 5: saddle point
	 choice 6: exit
Enter ur choice : 1

  enter row n col (r,c)3 3       

 enter 0,0 element3

 enter 0,1 element4

 enter 0,2 element5

 enter 1,0 element6

 enter 1,1 element7

 enter 1,2 element8

 enter 2,0 element9

 enter 2,1 element10

 enter 2,2 element11

  enter row n col (r,c)3 3

 enter 0,0 element2

 enter 0,1 element3

 enter 0,2 element4

 enter 1,0 element5

 enter 1,1 element6

 enter 1,2 element7

 enter 2,0 element8

 enter 2,1 element9

 enter 2,2 element10

	 choice 1: accept
	 choice 2: display
	 choice 3: addition
	 choice 4: multiplication
	 choice 5: saddle point
	 choice 6: exit
Enter ur choice : 2


	:: matrix A of order(3,3):: 

		 3  4  5 
		 6  7  8 
		 9  10  11 


	:: matrix B of order(3,3):: 

		 2  3  4 
		 5  6  7 
		 8  9  10 
	 choice 1: accept
	 choice 2: display
	 choice 3: addition
	 choice 4: multiplication
	 choice 5: saddle point
	 choice 6: exit
Enter ur choice : 3


	:: matrix C of order(3,3):: 

		 5  7  9 
		 11  13  15 
		 17  19  21 
	 choice 1: accept
	 choice 2: display
	 choice 3: addition
	 choice 4: multiplication
	 choice 5: saddle point
	 choice 6: exit
Enter ur choice : 5

 Matrix has a saddle point
	 choice 1: accept
	 choice 2: display
	 choice 3: addition
	 choice 4: multiplication
	 choice 5: saddle point
	 choice 6: exit
Enter ur choice : 6
*/










