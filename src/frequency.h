#pragma once

#include <stdio.h>

typedef struct FrequencyData {
    double frequencies[26];
    int counts[26];
    int total;
} freq_data_t;

int CalcFrequency(freq_data_t* freqData, FILE* inputFile);

double CalcIC(freq_data_t* freqData);