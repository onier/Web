/*Copyright (c) 2020 - 2022 xuzhenhai <282052309@qq.com>

This file is part of puppy builder
   License: MIT License

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */
#include <string>
#include <rttr/registration.h>
#include <ostream>

struct Parameter {
    std::string name;
    int age;

    Parameter();

    friend std::ostream &operator<<(std::ostream &os, const Parameter &parameter) {
        os << "name: " << parameter.name << " age: " << parameter.age;
        return os;
    }

RTTR_ENABLE();
};

struct Result : Parameter {
    std::string result;

    Result();

RTTR_ENABLE(Parameter);
};

struct TestAPI {
    TestAPI();

    virtual Result call(Parameter parameter) = 0;

    virtual ~TestAPI() {};

    virtual void test() = 0;
};