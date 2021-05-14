#include "lib.hpp"
#include "struct.hpp"
#include "fun.hpp"

int main()
{   
    vector<studentoSt> studentas;
    skaitymas(studentas);
    sortedIsvedimas(studentas);
    studentas.clear();

    return 0;
}

