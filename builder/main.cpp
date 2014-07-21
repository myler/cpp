#include <iostream>
#include "builder.h"
#include "concreatebuildera.h"
#include "concreatebuilderb.h"
#include "director.h"

using namespace std;

int main()
{
  Builder *p1 = new ConcreateBuilderA();
  Director *d1 = new Director(p1);
  d1->Construct();

  Builder *p2 = new ConcreateBuilderB();
  Director *d2 = new Director(p2);
  d2->Construct();

  delete d1, d2;

  return 0;
}

