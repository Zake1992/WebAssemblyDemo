#include <iostream>
// #include "myClass.h"

#include "emscripten/bind.h"

// using namespace std;
// #include "emscripten/bind.h"
using namespace emscripten;

class ClassTest
{
public:
    ClassTest(int x, std::string y)
        : x(x), y(y)
    {
    }

    void incrementX()
    {
        ++x;
    }

    int getX() const { return x; }
    void setX(int x_) { x = x_; }

    static std::string getStringFromInstance(const ClassTest &instance)
    {
        return instance.y;
    }

private:
    int x;
    std::string y;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example)
{
    class_<ClassTest>("ClassTest")
        .constructor<int, std::string>()
        .function("incrementX", &ClassTest::incrementX)
        .property("x", &ClassTest::getX, &ClassTest::setX)
        .class_function("getStringFromInstance", &ClassTest::getStringFromInstance);
}