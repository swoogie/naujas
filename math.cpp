#include "math.hpp"

double sarVidurkis(vector<double> pazymiai, int egzamRez)
{
    double avrg=0;
    for(int i=0; i<pazymiai.size(); i++)
        avrg += pazymiai[i];
            
    avrg = ((avrg/pazymiai.size())*0.4)+(0.6*egzamRez);
    return avrg;    
}

double sarMediana(vector<double> pazymiai, int egzamRez)
{
    sort(pazymiai.begin(), pazymiai.end());
    
    if((pazymiai.size())%2 == 0)
        return (((pazymiai[(pazymiai.size()/2)-1]+pazymiai[(pazymiai.size()/2)])/2)*0.4)+(0.6*egzamRez);
    else
        return (pazymiai[pazymiai.size()/2]*0.4)+(0.6*egzamRez);  
}