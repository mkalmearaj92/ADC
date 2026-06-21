#include <stdio.h>
#include <stdint.h>
#include "adc.h"
#include "io.h"

int main(void) {
    printf("Welcome to ADC project!  \n\n");
    readSensorData("adc_sensor_log.bin");
    return 0;
}

