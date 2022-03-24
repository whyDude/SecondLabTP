#include "Stack.h"
Stack& operator*(int l, Stack& r) {
	return r * l; // r.operator*(l)
}