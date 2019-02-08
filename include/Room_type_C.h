#ifndef ROOM_TYPE_C
#define ROOM_TYPE_C
#include "Room.h"

class RoomTC : public Room { //capacity, pricePerson, leastPeople, leastDays
	int leastPeople;
	int leastDays;

public: RoomTC(int mCapacity, double pPrice, int leastPeople, int leastDays) {
	Room::Room(mCapacity, pPrice);
	RoomTC::leastDays = leastDays;
	RoomTC::leastPeople = leastPeople;
}

		bool addBook(Book* new_book);
};
#endif
