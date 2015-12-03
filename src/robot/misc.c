/**
 * Miscellaneous functions to make my life easier.
 */
 #include "misc.h"

bool flag(int bit, int flags) {
	return (flags & bit)==bit;
}

double map(double value, double min1, double min2, double max1, double max2)
{
	return min2+(max2-min2)*((value-min1)/(max1-min1));
}