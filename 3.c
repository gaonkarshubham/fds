/*************************************************************
ASSIGNMENT NO.: 3
NAME    : 
CLASS   : SE-IT
ROLL NO.: 
BATCH   : 

*************************************************************/
#include<stdio.h>

void accept_string(char s[])
{
   printf("\n enter the string:");
   scanf("%s",s);
}

void display_string(char s[])
{

     printf("\n\t%s",s);


}
int mystrlen(char s[])
{ int len=0,i;
 for(i=0;s[i]!='\0';i++)
 {
 len++;
 }return(len);
}
void mystrcpy(char s[],char d[])
{int i;
 for(i=0;s[i]!='\0';i++)
 {
 d[i]=s[i];
 }
 d[i]='\0';
}
void mystrcat(char s[],char d[])
{
int i,l;
l=mystrlen(s);
for(i=0;d[i]!='\0';i++)
{
s[l+i]=d[i];
}
s[l+i]='\0';
}
void mystrrev(char s[])
{int b,e,temp;
b=0;
e=mystrlen(s)-1;
while(b<e)
{temp=s[b];
s[b]=s[e];
s[e]=temp;
b++;
e--;
}
}
char palindrome(char s[])
{int b,e;
b=0;
e=mystrlen(s);
while(b<e)
{
if(s[b]!=s[e])
return(0);
b++;
e--;
}return(1);
}
int mystrcmp(char sa[],char sb[])
{int i;
for(i=0;sb[i]!='\0',sa[i]!='\0';i++)
{
if(sa[i]>sb[i])
{
  return(sa[i]-sb[i]);
}
 else
if(sa[i]<sb[i])
{
    return(sb[i]-sa[i]);
}
}
return(0);
}
void mysubstring(char source[],char s[])
{
    int i,j,l1,l2,count=0;
    l1=mystrlen(source);
    l2=mystrlen(s);
    for(i=0;i<=(l1-l2);i++)
    {
        for(j=0;j<l2;j++)
        {
            if(source[i+j]!=s[j])
            break;
        }
        if(j==l2)
        {
            count=count+1;
            i=i+l2-1;
        }
    }printf("the occurrence is: %d",count);
}

void main()
{
   char source[30],dest[30],C[30],copy[30],l,l1,i,n,a,s[30];
   int ch;
   do
   {

   printf("\n choice 1: accept");
   printf("\n choice 2: display");
   printf("\n choice 3: length");
   printf("\n choice 4: copy the string");
   printf("\n choice 5: concatenate");
   printf("\n choice 6: reverse");
   printf("\n choice 7: palindrome");
   printf("\n choice 8: compare");
   printf("\n choice 9: substring");
   printf("\n choice10: exit");
   printf("\n\t enter ur choice :\t");
   scanf("%d",&ch);

switch(ch)
    {
     case 1:
	      accept_string(source);
	      accept_string(dest);
	      break;
     case 2:
          display_string(source);
	      display_string(dest);
	      break;
     case 3: printf("\nsource string: %s",source);
	     l=mystrlen(source);
	     printf("\nlength of the source string is %d",l);
	     printf("\ndestination string: %s",dest);
	     l1=mystrlen(dest);
	     printf("\nlength of the dest string is %d",l1);
	     break;
     case 4:
         printf("enter the string to be copied: ");
         scanf("%s",copy);
	     mystrcpy(copy,dest);
	     printf("\ncopied string is %s",dest);
	     break;
     case 5:
	     mystrcat(source,dest);
	     printf("\n\tsource string is: %s",dest);
	     printf("\n\tconcatenated string is:%s",source);
	     break;
     case 6:
         printf("\n\toriginal string :%s",source);
         mystrrev(source);
         printf("\n\treverse string is :%s",source);
	     break;
     case 7:
         printf("\nto check if the string is a palindrome");
	     a=palindrome(source);
	     if(a==1)
	     printf("\n\tsource string is a palindrome");
	     else
	     printf("\n\tsource string is not a palindrome");
	     break;
     case 8:
         printf("\n\t enter the string to be compared with source string\t");
	     scanf("%s",dest);
	     l=mystrcmp(source,dest);
	     if(l!=0)
	        printf("\nthe string is not equal");
	     else
	     {
	        printf("the string is equal");
	     }
	     break;
     case 9:
         printf("the main string is: %s",source);
         accept_string(s);
         mysubstring(source,s);
         break;
    case 10:
          printf("END the PROGRAM");
	      break;
   default: printf("\n\ttry again");
     }

  }while(ch!=10);
}

/*Output:

 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	1

 enter the string:abcd

 enter the string:efgh

 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	3

source string: abcd
length of the source string is 4
destination string: efgh
length of the dest string is 4
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	5

	source string is: efgh
	concatenated string is:abcdefgh
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	6

	original string :abcdefgh
	reverse string is :hgfedcba
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	7

to check if the string is a palindrome
	source string is not a palindrome
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	8

	 enter the string to be compared with source string	abcdefgh

the string is not equal
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	9
the main string is: hgfedcba
 enter the string:gfe
the occurrence is: 1
 choice 1: accept
 choice 2: display
 choice 3: length
 choice 4: copy the string
 choice 5: concatenate
 choice 6: reverse
 choice 7: palindrome
 choice 8: compare
 choice 9: substring
 choice10: exit
	 enter ur choice :	
*/
