/*************************************************************
ASSIGNMENT NO.: 1
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

*************************************************************/
#include<stdio.h>

int accept_array(int a[],char str[])
{
    int n,i;
    printf("enter the number of elements of set %s\n",str);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the element %d :",i+1);
        scanf("%d",&a[i]);
    }
    return(n);
}
int display_array(int A[],int n,char str[])
{
    int i;
    {
        printf("\n%s={",str);
        for(i=0;i<n;i++)
        {
            printf("%d,",A[i]);

        }
            printf("\b}");

    }
    return(n);
}


array_intersection(int a[],int na,int b[],int nb,int c[])
{
    int i,j,nc=0;
    for(i=0;i<na;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(a[i]==b[j])
            {
                c[nc]=a[i];
                nc=nc+1;
            }
        }
    }
    return(nc);
}
int search(int a[],int na,int e)
{
    int i;
    for(i=0;i<na;i++)
    {
        if(a[i]==e)
        return 1;
    }return 0;
}
array_subtraction(int a[],int na,int b[],int nb,int d[])
{
    int i,nd=0;
    for(i=0;i<na;i++)
    {
            if(!search(b,nb,a[i]))
            {d[nd]=a[i];
            nd=nd+1;
            }
    }
    return(nd);
}
array_union(int a[],int na,int b[],int nb,int f[])
{
    int i,nf=0;
    for(i=0;i<na;i++)
    {
        f[i]=a[i];
        nf=nf+1;
    }
    for(i=0;i<nb;i++)
    {
        if(!search(a,na,b[i]))
        {
            f[nf]=b[i];
            nf=nf+1;
        }
    }return(nf);

}
array_symdiff(int a[],int na,int b[],int nb,int g[])
{
    int i,ng=0;
    for(i=0;i<na;i++)
    {
        if(!search(b,nb,a[i]))
        {
            g[ng]=a[i];
            ng=ng+1;
        }
    }
    for(i=0;i<nb;i++)
    {
        if(!search(a,na,b[i]))
        {
            g[ng]=b[i];
            ng=ng+1;
        }
    }
    return(ng);
}
void main()
{
    int i,A[30],B[30],C[30],D[30],F[30],G[30],nd,nc,nb,ch,na,e,nf,ng;
    do{
       
        printf("\n\t\t********menu*********");
        printf("\n\t\toption 1: accept");
        printf("\n\t\toption 2:display the set");
        printf("\n\t\toption 3:find intersection");
        printf("\n\t\toption 4:array subtraction");
        printf("\n\t\toption 5:array union");
        printf("\n\t\toption 6:array symdiff");
        printf("\n\t\toption 7:exit");
        printf("\n\t\tenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            na=accept_array(A,"A");
            nb=accept_array(B,"B");
            break;
            case 2:
            display_array(A,na,"A");
            display_array(B,nb,"B");
            break;
            case 3:
            nc=array_intersection(A,na,B,nb,C);
            display_array(C,nc,"C");
            break;
            case 4:
            nd=array_subtraction(A,na,B,nb,D);
            display_array(D,nd,"D");
            break;
            case 5:
            nf=array_union(A,na,B,nb,F);
            display_array(F,nf,"F");
            break;
            case 6:
            ng=array_symdiff(A,na,B,nb,G);
            display_array(G,ng,"G");
            break;
            case 7:
            printf("end of program");
            break;
            default:
            printf("wrong choice");
        }
    }while(ch!=7);
}

/* Output

		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
1
enter the number of elements of set A
3
enter the element 1 :12
enter the element 2 :15
enter the element 3 :18
enter the number of elements of set B
4
enter the element 1 :12
enter the element 2 :14
enter the element 3 :17
enter the element 4 :18

		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
2

A={12,15,18}
B={12,14,17,18}
		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
3

C={12,18}
		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
4

D={15}
		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
5

F={12,15,18,14,17}
		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice
6

G={15,14,17}
		********menu*********
		option 1: accept
		option 2:display the set
		option 3:find intersection
		option 4:array subtraction
		option 5:array union
		option 6:array symdiff
		option 7:exit
		enter your choice

*/
