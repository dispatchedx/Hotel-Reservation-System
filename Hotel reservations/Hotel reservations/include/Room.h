#ifndef ROOM_H
#define ROOM_H

#include "Book.h"
#include <vector>

class Book;
class Room {
private:
	
	double pricePerson;
public:
	int maxCapacity;
	int r_count = -1;
	std::vector<Book*> availability;
	static int roomNumber; //unique
//getters+setters
	
	
int getMaxCapacity();
	//get megisti xoritikotita

void setMaxCapacity(int maxCapacity);
	//set megisti xoritikotita

double getPricePerson();
	//get timi ana atomo

void setPricePerson(double pricePerson);
	//set timi ana atomo

int getRoomNumber();
	//get arithmos domatiou

//Default constractor
Room() {
	this->r_count = ++roomNumber;
	for (int i = 0; i < 30; i++) {
		this->availability.push_back(NULL);
	}
}
//Overload constructor
Room(int mCapacity, double pPrice) {
	this->r_count = ++roomNumber;
	maxCapacity = mCapacity;
	pricePerson = pPrice;
	for (int i = 0; i < 30; i++) {
		this->availability.push_back(NULL);
	}
}
//Functions
		bool addBook(Book* new_reservation); // prosthiki kratisis

		double pricing();	// timologisis

		bool cancelBook(int cancelBookNumber); // akurosi kratisis

		int percentage();	// plirotitas



};
#endif