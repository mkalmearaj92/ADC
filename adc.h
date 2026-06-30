//
// Created by mkalm on 19/06/2026.
//

#ifndef ADC_ADC_H
#define ADC_ADC_H
#include <stdint.h>

typedef struct __attribute__((__packed__)) {
    float timestamp; //4 bytes
    uint8_t channelID; //1
    uint16_t raw_value; //adc 2
    float voltage;
    int16_t temperature; //could be negative 2
    uint8_t status_flags; //1
    uint32_t sequence_number; //4
    uint8_t reserved[2]; //array of reserved 2
}AdcSample;

typedef struct __attribute__((__packed__)) {
    uint32_t magic;
    uint16_t version;
    uint16_t channel_count;
    uint32_t sample_count;
    uint32_t sample_rate;
    uint8_t reserved[8];
}Header;

typedef  struct {
    int higherVoltage_fault; //counter for overvoltages >3 V
    int lowerVoltage_fault  ;//counter for undervoltages < 0.3 V
    int sensor_fault; //count for sensorfault where 0000 000(1) is one
}Faults;


void detectFaults ( AdcSample * records,uint32_t sample_count,Faults faults[4]);

#endif //ADC_ADC_H

