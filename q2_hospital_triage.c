#include <stdio.h>

int main() {
    int department, age, heartRate, consciousness, severity;
    float temp;
    int isDeptEmergency = 0;
    int isCritical = 0;
    int isSeniorPriority = 0;
    int isTempAlert = 0;
    int caseRem;

    printf("=== EMERGENCY TRIAGE SYSTEM ===\n");
    printf("Select Department:\n");
    printf("1. General Emergency\n2. Cardiology\n3. Neurology\n4. Trauma\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &department);

    printf("Enter patient age: ");
    scanf("%d", &age);

    printf("Enter heart rate (bpm): ");
    scanf("%d", &heartRate);

    printf("Enter body temperature (C): ");
    scanf("%f", &temp);

    printf("Is patient conscious? (1 = Yes, 0 = No): ");
    scanf("%d", &consciousness);

    printf("Enter severity level (1 to 10): ");
    scanf("%d", &severity);

    // Check department specific conditions using switch
    switch (department) {
        case 1: // General Emergency
            if (severity >= 7) {
                isDeptEmergency = 1;
            }
            break;

        case 2: // Cardiology
            // Cardiac attention needed if heart rate is abnormally high (> 120) or low (< 50)
            if (heartRate < 50 || heartRate > 120) {
                isDeptEmergency = 1;
            }
            break;

        case 3: // Neurology
            // Urgent attention needed if unconscious
            if (consciousness == 0) {
                isDeptEmergency = 1;
            }
            break;

        case 4: // Trauma
            // High severity level is high priority
            if (severity >= 8) {
                isDeptEmergency = 1;
            }
            break;

        default:
            printf("Invalid department code.\n");
            return 1;
    }

    // Critical condition check (heart rate < 50 or > 120 AND unconscious)
    if ((heartRate < 50 || heartRate > 120) && (consciousness == 0)) {
        isCritical = 1;
    }

    // Temperature alert (below 36 or above 38)
    if (temp < 36.0 || temp > 38.0) {
        isTempAlert = 1;
    }

    // Senior priority check
    if (age >= 65) {
        isSeniorPriority = 1;
    }

    // Case number calculation using modulus
    caseRem = (age + heartRate) % 4;

    // Display Findings
    printf("\n-------------------------------\n");
    printf("       TRIAGE ASSESSMENT       \n");
    printf("-------------------------------\n");
    
    switch(department) {
        case 1: printf("Department           : General Emergency\n"); break;
        case 2: printf("Department           : Cardiology\n"); break;
        case 3: printf("Department           : Neurology\n"); break;
        case 4: printf("Department           : Trauma\n"); break;
    }

    // Display Case Category using switch
    switch (caseRem) {
        case 0: printf("Case Category        : Case Category A\n"); break;
        case 1: printf("Case Category        : Case Category B\n"); break;
        case 2: printf("Case Category        : Case Category C\n"); break;
        case 3: printf("Case Category        : Case Category D\n"); break;
    }

    // Using conditional operators for quick status outputs
    printf("Senior Priority      : %s\n", isSeniorPriority ? "Yes" : "No");
    printf("Temperature Alert    : %s\n", isTempAlert ? "ALERT (Abnormal Temp)" : "Normal");
    printf("Critical Condition   : %s\n", isCritical ? "CRITICAL" : "Non-Critical");

    // Final Triage Decision Logic
    printf("\nFINAL TRIAGE DECISION: ");
    if (isCritical) {
        printf("IMMEDIATE MEDICAL ATTENTION REQUIRED!\n");
    } else if (isDeptEmergency || isSeniorPriority || isTempAlert) {
        printf("HIGH PRIORITY - Assigned for Urgent Assessment.\n");
    } else {
        printf("ROUTINE MEDICAL ASSESSMENT - Place in Standard Queue.\n");
    }
    printf("-------------------------------\n");

    return 0;
}