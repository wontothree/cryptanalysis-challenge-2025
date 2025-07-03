# Cryptanalysis Challenge 2025

# Dependencies

```bash
gcc -o wbcaes128 ./wbcaes128.c
```

- TracerGrind는 Valgrind라는 도구 위에서 동작하는 프로그램
- Valgrind는 프로그램 실행 중에 메모리 접근, 버그, 성능 등을 검사하는 오픈소스 도구
- TracerGrind는 프로그램이 어느 메모리 주소를 언제 읽고 썼는지 추적(로그)하는 역할
- 메모리 접근 시퀀스를 자세히 기록해서 암호 알고리즘 같은 민감한 부분에서 어떤 주소에 어떤 데이터가 언제 쓰이고 읽혔는지 파악하기 위해서. 보통 화이트박스 암호 분석, 바이너리 분석에 쓰입니다.

## 3번

```bash
cd challenge-3

# Valgrind 3.15.0 공식 소스 압축 파일을 다운
# curl -O https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2

# 압축을 풀어서자동으로 valgrind-3.15.0 폴더가 생성
tar xf valgrind-3.15.0.tar.bz2

cd valgrind-3.15.0

# 소스에 패치가 적용
patch -p1 < ../Tracer/TracerGrind/valgrind-3.15.0.diff

# Valgrind + TracerGrind 빌드 및 설치
apt update
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
cd challenge-3
valgrind --tool=tracergrind --output=wbcaes128.trace ./wbcaes128
ls -lh wbcaes128.trace

# TracerGrind를 사용해 화이트박스 암호 바이너리 wbcaes128의 실행 과정을 추적하는 명령어
valgrind --tool=tracergrind --output=wbcaes128.trace ./wbcaes128 00112233445566778899aabbccddeeff

# .trace 파일 확인 및 파싱
less wbcaes128.trace

# texttrace 또는 sqlitetrace로 분석 변환
apt install -y libcapstone-dev

cd /workspace/challenge-3/Tracer/TracerGrind/texttrace
make
./texttrace ./../../wbcaes128.trace > ./../wbcaes128.txt

# cat ../../wbcaes128.txt
# 파일의 맨 앞 줄부터 40번째줄까지를 출력하는 command
head -40 /workspace/challenge-3/wbcaes128.txt
```

```bash
cd /TraceGraph
sudo apt-get install build-essential qt5-qmake qtbase5-dev-tools qtbase5-dev libsqlite3-dev
make
sudo make install

```

### M1

```bash
brew install qt@5 sqlite
export PATH="/opt/homebrew/opt/qt@5/bin:$PATH"
```

# Reference

https://github.com/SideChannelMarvels/Tracer/tree/master
