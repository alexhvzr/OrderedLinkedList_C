//
// Created by Alex on 10/16/2018.
//
#include "Flight.h"
#include <iostream>
using namespace std;

class FlightManager{
    int flight;
    Passenger p;
    Flight *f = new Flight[NUMBER_OF_FLIGHTS];
    void addFirstName(){
        string answer1;
        getline(cin,answer1);
        if(!validateName(answer1)){
            p.setFName(answer1);
        } else {
            cout << "A name cannot contain numbers, please try entering the first name again:" << endl;
            addFirstName();
        }
    }
    void addLastName(){
        string lname;
        getline(cin,lname);
        if(!validateName(lname)){
            p.setLName(lname);
        } else {
            cout << "A name cannot contain numbers, please try entering the last name again:" << endl;
            addLastName();
        }
    }
    void addPhoneNumber(){
        string phone;
        getline(cin,phone);
        if(!validateNumber(phone)){
            p.setPhoneNum(phone);
        } else {
            cout << "A phone number cannot contain letters, please try again:" << endl;
            addPhoneNumber();
        }
    }
    void addFlight(){
        int flightNumber;
        cin >> flightNumber;
        if (flightNumber == 100 || flightNumber == 200 || flightNumber == 300 || flightNumber == 400) {
            p.setFlightNumber(flightNumber);
            flight = flightNumber;
        } else {
            cout << "Invalid flight number please select 100, 200, 300, or 400:" << endl;
            addFlight();
        }
        //check what flight number is here then assign it to the right place.
        for(int i =0; i<NUMBER_OF_FLIGHTS; i++){
            if(flight == ((i+1)*100)){
                f[i].addPassenger(p);
            }
        }
    }

public:
    void createFlightList();
};

void FlightManager::createFlightList() {

    char task;

    cout << "Welcome to Delta Airlines (Please select one):" << endl;
    while (!((task == 'Q') || (task == 'q'))) {
        cout << "A(Add) | S(Search)  D(Delete) |L(List) | Q(Quit): ";
        cin >> task;
        //switch case to see what character the user inputs
        switch (task) {
            case 'a':
            case 'A': {
                cout << "Enter first name:" << endl;
                cin.ignore();
                addFirstName();
                string address;
                cout << "Enter last name:" << endl;
                addLastName();
                cout << "Enter address:" << endl;
                getline(cin,address);
                p.setAddress(address);
                cout << "Enter phone:" << endl;
                addPhoneNumber();
                cout << "Enter flight number" << endl;
                addFlight();

            }
                break;
            case 's':
            case 'S': {
                cin.ignore();
                cout << "Enter first name:" << endl;
                addFirstName();
                cout << "Enter last name:" << endl;
                addLastName();
                for (int i = 0; i < NUMBER_OF_FLIGHTS; i++) {
                    try {
                        f[i].searchPassenger(p);
                    } catch (int){
                        throw MyException("Person Not Found",-1);
                    };
                }
            }
                break;
            case 'd':
            case 'D': {
                cin.ignore();
                cout << "Enter Flight Number: " << endl;
                addFlight();
                cin.ignore();
                cout << "Enter first name:" << endl;
                addFirstName();
                cout << "Enter last name:" << endl;
                addLastName();
                f[(flight/100)-1].delPassenger(p);
            }
                break;
            case 'l':
            case 'L': {
                cin.ignore();
                cout << "Enter Flight Number: " << endl;
                addFlight();
                f[(flight/100)-1].displayPassengers();
                cout << "\n" <<endl;
            }
                break;
            case 'q':
            case 'Q': {
                cout << "Hope you enjoyed flying Delta!" <<endl;
            }
                break;
                //default opperator will print error method if none of the cases are true
            default:
                cout << "Invalid Selection. Please try Again." << endl;
        }
    }

}
