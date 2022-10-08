#include <iostream>
using namespace std;

class Shop
{
  int itemId[10];
  int itemPrice[10];
  int counter;

public:
  void initCounter(void) { counter = 0; }
  void setPrice(void);
  void displayPrice(void);
};

void Shop ::setPrice(void)
{
  cout << "Enter id of your item number " << counter + 1 << ": ";
  cin >> itemId[counter];
  cout << "Enter price of item id " << itemId[counter] << ": ";
  cin >> itemPrice[counter];
  counter++;
}

void Shop ::displayPrice(void)
{
  for (int i = 0; i < counter; i++)
  {
    cout << "Price of item " << itemId[i] << ": " << itemPrice[i] << endl;
  }
}

int main()
{
  Shop s;
  s.initCounter();
  s.setPrice();
  s.setPrice();
  s.setPrice();
  s.displayPrice();

  return 0;
}