#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftArray(int arr[], int len, int repeatedCharIdx, int currentCharIdx,
                char currentChar) {
  printf("Current char index: %d\n", currentCharIdx);
  printf("Current repeated char index: %d\n", repeatedCharIdx);
  // Shift the rest of the array to the left
  for (int i = 0; i <= (currentCharIdx - repeatedCharIdx); i++) {
    printf("Current char shifted %c\n", arr[i + repeatedCharIdx + 1]);
    arr[i] = arr[i + repeatedCharIdx + 1];
    if (i == (currentCharIdx - repeatedCharIdx))
      arr[i] = currentChar;
    printf("Assigned char shifted %c\n", arr[i]);
  }

  for (int i = (currentCharIdx - repeatedCharIdx) + 1; i < len; i++) {
    arr[i] = 0;
  }

  printf("Set of chars inside the reset function: \n");
  for (int i = 0; i <= len; i++) {
    printf("%c ", (char)arr[i]);
  }
  printf("\n");
}

int main() {
  // test char (Input)
  char s[] = "abcabcbb";
  // char s[] = "pwwkew";

  int len = strlen(s);
  int stringAppendCounter = 0;
  int longest = 0;
  int *tempArr = (int *)calloc(len, sizeof(int));

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      // Check if the char not existed in the list
      if (s[i] != tempArr[j]) {
        // Check until the end of the list
        if (j == len - 1) {
          tempArr[stringAppendCounter++] = s[i];
          printf("This get called with character %c\n", s[i]);
        }
      } else {
        printf("Resetted via character %c at index %d\n", tempArr[j], j);
        shiftArray(tempArr, len, j, stringAppendCounter - 1, s[i]);
        if (longest < stringAppendCounter)
          longest = stringAppendCounter;
        stringAppendCounter = stringAppendCounter - j;
        break;
      };
    }
  }
  if (longest < stringAppendCounter)
    longest = stringAppendCounter;

  // Return longest

  // Debug zone --------------------------------------------------------------
  printf("Set of chars: \n");
  for (int i = 0; i <= stringAppendCounter; i++) {
    printf("%c ", (char)tempArr[i]);
  }

  printf("\n");

  printf("The current size: %d\n", stringAppendCounter);
  printf("The final size: %d\n", longest);

  return 0;
}
