#include <stdio.h>
#include "myClass.h"
#include "emscripten/bind.h"

using namespace emscripten;

class MyClass
{
public:
  MyClass(int num) { m_num = num; };

  void CompareBig(int x, int y)
  {
    printf("Big one is %d\n", x > y ? x : y);
  }

  static int getNum(MyClass &instance)
  {
    return instance.printfNum();
  }

  int getNumValue() const
  {
    printf("getNumvalue:%d\n", m_num);
    return m_num;
  }

  void setNum(int num)
  {
    printf("setNum:%d\n", num);
    m_num = num;
  }

private:
  int printfNum()
  {
    return m_num;
  }

private:
  int m_num;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example)
{
  class_<MyClass>("MyClass")
      .constructor<int>()                           //构造函数
      .function("CompareBig", &MyClass::CompareBig) //普通类成员函数
      .property("m_num", &MyClass::getNumValue, &MyClass::setNum)
      .class_function("getNum", &MyClass::getNum) //静态类成员函数
      ;
}
