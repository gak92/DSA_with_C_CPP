#include<iostream>
using namespace std;

class ShopItem
{
  int id;
  float price;
  public:
    void setData(int a, int b)
    {
      id = a;
      price = b;
    }
    void getData(void)
    {
      cout << "Code of item: " << id << endl;
      cout << "Price of item: " << price << endl;
    }
}; 

int main()
{
  int size = 3;
  ShopItem *item = new ShopItem[size];
  ShopItem *itemTemp = item;
  int p;
  float q;

  for(int i=0; i<size; i++)
  {
    cout << "Enter id and price of an item: " << i+1 << endl;
    cin >>  p >> q;

    // (*item).setData(p, q);
    item->setData(p, q);
    item++;
  }

  for(int i=0; i<size; i++)
  {
    cout << "Item Number: " << i+1 << endl;
    itemTemp->getData();
    itemTemp++;
  }

  return 0;
}