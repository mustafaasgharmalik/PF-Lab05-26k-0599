#include <stdio.h>
#define DOOR_LOCK     (1 << 0) // Bit value 1
#define ALARM_SYSTEM  (1 << 1) // Bit value 2
#define CCTV_CAMERA   (1 << 2) // Bit value 4
#define MOTION_SENSOR (1 << 3) // Bit value 8

int main(void) {
    int status = 0;
    int operationChoice = 0;
    int deviceChoice = 0;
    int modeChoice = 0;

    printf("========================================\n");
    printf("     SMART HOME SECURITY CONTROLLER     \n");
    printf("========================================\n");

    printf("Enter initial system status integer (0 to 15, or 0 for all inactive): ");
    if (scanf("%d", &status) != 1) {
        printf("Error: Invalid numeric input.\n");
        return 1;
    }

    status = status & 0x0F;

    printf("\nAvailable Operations:\n");
    printf("1. Activate a Device\n");
    printf("2. Deactivate a Device\n");
    printf("3. Check Device Status\n");
    printf("4. Toggle Device State\n");
    printf("5. Select Security Mode\n");
    printf("Select an operation (1-5): ");

    if (scanf("%d", &operationChoice) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }


    switch (operationChoice) {
        case 1:
            printf("\nSelect device to activate:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter device choice (1-4): ");
            scanf("%d", &deviceChoice);

            switch (deviceChoice) {
                case 1:
                    status |= DOOR_LOCK;
                    printf("\nAction: Main Door Lock activated.\n");
                    break;
                case 2:
                    status |= ALARM_SYSTEM;
                    printf("\nAction: Alarm System activated.\n");
                    break;
                case 3:
                    status |= CCTV_CAMERA;
                    printf("\nAction: CCTV Camera activated.\n");
                    break;
                case 4:
                    status |= MOTION_SENSOR;
                    printf("\nAction: Motion Sensor activated.\n");
                    break;
                default:
                    printf("\nError: Invalid device choice selected.\n");
                    break;
            }
            break;

        case 2: // Deactivate a device
            printf("\nSelect device to deactivate:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter device choice (1-4): ");
            scanf("%d", &deviceChoice);

            // Nested switch statement to select specific device
            switch (deviceChoice) {
                case 1:
                    status &= ~DOOR_LOCK;
                    printf("\nAction: Main Door Lock deactivated.\n");
                    break;
                case 2:
                    status &= ~ALARM_SYSTEM;
                    printf("\nAction: Alarm System deactivated.\n");
                    break;
                case 3:
                    status &= ~CCTV_CAMERA;
                    printf("\nAction: CCTV Camera deactivated.\n");
                    break;
                case 4:
                    status &= ~MOTION_SENSOR;
                    printf("\nAction: Motion Sensor deactivated.\n");
                    break;
                default:
                    printf("\nError: Invalid device choice selected.\n");
                    break;
            }
            break;

        case 3: // Check status of a device
            printf("\nSelect device to check status:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter device choice (1-4): ");
            scanf("%d", &deviceChoice);

            // Nested switch statement to select specific device
            switch (deviceChoice) {
                case 1:
                    printf("\nStatus: Main Door Lock is %s.\n",
                           (status & DOOR_LOCK) ? "ACTIVE" : "INACTIVE");
                    break;
                case 2:
                    printf("\nStatus: Alarm System is %s.\n",
                           (status & ALARM_SYSTEM) ? "ACTIVE" : "INACTIVE");
                    break;
                case 3:
                    printf("\nStatus: CCTV Camera is %s.\n",
                           (status & CCTV_CAMERA) ? "ACTIVE" : "INACTIVE");
                    break;
                case 4:
                    printf("\nStatus: Motion Sensor is %s.\n",
                           (status & MOTION_SENSOR) ? "ACTIVE" : "INACTIVE");
                    break;
                default:
                    printf("\nError: Invalid device choice selected.\n");
                    break;
            }
            break;

        case 4: // Toggle device state
            printf("\nSelect device to toggle:\n");
            printf("1. Main Door Lock (Bit 1)\n");
            printf("2. Alarm System (Bit 2)\n");
            printf("3. CCTV Camera (Bit 4)\n");
            printf("4. Motion Sensor (Bit 8)\n");
            printf("Enter device choice (1-4): ");
            scanf("%d", &deviceChoice);

            // Nested switch statement to select specific device
            switch (deviceChoice) {
                case 1:
                    status ^= DOOR_LOCK;
                    printf("\nAction: Main Door Lock toggled to %s.\n",
                           (status & DOOR_LOCK) ? "ACTIVE" : "INACTIVE");
                    break;
                case 2:
                    status ^= ALARM_SYSTEM;
                    printf("\nAction: Alarm System toggled to %s.\n",
                           (status & ALARM_SYSTEM) ? "ACTIVE" : "INACTIVE");
                    break;
                case 3:
                    status ^= CCTV_CAMERA;
                    printf("\nAction: CCTV Camera toggled to %s.\n",
                           (status & CCTV_CAMERA) ? "ACTIVE" : "INACTIVE");
                    break;
                case 4:
                    status ^= MOTION_SENSOR;
                    printf("\nAction: Motion Sensor toggled to %s.\n",
                           (status & MOTION_SENSOR) ? "ACTIVE" : "INACTIVE");
                    break;
                default:
                    printf("\nError: Invalid device choice selected.\n");
                    break;
            }
            break;

        case 5: // Security Modes
            printf("\nSelect Security Mode:\n");
            printf("1. Home Mode (Door Lock + CCTV Camera)\n");
            printf("2. Away Mode (All 4 Devices)\n");
            printf("3. Night Mode (Door Lock + Alarm + Motion Sensor; CCTV unchanged)\n");
            printf("Enter mode choice (1-3): ");
            scanf("%d", &modeChoice);

            // Switch statement to process security modes
            switch (modeChoice) {
                case 1: // Home Mode: Door Lock & CCTV
                    status |= (DOOR_LOCK | CCTV_CAMERA);
                    printf("\nMode: Home Mode activated.\n");
                    break;
                case 2: // Away Mode: All 4 devices
                    status |= (DOOR_LOCK | ALARM_SYSTEM | CCTV_CAMERA | MOTION_SENSOR);
                    printf("\nMode: Away Mode activated.\n");
                    break;
                case 3: // Night Mode: Door Lock, Alarm, Motion Sensor (CCTV unchanged)
                    status |= (DOOR_LOCK | ALARM_SYSTEM | MOTION_SENSOR);
                    printf("\nMode: Night Mode activated.\n");
                    break;
                default:
                    printf("\nError: Invalid security mode selected.\n");
                    break;
            }
            break;

        default:
            printf("\nError: Invalid operation choice.\n");
            break;
    }

    // Binary status display using right-shift operations (without loops)
    printf("\n========================================\n");
    printf("         CURRENT SYSTEM STATUS          \n");
    printf("========================================\n");
    printf("Status Value (Decimal)  : %d\n", status);
    printf("Binary Status [b3 b2 b1 b0]: %d %d %d %d\n",
           (status >> 3) & 1,
           (status >> 2) & 1,
           (status >> 1) & 1,
           (status >> 0) & 1);
    printf("----------------------------------------\n");
    printf("Main Door Lock (Bit 1) : %s\n", (status & DOOR_LOCK) ? "Active" : "Inactive");
    printf("Alarm System   (Bit 2) : %s\n", (status & ALARM_SYSTEM) ? "Active" : "Inactive");
    printf("CCTV Camera    (Bit 4) : %s\n", (status & CCTV_CAMERA) ? "Active" : "Inactive");
    printf("Motion Sensor  (Bit 8) : %s\n", (status & MOTION_SENSOR) ? "Active" : "Inactive");
    printf("----------------------------------------\n");

    // Logical operators evaluate whether complete system is armed (all four bits set simultaneously)
    int isArmed = ((status & DOOR_LOCK) &&
                   (status & ALARM_SYSTEM) &&
                   (status & CCTV_CAMERA) &&
                   (status & MOTION_SENSOR));

    // Conditional operator used to display concise status message
    printf("Overall Security State : %s\n", isArmed ? "SYSTEM FULLY ARMED" : "SYSTEM NOT FULLY ARMED");
    printf("========================================\n");

    return 0;
}
