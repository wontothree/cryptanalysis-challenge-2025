#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <m4ri/m4ri.h>
#include <stdint.h>

// 상수 정의
#define KEY_SIZE 64
#define NONCE_SIZE 19
#define PLAINTEXT_BLOCK_SIZE 160
#define CIPHERTEXT_SIZE 458
#define NUM_BLOCKS 5

#ifdef __cplusplus
extern "C" {
#endif

// --- m4ri 기반 LFSR 상태 구조체 ---
typedef struct {
    mzd_t* R1; // 1 x 19
    mzd_t* R2; // 1 x 22
    mzd_t* R3; // 1 x 23
    mzd_t* R4; // 1 x 17
} lfsr_matrix_state_t;

// --- 함수 선언 ---

// 키스케줄: key_vec(1x64), nonce_vec(1x19) -> a_vec(1x64)
void key_scheduling_m4ri(const mzd_t* key_vec, const mzd_t* nonce_vec, mzd_t* a_vec);

// 비트 리버설: a_vec(1x64) -> aa_vec(1x64)
void bit_reversal_m4ri(const mzd_t* a_vec, mzd_t* aa_vec);

// LFSR 상태 초기화
void lfsr_matrix_initialization(lfsr_matrix_state_t* state);

// 키 인젝션
void key_injection_m4ri(const mzd_t* aa_vec, lfsr_matrix_state_t* state);

// 상태 확장
void expand_states_from_initial_m4ri(const lfsr_matrix_state_t* S0, int num, lfsr_matrix_state_t** S_states);

// keystream 생성
void keystream_generation_with_pattern_m4ri(const lfsr_matrix_state_t* state, const uint8_t* pattern, mzd_t* z_vec);

// 암호화 메인 함수
void encrypt(
    const int key[KEY_SIZE],
    const char* plaintext,
    int err1, int err2,
    int err1_bit, int err2_bit,
    int* ciphertext,
    const int* s,
    const int* Gt
);

// 보조 함수들
mzd_t* lfsr_companion_matrix(uint32_t fp, int len);
mzd_t* lfsr_companion_matrix_transposed(uint32_t fp, int len);
void lfsr_matrix_clock(mzd_t* lfsr, mzd_t* A);
int lfsr_matrix_get(const mzd_t* lfsr, int idx);
int majority_matrix(int a, int b, int c);

void encrypt_from_state_precise_m4ri(
    int R1_init, int R2_init, int R3_init, int R4_init,
    const char* plaintext, int err1, int err2, int err1_bit, int err2_bit, int* c_out,
    const int* s, const int* Gt, int* z_out
);

// m4ri 기반: my_encrypt와 동일한 시그니처의 암호화 함수
void encrypt_m4ri(const int key[KEY_SIZE], const char* plaintext, int err1, int err2, int err1_bit, int err2_bit, int* ciphertext, const int* s, const int* Gt);

void lfsr_enc_m4ri(const int K[KEY_SIZE], const int N[NONCE_SIZE], int z[CIPHERTEXT_SIZE]);

#ifdef __cplusplus
}
#endif

#endif // ENCRYPT_H 