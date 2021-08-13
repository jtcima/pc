#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"

//nmos transistors
uint8_t nmos(uint8_t n)
{
    uint8_t output;
    if(n == 1)
    {
        output = 1;
    }
    if(n == 0)
    {
        output = 0;
    }
    return output;
}

//pmos transistors
uint8_t pmos(uint8_t n)
{
    uint8_t output;
    if(n == 1)
    {
        output = 0;
    }
    if(n == 0)
    {
        output = 1;
    }
    return output;
}

//not gate
uint8_t not_gate(uint8_t n)
{
    uint8_t output;
    if(pmos_circuit_status(n) || nmos_circuit_status(n))
    {
        output = pmos(n);
    }
    else
    {
        output = 0;
    }
    return output;
}

//nand gates with 2 inputs

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    uint8_t output;
    if(not_gate(a) || not_gate(b))
    {
        output = 1;
    }
    if(!not_gate(a) && !not_gate(b))
    {
        output = 0;
    }
    if(not_gate(a) && not_gate(b))
    {
        output = 1;
    }

    return output;    
}

//nand gate with 3 inputs

uint8_t nand_gate_3(uint8_t a, uint8_t b, uint8_t c)
{
    uint8_t output;
    if(not_gate(a) || not_gate(b) || not_gate(c))
    {
        output = 1;
    }
    if(!not_gate(a) && !not_gate(b) && !not_gate(c))
    {
        output = 0;
    }
    if(not_gate(a) && not_gate(b) && not_gate(c))
    {
        output = 1;
    }

    return output;    
}


uint8_t bit(uint8_t n, uint8_t s_bit)
{
    uint8_t bit_output;
    nand_gate_t output;
    output.output1 = nand_gate(n, s_bit);
    output.output2 = nand_gate(s_bit, output.output1);
    output.output3 = nand_gate(output.output4, output.output2);
    output.output4 = nand_gate(output.output3, output.output1);
    bit_output = output.output4;

    return bit_output;
}

//memory byte

uint8_t mem_byte(uint8_t s_bit)
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

uint8_t* decoder(uint8_t a, uint8_t b, uint8_t c)
{
    static uint8_t decoder_output[8];

    for(int i = 0; i < 8; i++)
    {
        decoder_output[i] = not_gate(nand_gate_3(decoder_extended_input_circuit_a(a)[i],
                                                 decoder_extended_input_circuit_b(b)[i],
                                                 decoder_extended_input_circuit_c(c)[i]));
    }
/*
    for(int i = 0; i < 8; i++)
    {
        printf("%u",decoder_output[i]);
    }
*/
    return decoder_output;
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

uint8_t* ram_8_byte()
{
    static uint8_t memory[8];
    switch(select_mem_no())
    {
        case 0:
            memory[0] = mem_byte(1);
            break;

        case 1:
            memory[1] = mem_byte(1);
            break;

        case 2:
            memory[2] = mem_byte(1);
            break;

        case 3:
            memory[3] = mem_byte(1);
            break;

        case 4:
            memory[4] = mem_byte(1);
            break;

        case 5:
            memory[5] = mem_byte(1);
            break;

        case 6:
            memory[6] = mem_byte(1);
            break;

        case 7:
            memory[7] = mem_byte(1);
            break;

        default:
            memory[select_mem_no()] = mem_byte(0);
    }

    sleep(2);
    printf("Listing of memory blocks: \n");
    sleep(2);
    for(int i = 0; i < 8; i++)
    {
        printf("mem_%d: %u\n",i, memory[i]);
        sleep(1);
    }


    return memory;
}