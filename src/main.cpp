#include "application/Application.hpp"
#include "application/Banner.hpp"

using namespace std;

int main(int argc, char **argv) {

    const string banner = Misc::Banner::loadBannerTextFromFile("./Banner.txt");        
    std::cout << banner << std::endl;
    app::Application app(19);

    std::cout << "Lucky number: " << app.getLuckyNumber() << std::endl;
    return EXIT_SUCCESS;

}