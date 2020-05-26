#include"Class.h"

const int numer_of_products = 3;
void addproducts(Products p[]);
void enter_id(Products order[], Products pro[], int num, int start);
Products* dele(Products order[], int index, int& size);
int main()
{

	customer cust;	Products* pro = new Products[numer_of_products], * orders = new Products[1000];	int* arr = nullptr;
	Payment* ptr = nullptr;	Visa v;		PayPal p;
	int start, n, c, py, op, size;
	double Total_Price = 0;
	addproducts(pro);


	Products::showProduct(pro, numer_of_products);

	cout << "\n=============================================================\n";

	cout << "Enter number of product1s you will buy  = ";
	cin >> size;

	enter_id(orders, pro, 0, size);

	cout << "\n\n=============================================================\n";

	cust.AddUser();

	cout << "\t\t\t\t 1)Visa \n\t\t\t\t 2)PayPal \n\nEnter Payment (1-2) = ";
	cin >> py;
	if (py == 1)
	{
		ptr = &v;
		ptr->addPayment();
	}
	else if (py == 2)
	{
		ptr = &p;
		ptr->addPayment();
	}
	else
	{
		cout << "Enter correct chose" << endl;
		exit(0);
	}

	do
	{
		start = 0;
		cout << "\n \t\t\t\t1)show your info\n \t\t\t\t2)show Visa Or PayPal info \n \t\t\t\t3)show Orders info \n\nEnter chose (1-3) = ";
		cin >> c;
		switch (c)
		{
		case 1:
			cust.showcustinfo();
			cout << "\n\n\t\t\t\t1)UpData Your Information \n \t\t\t\t2)Retern \n \t\t\t\t0)Exit  \n\nEnter chose  = ";
			cin >> c;
			if (c == 1)
			{
				cust.AddUser();
				op = 1;
			}
			else if (c == 2)
			{
				op = 1;
			}
			else if (c == 0)
			{
				exit(0);
			}
			else
			{
				exit(0);
			}

			break;
		case 2:
			if (py == 1)
			{
				ptr = &v;
				ptr->showpaymentinfo();
			}
			else
			{
				ptr = &p;
				ptr->showpaymentinfo();
			}

			cout << "\n\n\t\t\t\t1)UpData Your Information \n \t\t\t\t2)Retern \n \t\t\t\t0)Exit  \n\nEnter chose  = ";
			cin >> c;
			if (c == 1)
			{
				if (py == 1)
				{
					ptr = &v;
					ptr->addPayment();
				}
				else if (py == 2)
				{
					ptr = &p;
					ptr->addPayment();
				}
				op = 1;
			}
			else if (c == 2)
			{
				op = 1;
			}
			else if (c == 0)
			{
				exit(0);
			}
			else
			{
				exit(0);
			}
			break;
		case 3:
			Total_Price = 0;
			Products::showorders(orders, size, Total_Price);
			cout << "\n\n\t\t\t\t Total Prise = " << Total_Price << endl;
			cout << "\n\n\t\t\t\t1)Add Product \n \t\t\t\t2)Delet Product \n\nEnter chose (1-2) = ";
			cin >> c;
			if (c == 1)
			{
				system("cls");
				Products::showProduct(pro, numer_of_products);
				cout << "\n=============================================================\n";
				cout << "Enter number of product1s you will buy  = ";
				cin >> start;
				int s = size;
				size += start;
				enter_id(orders, pro, s, size);
				op = 1;

			}
			else if (c == 2)
			{
				Products::showorders(orders, size, Total_Price);
				cout << "\n=============================================================\n";
				int y;
				cout << "Enter id of prodect to delet it from your order list = ";
				cin >> y;
				orders = dele(orders, y, size);
				cout << "\n\n\t\t\t\tDelet doon\n" << endl;
				op = 1;
			}
			else
			{
				cout << "Enter correct chose" << endl;
				exit(0);
			}
			break;

		default:
			cout << "Enter correct chose" << endl;
			exit(0);
			break;
		}
	} while (op == 1);


	delete ptr, cust, Total_Price, pro, arr, py;
}

void addproducts(Products p[])
{
	p[0].id = 1;
	p[0].name = "product1";
	p[0].Discount = .15;
	p[0].Price = 10000;
	p[0].netPrice = p[0].Price - (p[0].Price * p[0].Discount);

	p[1].id = 2;
	p[1].name = "product2";
	p[1].Discount = .10;
	p[1].Price = 1000;
	p[1].netPrice = p[1].Price - (p[1].Price * p[1].Discount);

	p[2].id = 3;
	p[2].name = "product3";
	p[2].Discount = .10;
	p[2].Price = 1000;
	p[2].netPrice = p[2].Price - (p[2].Price * p[2].Discount);
}

void enter_id(Products order[], Products pro[], int start, int num)
{
	for (int i = start; i < num; i++)
	{
		int id, z = 0, q;
		cout << "Enter ID of product you will buy  = ";
		cin >> id;
		cout << "Enter Quantity of product : ";
		cin >> q;
		for (int j = 0; j < numer_of_products; j++)
		{
			if (pro[j].id == id)
			{
				z++;
				order[i].id = pro[j].id;
				order[i].name = pro[j].name;
				order[i].Discount = pro[j].Discount;
				order[i].Price = pro[j].Price;
				order[i].netPrice = pro[j].netPrice;
				order[i].Quantity = q;
				break;
			}
		}
		if (z == 0)
		{
			cout << "\n\t\t\t\tEnter correct id" << endl << "\t\t\t\tTry Adain\n " << endl;
			i--;
		}

	}

}

Products* dele(Products order[], int index, int& size)
{
	static Products* p = new Products[size - 1];
	int u = size;
	for (int i = 0, x = 0; i < u; i++, x++)
	{
		if (order[i].id == index)
		{
			x--;
			size--;
			continue;
		}
		else
		{
			p[x].id = order[i].id;
			p[x].Price = order[i].Price;
			p[x].Discount = order[i].Discount;
			p[x].netPrice = order[i].netPrice;
			p[x].Quantity = order[i].Quantity;
			p[x].name = order[i].name;
		}
	}

	return p;
}