//
// Created by Alex on 10/16/2018.
//
#include "Flight.h"
#include <iostream>
using namespace std;

class FlightManager{

    Flight *f = new Flight[NUMBER_OF_FLIGHTS];

public:
    void createFlightList();
};

void FlightManager::createFlightList() {

    char task;
    int flightNumber;
    cout << "Welcome to Delta Airlines (Please select one):" << endl;
    while (!((task == 'Q') || (task == 'q'))) {
        cout << "A(Add) | S(Search)  D(Delete) |L(List) | Q(Quit): ";
        cin >> task;
        //switch case to see what character the user inputs
        switch (task) {
            case 'a':
            case 'A': {
                Passenger p;
                string answer1 ,answer2, answer3, answer4;
                cin.ignore();
                cout << "Enter first name:" << endl;
                getline(cin,answer1);
                p.setFName(answer1);
                cout << "Enter last name:" << endl;
                getline(cin,answer2);
                p.setLName(answer2);
                cout << "Enter address:" << endl;
                getline(cin,answer3);
                p.setAddress(answer3);
                cout << "Enter phone:" << endl;
                getline(cin,answer4);
                p.setPhoneNum(answer4);
                cout << "Enter flight number" << endl;
                cin >> flightNumber;
                p.setFlightNumber(flightNumber);

                //check what flight number is here then assign it to the right place.
                for(int i =0; i<NUMBER_OF_FLIGHTS; i++){
                    if(flightNumber == ((i+1)*100)){
                       f[i].setFlightNum(flightNumber);
                        f[i].addPassenger(p);
                    }
                }

            }
                break;
            case 's':
            case 'S': {
                Passenger p;
                string answer1, answer2;
                cin.ignore();
                cout << "Enter first name:" << endl;
                getline(cin, answer1);
                p.setFName(answer1);
                cout << "Enter last name:" << endl;
                getline(cin, answer2);
                p.setLName(answer2);
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
                Passenger p;
                int num;
                string answer1 ,answer2;
                cin.ignore();
                cout << "Enter Flight Number: " << endl;
                cin >> num;
                cin.ignore();
                cout << "Enter first name:" << endl;
                getline(cin,answer1);
                p.setFName(answer1);
                cout << "Enter last name:" << endl;
                getline(cin,answer2);
                p.setLName(answer2);
                f[(num/100)-1].delPassenger(p);
            }
                break;
            case 'l':
            case 'L': {
                int num;
                cout << "Enter Flight Number: " << endl;
                cin >> num;
                f[(num/100)-1].displayPassengers();
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
