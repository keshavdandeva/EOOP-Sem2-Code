#include<iostream>
#include<string.h>

using namespace std;

class country
{
  int key;
  const char* name;
  long population;
  country* next;

public:
  country(int p_key, const char* p_name, long p_population);
  country(int p_key, const char* p_name, long p_population, country *p_next);
  ~country();
  int getKey(){return key;}
  void setKey(int p_key){key = p_key;}
  const char* getName(){return name;}
  void setName(const char* p_name){name = p_name;}
  long getPopulation(){return population;}
  void setPopulation(long p_population){ population = p_population;}
  //void setName(long p_population){population = p_population;}
  country* getNextCountry(){return next;}
  void setNextCountry(country *p_next){next = p_next;}
  void print();
};

country::country(int p_key, const char* p_name, long p_population)
{
  key = p_key;
  name = p_name;
  population = p_population;

}


country::country(int p_key, const char* p_name, long p_population, country *p_next)
{
  key = p_key;
  name = p_name;
  population = p_population;
  next = p_next;
}

country::~country()
{

}

void country::print()
{
  cout << "key:" << key <<"\t"<< "country name:" << name <<"\t"<< "population:" << population << endl;
}


class CountryList
{
  country *head;
public:
  CountryList();
  ~CountryList();
  void add_country(int p_key, const char *p_name, long p_population);
  void deleteCountry(int key);
  void printList();
  CountryList(const CountryList& x);
  CountryList& operator=(const CountryList& x);

};

CountryList::CountryList()
{
	head = NULL;
}

CountryList::~CountryList()
{
  country* current = head;
  while( current != 0 )
    {
      country* next = current->getNextCountry();
      delete current;
      current = next;
    }
head = 0;
}

CountryList::CountryList(const CountryList& x)
{
   country * one = x.head;
  head = new country(one->getKey(),one->getName(),one->getPopulation());
  country * current = head;
  country * prev;
  current->setName(one->getName());
  current->setKey(one->getKey());
  current->setPopulation( one->getPopulation());
  while((one = one->getNextCountry()) != 0)
  {
    prev = current;
    current = new country(one->getKey(),one->getName(),one->getPopulation());
    current->setName(one->getName());
    current->setKey(one->getKey());
    current->setPopulation( one->getPopulation());
    prev->setNextCountry( current);

  }

}

void CountryList::add_country(int p_key, const char *p_name, long p_population)
{

  country* new_node;
  new_node = new country( p_key, p_name, p_population);
  // new_node->key = key;
  // new_node->population = population;
  // new_node->name = name;
  new_node->setNextCountry( head);
  //new_node->next = head;
  head = new_node;

  if(new_node!= NULL)
    {
      while(new_node && new_node->getNextCountry())
	{
	  if(strcmp(new_node->getName(), new_node->getNextCountry()->getName())>0)
	    {
	      int temp = new_node->getKey();
	      new_node->setKey(new_node->getNextCountry()->getKey());
	      new_node->getNextCountry()->setKey(temp);

	      const char* temp1 = new_node->getName();
	      new_node->setName(new_node->getNextCountry()->getName());
	      new_node->getNextCountry()->setName(temp1);

	      int temp2 = new_node->getPopulation();
	      new_node->setPopulation( new_node->getNextCountry()->getPopulation());
	      new_node->getNextCountry()->setPopulation( temp2);
	    }
	  new_node = new_node->getNextCountry();
	}
    }
}

void CountryList::printList()
{
  country* current;
  current = head;
  while(current != NULL)
    {
      current->print();
      current = current->getNextCountry();
    }
}

void CountryList::deleteCountry(int p_key)
{
  country *temp = head;
  if(head == NULL)
    return;
  if(temp->getKey() == p_key)
  {
    head = head->getNextCountry();
    return;
  }
  while(temp->getNextCountry()!= NULL && temp->getNextCountry()->getKey() != p_key)
  {
    temp = temp->getNextCountry();
  }
  if(temp->getNextCountry()!=NULL)
  {
    temp->setNextCountry(temp->getNextCountry()->getNextCountry());
  }
}



int main()
{
  CountryList myCountryList;



  cout << "Printing the country names and population" << endl << endl;

  myCountryList.add_country(5,"Germany",7541265);
  myCountryList.add_country(3,"America",7365858);
  myCountryList.add_country(2,"Poland",7128495);
  myCountryList.add_country(4,"Russia",7463645);
  myCountryList.add_country(1,"England",7247663);

  myCountryList.printList();

  cout << endl;

  myCountryList.deleteCountry(1);

  cout << endl ;
  cout << "Printing the country names after deletion" << endl << endl;

  myCountryList.printList();

  cout << endl ;

  myCountryList.~CountryList();

  myCountryList.add_country(5,"Germany",7541265);

  cout << endl;

  myCountryList.printList();

  cout << endl;
  cout << endl;

  CountryList myCountryList2 = myCountryList;

  myCountryList2.printList();


   return 0;
}
