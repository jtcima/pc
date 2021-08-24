#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int main()
{
    check_power();
    
    while (true)
    {
        ram_8_byte();
    }
    
    //mem_bus_control(-2, 0);
    //decoder_extended_input_circuit_a(1);
    //decoder_extended_input_circuit_b(0);
    //decoder_extended_input_circuit_c(0);
    //decoder(0,1,0);
    //select_mem_no();
    //uint8_t arraya[8] = {1,1,0,0,0,0,0,0};
    //enabler(arraya, 1);
    //uint8_t arrayb[8] = {1,1,1,0,0,0,0,0};
    /*
    for(int i=0; i< 8; i++)
    {
        printf("%u", enabler(arraya, 1)[i]);
    }*/
    
    //input_binary();
    //alu_final(arraya, arrayb);
    
    //printf("\n%d", alu(arraya, arrayb, 1));
    /*for(int i=0; i< 8; i++)
    {
        printf("%u", dec_to_bin(-4)[i]);
    }*/
    
    
    //multiplexer(arraya,arrayb,0);
    /*for(int i = 0; i < 8; i++)
    {
        //printf("%u, %u, %u\n", arraya[i], arrayb[i], multiplexer(arraya,arrayb,0)[i]);
    }*/
   
    
    /*
    uint8_t input1 = input();
    uint8_t input2 = input();
    uint8_t _xor_gate = xor_gate(input1, input2);
    printf("%u\n", _xor_gate);
*/
    //uint8_t input3 = input();
    /*uint8_t _nmos = nmos(input1);
    uint8_t _pmos = pmos(input2);
    uint8_t _not_gate = not_gate(input1);
    uint8_t _nand_gate = nand_gate(input1,input2);
    uint8_t _nand_gate_3  = nand_gate_3(input1, input2, input3);
    uint8_t _bit = bit(input1, 1);

    printf("nmos: %u\npmos: %u\nnot_gate: %u\nnand_gate: %u\nbit: %u\nnand_gate_3: %u\n", 
            _nmos, _pmos, _not_gate, _nand_gate, _bit, _nand_gate_3);
    */

    return 0;
}