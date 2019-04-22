#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <map>
#include "gtest/gtest.h"
#include "../Data/beegeneration.h"
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
#include "../Data/datagenerator.h"
//#include "../Database/DBHiveTable.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    FooTest() {
        // You can do set-up work for each test here.
    }

    virtual ~FooTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for Foo.

    /** replace with your own **/
    //DBHiveTable t1;
    //DBHiveTable t2;
    //    BeeGeneration* b1 = new BeeGeneration(2);
    //    BeeGeneration* b2 = new BeeGeneration(2);
};
//DATABASE TEST SECTION

TEST(general, GETDATE) {
    /** replace with your own **/
    //        DataDecoder d1;
    //       ASSERT_EQ(d1.dateDecoder("D18.12.19T13.43.16000"), "18.12.19")
    //               << d1.dateDecoder("D18.12.19T13.43.16000")
    //               << " and "
    //               << ("18.12.19")
    //               << " should match!";
}
TEST_F(FooTest, GETTIME) {
    //ASSERT_EQ(d1.timeDecoder("D18.12.19T13.43.16000"), "13.43.16000")
    //      << "These should match!";
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
