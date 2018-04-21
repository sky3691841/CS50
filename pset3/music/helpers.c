// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //transfer stirng into an integer
    char x[2];
    char y[2];

    x[0] = fraction[0];
    y[0] = fraction[2];

    int num = atoi(x);
    int denom = atoi(y);

    //transfer all denominator to 8
    num = num * (8 / denom);

    return num;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //transfer string into integer
    int oct = 0;

    if (strlen(note) == 2)
    {
        oct = note[1] - 48;
    }
    else if (strlen(note) == 3)
    {
        oct = note[2] - 48;
    }

    //octave semitone (from octave 4), define A0-A8
    int oct_semitones = 12 * (oct - 4);

    //note semitones (from A)
    int note_semitones = 0;

    if (note[0] == 'A')
    {
        note_semitones = 0.0;
    }
    else if (note[0] == 'B')
    {
        note_semitones = 2.0;
    }
    else if (note[0] == 'G')
    {
        note_semitones = -2.0;
    }
    else if (note[0] == 'F')
    {
        note_semitones = -4.0;
    }
    else if (note[0] == 'E')
    {
        note_semitones = -5.0;
    }
    else if (note[0] == 'D')
    {
        note_semitones = -7.0;
    }
    else if (note[0] == 'C')
    {
        note_semitones = -9.0;
    }

    //implement sharp and flat notes
    if (note[1] == '#')
    {
        note_semitones ++;
    }
    else if (note[1] == 'b')
    {
        note_semitones --;
    }

    //calculate total semitones away from A4
    int n = oct_semitones + note_semitones;

    //calculate hertz
    double hz = round(pow(2, n / 12.0) * 440);

    return hz;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //returns true if user's line is a blank
    if (strcmp(s, "") == 0)
    {
        return true;
    }

    return false;
}
