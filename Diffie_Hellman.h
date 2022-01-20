//
// Created by rlego on 20.01.2022.
//
#include "Person.h"
#include <random>
#ifndef INFO_DEFENCE_DH_DIFFIE_HELLMAN_H
#define INFO_DEFENCE_DH_DIFFIE_HELLMAN_H
class Diffie_Hellman{
private:
    static BigInteger Pow(BigInteger& value,BigInteger exponent);
public:
    static void generateKey(Person& Alice,Person& Bob);
};
#endif //INFO_DEFENCE_DH_DIFFIE_HELLMAN_H
