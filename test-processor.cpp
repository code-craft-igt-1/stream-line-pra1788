#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "./processor.h"

class ProcessorTest : public ::testing::Test {
 protected:
    void SetUp() override {
        // Code to set up test case (if any)
    }

    void TearDown() override {
        // Code to clean up after test case (if any)
    }

    // Utility function to simulate input for Processor
    void simulateInput(Processor* processor, const std::vector<float>& testData) {
        std::stringstream input;
        for (float value : testData) {
            input << value << " ";
        }
        std::cin.rdbuf(input.rdbuf());  // Redirect input stream for testing
        processor->processStream();
    }
};

// Test for Min/Max functionality
TEST_F(ProcessorTest, MinMaxTest) {
    Processor processor;
    std::vector<float> testData = { 30.0, 25.0, 22.0, 35.0, 20.0 };

    simulateInput(&processor, testData);

    EXPECT_EQ(processor.getMinValue(), 20.0);  // Assert that min value is correct
    EXPECT_EQ(processor.getMaxValue(), 35.0);  // Assert that max value is correct
}

// Test for Simple Moving Average (SMA)
TEST_F(ProcessorTest, SMATest) {
    Processor processor;
    std::vector<float> testData = { 30.0, 25.0, 22.0, 35.0, 20.0, 28.0 };

    simulateInput(&processor, testData);

    EXPECT_FLOAT_EQ(processor.getSimpleMovingAverage(), 26.0);  // Assert that SMA is correct
}
