#ifndef ROOM_TYPE_B
#define ROOM_TYPE_B
#include "Room_type_A.h"

class RoomTB : public RoomTA { // capacity, pricePerson, priceDay, discountPerDay
private:
	int discountPerDay;
public: 
	RoomTB(int mCapacity, double pPrice, double pricePerDay, int discountPerDay) {
	RoomTA::RoomTA(mCapacity, pPrice, pricePerDay);
	this->discountPerDay = discountPerDay;
}
	RoomTB() {
		
	}
		double pricing();

		bool cancelBook(int cancelBookNumber);

};
#endif