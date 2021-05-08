#ifndef struct_hpp
#define struct_hpp

#include "lib.hpp"

class studentoSt
{
    private:
    string vardas, pavarde;
    double medRez;
    double avgRez;

    public: 
    studentoSt(); // constr
    studentoSt(const studentoSt&); // copy constr
    studentoSt operator=(const studentoSt& oth); // assign
    ~studentoSt(); // dest

    //getter
    string getVardas(){
        return vardas;
    }
    string getPavarde(){
        return pavarde;
    }
    double getmedRez(){
        return medRez;
    }
    double getavgRez(){
        return avgRez;
    }

    //setter
    void setVardas(string v){
        vardas = v;
    }
    void setPavarde(string p){
        pavarde = p;
    }
    void setmedRez(double m){
        medRez = m;
    }
    void setavgRez(double a){
        avgRez = a;
    }

    bool operator < (const studentoSt &stud) const{
        return vardas.compare(stud.vardas) < 0;
    }

};

studentoSt::studentoSt() // constr
{
    this->vardas = "";
    this->pavarde = "";
    this->medRez = 0;
    this->avgRez = 0;
}

studentoSt::studentoSt(const studentoSt& oth) // copy constr
{
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;
}

studentoSt studentoSt::operator=(const studentoSt& oth) // assign
{
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;

    return *this;
}

studentoSt::~studentoSt() {} // dest

#endif