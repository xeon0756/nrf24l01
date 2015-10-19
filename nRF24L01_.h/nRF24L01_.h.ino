#ifndef __NRF24L01_H__
#define __NRF24L01_H__

 
#include <Arduino.h>
#include <stdint.h>
#include <SPI.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define _BV(bit) (1 << (bit))

class nRF24L01{
public:
enum Registers{
CONFIG=0x00;
EN_AA=0x01;
EN_RXADDR=0x02;
SETUP_AW=0x03;
SETUP_RETR=0x04;
RF_CH=0x05;
RF_SETUP=0x06;
STATUS=0x07;
OBSERVE_TX=0x08;
RPD=0x09;
RX_ADDR_P0=0x0A;
RX_ADDR_P1=0x0B;
RX_ADDR_P2=0x0C;
RX_ADDR_P3=0x0D;
RX_ADDR_P4=0x0E;
RX_ADDR_P5=0x0F;
TX_ADDR=0x10;
RX_PW_P0=0x11;
RX_PW_P1=0x12;
RX_PW_P2=0x13;
RX_PW_P3=0x14;
RX_PW_P4=0x15;
RX_PW_P5=0x16;
FIFO_STATUS=0x17;
DYNPD=0x1C;
FEATURE=0x1D;
};
enum command{
/* Instruction Mnemonics */
R_REGISTER  =  0x00
W_REGISTER  =  0x20
REGISTER_MASK =0x1F
ACTIVATE    =  0x50
R_RX_PL_WID  = 0x60
R_RX_PAYLOAD = 0x61
W_TX_PAYLOAD = 0xA0
W_ACK_PAYLOAD= 0xA8
FLUSH_TX   =   0xE1
FLUSH_RX    =  0xE2
REUSE_TX_PL =  0xE3
NOP         =  0xFF
};

nRF24L01_(byte _cs,byte mode);
//functions
void spi_config();
byte read_reg(byte reg);
byte read_reg(byte reg,const void* buf,byte length_);
byte write_reg(byte reg);
byte write_reg(byte reg,const void* buf,byte length_);
void tx_payload(const void* buf,byte length_);
void rx_payload();
void reuse_tx_pl();
void w_acl_payload(const void* buf,byte length_);
void w_tx_pl_noack(const void* buf,byte length_);
void flush_tx();
void flush_rx();
void print_reg(byte reg); 
void set_address_tx(uint64_t addr);
void set_address_rx(byte data_pipe,uint64_t addr);
void enable_datapipe();
void no_ack();
void enable_Dynamic_payload();
void power_amplifier_mode(byte mode_pa);
bool RPD();
void set_rf_channel(byte rf_ch);
void air_data_rate(byte mode_adr);
void crc_mode(byte crc_mode);
void auto_ack_payload();
void set_auto_retr();
void get_retr_curr(); //arc_cnt
void get_retr_plos(); //plos_cnt
void set_ard(byte mult);

private:
byte cs;
byte mode;

}
#endif
