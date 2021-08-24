#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define ON              1
#define OFF             0
#define sPOWER          1

//control
int8_t input(void);
uint8_t decoder_input(void);
void check_power(void);
uint8_t set_s_bit(void);
uint8_t select_mem_no(void);
uint8_t* dec_to_bin(int8_t num);
int8_t mem_bus_control(int8_t num, uint8_t control_bit);

//memory
uint8_t bit(uint8_t n, uint8_t s_bit);
int8_t mem_byte(int8_t num, uint8_t s_bit);
int8_t *ram_8_byte();

//parts
uint8_t nmos(uint8_t n);
uint8_t pmos(uint8_t n);
uint8_t not_gate(uint8_t n);
uint8_t nand_gate(uint8_t a, uint8_t b);
uint8_t nand_gate_3(uint8_t a, uint8_t b, uint8_t c);
uint8_t* decoder(uint8_t a, uint8_t b, uint8_t c);
uint8_t *multiplexer(uint8_t *x, uint8_t *y, uint8_t s);
uint8_t reg_name(uint8_t s_bit);
uint8_t *and_gate(uint8_t *array1, uint8_t *array2);
uint8_t xor_gate(uint8_t a, uint8_t b);
uint8_t* xor_gate_1(uint8_t control_bit, uint8_t* array);
uint8_t *eight_bit_xor_gate(uint8_t * array1, uint8_t * array2);
int16_t adder(uint8_t *array1, uint8_t *array2, uint8_t c_bit);
//int8_t subtraction(uint8_t *array1, uint8_t *array2);
uint8_t *enabler(uint8_t * array, uint8_t control_bit);
uint8_t enabler_num(uint8_t * array, uint8_t control_bit);
int16_t alu(uint8_t *array1, uint8_t *array2, uint8_t control_bit);
uint8_t *alu_final(uint8_t *array1, uint8_t *array2); 

//circuit
bool pmos_circuit_status(uint8_t n);
bool nmos_circuit_status(uint8_t n);
uint8_t* decoder_extended_input_circuit_a(uint8_t n);
uint8_t* decoder_extended_input_circuit_b(uint8_t n);
uint8_t* decoder_extended_input_circuit_c(uint8_t n);



typedef struct multiplexer
{
    uint8_t output_1[8]; //add
    uint8_t output_2[8]; //sub
    uint8_t output_3[8]; //not
    uint8_t output_4[8]; //xor
    uint8_t output_5[8]; //and
    uint8_t output_6[8];
    uint8_t output_7[8];
    uint8_t output_8[8];
}multiplexer_t;

typedef struct nand_gate
{
    uint8_t output1;
    uint8_t output2;
    uint8_t output3;
    uint8_t output4;
}nand_gate_t; 

#endif