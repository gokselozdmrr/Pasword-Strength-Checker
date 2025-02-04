#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MIN_LENGTH 8

/*
 * Checks password strength based on:
 *   1) Length >= 8
 *   2) Contains uppercase
 *   3) Contains lowercase
 *   4) Contains digit
 *   5) Contains special character
 *
 * Returns an integer count of how many criteria were satisfied (0 to 5).
 */


int checkPasswordCriteria(const char* password){
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    bool hasMinLength = false;

    int length = strlen(password);

    // Check minimum length

    if (length < MIN_LENGTH){
        printf("Your password is shorter tham minimum length!!!...\n");
        printf("Your password's length should be equal or more than 8...\n");
    }

    else{
        

        hasMinLength = true;

        // Check other criterias by scanning each character

        for(int i = 0; i < length; i++){
            if(isupper((unsigned char)password[i])){
                hasUpper = true;
            }
            else if (islower((unsigned char)password[i])) {
                hasLower = true;
            } 
            else if (isdigit((unsigned char)password[i])) {
                hasDigit = true;
            } 
            else {
                // If it's not alphanumeric, consider it a special character
                hasSpecialChar = true;
            }
    }

    // Count how many conditions are met

    int score = 0;

    if(hasMinLength)
    {
        score++;
    }
    if (hasUpper)
    {
        score++;
    }
    if (hasLower)
    {
        score++;
    }
    if (hasDigit)
    {
        score++;
    }
    if (hasSpecialChar)
    {
        score++;
    }

    return score;
   }
    
    
}

const char* getStrengthLabel(int score) {
    /*
     * This function returns a textual label for a given score.
     * You can adjust the thresholds as you see fit.
     */
    switch(score) {
        case 2:
            return "Weak\n";
        case 3:
            return "Medium\n";
        case 4:
            return "Strong\n";
        case 5:
            return "Very Strong\n";
        default:
            return "Undefined\n";
    }
}


int main(void) {
    char password[256];

    printf("Enter your password: ");
    // Read input from the user. Note: Use safer alternatives as needed.
    scanf("%255s", password);

    int score = checkPasswordCriteria(password);
    const char *label = getStrengthLabel(score);

    printf("Password Strength: %s\n", label);

    return 0;
}
