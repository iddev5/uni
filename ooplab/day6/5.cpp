#include <iostream>
#include <string>
using namespace std;

class Product {
  string name_of_prod;
  int qty_purchased;
  int price;
  int total_price;
public:
  Product(string name, int qty, int pri) {
    name_of_prod = name;
    qty_purchased = qty;
    price = pri;
    total_price = qty_purchased * price;
  }

  int get_total_price() {
    return total_price;
  }

  void display() {
    cout << "Name of product: " << name_of_prod << endl;
    cout << "Quantity purchased: " << qty_purchased << endl;
    cout << "Price of product: " << price << endl;
    cout << "Total price of products: " << total_price << endl;
  }
};

class SalesTax: public Product {
  int rate_of_sales_tax;
  int total_amount;
public:
  SalesTax(string name, int qty, int price, int rate):
    Product(name, qty, price) 
  {
    rate_of_sales_tax = rate;
    total_amount = (1 + rate / 100.0) * get_total_price();  
  }

  void display() {
    Product::display();
    cout << "Rate of sales tax: " << rate_of_sales_tax << endl;
    cout << "Total amount: " << total_amount << endl;
  }
};

int main() {
  string name;
  int qty, price, rate;
  
  cout << "Enter name: ";
  cin >> name;

  cout << "Enter quantity: ";
  cin >> qty;

  cout << "Enter price: ";
  cin >> price;

  cout << "Enter rate of sales tax: ";
  cin >> rate;

  SalesTax st(name, qty, price, rate);
  st.display();

  return 0;
}