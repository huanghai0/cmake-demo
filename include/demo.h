#ifndef DEMO_H
#define DEMO_H

#include <string>

namespace demo
{

    class Calculator
    {
    public:
        Calculator() = default;

        int add(int a, int b);
        int subtract(int a, int b);
        int multiply(int a, int b);
        double divide(int a, int b);

        void printInfo() const;

    private:
        std::string name = "Calculator";
    };

    void greet(const std::string &name);

    constexpr int MAX_VALUE = 100;

} // namespace demo

#endif // DEMO_H
