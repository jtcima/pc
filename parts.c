#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
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

uint8_t *multiplexer(uint8_t *x, uint8_t *y, uint8_t s)
{
    static uint8_t output[8];
    if(sPOWER)
    {
        for(int i = 0; i < 8; i++)
        {
            output[i] = nand_gate(nand_gate(x[i], s), nand_gate(not_gate(s), y[i]));
        }
    }
    if(!sPOWER)
    {
        printf("WARNING!Multiplexer has not been turned on!\n");
        memset(output, 0, 8*sizeof(uint8_t));
    }
    return output;
}

//xor gate
uint8_t xor_gate(uint8_t control_bit, uint8_t b)
{
    uint8_t output;
    output = nand_gate(nand_gate(not_gate(control_bit), b), nand_gate(control_bit, not_gate(b)));
    return output;
}

//8_bit xor gate
uint8_t* eight_bit_xor_gate(uint8_t * array1, uint8_t * array2)
{
    //uint8_t output;
    static uint8_t output_bit[8];
    for(int i = 0; i < 8; i++)
    {
        output_bit[i] = xor_gate(array1[i], array2[i]);
        //output |= output_bit[i] << i;
    }

    return output_bit;
}

//8_bit and gate
uint8_t* and_gate(uint8_t *array1, uint8_t *array2)
{
    //uint8_t output;
    static uint8_t output_bit[8];
    for(int i = 0; i < 8; i++)
    {
        output_bit[i] = not_gate(nand_gate(array1[i], array2[i]));
        //output |= output_bit[i] << i;
    }
    return output_bit;
}

//Enabler
uint8_t* enabler(uint8_t * array, uint8_t control_bit)
{
    static uint8_t output[8];
    for(int i = 0; i < 8; i++)
    {
        output[i] = not_gate(nand_gate(array[i], control_bit));
        //printf("%u", output[i]);
    }

    return output;
}


//8 bit adder
int16_t adder(uint8_t *array1, uint8_t *array2, uint8_t c_bit)
{
    int16_t output;
    static uint8_t output_bit[9];
    
    for(int i =0; i<9; i++)
    {
        for(int i =0; i < 8; i++)
        {
            output_bit[i] = xor_gate(xor_gate(array1[i],array2[i]), c_bit);
            output_bit[i+1] = xor_gate(not_gate(nand_gate(xor_gate(array1[i],array2[i]), c_bit)),not_gate((nand_gate(array1[i],array2[i]))));
            c_bit = output_bit[i+1];
        }
        output |= output_bit[i] << i;
        //printf("%u", output_bit[i]);
    }
        
    return output;
}

/*
//8 bit subtraction

int8_t subtraction(uint8_t *array_sub, uint8_t *array2)
{
    int8_t output;
    uint8_t reverse_array_sub[8];
    uint8_t c_bit;
    static int8_t num1, num2;
    

    for(int i = 0; i < 8; i++)
    {
        num1 |= array_sub[i] << i;
        num2 |= array2[i] << i;
    }

    printf("%d %d\n", num1, num2);

    if(num1 > num2)
    {
        c_bit = 0;
    }
    if(num1 < num2)
    {
        c_bit = 1;
    }

    for(int i = 0; i < 8; i++)
    {
        reverse_array_sub[i] = not_gate(array_sub[i]);
    }
    
    if(c_bit == 0)
    {
        output = adder(reverse_array_sub, array2, c_bit)+num2;
    }
    if(c_bit == 1)
    {
        output = adder(reverse_array_sub, array2, c_bit);
    }
    return output;
}
*/
//ALU
int16_t alu(uint8_t *array1, uint8_t *array2, uint8_t control_bit)
{
    int16_t output;
    static uint8_t array_after_xor[8];
    uint8_t c_bit;
    static uint8_t num1, num2;

    for(int i = 0; i < 8; i++)
    {
        array_after_xor[i] = xor_gate(control_bit, array2[i]);
        printf("%u", array_after_xor[i]);
    }

    if(!control_bit)
    {
        output = adder(array_after_xor, array1, control_bit);
    }

    if(control_bit)
    {
        for(int i = 0; i < 8; i++)
        {
            num1 |= array1[i] << i;
            num2 |= array2[i] << i;
        }

        printf("\n%d %d\n", num1, num2);

        if(num1 > num2)
        {
            c_bit = 1;
        }
        if(num1 < num2)
        {
            c_bit = 0;
        }
        if(c_bit == 0)
        {
            output = (int8_t)adder(array_after_xor, array1, c_bit)+1;
        }
        if(c_bit == 1)
        {
            output = (uint8_t)adder(array_after_xor, array1, c_bit);
        }
    }

    return output;
}


