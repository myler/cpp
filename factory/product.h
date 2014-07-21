#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
protected:
  Product() {}
public:
  virtual ~Product() {}
  virtual void Sell() = 0;
};

class myProduct1 : public Product
{
public:
  myProduct1() {}
  virtual void Sell();
};

class myProduct2 : public Product
{
public:
  myProduct2() {}
  virtual void Sell();
};

void myProduct1::Sell()
{
  std::cout << "Sell product1.\n";
}

void myProduct2::Sell()
{
  std::cout << "Sell product2.\n";
}

#endif // PRODUCT_H
