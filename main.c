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
const float wardRates[NUM_WARDS]={
    3000.00,
    6000.00,
    12000.00,
    25000.00
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
void viewBedStatus(void);

float calculateSurcharge(int triage,float baseFee);
float calculateWardCost(int ward,int days);
float calculateGrossTotal(float baseFee,float surcharge,float wardCost);
float calculateDiscount(int age,float grossTotal);

void viewPatientRecords(void);

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
float calculateSurcharge(int triage,float baseFee)
{
    if(triage ==1)
    {
        return 0;
    }
    else if(triage==2)
    {
        return baseFee * 0.20;
    }
    else
    {
        return baseFee * 0.50;
    }
}
float calculateWardCost(int ward,int days)
{
    if(ward == 0)
    {
        return 0;
    }
    return days * wardRates[ward -1];
}
float calculateGrossTotal(float baseFee,float surcharge,float wardCost)
{
    return baseFee + surcharge +wardCost;
}
float calculateDiscount(int age,float grossTotal)
{
    if(age < 5|| age >65)
    {
        return grossTotal * 0.15;
    }
    else
    {
        return 0;
    }
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
    else if(choice == 2)
    {
        viewPatientRecords();
    }
    else if(choice == 3)
    {
        viewBedStatus();
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

    float baseFee;
    float surcharge;
    float wardCost;
    float grossTotal;
    float discount;
    float finalAmount;

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

    baseFee = specialtyFees[patientSpecialty[patientCount]-1];

    surcharge = calculateSurcharge(
        patientTriage[patientCount],
        baseFee
    );

    wardCost = calculateWardCost(
        patientWard[patientCount],
        patientDays[patientCount]
    );

    grossTotal = calculateGrossTotal(
        baseFee,
        surcharge,
        wardCost
    );

    discount = calculateDiscount(
        patientAges[patientCount],
        grossTotal
    );

    finalAmount = grossTotal - discount;

    printf("\n============================================\n");
    printf("SMART HOSPITAL ADMISSION & BILL\n");
    printf("==============================================\n");

    printf("Patient ID               : PAT-%d\n",patientIds[patientCount]);
    printf("Patient Name             : %s\n",patientNames[patientCount]);
    printf("Age                      : %d\n",patientAges[patientCount]);
    printf("Specialty                : %s\n",specialtyNames[patientSpecialty[patientCount]-1]);

    printf("Base Consultation Fee    : LKR %.2f\n", baseFee);
    printf("Emergency Surcharge      : LKR %.2f\n", surcharge);
    printf("Ward Stay Cost           : LKR %.2f\n", wardCost);

    printf("Gross Total Bill         : LKR %.2f\n", grossTotal);
    printf("Age Subsidy Discount     : LKR %.2f\n", discount);
    printf("Final Payable Amount     : LKR %.2f\n", finalAmount);

    printf("Estimated Waiting Time   : %d minutes\n", waitingTime);

    printf("================================================\n");
    patientCount++;

    printf("Patient registered successfully.\n");
}
void viewPatientRecords(void)
{
    int i;

    printf("\n==============================================\n");
    printf("           PATIENT RECORDS\n");
    printf("================================================\n");

    if(patientCount == 0)
    {
        printf("No patient records available.\n");
        return;
    }
    for(i =0; i< patientCount; i++)
    {
        printf("\nPatient ID     : %d\n",patientIds[i]);
        printf("Name             : %s\n",patientNames[i]);
        printf("Age              : %d\n",patientAges[i]);
        printf("Triage Level     : %d\n",patientTriage[i]);

        printf("Specialty        : %s\n",specialtyNames[patientSpecialty[i]-1]);

        if(patientAdmitted[i]==1)
        {
            printf("Admitted      : Yes\n");

            printf("Ward          : %s\n",wardNames[patientWard[i]-1]);

            printf("Days          : %d\n",patientDays[i]);

        }
        else
        {
            printf("Admitted      : No\n");
        }

        printf("--------------------------------------------------\n");
    }
}
void viewBedStatus(void)
{
    int ward;
    int bed;

    printf("\n=======================================================\n");
    printf("                 BED STATUS\n");
    printf("=========================================================\n");

    for(ward = 0;ward <NUM_WARDS;ward++)
    {
        printf("\n%s\n",wardNames[ward]);
        printf("------------------------------------------------------\n");

        for(bed =0;bed<wardCapacities[ward];bed++)
        {
            printf("Bed %02d :",bed + 1);

            if(bedOccupancy[ward][bed]==0)
            {
                printf("Available\n");
            }
            else
            {
                printf("Occupied\n");
            }

        }
    }
    printf("============================================================\n");

}
