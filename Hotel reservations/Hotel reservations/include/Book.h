#ifndef BOOK_H
#define BOOK_H
#include "Room.h"
#include "string"
class Room;
class Book {
private:
	std::string customerName;
	static int reservationNumber; //unique
	int arrival;
	int daysOfResidence;
	int people;
	int count = -1;
	Room* pRoom = NULL;
	
public:
  Book() {
	this->count = ++reservationNumber;
}

public: Book(std::string cName, int arrival, int dResidence, int people) {
	this->customerName = cName;
	this->count = ++reservationNumber;
	this->arrival = arrival;
	this->daysOfResidence = dResidence;
	this->people = people;
	//  /*this.*/room = room;
}

std::string getCustomerName();

void setCustomerName(std::string customerName);

int getArrival();

void setArrival(int arrival);

int getDaysOfResidence();

void setDaysOfResidence(int daysOfResidence);

Room* getRoom();

void setRoom(Room* room);

int getPeople();

void setPeople(int people);

int getBookNumber(); //TODO this was static
};
#endif // !BOOK_H
