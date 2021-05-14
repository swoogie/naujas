#ifndef struct_hpp
#define struct_hpp

#include "lib.hpp"

class zmogus
{
    protected:
        string vardas, pavarde;
    public:
        virtual const string getVardas(){
            return vardas;
        }
        virtual const string getPavarde(){
            return pavarde;
        }

        void setVardas(string v){
            vardas = v;
        }
        void setPavarde(string p){
            pavarde = p;
        }

        virtual void print() = 0;
};

class studentoSt : public zmogus
{
    private:
    double medRez;
    double avgRez;

    public: 
    studentoSt(){ // constr
    this->vardas = "";
    this->pavarde = "";
    this->medRez = 0;
    this->avgRez = 0;
    }
    studentoSt(const studentoSt& oth){ // copy constr
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;
    }
    studentoSt operator=(const studentoSt& oth){ // assign
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;

    return *this;
    }
    ~studentoSt(){ // dest
    }
    
    double getmedRez(){
        return medRez;
    }
    double getavgRez(){
        return avgRez;
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

    void print() override{};
};
#endif