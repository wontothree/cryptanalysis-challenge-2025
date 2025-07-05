// gcc -o testShiftRows ./testShiftRows.c  
// ./testShiftRows  

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

void ShiftRows(uint8_t state[16])
{
  const int shifts[16] = {
     0,  5, 10, 15,
     4,  9, 14,  3,
     8, 13,  2,  7,
    12,  1,  6, 11,
  };

  const uint8_t in[16] = {
    state[ 0], state[ 1], state[ 2], state[ 3],
    state[ 4], state[ 5], state[ 6], state[ 7],
    state[ 8], state[ 9], state[10], state[11],
    state[12], state[13], state[14], state[15],
  };

  for (int i = 0; i < 16; i++)
    state[i] = in[shifts[i]];
}

// 16진수 두 글자 → uint8_t 변환 함수
uint8_t hexToByte(char high, char low)
{
    uint8_t value = 0;

    if (high >= '0' && high <= '9') value += (high - '0') << 4;
    else if (tolower(high) >= 'a' && tolower(high) <= 'f') value += (tolower(high) - 'a' + 10) << 4;

    if (low >= '0' && low <= '9') value += (low - '0');
    else if (tolower(low) >= 'a' && tolower(low) <= 'f') value += (tolower(low) - 'a' + 10);

    return value;
}

int main(void) {
    char input[33];
    uint8_t state[16];

    printf("16바이트 16진수 입력 (32자리): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("입력 오류\n");
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';

    if (strlen(input) != 32) {
        printf("입력 길이가 32자가 아닙니다.\n");
        return 1;
    }

    for (int i = 0; i < 16; i++) {
        state[i] = hexToByte(input[i*2], input[i*2 + 1]);
    }

    ShiftRows(state);

    printf("ShiftRows 결과: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", state[i]);
    }
    printf("\n");

    return 0;
}
