#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#ifdef AD9833_DEBUG
    #define AD9833_DBG(__info__, ...) { fprintf(stderr, "[AD9833-DBG]: <%s> %d: " __info__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fprintf(stderr, "\n"); }
#else
    #define AD9833_DBG(__info__, ...)
#endif /* AD9833_DEBUG */

#define AD9833_WARN(__info__, ...) { fprintf(stderr, "[AD9833-WARN]: <%s> %d: " __info__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fprintf(stderr, "\n"); }
#define AD9833_ERR(__info__, ...) { fprintf(stderr, "[AD9833-ERR]: <%s> %d: " __info__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fprintf(stderr, "\n"); }

#ifdef DEV_DEBUG
    #define DEV_DBG(__info__, ...) { fprintf(stderr, "[DEV-DBG]: <%s> %d: " __info__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fprintf(stderr, "\n"); }
#else
    #define DEV_DBG(__info__, ...)
#endif

#define DEV_ERR(__info__, ...) { fprintf(stderr, "[DEV-ERR]: <%s> %d: " __info__, __FUNCTION__, __LINE__, ##__VA_ARGS__); fprintf(stderr, "\n"); }

#endif /* DEV_DEBUG */
