#include <stdio.h>

#define MAX_PATIENTS 100
#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20

const char *specialtyNames[NUM_SPECIALTIES] = {
    "General Practice",
    "Paediatrics",
    "Cardiology",
    "Neurology"

};

const float specialtyFees[NUM_SPECIALTIES]={
  1500.00,
  2500.00,
  4500.00,
  5000.00,
};

const int consultationTimes[NUM_SPECIALTIES]={
    15,
    20,
    30,
    30
};

const char *wardNames[NUM_WARDS]={
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};

const int wardCapacities[NUM_WARDS]={
    20,
    10,
    10,
    5
};
const int dailyPatientCaps[NUM_SPECIALTIES]={
    30,
    20,
    12,
    10
};

int bedOccupancy[NUM_WARDS][MAX_BEDS];


char patientNames[MAX_PATIENTS][50];
int patientAges[MAX_PATIENTS];
int patientTriage[MAX_PATIENTS];
int patientSpecialty[MAX_PATIENTS];
int patientAdmitted[MAX_PATIENTS];
int patientWard[MAX_PATIENTS];
int patientDays[MAX_PATIENTS];
int patientIds[MAX_PATIENTS];

int patientCount = 0;

int main(void)
{
    printf("Smart Hospital & Resource Allocation System\n");

    return 0;
}
