#include <iostream>
#include <cstring>
using namespace std;

struct Movie {
	int id;
	char *title;
	int year;
	struct Movie *next;
};
 
struct Movie *head = NULL;
 
void add_Movie(int id, char *title, int year) {
	struct Movie *temp = head;
	struct Movie *node = new Movie;
	node->next = NULL;
	node->title = new char[sizeof(title)+1];
	strcpy( node->title, title);
	node->id = id;
	node->year = year;
	if(head == NULL) {
		head = node;
		return;
	}
	while(temp != NULL) {
		if(temp->id == id) return;
		temp = temp->next;
	}
	temp = head;
	if(head == NULL) {
		head = node;
		return ;
	}
	
	if ((strcmp(head -> title , node -> title)) >= 0) { 
    node -> next = head; 
    head = node;
    return ; 
    } 

    
    while (temp -> next  != NULL && (strcmp(temp -> next -> title , node->title )) < 0 ) temp = temp -> next; 
     struct Movie *temp1 = temp->next;
	 temp->next = node;
	 node->next = temp1; 
     
}
 
void remove_Movie(int id) {
  Movie *current= new Movie;
  current = head;
  Movie *prev = new Movie;
  if(head == NULL) {
    return;
  } 
  else if (current -> next == NULL) {
    delete current -> title;
    delete current;
    head = NULL;
    return;
  }
  else if( current -> id == id && current -> next != NULL){
    head = current -> next;
    delete current -> title;
    delete current;
    return;
  }
  while(current -> id != id) {
    if(current -> next == NULL) {cout << "Movie not found" << endl;
    return;
  }
  else {
    prev = current;
    current = current -> next;
  }
} 
prev -> next = current -> next;
delete current -> title;
delete current;
}

void print() {
	struct Movie *temp = head;
	if(head == NULL) cout<<"List is empty!"<<endl;
	while(temp != NULL) {
		cout << temp->id << ": " << temp->title << " " << temp->year << endl;
		temp = temp->next;
	}
}

int& access(int id, char *title){

	struct Movie *temp = head;

	//checks if same id movie exists. if yes then changes its name.
	while( temp->next != NULL){

		if(temp->id == id){

			temp->title = new char[sizeof(title)+1];
			strcpy( temp->title, title);

			return temp->year;
		}

		temp = temp->next;
	}

	temp = head;

	//Movie not found. So adding it

	struct Movie *node = new Movie;
	node->next = NULL;
	node->title = new char[sizeof(title)+1];
	strcpy( node->title, title);
	node->id = id;
	node->year = 1900;
	if(head == NULL) {
		head = node;
		return node->year;
	}
	
	if ((strcmp(head -> title , node -> title)) >= 0) { 
    node -> next = head; 
    head = node;
    return node->year; 
    } 

     while (temp -> next  != NULL && (strcmp(temp -> next -> title , node->title )) < 0 ) temp = temp -> next; 
     struct Movie *temp1 = temp->next;
	 temp->next = node;
	 node->next = temp1; 
    return node->year;
}
 
int main() {
	cout<<" Printing empty List: "<<endl;
	print();
	cout<<"----------"<<endl;

	cout<<" Deleting element from empty List: "<<endl;
	remove_Movie(1);
	print();
	cout<<"----------"<<endl;

	add_Movie(2, "a", 2000);
	add_Movie(412, "b", 2001);
	add_Movie(2, "c", 2002);
	add_Movie(1, "d", 2003);
	add_Movie(4, "e", 2010);
	add_Movie(8, "f", 2019);
	add_Movie(9, "g", 1990);
	add_Movie(3, "h", 1850);

	cout<<" Printing full List without elements with same id: "<<endl;
	print();
	cout<<"----------"<<endl;

	remove_Movie(412);
	cout<<" Printing List after removing an element from middle: "<<endl;
	print();
	cout<<"----------"<<endl;
	remove_Movie(2);
	cout<<" Printing List after removing an element from top: "<<endl;
	print();
	cout<<"----------"<<endl;
	remove_Movie(3);
	cout<<" Printing List after removing an element from bottom: "<<endl;
	print();
	cout<<"----------"<<endl;

	cout<<"-- TASK 2 (Access Function) --"<<endl;

	cout<<"Entering an element with same id, so its name updates. Now, the list is:"<<endl;
	int i = access(1, "g");
	print();
	cout<<"Value stored in i is :"<<i<<endl;
	cout<<"----------"<<endl;

	cout<<" Adding a new element if the id doesn't already exists.Now, the list is:"<<endl;

	int j = access(6, "a"); //adding element with new id
	print();
	cout<<"Value stored in j is :"<<j<<endl;
	cout<<"----------"<<endl;

	cout<<"Test 1"<<endl;
	access(1, "b") = 20+i ;
	print();
	cout<<"----------"<<endl;

	cout<<"Test 2"<<endl;
	access(1, "x")++ ;
	print();
	cout<<"----------"<<endl;

	cout<<"Test 3"<<endl;
	access(1, "x") = access(7,"y") + access(2, "c") ;
	print();
	cout<<"----------"<<endl;

	return 0;
}