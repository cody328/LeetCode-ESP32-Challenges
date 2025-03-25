#include <stdio.h>
#include <string.h>
#include <unity.h>

// Function to be tested
int romanToInt(char* s) {
    int values[256] = {0};
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    int len = strlen(s);
    int value = 0;
    int temp = 0;

    for (int i = len - 1; i >= 0; i--) {
        int currentValue = values[(unsigned char)s[i]];
        if (currentValue >= temp) {
            value += currentValue;
        } else {
            value -= currentValue;
        }
        temp = currentValue;
    }

    return value;
}

// Test cases
void test_romanToInt_III(void) {
    TEST_ASSERT_EQUAL(3, romanToInt("III"));
}

void test_romanToInt_LVIII(void) {
    TEST_ASSERT_EQUAL(58, romanToInt("LVIII"));
}

void test_romanToInt_MCMXCIV(void) {
    TEST_ASSERT_EQUAL(1994, romanToInt("MCMXCIV"));
}

void app_main(void) {

    UNITY_BEGIN();
    RUN_TEST(test_romanToInt_III);
    RUN_TEST(test_romanToInt_LVIII);
    RUN_TEST(test_romanToInt_MCMXCIV);
    UNITY_END();
}
