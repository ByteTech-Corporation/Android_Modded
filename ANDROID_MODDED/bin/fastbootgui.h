#include <stdio.h>

void FastbootGUI()
{
    int main()
    {

        // Set color constants
        const int BLUE = 1;
        const int GRAY = 8;
        const int WHITE = 15;

        // Print OS info in blue
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
        printf("Android (Custom)\n");

        // Print hardware info in gray
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
        printf("Unknown CPU\n");

        // Print other info in white
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf("Copyright (C) 2024 The ModdedAndroidOS Project\n");

        return 0;
    }

    /// @brief mountPartition();
    // Update efs functions 
    void mount_efs();
    void print_efs_dir();



    char* efs_files[] = {"/efs/*"}; 

    void mount_efs() {
    printf("/efs partition mounted\n");
    }

    void print_efs_dir() {

    printf("Contents of /efs:\n");

    for(int i = 0; i < 3; i++) {
       printf("%s\n", efs_files[i]);
       }
    }

   // main.c

   int main() {

   mount_efs();
 
   print_efs_dir();
 
   return 0;
 }

}

