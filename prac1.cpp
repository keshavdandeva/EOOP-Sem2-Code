#include <iostream>
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
 
int main() {
	add_Movie(2, "mov1", 2000);
	add_Movie(412, "mov2", 2001);
	add_Movie(2, "mov3", 2002);
	add_Movie(1, "mov3", 2003);
	add_Movie(4, "mov4", 2002);
	remove_Movie(412);
	print();
}