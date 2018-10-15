   /*************************************************************
    ASSIGNMENT NO.: 10
    NAME    : 
    CLASS   : SE-IT
    ROLL NO.: 
    BATCH   : 
    *************************************************************/  
#include<stdio.h>
#include<memory.h>
#include<math.h>

typedef struct node
 {
  int expo,coef;
  struct node *next;
 }node;

node * insert(node *,int,int);
node * create();
node * add(node *p1,node *p2);
node * multi(node *p1,node *p2);
void display(node *head);

node *insert(node*head,int expo1,int coef1)
  {
   node *p,*q;
   p=(node *)malloc(sizeof(node));
   p->expo=expo1;
   p->coef=coef1;
   p->next=NULL;
   if(head==NULL)
    {
      head=p;
      head->next=head;
      return(head);
    }
   if(expo1>head->expo)
    {
      p->next=head->next;
      head->next=p;
      head=p;
      return(head);
    }
   if(expo1==head->expo)
    {
      head->coef=head->coef+coef1;
      return(head);
    }
    q=head;
    while(q->next!=head&&expo1>=q->next->expo)
      q=q->next;
      if(p->expo==q->expo)
               q->coef=q->coef+coef1;
      else
       {
                p->next=q->next;
                q->next=p;
       }
      return(head);
  }

node *create()
 {
  int n,i,expo1,coef1;
  node *head=NULL;
  printf("\n\nEnter no of terms of polynomial==>");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   {
     printf("\n\nEnter coef & expo==>");
     scanf("%d%d",&coef1,&expo1);
     head=insert(head,expo1,coef1);
   }
  return(head);
 }

node *add(node *p1,node *p2)
 {
  node *p;
  node *head=NULL;
  printf("\n\n\nAddition of polynomial==>");
  p=p1->next;
  do
   {
     head=insert(head,p->expo,p->coef);
     p=p->next;
   }while(p!=p1->next);
    p=p2->next;
  do
   {
     head=insert(head,p->expo,p->coef);
     p=p->next;
   }while(p!=p2->next);
    return(head);
  }

node *multi(node *p1,node *p2)
 {
  node *head1,*head2;
  node *head=NULL;
  printf("\n\n\nMultiplication of polynomial==>");
  head2=p2->next;
  do
   {
    head1=p1->next;
    do
     {
       head=insert(head,head1->expo+head2->expo,head1->coef*head2->coef);
       head1=head1->next;
     }while(head1!=p1->next);
       head2=head2->next;
   }while(head2!=p2->next);
    return(head);
 }

void display(node *head)
 {
  node *p,*q;
  int n=0;
  q=head->next;
  p=head->next;
  do
  {
   n++;
   q=q->next;
  }while(q!=head->next);
  printf("\n\n\tThe polynomial is==>");
  do
   {
    if(n-1)
     {
      printf("%dx^(%d) + ",p->coef,p->expo);
      p=p->next;
     }
    else
    {
     printf(" %dx^(%d)",p->coef,p->expo);
     p=p->next;
    }
    n--;
   } while(p!=head->next);
 }

void main()
 {
  char ans;
  int x,ch;
  double a;
  node *p1,*p2,*p3;
  p1=p2=p3=NULL;
  do
  {
   printf("\n\t----------------<<  MENU  >>---------------");
   printf("\n\tPolynomial Operations :");
   printf(" 1.Add");
   printf("\n\t\t\t\t2.Multiply");
   printf("\n\t\t\t\t3.Exit");
   printf("\n\t---------------------------------------------------");
   printf("\n\n\n\tEnter your choice==>");
   scanf("%d",&ch);
   switch(ch)
    {
     case 1 :
                      p1=create();
                      display(p1);
                      p2=create();
                      display(p2);
                      p3=add(p1,p2);
                      display(p3);
                       break;
     case 2 :
                     p1=create();
                     display(p1);
                     p2=create();
                     display(p2);
                     p3=multi(p1,p2);
        	     display(p3);
                     break;
  
     case 3 :
                     break;
    default :
                     printf("\n\n\tinvalid choice");
                     break;

   }
  }while(ch!=3);
 }

/*Output:

	----------------<<  MENU  >>---------------
	Polynomial Operations : 1.Add
				2.Multiply
				3.Exit
	---------------------------------------------------


	Enter your choice==>1


Enter no of terms of polynomial==>3


Enter coef & expo==>4 4


Enter coef & expo==>3 3


Enter coef & expo==>2 2


	The polynomial is==>2x^(2) + 3x^(3) +  4x^(4)

Enter no of terms of polynomial==>2 


Enter coef & expo==>4 4


Enter coef & expo==>1 1


	The polynomial is==>1x^(1) +  4x^(4)


Addition of polynomial==>

	The polynomial is==>1x^(1) + 2x^(2) + 3x^(3) +  8x^(4)
	----------------<<  MENU  >>---------------
	Polynomial Operations : 1.Add
				2.Multiply
				3.Exit
	---------------------------------------------------


	Enter your choice==>2


Enter no of terms of polynomial==>3


Enter coef & expo==>4 4


Enter coef & expo==>3 3


Enter coef & expo==>2 2


	The polynomial is==>2x^(2) + 3x^(3) +  4x^(4)

Enter no of terms of polynomial==>2


Enter coef & expo==>3 3


Enter coef & expo==>1 1


	The polynomial is==>1x^(1) +  3x^(3)


Multiplication of polynomial==>

	The polynomial is==>2x^(3) + 3x^(4) + 10x^(5) + 9x^(6) +  12x^(7)
	----------------<<  MENU  >>---------------
	Polynomial Operations : 1.Add
				2.Multiply
				3.Exit
	---------------------------------------------------


	Enter your choice==>3
*/
