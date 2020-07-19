#include "../src/time.cpp"
#include "../src/punchtime.cpp"

#define BOOST_TEST_MODULE test_all
#include <boost/test/included/unit_test.hpp>


// Time class
BOOST_AUTO_TEST_CASE (test_time_class) {
    Time timein(5, 46);

    BOOST_CHECK_EQUAL(timein.hour, 5);
    BOOST_CHECK_EQUAL(timein.minute, 46);
}

// Punchtime class
BOOST_AUTO_TEST_CASE (test_punchtime_class_default_values) {
    Punchtime defaultTime;

    BOOST_CHECK_EQUAL(defaultTime.workingHours, 9);
}

BOOST_AUTO_TEST_CASE (test_punchtime_setTimeout_function) {
    Punchtime testPunchtime;
    testPunchtime.setTimeout(5, 30);

    BOOST_CHECK_EQUAL(testPunchtime.out_hour, 2);
    BOOST_CHECK_EQUAL(testPunchtime.out_minute, 30);
}

BOOST_AUTO_TEST_CASE (test_punchtime_setBreaktime_function) {
    Punchtime testBreaktime;
    testBreaktime.setBreaktime(11, 0, 1, 30);

    BOOST_CHECK_EQUAL(testBreaktime.break_hour, 12);
    BOOST_CHECK_EQUAL(testBreaktime.break_minute, 30);
}

BOOST_AUTO_TEST_CASE (test_punchtime_setOvertime_function) {
    Punchtime testOvertime;
    testOvertime.setTimeout(5, 30);
    testOvertime.setOvertime(1);

    BOOST_CHECK_EQUAL(testOvertime.out_hour, 3);
}