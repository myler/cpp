#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "builder.h"

class Director
{
private:
  Builder *m_pBuilder;
public:
  Director(Builder *pBuilder);
  ~Director();

  void Construct();
};

#endif // DIRECTOR_H
