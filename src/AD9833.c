#include "AD9833.h"
#include "debug.h"

void AD9833_Write(uint16_t data)
{
    DEV_Digital_Write(DEV_CS_PIN, LOW);
    DEV_SPI_WriteByte(data >> 8);
    DEV_SPI_WriteByte(data & 0xff);
    DEV_Digital_Write(DEV_CS_PIN, HIGH);
}

#define AD9834_RAD_LOOP (6.283185307179586476925286766559)

static double AD9834_CheckPhase(double rad)
{
    if (rad > 0.0)
        for (; rad - AD9834_RAD_LOOP >= 0.0; rad -= AD9834_RAD_LOOP);
    else if (rad < 0.0)
        for (; rad < 0.0; rad += AD9834_RAD_LOOP);
    return rad;
}

void AD9833_SetPhaseRad(uint16_t reg, double rad)
{
    AD9833_Write(reg | (((uint16_t)(AD9834_CheckPhase(rad) * AD9833_PHASE_FACTOR)) & 0x0FFF));
}

void AD9833_SetPhaseDeg(uint16_t reg, double deg)
{
    AD9833_SetPhaseRad(reg, deg * AD9833_RAD_PER_DEG);
}

void AD9833_SetFreqLSB(uint16_t reg, double hz)
{
    AD9833_Write(reg | (((uint32_t) (hz * AD9833_FREQ_FACTOR)) & 0x3FFF));
}

void AD9833_SetFreqMSB(uint16_t reg, double hz)
{
    AD9833_Write(reg | (((uint32_t) (hz * AD9833_FREQ_FACTOR)) >> 14));
}

void AD9833_SetFreqB28(uint16_t reg, double hz)
{
    uint32_t val = (uint32_t) (hz * AD9833_FREQ_FACTOR);
    AD9833_Write(reg | (val & 0x3FFF));
    AD9833_Write(reg | (val >> 14));
}