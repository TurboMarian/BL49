/*
 * helpers.h
 *
 * Created: 27.10.2021 14:51:29
 *  Author: Heinrich
 */ 


#ifndef HELPERS_H_
#define HELPERS_H_

static __inline uint16_t __bswap_16(uint16_t __x)
{
	return (__x << 8)|(__x >> 8);
}

static __inline uint16_t __make_u16t(uint8_t __x1, uint8_t __x2)
{
	// return (uint16_t)((__x2 << 8) + (__x1 & 0x00ff));
	return ((uint16_t) __x2 << 8) | __x1;
}

#define bswap_16(x) __bswap_16(x)
#define make_u16t(x1,x2) __make_u16t(x1, x2)



#endif /* HELPERS_H_ */