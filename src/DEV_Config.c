#include "DEV_Config.h"
#include "debug.h"

static void DEV_GPIOConfig(void)
{
    bcm2835_gpio_fsel(DEV_CS_PIN, BCM2835_GPIO_FSEL_OUTP);
    DEV_Digital_Write(DEV_CS_PIN, HIGH);
#ifdef USE_SOFT_SPI
    bcm2835_gpio_fsel(DEV_SCLK_PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(DEV_SDAT_PIN, BCM2835_GPIO_FSEL_OUTP);
    DEV_Digital_Write(DEV_SCLK_PIN, HIGH);
#endif /* USE_SOFT_SPI */
}

uint8_t DEV_ModuleInit(void)
{
    if(!bcm2835_init())
    {
        DEV_ERR("init bcm2835 library failed");
        return 1;
    }

    DEV_GPIOConfig();
#ifndef USE_SOFT_SPI
    bcm2835_spi_begin();
    bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE2);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_2048);
#endif /* USE_SOFT_SPI */
    DEV_DBG("bcm2835 init success");

    return 0;
}

void DEV_ModuleExit(void)
{
    DEV_DBG("bcm2835 deinit");
    bcm2835_spi_end();
    bcm2835_close();
}