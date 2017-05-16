#include<iostream>
#include<cstring>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

struct Abonent
{
	char number[12],
		 name[10],
		 surname[20];
	Abonent* next;
	Abonent* prev;
	void InputNumber();
	void InputSurname();
	void InputName();
};

void Menu(Abonent* &, Abonent* &, int &);
void AddRecordToPhoneBook(Abonent* &, Abonent* &, int &);
void RemoveRecordFromPhoneBook(Abonent* &, Abonent* &, int &);
void FindRecordInPhoneBook(Abonent* &);
void FindAbonentByNumber(Abonent* &, char*);
void FindAbonentBySurname(Abonent* &, char*);
void ShowRecordsFromPhoneBook(Abonent* &);
void SortRecordsInPhoneBook(Abonent* &, int &);
void SavePhoneBookToFile(Abonent* &);
void CopyPhonebookFromFile(Abonent* &, Abonent* &, int &);
void AddAbonentFromFile(Abonent* &, Abonent* &, Abonent* &, int &);

bool IsNumberInPhoneBook(char*, Abonent* &);
bool IsOnlyNumbers(char*);
bool IsOnlyLetters(char*);


int main()
{
	Abonent* Head = NULL;
	Abonent* Tail = NULL;
	int counterAbonents = 0;
	Menu(Head, Tail, counterAbonents);
	while (Head)
	{
		Abonent* temp = Head;
		Head = Head->next;
		delete[] temp;
	}
  return 0;
}

void Abonent::InputNumber()
{

	cout << "Write the number:";
	cin.getline(number, 12);
	while (!IsOnlyNumbers(number) || !_stricmp(number, "\0"))
	{
		cout << "Write the correct number! Try again.\n";
		cin.getline(number, 12);
	}
}

void Abonent::InputSurname()
{
	cout << "Write the surname:";
	cin.getline(surname, 12);
	while (!IsOnlyLetters(surname) || !_stricmp(surname, "\0"))
	{
		cout << "Write correct surname! Try again.\n";
		cin.getline(surname, 12);
	}
}

void Abonent::InputName()
{
	cout << "Write the name:";
	cin.getline(name, 12);
	while (!IsOnlyLetters(name) || !_stricmp(name, "\0"))
	{
		cout << "Write correct name! Try again.\n";
		cin.getline(name, 12);
	}
}

void Menu(Abonent* &Head, Abonent* &Tail, int &counterAbonents)
{
	bool exit = false;
	int menu = 0;
	while (!exit)
	{
		cout << "Choose the action:\n"
			<< "1. Add record\n"
			<< "2. Delete record\n"
			<< "3. Find record\n"
			<< "4. Show all records\n"
			<< "5. Sort records in phonebook\n"
			<< "6. Save phonebook to file\n"
			<< "7. Copy abonents from file\n"
			<< "8. Exit\n\n";
		cin >> menu;
		if (!cin)
		{
			cout << "Incorrect input, write only numbers\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		switch (menu)
		{
		case 1:
			AddRecordToPhoneBook(Head, Tail, counterAbonents);
			break;
		case 2:
			RemoveRecordFromPhoneBook(Head, Tail, counterAbonents);
			break;
		case 3:
			FindRecordInPhoneBook(Head);
			break;
		case 4:
			ShowRecordsFromPhoneBook(Head);
			break;
		case 5:
			SortRecordsInPhoneBook(Head, counterAbonents);
			break;
		case 6:
			SavePhoneBookToFile(Head);
			break;
		case 7:
			CopyPhonebookFromFile(Head, Tail, counterAbonents);
			break;
		case 8:
			exit = true;
			break;
		default:
			cout << "Incorrect input. Write only numbers from 1 to 8.\n";
			break;
		}
	}
}

void AddRecordToPhoneBook(Abonent* &Head, Abonent* &Tail, int &counterAbonents)
{
	cin.get();
	Abonent* temp = new Abonent;
	temp->InputNumber();
	if (!counterAbonents)
	{
		temp->next = Head;
		Head = temp;
		Tail = temp;
		temp->prev = Tail;
		temp->InputSurname();
		temp->InputName();
		counterAbonents++;
		cout << "Abonent added!\n\n";
		return;
	}
	if (IsNumberInPhoneBook(temp->number, Head))
	{
		cout << "Abonent is already exist!\n\n";
		delete temp;
		return;
	}
	temp->InputSurname();
	temp->InputName();
	temp->next = Head;
	Head->prev = temp;
	Head = temp;
	counterAbonents++;
	cout << "Abonent added!\n\n";
}

void RemoveRecordFromPhoneBook(Abonent* &Head, Abonent* &Tail, int &counterAbonents)   //Make a correct checking number thich isnt exist.
{
	if (!counterAbonents)
	{
		cout << "Phonebook is empty\n";
		return;
	}
	char number[12];
	cin.get();
	cout << "Write the number\n";
	cin.getline(number, 12);
	if (!IsNumberInPhoneBook(number, Head))
	{
		cout << "Abonent is not exist\n";
		return;
	}
	 if (counterAbonents == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		counterAbonents--;
		cout << "Abonent is removed\n";
		return;
	}
	 Abonent* temp = Head;
	 while (temp)
	 {
		 if (!_strcmpi(temp->number, number))
		 {
			 if (temp == Head)
			 {
				 Head = temp->next;
				 Head->prev = NULL;
				 delete temp;
				 counterAbonents--;
				 cout << "Abonent is removed\n";
				 return;
			 }
			 else if (temp == Tail)
			 {
				 Tail = temp->prev;
				 delete temp;
				 counterAbonents--;
				 cout << "Abonent is removed\n";
				 return;
			 }
			 Abonent* pNext = temp->next;
			 Abonent* pPrev = temp->prev;
			 pNext->prev = pPrev;
			 pPrev->next = pNext;
			 delete temp;
			 counterAbonents--;
			 cout << "Abonent is removed\n";
			 return;
		 }
		 temp = temp->next;
	 }
}

void FindRecordInPhoneBook(Abonent* &Head)
{
	if (!Head)
	{
		cout << "Phonebook is empty!\n";
		return;
	}
	char surnameOrNumber[20];
	cin.get();
	cout << "Write the surname or number: \n";
	cin.getline(surnameOrNumber, 20);
	while (!IsOnlyNumbers(surnameOrNumber) && !IsOnlyLetters(surnameOrNumber))
	{
		cout << "Write only numbers or only letters! Try again.\n";
		cin.getline(surnameOrNumber, 20);
	}
	if (IsOnlyNumbers(surnameOrNumber))
	{
		FindAbonentByNumber(Head, surnameOrNumber);
	}
	else if (IsOnlyLetters(surnameOrNumber))
	{
		FindAbonentBySurname(Head, surnameOrNumber);
	}
}

void FindAbonentByNumber(Abonent* &Head, char* number)
{
	Abonent* temp = Head;
	cout << endl << endl;
	while (temp)
	{
		if (!_stricmp(number, temp->number))
		{
			cout << endl << temp->surname << '\t' << temp->name
				<< '\t' << temp->number << endl;
		}
		temp = temp->next;
	}
	cout << endl << endl;
}

void FindAbonentBySurname(Abonent* &Head, char* surname)
{
	Abonent* temp = Head;
	cout << endl << endl;
	while (temp)
	{
		if (!_stricmp(surname, temp->surname))
		{
			cout << endl << temp->surname << '\t' << temp->name
				<< '\t' << temp->number << endl;
		}
		temp = temp->next;
	}
	cout << endl << endl;
}

void ShowRecordsFromPhoneBook(Abonent* &Head)
{
	if (!Head)
	{
		cout << "Phonebook is empty\n";
		return;
	}
	Abonent* temp = Head;
	cout << endl << endl;
	while (temp)
	{
		cout << endl << temp->surname << '\t' << temp->name
			<< '\t' << temp->number << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

void SortRecordsInPhoneBook(Abonent* &Head, int &counterAbonents)
{
	if (!counterAbonents)
	{
		cout << "Phonebook is empty!\n";
		return;
	}
	else if (counterAbonents == 1)
	{
		return;
	}
	bool sort = true;
	while (sort)
	{
		Abonent* temp = Head;
		sort = false;
		while (temp)
		{
			Abonent* pNext = temp->next;
			if (!pNext)
			{
				break;
			}
			if ((temp->surname[0]) > (pNext->surname[0]))
			{
				char number[12], name[10],
					surname[20];

				strcpy(number, temp->number);
				strcpy(name, temp->name);
				strcpy(surname, temp->surname);

				strcpy(temp->number, temp->next->number);
				strcpy(temp->name, temp->next->name);
				strcpy(temp->surname, temp->next->surname);

				strcpy(temp->next->number, number);
				strcpy(temp->next->name, name);
				strcpy(temp->next->surname, surname);
				sort = true;
			}
			temp = temp->next;
		}
	}
}

void SavePhoneBookToFile(Abonent* &Head)
{
	if (!Head)
	{
		cout << "Phonebook is empty\n";
		return;
	}
	Abonent* temp = Head;
	std::ofstream save("phone.dat");
	while (temp)
	{
		save << endl << temp->surname << '\t' << temp->name
			<< '\t' << temp->number << endl;
		temp = temp->next;
	}
	save.close();
}

void CopyPhonebookFromFile(Abonent* &Head, Abonent* &Tail, int &counterAbonents)
{
	std::ifstream copy("phone.dat");
	if (!copy)
	{
		cout << "File is not found!\n";
		return;
	}
	while (copy)
	{
		Abonent* temp = new Abonent;
		copy >> temp->surname >> temp->name >> temp->number;
		AddAbonentFromFile(Head, Tail, temp, counterAbonents);
	}
	cout << "Phonebook copied!\n";
}

void AddAbonentFromFile(Abonent* &Head, Abonent* &Tail, Abonent* &temp, int &counterAbonents)
{
	if (!counterAbonents)
	{
		temp->next = Head;
		Head = temp;
		Tail = temp;
		temp->prev = Tail;
		counterAbonents++;
		return;
	}
	if (IsNumberInPhoneBook(temp->number, Head))
	{
		delete temp;
		return;
	}
	temp->next = Head;
	Head->prev = temp;
	Head = temp;
	counterAbonents++;
}

bool IsNumberInPhoneBook(char* number, Abonent* &Head)
{
	Abonent* temp = Head;
	bool existInPhoneBook = false;
	while (temp)
	{
		if (!_stricmp(number, temp->number))
		{
			existInPhoneBook = true;
			return existInPhoneBook;
		}
		temp = temp->next;
	}
	return existInPhoneBook;
}

bool IsOnlyNumbers(char* number)
{
	int counter = 0;
	bool isNumber = true;
	while (number[counter])
	{
		if (number[counter] < '0' || number[counter] > '9')
		{
			isNumber = false;
		}
		counter++;
	}
	return isNumber;
}

bool IsOnlyLetters(char* nameSurname)
{
	int counter = 0;
	bool isLetter = true;
	while (nameSurname[counter])
	{
		if ((nameSurname[counter] >= 'A' && nameSurname[counter] <= 'Z') ||
			(nameSurname[counter] >= 'a' && nameSurname[counter] <= 'z'))
			isLetter = true;
		else
		{
			isLetter = false;
			break;
		}
		counter++;
	}
	return isLetter;
}
