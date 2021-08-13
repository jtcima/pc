#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "main.h"


bool pmos_circuit_status(uint8_t n)
{
    bool circuit_pmos_end_connected;

    if(sPOWER_PMOS & (n == 0))
    {
        circuit_pmos_end_connected = true;
    }
    
    if(sPOWER_PMOS & (n == 1))
    {
        circuit_pmos_end_connected = false;
    }

    if(!sPOWER_PMOS)
    {
        circuit_pmos_end_connected = false;
    }

    return circuit_pmos_end_connected;

}

bool nmos_circuit_status(uint8_t n)
{
    bool circuit_nmos_end_connected;
    
    if(sPOWER_PMOS & (n == 0))
    {
        circuit_nmos_end_connected = false;
    }
    if(sPOWER_PMOS & (n == 1))
    {
        circuit_nmos_end_connected = true;
    }
    if(!sPOWER_PMOS)
    {
        circuit_nmos_end_connected = false;
    }

    return circuit_nmos_end_connected;
}

uint8_t* decoder_extended_input_circuit_a(uint8_t n)
{
    static uint8_t decoder_input_extended_a[8];
    for(int i =0; i < 4; i++)
    {
        decoder_input_extended_a[i] = not_gate(n);
    }
    for(int i = 7; i>3; i--)
    {
        decoder_input_extended_a[i] = n;
    }
/*
    for(int i =0; i < 8; i++)
    {
        printf("%hhu", decoder_input_extended_a[i]);
    }
    printf("\n");
 */   
    return decoder_input_extended_a;

}
uint8_t* decoder_extended_input_circuit_b(uint8_t n)
{
    static uint8_t decoder_input_extended_b[8];
    for(int i =0; i < 2; i++)
    {
        decoder_input_extended_b[i] = not_gate(n);
        decoder_input_extended_b[i+4] = not_gate(n);
    }
    for(int i = 7; i>5; i--)
    {
        decoder_input_extended_b[i] = n;
        decoder_input_extended_b[i-4] = n;
    }
/*
    for(int i =0; i < 8; i++)
    {
        printf("%hhu", decoder_input_extended_b[i]);
    }
    printf("\n");
 */   
    return decoder_input_extended_b;
}

uint8_t* decoder_extended_input_circuit_c(uint8_t n)
{
    static uint8_t decoder_input_extended_c[8];
    for(int i =0; i < 8; i+=2)
    {
        decoder_input_extended_c[i] = not_gate(n);
    }

    for(int i =1; i < 8; i+=2)
    {
        decoder_input_extended_c[i] = n;
    }
 
/*
    for(int i =0; i < 8; i++)
    {
        printf("%hhu", decoder_input_extended_c[i]);
    }
    printf("\n");
 */   
    return decoder_input_extended_c;

}