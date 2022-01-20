//
// Created by rlego on 20.01.2022.
//
#include "Diffie_Hellman.h"


using namespace std;

void Diffie_Hellman::GenerateSourceNumbers(Person &Alice, Person &Bob) {
    mt19937_64 gen(std::random_device{}());
    random_device rd;
    mt19937 mersenne(rd());
    Alice.rand_num = (unsigned long) gen() % 1000;
    Bob.rand_num = (unsigned long) gen() % 1000;
    //cout<<Bob.rand_num;
    Alice.g = (unsigned long) gen();
    Pow(Alice.g, 20);
    Bob.g = Alice.g;
    Alice.p = (unsigned long) gen();
    Pow(Alice.p, 20);
    Bob.p = Alice.p;
}

void Diffie_Hellman::GenerateKey(Person &Alice, Person &Bob) {
    GenerateSourceNumbers(Alice, Bob);
    PerformFirstStep(Alice, Bob);
    PerformLastStep(Alice, Bob);
}

BigInteger Diffie_Hellman::Pow(BigInteger &value, BigInteger exponent) {
    BigInteger originalValue = value;
    while (exponent > 1) {
        exponent--;
        value.multiply(value, originalValue);
    }
    return value;
}

void Diffie_Hellman::PerformFirstStep(Person &Alice, Person &Bob) {
    Alice.first_step_value = Pow(Alice.g, Alice.rand_num);
    Alice.first_step_value = Alice.first_step_value % (Alice.p);

    Bob.first_step_value = Pow(Bob.g, Bob.rand_num);
    Bob.first_step_value = Bob.first_step_value % (Bob.p);
}

void Diffie_Hellman::PerformLastStep(Person &Alice, Person &Bob) {
    BigInteger tmp;
    tmp = Alice.first_step_value;
    Alice.first_step_value = Bob.first_step_value;
    Bob.first_step_value = tmp;
    Alice.key = Pow(Alice.first_step_value, Alice.rand_num) % (Alice.p);
    Bob.key = Pow(Bob.first_step_value, Bob.rand_num) % (Bob.p);
}
