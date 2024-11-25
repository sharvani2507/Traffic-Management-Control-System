# Traffic Control Management System 🚦

## Overview
The **Traffic Control Management System** is a software tool designed to streamline the management of traffic, vehicles, violations, and healthcare resources. It offers comprehensive features for administrators and drivers to ensure efficient traffic operations and safety compliance.

---

## Features

### **Admin Menu**
The admin menu provides tools for managing and overseeing the entire system:

1. **Vehicle Management**:
   - Register new vehicles with owner details.
   - Display all registered vehicles.
   - View violations associated with a specific vehicle.
   - Calculate total fines for a vehicle.

2. **Violation Management**:
   - Add a new violation to a vehicle.
   - Check the fine for a specific violation.
   - Display all general violations in the system.
   - Count and display the total number of vehicle violations.
   - Add a new type of general violation.
   - Update existing general violation details.

3. **Location Management**:
   - Add new locations to the system.
   - Delete existing locations.
   - Display all locations.

4. **Traffic Light Management**:
   - View all traffic lights in the system.
   - Update the status of traffic lights.

5. **Healthcare Management**:
   - Display all healthcare centers in the system.
   - Add a new healthcare center.

6. **Registered Owners**:
   - Display details of all registered vehicle owners.

7. **Search Vehicle**:
   - Get detailed information about a specific vehicle.

8. **Exit**:
   - Exit the admin menu.

---

### **Driver Menu**
The driver menu allows individual drivers to access their details and view important traffic information:

1. **Driver Details**:
   - View personal details.
   - Update personal details.

2. **Violations**:
   - View personal violation records.
   - Display general violation types and fines.

3. **Healthcare Centers**:
   - Display all healthcare centers for emergency assistance.

4. **Exit**:
   - Exit the driver menu.

---

## Project Structure

```plaintext
.
├── data.h                # Definitions for core data models 
├── data.cpp              # Implementations for core data models
├── database.h            # Definitions for system's dummy database
├── database.cpp          # Implementations for system dummy database
├── main.cpp              # Main entry point for the application
├── Makefile              # Build instructions for the project
├── README.md             # Project documentation
