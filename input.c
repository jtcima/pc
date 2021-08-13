#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"

void check_power(void)
{
    if(!sPOWER_PMOS)
    {
        printf("*******WARNING!POWER NOT CONNECTED!*******\n");
    }
    if(sPOWER_PMOS)
    {
        printf("\n------POWER ON------\n");
    }
}

uint8_t input(void)
{
    uint8_t num;
    printf("enter 1 or 0: \n");
    scanf("%hhu", &num);
    return num;
}

uint8_t input_binary(void)
{
    


    return 0;
}

uint8_t decoder_input(void)
{
    uint8_t num;
    printf("\nEnter 1 or 0 for memory address: ");
    scanf("%hhu", &num);
    return num;

}

uint8_t set_s_bit(void)
{
    uint8_t s_bit;
    printf("S bit: 1 or 0?\n");
    scanf("%hhu", &s_bit);
    return s_bit;
}