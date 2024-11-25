// The database header file. This will contain all the classes and structures we need for the system to run.

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Owner {
public:
    string name;
    string dob;
    long int phNo;
    string home;
    long int emerPh;
    
    Owner() : name("Default Name"), dob("01-01-1980"), phNo(1234567890), home("Default Home"), emerPh(9876543210) {}

    Owner(string name, string dob, long int phNo, string home, long int emerPh) {
        this->name = name;
        this->dob = dob;
        this->phNo = phNo;
        this->home = home;
        this->emerPh = emerPh;
    }
};

class Graph {
public:
    
    struct Node {
        string name;
        string type;

        Node(string name, string type) : name(name), type(type) {}
    };

    vector<Node*> locations;

    void addLocation(const string& name, const string& type);
    void deleteLocation(const string& name);
    void displayLocations();
    Node* getNode(const string& nodeName);
};

class Vehicle {
public:
    long int regNo;
    string type;
    Owner owner;
    Graph::Node* location;

    class Violations {
    public:
        long int uniqNo;
        string vioType;
        string date;
        double fine;
        string status;

        Violations(long int no, string type, string date, double fineAmount, string stat) 
            : uniqNo(no), vioType(type), date(date), fine(fineAmount), status(stat) {}
    };
    
    vector<Violations> violations; 
    
    Vehicle() : regNo(0), type(""), owner(Owner()), location(nullptr) {}

    Vehicle(long int regNo, string type, Owner own, Graph::Node* loc) 
        : regNo(regNo), type(type), owner(own), location(loc) {}

    void addViolation(long int uniqNo, string vioType, string date, double fine, string status);
    void updateViolationStatus(long int uniqNo, string newStatus);
    void registerNewVehicle(long int regNo, string type, Owner own, Graph::Node* loc, vector<Vehicle>& vehicles);
    static void displayAllVehicles(const vector<Vehicle>& vehicles);
    void listViolations() const;
    static int countTotalViolations(const vector<Vehicle>& vehicles);
    static double calculateTotalFines(long int regNo, const vector<Vehicle>& vehicles);
};

class GenViolations {
public:
    string violationType;
    double fine;

    GenViolations(string type, double fineAmount) {
        this->violationType = type;
        this->fine = fineAmount;
    }
};

class HealthcareCentre {
public:
    string name;
    Graph::Node* location;
    string helpline;

    HealthcareCentre(string name, Graph::Node* loc, string helpline) 
        : name(name), location(loc), helpline(helpline) {}

    void addNewHealthcareCentre(string name, Graph::Node* loc, string helpline, vector<HealthcareCentre>& healthcareCentres);
    void updateHealthcareCentreLocation(Graph::Node* newLocation);
};

class TrafficLight {
public:
    int num;
    string status;
    Graph::Node* location;

    TrafficLight(int num, string status, Graph::Node* loc)
        : num(num), status(status), location(loc) {}

    void updateTrafficLightStatus(const string& newStatus);
    string getTrafficLightStatus() const;
};

class GeneralFunctions {
public:

    static void addNewViolationToGenViolations(const string& violationType, double fineAmount, vector<GenViolations>& genViolations);
    static void updateViolationDetailsInGenViolations(const string& violationType, double fineAmount, vector<GenViolations>& genViolations);
    static void displayAllViolations(const vector<GenViolations>& genViolations);
    static void displayViolationsByType(const string& violationType, const vector<GenViolations>& genViolations);
    void displayRegisteredOwners(const vector<Vehicle>& vehicles);
};

#endif
