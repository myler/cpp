#ifndef FACTORY_H
#define FACTORY_H

#include "product.h"

class Factory
{
protected:
  Factory() {}
public:
  virtual ~Factory() {}
  virtual Product *Produce(int i) = 0;
};

class myFactory : public Factory
{
public:
  myFactory() {}
  virtual Product *Produce(int i);
};

Product *myFactory::Produce(int i)
{
  switch (i) {
    case 1:
      return new myProduct1();
      break;
    case 2:
      return new myProduct2();
    default:
      break;
    }
}

#endif // FACTORY_H
