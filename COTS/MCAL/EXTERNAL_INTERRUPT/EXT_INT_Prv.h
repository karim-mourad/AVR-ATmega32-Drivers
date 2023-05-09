#ifndef EXT_INT_PRV_H_
#define EXT_INT_PRV_H_




#define INT0_CLR		0b00000011
#define INT1_CLR		0b00001100


#define		MCUCR	*((volatile u8*) 0x55)
#define		MCUCSR	*((volatile u8*) 0x54)
#define		GICR	*((volatile u8*) 0x5B)
#define		GIFR	*((volatile u8*) 0x5A)



#endif /* EXT_INT_PRV_H_ */