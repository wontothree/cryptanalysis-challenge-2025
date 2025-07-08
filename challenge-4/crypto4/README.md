# Crypto4: Cryptographic Analysis Library

A reusable C library for cryptographic analysis and LFSR-based stream cipher, using the M4RI library for efficient matrix operations over GF(2).

## Project Structure

```
crypto4/
├── include/         # Library header files
├── source/          # Library source files
├── lib/             # Built static libraries
├── bin/             # Compiled executables
├── data/            # (Download data files, see below)
├── examples/        # Example usage code
├── tools/           # Utility tools
├── Makefile
└── README.md
```

## Data Files

대용량 바이너리/데이터 파일은 Git에서 추적하지 않습니다. 아래 Google Drive 링크에서 다운로드하여 `data/` 폴더에 직접 넣어주세요:

**[Download data files (Google Drive)](https://drive.google.com/drive/folders/1liUMwRpyAcMHEVUwi5Ss53gn_1I4D6cg?usp=sharing)**

예시 파일:
- r4_clock_patterns.bin
- ciphertext.bin
- Gt.bin
- s.bin

## Build Instructions

### Prerequisites
- GCC
- M4RI library
- Make

### Build Commands
```bash
# Build all (libraries + examples)
make

# Clean build artifacts
make clean
```

빌드 결과물은 `bin/` (실행파일)과 `lib/` (라이브러리) 폴더에 생성됩니다.

## Usage Example

### Basic Matrix Operations
```c
#include "crypto_lib.h"
// ... matrix creation, multiplication, etc.
```

### LFSR Stream Cipher
```c
#include "encrypt.h"
// ... encryption, keystream generation, etc.
```

### Example Program
예제 코드는 `examples/` 폴더를 참고하세요.

## Extending the Library
- 새 함수는 `include/`와 `source/`에 추가
- Makefile에 필요시 빌드 규칙 추가

## License
This project is for educational and research purposes in cryptographic analysis. 