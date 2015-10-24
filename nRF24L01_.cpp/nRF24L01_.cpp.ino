#include "nRF24L01_.h"

nRF24L01_:nRF24L01_(byte _cs,byte _mode){
cs=_cs;
mode=_mode;
spi_config();
}
void nRF24L01_:spi_config(){
SPI.setBitOrder(MSBFIRST,SPI_MODE0);
SPI.setDataMode(SPI_MODE0);
SPI.setClockDivider(SPI_CLOCK_DIV4);
pinMode(cs,OUTPUT);
digitalWrite(cs,HIGH);
}

void nRF24L01_:read_reg(byte reg,const void* buf,byte length_){
digitalWrite(cs,LOW);
status_=SPI.transfer(R_REGISTER|reg);
while(length_){
buf[length_]=SPI.transfer(0xff);
length_--;
}
digitalWrite(cs,HIGH);
}



