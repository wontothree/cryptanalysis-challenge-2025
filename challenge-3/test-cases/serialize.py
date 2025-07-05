import json
import re
import sys

def hex_to_bit_string(hex_str, byte_length):
    """16진수 문자열을 비트 문자열로 변환 (문자열 형태 직렬화)"""
    bin_str = bin(int(hex_str, 16))[2:].zfill(byte_length * 8)
    return bin_str  # 문자열 그대로 반환

def parse_trace_file(input_path, output_path):
    result = []

    with open(input_path, 'r') as f:
        for line in f:
            if not line.startswith('[M]') or 'MODE: R' not in line:
                continue

            # 정규식으로 정보 추출
            exec_id = re.search(r'EXEC_ID:\s*(\d+)', line)
            ins_addr = re.search(r'INS_ADDRESS:\s*([0-9a-fA-F]+)', line)
            start_addr = re.search(r'START_ADDRESS:\s*([0-9a-fA-F]+)', line)
            length = re.search(r'LENGTH:\s*(\d+)', line)
            data = re.search(r'DATA:\s*([0-9a-fA-F]+)', line)

            if all([exec_id, ins_addr, start_addr, length, data]):
                item = {
                    "exec_id": int(exec_id.group(1)),
                    "ins_address": "0x" + ins_addr.group(1),
                    "start_address": "0x" + start_addr.group(1),
                    "length": int(length.group(1)),
                    "data_hex": data.group(1),
                    "data_serialized_bits": hex_to_bit_string(data.group(1), int(length.group(1)))
                }
                result.append(item)

    with open(output_path, 'w') as out_file:
        json.dump(result, out_file, indent=2)

    print(f"[+] {len(result)} entries saved to {output_path}")

# 실행 예시
if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 serialize.py <input_file> <output_file>")
        sys.exit(1)

    input_path = sys.argv[1]
    output_path = sys.argv[2]

    parse_trace_file(input_path, output_path)
