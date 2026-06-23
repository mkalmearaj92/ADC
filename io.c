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
    printf("\n-----------------------------------------\n");
    // dynamic memory allocation should be used
    // to reservce memory at running time
    sample = malloc(header.sample_count * sizeof(AdcSample));

    fread(sample, sizeof(AdcSample), header.sample_count, file);

    fclose(file);
    return sample;
}

