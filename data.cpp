#include "data.h"
#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

Graph::Node* location; // Pointer to represent a single location in the graph (not used in the provided code).

// Function to add a new location (node) to the graph.
void Graph::addLocation(const string& name, const string& type) {
    // Create a new Node object with the given name and type and add it to the locations vector.
    locations.push_back(new Node(name, type));
}

// Function to delete a location (node) from the graph by its name.
void Graph::deleteLocation(const string& name) {
    // Iterate through the locations vector to find the node with the matching name.
    for (auto it = locations.begin(); it != locations.end(); ++it) {
        if ((*it)->name == name) { // Check if the name matches.
            delete *it; // Free the memory allocated for the Node.
            locations.erase(it); // Remove the node from the vector.
            cout << "Location deleted successfully!" << endl; // Success message.
            return; // Exit the function after deleting the location.
        }
    }
    cout << "Location not found!" << endl; // If no matching node is found, display an error message.
}

// Function to display all the locations in the graph.
void Graph::displayLocations() {
    // Loop through each Node pointer in the locations vector.
    for (Node* location : locations) {
        // Print the name and type of the location.
        cout << "Location: " << location->name << ", Type: " << location->type << endl;
    }
}

// Function to find and return a pointer to a Node in the graph by its name.
Graph::Node* Graph::getNode(const string& nodeName) {
    // Iterate through the locations vector to search for a matching node.
    for (auto& node : locations) {
        if (node->name == nodeName) { // Check if the node's name matches the input name.
            return node; // Return the pointer to the matching Node.
        }
    }
    return nullptr; // Return nullptr if no matching node is found.
}

// Function to add a violation to the vehicle.
void Vehicle::addViolation(long int uniqNo, string vioType, string date, double fine, string status) {
    // Add a new Violation object to the violations vector.
    violations.push_back(Violations{uniqNo, vioType, date, fine, status});
}

// Function to update the status of a specific violation for the vehicle.
void Vehicle::updateViolationStatus(long int uniqNo, string newStatus) {
    // Iterate through the violations vector to find the violation with the given unique number.
    for (auto& violation : violations) {
        if (violation.uniqNo == uniqNo) { // Check if unique number matches.
            violation.status = newStatus; // Update the status of the violation.
            break; // Exit the loop once the violation is found and updated.
        }
    }
}

// Function to register a new vehicle.
void Vehicle::registerNewVehicle(long int regNo, string type, Owner own, Graph::Node* loc, vector<Vehicle>& vehicles) {
    // Set the attributes for the new vehicle.
    this->regNo = regNo;
    this->type = type;
    this->owner = own;
    this->location = loc;
    vehicles.push_back(*this); // Add the new vehicle to the vehicles vector.
}

// Function to display all registered vehicles.
void Vehicle::displayAllVehicles(const vector<Vehicle>& vehicles) {
    for (const auto& vehicle : vehicles) { // Loop through each vehicle in the vector.
        cout << "Vehicle Registration Number: " << vehicle.regNo << endl;
        cout << "Owner: " << vehicle.owner.name << endl;
        cout << "Type: " << vehicle.type << endl;
        cout << "Location: " << vehicle.location->name << endl; // Display the name of the location.
        cout << "-----------------------------------------" << endl;
    }
}

// Function to list all violations for the current vehicle.
void Vehicle::listViolations() const {
    if (violations.empty()) { // Check if there are no violations.
        cout << "No violations found for vehicle with registration number: " << regNo << endl;
    } else {
        cout << "Violations for vehicle " << regNo << ":\n"; // Display the header.
        for (const auto& violation : violations) { // Loop through each violation.
            cout << "Violation type: " << violation.vioType 
                 << ", Fine: " << violation.fine 
                 << ", Status: " << violation.status << endl; // Display details of each violation.
        }
    }
}

// Function to count the total number of violations across all vehicles.
int Vehicle::countTotalViolations(const vector<Vehicle>& vehicles) {
    int totalViolations = 0; // Initialize a counter for total violations.

    // Loop through each vehicle to display their violations and count them.
    for (const auto& vehicle : vehicles) {
        if (!vehicle.violations.empty()) { // Check if the vehicle has violations.
            cout << "Vehicle Registration Number: " << vehicle.regNo << endl;
            cout << "Violations for this vehicle:" << endl;
            for (const auto& violation : vehicle.violations) { // Loop through each violation.
                cout << "- Violation Type: " << violation.vioType
                     << ", Fine: " << violation.fine
                     << ", Status: " << violation.status
                     << ", Date: " << violation.date << endl; // Include the date of violation.
            }
            cout << "-------------------------------------" << endl;
        }
        // Add the number of violations for the current vehicle to the total count.
        totalViolations += vehicle.violations.size();
    }

    return totalViolations; // Return the total number of violations.
}

// Function to calculate the total fines for a specific vehicle by its registration number.
double Vehicle::calculateTotalFines(long int regNo, const vector<Vehicle>& vehicles) {
    for (const auto& vehicle : vehicles) { // Search for the vehicle with the given registration number.
        if (vehicle.regNo == regNo) { // If the registration number matches.
            double totalFines = 0; // Initialize total fines.
            double paidFines = 0; // Initialize paid fines.
            double unpaidFines = 0; // Initialize unpaid fines.

            // Loop through the violations for the vehicle.
            for (const auto& violation : vehicle.violations) {
                totalFines += violation.fine; // Add fine to the total fines.

                if (violation.status == "Paid") {
                    paidFines += violation.fine; // Add to paid fines if status is "Paid".
                } else if (violation.status == "Unpaid") {
                    unpaidFines += violation.fine; // Add to unpaid fines if status is "Unpaid".
                }
            }

            // Display the fine details.
            cout << "Total Fines for Vehicle " << vehicle.regNo << ":\n";
            cout << "Paid Fines: " << paidFines << endl;
            cout << "Unpaid Fines: " << unpaidFines << endl;

            return totalFines; // Return the total fines.
        }
    }

    // If the vehicle is not found, display an error and return 0.
    cout << "Vehicle with registration number " << regNo << " not found." << endl;
    return 0.0;
}

// Function to add a new healthcare centre to the system.
void HealthcareCentre::addNewHealthcareCentre(string name, Graph::Node* loc, string helpline, vector<HealthcareCentre>& healthcareCentres) {
    // Check if a healthcare centre already exists at the provided location.
    for (const auto& centre : healthcareCentres) {
        if (centre.location == loc) { // Compare locations to see if one already exists at this spot.
            cout << "A healthcare center already exists at this location." << endl;
            return; // Exit the function if a duplicate is found.
        }
    }

    // Assign the details of the new healthcare centre to the current object.
    this->name = name;
    this->location = loc;
    this->helpline = helpline;

    // Add the newly created healthcare centre to the vector of healthcare centres.
    healthcareCentres.push_back(*this);

    // Confirmation message indicating successful addition.
    cout << "New healthcare center added successfully!" << endl;
}

// Function to update the location of an existing healthcare centre.
void HealthcareCentre::updateHealthcareCentreLocation(Graph::Node* newLocation) {
    location = newLocation; // Update the `location` attribute with the new Graph node.
}

// Function to update the status of the traffic light.
void TrafficLight::updateTrafficLightStatus(const string& newStatus) {
    status = newStatus; // Set the `status` attribute to the new status provided.
}

// Function to retrieve the current status of the traffic light.
string TrafficLight::getTrafficLightStatus() const {
    return status; // Return the value of the `status` attribute.
}

// Function to add a new violation to the list of general violations.
void GeneralFunctions::addNewViolationToGenViolations(
    const string& violationType,       // Type of the violation.
    double fineAmount,                 // Fine amount for the violation.
    vector<GenViolations>& genViolations // Reference to the list of general violations.
) {
    // Check if the violation type already exists in the list.
    for (const auto& violation : genViolations) {
        if (violation.violationType == violationType) {
            cout << "Violation type '" << violationType << "' already exists in the list." << endl;
            return; // Exit the function if a duplicate violation is found.
        }
    }

    // Create a new violation and add it to the list.
    GenViolations newViolation = {violationType, fineAmount};
    genViolations.push_back(newViolation);

    // Confirmation message indicating the violation was added successfully.
    cout << "New violation type '" << violationType << "' added successfully with a fine of " << fineAmount << "." << endl;
}

// Function to update the fine amount for an existing violation type.
void GeneralFunctions::updateViolationDetailsInGenViolations(const string& violationType, double fineAmount, vector<GenViolations>& genViolations) {
    // Search for the violation type in the list.
    for (auto& violation : genViolations) {
        if (violation.violationType == violationType) {
            violation.fine = fineAmount; // Update the fine amount.
            cout << "Violation type '" << violationType << "' updated successfully with a new fine of " << fineAmount << "." << endl;
            return; // Exit after updating the violation.
        }
    }

    // If the violation type is not found in the list.
    cout << "Violation type '" << violationType << "' does not exist in the list." << endl;
}

// Function to display all violations in the general violations list.
void GeneralFunctions::displayAllViolations(const vector<GenViolations>& violations) {
    // Loop through and display each violation in the list.
    for (const auto& violation : violations) {
        cout << "Violation Type: " << violation.violationType 
             << ", Fine: " << violation.fine << endl;
    }
}

// Function to display violations of a specific type.
void GeneralFunctions::displayViolationsByType(
    const string& violationType, const vector<GenViolations>& genViolations) {
    bool found = false; // Flag to track if the violation type is found.

    // Loop through the general violations list to find the specified type.
    for (const auto& genViolation : genViolations) {
        if (genViolation.violationType == violationType) {
            // Display the violation details if found.
            cout << "Violation Type: " << genViolation.violationType 
                 << ", Fine: " << genViolation.fine << endl;
            found = true;
        }
    }

    // If no violation of the specified type is found.
    if (!found) {
        cout << "No violations of type '" << violationType << "' found in the general violations list." << endl;
    }
}

// Function to display registered vehicle owners along with their vehicles.
void GeneralFunctions::displayRegisteredOwners(const vector<Vehicle>& vehicles) {
    // Loop through and display the owner and vehicle registration details.
    for (const auto& vehicle : vehicles) {
        cout << "Owner: " << vehicle.owner.name 
             << ", Vehicle: " << vehicle.regNo << endl;
    }
}

