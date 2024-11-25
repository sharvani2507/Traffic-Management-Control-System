#include "database.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

vector<Graph::Node*> generateDummyLocations(Graph& locationGraph) {
    vector<Graph::Node*> allLocations;
    vector<string> locationTypes = {"City Center", "Highway", "Park", "Suburb", "Airport", "Shopping Mall", "Industrial Area", "Residential Area", "Hospital", "Train Station", "University", "Bus Depot", "Stadium", "Harbor", "Amusement Park", "Market Square", "Warehouse", "Museum", "Zoo", "Government Office"};

    // Create 40 locations with unique names and cyclic location types
    for (size_t i = 0; i < 40; ++i) {
        string locName = "Location" + to_string(i); // Generate a unique name for each location
        string locType = locationTypes[i % locationTypes.size()]; // Cycle through location types

        // Add location to the graph and retrieve its reference
        locationGraph.addLocation(locName, locType); // Assuming addLocation adds a node to the graph
        allLocations.push_back(locationGraph.getNode(locName)); // Retrieve the node reference by name
    }

    return allLocations; // Return the collection of generated locations
}

vector<GenViolations> generateDummyViolations(vector<GenViolations>& genViolations) {
    // Populate a list of generic traffic violations with associated fines
    genViolations.push_back(GenViolations("Speeding", 150.0));
    genViolations.push_back(GenViolations("Red Light Violation", 200.0));
    genViolations.push_back(GenViolations("Parking in No-Parking Zone", 75.0));
    genViolations.push_back(GenViolations("Driving Without License", 500.0));
    genViolations.push_back(GenViolations("Seatbelt Violation", 100.0));
    genViolations.push_back(GenViolations("Using Mobile While Driving", 250.0));
    genViolations.push_back(GenViolations("Drunk Driving", 1000.0));
    genViolations.push_back(GenViolations("Driving Without Insurance", 400.0));
    genViolations.push_back(GenViolations("Speeding in School Zone", 250.0));
    genViolations.push_back(GenViolations("Running a Stop Sign", 150.0));
    genViolations.push_back(GenViolations("Failure to Signal", 100.0));

    return genViolations; // Return the updated list of violations
}

vector<Vehicle> generateDummyVehicles(vector<Graph::Node*>& allLocations, vector<GenViolations>& genViolations) {
    vector<Vehicle> vehicles; // Collection to store generated vehicles
    vector<string> vehicleTypes = {"Car", "Motorcycle", "Truck", "Bus", "Van", "SUV", "Bicycle", "Taxi", "Emergency Vehicle", "Ambulance"};
    vector<string> violationTypes;

    // Extract violation types from genViolations
    for (const auto& violation : genViolations) {
        violationTypes.push_back(violation.violationType);
    }

    vector<string> ownerNames = {"Sharvani", "Aditya", "Sandhya", "Mrigank", "Rajarshi", "Vaishnavi", "Vibha", "Aryan", "Tejas", "Lakshmi", "Bhavika", "Samvid", "Harshit", "Daivik", "Shourya", "Om", "Pranav", "Varshith", "Sai", "Kalyan", "Cherish", "Yashwanth", "Jaswanth", "Ashmita", "Abhiram"};
    srand(time(0)); // Seed for randomization

    for (int i = 0; i < 25; ++i) { // Generate 25 vehicles
        long int regNo = 100000 + i; // Unique registration number
        string type = vehicleTypes[i % vehicleTypes.size()]; // Cyclic vehicle type
        string ownerName = ownerNames[i % ownerNames.size()]; // Unique owner name

        Graph::Node* location = allLocations[rand() % allLocations.size()]; // Random location assignment

        // Create owner object with dummy data
        Owner owner(ownerName, "01-01-1980", stoll("1234567890" + to_string(i)), "123 Street, City", stoll("9876543210" + to_string(i)));

        Vehicle newVehicle;
        newVehicle.registerNewVehicle(regNo, type, owner, location, vehicles); // Register the vehicle

        // Assign violations to some vehicles randomly
        if (i % 3 == 0) { // Add violations to every 3rd vehicle
            string violationType = violationTypes[rand() % violationTypes.size()]; // Random violation type

            double fineAmount = 0.0;
            for (const auto& violation : genViolations) {
                if (violation.violationType == violationType) {
                    fineAmount = violation.fine; // Get corresponding fine amount
                    break;
                }
            }

            // Add violation to the vehicle
            vehicles[i].addViolation(12345 + rand() % 1000, violationType, "01-01-2024", fineAmount, "Unpaid");
        }
    }

    return vehicles; // Return the list of vehicles
}

vector<TrafficLight> generateDummyTrafficLights(vector<Graph::Node*>& allLocations) {
    vector<TrafficLight> trafficLights; // Collection to store generated traffic lights
    vector<string> statuses = {"Red", "Green", "Yellow"}; // Possible traffic light statuses
    srand(time(0)); // Seed for randomization

    // Create 10 traffic lights at different locations
    for (int i = 0; i < 10; ++i) {
        int locIndex = rand() % allLocations.size(); // Randomly select a location for the traffic light
        string status = statuses[rand() % statuses.size()]; // Randomly select a status from available statuses
        
        // Create a new TrafficLight object and add it to the list
        TrafficLight trafficLight(i + 1, status, allLocations[locIndex]);

        trafficLights.push_back(trafficLight); // Add the new traffic light to the list
    }

    return trafficLights; // Return the list of generated traffic lights
}

vector<HealthcareCentre> generateDummyHealthcareCentres(vector<Graph::Node*>& allLocations, vector<HealthcareCentre>& healthcareCentres) {
    srand(time(0)); // Seed for randomization

    // Create 5 healthcare centers at different locations
    for (int i = 0; i < 10; ++i) {
        int locIndex = rand() % allLocations.size(); // Randomly select a location for the healthcare center
        string helpline = "1-800-" + to_string(rand() % 1000000 + 100000); // Generate a random helpline number

        // Create a new HealthcareCentre object and add it to the list
        HealthcareCentre healthcareCentre("Healthcare Center " + to_string(i + 1), allLocations[locIndex], helpline);
        
        healthcareCentres.push_back(healthcareCentre); // Add the new healthcare center to the list
    }

    return healthcareCentres; // Return the list of healthcare centers
}

void addDummyDataToDatabase(vector<Vehicle>& vehicles, vector<Graph::Node*>& allLocations, Graph& locationGraph, vector<TrafficLight>& trafficLights, vector<GenViolations>& genViolations, vector<HealthcareCentre>& healthcareCentres) {
    // Add dummy data to the system
    allLocations = generateDummyLocations(locationGraph);  // Generate and add locations to the graph
    genViolations = generateDummyViolations(genViolations); // Generate and add violations
    vehicles = generateDummyVehicles(allLocations, genViolations);  // Generate and add vehicles
    trafficLights = generateDummyTrafficLights(allLocations);  // Generate and add traffic lights
    healthcareCentres = generateDummyHealthcareCentres(allLocations, healthcareCentres); // Generate and add healthcare centers
}

