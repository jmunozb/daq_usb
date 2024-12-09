#include <iostream>
#include "FIRFilter.cpp"

using namespace std;

main() {
    float coeffs[FIR_FILTER_LENGTH] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
    FIRFilter filter(coeffs);

    float input_buf[FIR_FILTER_LENGTH+3] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};

    cout << "Results" << endl;

    float out = 0;

    for(int i = 0; i < FIR_FILTER_LENGTH+3; i++){
        out = filter.update(input_buf[i]);
        cout << out << endl;
    }

    return 0;
}



