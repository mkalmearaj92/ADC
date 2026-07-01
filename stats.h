//
// Created by mkalm on 19/06/2026.
//

#ifndef ADC_STATS_H
#define ADC_STATS_H
#include "adc.h"

typedef struct {
   float min_voltage;
   float max_voltage;
   float average; //mean
   float std_dev;
}Stats;

void calculate_stats(AdcSample * records , uint32_t sample_count , Stats ch_st[4] );
#endif //ADC_STATS_H
