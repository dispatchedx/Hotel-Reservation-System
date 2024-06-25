// Hotel reservations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "vector"
#include "random"
#include "string"
#include "cstdlib"
#include "iostream"
#include "time.h"

#include "include/Room.h"
#include "include/Room_type_A.h"
#include "include/Room_type_B.h"
#include "include/Room_type_C.h"
#include "include/Room_type_D.h"
#include "include/Room_type_E.h"
#include "include/Hotel.h"

//exei polla bugs akoma

/* TODO known bugs
	?

*/

/* possible features
	add/remove rooms
	adjust pricing
	connection possiblity to real databases (mysql)
	tell the dates that are already reserved when unsucessful?
*/
class Room;
int main() {
	//int ranvar = rand() % 30;
	//Book* newreservation = new Book;

	Hotel Winston = Hotel("Winston");
	RoomTA RA1 = RoomTA(4, 10,40); //it puts default values instead of 4,10
	//RA1.setMaxCapacity(4);
	//RA1.setPricePerson(10);
	RoomTA* A1 = &RA1;
	Winston.add_Room(A1);
	RoomTB RB1 = RoomTB(4, 10, 50, 5);
	RoomTB* B1 = &RB1;
	Winston.add_Room(B1);
	RoomTC RC1 = RoomTC(6, 50, 4, 5);
	RoomTC* C1 = &RC1;
	Winston.add_Room(C1);
	RoomTE RE1 = RoomTE(2, 25, 50, true);
	RoomTE* E1 = &RE1;
	Winston.add_Room(E1);
	RoomTE RE2 = RoomTE(3, 20, 50, false);
	RoomTE* E2 = &RE2;
	Winston.add_Room(E2);
	RoomTD RD1 = RoomTD(3, 40, true);
	RoomTD* D1 = &RD1;
	Winston.add_Room(D1);
	RoomTA RA2 = RoomTA(1, 30, 30);
	RoomTA* A2 = &RA2;
	Winston.add_Room(A2);
	RoomTA RA3 = RoomTA(2, 5, 15);
	RoomTA* A3 = &RA3;
	Winston.add_Room(A3);
	RoomTC RC2(7, 15, 4, 2);
	RoomTC* C2 = &RC2;
	Winston.add_Room(C2);
	RoomTB RB2 = RoomTB(10, 5, 100, 10);
	RoomTB* B2 = &RB2;
	Winston.add_Room(B2);
	std::string listName[] = { "Johnny", "Walker", "Smith", "Andrea", "Watermelon", "Bird", "Exile", "Nothing", "Lee", "Ayumi" };
	for (int i = 0; i < 5; i++) {
		int ran_people = rand() % 6;
		int ran_arrival_day = rand() % 31 + 1;
		int ran_days = rand() % 5 + 1; //(32 - ran_arrival_day) + +1;
		int ran_string = rand() % 10;
		std::string clientName = listName[ran_string];
		Book* test = new Book(clientName, ran_arrival_day, ran_days, ran_people); //not like this
		Winston.add_reservation(test);

		srand(time(NULL));
		int dice = rand() % 101 + 1;
		if (dice < 25) {
			int eraser = rand() % Winston.reservations_List.size();
			//Winston.reservations_List.erase(Winston.reservations_List.begin() + eraser);		exei 25% pithanotita na diagrapsei, alla den diagrafei.. 
	//		Winston.cancel_reservation(Winston.reservations_List[eraser]->getBookNumber());            FIX THIS
		}
	}

	int input = 0;
	while (input != 99) {
		std::cout << "\nChoose an option:" << std::endl;
		std::cout << "1. Add a reservation " << std::endl;
		std::cout << "2. Cancel a reservation  " << std::endl;
		std::cout << "3. View hotel's reservation " << std::endl;
		std::cout << "4. View all the rooms of the hotel" << std::endl;
		std::cout << "5. View reservation plan" << std::endl;
		std::cout << "6. View income" << std::endl;
		std::cout << "99. exit" << std::endl;
		std::cout << "Press any other number to refresh" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin >> input;

		switch (input) {
		case 1:
		{ // putting brackets inside cases allows the initialization of variables, since scope is now specific to each case
			int room_id = -1;
			int arrival = -1;
			int days = -1;
			int people = -1;
			std::string answer = "";
			std::string cName;

			std::cout << "What is your name?" << std::endl;
			std::cin.ignore();
			getline(std::cin, cName);
			if (cName.empty()){ std::cout <<  "Incorrect Value, please try again"; continue;}
			
			std::cout << "When will you arrive?" << std::endl;
			std::cin >> arrival;
			if (std::cin.fail()){std::cout <<  "Invalid input, please enter a number between 1-30";continue;}
			if (arrival<1 || arrival > 30) { std::cout <<  "Please enter a number between 1-30";continue;}
			
			std::cout << "How many days will you stay?" << std::endl;
			std::cin >> days;
			if (std::cin.fail()){std::cout <<  "Invalid input, please enter a number between 1-30";continue;}
			if (days<1 || days > 30) { std::cout <<  "Please enter a number between 1-30";continue;}
			
			std::cout << "How many people will stay?" << std::endl;
			std::cin >> people;
			if (std::cin.fail()){std::cout <<  "Invalid input, please enter a number between 1-5";continue;}
			if (days<1 || days > 30) { std::cout <<  "Please enter a number between 1-5";continue;}			
			Book* p_newreservation = new Book(cName, arrival, days, people);
			
			std::cout << "Would you like a specific room? (y for yes n for no)" << std::endl;
			std::cin >> answer;
			if (answer == "y") {
				std::cout << "What is the room's ID?" << std::endl;
				std::cin >> room_id;

				if (Winston.get_room_by_code(room_id) != NULL) {
					Winston.add_reservation_to_room(p_newreservation, room_id);
				}
			}
			else {
				Winston.add_reservation(p_newreservation);
			}
			break;
		}
		case 2:
		{
			int cancel_id = -1;

			std::cout << "What is the reservation ID you want to cancel?" << std::endl;
			std::cin >> cancel_id;
			Winston.cancel_reservation(cancel_id);
			break;
		}
		case 3:
		{
			std::cout << "Booking id | Name of Customer | Room id" << std::endl;//TODO maybe catch error for empty reservation
			for (int i = 0; i <= Winston.reservations_List.size() - 1; i++) {
				int reservation_id = Winston.reservations_List.at(i)->getBookNumber();
				std::cout << " " << reservation_id << "\t | "; 
				std::cout << Winston.reservations_List.at(i)->getCustomerName() << " \t| ";
				std::cout << Winston.reservations_List.at(i)->getRoom()->getRoomNumber() << std::endl;
			}
			break;
		}
		case 4:
		{
			std::cout << "room code | percentage | Income from this room" << std::endl;
			for (int i = 0; i < Winston.rooms_List.size(); i++) {
				std::cout << Winston.rooms_List.at(i)->getRoomNumber() << "\t  | ";
				std::cout << Winston.rooms_List.at(i)->percentage() << "\t\t | ";
				std::cout << Winston.rooms_List.at(i)->pricing() << std::endl;
			}
			break;
		}
		case 5:
		{
			Winston.reservation_plan();
			break;
		}
		case 6:
		{
			int rooms_id = -1;
			std::string answer = "";

			std::cout << "Do you want the income for a certain room (y for yes n for no)" << std::endl;
			std::cin >> answer;

			if (answer == "y") {
				std::cout << "What is the room number" << std::endl;
				std::cin >> rooms_id;

				if (Winston.get_room_by_code(rooms_id) != NULL) {
					std::cout << Winston.calculate_income(rooms_id) << std::endl; //TODO check if the values are correctly calculated
				}
				else {
					std::cout << "It looks like there is no room with this id: " << rooms_id << std::endl; // i think this can never be reached but it shouldn't matter
				}
			}
			else {
				std::cout << "Total income for this hotel is: " << Winston.calculate_income() << std::endl;
			}
			break;
		}
		} // end switch
	} // end while
}
