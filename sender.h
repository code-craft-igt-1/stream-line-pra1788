#ifndef SENDER_H_
#define SENDER_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class Sender {
 public:
    Sender();
    void generateData(int count);

 private:
    float generateTemperature() const;
    int generatePulseRate() const;
    float generateSpo2() const;
    float generateRandomValue(float min, float max) const;
    void outputData(float temperature, int pulseRate, float spo2) const;
};

#endif  // SENDER_H_
