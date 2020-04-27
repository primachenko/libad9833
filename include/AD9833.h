#ifndef AD9833_H
#define AD9833_H

#include "DEV_Config.h"

#define AD9833_FREQ_FACTOR  (10.73741824)
#define AD9833_PHASE_FACTOR (651.89864690440329530934789477382)
#define AD9833_RAD_PER_DEG  (0.01745329251994329576923690768489)

#define AD9833_NON (0x0000)
#define AD9833_D0  (0x0001)
#define AD9833_D1  (0x0002)
#define AD9833_D2  (0x0004)
#define AD9833_D3  (0x0008)
#define AD9833_D4  (0x0010)
#define AD9833_D5  (0x0020)
#define AD9833_D6  (0x0040)
#define AD9833_D7  (0x0080)
#define AD9833_D8  (0x0100)
#define AD9833_D9  (0x0200)
#define AD9833_D10 (0x0400)
#define AD9833_D11 (0x0800)
#define AD9833_D12 (0x1000)
#define AD9833_D13 (0x2000)
#define AD9833_D14 (0x4000)
#define AD9833_D15 (0x8000)

#define AD9833_MODE     AD9833_D1
#define AD9833_DIV2     AD9833_D3
#define AD9833_OPBITEN  AD9833_D5
#define AD9833_SLEEP12  AD9833_D6
#define AD9833_SLEEP1   AD9833_D7
#define AD9833_RESET    AD9833_D8
#define AD9833_PSELECT  AD9833_D10
#define AD9833_FSELECT  AD9833_D11
#define AD9833_HLB      AD9833_D12
#define AD9833_B28      AD9833_D13

#define AD9833_FREQ0 AD9833_D14
#define AD9833_FREQ1 AD9833_D15

#define AD9833_PHASE0 (AD9833_D14 & AD9833_D15)
#define AD9833_PHASE1 (AD9833_D13 & AD9833_D14 & AD9833_D15)

#define AD9833_LSB(val) (val & 0x3FFF)
#define AD9833_MSB(val) (val >> 14)

void AD9833_Write(uint16_t data);

void AD9833_SetFreqB28(uint16_t reg, double hz);
void AD9833_SetFreqMSB(uint16_t reg, double hz);
void AD9833_SetFreqLSB(uint16_t reg, double hz);

void AD9833_SetPhaseRad(uint16_t reg, double rad);
void AD9833_SetPhaseDeg(uint16_t reg, double deg);

/*
+------------------------------------------------------------------------------------------------------------------+
|                                                   Register map                                                   |
+-----+-----+-----+-----+---------+---------+----+-------+--------+---------+---------+----+------+----+------+----+
| D15 | D14 | D13 | D12 |   D11   |   D10   | D9 |  D8   |   D7   |   D6    |   D5    | D4 |  D3  | D2 |  D1  | D0 |
+-----+-----+-----+-----+---------+---------+----+-------+--------+---------+---------+----+------+----+------+----+
|  0  |  0  | B28 | HLB | FSELECT | PSELECT | 0  | RESET | SLEEP1 | SLEEP12 | OPBITEN | 0  | DIV2 | 0  | MODE | 0  |
+-----+-----+-----+-----+---------+---------+----+-------+--------+---------+---------+----+------+----+------+----+
+-------------------------------+
|       Fequency registers      |
+-----+-----+-----+-----+-------+
| D15 | D14 | D13 | D0  | FREQ  |
+-----+-----+-----+-----+-------+
|  0  |  1  | MSB | LSB | FREQ0 |
+-----+-----+-----+-----+-------+
|  1  |  0  | MSB | LSB | FREQ1 |
+-----+-----+-----+-----+-------+
+--------------------------------------+
|           Phase registers            |
+-----+-----+-----+-----+-----+--------+
| D15 | D14 | D13 | D12 | D0  | PHASE  |
+-----+-----+-----+-----+-----+--------+
|  1  |  1  |  0  |  X  | LSB | PHASE0 |
+-----+-----+-----+-----+-----+--------+
|  1  |  1  |  1  |  X  | LSB | PHASE1 |
+-----+-----+-----+-----+-----+--------+
+----------------------------------+
|         Mode registers           |
+---------+------+------+----------+
| OPBITEN | MODE | DIV2 |  Output  |
+---------+------+------+----------+
|    0    |  0   |  X   |   Sine   |
+---------+------+------+----------+
|    1    |  0   |  X   | Triangle |
+---------+------+------+----------+
|    1    |  0   |  0   |  MSB/2   |
+---------+------+------+----------+
|    1    |  0   |  1   |   MSB    |
+---------+------+------+----------+
*/

#endif /* AD9833_H */