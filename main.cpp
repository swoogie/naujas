#include "lib.hpp"
#include "struct.hpp"
#include "fun.hpp"
#include "newFile.hpp"

int main()
{   

    vector<studentoSt> studentas;
    skaitymas(studentas,0);
    sortedIsvedimas(studentas);
    studentas.clear();

    return 0;
}

