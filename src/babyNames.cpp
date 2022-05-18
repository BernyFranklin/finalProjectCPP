/*
 * babyNames.cpp Version#1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: nameToSearch
 * Output: match/noMatch and rank
 * 17 May 2022
 */

#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <cstring> 
#include <cstdlib> 
#include <cctype>
using namespace std;

// Start main
int main() {
    // Declare variables
    bool searchAgain = true;

    // Welcome user
    cout << "\n========================================";
    cout << "\n         Baby Name Finder v1.0          ";
    cout << "\n========================================";

    // Start loop for search
    while (searchAgain) {
        // Declare and initialize variables for loop
        char nameToSearch[100] = "";          // User input for search
        char boyName[100] = "";               // Placeholder for name
        char girlName[100] = "";              // Placeholder for name
        char again = ' ';                     // Search again input
        char fileName[] = "FirstNames.txt";   // Relative path to file
        char buff[100];                       // Buffer to read from file
        int boyCount = 0;                     // Counter
        int girlCount = 0;                    // Counter
        // Bools for name found
        bool boyNameFound = false;
        bool girlNameFound = false;

        // Prompt User for name to search
        cout << "\nPlease enter a name to search: ";
        // Read Input
        cin >> nameToSearch;

        // Open file
        ifstream inFile(fileName);
        // Did it open?
        if (inFile.fail()) {
            // Alert User
            cout << "\nUnable to open " << fileName;
            // Exit program and return 1
            return 1;   
        }   // End of check

        // Iterate through names and keep track until found
        while (!inFile.eof()) {
            // Read first name into boyName
            inFile >> boyName;
            // Update boyCount
            boyCount++;
            // Did we find a boy match?
            if (strcasecmp(nameToSearch, boyName) == 0) {
                // Set flag
                boyNameFound = true;
                cout << "\nThe name " << boyName << " has a rank of " << boyCount << " among boy names.";
            }   // End of boy match
            // Read next name into girlName
            inFile >> girlName;
            // Update girlCount
            girlCount++;
            // Did we find a girl match?
            if (strcasecmp(nameToSearch, girlName) == 0) {
                // Set flag
                girlNameFound = true;
                cout << "\nThe name " << girlName << " has a rank of " << girlCount << " among girls names.";
            }   // End of girl match

        }   // End of search

        // No matches
        if (!boyNameFound)
            cout << "\nThere were no boy names that matched the name " << nameToSearch << ".";
        if (!girlNameFound)
            cout << "\nThere were no girl names that matched the name " << nameToSearch << ".";


        // Search again?
        while (again != 'Y' && again != 'N') {
            // Prompt User
            cout << "\n\nWould you like to search another name? [Y or N]: ";
            // Read input
            cin >> again;
            // Convert to upperCase
            again = toupper(again);

            // Input valid?
            if (again == 'Y')
                searchAgain = true;
            else if (again == 'N')
                searchAgain = false;
            else
                cout << "Please enter [Y] or [N]";
        }   // End of search again prompt

    }   // End of loop

    // Goodbye
    cout << "\nThank you for using Baby Name Finder\n\n";

    return 0;
}   // End of main