#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "AD9833.h"

void sig_handler(int signo)
{
    printf("SIGINT received, exiting\n");
    DEV_ModuleExit();
    exit(0);
}

int main(void)
{
    printf("test ad9833\n");

    if(DEV_ModuleInit())
    {
        printf("dev init failed\n");
        return -1;
    }

    signal(SIGINT, sig_handler);

    AD9833_Write(AD9833_B28 | AD9833_RESET);
    AD9833_SetFreqB28(AD9833_FREQ0, 51000);
    AD9833_Write(AD9833_B28);

    AD9833_Write(AD9833_RESET);
    AD9833_SetFreqLSB(AD9833_FREQ0, 0);
    AD9833_Write(AD9833_HLB);
    AD9833_SetFreqMSB(AD9833_FREQ0, 75000);
    AD9833_Write(AD9833_NON);

    DEV_ModuleExit();

    return 0;
}