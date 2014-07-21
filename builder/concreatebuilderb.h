#ifndef CONCREATEBUILDERB_H
#define CONCREATEBUILDERB_H

#include "builder.h"

class ConcreateBuilderB : public Builder
{
public:
  ConcreateBuilderB() {}
  virtual ~ConcreateBuilderB() {}

  virtual void build_part_a();
  virtual void build_part_b();
};

#endif // CONCREATEBUILDERB_H
