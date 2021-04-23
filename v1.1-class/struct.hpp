#ifndef struct_hpp
#define struct_hpp

#include "lib.hpp"

class studentoSarStruct
{
    private:
    string vardas, pavarde;
    double medRez;
    double avgRez;

    public: 
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

    bool operator < (const studentoSarStruct &stud) const{
        return vardas.compare(stud.vardas) < 0;
    }

};

/*struct studentoStruct
{
    string vardas, pavarde;
    int pazymiuSkaicius=0;
    vector<double> ndRez;
    double egzamRez;

    bool operator < (const studentoStruct &stud) const
    {
        return vardas.compare(stud.vardas) < 0;
    }
};*/

#endif