#include "Item.hpp"

bool operator==(const Item& lhs, const Item& rhs)
{
	if (lhs.getName().compare(rhs.getName()) == 0) {
		return true;
	}
	else {
		return false;
	}
}
