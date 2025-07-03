# Cryptanalysis Challenge 2025

# Dependencies

- TracerGrind는 Valgrind라는 도구 위에서 동작하는 프로그램
- Valgrind는 프로그램 실행 중에 메모리 접근, 버그, 성능 등을 검사하는 오픈소스 도구
- TracerGrind는 프로그램이 어느 메모리 주소를 언제 읽고 썼는지 추적(로그)하는 역할
- 메모리 접근 시퀀스를 자세히 기록해서 암호 알고리즘 같은 민감한 부분에서 어떤 주소에 어떤 데이터가 언제 쓰이고 읽혔는지 파악하기 위해서. 보통 화이트박스 암호 분석, 바이너리 분석에 쓰입니다.

# Reference

https://github.com/SideChannelMarvels/Tracer/tree/master
