#ifndef CONCREATEBUILDERA_H
#define CONCREATEBUILDERA_H

#include "builder.h"

class ConcreateBuilderA : public Builder
{
public:
  ConcreateBuilderA() {}
  virtual ~ConcreateBuilderA() {}

  virtual void build_part_a();
  virtual void build_part_b();
};

#endif // CONCREATEBUILDERA_H
