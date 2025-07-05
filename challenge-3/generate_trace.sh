#!/bin/bash

# 평문(hex) 입력 받기
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <plaintext_hex>"
  exit 1
fi

PLAINTEXT=$1

# 경로들 정의 (절대 경로 사용)
BASE_DIR=$(pwd)
TRACE_DIR="${BASE_DIR}/test-cases"
TRACE_FILE="${TRACE_DIR}/_${PLAINTEXT}.trace"
TEXT_FILE="${TRACE_DIR}/_${PLAINTEXT}.txt"
MEM_READ_FILE="${TRACE_DIR}/_${PLAINTEXT}_mem_read_only.txt"
JSON_FILE="${TRACE_DIR}/_${PLAINTEXT}_serialized_mem_read_only.json"

# 1. Valgrind trace 생성
setarch `uname -m` -R valgrind \
  --tool=tracergrind \
  --output="$TRACE_FILE" \
  ./fixed_address_wbcaes128 "$PLAINTEXT"

# 2. texttrace로 변환
cd /workspace/challenge-3/Tracer/TracerGrind/texttrace || exit 1
./texttrace "$TRACE_FILE" "$TEXT_FILE"

# 3. 메모리 읽기만 추출
grep '^\[M\].*MODE: R' "$TEXT_FILE" > "$MEM_READ_FILE"

# 4. JSON 변환 (Python 파서 실행)
cd "$TRACE_DIR" || exit 1
python3 serialize.py "$(basename "$MEM_READ_FILE")" "$(basename "$JSON_FILE")"


echo "✅ 전체 처리 완료: $JSON_FILE"

# chmod +x generate_trace.sh
# ./generate_trace.sh 00112233445566778899aabbccddee01