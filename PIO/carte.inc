@ Plan de ce qui suit
@ ===================
@ définition horloge
@ adresses de base des circuits
@ offsets pour accéder aux registres du PIO
@ offsets pour accéder aux registres de l'AIC
@ offsets pour accéder aux registres du timer
@ offsets pour accéder aux registres de l'USART
@ constantes pour les LEDs, les boutons-poussoirs et l'initialisation de l'USART



@ ===============================================================
@ Définition horloge du processeur
@ ===============================================================
.equ	MCK,		66000000

@ ===============================================================
@ Adresses de base des circuits de la carte
@
@ ===============================================================

@ Adresse de base du PIO
.equ	PIO_BASE,	0xFFFF0000      @ Adresse de base PIO

@ Adresse de base du contrôleur d interruptions
.equ	AIC_BASE,	0xFFFFF000

@ Adresse de base du timer
.equ	TC0_BASE,	0xFFFE0000
.equ	TC1_BASE,	0xFFFE0040
.equ	TC2_BASE,	0xFFFE0080

@ Adresse de base des USART
.equ USART1_BASE,       0xFFFCC000      @ Adresse de base USART 1  
.equ USART0_BASE,       0xFFFD0000      @ Adresse de base USART 0  


@ ===============================================================
@ Offsets des adresses des  registres   des circuits 
@ à ajouter à l adresse de base
@ ===============================================================
@ offsets des registres du PIO
.equ	PIO_PER,		0x00	@ PIO Enable Register 
.equ	PIO_PDR,		0x04	@ PIO Disable Register 
.equ	PIO_PSR,		0x08	@ PIO Status Register 
.equ	PIO_RES0,		0x0C	@ Reserved 0 
.equ	PIO_OER,		0x10	@ Output Enable Register 
.equ	PIO_ODR,		0x14	@ Output Disable Register 
.equ	PIO_OSR,		0x18	@ Output Status Register 
.equ	PIO_RES1,		0x1C	@ Reserved 1 
.equ	PIO_IFER,		0x20	@ Input Filter Enable Register 
.equ	PIO_IFDR,		0x24	@ Input Filter Disable Register 
.equ	PIO_IFSR,		0x28	@ Input Filter Status Register 
.equ	PIO_RES2,		0x2C	@ Reserved 2 
.equ	PIO_SODR,		0x30	@ Set Output Data Register 
.equ	PIO_CODR,		0x34	@ Clear Output Data Register 
.equ	PIO_ODSR,		0x38	@ Output Data Status Register 
.equ	PIO_PDSR,		0x3C	@ Pin Data Status Register 
.equ	PIO_IER,		0x40	@ Interrupt Enable Register 
.equ    PIO_IDR,		0x44	@ Interrupt Disable Register 
.equ    PIO_IMR,		0x48	@ Interrupt Mask Register 
.equ    PIO_ISR,		0x4C	@ Interrupt Status Register 
.equ    PIO_MDER,		0x50	@ Interrupt Enable Register 
.equ    PIO_MDDR,		0x54	@ Interrupt Disable Register 
.equ    PIO_MDSR,		0x58	@ Interrupt Status Register 

@ offsets des registres de l'AIC par rapport à AIC_BASE
.equ	AIC_SMR,	0x000		@ Base Source Mode Registers
.equ	AIC_SMR3,	AIC_SMR+3*4	@ Source Mode Register 3  (correspond à usart 1)
.equ	AIC_SMR5,	AIC_SMR+5*4	@ Source Mode Register 5  (correspond à timer 1)
.equ	AIC_SMR8,	AIC_SMR+8*4	@ Source Mode Register 8  (correspond à pio)
.equ	AIC_SVR,	0x080  		@ Base Source Vector Registers
.equ	AIC_SVR3,	AIC_SVR+3*4     @ Source Vector Register 3 (correspond à usart 1)
.equ	AIC_SVR5,	AIC_SVR+5*4     @ Source Vector Register 5 (correspond à timer 1)
.equ	AIC_SVR8,	AIC_SVR+8*4     @ Source Vector Register 8 (correspond à pio)
.equ	AIC_IVR,	0x100  		@ IRQ Vector Register 
.equ	AIC_FVR,	0x104  		@ FIQ Vector Register 
.equ	AIC_ISR,	0x108  		@ Interrupt Status Register 
.equ	AIC_IPR,	0x10C  		@ Interrupt Pending Register 
.equ	AIC_IMR,	0x110  		@ Interrupt Mask Register 
.equ	AIC_CISR,	0x114 		@ Core Interrupt Status Register 
.equ	AIC_RES1,	0x118 		@ Reserved 0 
.equ	AIC_RES2,	0x11C 		@ Reserved 1 
.equ	AIC_IECR,	0x120 		@ Interrupt Enable Command Register 
.equ	AIC_IDCR,	0x124 		@ Interrupt Disable Command Register 
.equ	AIC_ICCR,	0x128 		@ Interrupt Clear Command Register 
.equ	AIC_ISCR,	0x12C 		@ Interrupt Set Command Register 
.equ	AIC_EOICR,	0x130		@  of Interrupt Command Register 
.equ	AIC_SPU,	0x134  		@ Spurious Vector Register 

@ offset des registres du timer
.equ    TC_BCR,          0xC4
.equ    TC_BMR,          0xC8
@ offsets des registres du timer 0 par rapport à TC_BASE
.equ	TC_CCR,		0x00 @ Control Register
.equ	TC_CMR,		0x04 @ Mode register
.equ	TC_CV,		0x10 @ Value Register (en lecture seulement)
.equ	TC_RC,		0x1c @ Registre de comparaison
.equ	TC_SR,		0x20 @ Status Register (en lecture seulement)
.equ	TC_IER,		0x24 @ Interrupt Enable Register (en ecriture seulement)
.equ	TC_IDR,		0x28 @ Interrupt Disable Register (en ecriture seulement)
.equ	TC_IMR,		0x2C @ Interrupt Mask Register (en lecture seulement)


@ Offset des registres de l'USART
.equ    US_CR,      	0x00			/* Control Register */
.equ    US_MR,       0x04			/* Mode Register */
.equ    US_IER,       0x08			/* Interrupt Enable Register */
.equ    US_IDR,       0x0C			/* Interrupt Disable Register */
.equ    US_IMR,       0x10			/* Interrupt Mask Register */
.equ    US_CSR,       0x14			/* Channel Status Register */
.equ    US_RHR,       0x18			/* Receive Holding Register */
.equ    US_THR,       0x1C			/* Transmit Holding Register */
.equ    US_BRGR ,       0x20			/* Baud Rate Generator Register */
.equ    US_RTOR ,       0x24			/* Receiver Timeout Register */
.equ    US_TTGR ,       0x28			/* Transmitter Time-guard Register */
.equ    US_RES,       0x2C			/* Reserved */
.equ    US_RPR,       0x30			/* Receiver Pointer Register */
.equ    US_RCR,       0x34			/* Receiver Counter Register */
.equ    US_TPR,       0x38			/* Transmitter Pointer Register */
.equ    US_TCR,       0x3C			/* Transmitter Counter Register */


@ ===============================================================
@ Constantes pour initialiser
@ ===============================================================

@ Ports du PIO correspondant aux LEDS
.equ	LED1,       0b10000000000000000	        @ La LED1 est sur P16
.equ	LED2,       0b100000000000000000        @ La LED2 est sur P17 
.equ	LED3,       0b1000000000000000000       @ La LED3 est sur P18 
.equ	LED4,       0b10000000000000000000      @ La LED4 est sur P19         
.equ	LED5,       0b1000		        @ La LED5 est sur P3        
.equ	LED6,       0b10000		        @ La LED5 est sur P4
.equ	LED7,       0b100000		        @ La LED5 est sur P5
.equ	LED8,       0b1000000		        @ La LED5 est sur P6


@ Ports du PIO correspondant aux boutons-poussoirs
.equ	SW1,       0b1000000000000	@ SW1 est sur P12
			@ ou 0x1000 
			@ ou (1<<12) 
.equ	SW2,       0b1000000000	@ (1<<9) SW2 est sur P9
.equ	SW3,       0b10		@ SW3 est sur P1
.equ	SW4,       0b100		@ SW4 est sur P2


@ US_CR : registre de contrôle

.equ US_RSTRX,      0x0004      @ Reset Receiver 
.equ US_RSTTX,      0x0008      @ Reset Transmitter 
.equ US_RXEN ,      0x0010      @ Receiver Enable 
.equ US_RXDIS,      0x0020      @ Receiver Disable 
.equ US_TXEN ,      0x0040      @ Transmitter Enable 
.equ US_TXDIS,      0x0080      @ Transmitter Disable 
.equ US_RSTSTA,     0x0100      @ Reset Status Bits 
.equ US_STTBRK,     0x0200      @ Start Break 
.equ US_STPBRK,     0x0400      @ Stop Break 
.equ US_STTTO,      0x0800      @ Start Time-out 
.equ US_SENDA,      0x1000      @ Send Address 

@ US_MR : Mode Register

.equ US_CLKS ,       0x0030      @ Clock Selection 
.equ US_CLKS_MCK,   0x00        @ Master Clock 
.equ US_CLKS_MCK8,  0x10        @ Master Clock divided by 8 
.equ US_CLKS_SCK,    0x20        @ External Clock 
.equ US_CLKS_SLCK,   0x30        @ Slow Clock 
										
.equ US_CHRL,        0x00C0      @ Byte Length 
.equ US_CHRL_5,      0x00        @ 5 bits 
.equ US_CHRL_6,      0x40        @ 6 bits 
.equ US_CHRL_7,      0x80        @ 7 bits 
.equ US_CHRL_8,      0xC0        @ 8 bits 
										
.equ US_SYNC,        0x0100      @ Synchronous Mode Enable 
										
.equ US_PAR,         0x0E00      @ Parity Mode 
.equ US_PAR_EVEN,    0x000        @ Even Parity 
.equ US_PAR_ODD,     0x200        @ Odd Parity 
.equ US_PAR_SPACE,   0x400        @ Space Parity to 0 
.equ US_PAR_MARK,    0x600        @ Marked Parity to 1 
.equ US_PAR_NO,      0x800        @ No Parity 

.equ US_NBSTOP,      0x3000      @ Stop Bit Number 
.equ US_NBSTOP_1,    0x0000      @ 1 Stop Bit 
.equ US_NBSTOP_1_5,  0x1000      @ 1.5 Stop Bits 
.equ US_NBSTOP_2,    0x2000      @ Stop Bits 

.equ US_CHMODE,	                  0xC000  @ Channel Mode 
.equ US_CHMODE_NORMAL,            0x0000  @ Normal Mode 
.equ US_CHMODE_AUTOMATIC_ECHO,    0x4000  @ Automatic Echo 
.equ US_CHMODE_LOCAL_LOOPBACK,    0x8000  @ Local Loopback 
.equ US_CHMODE_REMOTE_LOOPBACK,   0xC000  @ Remote Loopback 
										
.equ US_MODE9,       0x20000     @ 9 Bit Mode 
										
.equ US_CLKO ,       0x40000     @ Baud Rate Output Enable 

@  US_IER, US_IDR, US_IMR, US_IMR: registres d état et d interruption
.equ US_RXRDY,       0x001       @ Receiver Ready 
.equ US_TXRDY,       0x002       @ Transmitter Ready 
.equ US_RXBRK,       0x004       @ Receiver Break 
.equ US_ENDRX,       0x008       @ End of Receiver PDC Transfer 
.equ US_ENDTX,       0x010       @ End of Transmitter PDC Transfer 
.equ US_OVRE ,       0x020       @ Overrun Error 
.equ US_FRAME,       0x040       @ Framing Error 
.equ US_PARE ,       0x080       @ Parity Error 
.equ US_TIMEOUT,     0x100       @ Receiver Timeout 
.equ US_TXEMPTY,     0x200       @ Transmitter Empty 

