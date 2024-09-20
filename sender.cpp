#include "./sender.h"

Sender::Sender() {
    std::srand(static_cast<unsigned int>(std::time(0)));  // Seed for randomness
}

void Sender::generateData(int count) {
    for (int i = 0; i < count; ++i) {
        outputData(generateTemperature(), generatePulseRate(), generateSpo2());
    }
}

float Sender::generateTemperature() const {
    return generateRandomValue(20.0f, 30.0f);  // Random temp between 20 and 30
}

int Sender::generatePulseRate() const {
    return std::rand() % 41 + 60;  // Random pulse rate between 60 and 100
}

float Sender::generateSpo2() const {
    return generateRandomValue(95.0f, 100.0f);  // Random SPO2 between 95 and 100
}

float Sender::generateRandomValue(float min, float max) const {
    return min + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}

void Sender::outputData(float temperature, int pulseRate, float spo2) const {
    std::cout << std::fixed << std::setprecision(2)
              << temperature << ","
              << pulseRate << ","
              << spo2 << std::endl;
}
