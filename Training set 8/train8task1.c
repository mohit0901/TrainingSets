#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#define TBLSZ 5000
// Hashing choice related constants
#define DIVISION '%'
#define MULTIPLICATIVE '*'
#define LINEAR 1
// Step size for linear probing. Use only primes
#define STEP 2
#define DOUBLE_HASHING 2
#define QUADRATIC_REHASH 4
// To be set by the students as needed
#define PRIMARY_HASHING_METHOD MULTIPLICATIVE
#define PROBING_METHOD LINEAR
// The following are primes < TBLSZ
int usedSize, // Part of the table that will be used
probeStepSz; // Step size for double hashing
double goldenNumber;
char *table[TBLSZ];
int initialise(int tableSize)
{
/* Find two suitable prime values for
two division hashings funtions.
*/
/* usedSize should be a prime that is nearly
as big as TBLSZ
This sets the part of the table that is actually
used to store pointers to strings
*/
    assert(TBLSZ > 1000);
    assert(PROBING_METHOD >=0);
    assert(PROBING_METHOD < 3);
    assert(PRIMARY_HASHING_METHOD == MULTIPLICATIVE ||
    PRIMARY_HASHING_METHOD == DIVISION);
    goldenNumber = (sqrt(5.0)+1)/2;
    int testing, prime, i;
    if (TBLSZ%2 == 0)
        usedSize = TBLSZ-1;
    else
        usedSize = TBLSZ;
    /* Begin with usedSize as big as TBLSZ and
    progressively lower it till it is a prime
    Pointers to words/strings will be stored
    in index range 0 to usedSize-1 only.
    */
    while (usedSize > 2)
    { // Keep trying
        i = 3;
        while (i*i <= usedSize)
        {
            if (usedSize%i == 0)
            {
                /* No good */
                usedSize -= 2;
                break;
            }
            i += 2;
        }
        if (i*i > usedSize)
        {
            assert(usedSize > 1000);
            assert(usedSize < TBLSZ);
            break;
        }
    }
    /* The following code finds a prime to use to do
    probes over the table when there is a collision */
    probeStepSz = 2;
    while (probeStepSz*probeStepSz < usedSize)
        probeStepSz *= 2;
    /* Similar to the previous search for a prime */
    while (probeStepSz > 2)
    { // Keep trying
        i = 3;
        while (i*i <= probeStepSz)
        {
            if (probeStepSz%i == 0)
            {
                /* No good */
                probeStepSz -= 2;
                break;
            }
            i += 2;
        }
        if (i*i > probeStepSz)
        {
            assert(probeStepSz > 1);
            assert(probeStepSz < usedSize);
            break;
        }
    }
}
int goldenMultiplicative(int key, int size)
{
/* Returns the primary location for the data
in the hash table.
The location is computed using
multiplication by golden number.
Reference: Reema Thareja Edn 2 page 468
*/
    double multiplier = goldenNumber - 1;
    double frac = (key*multiplier);
    int index = frac;
    frac = frac-index; // Get fractional part
    index = frac*size;
    assert(index >= 0);
    assert(index < size);
    return index;
}
int makeNumber(char *str)
{
/* ********************************************
Students to use code - implementation not important
Construct a number from the string
The function may return the same number for
several different strings
However, it will alway return the same number
for a string
**********************************************/
    assert(str != NULL);
    int num = 0;
    int el = strlen(str);
    int i = el - 1; // Next letter to process
    if (el%2 == 0) el--; // Make it odd
    assert(el < 20 && el > 0); // Too long a word
    /* Computer specific limit on while */
    while(num < INT_MAX/26/26)
    {
        num = num*26+toupper(str[i])-toupper('A');
        i = (i+2)%el; // Choose alternate letters
    }
    num = 26*num+el; // Include word length
    return num;
}
int indexAdvisedByHash(int key, int probe)
{
    /* What arrangement has been chosen */
    int step, goldIndx;
    switch (PRIMARY_HASHING_METHOD)
    {
        case DIVISION:
            switch (PROBING_METHOD)
            {
                case LINEAR:
                    return (key + STEP*probe)%usedSize;
                case DOUBLE_HASHING:
                    step = key%probeStepSz;
                // step != 0 is necessary
                    if (step < 2)
                        step = 17;
                    return (key + probe*step)%usedSize;
                default:
                    assert(0); // Unexpected
                return 0;
            }
        case MULTIPLICATIVE:
        goldIndx = goldenMultiplicative(key, usedSize);
        switch (PROBING_METHOD)
        {
            case LINEAR:
                return (goldIndx + STEP*probe)%usedSize;
            case DOUBLE_HASHING:
                step = goldenMultiplicative(key,
                probeStepSz);
                // step != 0 is necessary
                if (step < 2)
                    step = 1009;
                return (goldIndx + probe*step)%usedSize;
            default:
                assert(0); // Not expected
            return 0;
        }
        default:
            assert(0); // ERROR
    }
}
int main(void)
{
    FILE *collection = fopen("collection.txt", "r");
    assert(collection != NULL);
    char strg[100];
    char * dataP;
    int loc, collisions=0, noCollisions=0;
    int el, reTry, rehash, filled;
    initialise(TBLSZ);
    /* Read word from FILE collection and
    store pointer to word in array table[].
    Array index to be determined by a
    hashing method.
    */
    while (fgets(strg,90,collection))
    {
        el= strlen(strg)-1;
        strg[el] = '\0';
        dataP = malloc(strlen(strg)+1);
        assert(dataP != NULL);
        strcpy(dataP, strg);
        /* reTry == 0 is primary hashing attempt.
        reTry > 0 are attempted alternate locations.
        */
        reTry = 0;
        while (rehash < 100)
        {
            loc = indexAdvisedByHash(makeNumber(strg), reTry);
            if (table[loc] != NULL)
            {
                reTry++;
                collisions++;
                continue;
            }
            else
            {
                filled++;
                table[loc] = dataP;
                break;
            }
        }
    }
    printf("Total collisions %d\n", collisions);
    printf("Unused %d\n", TBLSZ-filled);
    printf("Filled %d\n", filled);
    return 0;
}



