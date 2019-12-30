#include "catch.hpp"
#include "application/Application.hpp"

TEST_CASE("Application Test Suite", "[Sample]")
{
    SECTION("should_return_lucky_number_as_initialized")
    {
        app::Application app(19);
        const int luckyNumber = app.getLuckyNumber();
        REQUIRE(luckyNumber == 19);
    }
}