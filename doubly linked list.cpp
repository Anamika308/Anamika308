#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }
void insert(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
void insert2(int newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}
//Inserts a new element at the given position 
    void insert_position(int newElement, int position) {
      Node* newNode = new Node(); 
      newNode->data = newElement;
      newNode->next = NULL;
      newNode->prev = NULL;
      if(position < 1) {
        cout<<"\nposition should be >= 1.";
      } else if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      } else {
        Node* temp = head;
        for(int i = 1; i < position-1; i++) {
          if(temp != NULL) {
            temp = temp->next;
          }
        }
        if(temp != NULL) {
          newNode->next = temp->next;
          newNode->prev = temp;
          temp->next = newNode;
          if(newNode->next != NULL)
            newNode->next->prev = newNode;  
        } else {
          cout<<"\nThe previous node is null.";
        } 
      }
    }
 //Add new element at the end of the list
    void insert_last(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL;
      newNode->prev = NULL; 
      if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
      }    
    }
    void delete_position(int position) {     
      if(position < 1) {
        cout<<"\nposition should be >= 1.";
      } else if (position == 1 && head != NULL) { 
        Node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
        if(head != NULL)
          head->prev = NULL;
      } else {
        Node* temp = head;
        for(int i = 1; i < position-1; i++) {
          if(temp != NULL) {
            temp = temp->next;
          }
        }
        if(temp != NULL && temp->next != NULL) {
          Node* nodeToDelete = temp->next;
          temp->next = temp->next->next;
          if(temp->next->next != NULL)
            temp->next->next->prev = temp->next;  
          free(nodeToDelete); 
        } else {
          cout<<"\nThe node is already null.";
        }       
      }
    }  
void delete_first()  
{  
    struct Node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\n UNDERFLOW\n";  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  ;  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  ;  
    }  
}
    void delete_last() {
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
        } else {
          Node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          free(lastNode); 
        }
      }
    }
void search_element(int searchValue) {
  
  Node* temp = head;
  int found = 0;
  int i = 0;
  if(temp != NULL) {
    while(temp != NULL) {
      i++;
      if(temp->data == searchValue) {
        found++;
        break;
      }
      temp = temp->next;
    }
    if (found == 1) {
      cout<<searchValue<<" is found at index = "<<i<<".\n";
    } else {
      cout<<searchValue<<" is not found in the list.\n";
    }
  } else {
    cout<<"The list is empty.\n";
  }
}
void display() {
      Node* temp = head;
      if(temp != NULL) {
        while(temp != NULL) {
          cout<<temp->data<<"-> ";
          temp = temp->next;
        }
        cout<<"NULL"<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }
};
int main()
{
	LinkedList obj;
	obj.insert(8);
	obj.insert(6);
	obj.insert(4);
	obj.insert(2);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert(1);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At End--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_last(9);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,3);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(2);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Finding the element-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.search_element(4);
	obj.search_element(9);
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Concatenate two list-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert2(15);
	obj.insert2(20);
	obj.insert2(25);
	obj.insert2(30);
	obj.display();
	
	return 0;
}
/* ----------OUTPUT-----------
--------------------------------------------------
---------------Displaying All nodes---------------
--------------------------------------------------
2-> 4-> 6-> 8-> NULL

--------------------------------------------------
----------------Inserting At Start----------------
--------------------------------------------------
1-> 2-> 4-> 6-> 8-> NULL

--------------------------------------------------
-------------Inserting At End--------------
--------------------------------------------------
1-> 2-> 4-> 6-> 8-> 9-> NULL

--------------------------------------------------
-------------Inserting At Particular--------------
--------------------------------------------------
1-> 2-> 5-> 4-> 6-> 8-> 9-> NULL

--------------------------------------------------
----------------Deleting At Start-----------------
--------------------------------------------------
2-> 5-> 4-> 6-> 8-> 9-> NULL

--------------------------------------------------
----------------Deleting At End-----------------
--------------------------------------------------
2-> 5-> 4-> 6-> 8-> NULL

--------------------------------------------------
--------------Deleting At Particular--------------
--------------------------------------------------
2-> 4-> 6-> 8-> NULL

--------------------------------------------------
----------------Finding the element-----------------
--------------------------------------------------
4 is found at index = 2.
9 is not found in the list.

--------------------------------------------------
----------------Concatenate two list-----------------
--------------------------------------------------
30-> 25-> 20-> 15-> 2-> 4-> 6-> 8-> NULL

--------------------------------
*/

	    

