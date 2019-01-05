// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int n = strlen(fraction);
    int duration = 0;
    if(n == 3)
        duration = 8*atoi(&fraction[0])/atoi(&fraction[2]);
    else if(n == 1)
        duration =  8*atoi(&fraction[0]);
    else
    {
        printf("Improper note format.\n");
        exit(2);
    }

    return duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int octave = 0;
    int let = 0;
    char letter = note[0];
    char mod;
    int n = strlen(note);

    if(letter == 'C') let = -9;
    else if(letter == 'D') let = -7;
    else if(letter == 'E') let = -5;
    else if(letter == 'F') let = -4;
    else if(letter == 'G') let = -2;
    else if(letter == 'A') let = 0;
    else if(letter == 'B') let = 2;
    else
    {
        printf("Notes are A-G.\n");
        exit(1);
    }

    if(n==2)
    {
        octave = atoi(&note[1]) - 4;
    }
    else if(n==3)
    {
        octave = atoi(&note[2]) - 4;
        mod = note[1];
        if(mod == '#') let++;
        else if(mod == 'b') let--;
        else
        {
            printf("Mod usage: '#' or 'b'\n");
            exit(1);
        }
    }
    else
    {
        printf("Note format: A4 or A#4\n");
        exit(1);
    }
    return round( pow(2,(double)(octave*12 + let)/12.0) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strlen(s) == 0)
        return true;
    else
        return false;
}
