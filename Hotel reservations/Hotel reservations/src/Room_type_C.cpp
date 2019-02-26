#include "../pch.h"
#include "../include/Room_type_C.h"
#include "iostream"

bool RoomTC::addBook(Book* new_reservation) {
	if (new_reservation->getPeople() <= this->getMaxCapacity() && new_reservation->getPeople() >= this->leastPeople
		&& new_reservation->getDaysOfResidence() >= this->leastDays) {
		for (int i = new_reservation->getArrival(); i <= new_reservation->getArrival() + new_reservation->getDaysOfResidence(); i++) {
			if (availability[i] != NULL) { //TODO possible issue if its reserved
				availability[i] = new_reservation;
				new_reservation->setRoom(this);
			}
			else {
				std::cout << "Unfortunately the room is reserved on " << i <<std::endl;
			}
		}
		return true;
	}
	else {
		std::cout << "Unfortunately there are too many/few people to book a reservation this room." << std::endl;
		return false;
	}
}