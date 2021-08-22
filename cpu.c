#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

uint8_t reg_name(uint8_t s_bit)
{
    uint8_t byte_output = 0;
    uint8_t bits[8];
    uint8_t bits_result[8]; 
    uint8_t result;
    if(s_bit == 1)
    {
        for(int i = 0; i < 8; i++)
        {
            uint8_t num = input();
            bits[i] = bit(num, s_bit);
            bits_result[i] = bits[i];
            byte_output |= (bits[i] << i);
        }
            result = byte_output;
    }
    if(s_bit == 0)
    {
        for(int i = 0; i < 8; i++)
        {
            uint8_t num = input();
            bits[i] = bit(num, s_bit);
            byte_output |= (bits[i] << i);
        }   
    }
/*
    printf("The binary you entered is: ");
    for(int i = 7; i >= 0; i--)
    {
        printf("%u", bits_result[i]);
    }
    
    printf(" .In decimal format is %u.\n", result);
*/
    return result;
    
}


//ALU final

uint8_t alu_final(uint8_t *array1, uint8_t *array2)
{
    alu(array1, array2, 0);
    
}