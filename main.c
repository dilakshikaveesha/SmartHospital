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

int specialtyQueueCount[NUM_SPECIALTIES]={0};


char patientNames[MAX_PATIENTS][50];
int patientAges[MAX_PATIENTS];
int patientTriage[MAX_PATIENTS];
int patientSpecialty[MAX_PATIENTS];
int patientAdmitted[MAX_PATIENTS];
int patientWard[MAX_PATIENTS];
int patientDays[MAX_PATIENTS];
int patientIds[MAX_PATIENTS];

int patientCount = 0;

void registerPatient(void);
int calculateWaitingTime(int specialty);
int allocateBed(int ward);

int calculateWaitingTime(int specialty)
{
    int index;

    index= specialty -1;

    return specialtyQueueCount[index]*consultationTimes[index];
}
int allocateBed(int ward)
{
    int wardIndex;
    int bed;

    wardIndex = ward -1;

    for(bed =0;bed< wardCapacities[wardIndex];bed++)
    {
        if(bedOccupancy[wardIndex][bed]==0)
        {
            bedOccupancy[wardIndex][bed]=1;

            return bed+1;
        }
    }
    return 0;
}

int main(void)
{
    int choice;

    do{

    printf("\n=============================================\n");
    printf("Smart Hospital & Resource Allocation System\n");
    printf("===============================================\n");
    printf("1.Register Patient\n");
    printf("2.view Patient Records\n");
    printf("3.View Bed Status\n");
    printf("4.Display Patient Priority\n");
    printf("5.Generate Reports\n");
    printf("6.Exit\n");
    printf("===============================================\n");

    printf("Enter your choice:");
    scanf("%d",&choice);

    if(choice == 1)
    {
        registerPatient();
    }
    }
    while(choice!=6);

    printf("Thank you for using Smart Hospital System.\n");

    return 0;
}


void registerPatient(void)
{
    int waitingTime;
    int bedNumber;
    printf("\n---Register Patient---\n");

    printf("Enter patient name :");
    scanf(" %49[^\n]",patientNames[patientCount]);

    printf("Enter patient age:");
    scanf("%d",&patientAges[patientCount]);

    printf("Enter triage level(1-Normal,2-Urgent,3-Critical):");
    scanf("%d",&patientTriage[patientCount]);

    printf("Enter specialty (1-4):");
    scanf("%d",&patientSpecialty[patientCount]);

    waitingTime = calculateWaitingTime(patientSpecialty[patientCount]);

    printf("Estimated Waiting Time :%d minutes\n",waitingTime);

    specialtyQueueCount[patientSpecialty[patientCount]-1]++;

    printf("Is admitted to ward?(1-Yes,0-No):");
    scanf("%d",&patientAdmitted[patientCount]);

    if(patientAdmitted[patientCount]==1)
    {
        printf("Enter ward ID (1-4):");
        scanf("%d",&patientWard[patientCount]);

        bedNumber = allocateBed(patientWard[patientCount]);

        if(bedNumber == 0)
        {
            printf("No beds available in the selected ward.\n");
        }
        else
        {
            printf("Bed allocated successfully.Bed #%02d\n",bedNumber);
        }

        printf("Enter number of days admitted:");
        scanf("%d",&patientDays[patientCount]);
    }
    else
    {
        patientWard[patientCount]=0;
        patientDays[patientCount]=0;
    }

    patientIds[patientCount]=1001+patientCount;

    patientCount++;

    printf("Patient registered successfully.\n");
}
