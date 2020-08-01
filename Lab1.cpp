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
	if(head->year > year) {
		node->next = head;
		head = node;
		return;
	}
	while(temp->next != NULL && temp->next->year < year) temp = temp->next;
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
    if(current -> next == NULL) {
    	cout << "Movie not found" << endl;
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
 
int main() {
	
	cout<<" Printing empty List: "<<endl;
	print();
	cout<<"----------"<<endl;

	cout<<" Deleting element from empty List: "<<endl;
	remove_Movie(1);
	print();
	cout<<"----------"<<endl;

	add_Movie(2, "mov1", 2000);
	add_Movie(412, "mov2", 2001);
	add_Movie(2, "mov3", 2002);
	add_Movie(1, "mov3", 2003);
	add_Movie(4, "mov4", 2010);
	add_Movie(8, "abs", 2019);
	add_Movie(9, "ask", 1990);
	add_Movie(3, "lsd", 1850);

	cout<<" Printing full List without elements with same id: "<<endl;
	print();
	cout<<"----------"<<endl;

	remove_Movie(412);
	cout<<" Printing List after removing an element from middle: "<<endl;
	print();
	cout<<"----------"<<endl;
	remove_Movie(3);
	cout<<" Printing List after removing an element from top: "<<endl;
	print();
	cout<<"----------"<<endl;
	remove_Movie(8);
	cout<<" Printing List after removing an element from bottom: "<<endl;
	print();
	cout<<"----------"<<endl;

	return 0;
}