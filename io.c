//
// Created by mkalm on 19/06/2026.
//

#include "io.h"

#include <stdio.h>
#include <stdlib.h>

void readSensorData(char * filename) {

    FILE *file;
    AdcSample  * sample;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    Header header;
    fread(&header, sizeof(Header), 1, file);
    printf("header info AS FOLLOWING :\n");
    printf("Version is : %u\n" , header.version);
    printf("Channel count is : %u\n" , header.channel_count);
    printf("Sample rate is : %u\n" , header.sample_rate);
    printf("records count: %u\n", header.sample_count);

    printf("\n-----------------------------------------\n");
    // dynamic memory allocation should be used
    // to reservce memory at running time
    sample = malloc(header.sample_count * sizeof(AdcSample));

    fread(sample, sizeof(AdcSample), header.sample_count, file);
    //print first record for testing
    printf("TimeStamp : %f \n", sample[0].timestamp);
    printf("Channel ID : %u \n", sample[0].channelID);
    printf("raw value  : %u \n", sample[0].raw_value);


    fclose(file);
}

