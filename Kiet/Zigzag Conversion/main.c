#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
  const int inputLenght = strlen(s);
  // Allocate for function return
  char *result = malloc((inputLenght + 1) * sizeof(char));
  int resultIdx = 0;

  // Finding the top anchor points (top row character index)
  int anchorPoints[inputLenght / 2];
  int anchorPointsIdx = 0;
  for (int i = 0; i < inputLenght; i += (numRows - 1) * 2) {
    anchorPoints[anchorPointsIdx] = i;
    anchorPointsIdx++;
  }
  int nonExistAnchor = anchorPoints[anchorPointsIdx - 1] + 2 * (numRows - 1);

  // Populate the result
  for (int i = 0; i < numRows; i++) {
    // Idx now is the same as number of elements
    // Check for the non existance anchor point in middle rows
    int maxJ =
        (i > 0 && i < numRows - 1) ? anchorPointsIdx + 1 : anchorPointsIdx;
    for (int j = 0; j < maxJ; j++) {
      int anchor = (j < anchorPointsIdx) ? anchorPoints[j] : nonExistAnchor;
      // First row
      if (i == 0) {
        result[resultIdx++] = s[anchor];
        // Last row
      } else if (i == numRows - 1) {
        if (anchor + i < inputLenght) {
          result[resultIdx++] = s[anchor + i];
        }
        // Other rows
      } else {
        // Check if the anchor point is at the start
        if (anchor > inputLenght - 1) {
          if (anchor - i < inputLenght)
            result[resultIdx++] = s[anchor - i];
        } else if (anchor == 0)
          result[resultIdx++] = s[anchor + i];
        // Check if the anchor point is at the end of input string
        else if (anchor == inputLenght - 1)
          result[resultIdx++] = s[anchor - i];
        // Check if the anchor point is non existed and its corresponding
        // character
        else {
          result[resultIdx++] = s[anchor - i];
          // Bound checking
          if (anchor + i < inputLenght) {
            result[resultIdx++] = s[anchor + i];
          }
        }
      }
    }
  }

  result[inputLenght] = '\0';
  return result;
}

int main(int argc, char *argv[]) {
  char *input = "PAYPALISHIRING";
  const int inputLenght = strlen(input);
  char *result;

  result = convert(input, 5);
  printf("Size of result: %ld\n", strlen(result));
  printf("Result: %s", result);

  return 0;
}
