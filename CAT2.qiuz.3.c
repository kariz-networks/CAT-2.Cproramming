/*
Name: joseph kariuki gichuhi
Reg:CT100/G/26129/25
Desription:storing integers in "input.txt"
*/
#include <stdio.h>
int main() {
	#include <stdio.h>
#include <stdlib.h> // Required for exit()

// Function Prototypes
void write_input_file();
void process_file();
void display_files();

int main() {
    write_input_file();
    process_file();
    display_files();
    return 0;
}

// 1. Write 10 integers to 'input.txt'
void write_input_file() {
    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("ERROR: Cannot open 'input.txt'.\n");
        // Use exit(1) only if the program absolutely cannot continue.
        // For this task, it's acceptable.
        exit(1);
    }

    printf("--- Input 10 Integers ---\n");
    int num, i;
    for (i = 0; i < 10; i++) {
        printf("Int #%d: ", i + 1);
        
        // CORRECTION: Check if scanf was successful
        if (scanf("%d", &num) == 1) {
            fprintf(fp, "%d\n", num);
        } else {
            // Error Handling: If scanf failed (non-number entered)
            printf("Invalid input. Please enter an integer.\n");
            
            // Clear the input buffer to prevent infinite loop or skipping next input
            int c;
            while ((c = getchar()) != '\n' && c != EOF); 
            
            // Decrement counter to retry the current input
            i--; 
        }
    }
    printf("Data written.\n");
    fclose(fp);
}

// 2. Read 'input.txt', calc sum/avg, write to 'output.txt'
void process_file() {
    FILE *fpin = fopen("input.txt", "r");
    FILE *fpout = fopen("output.txt", "w");
    if (fpin == NULL || fpout == NULL) {
        printf("ERROR: Cannot process files.\n");
        // Clean up the opened file if one failed
        if (fpin) fclose(fpin);
        if (fpout) fclose(fpout);
        exit(1);
    }

    int num, count = 0;
    long long sum = 0;
    
    // Read & Calculate
    while (fscanf(fpin, "%d", &num) == 1) { 
        sum += num;
        count++;
    }
    
    // Write Results
    if (count > 0) {
        float avg = (float)sum / count;
        fprintf(fpout, "SUM: %lld\n", sum);
        fprintf(fpout, "AVERAGE: %.2f\n", avg);
        printf("Processing complete.\n");
    } else {
        fprintf(fpout, "No data found.\n");
        printf("No data found in input file.\n");
    }

    fclose(fpin);
    fclose(fpout);
}

// 3. Display contents of both files
void display_files() {
    FILE *fp;
    char buffer[256];

    printf("\n--- RESULTS ---\n");

    // Display 'input.txt'
    printf(">>> input.txt (Raw Data):\n");
    fp = fopen("input.txt", "r");
    if (fp != NULL) {
        while (fgets(buffer, sizeof(buffer), fp) != NULL) { printf("%s", buffer); }
        fclose(fp);
    } else {
         printf("[File not found]\n");
    }

    // Display 'output.txt'
    printf(">>> output.txt (Summary):\n");
    fp = fopen("output.txt", "r");
    if (fp != NULL) {
        while (fgets(buffer, sizeof(buffer), fp) != NULL) { printf("%s", buffer); }
        fclose(fp);
    } else {
        printf("[File not generated]\n");	
	
	return 0;

}
