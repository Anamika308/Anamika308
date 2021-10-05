#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;	
};
class list
{
		private:
		node *head, *tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
		void createnode1(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void createnode2(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else
			{	
				tail->next=temp;
				tail=temp;
			}
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL";
		}
		void insert_start(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, int value)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=value;
			pre->next=temp;	
			temp->next=cur;
		}
		void delete_first()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
		
	    void searchNode(int data) 
		{  
            struct node *current = head;  
            int i = 1;  
            bool flag = false;  
         //Checks whether list is empty  
           if(head == NULL)
		    {  
                cout<<"List is empty \n";  
            }  
           else {  
                 while(current != NULL)
				{  
             //Compares node to be found with each node present in the list  
                    if(current->data == data)
			    	{  
                  flag = true;  
                   break;  
                    }  
                    i++;  
                    current = current->next;  
               }  
    }  
    if(flag)  
        cout<<"Element is present in the list at the position: "<< i;  
    else  
         cout<<"\nElement is not present in the list";  
}  
};
int main()
{
	list obj;
	obj.createnode1(5);
	obj.createnode1(10);
	obj.createnode1(11);
	obj.createnode1(14);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(6);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,9);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Finding the element-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.searchNode(11);
	obj.searchNode(9);
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Concatenate two list-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode2(15);
	obj.createnode2(20);
	obj.createnode2(25);
	obj.createnode2(30);
	obj.display();
	
	return 0;
}
/* -----------------output-------------
--------------------------------------------------
---------------Displaying All nodes---------------
--------------------------------------------------
5       10      11      14
--------------------------------------------------
----------------Inserting At Start----------------
--------------------------------------------------
6       5       10      11      14
--------------------------------------------------
-------------Inserting At Particular--------------
--------------------------------------------------
6       5       10      11      9       14
--------------------------------------------------
----------------Deleting At Start-----------------
--------------------------------------------------
5       10      11      9       14
--------------------------------------------------
--------------Deleting At Particular--------------
--------------------------------------------------
5       10      11      14
--------------------------------------------------
----------------Finding the element-----------------
--------------------------------------------------

Element is present in the list at the position: 3
Element is not present in the list
--------------------------------------------------
----------------Concatenate two list-----------------
--------------------------------------------------
5       10      11      14      15      20      25      30
--------------------------------
*/
