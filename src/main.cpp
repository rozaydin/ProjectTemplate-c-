#include "sample_project/Application.h"

using namespace std;

int main(int argc, char **argv) {

    // initialize logging
    app::initLogging();

    const string banner = Misc::Banner::loadBannerTextFromFile("./resource/Banner.txt");
    BOOST_LOG_TRIVIAL(info) << banner << endl;
    cout << banner << endl;
    BOOST_LOG_TRIVIAL(info) << "Starting application ....";


    BOOST_LOG_TRIVIAL(info) << "Shutting down application ....";
    return EXIT_SUCCESS;
}