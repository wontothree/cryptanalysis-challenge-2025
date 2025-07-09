# Crypto4: Cryptographic Analysis Library

A reusable C library for cryptographic analysis and LFSR-based stream cipher, using the M4RI library for efficient matrix operations over GF(2).

## Project Structure

```
crypto4/
├── include/         # Library header files
│   ├── crypto_lib.h
│   └── encrypt.h
├── source/          # Library source files
│   ├── crypto_lib.c
│   ├── encrypt.c
│   ├── debug_init.c
│   └── verify_r4_clock_pattern_bin.c
├── tools/           # Utility tools
│   ├── gen_zS_bin.c
│   ├── gen_s_gt_bin.c
│   └── gen_s_gt_bin_no_header.c
├── bin/             # Compiled executables
├── data/            # Data files (see below)
├── examples/        # Example usage code
├── Makefile
└── README.md
```

## Core Components

### Library Files
- **crypto_lib.c/h**: Core matrix operations and cryptographic utilities
- **encrypt.c/h**: LFSR-based stream cipher implementation with M4RI optimization

### Tools
- **gen_zS_bin.c**: Generate zS binary data for linearized state expansion
- **gen_s_gt_bin.c**: Generate S and Gt binary data files
- **gen_s_gt_bin_no_header.c**: Generate S and Gt data without headers

### Utilities
- **debug_init.c**: Debug initialization functions
- **verify_r4_clock_pattern_bin.c**: Verify R4 clock pattern binary files

## Data Files

대용량 바이너리/데이터 파일은 Git에서 추적하지 않습니다. 아래 Google Drive 링크에서 다운로드하여 `data/` 폴더에 직접 넣어주세요:

**[Download data files (Google Drive)](https://drive.google.com/drive/folders/1liUMwRpyAcMHEVUwi5Ss53gn_1I4D6cg?usp=sharing)**

필요한 파일들:
- `zS.bin`: Linearized state expansion data
- `r4_clock_patterns.bin`: R4 clock patterns
- `ciphertext.bin`: Ciphertext data
- `Gt.bin`: Gt matrix data
- `s.bin`: S vector data

## Build Instructions

### Prerequisites
- GCC (MinGW64)
- M4RI library
- Make

### Build Commands
```bash
# Build all (core library + tools)
make

# Build specific components
make core_library    # Build core library only
make tools           # Build utility tools
make debug_init      # Build debug initialization tool
make verify_r4       # Build R4 verification tool

# Clean build artifacts
make clean
```

빌드 결과물은 `bin/` 폴더에 생성됩니다.

## Key Features

### Matrix Operations
- Efficient GF(2) matrix operations using M4RI
- LFSR companion matrix generation and caching
- Linearized state expansion with precomputed zS data

### LFSR Stream Cipher
- 4 LFSR registers (R1:19, R2:22, R3:23, R4:17 bits)
- Matrix-based clock operations
- Keystream generation with pattern-based clocking
- Linearized state expansion for performance

### Performance Optimizations
- Global caching of companion matrices
- Precomputed zS data for linear expansion
- M4RI matrix operations for efficiency
- Vectorized operations where possible

## Usage Example

### Basic Matrix Operations
```c
#include "crypto_lib.h"

// Initialize matrices
crypto_matrix_t* A = crypto_matrix_init(4, 4, "Matrix A");
crypto_matrix_t* B = crypto_matrix_init(4, 4, "Matrix B");

// Matrix operations
crypto_matrix_t* C = crypto_matrix_multiply(A, B);
crypto_matrix_t* D = crypto_matrix_add(A, B);
```

### LFSR Stream Cipher
```c
#include "encrypt.h"

// Initialize LFSR matrices
lfsr_matrices_init();

// Create and initialize state
lfsr_matrix_state_t state;
lfsr_matrix_initialization(&state);

// Generate keystream
mzd_t* keystream = mzd_init(1, CIPHERTEXT_SIZE);
keystream_generation_with_pattern_m4ri(&state, pattern, keystream);
```

## Extending the Library

### Adding New Functions
- 새 함수는 `include/`와 `source/`에 추가
- Makefile에 필요시 빌드 규칙 추가
- M4RI 스타일의 행렬 연산 활용

### Performance Considerations
- Global caching 활용 (companion matrices, zS data)
- M4RI의 벡터화된 연산 사용
- 메모리 효율성 고려

## License
This project is for educational and research purposes in cryptographic analysis. 