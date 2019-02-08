#include "stdafx.h"
#include "Room_type_C.h"
#include "iostream"

bool RoomTC::addBook(Book* new_book) {
	if (new_book->getPeople() <= this->getMaxCapacity() && new_book->getPeople() >= this->leastPeople
		&& new_book->getDaysOfResidence() >= this->leastDays) {
		for (int i = new_book->getArrival(); i <= new_book->getArrival() + new_book->getDaysOfResidence(); i++) {
			if (availability[i] != NULL) {
				availability[i] = new_book;
				new_book->setRoom(this);
			}
			else {
				std::cout << "Unfortunately the room is booked on " << i <<std::endl;
			}
		}
		return true;
	}
	else {
		std::cout << "Unfortunately there are too many/few people to book this room." << std::endl;
		return false;
	}
}