#include "FIRFilter.h"

FIRFilter::FIRFilter(float* impulse_response){
    FIR_impulse_response = impulse_response; // Assign impulse response buffer
    for (int i = 0; i < FIR_FILTER_LENGTH; i++){ // Clear buffer
        buf[i] = 0;
    }
    bufIndex = 0;
    out = 0;
}

float FIRFilter::update(float in){
    buf[bufIndex] = in;
    if (bufIndex < FIR_FILTER_LENGTH-1){
        bufIndex++;
    } else {
        bufIndex = 0;
    }
    out = 0;
    uint8_t sumIndex = bufIndex;
    for (int i = 0; i < FIR_FILTER_LENGTH; i++){
        if(sumIndex > 0){
            sumIndex--;
        }else{
            sumIndex = FIR_FILTER_LENGTH-1;
        }
        out += *(FIR_impulse_response+i)*buf[sumIndex];
    }
    return out;
}