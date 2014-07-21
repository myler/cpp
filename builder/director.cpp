#include "director.h"

Director::Director(Builder *pBuilder) : m_pBuilder(pBuilder) {}

Director::~Director()
{
  delete m_pBuilder;
  m_pBuilder = nullptr;
}

void Director::Construct()
{
  m_pBuilder->build_part_a();
  m_pBuilder->build_part_b();
}
