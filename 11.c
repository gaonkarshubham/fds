    /*************************************************************
    ASSIGNMENT NO.: 11
    NAME    : 
    CLASS   : SE-IT
    ROLL NO.: 
    BATCH   : 

    *************************************************************/ 
      #include<stdio.h>
      #include<stdlib.h>
      struct DLL
      {
	      struct DLL *prev;
	      char data;
	      struct DLL *next;
      };
      typedef struct DLL dll;

      dll * getnode(char d)
      {
	    dll *temp;
	    temp = (dll *)malloc(sizeof(dll));
	    temp->prev = NULL;
	    temp->data = d;
	    temp->next = NULL;
	    return(temp);
      }



      dll * create_dll()
      {
	 int i;
	 char s[30];
	 dll *head=NULL,*node,*last;
     printf("\n enter the string:");
     scanf("%s",s);
	 for(i=0;s[i]!='\0';i++)
	 {

	    node=getnode(s[i]);
	    if(i==0)
	    {
	      head=node;
	      last=node;
	    }
	    else
	    {
	       last->next=node;
	       node->prev=last;
	       last=node;
	    }
	 }
	 return(head);
      }

      void display_dll(dll *head)
      {
	  dll *temp;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nDLL is as follows : ");
	    printf("\n\t\tNODE ADDr  NODE->DATA   NODE->NEXT");
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       printf("\n\t\t %4u ==>  %4u  %2c  %4u ",temp,temp->prev,temp->data,temp->next);
	    }
	  }
      }
      void search_dll(dll *head)
      {
	  dll *temp;
	  char x;
	  if(head==NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nEnter the element to be searched:");
	    scanf("%c",&x);
	    for(temp=head;temp!= NULL;temp=temp->next)
	    {
	       if(temp->data == x)
	       {
		  printf("\n%c element present in the DLL",x);
		  printf("\n\t\t %4u ==> %4u   %2c   %4u ",temp,temp->prev,temp->data,temp->next);
	      break;
	       }
	    }
	      if(temp == NULL)
	       printf("\n%c element not present in the DLL",x);
	    }
      }

      void modify_dll(dll *head)
      {
	  dll *temp;
	  char x;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nEnter the element to be modified: ");
	    scanf("%c",&x);
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       if(temp->data == x)
	       {
		  printf("\n%c element found in the DLL",x);
		  printf("\nEnter the modified data : ");
		  scanf("%c",&temp->data);
		  printf("\n\t\t Modified successfully");
	      break;
	       }
	    }
	    if(temp == NULL)
	       printf("\n%c element not present in the DLL",x);
	  }
      }
      dll * delete_dll(dll *head)
      {
	  dll *temp;
	  char x;
	  if(head == NULL)
	    printf("\nList is empty");
	  else
	  {
	    printf("\nEnter the element to be deleted  : ");
	    scanf("%c",&x);
	    for(temp = head;temp!= NULL;temp = temp->next)
	    {
	       if(temp->data == x)
		  break;
	    }
	    if(temp == NULL)
	       printf("\n%c element to be deleted not present in the DLL",x);
	    else
	    {
	       if(temp == head)
	       {
		  head = head->next;
		  head->prev = NULL;
	       }
	       else
	       {
		  if(temp->next == NULL)
		  {
		     temp->prev->next = NULL;
		  }
		  else
		  {
		      temp->next->prev = temp->prev;
		      temp->prev->next = temp->next;
		  }
	       }
	       free(temp);
	       printf("\nFound and deleted successfully");
	    }
	  }
	  return(head);
      }

      void print_reverse(dll *head)
      {
	 dll *last,*temp;
	 last = head;
	 while(last->next!= NULL)
	   last=last->next;
	 for(temp=last;temp!= NULL;temp=temp->prev)
	 {
	    printf(" %c ",temp->data);
	 }
      }

      dll * revert_dll(dll *head)
      {
	  dll *node,*temp;
	  temp = head;
	  while(temp != NULL)
	  {
	     node = temp->prev;
	     temp->prev = temp->next;
	     temp->next = node;
	     temp = temp->prev;
	  }
	  head = node->prev;
	  return(head);
      }

      dll * insert_dll(dll *head)
      {
	 int pos,i;
	 char x;
	 dll *node,*last,*pnode;
	 printf("\nEnter the data to be inserted : ");
	 scanf("%c",&x);
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
	       head->prev = node;
	       head = node;
	    }
	    else
	    {
	       if(pos == 0)  // end
	       {
		  last = head;
		  while(last->next != NULL)
		    last = last->next;
		  last->next = node;
		  node->prev = last;
	       }
	       else
	       {
		  pnode = head;
		  for(i=1;i<pos-1;i++)
		    pnode = pnode->next;

		  node->next = pnode->next;
		  node->prev = pnode;
		  pnode->next = node;
		  node->next->prev = node;
	       }
	    }
	 }
	 printf("\nInserted successfully");
	 return(head);
      }

   int main()
   {
    int ch;
    dll * head1=NULL;
    do
    {
      printf("\n\t\tChoice 1 : Create");
      printf("\n\t\tChoice 2 : Display");
      printf("\n\t\tChoice 3 : Search");
      printf("\n\t\tChoice 4 : Modify");
      printf("\n\t\tChoice 5 : Delete");
      printf("\n\t\tChoice 6 : Insert");
      printf("\n\t\tChoice 7 : Reverse");
      printf("\n\t\tChoice 8 : Revert");
      printf("\n\t\tChoice 9 : Exit");
      printf("\n\nEnter ur choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1 : head1 = create_dll();
		 break;
	case 2 : display_dll(head1);
		 break;
	case 3 : search_dll(head1);
		 break;
	case 4 : modify_dll(head1);
		 break;
	case 5 : head1 =  delete_dll(head1);
		 break;
	case 6 : head1 =  insert_dll(head1);
		 break;
	case 7 : printf("\nDLL in reverse order is : ");
		 print_reverse(head1);
		 break;
	case 8 : head1 = revert_dll(head1);
		 printf("\nDLL reverted successfully");
		 break;
	case 9 : printf("\nEnd");
		 break;
	default: printf("\nTry again");
      }
    }while(ch!=9);
   }

/*Output:
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 1

 enter the string:ram

		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 2

DLL is as follows : 
		NODE ADDr  NODE->DATA   NODE->NEXT
		 13717520 ==>     0   r  13717552 
		 13717552 ==>  13717520   a  13717584 
		 13717584 ==>  13717552   m     0 
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 3

Enter the element to be searched:

 element not present in the DLL
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : a

Enter the element to be searched:
a element present in the DLL
		 13717552 ==> 13717520    a   13717584 
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 8

DLL reverted successfully
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 2

DLL is as follows : 
		NODE ADDr  NODE->DATA   NODE->NEXT
		 13717584 ==>     0   m  13717552 
		 13717552 ==>  13717584   a  13717520 
		 13717520 ==>  13717552   r     0 
		Choice 1 : Create
		Choice 2 : Display
		Choice 3 : Search
		Choice 4 : Modify
		Choice 5 : Delete
		Choice 6 : Insert
		Choice 7 : Reverse
		Choice 8 : Revert
		Choice 9 : Exit

Enter ur choice : 9
*/
