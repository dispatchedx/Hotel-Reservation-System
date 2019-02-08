#include "stdafx.h"
#include "Book.h"
#include "string"

int Book::bookNumber=0;
std::string Book::getCustomerName() {
	return customerName;
}
void Book::setCustomerName(std::string customerName) {
	this->customerName = customerName;
}
int Book::getArrival() {
	return arrival;
}
void Book::setArrival(int arrival) {
	this->arrival = arrival;
}
int Book::getDaysOfResidence() {
	return daysOfResidence;
}
void Book::setDaysOfResidence(int daysOfResidence) {
	this->daysOfResidence = daysOfResidence;
}
Room Book::getRoom() {
	return *pRoom; // care
}
void Book::setRoom(Room* room) {
	this->pRoom = room;
}
int Book::getPeople() {
	return this->people;
}
void Book::setPeople(int people) {
	this->people = people;
}
int Book::getBookNumber() { //used to be static
	return bookNumber;
}