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
	struct Movie *node = (struct Movie *) malloc(sizeof(*node));
	node->next = NULL;
	node->title = title;
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

			temp->title = (char*) malloc(sizeof(char) * sizeof(title));
			temp->title = title;
			return temp->year;
		}

		temp = temp->next;
	}

	temp = head;

	//Movie not found. So adding it

	struct Movie *node = (struct Movie *) malloc(sizeof(*node));
	node->next = NULL;
	node->title = title;
	node->id = id;
	node->year = 1900;
	if(head == NULL) {
		head = node;
		return node->year;
	}
	
	// if(head->year > year) {
	// 	node->next = head;
	// 	head = node;
	// 	return node->year;
	// }
	// while(temp->next != NULL && temp->next->year < year) temp = temp->next;
	// struct Movie *temp1 = temp->next;
	// temp->next = node;
	// node->next = temp1;

	 if ((strcmp(head -> title , node -> title)) >= 0) { 
    node -> next = head; 
    head = node;
    return node->year; 
    } 

    // else { 
    // current = head; 
    while (temp -> next  != NULL && (strcmp(temp -> next -> title , node->title )) < 0 ) temp = temp -> next; 
     struct Movie *temp1 = temp->next;
	 temp->next = node;
	 node->next = temp1; 
    //} 
}
 
int main() {
	add_Movie(2, "a", 2000);
	add_Movie(412, "b", 2001);
	add_Movie(2, "b", 2002); // movie with same id wont't be added
	add_Movie(1, "c", 2003);
	add_Movie(3, "d", 2002);
	remove_Movie(412);
	print();

	cout<<"After adding new function, the list is:"<<endl;

	access(4, "e");
	access(1, "f");
	print();
}