#include "stdafx.h"
#include "Room_type_E.h"


double RoomTE::pricing() {

	double final_price = 0;
	for (unsigned int i = 0; i<availability.size(); i++)
	{
		if (availability[i] != NULL)
			final_price += getPricePerson()*availability[i]->getPeople();
	}
	if (couple) {
		final_price *= 0.8;
	}
	return final_price;

}