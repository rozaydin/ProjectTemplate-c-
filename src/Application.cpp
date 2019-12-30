#include "application/Banner.hpp"
#include "application/Application.hpp"

int app::Application::getLuckyNumber() const {
    return this->luckyNumber;
}

void app::Application::doSth(int somenumber) {
    std::cout << "Hello people!" << std::endl;
}