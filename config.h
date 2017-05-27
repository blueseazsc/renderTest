#ifndef CONFIG_H
#define CONFIG_H

#define FLOAT_BASIC_PRECISION   1e-3
#define FLOAT_PRECISION 1e-6

inline bool IsZero(float f) {
	return f < FLOAT_PRECISION && f > -FLOAT_PRECISION;
}

#endif
