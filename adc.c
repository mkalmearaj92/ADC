//
// Created by mkalm on 19/06/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "adc.h"
void detectFaults ( AdcSample * records ,uint32_t sample_count,Faults faults[4]) {

    for (uint32_t i=0;i<sample_count;i++) {

        //check overVoltage:
        if ( (records + i )->voltage > 3.0f ) {
            uint8_t ch = (records + i )->channelID;
            faults[ch].higherVoltage_fault ++;
        }

        //check underVoltage:
        if ( (records + i )->voltage < 0.3f ) {
            uint8_t ch = (records + i )->channelID;
            faults[ch].lowerVoltage_fault ++;
        }

        //check sensor fault:
        if ( (records + i )->status_flags & 0x01 ) {
            uint8_t ch = (records + i )->channelID;
            faults[ch].sensor_fault ++;
        }


    }
}
#include "adc.h"
