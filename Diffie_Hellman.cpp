//
// Created by rlego on 20.01.2022.
//
#include "Diffie_Hellman.h"


using namespace std;
void Diffie_Hellman::generateKey(Person& Alice,Person& Bob) {
    mt19937_64 gen (std::random_device{}());
    random_device rd;
    mt19937 mersenne(rd());
    Alice.rand_num = (unsigned long )gen()%1000;
    Bob.rand_num = (unsigned long)gen()%1000;
    //cout<<Bob.rand_num;
    Alice.g = (unsigned long) gen();
    Bob.g = Alice.g;
    Alice.p =  (unsigned long)gen();
    Bob.p =  Alice.p;
    Alice.first_step_value = Pow(Alice.g,Alice.rand_num) ;
    Alice.first_step_value  =Alice.first_step_value%(Alice.p);

    Bob.first_step_value = Pow(Bob.g,Bob.rand_num) ;
    Bob.first_step_value = Bob.first_step_value %(Bob.p);
    BigInteger tmp;
    tmp = Alice.first_step_value;
    Alice.first_step_value = Bob.first_step_value;
    Bob.first_step_value = tmp;
    Alice.key = Pow(Alice.first_step_value,Alice.rand_num) % (Alice.p);
    Bob.key = Pow(Bob.first_step_value,Bob.rand_num) % (Bob.p);
}

BigInteger Diffie_Hellman::Pow(BigInteger& value,BigInteger exponent) {
    BigInteger originalValue = value;
    while (exponent > 1) {
        exponent--;
        value.multiply(value,originalValue);
    }
    return value;
}
