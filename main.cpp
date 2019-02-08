#include "stdafx.h"
#include "vector"
#include "Random"
#include "string"
#include "cstdlib"
#include "iostream"
#include "time.h"

#include "Room.h"
#include "Room_type_A.h"
#include "Room_type_B.h"
#include "Room_type_C.h"
#include "Room_type_D.h"
#include "Room_type_E.h"
#include "Hotel.h"
//exei polla bugs akoma
class Room;
int main(){
int ranvar = rand() % 30;
int input = 0;
Book* newbook = new Book;
std::string cName;
	
Hotel Winston = Hotel("Winston");
RoomTA RA1 = RoomTA(4, 10, 40);
RoomTA* A1 =& RA1;
Winston.add_Room(A1);
RoomTB RB1 = RoomTB(4, 10, 50, 5);
RoomTB* B1 =& RB1;
Winston.add_Room(B1); 
RoomTC RC1 = RoomTC(6, 50, 4, 5);
RoomTC* C1 =& RC1;
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
	for (int i = 0; i<5; i++) {
		int ran_people = rand() % 6;
		int ran_arrival_day = rand() % 31 +1;
		int ran_days = rand() %(32 - ran_arrival_day) + +1;
		int ran_string = rand() % 10;
		std::string clientName = listName[ran_string];
		Book* test = new Book(clientName, ran_arrival_day, ran_days, ran_people); //not like this
		Winston.add_booking(test);
			
		srand(time(NULL));
		int dice = rand() %101 +1;
		if (dice < 25) {
			int eraser = rand() %Winston.books_List.size();
			//Winston.books_List.erase(Winston.books_List.begin() + eraser);		exei 25% pithanotita na diagrapsei, alla den diagrafei.. 
	//		Winston.cancel_booking(Winston.books_List[eraser]->getBookNumber());            FIX THIS
		}
	}


while (input != 99) {
		std::cout <<"Choose an option:" << std::endl;
		std::cout << "1. Add a booking " << std::endl;
		std::cout << "2. Cancel a booking  " << std::endl;
		std::cout << "3. View hotel's booking " << std::endl;
		std::cout << "4. View all the rooms of the hotel" << std::endl;
		std::cout << "5. View booking plan" << std::endl;
		std::cout << "6. View income" << std::endl;
		std::cout << "99. exit" << std::endl;
		std::cout << "Press any other key to refresh" << std::endl;
		std::cin.clear();
		//std::cin.ignore();
			std::cin>> input;
		
			
			int room_id = 0;
			int arrival = 0;
			int days = 0;
			int people = 0;
			bool code = false;
			int cancel_id = 0;
		switch (input) {
		case 1:
		//	Book newbook;
			//std::string cName;
			//int arrival = 0;
			//int days = 0;
			//int people = 0;
			//bool code = false;
			//int room_id = 0;
			std::cout << "What is your name?" << std::endl;
			std::cin.ignore();
				getline(std::cin, cName);
			std::cout << "When will you arrive?" << std::endl;
				std::cin>> arrival; 
			std::cout << "How many days will you stay?" << std::endl;
				std::cin >> days; 
			std::cout << "How many people will stay?" << std::endl;
				std::cin >> people;
			
				newbook->setCustomerName(cName);
				newbook->setArrival(arrival);
				newbook->setPeople(people);
				newbook->setDaysOfResidence(days);
				std::cout << "Would you like a specific room? (true for yes false for no)" << std::endl;
				std::cin >> code; 
	

			if (code) {	
					std::cout << "Which is the room's number?" << std::endl;
					std::cin >> room_id;
				}
				if (Winston.get_room_by_code(room_id) != NULL) {
					Winston.add_book_to_room(newbook, room_id);
				}
			
			else {
				Winston.add_booking(newbook);
			}

			break;
		case 2:
			//int cancel_id = 0;
			
				std::cout << "What is the booking ID you want to cancel?" << std::endl;
				std::cin >> cancel_id;
			Winston.cancel_booking(cancel_id);
			break;
		case 3:
			std::cout << "Booking id Name of Customer Room id" << std::endl;
			for (int i = 0; i <= Winston.books_List.size() - 1; i++) {
				std::cout << Winston.books_List.at(i)->getBookNumber() + "\t ";
				std::cout << Winston.books_List.at(i)->getCustomerName() + " \t";
				std::cout << Winston.books_List.at(i)->getRoom().getRoomNumber() << std::endl;
			}
			break;
		case 4:
			std::cout << "room code percentage Income from this room" << std::endl;
			for (int i = 0; i < Winston.rooms_List.size(); i++) {
				std::cout << Winston.rooms_List.at(i)->getRoomNumber() << " ";
				std::cout << Winston.rooms_List.at(i)->percentage() << " ";
				std::cout << Winston.rooms_List.at(i)->pricing() << std::endl;
			}
			break;
		case 5:
			Winston.booking_plan();
			break;
		case 6:
			int rooms_id = 1;
			code = false;
				std::cout << "Do you want the income for a certain room (true for yes false for no)" << std::endl;
				std::cin >> code;
			if (code) {
					std::cout << "What is the room number" << std::endl;
					rooms_id;
				}
					std::cin >> rooms_id;
				if (Winston.get_room_by_code(rooms_id) != NULL) {
					std::cout << Winston.calculate_income(rooms_id) << std::endl;
				}
			else {
				std::cout << Winston.calculate_income() << std::endl;
			}
			break;
		}
	}
}