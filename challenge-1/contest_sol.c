// AES code from https://github.com/m3y54m/aes-in-c
// other code from contest manager!

// #pragma GCC optimize ("O3")

#include <stdio.h>  // for printf
#include <stdlib.h> // for malloc, free
#include <stdint.h> // for uint8_t
#include <time.h>   // for random seed
#include <inttypes.h>  // for PRId64 macro
#include <wmmintrin.h> // AES-NI, PCLMULQDQ
#include <emmintrin.h> // SSE2
#include <smmintrin.h> // SSE4.1
#include <immintrin.h> // AVX, AVX2 (통합)

enum errorCode
{
    SUCCESS = 0,
    ERROR_AES_UNKNOWN_KEYSIZE,
    ERROR_MEMORY_ALLOCATION_FAILED,
};

// Implementation: S-Box
uint8_t sbox[256] = {
    // 0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,  // 0
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,  // 1
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,  // 2
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,  // 3
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,  // 4
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,  // 5
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,  // 6
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,  // 7
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,  // 8
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,  // 9
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,  // A
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,  // B
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,  // C
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,  // D
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,  // E
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}; // F

uint8_t rsbox[256] =
    {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb, 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb, 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e, 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25, 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92, 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84, 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06, 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b, 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73, 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e, 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b, 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4, 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f, 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef, 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61, 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

uint8_t getSBoxValue(uint8_t num);
uint8_t getSBoxInvert(uint8_t num);

// Implementation: Rotate
void rotate(uint8_t *word);

// Implementation: Rcon
uint8_t Rcon[255] = {
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d,
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab,
    0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d,
    0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25,
    0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01,
    0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d,
    0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa,
    0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a,
    0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02,
    0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f,
    0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5,
    0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33,
    0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb};

uint8_t getRconValue(uint8_t num);

// Implementation: Key Schedule Core
void core(uint8_t *word, int32_t iteration);

// Implementation: Key Expansion
enum keySize
{
    SIZE_16 = 16,
    SIZE_24 = 24,
    SIZE_32 = 32
};

#define defined_expandedKeySize 176
#define AES_SIZE_64 2
#define BENCH_COUNT 5000

// aes encryption
void expandKey(uint8_t *expandedKey, uint8_t *key, enum keySize, size_t expandedKeySize);
void subBytes(uint8_t *state);
void shiftRows(uint8_t *state);
void shiftRow(uint8_t *state, uint8_t nbr);
void addRoundKey(uint8_t *state, uint8_t *roundKey);
uint8_t galois_multiplication(uint8_t a, uint8_t b);
void mixColumns(uint8_t *state);
void mixColumn(uint8_t *column);
void aes_round(uint8_t *state, uint8_t *roundKey);
void createRoundKey(uint8_t *expandedKey, uint8_t *roundKey);
void aes_main(uint8_t *state, uint8_t *expandedKey, int32_t nbrRounds);
int8_t aes_encrypt(uint8_t *input, uint8_t *output, uint8_t *key, enum keySize size);

// polynomial multiplication
void GF_mul(const uint64_t* a, const uint64_t* b, uint64_t* c);
void poly64_mul(uint64_t a, uint64_t b, uint64_t *c);

// rotation operation
void rotate_left_128(uint64_t* inout, int bits);


// optimize aes round
// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#ig_expand=236,222,234,234 참고하여 제작
void opt_aes_round(uint8_t *state_bytes, uint8_t *roundKey_bytes);
void aes_intr_main(uint8_t *state, uint8_t *expandedKey, int32_t nbrRounds);

void opt_aes_round(uint8_t *state_bytes, uint8_t *roundKey_bytes){

    __m128i state = _mm_loadu_si128((__m128i*)state);
    __m128i roundkey = _mm_loadu_si128((__m128i*)roundkey);
    state = _mm_aesenc_si128(state, roundkey);
    _mm_storeu_si128((__m128i*)state_bytes, state);
}

void aes_intr_main(uint8_t *state, uint8_t *expandedKey, int32_t nbrRounds){
    int32_t i = 0;

    uint8_t roundKey[16];

    createRoundKey(expandedKey, roundKey);
    addRoundKey(state, roundKey);

    for (i = 1; i < nbrRounds; i++)
    {
        createRoundKey(expandedKey + 16 * i, roundKey);
        opt_aes_round(state, roundKey);
    }

<<<<<<< HEAD
=======
    createRoundKey(expandedKey + 16 * nbrRounds, roundKey);

    // Intristics으로 처리하기
    __m128i s = _mm_loadu_si128((__m128i*)state);
    __m128i rk = _mm_loadu_si128((__m128i*)roundKey);
    s = _mm_aesenclast_si128(s, rk);
>>>>>>> parent of fea19f2 (함수 최적화하게 수정)
    _mm_storeu_si128((__m128i*)state, s);
}

uint8_t getSBoxValue(uint8_t num)
{
    return sbox[num];
}

uint8_t getSBoxInvert(uint8_t num)
{
    return rsbox[num];
}

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

uint8_t getRconValue(uint8_t num)
{
    return Rcon[num];
}



void core(uint8_t *word, int32_t iteration)
{
    int32_t i;

    // rotate the 32-bit word 8 bits to the left
    rotate(word);

    // apply S-Box substitution on all 4 parts of the 32-bit word
    for (i = 0; i < 4; ++i)
    {
        word[i] = getSBoxValue(word[i]);
    }

    // XOR the output of the rcon operation with i to the first part (leftmost) only
    word[0] = word[0] ^ getRconValue(iteration);
}

/* Rijndael's key expansion
 * expands an 128,192,256 key into an 176,208,240 bytes key
 *
 * expandedKey is a pointer to an int8_t array of large enough size
 * key is a pointer to a non-expanded key
 */

void expandKey(uint8_t *expandedKey,
               uint8_t *key,
               enum keySize size,
               size_t expandedKeySize)
{
    // current expanded keySize, in bytes
    int32_t currentSize = 0;
    int32_t rconIteration = 1;
    int32_t i;
    uint8_t t[4] = {0}; // temporary 4-byte variable

    // set the 16,24,32 bytes of the expanded key to the input key
    for (i = 0; i < size; i++)
        expandedKey[i] = key[i];
    currentSize += size;

    while (currentSize < expandedKeySize)
    {
        // assign the previous 4 bytes to the temporary value t
        for (i = 0; i < 4; i++)
        {
            t[i] = expandedKey[(currentSize - 4) + i];
        }

        /* every 16,24,32 bytes we apply the core schedule to t
         * and increment rconIteration afterwards
         */
        if (currentSize % size == 0)
        {
            core(t, rconIteration++);
        }

        // For 256-bit keys, we add an extra sbox to the calculation
        if (size == SIZE_32 && ((currentSize % size) == 16))
        {
            for (i = 0; i < 4; i++)
                t[i] = getSBoxValue(t[i]);
        }

        /* We XOR t with the four-byte block 16,24,32 bytes before the new expanded key.
         * This becomes the next four bytes in the expanded key.
         */
        for (i = 0; i < 4; i++)
        {
            expandedKey[currentSize] = expandedKey[currentSize - size] ^ t[i];
            currentSize++;
        }
    }
}

void subBytes(uint8_t *state)
{
    int32_t i;
    /* substitute all the values from the state with the value in the SBox
     * using the state value as index for the SBox
     */
    for (i = 0; i < 16; i++)
        state[i] = getSBoxValue(state[i]);
}

void shiftRows(uint8_t *state)
{
    int32_t i;
    // iterate over the 4 rows and call shiftRow() with that row
    for (i = 0; i < 4; i++)
        shiftRow(state + i * 4, i);
}

void shiftRow(uint8_t *state, uint8_t nbr)
{
    int32_t i, j;
    uint8_t tmp;
    // each iteration shifts the row to the left by 1
    for (i = 0; i < nbr; i++)
    {
        tmp = state[0];
        for (j = 0; j < 3; j++)
            state[j] = state[j + 1];
        state[3] = tmp;
    }
}

void addRoundKey(uint8_t *state, uint8_t *roundKey)
{
    int32_t i;
    for (i = 0; i < 16; i++)
        state[i] = state[i] ^ roundKey[i];
}

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

void mixColumns(uint8_t *state)
{
    int32_t i, j;
    uint8_t column[4];

    // iterate over the 4 columns
    for (i = 0; i < 4; i++)
    {
        // construct one column by iterating over the 4 rows
        for (j = 0; j < 4; j++)
        {
            column[j] = state[(j * 4) + i];
        }

        // apply the mixColumn on one column
        mixColumn(column);

        // put the values back into the state
        for (j = 0; j < 4; j++)
        {
            state[(j * 4) + i] = column[j];
        }
    }
}

void mixColumn(uint8_t *column)
{
    uint8_t cpy[4];
    int32_t i;
    for (i = 0; i < 4; i++)
    {
        cpy[i] = column[i];
    }
    column[0] = galois_multiplication(cpy[0], 2) ^
                galois_multiplication(cpy[3], 1) ^
                galois_multiplication(cpy[2], 1) ^
                galois_multiplication(cpy[1], 3);

    column[1] = galois_multiplication(cpy[1], 2) ^
                galois_multiplication(cpy[0], 1) ^
                galois_multiplication(cpy[3], 1) ^
                galois_multiplication(cpy[2], 3);

    column[2] = galois_multiplication(cpy[2], 2) ^
                galois_multiplication(cpy[1], 1) ^
                galois_multiplication(cpy[0], 1) ^
                galois_multiplication(cpy[3], 3);

    column[3] = galois_multiplication(cpy[3], 2) ^
                galois_multiplication(cpy[2], 1) ^
                galois_multiplication(cpy[1], 1) ^
                galois_multiplication(cpy[0], 3);
}

void aes_round(uint8_t *state, uint8_t *roundKey)
{
    subBytes(state);
    shiftRows(state);
    mixColumns(state);
    addRoundKey(state, roundKey);
}

void createRoundKey(uint8_t *expandedKey, uint8_t *roundKey)
{
    int32_t i, j;
    // iterate over the columns
    for (i = 0; i < 4; i++)
    {
        // iterate over the rows
        for (j = 0; j < 4; j++)
            roundKey[(i + (j * 4))] = expandedKey[(i * 4) + j];
    }
}

void aes_main(uint8_t *state, uint8_t *expandedKey, int32_t nbrRounds)
{
    int32_t i = 0;

    uint8_t roundKey[16];

    createRoundKey(expandedKey, roundKey);
    addRoundKey(state, roundKey);

    for (i = 1; i < nbrRounds; i++)
    {
        createRoundKey(expandedKey + 16 * i, roundKey);
        aes_round(state, roundKey);
    }

    createRoundKey(expandedKey + 16 * nbrRounds, roundKey);
    subBytes(state);
    shiftRows(state);
    addRoundKey(state, roundKey);
}

int8_t aes_encrypt(uint8_t *input,
                   uint8_t *output,
                   uint8_t *key,
                   enum keySize size)
{
    // the expanded keySize
    int32_t expandedKeySize;

    // the number of rounds
    int32_t nbrRounds;

    // the expanded key
    uint8_t *expandedKey;

    // the 128 bit block to encode
    uint8_t block[16];

    int32_t i, j;

    // set the number of rounds
    switch (size)
    {
    case SIZE_16:
        nbrRounds = 10;
        break;
    case SIZE_24:
        nbrRounds = 12;
        break;
    case SIZE_32:
        nbrRounds = 14;
        break;
    default:
        return ERROR_AES_UNKNOWN_KEYSIZE;
        break;
    }

    expandedKeySize = (16 * (nbrRounds + 1));

    expandedKey = (uint8_t *)malloc(expandedKeySize * sizeof(uint8_t));

    if (expandedKey == NULL)
    {
        return ERROR_MEMORY_ALLOCATION_FAILED;
    }
    else
    {
        /* Set the block values, for the block:
         * a0,0 a0,1 a0,2 a0,3
         * a1,0 a1,1 a1,2 a1,3
         * a2,0 a2,1 a2,2 a2,3
         * a3,0 a3,1 a3,2 a3,3
         * the mapping order is a0,0 a1,0 a2,0 a3,0 a0,1 a1,1 ... a2,3 a3,3
         */

        // iterate over the columns
        for (i = 0; i < 4; i++)
        {
            // iterate over the rows
            for (j = 0; j < 4; j++)
                block[(i + (j * 4))] = input[(i * 4) + j];
        }

        // expand the key into an 176, 208, 240 bytes key
        expandKey(expandedKey, key, size, expandedKeySize);

        // encrypt the block using the expandedKey
        aes_main(block, expandedKey, nbrRounds);

        // unmap the block again into the output
        for (i = 0; i < 4; i++)
        {
            // iterate over the rows
            for (j = 0; j < 4; j++)
                output[(i * 4) + j] = block[(i + (j * 4))];
        }

        // de-allocate memory for expandedKey
        free(expandedKey);
        expandedKey = NULL;
    }

    return SUCCESS;
}

void poly64_mul(uint64_t a, uint64_t b, uint64_t *c)
{   
    uint64_t table[16];
    uint64_t temp, mask, high, low;
    uint64_t top3 = a >> 61;

    table[0] = 0;
    table[1] = a & 0x1fffffffffffffffULL;
    table[2] = table[1] << 1;
    table[4] = table[2] << 1;
    table[8] = table[4] << 1;

    table[3] = table[1] ^ table[2];

    table[5] = table[1] ^ table[4];
    table[6] = table[2] ^ table[4];
    table[7] = table[1] ^ table[6];

    table[9] = table[1] ^ table[8];
    table[10] = table[2] ^ table[8];
    table[11] = table[3] ^ table[8];
    table[12] = table[4] ^ table[8];
    table[13] = table[5] ^ table[8];
    table[14] = table[6] ^ table[8];
    table[15] = table[7] ^ table[8];

    low = table[b & 0xf];
    temp = table[(b >> 4) & 0xf];
    low ^= temp << 4;
    high = temp >> 60;
    temp = table[(b >> 8) & 0xf];
    low ^= temp << 8;
    high ^= temp >> 56;
    temp = table[(b >> 12) & 0xf];
    low ^= temp << 12;
    high ^= temp >> 52;
    temp = table[(b >> 16) & 0xf];
    low ^= temp << 16;
    high ^= temp >> 48;
    temp = table[(b >> 20) & 0xf];
    low ^= temp << 20;
    high ^= temp >> 44;
    temp = table[(b >> 24) & 0xf];
    low ^= temp << 24;
    high ^= temp >> 40;
    temp = table[(b >> 28) & 0xf];
    low ^= temp << 28;
    high ^= temp >> 36;
    temp = table[(b >> 32) & 0xf];
    low ^= temp << 32;
    high ^= temp >> 32;
    temp = table[(b >> 36) & 0xf];
    low ^= temp << 36;
    high ^= temp >> 28;
    temp = table[(b >> 40) & 0xf];
    low ^= temp << 40;
    high ^= temp >> 24;
    temp = table[(b >> 44) & 0xf];
    low ^= temp << 44;
    high ^= temp >> 20;
    temp = table[(b >> 48) & 0xf];
    low ^= temp << 48;
    high ^= temp >> 16;
    temp = table[(b >> 52) & 0xf];
    low ^= temp << 52;
    high ^= temp >> 12;
    temp = table[(b >> 56) & 0xf];
    low ^= temp << 56;
    high ^= temp >> 8;
    temp = table[b >> 60];
    low ^= temp << 60;
    high ^= temp >> 4;

    mask = -(int64_t)(top3 & 0x1);
    low ^= mask & (b << 61);
    high ^= mask & (b >> 3);
    mask = -(int64_t)((top3 >> 1) & 0x1);
    low ^= mask & (b << 62);
    high ^= mask & (b >> 2);
    mask = -(int64_t)((top3 >> 2) & 0x1);
    low ^= mask & (b << 63);
    high ^= mask & (b >> 1);

    c[0] = low;
    c[1] = high;
     
}

void GF_mul(const uint64_t* a, const uint64_t* b, uint64_t* c)
{
  uint64_t t[2] = {0,};
  uint64_t temp[8] = {0,};

  poly64_mul(a[0], b[0], &temp[0]);
  poly64_mul(a[1], b[1], &temp[2]);  
  poly64_mul(a[0], b[1], &temp[4]);
  poly64_mul(a[1], b[0], &temp[6]);

    c[0] = temp[0];
    c[1] = temp[1] ^ temp[4] ^ temp[6];
    c[2] = temp[2] ^ temp[5] ^ temp[7];
    c[3] = temp[3];

}

void rotate_left_128(uint64_t* inout, int bits) {
    if (bits >= 64) {
        uint64_t temp = inout[1];
        inout[1] = (inout[0] << (bits - 64)) | (temp >> (128 - bits));
        inout[0] = (temp << (bits - 64)) | (inout[0] >> (128 - bits));
    } else {
        uint64_t temp_high = inout[1];
        inout[1] = (inout[1] << bits) | (inout[0] >> (64 - bits));
        inout[0]  = (inout[0] << bits) | (temp_high >> (64 - bits));
    }
}

int64_t cpucycles(void)
{
	uint32_t hi, lo;

    	__asm__ __volatile__ ("rdtsc\n\t" : "=a" (lo), "=d"(hi));

    	return ((int64_t)lo) | (((int64_t)hi) << 32);
}


void new_keyed_hash(const uint64_t* input, uint64_t* key, uint64_t* output){
    uint64_t first_temp[8] = {0,};
    uint64_t second_temp[8] = {0,};

    aes_encrypt((uint8_t*)&input[0], (uint8_t*)&first_temp[0], (uint8_t*)key, SIZE_16);
    aes_encrypt((uint8_t*)&input[2], (uint8_t*)&first_temp[2], (uint8_t*)key, SIZE_16);
    aes_encrypt((uint8_t*)&input[4], (uint8_t*)&first_temp[4], (uint8_t*)key, SIZE_16);
    aes_encrypt((uint8_t*)&input[6], (uint8_t*)&first_temp[6], (uint8_t*)key, SIZE_16);

    rotate_left_128(&first_temp[0], 8);  
    rotate_left_128(&first_temp[2], 16);
    rotate_left_128(&first_temp[4], 24);
    rotate_left_128(&first_temp[6], 32);


    GF_mul(&first_temp[0],&first_temp[2],&second_temp[0]);
    GF_mul(&first_temp[4],&first_temp[6],&second_temp[4]);

    for(int i=0; i<4; i++){
        output[i] = second_temp[i] ^ second_temp[i+4];
    }

}

void compare_two_hash(uint64_t* hash1, uint64_t* hash2){
    for(int i=0; i<4; i++){
        if(hash1[i] != hash2[i]){
            printf("wrong result!\n");  
            return;
        }
    }
    printf("correct result!\n");
    return;
}

int32_t main(int32_t argc, int8_t *argv[])
{

    int64_t start, end, cycles;

    uint64_t test1_plaintext_input[AES_SIZE_64*4]=  {0x2C95BE227436F55C, 0x3934846C46377D53, 0x6627817850433865, 0x3E3EEADB7F545B4B, 0x6B5C9437034BD64F, 0x05AC8F4E215CDC71, 0x35EE330344C84AF5, 0x74A31565301EED6B};
    uint64_t test1_key_input[2] =                   {0x592E744D6716A18A, 0x6952DFC81D2C6487};
    uint64_t test1_hash_output[4] =                 {0xf2a1e205e9cf89a4, 0x7d54c37ceeace92f, 0x13941ffaf64a8f5a, 0x55a65473aacbf41c};
    uint64_t hash_output[4] = {0,};
    
    new_keyed_hash(test1_plaintext_input, test1_key_input, hash_output);
    compare_two_hash(hash_output, test1_hash_output);

    uint64_t test2_plaintext_input[AES_SIZE_64*4]=  {0x697DA91259518212, 0x39E7FC275A91A002, 0x62F96ACD1915468F, 0x6EAACA112BBDE85A, 0x63A3D6517334C6FD, 0x3E67CF567018581C, 0x368B535C74D2A5F3, 0x526ADB695FCE51BB};
    uint64_t test2_key_input[2] =                   {0x7D36440674756AD5, 0x0E4C0ACF339B644C};
    uint64_t test2_hash_output[4] =                 {0x5d96d157c67ca6c1, 0xfb5e89aa7bf84b59, 0x5dac336c4d3fe780, 0x068d8a8b98872aa9};

    new_keyed_hash(test2_plaintext_input, test2_key_input, hash_output);
    compare_two_hash(hash_output, test2_hash_output);

    uint64_t test3_plaintext_input[AES_SIZE_64*4]=  {0x1AFBDFD108FA59A6, 0x626DF9573A5830F5, 0x2E8F162C66C9428F, 0x3BD713004456009C, 0x6A0E14AA2BD19C66, 0x21D051B253693C30, 0x6A9B08F21454E362, 0x7A6BD57B381A2B6F};
    uint64_t test3_key_input[2] =                   {0x632CB19B69390962, 0x2DF2E23F25B21436};
    uint64_t test3_hash_output[4] =                 {0x933ef1ad925db3d8, 0x9e0ccf9ca7220e66, 0x70bc273f42343f10, 0x38fa554c85dbabf8};

    start = cpucycles();
    for(int i=0;i<BENCH_COUNT;i++){
        new_keyed_hash(test3_plaintext_input, test3_key_input, hash_output);
        for(int j=0;j<4;j++){
            test3_plaintext_input[j] = test3_plaintext_input[j] ^ hash_output[j];
            test3_plaintext_input[j+4] = test3_plaintext_input[j+4] ^ hash_output[j];
        }
    }
    end = cpucycles();
    cycles = end - start;
       
    compare_two_hash(hash_output, test3_hash_output);
    printf("CPU cycles used: %" PRId64 "\n", cycles);

    return 0;
}