#include <iostream>
using namespace std;

struct node{

	int data;
	node *next;
};

struct node *head = NULL;

void add_data(int x);
void print();

int main(int argc, char const *argv[]){

	add_data(1);
	add_data(2);
	add_data(3);
	print();
	return 0;
}

void add_data(int x){

	struct node *new_node = (struct node*) malloc(sizeof(*new_node));
	struct node *temp = head;
	new_node->next = NULL;
	new_node->data = x;
	temp = temp->next;
	if(head == NULL) {
		head = new_node;
		return;
	}
}

void print(){

	struct node *temp = head;
	while(temp != NULL){
	cout<<"Data : "<<temp->data<<endl;
	temp = temp->next;
	}
}