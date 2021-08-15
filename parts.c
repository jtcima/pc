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

uint8_t multiplexer(uint8_t x, uint8_t y, uint8_t s)
{
    uint8_t output;
    output = nand_gate(nand_gate(x, s), nand_gate(not_gate(s), y));
    return output;
}

