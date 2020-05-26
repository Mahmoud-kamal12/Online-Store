#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Adress
{
public:
	string city;
	int streatNo;
};

class Date
{
public:
	int day, month, year;
};

class Products
{
public:
	int id;
	string name;
	float Price;
	float Discount;
	float netPrice;
	int Quantity;
	static void showProduct(Products p[], int numer_of_products);
	static void showorders(Products p[], int num, double& total);
};

class customer : public Adress, public Date
{
private:
	string fname;
	string lname;
	int Phone;
	string email;

public:
	void setfName(string fname);
	void setlName(string lname);
	void setEmail(string email);
	void setPhone(int phone);

	string getfNmae();
	string getlName();
	string getemail();
	int getphone();

	void AddUser();
	void showcustinfo();


};

class Payment : public Date
{
public:
	virtual void showpaymentinfo() {};
	virtual void addPayment() {};
};

class Visa : public Payment
{
public:
	string CardNumber;
	string CardholderName;
	string cvv;
	void showpaymentinfo();
	void addPayment();
};

class PayPal : public Payment
{
public:
	string email;
	string pass;
	void showpaymentinfo();
	void addPayment();
};
