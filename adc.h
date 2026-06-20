//
// Created by mkalm on 19/06/2026.
//

#ifndef ADC_ADC_H
#define ADC_ADC_H
#include <stdint.h>

typedef struct {
    float timestamp;
    uint8_t channelID;
    uint16_t raw_value; //adc
    int16_t temperature; //could be negative
    uint8_t status_flags;
    uint32_t sequence_number;
    uint8_t reserved[2]; //array of reserved
}AdcSample;

typedef struct {
    uint32_t magic;
    uint16_t version;
    uint16_t channel_count;
    uint32_t sample_count;
    uint32_t sample_rate;
    uint8_t reserved[8];
}Header;
#endif //ADC_ADC_H

