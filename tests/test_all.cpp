#include "../src/time.cpp"

#define BOOST_TEST_MODULE test_all
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_CASE (test_time_class) {
    Time timein(5, 46);
    BOOST_TEST(timein.hour == 5);
    BOOST_TEST(timein.minute == 46);
}
