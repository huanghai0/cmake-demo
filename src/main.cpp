#include <iostream>
#include <string>
#include "demo.h"
#include "ThreadPool.h"
#include "httplib.h"
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
// 实现头文件中声明的函数
namespace demo
{

    int Calculator::add(int a, int b)
    {
        return a + b;
    }

    int Calculator::subtract(int a, int b)
    {
        return a - b;
    }

    int Calculator::multiply(int a, int b)
    {
        return a * b;
    }

    double Calculator::divide(int a, int b)
    {
        if (b == 0)
        {
            return 0.0;
        }
        return static_cast<double>(a) / b;
    }

    void Calculator::printInfo() const
    {
        std::cout << "Calculator name: " << name << std::endl;
    }

    void greet(const std::string &name)
    {
        std::cout << "Hello, " << name << "! Welcome to CMakeDemo." << std::endl;
    }

} // namespace demo

int main()
{
    using json = nlohmann::json;

    json j;
    j["name"] = "CMakeDemo";
    j["version"] = "1.0.0";
    std::cout << j.dump(4) << std::endl;

    spdlog::info("This is an info message from spdlog");

    httplib::Server svr;
    svr.Get("/", [](const httplib::Request &, httplib::Response &res)
            { res.set_content("Hello from CMakeDemo HTTP server!", "text/plain"); });
    std::cout << "Starting server on port 8080..." << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
