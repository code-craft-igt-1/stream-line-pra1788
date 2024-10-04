#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include "./sender.h"

class TestSender {
 public:
    void run() {
        testGenerateData();
    }

 private:
    void testGenerateData() {
        Sender sender;
        std::ostringstream output;

        // Redirect cout to capture the output
        std::streambuf* oldCoutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        // Generate 10 sets of readings for testing
        sender.generateData(10);

        // Restore cout
        std::cout.rdbuf(oldCoutBuffer);

        validateOutput(output.str(), 10);
    }

    void validateOutput(const std::string& output, int expectedLineCount) {
        std::istringstream input(output);
        std::string line;
        int lineCount = 0;

        while (std::getline(input, line)) {
            lineCount++;
            validateLine(line);
        }

        // Ensure that we generated the correct number of lines
        assert(lineCount == expectedLineCount);
        std::cout << "All tests passed!" << std::endl;
    }

    void validateLine(const std::string& line) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        assert(firstComma != std::string::npos);
        assert(secondComma != std::string::npos);
        assert(secondComma > firstComma);

        validateValues(line, firstComma, secondComma);
    }

    void validateValues(const std::string& line, size_t firstComma, size_t secondComma) {
        float temperature = std::stof(line.substr(0, firstComma));
        int pulseRate = std::stoi(line.substr(firstComma + 1, secondComma - firstComma - 1));
        float spo2 = std::stof(line.substr(secondComma + 1));

        checkTemperature(temperature);
        checkPulseRate(pulseRate);
        checkSpo2(spo2);
    }

    void checkTemperature(float temperature) {
        assert(temperature >= 20.0 && temperature <= 30.0);
    }

    void checkPulseRate(int pulseRate) {
        assert(pulseRate >= 60 && pulseRate <= 100);
    }

    void checkSpo2(float spo2) {
        assert(spo2 >= 95.0 && spo2 <= 100.0);
    }
};

int main() {
    TestSender test;
    test.run();
    return 0;
}
