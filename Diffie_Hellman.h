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
    static void PerformLastStep(Person& Alice,Person& Bob);
    static void PerformFirstStep(Person& Alice,Person& Bob);
    static void GenerateSourceNumbers(Person& Alice,Person& Bob);
public:

    static void GenerateKey(Person& Alice,Person& Bob);
};
#endif //INFO_DEFENCE_DH_DIFFIE_HELLMAN_H
