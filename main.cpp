//#include <iostream>
//#include <vector>
#include <gtest/gtest.h>
//#include <algorithm>

#include "dzS1.h"
#include "tests.h"
//#include <sstream>

using namespace std;


int main(int argc, const char ** argv) {

    // ---Task 2
    // 1. Установить фреймворк Google Test.
    // 2. Добавить unit-тесты в проект из первого урока..

  //  dzS1();

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
