#include "factory.h"

AbstractProduct_A *Factory_1::Produce_A()
{
  return new Product_A1();
}

AbstractProduct_B *Factory_1::Produce_B()
{
  return new Product_B1();
}

AbstractProduct_A *Factory_2::Produce_A()
{
  return new Product_A2();
}

AbstractProduct_B *Factory_2::Produce_B()
{
  return new Product_B2();
}
