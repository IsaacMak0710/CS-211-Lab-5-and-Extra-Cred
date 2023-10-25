/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Isaac Mak
| Course:           CS-211: Introduction to Programming for Engineers
| Program  Name:    Lab #5
| Date:             10/24/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   Take a data file full of numbers and take the bit values and use bit manipulation
|   to evaluate the monster, color, and strength and print them out in a table form.
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Inputs that were used are the numbers found in the data file. The bits evaluated from the data, the monster code, 
|   monster string, color code, color string, and strength.
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The calcuations done in this lab are the functions that process the data by using bit manipulation with a mask in order
|   to return the bits needed for the monster, color, and strength.
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The monster, color, and strength are printed out in a table form.
|   As well as the number of monsters and average strength:
|      Number of Dragons: 26
|      Number of Goblins: 27
|      Number of Trolls: 23
|      Number of Ghosts: 24
|      Average Monster Strength: 30
|
|--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "MakI_Lab5.h"

int main(void) {

  // Declare two strings of 10 characters each
  char monster[10];
  char color[10];

  // Declare variables to hold data for the monster, color, and strength
  int number;
  int monsterCode;
  int colorCode;
  int monsterStrength;

  // Declare Variables to hold Monster Counters
  int dragonCounter = 0;
  int goblinCounter = 0;
  int trollCounter = 0;
  int ghostCounter = 0;
  int totalMonsters;

  // Declare Variable for total strength and average strength
  int totalStrength = 0;
  int averageStrength;
  
  // Declare two file pointers
  FILE* pInputFile = fopen("Lab5_DataFile.txt", "r");
  FILE* pOutputFile = fopen("Lab5_Output.txt", "w");
  
  // Print Header
  PrintHeader(pOutputFile, SCHOOL, LAB, PROGRAMMER);

  // Print Table Header
  PrintTableHeader(pOutputFile);

  // Print Divider
  PrintDivider(pOutputFile, DASH, DIVIDER_LENGTH);

  // File Error Checker
  if (pInputFile == NULL) 
  {
    perror("Error opening the file");
    return 1;
  }

  // File Processing Loop
  fscanf(pInputFile, "%d", &number); // Primer
  while (!feof(pInputFile))
  {
    monsterCode = GetMonsterCode(number); // Get Bit Value for Monster
    colorCode = GetColorCode(number); // Get Bit Value for Color
    monsterStrength = GetStrength(number); // Get value for Strength
    totalStrength+=monsterStrength; // Update total strength
    GetMonster(monsterCode, monster, &dragonCounter, &goblinCounter, &trollCounter, &ghostCounter); // Get Monster Name from Monster Code
    GetColor(colorCode, color); // Get Color Name from Color Code
    PrintLineOfData(pOutputFile, monster, color, monsterStrength); // Print Data to File
    fscanf(pInputFile, "%d", &number); // Update number value to next row in data file
  }

  // Print Divider
  PrintDivider(pOutputFile, DASH, DIVIDER_LENGTH);

  // Print Monster Counts
  fprintf(pOutputFile, "Number of Dragons: %d\n", dragonCounter);
  fprintf(pOutputFile, "Number of Goblins: %d\n", goblinCounter);
  fprintf(pOutputFile, "Number of Trolls: %d\n", trollCounter);
  fprintf(pOutputFile, "Number of Ghosts: %d\n", ghostCounter);

  // Print Divider
  PrintDivider(pOutputFile, DASH, DIVIDER_LENGTH);

  // Print Average Strength
  totalMonsters = dragonCounter + goblinCounter + trollCounter + ghostCounter;
  averageStrength = AverageStrength(totalStrength, totalMonsters);
  fprintf(pOutputFile, "Average Monster Strength: %d\n", averageStrength);

  // Print Divider
  PrintDivider(pOutputFile, DASH, DIVIDER_LENGTH);

  return 0;
}