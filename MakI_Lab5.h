#ifndef MAKI_LAB4_H
#define MAKI_LAB4_H

#include <string.h>
#include <stdio.h>

// Macros for Headers
#define DIVIDER_LENGTH 110
#define STAR '*'
#define DASH '-'
#define SCHOOL "Binghamton University\n"
#define LAB "Lab 5 - Bit Manipulation\n"
#define PROGRAMMER "Program Written by: Isaac Mak\n"

#define MONSTER "Monster"
#define COLOR "Color"
#define STRENGTH "Strength"

// Function Prototypes
void PrintHeader(FILE* outputFile, char school[], char lab[], char programmer[]);

void PrintDivider(FILE* outputFile, char symbol, int numberOf);

void CenterString(FILE* outputFile, char string[], int lengthToCenterAcross);

void PrintTableHeader(FILE* outputFile);

int GetColorCode(int colorCode);

int GetMonsterCode(int monsterCode);

int GetStrength(int number);

void GetColor(int colorCode, char color[]);

void GetMonster(int monsterCode, char monster[], int* dragonCounter, int* goblinCounter, int* trollCounter, int* ghostCounter);

void PrintLineOfData(FILE* outputFile, char monster[], char color[], int strength);

int AverageStrength(int totalStrength, int totalMonsters);

#endif