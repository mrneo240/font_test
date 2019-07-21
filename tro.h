#ifndef __TRO_H
#define __TRO_H

#ifndef NULL
#define NULL (void*)0
#endif

typedef unsigned long uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed long int32;
typedef signed short int16;
typedef signed char int8;

/*volatile */static unsigned long *videobase = (unsigned long*)0xa05f8000;
/*volatile */static /*uint32*/ unsigned long* vram_l=(unsigned long*)0xa5000000;
/*volatile */static unsigned short* vram_s=(unsigned short*)0xa5000000;

extern unsigned int sleep(unsigned int seconds);
extern unsigned int sleep_ms(unsigned int ms);

#endif