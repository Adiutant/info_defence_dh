#include <iostream>
#include "Diffie_Hellman.h"
#include "Person.h"
using namespace std;
int main() {
    Diffie_Hellman dh;
    Person Alice;
    Person Bob;
    Diffie_Hellman::GenerateKey(Alice,Bob);
   // cout<< Alice.first_step_value<<endl;
    cout<<Alice.key<<endl;
    cout<<Bob.key<<endl;


    return 0;
}
