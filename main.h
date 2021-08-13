#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ON              1
#define OFF             0
#define sPOWER_PMOS     1

//control
uint8_t input(void);
uint8_t input_binary(void);
uint8_t decoder_input(void);
void check_power(void);
uint8_t set_s_bit(void);

//parts
uint8_t nmos(uint8_t n);
uint8_t pmos(uint8_t n);
uint8_t not_gate(uint8_t n);
uint8_t nand_gate(uint8_t a, uint8_t b);
uint8_t nand_gate_3(uint8_t a, uint8_t b, uint8_t c);
uint8_t bit(uint8_t n, uint8_t s_bit);
uint8_t mem_byte(uint8_t s_bit);
uint8_t select_mem_no(void);
uint8_t* decoder(uint8_t a, uint8_t b, uint8_t c);
uint8_t* ram_8_byte();

//circuit
bool pmos_circuit_status(uint8_t n);
bool nmos_circuit_status(uint8_t n);
uint8_t* decoder_extended_input_circuit_a(uint8_t n);
uint8_t* decoder_extended_input_circuit_b(uint8_t n);
uint8_t* decoder_extended_input_circuit_c(uint8_t n);

typedef struct decoder
{
    uint8_t output1;
    uint8_t output2;
    uint8_t output3;
    uint8_t output4;
    uint8_t output5;
    uint8_t output6;
    uint8_t output7;
    uint8_t output8;
}decoder_t;

typedef struct decoder_input
{
    uint8_t input1;
    uint8_t input2;
    uint8_t input3;
    uint8_t input4;
    uint8_t input5;
    uint8_t input6;
    uint8_t input7;
    uint8_t input8;
}decoder_input_t;


typedef struct nand_gate
{
    uint8_t output1;
    uint8_t output2;
    uint8_t output3;
    uint8_t output4;
}nand_gate_t; 

#endif