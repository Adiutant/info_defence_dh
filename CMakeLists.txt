cmake_minimum_required(VERSION 3.21)
project(info_defence_dh)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(info_defence_dh main.cpp Diffie_Hellman.cpp Person.cpp bigint/BigInteger.cc bigint/BigIntegerAlgorithms.cc bigint/BigIntegerUtils.cc bigint/BigUnsigned.cc bigint/BigUnsignedInABase.cc)
