#ifndef FIXED_POINT_MATH_H
#define FIXED_POINT_MATH_H

#include <stdint.h>

typedef int32_t fixed_24_8_t;

#define INT_TO_FIXED(x) ((x) << 8)
#define FLOAT_TO_FIXED(x) ((int32_t)((x) * 256.0f))

#define MULT_FIXED(a, b) ((int32_t)((((int64_t)(a)*(b)) >> 8)))
#define DIV_FIXED(a, b) ((int32_t)(((int64_t)(a) << 8)/(b)))

#define FLOOR(x) ((x) & ~0x0FF)
#define CEIL(x) FLOOR(((x) + 0x00FF))
#define ROUND(x) FLOOR(((x) + 0x0080))
#define FRAC(x) ((x) & 0x00FF)

#define ABS(x) (((x) ^ ((x) >> 31)) - ((x) >> 31))

#define FIXED_TO_INT(x) ((x) >> 8)
#define FLOOR_TO_INT(x) ((x) >> 8)
#define CEIL_TO_INT(x) (((x) + 0x00FF) >> 8)
#define ROUND_TO_INT(x) (((x) + 0x0080) >> 8)

#endif
