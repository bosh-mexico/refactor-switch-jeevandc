cmake_minimum_required(VERSION 3.14)
project(bms-monitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Main executable (exclude test files)
add_executable(bms-main
    main.cpp
    PaymentModes.cpp
    # ...add other source files as needed
)

# Test executable (exclude main.cpp)
add_executable(test-monitor
    Test_paymentmodes.cpp
    PaymentModes.cpp
)

target_link_libraries(
  test-monitor
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test-monitor)
