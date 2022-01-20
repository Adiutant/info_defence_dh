//
// Created by rlego on 20.01.2022.
//
#include "bigint/BigIntegerLibrary.hh"

#ifndef INFO_DEFENCE_DH_PERSON_H
#define INFO_DEFENCE_DH_PERSON_H
struct Person{
public:

    BigInteger p;
    BigInteger g;
    BigInteger rand_num;
    BigInteger first_step_value;
    BigInteger key;
};
#endif //INFO_DEFENCE_DH_PERSON_H
