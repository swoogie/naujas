#include "lib.hpp"
#include "struct.hpp"
#include "fun.hpp"

int main()
{   
    vector<studentoSt> studentas;
    skaitymas(studentas);
    sortedIsvedimas(studentas);
    studentas.clear();
    cout << "Spauskite 'Enter', kad uzdarytumete langa" << endl;
    cin.get();
    return 0;
}

