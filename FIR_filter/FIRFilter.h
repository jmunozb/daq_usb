#include <stdint.h>

#define FIR_FILTER_LENGTH 16

class FIRFilter {
private:
    float* FIR_impulse_response;
    float buf[FIR_FILTER_LENGTH];
    uint8_t bufIndex;
    float out;
public:
    FIRFilter(float* impulse_response);
    float update(float in);
};