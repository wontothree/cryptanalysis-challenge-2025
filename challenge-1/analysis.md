# Analysis

다음은 1번문제 소스코드를 분석한 파일이다.

```c
enum errorCode
{
    SUCCESS = 0,
    ERROR_AES_UNKNOWN_KEYSIZE,
    ERROR_MEMORY_ALLOCATION_FAILED,
};
```

- enum을 통하여 errorcode를 정의하였다.
    
# 갈루아 곱 연산
    
```c
uint8_t galois_multiplication(uint8_t a, uint8_t b)
{
    uint8_t p = 0;
    uint8_t counter;
    uint8_t hi_bit_set;
    for (counter = 0; counter < 8; counter++)
    {
        if ((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}
```

이 함수는 갈루아곱을 의미하는 것이다.
갈루아곱은 GF(p^n)으로 표시됨으로써는 p는 소수이고, n은 양의 정수임을 의미함.
필드의 요소 수는 p^n으로 지정되어 {1, 0, ..,p-1} 계수를 사용하여 n-1차 다항식으로 표시됨

갈루아곱에서 더하기는 XOR, 곱하기는 AND 연산이다.

(b & 1) == 1은 b의 최하위 비트가 1인지를 확인하는 것(LSB)으로써, 최하위 비트가 1이라면
a를 더해준다.
이후 hi_bit_set은 0x80 즉, 곱셈 시 최상위 비트가 넘어가는질 확인한다. 

갈루아곱의 역산은 확장 유클리드 알고리즘을 활용한다.
    

```c
/* Rijndael's key schedule rotate operation
 * rotate the word eight bits to the left
 *
 * rotate(1d2c3a4f) = 2c3a4f1d
 *
 * word is an int8_t array of size 4 (32 bit)
 */
void rotate(uint8_t *word)
{
    uint8_t c;
    int32_t i;

    c = word[0];
    for (i = 0; i < 3; i++)
        word[i] = word[i + 1];
    word[3] = c;
}
```

- 문자열을 8비트씩 이동하는 것