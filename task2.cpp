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
	node->title = new char(sizeof(title)+1);
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
	struct Movie *temp = head;
	if(head == NULL) return;
	if(temp->id == id) {
		head = head->next;
		return;
	}
	while(temp->next != NULL && temp->next->id != id) temp = temp->next;
	if(temp->next != NULL) temp->next = temp->next->next;
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

			temp->title = new char(sizeof(title)+1);
			strcpy( temp->title, title);

			return temp->year;
		}

		temp = temp->next;
	}

	temp = head;

	//Movie not found. So adding it

	struct Movie *node = new Movie;
	node->next = NULL;
	node->title = new char(sizeof(title)+1);
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
	add_Movie(4, "e", 2002);
	cout<<" Printing full List without elements with same id: "<<endl;
	print();
	cout<<"----------"<<endl;
	remove_Movie(412);
	cout<<" Printing List after removing an element: "<<endl;
	print();
	cout<<"----------"<<endl;

	cout<<"After adding new access function and new element with diff id, the list is:"<<endl;

	access(5, "f"); //adding element with new id
	print();
	cout<<"----------"<<endl;

	cout<<"Now entering an element with same id, so its name updates. Now, the list is:"<<endl;
	access(1, "g");
	print();
	cout<<"----------"<<endl;

	int i = access(6, "Forrest Gump");
	// cout<<"Value of i initially: "<<i<<endl;
	// cout<<"----------"<<endl;
	access(7, "Forrest Gump") = 20 + i;
	access(6, "Forrest Gump")++;

	access(6, "Forrest Gump") = access(4,"M2") + access(-15, "M3");
	return 0;
}