#ifndef ROOM_TYPE_D
#define ROOM_TYPE_D
#include "Room.h"


class RoomTD : public Room {//capacity, pricePerson, wifi
	bool wifi;
public: RoomTD(int mCapacity, double pPrice, bool wifi) : Room::Room(mCapacity, pPrice) {
	RoomTD::wifi = wifi;
}

		double pricing();
};


#endif // !ROOM_TYPE_D
