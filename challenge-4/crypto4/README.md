# Crypto4 - Cryptographic Analysis Library

A reusable C library for cryptographic analysis using the M4RI library for efficient matrix operations over GF(2), plus an LFSR-based stream cipher implementation.

## Project Structure

```
crypto4/
├── include/
│   ├── crypto_lib.h          # Main library header
│   └── lfsr_crypto.h         # LFSR crypto header
├── source/
│   ├── crypto_lib.c          # Library implementation
│   └── lfsr_crypto.c         # LFSR crypto implementation
├── lib/
│   ├── libcrypto.a           # Static library
│   └── liblfsr.a            # LFSR crypto library
├── examples/
│   ├── basic_usage.c         # Usage examples
│   └── lfsr_example.c        # LFSR crypto example
├── data/                     # Matrix data files
│   ├── matrix_A.txt
│   ├── matrix_B.txt
│   ├── large_matrix.txt
│   ├── result_matrix.txt
│   └── linear_systems.arc
├── bin/
│   ├── basic_usage.exe       # Example executable
│   └── lfsr_example.exe      # LFSR crypto executable
└── Makefile
```

## Features

### Core Matrix Operations
- Matrix creation and management
- Binary matrix operations (GF(2))
- Matrix multiplication, addition, transpose
- Rank calculation and invertibility checking

### Cryptographic Analysis
- Linear cryptanalysis for S-boxes
- Linear Approximation Table (LAT) generation
- S-box comprehensive analysis
- Performance monitoring

### LFSR Stream Cipher
- 4-LFSR based stream cipher implementation
- Majority function based keystream generation
- Error correction code integration
- Binary file output support

### File I/O
- Text file matrix loading/saving
- Archive file support for large datasets
- Error handling and validation

## Building

### Prerequisites
- GCC compiler
- M4RI library
- Make

### Build Commands
```bash
# Build everything (libraries + examples)
make

# Build only the crypto library
make lib/libcrypto.a

# Build only the LFSR library
make lib/liblfsr.a

# Build and run crypto example
make run

# Build and run LFSR example
make run-lfsr

# Clean build artifacts
make clean
```

## Usage

### Basic Matrix Operations
```c
#include "crypto_lib.h"

// Create matrices
crypto_matrix_t* A = crypto_matrix_init(4, 4, "Matrix A");
crypto_matrix_t* B = crypto_matrix_init(4, 4, "Matrix B");

// Matrix operations
crypto_matrix_t* C = crypto_matrix_multiply(A, B);
crypto_matrix_t* D = crypto_matrix_add(A, B);

// Get statistics
matrix_stats_t stats = crypto_matrix_get_stats(A);

// Clean up
crypto_matrix_free(A);
crypto_matrix_free(B);
crypto_matrix_free(C);
crypto_matrix_free(D);
```

### LFSR Stream Cipher
```c
#include "lfsr_crypto.h"

// Initialize crypto parameters
crypto_params_t params;
crypto_params_init(&params);

// Set up parameters
params.plaintext = "Hello, LFSR Crypto!";
params.num = 1;  // Number of blocks

// Initialize key (would be secret in real usage)
for (int i = 0; i < KEY_SIZE; i++) {
    params.K[i] = i % 2;
}

// Allocate memory for results
KeystreamArray* ciphertext = malloc(params.num * sizeof(KeystreamArray));
KeystreamArray* keystream = malloc(params.num * sizeof(KeystreamArray));

// Perform encryption
perform_encryption(&params, ciphertext, keystream);

// Save ciphertext
save_ciphertext(ciphertext, params.num, "ciphertext.bin");

// Clean up
free(ciphertext);
free(keystream);
crypto_params_free(&params);
```

### S-box Analysis
```c
// Define S-box
int sbox[16] = {0xE, 0x4, 0xD, 0x1, 0x2, 0xF, 0xB, 0x8, 
                0x3, 0xA, 0x6, 0xC, 0x5, 0x9, 0x0, 0x7};

// Perform analysis
sbox_analysis_t* analysis = crypto_sbox_analysis(sbox, 4, 4);

// Access results
printf("Max bias: %.4f\n", analysis->lat->max_bias);
printf("Max bias input mask: 0x%X\n", analysis->lat->max_input_mask);
printf("Max bias output mask: 0x%X\n", analysis->lat->max_output_mask);

// Clean up
crypto_sbox_analysis_free(analysis);
```

### File Operations
```c
// Load matrix from file
crypto_matrix_t* matrix = crypto_matrix_load_text("data/matrix.txt");

// Save matrix to file
crypto_matrix_save_text(matrix, "data/output.txt");

// Load from archive
crypto_matrix_t* archived = crypto_matrix_load_archive("data/archive.arc", 0);
```

### Performance Monitoring
```c
// Start monitoring
crypto_performance_start();

// ... perform operations ...

// Get results
crypto_performance_t perf = crypto_performance_end();
crypto_performance_print(&perf);
```

## Error Handling

```c
// Set custom error handler
void my_error_handler(crypto_error_t error, const char* message) {
    fprintf(stderr, "Crypto Error: %s\n", message);
}

crypto_set_error_handler(my_error_handler);
```

## Extending the Library

### Adding New Analysis Functions
1. Add function declarations to `include/crypto_lib.h`
2. Implement functions in `source/crypto_lib.c`
3. Update the library by rebuilding

### Adding New File Formats
1. Implement load/save functions
2. Add to the library interface
3. Update documentation

## Example Output

Running the example program:
```
=== Crypto Library Usage Example ===

1. Matrix Operations:
Matrix: Matrix A (4x4)
ID: -1, Binary: Yes
Data:
  0 1 0 1
  1 0 1 0
  0 1 0 1
  1 0 1 0

Matrix A Statistics:
  Size: 4x4
  Rank: 2
  Invertible: No
  Density: 50.00%
  Hamming Weight: 8

2. S-box Analysis:
S-box Analysis Results:
  Input Size: 4 bits
  Output Size: 4 bits
  Max Linear Bias: 0.2500
  Max Bias Input Mask: 0x3
  Max Bias Output Mask: 0x1

4. Performance Results:
Performance Results:
  CPU Time: 0.001 seconds
  Memory Used: 1024 bytes
  Operations Count: 5
```

## License

This project is for educational and research purposes in cryptographic analysis. 