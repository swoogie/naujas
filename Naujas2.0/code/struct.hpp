#ifndef struct_hpp
#define struct_hpp

#include "lib.hpp"

class zmogus
{
    protected:
        string vardas, pavarde;
    public:
        virtual const string getVardas();
        virtual const string getPavarde();

        void setVardas(string v);
        void setPavarde(string p);

        virtual void print() = 0;
};

class studentoSt : public zmogus
{
    private:
    double medRez;
    double avgRez;

    public: 
    studentoSt(string vardas, string pavarde);
    studentoSt();
    studentoSt(const studentoSt& oth);
    studentoSt operator=(const studentoSt& oth);
    ~studentoSt();
    
    void galutinisrez(std::vector<double> &pazymys, double egzamRez);

    double getmedRez();
    double getavgRez();
    

    
    void setmedRez(double m);
    void setavgRez(double a);
    bool operator < (const studentoSt &stud) const;

    void print() override{};
};
#endif