#include "./processor.h"

void Processor::processStream() {
    float value;
    std::cout << "Enter values (non-numeric input to stop):" << std::endl;

    while (std::cin >> value) {
        calculateMinMax(value);
        calculateSimpleMovingAverage(value);
        printMinMax();
        printSimpleMovingAverage();
    }
}

void Processor::calculateMinMax(float value) {
    if (value < minValue) {
        minValue = value;
    }
    if (value > maxValue) {
        maxValue = value;
    }
}

void Processor::calculateSimpleMovingAverage(float value) {
    if (lastValues.size() == SMA_WINDOW) {
        lastValues.pop();
    }
    lastValues.push(value);
}

void Processor::printMinMax() const {
    std::cout << "Min: " << minValue << ", Max: " << maxValue << std::endl;
}

void Processor::printSimpleMovingAverage() const {
    if (lastValues.empty()) return;

    float average = calculateSum() / lastValues.size();
    std::cout << "SMA (last 5 values): " << average << std::endl;
}

float Processor::getMinValue() const { return minValue; }

float Processor::getMaxValue() const { return maxValue; }

float Processor::getSimpleMovingAverage() const {
    if (lastValues.empty()) return 0.0f;

    return calculateSum() / lastValues.size();
}

// New helper function to sum values in lastValues
float Processor::calculateSum() const {
    float sum = 0.0f;
    std::queue<float> tempQueue = lastValues;  //  Create a temporary copy of the queue

    // Sum all values in the temporary queue
    while (!tempQueue.empty()) {
        sum += tempQueue.front();
        tempQueue.pop();
    }

    return sum;  //  Return the computed sum
}
