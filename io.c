//
// Created by mkalm on 19/06/2026.
//

#include "io.h"

#include <stdio.h>
#include <stdlib.h>

AdcSample * readSensorData(char * filename) {

    FILE *file;
    AdcSample  * sample;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    Header header;
    fread(&header, sizeof(Header), 1, file);
    printf("header info AS FOLLOWING :\n");
    printf("Version is : %u\n" , header.version);
    printf("Channel count is : %u\n" , header.channel_count);
    printf("Sample rate is : %u\n" , header.sample_rate);
    printf("records count: %u\n", header.sample_count);

    //check the magic number is correct
    if (header.magic != 0xADC1BEEF) {
        //incorrect file
        printf("Error with file \n");
        fclose(file);
        return NULL ;
    }
    if (header.sample_count ==0) {
        printf("file empty \n");
        fclose(file);
        return NULL ;
    }
    printf("\n-----------------------------------------\n");
    // dynamic memory allocation should be used
    // to reservce memory at running time
    sample = malloc(header.sample_count * sizeof(AdcSample));


    for (uint32_t i  = 0; i < header.sample_count; i++) {
        fread(&sample[i].timestamp, sizeof(float), 1, file);
        fread(&sample[i].channelID, sizeof(uint8_t), 1, file);
        fread(&sample[i].raw_value, sizeof(uint16_t), 1, file);
        sample[i].voltage = (sample[i].raw_value / 4095.0f ) * 3.3f; // calcualte volt for each raw value during reading
        fread(&sample[i].temperature, sizeof(uint16_t), 1, file);
        fread(&sample[i].status_flags, sizeof(uint8_t), 1, file);
        fread(&sample[i].sequence_number, sizeof(uint32_t), 1, file);
        fread(&sample[i].reserved, sizeof(uint8_t), 2   , file);
    }
    fclose(file);
    return sample;
}