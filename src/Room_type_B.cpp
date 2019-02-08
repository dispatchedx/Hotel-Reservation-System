#include "stdafx.h"
#include "Room_type_B.h"
#include "iostream"
double RoomTB::pricing() {
	int days = 5;
	int pricePerDay = 50;
	int discountPerDay = 10;
	double tempPrice = pricePerDay;
	double finalPayment = 0;
	for (int i = days; i > 0; i--) {
		if (tempPrice >= pricePerDay / 2) {
			finalPayment += tempPrice;
			tempPrice -= discountPerDay;
		}
		else {
			tempPrice = pricePerDay / 2;
			finalPayment += tempPrice;
		}
	}
	return finalPayment;
}

bool RoomTB::cancelBook(int cancelBookNumber) {
	std::cout << "You cannot cancel a booking on this room." << std::endl;
	return false;
}