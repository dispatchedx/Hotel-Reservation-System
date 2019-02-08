#include "stdafx.h"
#include "Room.h"
#include <vector>
#include "iostream"

int Room::roomNumber=0; 

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
	 if(new_book->getArrival()+new_book->getDaysOfResidence()<30){
		 for (unsigned int i = new_book->getArrival() - 1; i < new_book->getArrival() + new_book->getDaysOfResidence() - 1; i++) {
				 if (availability[i] != NULL){
				 availability[i] = new_book; 
				 new_book->setRoom(this); 
			 }
			 else{
			 return false;
			 }
		 }
		 return true;
	 
	 return false;}
	 }
	 else
		 std::cout << "The room is either already booked or is too small" << std::endl;
	 return false;
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

		bool Room::cancelBook(int cancelBookNumber) {
			availability[cancelBookNumber] = NULL;
			return true;
		}

		int Room::percentage() {
			int percentCount = 0;
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