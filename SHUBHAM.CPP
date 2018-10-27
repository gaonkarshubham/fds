#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
	int priority;
	char info[20];
	struct node *link;
};
/*
 * Class Priority Queue
 */
class Priority_Queue
{
private:
	node *front;
public:
	Priority_Queue()
	{
	front = NULL;
	}
	/*
	 * Insert into Priority Queue
	 */
		void insert(char Patient_name[20], int priority);
	/*
	 * Delete from Priority Queue
	 */
	void del()
	{
	node *tmp;
	if(front == NULL)
		cout<<"Queue Underflow\n";
	else
	    {
		tmp = front;
		cout<<"Deleted Patient_name is: "<<tmp->info<<endl;
		front = front->link;
		free(tmp);
	    }
	}
	/*
	 * Print Priority Queue
	 */
	void display();
};
	void Priority_Queue::display()
	{
	node *ptr;
	ptr = front;
	if (front == NULL)
		cout<<"Queue is empty\n";
	else
	    {	cout<<"Queue is :\n";
		cout<<"Priority       Patient_name\n";
		while(ptr != NULL)
		{
		cout<<ptr->priority<<"                 "<<ptr->info<<endl;
		ptr = ptr->link;
		}
	    }
	}


      void Priority_Queue::insert(char Patient_name[20], int priority)
	{
	node *tmp, *q;
	tmp = new node;
	strcpy(tmp->info,Patient_name);
	tmp->priority = priority;
	if (front == NULL || priority < front->priority)
	    {
		tmp->link = front;
		front = tmp;
	    }
	else
	    {
		q = front;
		while (q->link != NULL && q->link->priority <= priority)
		    q=q->link;
		tmp->link = q->link;
		q->link = tmp;
	    }
	}



/*
 * Main
 */
int main()
{
int choice;
char Patient_name[20];
int priority;
Priority_Queue pq;
do
    {
	cout<<"1.Insert Patient names\n";
	cout<<"2.Delete\n";
	cout<<"3.Display\n";
	cout<<"4.Quit\n";
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	cout<<"Input the Patient_name to be added in the queue : ";
	cin>>Patient_name;
	cout<<"Enter its priority : ";
	cin>>priority;
	pq.insert(Patient_name, priority);
	break;
	case 2:
	pq.del();
	break;
	case 3:
	pq.display();
	break;
	case 4:
	break;
	default :
	cout<<"Wrong choice\n";
	}
    }
while(choice != 4);
return 0;
}

/************************************************OUTPUT*********************************************
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice :  1
Input the Patient_name to be added in the queue : Shubham_Dipak_gaonkar
Enter its priority : 3
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 1
Input the Patient_name to be added in the queue : Siddhesh_Gage
Enter its priority : 2
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 1
Input the Patient_name to be added in the queue : Shubhangi_Gulave
Enter its priority : 1
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 3
Queue is :
Priority       Patient_name
1                 Shubhangi_Gulave
2                 Siddhesh_Gage
3                 Shubham_Dipak_gaonka
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 2
Deleted Patient_name is: Shubhangi_Gulave
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 3
Queue is :
Priority       Patient_name
2                 Siddhesh_Gage
3                 Shubham_Dipak_gaonka
1.Insert Patient names
2.Delete
3.Display
4.Quit
Enter your choice : 4
*********************************************************************/
