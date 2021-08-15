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

uint8_t select_mem_no(void)
{
    uint8_t a, b, c;
    printf("\n---Memory Address Selection---\n");
    a = decoder_input();
    b = decoder_input();
    c = decoder_input();
    uint8_t i = 0;
    
    while((i < 8) && (decoder(a,b,c)[i] != 1))
    {
        i++;
    }
    printf("\n---Memory Block %hhu Selected!---\n", i);
    printf("\nWriting to memory block %u...\n", i);
    sleep(2);
    return i;
}