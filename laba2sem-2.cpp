#include <iostream>
#include <malloc.h>
#include <string>

using namespace std;

struct TelephoneS
{
	int id;
	char Name[10];
	char Shurname[20];
	int namber;
	TelephoneS* Next;
	TelephoneS* Prev;
};
struct List
{
	TelephoneS* itsFirst;
	TelephoneS* itsLast;
};
void Menu();
void AddItem(List&);
//void DellItem(list&);
void PrintList(List&);
void CreateList(List*&);
List* theList = 0 ;

int main()
{
	List* itsFirst=0;
	List* itsLast=0;
	Menu();
	
	return 0;
}

void Menu()
{
	bool quit = false;
	while (true)
	{
		int choice;
		cout<< "\n ******* MENU ******* \n";
		cout<< "(1) vvedite spisok \n";
		cout<< "(2) prosmotr \n";
		cout<< "(3) dobavlenie \n";
		cout<< "(4) udalenie \n";
		cout<< "(5) exit \n";

		cin>> choice;

		switch (choice)
		{
			case(1):
				if (!theList)
				{
					CreateList (theList);
					theList->itsFirst = NULL;
					theList->itsLast = NULL;
					cout<<"the list has been created ... \n";
				}
				else
					cout<<"the List is alrealy created ... \n";
				break;
			case(2):
				if (theList)
					PrintList(*theList);
				else
					cout<<" the List is not created ... \n";
				break;
			case(3):
				if (theList)
					AddItem(*theList);
				else
					cout<<" the List is not created ... \n";
				break;
			//case(4):
			//	if (theList)
					//DeleteItem(*theList);
			//	else
			//		cout<<" the List is not created .. \n";
			//	break;
			case(5):
				quit = true;
		}
		if (quit == true)
			break;
	}
}

void AddItem(List &theList)
{
	cout<<"\n *** dobavit novogo abonenta ***\n";
	cout<<" Vvedite name: \n";
	TelephoneS* newTelephoneS = new TelephoneS;
	cin>> newTelephoneS -> Name;
	cout<<" Vvedite Shurname: \n";
	cin>> newTelephoneS -> Shurname;
	cout<< " Vvedite namber: \n";
	cin>> newTelephoneS -> namber;
	if (theList.itsLast)
	{
		theList.itsLast ->  Next = newTelephoneS;
		newTelephoneS -> Prev = theList.itsLast;
	}
	else
	{
		theList.itsFirst =newTelephoneS;
		newTelephoneS -> Prev = 0 ;
	}
	theList.itsLast = newTelephoneS;
	newTelephoneS -> Next = 0;
	cout<<" *** item was added *** \n";
}

void CreateList (List*&)
{
	bool temp=true;
	string answer;
	TelephoneS* pList,* p;
	TelephoneS* itsFirst;
	TelephoneS* itsLast;
	pList = NULL;
	do 
	{p=(TelephoneS*)malloc(sizeof(TelephoneS));
		cout<<"\n *** dobavit novogo abonenta ***\n";
		cout<<" Vvedite name: \n";
		TelephoneS* newTelephoneS = new TelephoneS;
		cin>> newTelephoneS -> Name;
		cout<<" Vvedite Shurname: \n";
		cin>> newTelephoneS -> Shurname;
		cout<< " Vvedite namber: \n";
		cin>> newTelephoneS -> namber;
		p -> Prev = pList;
		if (pList != NULL)
			pList -> Next = p;
		else
			itsFirst = p;
		pList=p;
		//puts ("Zaconchit' - <esc>");
		cout<<"\n prodolgit vvod? [yes/no]";
		cin>>answer;
		if((answer=="yes") || (answer=="y") || (answer=="Yes") || (answer=="Y"))
		{
			temp=true;
		}
		else if((answer=="no") || (answer=="n") || (answer=="No") || (answer=="N"))
		{
			break;
		}
	}
	while (!temp);
	itsLast=p;
	itsLast -> Next = NULL;
}

void PrintList(List &theList)
{
	cout<<"\n *** prosmotr spiska *** \n";
	TelephoneS* curTelephoneS = theList.itsFirst;
	while (curTelephoneS)
	{
		cout<< curTelephoneS -> Name;
		cout<< curTelephoneS -> Shurname;
		cout<< curTelephoneS -> namber;

		curTelephoneS = curTelephoneS -> Next;
	}
	cout<<"\n *** end ***\n";
}


