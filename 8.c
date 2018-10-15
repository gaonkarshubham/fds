/*************************************************************
ASSIGNMENT NO.: 8
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 
*************************************************************/
#include<stdio.h>
struct SPARSE
{
         int row;
         int col;
         int val;
};
typedef struct SPARSE spr;
void accept(int A[20][20],int *r,int*c)
{
       int i,j,x;
       printf("\nEnter no. of rows in the matrix:");
       scanf("%d",r);
       printf("\nenter no.of columns in the matrix:");
       scanf("%d",c);
       for(i=0;i<*r;i++)
         {
            for(j=0;j<*c;j++)
             {
                 printf("\nenter the value of %d %d\t",i,j);
                 scanf("%d",&x);
                 A[i][j]=x;
            }
       }
}
 void convert(int A[20][20],int r,int c,spr R[])
  {
        int k,i,j;
        k=1;
        for(i=0;i<r;i++)
          for(j=0;j<c;j++)
         {
             if(A[i][j]!=0)
               {
                    R[k].row=i;
                    R[k].col=j;
                    R[k].val=A[i][j];
                    k++;
               }
       }

       R[0].row=r;
       R[0].col=c;
       R[0].val=k-1;
}
  void display(spr S[])
   {
        int i;
        printf("\n\tRow\tColumn\tValue:");
        for(i=0;i<=S[0].val;i++)
          {
               printf("\n\t%d\t%d\t%d",S[i].row,S[i].col,S[i].val);
          }
   }

   void add(spr s1[],spr s2[],spr R[])
     {
     int i=1,j=1,k=1;
     if(s1[0].row==s2[0].row&&s1[0].col==s2[0].col)
      {
       while(i<=s1[0].val&& j<=s2[0].val)
        {
           if(s1[i].row<s2[j].row)
           {
                   R[k].row=s1[i].row;
                   R[k].col=s1[i].col;
                   R[k].val=s1[i].val;
                   k++;
                   i++;
           }
	else if(s1[i].row>s2[j].row)
          {
                   R[k].row=s2[j].row;
                   R[k].col=s2[j].col;
                   R[k].val=s2[j].val;
                   k++;
                   j++;
          }
	else if(s1[i].col<s2[j].col)
	  {
                   R[k].row=s1[i].row;
                   R[k].col=s1[i].col;
                   R[k].val=s1[i].val;
                   k++;
                   i++;
          }
	else if(s1[i].col>s2[j].col)
	  {
                   R[k].row=s2[j].row;
                   R[k].col=s2[j].col;
                   R[k].val=s2[j].val;
                   k++;
                   j++;
          }

	else
             {
                    R[k].row=s2[j].row;
                    R[k].col=s2[j].col;
                    R[k].val=s1[i].val+s2[j].val;
                    k++;
                    i++;
                    j++;
             }
 	}       
 
	while(i<=s1[0].val)
 	{
      		R[k].row=s1[i].row;
      		R[k].col=s1[i].col;
     		 R[k].val=s1[i].val;
      		k++;
     		 i++;
 	 }

	while(j<=s2[0].val)
 	{
      		R[k].row=s2[j].row;
      		R[k].col=s2[j].col;
      		R[k].val=s2[j].val;
      		k++;
      		j++;
  	}

      		R[0].row=s1[0].row;
      		R[0].col=s1[0].col;
      		R[0].val=k-1;
	}
}

 void simple_trans(spr s[],spr R[])
  {
      int i,j,k=1;
      R[0].row=s[0].col;
      R[0].col=s[0].row;
      R[0].val=s[0].val;
       for(i=0;i<s[0].col;i++)
        {
            for(j=1;j<=s[0].val;j++)
              {
                 if(i==s[j].col)
                   {
                        R[k].row=s[j].col;
                        R[k].col=s[j].row;
                        R[k].val=s[j].val;
                        k++;
                        }
                 }
            }
  }
void quick_trans(spr s[],spr R[])
   {
       int i;
       int count[20],pos[20];
       for(i=0;i<s[0].col;i++)
	{
	    count[i]=0;
    }
	for(i=0;i<=s[0].val;i++)
	 {
	     count[s[i].col]++;
	 }
	  pos[0]=1;
	  for(i=1;i<s[0].col;i++)
           {
              pos[i]=count[i-1]+pos[i-1];
           }
           for(i=1;i<=s[0].val;i++)
            {

                 R[pos[s[i].col]].row=s[i].col;
		 R[pos[s[i].col]].col=s[i].row;
		 R[pos[s[i].col]].val=s[i].val;
		 pos[s[i].col]++;
            }
        }
 void main()
 {
 int ch;
 int A[20][20],r1,c1,r2,c2;
 spr s1[20],s2[20],r[20];
 do
  {
   printf("\n\tchoice 1:Accept the matrix:");
   printf("\n\tchoice 2:display the matrix:");
   printf("\n\tchoice 3:addition of sparse matrix:");
   printf("\n\tchoice 4:Simple transpose of matrix:");
   printf("\n\tchoice 5:Quick transpose of matrix:");
   printf("\n\tchoice 6:End");
   printf("\n\tEnter ur Choice :");
   scanf("%d",&ch);
   switch(ch)
    {
       case 1:accept(A,&r1,&c1);
              convert(A,r1,c1,s1);
              break;
       case 2:display(s1);
              break;
       case 3:printf("enter the details of second matrix:");
              accept(A,&r2,&c2);
              convert(A,r2,c2,s2);
              add(s1,s2,r);
              display(r);
              break;
       case 4:simple_trans(s1,r);
              display(r);
              break;
       case 5:quick_trans(s1,r);
              display(r);
              break;
       case 6:printf("\nEnd");
		      break;
	 default: printf("\nyou have given an incorrect choice !!!");
      }
   }while(ch!=6);
}

/* Output:

	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :1

Enter no. of rows in the matrix:3

enter no.of columns in the matrix:3

enter the value of 0 0	0

enter the value of 0 1	0

enter the value of 0 2	12

enter the value of 1 0	0

enter the value of 1 1	0

enter the value of 1 2	13

enter the value of 2 0	14

enter the value of 2 1	0

enter the value of 2 2	0

	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :2

	Row	Column	Value:
	3	3	3
	0	2	12
	1	2	13
	2	0	14
	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :3
enter the details of second matrix:
Enter no. of rows in the matrix:3

enter no.of columns in the matrix:3

enter the value of 0 0	0

enter the value of 0 1	0

enter the value of 0 2	21

enter the value of 1 0	0

enter the value of 1 1	22

enter the value of 1 2	0

enter the value of 2 0	23

enter the value of 2 1	0

enter the value of 2 2	0

	Row	Column	Value:
	3	3	4
	0	2	33
	1	1	22
	1	2	13
	2	0	37
	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :4

	Row	Column	Value:
	3	3	3
	0	2	14
	2	0	12
	2	1	13
	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :5

	Row	Column	Value:
	3	3	3
	0	2	14
	2	0	12
	2	1	13
	choice 1:Accept the matrix:
	choice 2:display the matrix:
	choice 3:addition of sparse matrix:
	choice 4:Simple transpose of matrix:
	choice 5:Quick transpose of matrix:
	choice 6:End
	Enter ur Choice :6

*/


