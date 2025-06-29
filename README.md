# Cryptanalysis Challenge 2025

# Dependencies

```bash
gcc -o wbcaes128 ./wbcaes128.c
```

- TracerGrind는 Valgrind라는 도구 위에서 동작하는 프로그램
- Valgrind는 프로그램 실행 중에 메모리 접근, 버그, 성능 등을 검사하는 오픈소스 도구
- TracerGrind는 프로그램이 어느 메모리 주소를 언제 읽고 썼는지 추적(로그)하는 역할
- 메모리 접근 시퀀스를 자세히 기록해서 암호 알고리즘 같은 민감한 부분에서 어떤 주소에 어떤 데이터가 언제 쓰이고 읽혔는지 파악하기 위해서. 보통 화이트박스 암호 분석, 바이너리 분석에 쓰입니다.

```bash
cd challenge-3

# 먼저 Valgrind 3.15.0 공식 소스 압축 파일을 다운받고
curl -O https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2

# 압축을 풀면 자동으로 valgrind-3.15.0 폴더가 생성
tar xf valgrind-3.15.0.tar.bz2

cd valgrind-3.15.0

# 소스에 패치가 적용
patch -p1 < ../Tracer/TracerGrind/valgrind-3.15.0.diff

# Valgrind + TracerGrind 빌드 및 설치
apt install -y autoconf automake libtool pkg-config

cp -r ../Tracer/TracerGrind/tracergrind ./
ls tracergrind

./autogen.sh
./configure --prefix=/usr
make -j$(nproc)
sudo make install

apt install -y locales
locale-gen en_US.UTF-8
update-locale LANG=en_US.UTF-8
export LANG=en_US.UTF-8
```

```bash
valgrind --tool=tracergrind --output=wbcaes128.trace ./wbcaes128
ls -lh wbcaes128.trace

# TracerGrind를 사용해 화이트박스 암호 바이너리 wbcaes128의 실행 과정을 추적하는 명령어
valgrind --tool=tracergrind --output=wbcaes128.trace ./wbcaes128 00112233445566778899aabbccddeeff

# .trace 파일 확인 및 파싱
less wbcaes128.trace

# texttrace 또는 sqlitetrace로 분석 변환
cd /workspace/challenge-3/Tracer/TracerGrind/texttrace
make
./texttrace ./../../wbcaes128.trace > ./../wbcaes128.txt

cat ../../wbcaes128.txt

# 이건 TracerGrind가 생성한 trace 파일 wbcaes128.trace를 texttrace로 사람이 읽을 수 있는 텍스트 형태로 변환한 결과 일부입니다.
head -40 /workspace/challenge-3/wbcaes128.txt
```

```
root@7cfb39f0bf08:/workspace/challenge-3/Tracer/TracerGrind/texttrace# head -40 /workspace/challenge-3/wbcaes128.txt
[!] TRACERGRIND_VERSION: 1.4
[!] ARCH: AMD64
[!] PROGRAM: ./wbcaes128
[!] ARGS: 00112233445566778899aabbccddeeff
[T] EXEC_ID: 0 THREAD_ID: 0000000000000001 TYPE: THREAD_CREATE
[M] EXEC_ID: 0 INS_ADDRESS: 0000000004020293 START_ADDRESS: 0000001fff0000d8 LENGTH: 8 MODE: W DATA: 9802020400000000
[B] EXEC_ID: 0 THREAD_ID: 0000000000000001 START_ADDRESS: 0000000004020290 END_ADDRESS: 0000000004020293
[I] 0000000004020290: mov rdi, rsp
[I] 0000000004020293: call 0x4021030
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021034 START_ADDRESS: 0000001fff0000d0 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021038 START_ADDRESS: 0000001fff0000c8 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 000000000402103a START_ADDRESS: 0000001fff0000c0 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 000000000402103c START_ADDRESS: 0000001fff0000b8 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 000000000402103e START_ADDRESS: 0000001fff0000b0 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021040 START_ADDRESS: 0000001fff0000a8 LENGTH: 8 MODE: W DATA: 0000000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021048 START_ADDRESS: 0000001fff000058 LENGTH: 8 MODE: W DATA: e00000ff1f000000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021055 START_ADDRESS: 000000000403ae0e LENGTH: 1 MODE: R DATA: 00
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021055 START_ADDRESS: 000000000403ae0e LENGTH: 1 MODE: W DATA: 00
[M] EXEC_ID: 1 INS_ADDRESS: 000000000402105c START_ADDRESS: 000000000403aaf0 LENGTH: 8 MODE: W DATA: 0000000400000000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021071 START_ADDRESS: 0000000004039aa0 LENGTH: 8 MODE: W DATA: 6e19a0b8b10a0000
[M] EXEC_ID: 1 INS_ADDRESS: 0000000004021078 START_ADDRESS: 0000000004039e80 LENGTH: 8 MODE: R DATA: 0e00000000000000
[M] EXEC_ID: 1 INS_ADDRESS: 000000000402107f START_ADDRESS: 000000000403ab00 LENGTH: 8 MODE: W DATA: 809e030400000000
[B] EXEC_ID: 1 THREAD_ID: 0000000000000001 START_ADDRESS: 0000000004021030 END_ADDRESS: 00000000040210be
[I] 0000000004021030: endbr64 
[I] 0000000004021034: push rbp
[I] 0000000004021035: mov rbp, rsp
[I] 0000000004021038: push r15
[I] 000000000402103a: push r14
[I] 000000000402103c: push r13
[I] 000000000402103e: push r12
[I] 0000000004021040: push rbx
[I] 0000000004021041: sub rsp, 0x88
[I] 0000000004021048: mov qword ptr [rbp - 0x78], rdi
[I] 000000000402104c: rdtsc 
[I] 000000000402104e: lea r12, [rip - 0x21055]
[I] 0000000004021055: and byte ptr [rip + 0x19db2], 0xdf
[I] 000000000402105c: mov qword ptr [rip + 0x19a8d], r12
[I] 0000000004021063: shl rdx, 0x20
[I] 0000000004021067: or rax, rdx
[I] 000000000402106a: lea rdx, [rip + 0x18e0f]
```

# Reference

https://github.com/SideChannelMarvels/Tracer/tree/master
