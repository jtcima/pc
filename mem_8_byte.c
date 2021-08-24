#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

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

int8_t mem_byte(int8_t num, uint8_t s_bit)
{
    int8_t byte_output = 0;
    static uint8_t bits[8];
    //static uint8_t bits_result[8]; 
    static int8_t result;
    if(s_bit == 1)
    {

        for(int i = 0; i < 8; i++)
        {
            bits[i] = bit(((num >> i) & 1), s_bit);
            //bits_result[i] = bits[i];
            byte_output |= (bits[i] << i);
        }
            result = byte_output;
    }
    if(s_bit == 0)
    {
        for(int i = 0; i < 8; i++)
        {
            bits[i] = bit(((num >> i) & 1), s_bit);
            //bits_result[i] = bits[i];
            byte_output |= (bits[i] << i);
        }
          
    }
/*
    printf("The binary you entered is: ");
    for(int i = 7; i >= 0; i--)
    {
        printf("%u", bits_result[i]);
    }
    
    printf(" .In decimal format is %d.\n", result);
*/
    return result;
    
}

int8_t* ram_8_byte()
{
    static int8_t memory[8];
    int8_t num = input();
    uint8_t s_bit = set_s_bit();
    num = mem_bus_control(num, s_bit);

    if(s_bit == 0)
    {
        printf("Can not write to memory! Please enable memory by setting s_bit to 1!\n");
        return memory;
    }

    switch(select_mem_no())
    {
        case 0:
            memory[0] = mem_byte(num, s_bit);
            break;

        case 1:
            memory[1] = mem_byte(num, s_bit);
            break;

        case 2:
            memory[2] = mem_byte(num, s_bit);
            break;

        case 3:
            memory[3] = mem_byte(num, s_bit);
            break;

        case 4:
            memory[4] = mem_byte(num, s_bit);
            break;

        case 5:
            memory[5] = mem_byte(num, s_bit);
            break;

        case 6:
            memory[6] = mem_byte(num, s_bit);
            break;

        case 7:
            memory[7] = mem_byte(num, s_bit);
            break;
        /*
        default:
            memory[select_mem_no()] = mem_byte(num, s_bit);
        */
    }


    sleep(2);
    printf("Listing of memory blocks: \n");
    sleep(2);
    for(int i = 0; i < 8; i++)
    {
        printf("mem_%d: %d\n",i, memory[i]);
        sleep(1);
    }


    return memory;
}
/*
int8_t mem_final_output(int8_t * memory)
{

}
*/