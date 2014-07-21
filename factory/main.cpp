#include <iostream>
#include "factory.h"
#include "product.h"

using namespace std;

int main()
{
  Factory *f = new myFactory();
  Product *p1 = f->Produce(1);
  Product *p2 = f->Produce(2);

  p1->Sell();
  p2->Sell();

  return 0;
}
