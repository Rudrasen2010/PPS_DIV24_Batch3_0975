#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "navigation_history.txt"
#define SAFE_DISTANCE 20.0 // Minimum safe distance in cm

// Structure to hold navigation data
struct NavRecord {
    float distance;
    int x;
    int y;
    char direction[20];
    char status[30];
};

// Function to check if an obstacle was already recorded at (x, y)
int isRepeatedObstacle(int x, int y) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0; // File doesn't exist yet, so no repeated obstacle
    }

    struct NavRecord temp;
    // Read records from the file one by one
    while (fscanf(file, "%f %d %d %s %s", &temp.distance, &temp.x, &temp.y, temp.direction, temp.status) != EOF) {
        if (temp.x == x && temp.y == y && strcmp(temp.status, "OBSTACLE") == 0) {
            fclose(file);
            return 1; // Match found! It's a repeated obstacle
        }
    }

    fclose(file);
    return 0;
}

// Function to add a new sensor reading and decide movement
void addNavigationRecord() {
    struct NavRecord rec;
    FILE *file;

    printf("\n--- Enter Current Sensor Data ---\n");
    printf("Enter distance sensor reading (in cm): ");
    scanf("%f", &rec.distance);
    printf("Enter current X coordinate: ");
    scanf("%d", &rec.x);
    printf("Enter current Y coordinate: ");
    scanf("%d", &rec.y);
    printf("Enter intended movement direction (FORWARD/LEFT/RIGHT/BACK): ");
    scanf("%s", rec.direction);

    // Decision Logic
    if (rec.distance < SAFE_DISTANCE) {
        strcpy(rec.status, "OBSTACLE");
        printf("\n[ALERT] Obstacle detected at (%d, %d)!\n", rec.x, rec.y);

        // Check navigation history for repeated obstacles
        if (isRepeatedObstacle(rec.x, rec.y)) {
            printf("[WARNING] Repeated obstacle! This spot was blocked before.\n");
            printf("[DECISION] Rerouting: Take a 180-degree turn (Move BACK) and find a new path.\n");
            strcpy(rec.direction, "REROUTE_BACK");
        } else {
            printf("[DECISION] New obstacle: Stop and turn RIGHT to avoid collision.\n");
            strcpy(rec.direction, "TURN_RIGHT");
        }
    } else {
        strcpy(rec.status, "CLEAR");
        printf("\n[OK] Path is clear. Continuing %s.\n", rec.direction);
    }

    // Save record to file in append mode ("a")
    file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(file, "%.2f %d %d %s %s\n", rec.distance, rec.x, rec.y, rec.direction, rec.status);
    fclose(file);

    printf("Record saved to '%s'.\n", FILENAME);
}

// Function to display all past records from the file
void viewNavigationHistory() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("\nNo navigation history found yet.\n");
        return;
    }

    struct NavRecord rec;
    printf("\n--- Navigation History ---\n");
    printf("Dist(cm)\tX\tY\tAction\t\tStatus\n");
    printf("--------------------------------------------------------\n");

    while (fscanf(file, "%f %d %d %s %s", &rec.distance, &rec.x, &rec.y, rec.direction, rec.status) != EOF) {
        printf("%.2f\t\t%d\t%d\t%-12s\t%s\n", rec.distance, rec.x, rec.y, rec.direction, rec.status);
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Robot Navigation System ===\n");
        printf("1. Log New Sensor Reading & Calculate Move\n");
        printf("2. View Navigation History\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNavigationRecord();
                break;
            case 2:
                viewNavigationHistory();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
