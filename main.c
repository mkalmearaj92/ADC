#include <stdio.h>
#include <stdint.h>
#include "adc.h"
#include "io.h"

int main(void) {
    printf("Welcome to ADC project!  \n\n");
    AdcSample  * records;
   records =  readSensorData("adc_sensor_log.bin");

    for (uint32_t i = 0;
         i <  10;
         i++)
    {
        printf(
            "Record %u\n"
            "Timestamp       : %.4f s\n"
            "Channel ID      : %u\n"
            "Raw Value       : %u\n"
            "Voltage         :%.4f\n"
            "Temperature     : %d\n"
            "Status Flags    : 0x%02X\n"
            "Sequence Number : %u\n"
            "Reserved        : [%u, %u]\n"
            "-----------------------------\n",

            i,

            records[i].timestamp,

            records[i].channelID,

            records[i].raw_value,
            records[i].voltage,

            records[i].temperature,

            records[i].status_flags,

            records[i].sequence_number,

            records[i].reserved[0],

            records[i].reserved[1]
        );
    }
    //printf("ADC size is : %lu \n " ,sizeof(AdcSample));
    return 0;
}

