#ifndef DEV_CONFIG_H
#define DEV_CONFIG_H

/*
       Connection scheme
+--------------+
|              |      +--------+
|     RPi3     |      | AD9833 |
|              |      |        |
|         MOSI +------+ SDATA  |
|         SCLK +------+ SCLK   |
|        GPIO6 +------+ FSYNC  |
|              |      |        |
|              |      +--------+
|              |
+--------------+
*/

#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>

#ifdef USE_SOFT_SPI
#define DEV_SCLK_PIN  (RPI_GPIO_P1_23)
#define DEV_SDAT_PIN  (RPI_GPIO_P1_19)
#endif /* USE_SOFT_SPI */

/* when used hardware SPI, CS pin need be NOT CS0 or CS1 */
#define DEV_CS_PIN (RPI_GPIO_P1_22)

#define DEV_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)
#define DEV_Digital_Read(_pin) bcm2835_gpio_lev(_pin)

#ifdef USE_SOFT_SPI
#define DEV_SPI_WriteByte(__value) \
do { \
    uint8_t reg = __value; \
    for (int i = 0; i < 8; ++i) \
    { \
        DEV_Digital_Write(DEV_SDAT_PIN, ((reg << i) & 0x80) >> 7); \
        DEV_Digital_Write(DEV_SCLK_PIN, LOW); \
        DEV_Digital_Write(DEV_SCLK_PIN, HIGH); \
    } \
} while (0)
#else
#define DEV_SPI_WriteByte(__value) bcm2835_spi_transfer(__value)
#define DEV_SPI_ReadByte() bcm2835_spi_transfer(0xff)
#endif /* USE_SOFT_SPI */

uint8_t DEV_ModuleInit(void);
void DEV_ModuleExit(void);

#endif /* DEV_CONFIG_H */
