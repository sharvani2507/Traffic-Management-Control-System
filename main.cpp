#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "data.h"
#include "database.h"

using namespace std;

void showAuthorityMenu() {
    cout << "\n===== Authority (Traffic Police) Menu =====\n";

    // Vehicle Management
    cout << "\n--- Vehicle Management ---\n";
    cout << "1. Register New Vehicle\n";
    cout << "2. Display All Vehicles\n";
    cout << "3. Display Vehicle Violations\n";
    cout << "4. Display Total Fines for a Vehicle\n";
    
    // Violation Management
    cout << "\n--- Violation Management ---\n";
    cout << "5. Add Violation to Vehicle\n";
    cout << "6. Check fine for violation\n";
    cout << "7. Display General Violations in System\n";
    cout << "8. Display Total Vehicle Violations in System\n";
    cout << "9. Add New General Violation\n";
    cout << "10. Update General Violation\n";
    
    // Location Management
    cout << "\n--- Location Management ---\n";
    cout << "11. Add Location\n";
    cout << "12. Delete Location\n";
    cout << "13. Display All Locations\n";

    // Traffic Light Management
    cout << "\n--- Traffic Light Management ---\n";
    cout << "14. View All Traffic Lights\n";
    cout << "15. Update Traffic Light Status\n";
    
    // Healthcare Management
    cout << "\n--- Healthcare Management ---\n";
    cout << "16. Display All Healthcare Centres\n";
    cout << "17. Add a New Healthcare Centre\n";

    // Registered Owners 
    cout << "\n--- Registered Owners ---\n";
    cout << "18. Display Registered Owners\n";
    
    // Search vehicle
    cout << "\n--- Search for Vehicle ---\n";
    cout << "19. Get vehicle details\n";
    
    // Exit Option
    cout << "\n--- Exit ---\n";
    cout << "20. Exit\n";

    cout << "Enter your choice: ";
}

void showUserMenu() {
    cout << "\n===== Driver Menu =====\n";
    
    // User Details
    cout << "\n--- Driver Details ---\n";
    cout << "1. View My Details\n";
    cout << "2. Update My Details\n";
    
    // Violations
    cout << "\n--- Violations ---\n";
    cout << "3. View My Violations\n";
    cout << "4. Display General Violations\n";
    
    // Healthcare Centres
    cout << "\n--- Healthcare Centres ---\n";
    cout << "5. Display All Healthcare Centres\n";
    
    // Exit Option
    cout << "\n--- Exit ---\n";
    cout << "6. Exit\n";

    cout << "Enter your choice: ";
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Welcome message
    cout << "==============================================\n";
    cout << "       Welcome to the Traffic Management       \n";
    cout << "            Control System!                   \n";
    cout << "==============================================\n";
    cout << "Please select your user type to proceed.\n";
    cout << "----------------------------------------------\n";
    
    // Initialize vectors
    vector<Vehicle> vehicles;
    vector<Graph::Node*> allLocations;
    vector<GenViolations> genViolations;
    vector<HealthcareCentre> healthcareCentres;
    vector<TrafficLight> trafficLights;
    Graph locationGraph;

    // User input for user type
    string userType;
    cout << "\nEnter user type (Authority/Driver): ";
    cin >> userType;

    cout << "\n----------------------------------------------\n";

    if (userType != "Authority" && userType != "Driver") {
        cout << "Invalid user type. Exiting.\n";
    	cout << "==============================================\n";
        return 1;
    }

    addDummyDataToDatabase(vehicles, allLocations, locationGraph, trafficLights, genViolations, healthcareCentres);

    bool running = true;
    while (running) {
        if (userType == "Authority") {
		    showAuthorityMenu();
		    int choice;
		    cin >> choice;
		    
		    switch (choice) {
				case 1: {
				    long int regNo;
				    string type, ownerName, dob, phn, ephn;

				    // Display available vehicle types for the user to choose from
				    cout << "Choose vehicle type:\n";
				    cout << "1. Car\n";
				    cout << "2. Motorcycle\n";
				    cout << "3. Truck\n";
				    cout << "4. Bus\n";
				    cout << "5. Van\n";
				    cout << "6. SUV\n";
				    cout << "7. Bicycle\n";
				    cout << "8. Taxi\n";
				    cout << "9. Emergency Vehicle\n";
				    cout << "10. Ambulance\n";
				    cout << "Enter the number corresponding to the vehicle type: ";

				    int choice;
				    cin >> choice;

				    // Assign the type based on the user's choice
				    switch (choice) {
					case 1: type = "Car"; break;
					case 2: type = "Motorcycle"; break;
					case 3: type = "Truck"; break;
					case 4: type = "Bus"; break;
					case 5: type = "Van"; break;
					case 6: type = "SUV"; break;
					case 7: type = "Bicycle"; break;
					case 8: type = "Taxi"; break;
					case 9: type = "Emergency Vehicle"; break;
					case 10: type = "Ambulance"; break;
					default: 
					    cout << "Invalid choice! Defaulting to 'Car'.\n";
					    type = "Car"; // Default type if an invalid option is chosen
					    break;
				    }

				    // Prompt user to enter vehicle registration number
				    cout << "Enter vehicle registration number: ";
				    cin >> regNo;
				    
				    bool found = false;
				    // Check if a vehicle with the same registration number already exists.
				    for (const auto& vehicle : vehicles) {
					if (vehicle.regNo == regNo) {
					    cout << "Vehicle with this registration number already exists." << endl; // Display error message.
					    found = true;
					}
				    }

				if(!found){
				    // Prompt user to enter owner's name
				    cout << "Enter owner's name: ";
				    cin >> ownerName;

				    // Validate phone number to be exactly 10 digits
				    bool validPhn = false, validEphn = false;
				    while (!validPhn) {
					cout << "Enter Phone Number (10 digits): ";
					cin >> phn;

					// Check if phone number is 10 digits and contains only numbers
					if (phn.length() == 10 && all_of(phn.begin(), phn.end(), ::isdigit)) {
					    validPhn = true;
					} else {
					    cout << "Invalid phone number. Please enter a 10-digit phone number.\n";
					}
				    }

				    // Validate emergency phone number to be exactly 10 digits
				    while (!validEphn) {
					cout << "Enter Emergency phone number (10 digits): ";
					cin >> ephn;

					// Check if emergency phone number is 10 digits and contains only numbers
					if (ephn.length() == 10 && all_of(ephn.begin(), ephn.end(), ::isdigit)) {
					    validEphn = true;
					} else {
					    cout << "Invalid emergency phone number. Please enter a 10-digit number.\n";
					}
				    }

				    // Validate Date of Birth format (DD-MM-YYYY)
				    bool validDob = false;
				    while (!validDob) {
					cout << "Enter Date of Birth (DD-MM-YYYY): ";
					cin >> dob;

					// Check if the date follows the correct format and contains only digits
					if (dob.length() == 10 && dob[2] == '-' && dob[5] == '-' && 
					    all_of(dob.begin(), dob.begin() + 2, ::isdigit) && 
					    all_of(dob.begin() + 3, dob.begin() + 5, ::isdigit) && 
					    all_of(dob.begin() + 6, dob.end(), ::isdigit)) {
					    validDob = true;
					} else {
					    cout << "Invalid date of birth format. Please use DD-MM-YYYY format.\n";
					}
				    }

				    // Create an Owner object with the entered details
				    Owner owner(ownerName, dob, stoll(phn), "123 Street, City", stoll(ephn));

				    // Create a new Vehicle object and register it
				    Vehicle newVehicle;
				    newVehicle.registerNewVehicle(regNo, type, owner, *allLocations.begin(), vehicles);

				    cout << "Vehicle registered successfully!" << endl;
				}
				    break;
				}

				case 2: {
				    Vehicle::displayAllVehicles(vehicles);
				    break;
				}
				
				case 3: {
				    string regNo;  // Variable to store the input registration number as a string
				    cout << "Enter vehicle registration number: ";
				    cin >> regNo;  // Input as string

				    // Convert the string to a long integer
				    long int regNoInt = stoll(regNo);

				    bool found = false;  // Flag to check if the vehicle is found

				    // Loop through the list of vehicles to find the matching registration number
				    for (auto& vehicle : vehicles) {
					// If the vehicle's registration number matches the input
					if (vehicle.regNo == regNoInt) {
					    vehicle.listViolations();  // Call listViolations to display the violations for the found vehicle
					    found = true;  // Set the flag to true since the vehicle is found
					    break;  // Exit the loop once the vehicle is found
					}
				    }

				    // If the vehicle was not found in the list
				    if (!found) {
					cout << "Vehicle with registration number " << regNoInt << " not found." << endl;
				    }

				    break;
				}
				  
				case 4: {
				    string regNo;  // Variable to store the input registration number as a string
				    cout << "Enter vehicle registration number: ";
				    cin >> regNo;
				    bool found = false;
				    // Loop through the list of vehicles to find the matching registration number
				    for (auto& vehicle : vehicles) {
					// If the vehicle's registration number matches the input
					if (vehicle.regNo == stoi(regNo)) {
					    // Calculate the total fines for the vehicle and display it
					    found = true;
					    double totalFines = vehicle.calculateTotalFines(stoi(regNo), vehicles);  // Pass regNo and vehicles to the function
					    cout << "Total fine amount: " << totalFines << endl;
					    break;  // Exit the loop once the vehicle is found and fine is calculated
					}
				    }

				    // If the vehicle with the given registration number was not found
				    if(!found) cout << "Vehicle with registration number " << regNo << " not found." << endl;

				    break;
				}
				case 5: {
				    long int regNo;  // Variable to store the vehicle's registration number
				    cout << "Enter vehicle registration number: ";
				    cin >> regNo;  // Input registration number

				    string vioType, date, status;  // Variables to store violation type, date, and status
				    double fine;  // Variable to store fine amount

				    // Check if the vehicle exists in the system
				    bool vehicleExists = false;
				    for (auto& vehicle : vehicles) {
					if (vehicle.regNo == regNo) {
					    vehicleExists = true;  // Vehicle found
					    break;  // Exit the loop if vehicle is found
					}
				    }

				    // If the vehicle doesn't exist, show an error message and break out of the case
				    if (!vehicleExists) {
					cout << "Vehicle registration number does not exist." << endl;
					break;  // Exit the case if the vehicle is not found
				    }

				    // Display available violation types to the user
				    cout << "Choose a violation type:\n";
				    for (size_t i = 0; i < genViolations.size(); ++i) {
					cout << i + 1 << ". " << genViolations[i].violationType << "\n";
				    }

				    int choice;  // Variable to store user's choice for violation type
				    bool validChoice = false;  // Flag to check if the user's choice is valid
				    while (!validChoice) {
					cout << "Enter the number corresponding to the violation: ";
					cin >> choice;  // User input for violation choice

					// Validate the choice and set violation type and fine
					if (choice >= 1 && choice <= static_cast<int>(genViolations.size())) {
					    vioType = genViolations[choice - 1].violationType;  // Set violation type
					    fine = genViolations[choice - 1].fine;  // Set fine amount
					    validChoice = true;  // Mark choice as valid
					} else {
					    cout << "Invalid choice! Please enter a valid number between 1 and " << genViolations.size() << "." << endl;
					}
				    }

				    // Ask user for violation date in dd-mm-yy format
				    bool validDate = false;
				    while (!validDate) {
					cout << "Enter violation date (dd-mm-yy): ";
					cin >> date;  // Input date

					// Validate date format
					if (date.length() != 8 || date[2] != '-' || date[5] != '-') {
					    cout << "Invalid date format! Please enter in dd-mm-yy format." << endl;
					} else {
					    validDate = true;  // Mark date as valid
					}
				    }

				    // Ask user for violation status (paid or unpaid)
				    bool validStatus = false;
				    while (!validStatus) {
					cout << "Enter violation status (Paid/Unpaid): ";
					cin >> status;  // Input status

					// Check if the status is either "paid" or "unpaid"
					if (status != "Paid" && status != "Unpaid") {
					    cout << "Invalid status! Please enter either 'paid' or 'unpaid'." << endl;
					} else {
					    validStatus = true;  // Mark status as valid
					}
				    }

				    // Add the violation to the vehicle
				    for (auto& vehicle : vehicles) {
					if (vehicle.regNo == regNo) {
					    // Add the violation using a unique violation ID (e.g., 12345) and other details
					    vehicle.addViolation(12345, vioType, date, fine, status);
					    cout << "Violation added successfully!" << endl;
					    break;  // Exit the loop once violation is added
					}
				    }

				    break;
				}
				case 6: {
				    string vioType;  // Variable to store the selected violation type
				    cout << "Available violation types:" << endl;

				    // Display all available violation types from the genViolations list
				    for (size_t i = 0; i < genViolations.size(); ++i) {
					cout << i + 1 << ". " << genViolations[i].violationType << endl;  // Display each violation type
				    }

				    int choice;  // Variable to store the user's choice
				    cout << "Enter the number corresponding to the violation type: ";
				    cin >> choice;  // User input for the violation type choice

				    // Validate the user's choice
				    if (choice < 1 || choice > static_cast<int>(genViolations.size())) {
					cout << "Invalid choice. Please try again." << endl;  // Error message for invalid choice
				    } else {
					vioType = genViolations[choice - 1].violationType;  // Get the violation type based on user's choice
					GeneralFunctions::displayViolationsByType(vioType, genViolations);  // Call the function to display violations of the selected type
				    }

				    break;  // End of case
				}
				case 7: {
				    GeneralFunctions::displayAllViolations(genViolations);
				    break;
				}
				case 8: {
				    cout << "Total Vehicle Violations in System: " << Vehicle::countTotalViolations(vehicles) << endl;
				    break;
				}
				case 9: {
				    // Add a new violation type
				    string violationType;  // Variable to store the violation type input by the user
				    double fineAmount;     // Variable to store the fine amount for the violation

				    cout << "Enter the violation type: ";
				    cin.ignore();  // To clear the input buffer before reading a line of text
				    getline(cin, violationType);  // Read the entire violation type

				    cout << "Enter the fine amount: ";
				    cin >> fineAmount;  // Read the fine amount for the violation

				    // Call the function to add the new violation to the genViolations list
				    GeneralFunctions::addNewViolationToGenViolations(violationType, fineAmount, genViolations);

				    break;  // End of case
				}

				case 10: {
				    // Display all existing violation types
				    cout << "Existing violation types:\n";
				    for (size_t i = 0; i < genViolations.size(); ++i) {
					cout << i + 1 << ". " << genViolations[i].violationType << " (Current Fine: " << genViolations[i].fine << ")" << endl;
				    }

				    // Let the user choose the violation type to update
				    int choice;
				    cout << "Enter the number corresponding to the violation type you want to update: ";
				    cin >> choice;  // Read the choice of the violation type to update

				    // Validate the choice
				    if (choice < 1 || choice > static_cast<int>(genViolations.size())) {
					cout << "Invalid choice. Returning to the main menu." << endl;  // Error message for invalid choice
					break;  // Exit this case and return to the main menu
				    }

				    // Get the selected violation type
				    string violationType = genViolations[choice - 1].violationType;

				    // Ask for the new fine amount
				    double fineAmount;
				    cout << "Enter the new fine amount for '" << violationType << "': ";
				    cin >> fineAmount;  // Read the new fine amount for the selected violation type

				    // Call the function to update the violation's fine amount
				    GeneralFunctions::updateViolationDetailsInGenViolations(violationType, fineAmount, genViolations);

				    break;  // End of case
				}
				case 11: {
				    // Add a new location with a specified type
				    string name;  // Variable to store the location name
				    int typeChoice;  // Variable to store the type choice input by the user
				    cout << "Enter location name: ";
				    cin >> name;  // Read the location name

				    // List of available location types
				    vector<string> locationTypes = {"City", "Highway", "Park", "Suburb", "Airport", "Mall", "Industrial Area", "Residential Area", "Hospital", "Train Station"};
				    
				    bool validChoice = false;  // Flag to ensure a valid location type is chosen
				    string type;  // Variable to store the selected location type

				    // Loop to ensure a valid location type is selected
				    while (!validChoice) {
					// Display available location types
					cout << "Available location types:\n";
					for (size_t i = 0; i < locationTypes.size(); ++i) {
					    cout << i + 1 << ". " << locationTypes[i] << endl;
					}

					cout << "Enter location type number (1-" << locationTypes.size() << "): ";
					cin >> typeChoice;  // Read the user’s choice for the location type

					// Validate the choice and assign the type if valid
					if (typeChoice >= 1 && typeChoice <= static_cast<int>(locationTypes.size())) {
					    type = locationTypes[typeChoice - 1];  // Get the selected type from the list
					    validChoice = true;  // Mark the choice as valid
					} else {
					    cout << "Invalid choice. Please choose a number between 1 and " << locationTypes.size() << ".\n";  // Error message for invalid choice
					}
				    }

				    // Add the location with the selected type
				    locationGraph.addLocation(name, type);  // Call the addLocation method from locationGraph object
				    cout << "Location added successfully!" << endl;  // Confirmation message

				    break;  // End of case
				}

				case 12: {
				    // Delete an existing location
				    string name;  // Variable to store the location name to delete
				    cout << "Enter location name to delete: ";
				    cin >> name;  // Read the location name to be deleted

				    // Call the deleteLocation method from locationGraph to handle the deletion process
				    locationGraph.deleteLocation(name);  // This will handle invalid names with a message

				    break;  // End of case
				}
				case 13: {
				    locationGraph.displayLocations();
				    break;
				}
				case 14: {
				    // View all traffic lights and their statuses
				    if (trafficLights.empty()) {
					cout << "No traffic lights available." << endl;  // Handle case where there are no traffic lights
				    } else {
					for (const auto& light : trafficLights) {
					    cout << "Traffic Light at " << light.location->name 
						 << " Status: " << light.status << endl;
					}
				    }
				    break;
				}

				case 15: {
				    // Display available traffic light locations along with their current statuses
				    cout << "Available traffic light locations: " << endl;

				    if (trafficLights.empty()) {
					cout << "No traffic lights available to update." << endl;  // Handle case where there are no traffic lights
					break;
				    }

				    for (size_t i = 0; i < trafficLights.size(); ++i) {
					cout << i + 1 << ". " << trafficLights[i].location->name 
					     << " (Current Status: " << trafficLights[i].status << ")" << endl;
				    }

				    // Ask the user to choose a traffic light to update
				    int choice;
				    cout << "Enter the number of the traffic light location you want to update: ";
				    cin >> choice;

				    // Validate the input to ensure the choice is within a valid range
				    if (choice < 1 || choice > static_cast<int>(trafficLights.size())) {
					cout << "Invalid choice! Please choose a valid location number." << endl;
					break;
				    }

				    // Ask for the new status
				    string newStatus;
				    cout << "Enter new status (Red/Green/Yellow): ";
				    cin >> newStatus;

				    // Validate the status input
				    if (newStatus != "Red" && newStatus != "Green" && newStatus != "Yellow") {
					cout << "Invalid status! Please enter 'Red', 'Green', or 'Yellow'." << endl;
					break;
				    }

				    // Update the status of the selected traffic light
				    trafficLights[choice - 1].status = newStatus;
				    cout << "Traffic light status updated successfully!" << endl;

				    break;
				}
				case 16: {
				    // Display all healthcare centres
				    if (healthcareCentres.empty()) {
					cout << "No healthcare centres available." << endl;
				    } else {
					cout << "List of Healthcare Centres:" << endl;
					for (size_t i = 0; i < healthcareCentres.size(); ++i) {
					    cout << i + 1 << ". Name: " << healthcareCentres[i].name
						 << ", Location: " << healthcareCentres[i].location->name
						 << ", Helpline: " << healthcareCentres[i].helpline << endl;
					}
				    }
				    break;
				}

				case 17: {
				    // Add a new healthcare centre
				    string name, helpline;
				    
				    // Ask for the name of the healthcare centre
				    cout << "Enter name of the healthcare centre: ";
				    cin.ignore();  // Clear the input buffer to handle any leftover newline characters
				    getline(cin, name);  // Read the full name

				    // Ask for the helpline number of the healthcare centre
				    cout << "Enter helpline number of the healthcare centre: ";
				    cin >> helpline;

				    // Check if there are available locations
				    cout << "Available Locations: " << endl;
				    for (size_t i = 0; i < allLocations.size(); ++i) {
					cout << i + 1 << ". " << allLocations[i]->name << endl;
				    }

				    // Prompt the user to choose a location for the healthcare centre
				    cout << "Enter the number corresponding to the location: ";
				    int locChoice;
				    cin >> locChoice;

				    // Validate the choice and ensure it's within range
				    if (locChoice < 1 || locChoice > static_cast<int>(allLocations.size())) {
					cout << "Invalid choice. Unable to add healthcare centre." << endl;
					break;
				    }

				    // Add the new healthcare centre to the list
				    Graph::Node* chosenLocation = allLocations[locChoice - 1];  // Get the chosen location
				    HealthcareCentre newCentre(name, chosenLocation, helpline);  // Create a new healthcare centre object
				    healthcareCentres.push_back(newCentre);  // Add to the list

				    cout << "Healthcare centre added successfully!" << endl;
				    break;
				}
				case 18: {
				    for (const auto& vehicle : vehicles) {
       				    cout << "Owner: " << vehicle.owner.name << ", Vehicle: " << vehicle.regNo << endl;
	 		            }
				    break;
				}
				case 19: {
				    string input;
				    cout << "Enter the name or vehicle registration number: ";
				    cin >> input;

				    Vehicle* userVehicle = nullptr;

				    // Check if the input is a name or registration number
				    if (isdigit(input[0])) {  // If the input is a number (registration number)
					long int regNo = stoll(input);  // Convert input to long int for regNo
					for (auto& vehicle : vehicles) {
					    if (vehicle.regNo == regNo) {
						userVehicle = &vehicle;				
						break;
					    }
					}
				    } else {  // If the input is a name
					for (auto& vehicle : vehicles) {
					    if (vehicle.owner.name == input) {
						userVehicle = &vehicle;
						break;
					    }
					}
				    }

				    if (!userVehicle) {
					cout << "Vehicle not found for this information.\n";
				    }else{
				        // Display user details
					cout << "\n--- User Details ---\n";
					cout << "Owner Name: " << userVehicle->owner.name << endl;
					cout << "Date of Birth: " << userVehicle->owner.dob << endl;
					cout << "Phone Number: " << userVehicle->owner.phNo << endl;
					cout << "Home Address: " << userVehicle->owner.home << endl;
					cout << "Emergency Phone: " << userVehicle->owner.emerPh << endl;

					// Display vehicle details
					cout << "\n--- Vehicle Details ---\n";
					cout << "Registration Number: " << userVehicle->regNo << endl;
					cout << "Vehicle Type: " << userVehicle->type << endl;
					cout << "Vehicle Location: " << userVehicle->location->name << endl;
					
				    }
				    break;
				}
				case 20: {
				    cout << "Exiting the system.\n";
				    running = false;
				    break;
				}
				default:{
				    cout << "Invalid choice. Please try again.\n";
			        }
		    }
	     }else if (userType == "Driver") {
		    string input;
		    cout << "Enter your name or vehicle registration number: ";
		    cin >> input;

		    Vehicle* userVehicle = nullptr;

		    // Check if the input is a name or registration number
		    if (isdigit(input[0])) {  // If the input is a number (registration number)
			long int regNo = stoll(input);  // Convert input to long int for regNo
			for (auto& vehicle : vehicles) {
			    if (vehicle.regNo == regNo) {
				userVehicle = &vehicle;				
				break;
			    }
			}
		    } else {  // If the input is a name
			for (auto& vehicle : vehicles) {
			    if (vehicle.owner.name == input) {
				userVehicle = &vehicle;
				break;
			    }
			}
		    }

		    if (!userVehicle) {
			cout << "Vehicle not found for this user.\n";
			continue;
		    }

		    bool continueUserMenu = true; // Flag to control menu loop
		    while (continueUserMenu) {
			showUserMenu();
			int choice;
			cin >> choice;

			switch (choice) {
				case 1: {
					// Display user details
					cout << "\n--- User Details ---\n";
					cout << "Owner Name: " << userVehicle->owner.name << endl;
					cout << "Date of Birth: " << userVehicle->owner.dob << endl;
					cout << "Phone Number: " << userVehicle->owner.phNo << endl;
					cout << "Home Address: " << userVehicle->owner.home << endl;
					cout << "Emergency Phone: " << userVehicle->owner.emerPh << endl;

					// Display vehicle details
					cout << "\n--- Vehicle Details ---\n";
					cout << "Registration Number: " << userVehicle->regNo << endl;
					cout << "Vehicle Type: " << userVehicle->type << endl;
					break;
				}
				case 2: {
				bool continueUpdating = true; // Flag to control the update menu
				while (continueUpdating) {
				    // Ask the user what they want to update
				    cout << "What would you like to update?\n";
				    cout << "1. Name\n";
				    cout << "2. Phone Number\n";
				    cout << "3. Date of Birth\n";
				    cout << "4. Emergency Phone Number\n";
				    cout << "5. Exit Update\n";
				    cout << "Enter your choice: ";
				    int updateChoice;
				    cin >> updateChoice;

				    switch (updateChoice) {
				        case 1: {
				            string newName;
				            cout << "Enter your new name: ";
				            cin >> newName;
				            userVehicle->owner.name = newName;
				            cout << "Name updated successfully!\n";
				            break;
				        }
				        case 2: {
				            string newPhone;
				            bool validPhone = false;
				            while (!validPhone) {
				                cout << "Enter your new 10-digit phone number: ";
				                cin >> newPhone;

				                // Check if the phone number is 10 digits long
				                if (newPhone.length() == 10 && all_of(newPhone.begin(), newPhone.end(), ::isdigit)) {
				                    userVehicle->owner.phNo = stoll(newPhone);
				                    cout << "Phone number updated successfully!\n";
				                    validPhone = true;
				                } else {
				                    cout << "Invalid phone number. Please enter exactly 10 digits.\n";
				                }
				            }
				            break;
				        }
				        case 3: {
				            string newDOB;
				            cout << "Enter your new Date of Birth (dd-mm-yyyy): ";
				            cin >> newDOB;

				            // Simple validation for the format (dd-mm-yyyy)
				            if (newDOB.length() == 10 && newDOB[2] == '-' && newDOB[5] == '-' &&
				                all_of(newDOB.begin(), newDOB.begin() + 2, ::isdigit) &&  // dd
				                all_of(newDOB.begin() + 3, newDOB.begin() + 5, ::isdigit) &&  // mm
				                all_of(newDOB.begin() + 6, newDOB.end(), ::isdigit)) {  // yyyy
				                userVehicle->owner.dob = newDOB;
				                cout << "Date of Birth updated successfully!\n";
				            } else {
				                cout << "Invalid format. Please enter in dd-mm-yyyy format.\n";
				            }
				            break;
				        }
				        case 4: {
				            string newEmergPhone;
				            bool validEmergPhone = false;
				            while (!validEmergPhone) {
				                cout << "Enter your new 10-digit emergency phone number: ";
				                cin >> newEmergPhone;

				                // Check if the emergency phone number is 10 digits long
				                if (newEmergPhone.length() == 10 && all_of(newEmergPhone.begin(), newEmergPhone.end(), ::isdigit)) {
				                    userVehicle->owner.emerPh = stoll(newEmergPhone);
				                    cout << "Emergency phone number updated successfully!\n";
				                    validEmergPhone = true;
				                } else {
				                    cout << "Invalid emergency phone number. Please enter exactly 10 digits.\n";
				                }
				            }
				            break;
				        }
				        case 5: {
				            cout << "Exiting update menu.\n";
				            continueUpdating = false;  // Exit the update menu
				            break;
				        }
				        default: {
				            cout << "Invalid choice. Please select a valid option.\n";
				            break;
				        }
				    }
				}
				break;
			    }
			    case 3: {
				if(userVehicle->violations.empty()) cout << "No violations" << endl;
				for (const auto& violation : userVehicle->violations) {
				    cout << "Your Violations:\n";
				    cout << "Violation No: " << violation.uniqNo
				         << ", Violation Type: " << violation.vioType
				         << ", Date: " << violation.date
				         << ", Fine: " << violation.fine
				         << ", Status: " << violation.status << endl;
				}
				break;
			    }
			   case 4: {
		            GeneralFunctions::displayAllViolations(genViolations);
		            break;
		           }
		           case 5: {
			    // Display all healthcare centres
			    if (healthcareCentres.empty()) {
				cout << "No healthcare centres available." << endl;
			    } else {
				cout << "List of Healthcare Centres:" << endl;
				for (size_t i = 0; i < healthcareCentres.size(); ++i) {
				    cout << i + 1 << ". Name: " << healthcareCentres[i].name
					 << ", Location: " << healthcareCentres[i].location->name
					 << ", Helpline: " << healthcareCentres[i].helpline << endl;
				}
			    }
			    break;
			 }
			 case 6: {
				cout << "Exiting.\n";
				continueUserMenu = false;  // Stop the loop, exit the menu
				running = false;
				break;
			 }
			 default: {
				cout << "Invalid choice.\n";
				break;
			 }	
		      }
		 }
	   }	    
     }		    

    // Closing statement
    cout << "==============================================\n";
    return 0;
}


