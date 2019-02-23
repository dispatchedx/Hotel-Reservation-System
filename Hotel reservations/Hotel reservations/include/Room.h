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
	int r_count = 0;
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
	
	this->maxCapacity = mCapacity;
	this->pricePerson = pPrice;
	for (int i = 0; i < 30; i++) {
		this->availability.push_back(NULL);
	}
}
//Functions
		bool addBook(Book* new_book); // prosthiki kratisis

		double pricing();	// timologisis

		bool cancelBook(int cancelBookNumber); // akurosi kratisis

		int percentage();	// plirotitas



};
#endif