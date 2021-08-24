#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/*
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


    printf("The binary you entered is: ");
    for(int i = 7; i >= 0; i--)
    {
        printf("%u", bits_result[i]);
    }
    
    printf(" .In decimal format is %u.\n", result);

    return result;
    
}
*/

//ALU final

uint8_t* alu_final(uint8_t *array1, uint8_t *array2) 
{
    static uint8_t output[8];
    multiplexer_t mux_input;
    uint8_t decoder_1st_bit = decoder_input();
    uint8_t decoder_2nd_bit = decoder_input();
    uint8_t decoder_3rd_bit = decoder_input();
    uint8_t s_bit = set_s_bit();

    if(decoder(decoder_1st_bit, decoder_2nd_bit, decoder_3rd_bit)[0] == 1 && s_bit) 
    {    
        for(int i = 0; i < 8; i++)
        {
            mux_input.output_1[i] = enabler(dec_to_bin(alu(array1, array2, 0)), 1)[i];
            output[i] = mux_input.output_1[i];
            //printf("%u", mux_input.output_add[i]);
        }
    }
    if(decoder(decoder_1st_bit, decoder_2nd_bit, decoder_3rd_bit)[1] == 1 && s_bit)
    {    
        for(int i = 0; i < 8; i++)
        {
            mux_input.output_2[i] = enabler(dec_to_bin(alu(array1, array2, 1)), 1)[i];
            output[i] = mux_input.output_2[i];
            //printf("%u", output[i]);
        }
    } 
        
    if(decoder(decoder_1st_bit, decoder_2nd_bit, decoder_3rd_bit)[2] == 1 && s_bit)
    {    
        for(int i = 0; i < 8; i++)
        {
            mux_input.output_3[i] = enabler(xor_gate_1(1, array2),1)[i];
            output[i] = mux_input.output_3[i];
            //printf("%u", output[i]);
        }
    }
    
    if(decoder(decoder_1st_bit, decoder_2nd_bit, decoder_3rd_bit)[3] == 1 && s_bit)
    {    
        for(int i = 0; i < 8; i++)
        {
            mux_input.output_4[i] = enabler(eight_bit_xor_gate(array1, array2), 1)[i];
            output[i] = mux_input.output_4[i];
            //printf("%u", output[i]);
        }
    }
        
    if(decoder(decoder_1st_bit, decoder_2nd_bit, decoder_3rd_bit)[4] == 1 && s_bit)
    {    
        for(int i = 0; i < 8; i++)
        {
            mux_input.output_5[i] = enabler(and_gate(array1, array2), 1)[i];
            output[i] = mux_input.output_5[i];
            //printf("%u", output[i]);
        }    
    }
    
    if(!s_bit)
    {
        printf("WARNING!Multiplexer has not been turned on!\n");
        return 0;
    }
    for(int i = 0; i < 8; i++)
    {
        printf("%u", output[i]);
    }
    
    return output;

}