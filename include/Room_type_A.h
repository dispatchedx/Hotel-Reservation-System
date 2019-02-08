#ifndef ROOM_TYPE_A
#define ROOM_TYPE_A
#include "stdafx.h"
#include "Room.h"
class RoomTA : public Room {//capacity, pricePerson, pricePerDay
	private:
	double pricePerDay;
public:
RoomTA(int mCapacity, double pPrice, double pricePerDay) {
	Room::Room(mCapacity, pPrice);
	this->pricePerDay = pricePerDay;
}
RoomTA() {
}
		double pricing();
};
#endif