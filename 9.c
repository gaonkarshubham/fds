    /*************************************************************
    ASSIGNMENT NO.: 9
    NAME    : ANISHA CHOWGULE
    CLASS   : SE-IT
    ROLL NO.: S106
    BATCH   : S1
    *************************************************************/ 
      #include<stdio.h>
      #include<stdlib.h>
      struct SLL
      {
	      int data;
	      struct SLL *next;
      };
      typedef struct SLL sll;

      sll * getnode(int d)
      {
	    sll *temp;
	    temp = (sll *)malloc(sizeof(sll));
	    temp->data = d;
	    temp->next = NULL;
	    return(temp);
      }

      sll * create_sll()
      {
	 int i,n,x;
	 sll *head=NULL,*node,*last;
	 printf("\nEnter the no. of elements : ");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
	    printf("\nEnter the %d data : ",i+1);
	    scanf("%d",&x);
	    node = getnode(x);
	    if(i==0)
	    {
	      head = node;
	      last = node;
	    }
	    else
	    {
	       last->next = node;
	       last = node;
	    }
	 }
	 return(head);
      }

      void display_sll(sll *head)
      {
	  sll *temp;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nSLL is as follows : \n");
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       printf("\t%d",temp->data);
	    }
	  }
      }
      void search_sll(sll *head)
      {
	  sll *temp;
	  int x;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nEnter the element to be searched  : ");
	    scanf("%d",&x);
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       if(temp->data == x)
	       {
		  printf("\n%d element present in the SLL",x);
		  printf("\t%d",temp->data);
		  break;
	       }
	    }
	    if(temp == NULL)
	       printf("\n%d element not present in the SLL",x);
	  }
      }

      sll * delete_sll(sll *head)
      {
	  sll *temp,*pnode;
	  int x;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nEnter the element to be deleted  : ");
	    scanf("%d",&x);
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       if(temp->data == x)
		  break;
	       pnode = temp;
	    }
	    if(temp == NULL)
	       printf("\n%d element to be deleted is not present in the SLL",x);
	    else
	    {
	       if(temp == head)
		  head = head->next;
	       else
		  pnode->next = temp->next;
	       free(temp);
	       printf("\nFound and deleted successfully");
	    }
	  }
	  return(head);
      }

      void print_reverse(sll *temp)
      {
	 if(temp!=NULL)
	 {
	    print_reverse(temp->next);
	    printf("%d",temp->data);
	 }
      }

      sll * revert_sll(sll *head)
      {
	  sll *Cnode,*Pnode=NULL,*Nnode;
	  Pnode=NULL;
	  Cnode=head;
	  while(Cnode!=NULL)
	  {
	     Nnode = Cnode->next;
	     Cnode->next=Pnode;
	     Pnode=Cnode;
	     Cnode=Nnode;
	  }
	  head=Pnode;
	  return(head);
      }

      sll * insert_sll(sll *head)
      {
	 int x,pos,i;
	 sll *node,*last,*pnode;
	 printf("\nEnter the data to be inserted : ");
	 scanf("%d",&x);
	 node = getnode(x);
	 if(head == NULL)
	   head = node;
	 else
	 {
	    printf("\nEnter the Position where to enter ( 1 (front ) /  0(end) / postion where : ");
	    scanf("%d",&pos);
	    if(pos == 1)
	    {
	       node->next = head;
	       head=node;
	    }
	    else
	    {
	       if(pos == 0)
	       {
		  last = head;
		  while(last->next != NULL)
		    last = last->next;
		  last->next = node;
	       }
	       else
	       {
		  pnode = head;
		  for(i=1;i<pos-1;i++)
		    pnode = pnode->next;
		  node->next = pnode->next;
		  pnode->next = node;
	       }
	    }
	 }
	 printf("\nInserted successfully");
	 return(head);
      }

   void main()
   {
    int ch;
    sll * head1=NULL;
    do
    {
      printf("\n\t\tChoice 1 : Create");
      printf("\n\t\tChoice 2 : Display");
      printf("\n\t\tChoice 3 : Search");
      printf("\n\t\tChoice 4 : Delete");
      printf("\n\t\tChoice 5 : Insert");
      printf("\n\t\tChoice 6 : Reverse");
      printf("\n\t\tChoice 7 : Revert");
      printf("\n\t\tChoice 8 : Exit");
      printf("\n\nEnter ur choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1 : head1 = create_sll();
		 break;
	case 2 : display_sll(head1);
		 break;
	case 3 : search_sll(head1);
		 break;
	case 4 : head1 =  delete_sll(head1);
		 break;
	case 5 : head1 =  insert_sll(head1);
		 break;
	case 6 : printf("\nSLL in reverse order is : ");
		 print_reverse(head1);
		 break;
	case 7 : head1 = revert_sll(head1);
		 printf("\nSLL reverted successfully");
		 break;
	case 8 : printf("\nEnd");
		 break;
	default: printf("\nTry again");
      }
    }while(ch!=8);
   }

/*Output:

		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 1

Enter the no. of elements : 3

Enter the 1 data : 10

Enter the 2 data : 20

Enter the 3 data : 30

		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 2

SLL is as follows : 
	10	20	30
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 3

Enter the element to be searched  : 20

20 element present in the SLL	20
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 4

Enter the element to be deleted  : 20

Found and deleted successfully
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 5

Enter the data to be inserted : 25

Enter the Position where to enter ( 1 (front ) /  0(end) / postion where : 2

Inserted successfully
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 6

SLL in reverse order is : 302510
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 7

SLL reverted successfully
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 2

SLL is as follows : 
	30	25	10
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Delete
		Choice 5 : Insert
		Choice 6 : Reverse
		Choice 7 : Revert
		Choice 8 : Exit

Enter ur choice : 8

End
*/
