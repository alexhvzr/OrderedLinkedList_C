//
// Created by Alex on 10/14/2018.
//

#ifndef ASSIGNMENT2CS300_FLIGHT_H
#define ASSIGNMENT2CS300_FLIGHT_H

using namespace std;
#include "Passenger.h"
#include <iostream>

int NUMBER_OF_FLIGHTS = 4;
class Flight{
    int flightNum;
    OrderedLinkedList<Passenger>* passengers;
public:

    Flight(OrderedLinkedList<Passenger>* _passengers);
    Flight();
    void addPassenger(Passenger&);
    void getPassengerInfo(Passenger&);
    bool searchPassenger(Passenger&);
    int getFlightNum() const;
    void setFlightNum(int &);
    void delPassenger(Passenger&);
    void displayPassengers();
    void destroylist();
    ~Flight();
//    string displayPassengers();

};
Flight::Flight(){
    passengers = new OrderedLinkedList<Passenger>();
}
int Flight::getFlightNum() const {
    return flightNum;
}

void Flight::setFlightNum(int &f) {
    if(f== 100 || f == 200 || f == 300 || f == 400) {
        flightNum = f;
        
    } else {
        throw MyException("Flight not found",-1);

    }
}

void Flight::addPassenger(Passenger& pass ) {
    passengers->insertSorted(pass);
}
bool Flight::searchPassenger(Passenger& pass){
  bool a = passengers->search(pass);
   return a;
}
void Flight::getPassengerInfo(Passenger& pass) {
   cout << pass;
}
void Flight::delPassenger(Passenger& pass) {

    passengers->deleteNode(pass);

}
//template<class T>
//void OrderedLinkedList<T>::destroylist() {
//    node<T> *p;
//    while (this->head != NULL) {
//        p = this->head;
//        this->head = this->head->next;
//        delete p;
//    }
//    this->last = NULL;
//    this->count = 0;
//}
void Flight::displayPassengers() {
   passengers->displayList();
}
Flight::Flight(OrderedLinkedList<Passenger> *passengers) : passengers(passengers) {
    cout << "constructed" <<endl;
}
Flight::~Flight() {
    delete passengers;
}
//string Flight::displayPassengers() {
//while (passengers != NULL){
//    passengers.
//}
//    return "test";
//}

//ostream& operator<<(ostream& os, Flight f) {
//
//    os << f.displayPassengers() <<endl;
//    return os;
//}



#endif //ASSIGNMENT2CS300_FLIGHT_H
