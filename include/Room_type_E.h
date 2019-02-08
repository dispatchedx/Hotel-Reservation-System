#ifndef ROOM_TYPE_E
#define ROOM_TYPE_E
#include "Room.h"

class RoomTE : public Room {//capacity, pricePerson, pricePerDay, couple
	bool couple;
	double pricePerDay;
public: RoomTE(int maxCapacity, double pPrice, double pricePerDay, bool couple) {
	Room::Room(maxCapacity, pPrice);
	RoomTE::setMaxCapacity(2);
	RoomTE::couple = couple;
	RoomTE::pricePerDay = pricePerDay;
	if (couple)
		RoomTE::pricePerDay *= 0.8;
}

		double pricing();
};


#endif // !ROOM_TYPE_E

