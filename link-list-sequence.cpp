#include <iostream>

using namespace std;
template <typename Key, typename Info>
class Sequence {
	class Node {
	public:
		Key key;
		Info info;
		Node *next;
		Node(Key k, Info i) { key = k; info = i; next = NULL; }
		Key key_() { return key; }
		Info info_() { return info; }
	};
	Node *head;
public:
	Node *head_() { return head; }

	void insert(const Key &, const Info &);
	void print();
	int split(Sequence &, int, Sequence &, int, Sequence &, int);

	Sequence();
	~Sequence() { };
}; 

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence() { head = NULL; };

template <typename Key, typename Info>
void Sequence<Key, Info>::insert(const Key &key, const Info &info) {
	if(head == NULL) {
		Node *temp = new Node(key, info);
		head = temp;
	} else {
		Node *temp = head;
		while(temp -> next != NULL) 
			temp = temp -> next;
		Node *insert_this = new Node(key, info);
		temp -> next = insert_this;
	}
}

template <typename Key, typename Info>
void Sequence<Key, Info>::print() {
	Node *temp = head;
	while(temp != NULL) {
		if(temp -> next != NULL) 
			cout << temp -> key << ", ";
		else 
			cout << temp -> key << endl;
		temp = temp -> next;
	}
	
}

template <typename Key, typename Info> 
int Sequence<Key, Info>::split(Sequence<Key, Info> &source, int start, 
	Sequence<Key, Info> &result1, int step1, Sequence<Key, Info> &result2, int step2) {
	
	Node *temp_s = source.head_();
	while(start != 0) {
		temp_s = temp_s -> next;
		start--;
	}
	while(temp_s != NULL) {
		for(int i = 0; i < step1 && temp_s != NULL; i++) {
			result1.insert(temp_s -> key_(), temp_s -> info_());
			temp_s = temp_s -> next;
		}
		for(int i = 0; i < step2 && temp_s != NULL; i++) {
			result2.insert(temp_s -> key_(), temp_s -> info_());
			temp_s = temp_s -> next;
		}
	}
	return 0;
}
int main() {
	Sequence<int, int> s1, r1, r2;
	s1.insert(1, 2); s1.insert(2, 2); s1.insert(3, 2); s1.insert(10, 2);
	s1.insert(20, 2); s1.insert(4, 2); s1.insert(5, 2); s1.insert(6, 2);
	s1.insert(7, 2); s1.insert(30, 2); s1.insert(40, 2); s1.insert(8, 2);
	s1.insert(9, 2); s1.insert(10, 2); s1.insert(11, 2); s1.insert(50, 2);

	s1.split(s1, 3, r1, 2, r2, 4);
	cout << "Source: ";
	s1.print();
	cout << "Res 1: ";
	r1.print();
	cout << "Res 2: ";
	r2.print();

	return 0;
}