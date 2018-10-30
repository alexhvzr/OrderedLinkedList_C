//
// Created by Alex on 10/14/2018.
//

#ifndef ASSIGNMENT2CS300_PASSENGER_H
#define ASSIGNMENT2CS300_PASSENGER_H


#include <string>
#include <iostream>
#include "OrderedLinkedList.h"
using namespace std;
class Passenger{

    string fName, lName, address, phoneNum;
    int flightNumber;
public:
    int getFlightNumber() const;

    void setFlightNumber(int flightNumber);

public:
    int charLnameVal();
    Passenger(){}
    Passenger(string fName, string lName, string address, string phoneNum) : fName(fName), lName(lName), address(address), phoneNum(phoneNum){}
    friend ostream& operator<< (ostream &os, Passenger&);

    const string &getFName() const {
        return fName;
    }

    void setFName(const string &fName) {
        Passenger::fName = fName;
    }

    const string &getLName() const {
        return lName;
    }

    void setLName(const string &lName) {
        Passenger::lName = lName;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Passenger::address = address;
    }

    const string &getPhoneNum() const {
        return phoneNum;
    }

    void setPhoneNum(const string &phoneNum) {
        Passenger::phoneNum = phoneNum;

    }
    bool operator<(Passenger p){
        return lName < p.lName;
    }
    bool operator>(Passenger p){

        return lName > p.lName;
    }
    bool operator==(Passenger& p){
        return lName == p.lName;
    }
    friend ostream& operator<<(ostream& os, Passenger& pass) {

        os << "First Name: " << pass.fName
           << "\nLast Name: " << pass.lName
           << "\nAddress: " << pass.address
           << "\nPhone Number: " << pass.phoneNum
           << "\nFlight Number: " << pass.flightNumber;

        return os;
    }

};

int Passenger::getFlightNumber() const {
    return flightNumber;
}

void Passenger::setFlightNumber(int flightNumber) {
    Passenger::flightNumber = flightNumber;
}


#endif //ASSIGNMENT2CS300_PASSENGER_H
