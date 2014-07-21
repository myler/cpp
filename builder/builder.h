#ifndef BUILDER_H
#define BUILDER_H

class Builder
{
public:
  Builder();
  virtual ~Builder() {}

  virtual void build_part_a() = 0;
  virtual void build_part_b() = 0;
};

#endif // BUILDER_H
