/**
 * Miscellaneous functions to make my life easier.
 */
 #include "misc.h"

bool flag(int bit, int flags) {
	return (flags & bit)==bit;
}