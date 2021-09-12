#include <string>
#include <vector>
#include <algorithm>
#include "struct.hpp"

studentoSt::studentoSt(string vardas, string pavarde)
{
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->medRez = 0;
    this->avgRez= 0;
}

studentoSt::studentoSt()
{
    this->vardas = "";
    this->pavarde = "";
    this->medRez = 0;
    this->avgRez = 0;
}

studentoSt::studentoSt(const studentoSt& oth)
{
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;
}

studentoSt studentoSt::operator=(const studentoSt& oth){ // assign
    this->vardas = oth.vardas;
    this->pavarde = oth.pavarde;
    this->medRez = oth.medRez;
    this->avgRez = oth.avgRez;

    return *this;
}

studentoSt::~studentoSt(){}

double getVid(std::vector<double> &pazymiai){
    double sum = 0;

    for(int i = 0; i<pazymiai.size(); i++)
    {
        sum += pazymiai[i];
    }

    return sum/pazymiai.size();
}

double getMed(std::vector<double> &pazymiai)
{
    double mediana;

    if (pazymiai.size() == 0)
    {
        return 0;
    }  
    else
    {
        sort(pazymiai.begin(), pazymiai.end());
        if (pazymiai.size() % 2 == 0)
        {
            return (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2;
        }
        else
        {
            return pazymiai[pazymiai.size() / 2];
        }
    }
}

void studentoSt::galutinisrez(std::vector<double> &pazymys, double egzamRez)
{
    egzamRez *= 0.6;
    avgRez = ((getVid(pazymys) * 0.4) + egzamRez);
    medRez = ((getMed(pazymys) * 0.4) + egzamRez);
}

const string zmogus::getVardas(){
    return vardas;
}

const string zmogus::getPavarde(){
    return pavarde;
}

void zmogus::setVardas(string v){
    vardas = v;
}

void zmogus::setPavarde(string p){
    pavarde = p;
}

double studentoSt::getmedRez(){
        return medRez;
    }
double studentoSt::getavgRez(){
        return avgRez;
    }
void studentoSt::setavgRez(double m){
    medRez = m;
}
void studentoSt::setmedRez(double a){
     avgRez = a;
}

bool studentoSt::operator < (const studentoSt &stud) const{
        return vardas.compare(stud.vardas) < 0;
    }
