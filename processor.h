#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <iostream>
#include <queue>
#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

class Processor {
 public:
    void processStream();
    float getMinValue() const;
    float getMaxValue() const;
    float getSimpleMovingAverage() const;

 private:
    void calculateMinMax(float value);
    void calculateSimpleMovingAverage(float value);

    float minValue = std::numeric_limits<float>::max();
    float maxValue = std::numeric_limits<float>::lowest();
    std::queue<float> lastValues;
    const int SMA_WINDOW = 5;

    void printMinMax() const;
    void printSimpleMovingAverage() const;
};

#endif  // PROCESSOR_H_
