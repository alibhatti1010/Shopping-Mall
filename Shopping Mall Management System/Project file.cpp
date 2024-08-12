#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"Queue header.h"
#include"Style and colours.h"
#include"Stack Header.h"
using namespace std;

int search(int);
int display();
string check(int);


struct node
{
	int ID;
	string productName;
	double Price;
	int quantity;
	node* next;
};

struct node *head = NULL;



void newEntry()
{
	system("cls");
	int id, Quantity;
	string name;
	double price;
	struct node *ptr = new node;
	struct node *p = head;

	cout << "\t\t\tEnter product ID:-";
	cin >> id;
			Beep(2000, 90);
	ptr->ID = id;
	cout << "\t\t\tEnter product Name:-";
	cin >> name;
			Beep(2000, 90);
	ptr->productName = name;
	cout << "\t\t\tEnter product price:-";
	cin >> price;
			Beep(2000, 90);
	ptr->Price = price;
	cout << "\t\t\tEnter product quantity:-";
	cin >> Quantity;
			Beep(2000, 90);
	ptr->quantity = Quantity;
	if (head == NULL)
	{
		ptr->next = head;
		head = ptr;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = NULL;

	}
	system("cls");
	cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";

}


int search(int id)
{
	int count = 1;
	struct node *p = head;
	while (p != NULL)
	{
		if (p->ID == id)
			break;
		else
			count++;
		p = p->next;
	}
	return count;
}


void deleteProduct()
{
	system("cls");
	display();
			Beep(2000, 90);
	int id;
	node *current = head;
	node *previous = head;
	cout << "\n\nEnter ID to delete product:\n\n";
	cin >> id;
			Beep(2000, 90);
	if (head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	int pos = 0;
	int count = display();              
	pos = search(id);                       
	if (pos <= count){

		while (current->ID != id){
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		system("cls");
		cout << "\n<<Item is deleted successfully>>\n";
	}
	else{
		cout << "\n<<<Not available>>\n\n";
	}
}


void update()
{
	int id;
	double price;
	string pName;
	int new_id; int n_quantity;
	if (head == NULL)
	{
		system("cls");
		cout << "No Products" << endl;
	}
	else
	{
		display();
				Beep(2000, 90);
		cout << "\n\nEnter ID to modify product Name and its price:\n";
		cin >> id;
				Beep(2000, 90);
		struct node *cur = head;
		int pos = 0;
		int count = display();
		pos = search(id);
		if (pos <= count)
		{
			while (cur->ID != id)
			{
				cur = cur->next;
			}
			cout << "\nOld ID : " << cur->ID << endl;
			cout << "\nOld Name : " << cur->productName << endl;
			cout << "\nOld Price : " << cur->Price << endl;
			cout << "\nOld Quantity : " << cur->quantity << endl;

			cout << endl << endl;
			cout << "Enter new ID:";
			cin >> new_id;
			cur->ID = new_id;
			cout << "Enter new Name:";
			cin >> pName;
			cur->productName = pName;
			cout << "Enter new Price:";
			cin >> price;
			cur->Price = price;
			cout << "Enter new Quantity:";
			cin >> n_quantity;
			cur->quantity = n_quantity;
		}

		else
		{
			cout << id << " is <<<Not found>>\n\n";
		}
	}
}


int display()
{
	system("cls");
	int c = 0;            
	struct node *p = head;
	cout << "Existing products are:\n";
	cout << "ID\t\tProduct Name\t\t Price\t\tQuantity\n";
	cout << "=================================================================|\n";
	while (p != NULL)
	{
		cout << p->ID << "\t\t" << p->productName << "\t\t\t" << p->Price << "\t\t\t" << check(p->quantity) << "\n";
		p = p->next;
		c = c + 1;
	}
	cout << "\nTotal products in our store is : " << c << "\n\n\n";
	return c;
}

string check(int quant)

{         
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

	if (quant <= 0)
		return "out of stock!";
	else
		return quantity;
}

void buy()
{
	system("cls");
	display();
	string products[20];

	int pay = 0, num, cur = 0, price, id, i = 1;

	if (head == NULL)
	{
		cout << "\n<<<<There is no items to buy>>>>\n\n";
	}
	else
	{
		cout << "How many items you wanna to buy!\n";
		cin >> num;
				Beep(2000, 90);
		int count = display();
		while (i <= num)
		{
			struct node *current = head;
			int Quantity, choice;   a:          
			cout << "Enter id of item that you want to buy: ";
			int id, pos = 0;
			cin >> id;
					Beep(2000, 90);
			if (id == -1){ 
			system("cls"); 
			return; 
			}
			pos = search(id);
			if (pos <= count)
			{
				while (current->ID != id)
				{
					current = current->next;
				}
				cout << "How many quantities you want:";
				cin >> Quantity;
				if (current->quantity<Quantity)
				{
					cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;

				}
				products[cur] = current->productName; 
				cur++;

				pay = pay + (current->Price*Quantity);         
				current->quantity = current->quantity -Quantity;   
				i++;

			}
			else
			{

				cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

			}
		}
		string customer;
		cout << "\n\t\t Enter Your Name :"; 
		cin >> customer;
				Beep(2000, 90);
		enqueue(customer);
		system("cls");
		cout << "\n\n\n\n\t\t\tYou bought : ";
		for (int i = 0; i<num; i++)
		{              
			cout << products[i] << ",";
		}
		price = pay*(0.90);
		cout << "\n\nOriginal price: " << (pay);
		cout << "\n Sale price: " << (price)<< "\nThank you! for shopping\n\n";




	}
}


void administator()
{
	
	system("cls");
	int ch;


	do {

		cout << "\t\t============================================" << endl;
		cout << "\t\t|          Administation              |" << endl;
		cout << "\t\t============================================" << endl;

		cout << "\t\t     Enter 1 for Add a new product    " << endl;
		cout << "\t\t     Enter 2 to Display all products   " << endl;
		cout << "\t\t     Enter 3 for Update existing products" << endl;
		cout << "\t\t     Enter 4 for Delete a product" << endl;
		cout << "\t\t     Enter 5 for Customers list " << endl;
		cout << "\t\t     Enter 6 for Dequeue customer" << endl;
		cout << "\t\t     Enter 0 for Main Menu" << endl;


		cout << "\nEnter Your choice >>>";  
		cin >> ch;
				Beep(2000, 90);
		switch (ch){
		case 1:
			newEntry();
					Beep(2000, 90);
			break;
		case 2:
			system("cls");
			display();
					Beep(2000, 90);
			break;
		case 3:
			update();
					Beep(2000, 90);
			system("cls");
			
			break;
		case 4:
			deleteProduct();
					Beep(2000, 90);
			cout << "\n-------Product is Deleted-------\n";
			break;
		case 5:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			displayQueue();
					Beep(2000, 90);
			break;
		case 6:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			dequeue();
					Beep(2000, 90);
			displayQueue();
			break;
			
		default: 
		system("cls");

		}
	} while (ch != 0);
}


int main()
{

	for (int i = 0; i <= 51; i++)
	{

		push(i);
	}


	system("color F1");
	gotoxy(17, 5);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 7);
	cout << "||            Shopping Mall Management System                ||" << endl;
	gotoxy(17, 9);
	cout << "--------------------------------------------------" << endl;
	gotoxy(17, 11);
			Beep(3000, 1000);
	system("pause");
	system("cls");
	system("color Fc");

	int ch;
	while (ch != 3){



		cout << "\n\t\t|--------<Main Menu>-----------|";
		cout << "\n\n";
		cout << "\t\t 1)Administator of Market\n";
		cout << "\t\t 2)Customer               \n";
		cout << "\t\t 3)Exit                    \n";



		cout << "\nEnter Your choice >>>"; cin >> ch;
				Beep(2000, 90);
		switch (ch){
		case 1:


			administator();
					Beep(2000, 90);
			break;

		case 2:
			cout << endl << endl;
			bpop();
					Beep(2000, 90);
			system("pause");
			buy();
					Beep(2000, 90);
			break;

		case 3:
			cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
			break;

		}
	}
	return 0;
}






