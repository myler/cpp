#include "factory.h"
#include "product.h"

using namespace std;

int main()
{
  AbstractFactory *af_1 = new Factory_1();
  AbstractFactory *af_2 = new Factory_2();

  AbstractProduct_A *pa_1 = af_1->Produce_A();
  AbstractProduct_A *pa_2 = af_2->Produce_A();
  pa_1->Sell();
  pa_2->Sell();

  AbstractProduct_B *pb_1 = af_1->Produce_B();
  AbstractProduct_B *pb_2 = af_2->Produce_B();
  pb_1->Sell();
  pb_2->Sell();

  return 0;
}

