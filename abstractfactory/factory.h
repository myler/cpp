#ifndef FACTORY_H
#define FACTORY_H

#include "product.h"

class AbstractFactory
{
protected:
  AbstractFactory() {}
public:
  virtual ~AbstractFactory() {}
  virtual AbstractProduct_A *Produce_A() = 0;
  virtual AbstractProduct_B *Produce_B() = 0;
};

class Factory_1 : public AbstractFactory
{
public:
  Factory_1() {}
  virtual AbstractProduct_A *Produce_A();
  virtual AbstractProduct_B *Produce_B();
};

class Factory_2 : public AbstractFactory
{
public:
  Factory_2() {}
  virtual AbstractProduct_A *Produce_A();
  virtual AbstractProduct_B *Produce_B();
};

#endif // FACTORY_H
