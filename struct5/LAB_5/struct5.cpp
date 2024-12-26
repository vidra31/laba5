#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "struct3.cpp"

TEST_CASE("Check if OneList is empty after creation") {
    OneList<int> lst;
    REQUIRE(lst.empty());
    REQUIRE(lst.size() == 0);
}

TEST_CASE("Adding single element to the front of OneList") {
    OneList<int> lst;
    lst.push_front(5);
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.front() == 5);
    REQUIRE(lst.back() == 5);
}

TEST_CASE("Adding single element to the back of OneList") {
    OneList<int> lst;
    lst.push_back(10);
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.front() == 10);
    REQUIRE(lst.back() == 10);
}

TEST_CASE("Adding elements at both ends of OneList") {
    OneList<int> lst;
    lst.push_back(15);
    lst.push_front(20);
    REQUIRE(lst.size() == 2);
    REQUIRE(lst.front() == 20);
    REQUIRE(lst.back() == 15);
}

TEST_CASE("Inserting elements at different positions in OneList") {
    OneList<int> lst;
    lst.push_back(1);
    lst.insert(0, 0);
    lst.insert(2, 2);
    REQUIRE(lst.size() == 3);
    REQUIRE(lst.front() == 0);
    REQUIRE(lst.back() == 2);
}

TEST_CASE("Removing the front element from OneList") {
    OneList<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.pop_front();
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.front() == 20);
}

TEST_CASE("Removing the back element from OneList") {
    OneList<int> lst;
    lst.push_back(30);
    lst.push_back(40);
    lst.pop_back();
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.back() == 30);
}

TEST_CASE("Clearing all elements from OneList") {
    OneList<int> lst;
    lst.push_back(50);
    lst.push_back(60);
    lst.clear();
    REQUIRE(lst.empty());
}

TEST_CASE("Removing specific element from OneList") {
    OneList<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(100);
    lst.remove(100);
    REQUIRE(lst.size() == 2);
    REQUIRE(lst.front() == 200);
}

TEST_CASE("Exception when accessing front on empty OneList") {
    OneList<int> lst;
    bool exceptionThrown = false;
    try {
        lst.front();
    }
    catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE("Exception when accessing back on empty OneList") {
    OneList<int> lst;
    bool exceptionThrown = false;
    try {
        lst.back();
    }
    catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE("Check if DoubleList is empty after creation") {
    DoubleList<int> lst;
    REQUIRE(lst.empty());
    REQUIRE(lst.size() == 0);
}

TEST_CASE("Adding elements to the front and back of DoubleList") {
    DoubleList<int> lst;
    lst.push_front(1);
    lst.push_back(2);
    REQUIRE(lst.size() == 2);
    REQUIRE(lst.front() == 1);
    REQUIRE(lst.back() == 2);
}

TEST_CASE("Removing front element from DoubleList") {
    DoubleList<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.pop_front();
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.front() == 20);
}

TEST_CASE("Removing back element from DoubleList") {
    DoubleList<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.pop_back();
    REQUIRE(lst.size() == 1);
    REQUIRE(lst.back() == 10);
}

TEST_CASE("Inserting and removing elements in DoubleList") {
    DoubleList<int> lst;
    lst.push_back(3);
    lst.insert(0, 1);
    lst.insert(1, 2);
    lst.remove(2);
    REQUIRE(lst.size() == 2);
    REQUIRE(lst.front() == 1);
    REQUIRE(lst.back() == 3);
}

TEST_CASE("Clearing DoubleList") {
    DoubleList<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.clear();
    REQUIRE(lst.empty());
}

TEST_CASE("Exception when accessing front on empty DoubleList") {
    DoubleList<int> lst;
    bool exceptionThrown = false;
    try {
        lst.front();
    }
    catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE("Exception when accessing back on empty DoubleList") {
    DoubleList<int> lst;
    bool exceptionThrown = false;
    try {
        lst.back();
    }
    catch (const std::underflow_error&) {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE("Stress test for OneList operations") {
    OneList<int> lst;
    for (int i = 0; i < 1000; ++i) {
        lst.push_back(i);
    }
    REQUIRE(lst.size() == 1000);
    for (int i = 0; i < 500; ++i) {
        lst.pop_front();
    }
    REQUIRE(lst.size() == 500);
    for (int i = 0; i < 500; ++i) {
        lst.pop_back();
    }
    REQUIRE(lst.empty());
}

TEST_CASE("Stress test for DoubleList operations") {
    DoubleList<int> lst;
    for (int i = 0; i < 1000; ++i) {
        lst.push_back(i);
    }
    REQUIRE(lst.size() == 1000);
    for (int i = 0; i < 500; ++i) {
        lst.pop_front();
    }
    REQUIRE(lst.size() == 500);
    for (int i = 0; i < 500; ++i) {
        lst.pop_back();
    }
    REQUIRE(lst.empty());
}

TEST_CASE("Memory management for OneList") {
    OneList<int>* lst = new OneList<int>();
    lst->push_back(10);
    lst->push_back(20);
    delete lst;
    REQUIRE(true);
}

TEST_CASE("Memory management for DoubleList") {
    DoubleList<int>* lst = new DoubleList<int>();
    lst->push_back(30);
    lst->push_back(40);
    delete lst;
    REQUIRE(true);
}