#ifndef BITS_H
#define BITS_H

#define BIT_MASK(bits) ((1 << (bits)) - 1)
#define BITS(value, a, b) (((value) >> (a)) & BIT_MASK((b) - (a) + 1))

#define SIGN_EXT(value, origSize) (((int32_t)(value) << (32 - (origSize))) >> (32 - (origSize)))

#endif
