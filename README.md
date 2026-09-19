# Smart Hospital & Resource Allocation System

## Project Description

The Smart Hospital & Resource Allocation System is a C programming project developed to manage patient registration, hospital wards, bed allocation, patient priority, billing, and hospital reports.

## Features

- Patient registration
- Patient age validation
- Triage level validation
- Specialty validation
- Daily patient limit validation
- Waiting time calculation
- Ward admission
- Ward ID validation
- Admission days validation
- Automatic bed allocation
- Bed occupancy tracking
- Patient record viewing
- Patient priority sorting
- Hospital reports
- Revenue calculation
- Discount calculation
- Patient data file handling
- Loading patient records from a file

## Technologies Used

- C Programming Language
- Code::Blocks
- Git
- GitHub

## How to Run

1. Open the project in Code::Blocks.
2. Open the `main.c` file.
3. Make sure the patient data file is in the project folder.
4. Build and run the program.
5. Select an option from the main menu.
6. Register and manage patient records.

## Main Menu

The system provides the following options:

1. Register Patient
2. View Patient Records
3. View Bed Status
4. Display Patient Priority
5. Generate Reports
6. Exit

## Main Functions

### registerPatient()

Registers a new patient and calculates the consultation fee, emergency surcharge, ward cost, discount, and final payable amount.

### calculateWaitingTime()

Calculates the estimated waiting time based on the number of patients waiting for the selected specialty.

### allocateBed()

Finds an available bed in the selected ward and allocates it to the patient.

### viewPatientRecords()

Displays the stored patient information.

### viewBedStatus()

Displays the availability of beds in each hospital ward.

### displayPatientPriority()

Sorts patients according to their triage level and displays the patient priority order.

### generateReports()

Generates hospital reports including total revenue, total discounts, bed occupancy, highest-paying patient, and patient counts by triage level.

### loadPatientsFromFile()

Loads previously saved patient records from the patient data file when the program starts.

## File Handling

Patient records are stored in a text file.

The `loadPatientsFromFile()` function reads previously saved patient records when the program starts.

This allows patient records to remain available even after the program is closed and restarted.

## Validation

The system validates:

- Patient age
- Triage level
- Specialty
- Daily specialty patient limit
- Admission selection
- Ward ID
- Number of admission days
- Bed availability

## Billing

The system calculates:

- Base consultation fee
- Emergency surcharge
- Ward stay cost
- Gross total
- Age-based discount
- Final payable amount

## Future Improvements

- Add a graphical user interface
- Add patient search functionality
- Add user login and authentication
- Improve file management
- Add more detailed hospital reports
- Add appointment management