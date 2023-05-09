#ifndef G_INT_H_
#define G_INT_H_



typedef enum
{
	G_INT_enuNOK =0,
	G_INT_enuOK
	
}G_INT_enuErrorStatus;


G_INT_enuErrorStatus GIE_INIT(void);
G_INT_enuErrorStatus GIE_DIS(void);


#endif /* G_INT_H_ */