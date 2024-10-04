#include ".\processor.h"

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
    if (lastValues.size() < 1) return;

    float sum = std::accumulate(lastValues.front(), lastValues.back(), 0.0f);
    float average = sum / lastValues.size();

    std::cout << "SMA (last 5 values): " << average << std::endl;
}

float Processor::getMinValue() const { return minValue; }

float Processor::getMaxValue() const { return maxValue; }

float Processor::getSimpleMovingAverage() const {
    if (lastValues.empty()) return 0.0f;
    float sum = std::accumulate(lastValues.front(), lastValues.back(), 0.0f);
    return sum / lastValues.size();
}
