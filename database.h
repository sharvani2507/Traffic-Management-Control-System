#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "data.h" 

using namespace std;

// Function to generate dummy locations in the graph
vector<Graph::Node*> generateDummyLocations(Graph& locationGraph);

// Function to generate dummy general violations
vector<GenViolations> generateDummyViolations(vector<GenViolations>& genViolations);

// Function to generate dummy vehicles
vector<Vehicle> generateDummyVehicles(vector<Graph::Node*>& allLocations, vector<GenViolations>& genViolations);

// Function to generate dummy traffic lights
vector<TrafficLight> generateDummyTrafficLights(vector<Graph::Node*>& allLocations);

// Function to generate dummy healthcare centres
vector<HealthcareCentre> generateDummyHealthcareCentres(vector<Graph::Node*>& allLocations, vector<HealthcareCentre>& healthcareCentres);

// Function to add dummy data to the database (vehicles, locations, violations, traffic lights and healthcare centres)
void addDummyDataToDatabase(vector<Vehicle>& vehicles, vector<Graph::Node*>& allLocations, Graph& locationGraph, vector<TrafficLight>& trafficLights, vector<GenViolations>& genViolations, vector<HealthcareCentre>& healthcareCentres);

#endif 
