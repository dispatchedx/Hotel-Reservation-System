#include "../pch.h"
#include "../include/Room.h"
#include <vector>
#include "iostream"

int Room::roomNumber=-1; 

int Room::getMaxCapacity() {
	return maxCapacity;
}
void Room::setMaxCapacity(int maxCapacity) {
	this->maxCapacity = maxCapacity;
}
double Room::getPricePerson() {
	return pricePerson;
}
void Room::setPricePerson(double pricePerson) {
	this->pricePerson = pricePerson;
}
 int Room::getRoomNumber() { //maybe need to put it static.. NO STATIC IN CPP ONLY ON HEADERS
	return r_count;
}
 bool Room::addBook(Book* new_book) {
	 if (new_book->getPeople() <= maxCapacity) {
		 int res_arrival = new_book->getArrival();
		 int res_days_residence = new_book->getDaysOfResidence();
		 if (res_arrival + res_days_residence-1 <= 30) { //TODO make variables for these results and fix IF block
			 for (unsigned int i = res_arrival - 1; i < res_arrival + res_days_residence - 1; i++) {
				 if (availability[i] != NULL) {
					 return false;
				 }
			 }
			 for (unsigned int i = res_arrival - 1; i < res_arrival + res_days_residence - 1; i++) {
				 availability[i] = new_book;
				 new_book->setRoom(this);
			 }
		 }
		 else {
			 std::cout << "The room is either already booked or is too small" << std::endl;
			 return false;
		 }
		 return true;
	 }
	 
	 else {
		 std::cout << "The room is too small" << std::endl;
		 return false;
	 }
 }

double Room::pricing() {
	double final_price = 0;
	for (unsigned int i = 0; i<availability.size(); i++)
	{
		if (availability[i] != NULL)
			final_price += pricePerson*availability[i]->getPeople();
	}
	return final_price;
}

bool Room::cancelBook(int reservationID) {
	for (int i = 0; i < availability.size(); i++){
		if (availability[i]!=NULL && availability[i]->getBookNumber() == reservationID)
			availability[i] = NULL;
	//int arrivalDay = availability[reservationID]->getArrival();
	//int daysStaying = availability[reservationID]->getDaysOfResidence();
	//for (int i = arrivalDay; i <= arrivalDay + daysStaying; i++) { //TODO check, though i think its fixed
	//	availability[i] = NULL;
	}
	return true;
}

int Room::percentage() {
	double percentCount = 0;
	for (unsigned int i = 0; i<availability.size(); i++)
	{
		if (availability[i] != NULL)
			percentCount++;
	}
	return (percentCount / 30) * 100;
}

/*int main(){
std::vector< Book* > availability;
availability.resize(30);
Room::roomNumber = 0;
}*/