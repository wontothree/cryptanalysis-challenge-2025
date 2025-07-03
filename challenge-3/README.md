# Problem 3

화이트박스 암호는 공격자가 소프트웨어의 내부를 완전히 분석할 수 있는 화이트박스 모델 공격자 환경에서 암호 알고리즘 키를 포함한 내부 정보를 보호하면서 암호 연산을 수행할 수 있도록 설계한 암호입니다.

주어진 소스파일(`wbcases128.c`)은 Chow et al.의 White-box cryptograph and an AES implementation 논문 방식으로 AES-128 암호화를 외부 인코딩 없이 구현한 버전입니다. 즉, 일반 AES-128 암호화와 동일하게 동작합니다. 이를 분석하여 128비트 마스터키를 찾아내고, 그 분석 논리 및 과정을 상세히 문서화하시오.

# Getting Started

```bash
# generate wbcaes128 (binary file)
gcc -o wbcaes128 ./wbcaes128.c

# generate db
cd /workspace/challenge-3/Tracer/TracerGrind/sqlitetrace
make
cd /workspace/challenge-3
sqlitetrace wbcaes128.trace wbcaes128.db
```

# Dependencies

```bash
cd challenge-3

# curl -O https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2 # Valgrind 3.15.0 공식 소스 압축 파일을 다운

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

## TraceGraph on Mac M1

```bash
brew install qt@5 sqlite
export PATH="/opt/homebrew/opt/qt@5/bin:$PATH"
```

```bash
cd ~/TraceGraph
make
file tracegraph.app/Contents/MacOS/tracegraph # tracegraph.app/Contents/MacOS/tracegraph: Mach-O 64-bit executable arm64
./tracegraph.app/Contents/MacOS/tracegraph
```
