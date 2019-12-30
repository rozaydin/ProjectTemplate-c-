#pragma once

// C++ standard libs
#include <iostream>
#include <string>

namespace app
{

class Application
{

private:
    const int luckyNumber;

public:
    Application(int luckyNumber) : luckyNumber(luckyNumber)
    {
    }

    int getLuckyNumber() const;

    void doSth(int somenum);
};

} // namespace app