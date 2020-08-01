#include <iostream>
#include <cstring>
using namespace std;

class Movie {
	int id;
	char *title;
	int year;
	Movie *next;

public: 
	Movie(){};

	Movie(int id, char* title, int year){
		//Constructor prints all data of this object

		cout<<"Constructor called :"<<endl;
		this->title = new char[sizeof(title)+1];
		strcpy(this->title,title);
		this->id = id;
		this->year = year;
		cout<<"ID: "<<this->id<<" Title: "<<this->title<<" Year: "<<this->year<<endl;

	}

	~Movie(){
		//prints all data of the destroyed object
		cout<<"Destructor called and deleted the following object:"<<endl;
		cout<<"ID: "<<this->id<<" Title: "<<this->title<<" Year: "<<this->year<<endl;
		delete [] this->title;

	} 

	int get_id(){return this->id;}

	void set_id(int id){this->id = id;}

	char* get_title(){return this->title;}

	void set_title(char* title){
		this->title = new char[sizeof(title)+1];
		strcpy(this->title,title);
	}

	int get_year(){return this->year;}

	void set_year(int year){ this->year = year;}

	Movie* get_next_movie() {return this->next;}
	
	void set_next_movie (Movie *next){ this->next = next;}

	void print() { //prints all data of the object

		cout<<"Print function called"<<endl;
		cout<<"ID: "<<this->id<<" Title: "<<this->title<<" Year: "<<this->year<<endl;
	}

	friend class MovieList;

};

class MovieList {
	Movie *head;

public:
	MovieList(){
		head = NULL; 
		cout << "Empty List is created " << endl;
	}

	~MovieList(){
		Movie * current = head ;
		if(head == NULL)
			cout << "List is empty so nothing to delete " << endl;

		while (current != NULL){ 
			delete current -> get_title();
			delete current;
			current = current -> get_next_movie();
		}
		head = NULL ;

	}

	MovieList(const MovieList &x){

		Movie *temp = x.get_head();

		while(temp != NULL){
			this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
			temp = temp -> next;
		}
	}

		//methods according to functions from Task 1

	void add_Movie(int id, char *title, int year) {
		Movie *temp = head;
		Movie *node = new Movie ;
		node->set_next_movie(NULL);
		node->set_title(title);
		node->set_id(id);
		node->set_year(year);

		if(head == NULL) {
			head = node;
			return;
		}
		while(temp != NULL) {
			if(temp->get_id() == id) return;
			temp = temp->get_next_movie();
		}
		temp = head;
		if(head == NULL) {
			head = node;
			return ;
		}

		if ((strcmp(head -> get_title() , node -> get_title())) >= 0) { 
			node -> set_next_movie(head); 
			head = node;
			return ; 
		} 


		while (temp -> get_next_movie()  != NULL && (strcmp(temp -> get_next_movie() -> get_title() , node->get_title() )) < 0 ) temp = temp -> get_next_movie(); 
		Movie *temp1 = temp->get_next_movie();
		temp->set_next_movie(node);
		node->set_next_movie(temp1); 

	}
	void remove_Movie(int id) {
		Movie *current= new Movie;
		current = head;
		Movie *prev = new Movie;
		if(head == NULL) {
			return;
		} 
		else if (current -> get_next_movie() == NULL) {
			delete current -> get_title();
			delete current;
			head = NULL;
			return;
		}
		else if( current -> get_id() == id && current -> get_next_movie() != NULL){
			head = current -> get_next_movie();
			delete current -> get_title();
			delete current;
			return;
		}
		while(current -> get_id() != id) {
			if(current -> get_next_movie() == NULL) {cout << "Movie not found" << endl;
			return;
		}
		else {
			prev = current;
			current = current -> get_next_movie();
		}
	} 
	prev -> set_next_movie(current -> get_next_movie());
	delete current -> get_title();
	delete current;
}
void print() {
	Movie *temp = head;
	if(head == NULL) cout<<"List is empty!"<<endl;
	while(temp != NULL) {
		cout <<"ID: "<< temp->get_id() <<" Title : " << temp->get_title() << " Year : " << temp->get_year() << endl;
		temp = temp->get_next_movie();
	}
}

Movie *get_movie(int id) const{

	Movie *temp = head;
	while(temp != NULL) {
		if(temp -> id == id) 
			return temp;
		temp = temp -> next;
	}
	printf("Movie not found\n");
	return NULL;
}

void delete_list(){
	this-> ~MovieList();
}

Movie *get_head() const{
	return head;
}

MovieList & operator = (const MovieList &x){

	if(x.get_head() != this->get_head()){
		Movie *temp = x.get_head();
		while(temp != NULL){
			this -> add_Movie(temp->get_id(), temp->get_title(), temp->get_year());
			temp = temp -> next;
		}
		return *this;
	}
	else {
		cout <<"Error encountered!"<<endl;
		return *this;
	}
}
};

int main(){

	
	MovieList list1;
	
	list1.add_Movie(01,"Zvengers",1942);
	list1.add_Movie(03,"Bvengers2",1952);
	list1.add_Movie(02,"Avengers3",1962);
	list1.add_Movie(37,"Batman",2010);
	list1.print();
	cout<<"Now Removing a movie"<<endl;
	list1.remove_Movie(37);

	cout<<"List without that movie:"<<endl;
	list1.print();

	cout<<"Now Dynamic object"<<endl;
	MovieList *list2 = new MovieList();

	list2->add_Movie(05,"Toy Story",2002);
	list2->add_Movie(07,"Toy Story 2",2006);
	list2->add_Movie(06,"Toy Story 3",2010);
	list2->add_Movie(82,"Sample",1280);
	list2->print();

	cout<<"Now Removing a movie"<<endl;
	list2->remove_Movie(82);

	cout<<"List without that movie:"<<endl;
	list2->print();

	delete list2;

	//Task 4

	cout << "Using copy constructor" << endl;
	//copy constructor
	MovieList list3 = list1;
	list3.print();

	cout << "Using assignment operator "<< endl;
	//assignment operator
	MovieList list4;
	list4 = list3;
	list4.print();
	//list1 = list1;
	//list1.print();
	return 0;
}