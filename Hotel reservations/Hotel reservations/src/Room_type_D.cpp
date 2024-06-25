#include "../include/Room_type_D.h"

double RoomTD::pricing() {
	double final_price = 0;
	for (unsigned int i = 0; i<availability.size(); i++)
	{
		if (availability[i] != NULL)
			final_price += this->getPricePerson()*availability[i]->getPeople();
	}
	return final_price*1.2;
}