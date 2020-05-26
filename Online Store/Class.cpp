#include "Class.h"

void customer::setfName(string fname)
{
	this->fname = fname;
}

void customer::setlName(string lname)
{
	this->lname = lname;
}

void customer::setEmail(string email)
{
	this->email = email;
}

void customer::setPhone(int phone)
{
	this->Phone = phone;
}

string customer::getfNmae()
{
	return this->fname;
}

string customer::getlName()
{
	return this->lname;
}

string customer::getemail()
{
	return this->email;
}

int customer::getphone()
{
	return this->Phone;
}

void customer::AddUser()
{
	string s;
	int n;
	system("cls");
	cout << "\n\t\t\t\t		Enter your information \n";
	cout << "First Name : ";
	cin >> s;	setfName(s);
	cout << "Last Name : ";
	cin >> s;	setlName(s);
	cout << "Email : ";
	cin >> s;	setEmail(s);
	cout << "Phone : ";
	cin >> n;	setPhone(n);
	cout << "City : ";
	cin >> city;
	cout << "streat No : ";
	cin >> streatNo;
	cout << "\t\t\t\t Time that you want to reseve order in it . " << endl;
	cout << "Day : ";
	cin >> day;
	cout << "Month : ";
	cin >> month;
	cout << "Year : ";
	cin >> year;

}

void customer::showcustinfo()
{

	system("cls");
	cout << "\n\t\t\t\t		your information \n";
	cout << "First Name is : " << getfNmae() << endl;
	cout << "Last Name is : " << getlName() << endl;
	cout << "Email is : " << getemail() << endl;
	cout << "Phone is : " << getphone() << endl;
	cout << "City : " << city << endl;
	cout << "streat No : " << streatNo << endl;
	cout << "Day : " << day << endl;
	cout << "Month : " << month << endl;
	cout << "Year : " << year << endl;

}

void Products::showProduct(Products p[], int numer_of_products)
{
	cout << "id" << "\t" << setw(20) << "Name Of Product" << "\t" << setw(20) << "Price Of Product" << "\t" << setw(20) << "Discount" << "\t" << setw(20) << "Net Price" << endl;
	for (int i = 0; i < numer_of_products; i++)
	{
		cout << p[i].id << "\t" << setw(20) << p[i].name << "\t" << setw(20) << p[i].Price << "\t" << setw(20) << p[i].Discount << "\t" << setw(20) << p[i].netPrice << endl;
	}
}

void Products::showorders(Products p[], int num, double& total)
{
	cout << "id" << "\t" << setw(20) << "Name Of Product" << "\t" << setw(20) << "Price Of Product" << "\t" << setw(20) << "Discount" << "\t" << setw(20) << "Net Price" << "\t" << setw(20) << "Quantity" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << p[i].id << "\t" << setw(20) << p[i].name << "\t" << setw(20) << p[i].Price << "\t" << setw(20) << p[i].Discount << "\t" << setw(20) << p[i].netPrice << "\t" << setw(20) << p[i].Quantity << endl;
		total += (p[i].netPrice * p[i].Quantity);
	}
}

void Visa::showpaymentinfo()
{
	cout << "\n\t\t\t\tVisa information \n";
	cout << "Card holder Name is : " << CardholderName << endl;
	cout << "Card Number is : " << CardNumber << endl;
	cout << "cvv is : " << cvv << endl;
	cout << "ExpiryDate month is : " << month << endl;
	cout << "ExpiryDate year is : " << year << endl;

}

void Visa::addPayment()
{
	cout << "\n\nCard holder Name : ";
	cin >> CardholderName;
	cout << "Card Number : ";
	cin >> CardNumber;
	cout << "cvv : ";
	cin >> cvv;
	cout << "ExpiryDate month : ";
	cin >> month;
	cout << "ExpiryDate year : ";
	cin >> year;
}

void PayPal::showpaymentinfo()
{
	cout << "\n\t\t\t\tPayPal information \n";
	cout << "Email is : " << email << endl;
	cout << "Password is : " << pass << endl;
}

void PayPal::addPayment()
{
	cout << "\n\nEmail : ";
	cin >> email;
	cout << "Password : ";
	cin >> pass;
}
