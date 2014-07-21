#ifndef PRODUCT_H
#define PRODUCT_H

class AbstractProduct_A
{
protected:
  AbstractProduct_A() {}
public:
  virtual ~AbstractProduct_A() {}
  virtual void Sell() const = 0;
};

class AbstractProduct_B
{
protected:
  AbstractProduct_B() {}
public:
  virtual ~AbstractProduct_B() {}
  virtual void Sell() const = 0;
};

class Product_A1 : public AbstractProduct_A
{
public:
  Product_A1() {}
  virtual void Sell() const;
};

class Product_A2 : public AbstractProduct_A
{
public:
  Product_A2() {}
  virtual void Sell() const;
};

class Product_B1 : public AbstractProduct_B
{
public:
  Product_B1() {}
  virtual void Sell() const;
};

class Product_B2 : public AbstractProduct_B
{
public:
  Product_B2() {}
  virtual void Sell() const;
};

#endif // PRODUCT_H
