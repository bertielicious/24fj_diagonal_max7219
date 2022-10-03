/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GB202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */
int main(void)
{
    /*uint8_t splash[] ={0xe7, 0x44, 0x46, 0x44, 0x47, 0x00, 0xee, 0x4a, 0x4c, // T E
0x4a, 0x49, 0x00, 0x4f, 0x44, 0x42, 0x4f}; 
    uint8_t *p;
    p = &splash[0];*/
    // initialize the device
    SYSTEM_Initialize();
    SPI1_Initialize();
    
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(0x0c);    //leave shutdown mode and enter normal operation
    SPI1_Exchange8bit(0x00);
    LATBbits.LATB7 = 1;
    
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(0x0A);    // minimum display intensity 1/32
    SPI1_Exchange8bit(0x00);
    LATBbits.LATB7 = 1;
    
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(0x09);    // decode mode off
    SPI1_Exchange8bit(0x00);
    LATBbits.LATB7 = 1;
    
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(0x0b);    // scan limit = 8 digits multiplexed
    SPI1_Exchange8bit(0x07);
    LATBbits.LATB7 = 1;
    
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(0x0c);    //leave shutdown mode and enter normal operation
    SPI1_Exchange8bit(0x01);
    LATBbits.LATB7 = 1;
    
    uint8_t i = 1;
    for(i=0; i<8;i++)
    {
    LATBbits.LATB7 = 0;
    SPI1_Exchange8bit(i+1);    //row I+1 (1 to 8))
    SPI1_Exchange8bit(1<<i);   //col 1<<i (1 to 128)
    LATBbits.LATB7 = 1;
   // p++;
    }
    
    while (1)
    {
        // Add your application code
    }

    return 1;
}
/**
 End of File
*/

