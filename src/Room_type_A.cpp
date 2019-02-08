#include "stdafx.h"
#include "Room_type_A.h"
double RoomTA::pricing() {
	double final_price = 0;
	for (unsigned int i = 0; i<availability.size(); i++)
	{
		if (availability[i] != NULL)
			final_price += pricePerDay;
	}
	return final_price;
}