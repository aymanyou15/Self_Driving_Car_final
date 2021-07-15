#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "SPI_register.h"
#include "../GPIO/GPIO_interface.h"

/* SPCR register */
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE  6
#define SPIE 7

/* SPSR register */
#define SPI2X 0
#define WCOL  6
#define SPIF 7

void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(void);

#endif /* GPIO_INTERFACE_H */