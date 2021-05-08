#include "fun.hpp"

void tinkamaReiksme(string &y)
{
    while (true)
    {
        cin >> y;
        if(y == "Y" || y == "y" || y == "N" || y == "n")
            break;
        else
            cout << "Iveskite tinkama reiksme: "<< endl;
    }
}

int neRaide()
{
    int n;
    while(true)
    {
        cin >> n;
        if(!cin)
        {
            cout << "Iveskite tinkama reiksme: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return n;
            break;
        }    
    }
}

void sortedIsvedimas(vector<studentoSt> studentas)
{
    ofstream prS("smegeniai.txt");
    ofstream prB("besmegeniai.txt");
    
    prS << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    prB << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    vector<studentoSt> studentasSmegenis;
    vector<studentoSt> studentasBesmegenis;

    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<studentas.size();i++)
    {
        if(studentas[i].getavgRez() >= 5)
        {
            studentasSmegenis.push_back(studentas[i]);
        }
        else
        {
            studentasBesmegenis.push_back(studentas[i]);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
        cout << "\nRusiavimas uztruko: "<< diff.count() << " s\n";

    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i=0;i<studentasSmegenis.size();i++)
    {
        prS << studentasSmegenis[i].getVardas() << setw(21-studentasSmegenis[i].getVardas().length()+studentasSmegenis[i].getPavarde().length()) << studentasSmegenis[i].getPavarde() 
            << setw(23-studentasSmegenis[i].getPavarde().length()+3) << fixed << setprecision(2) << studentasSmegenis[i].getmedRez()  
            << setw(20-3+3) << fixed << setprecision(2) << studentasSmegenis[i].getavgRez() << endl;
    }
    for(int i=0;i<studentasBesmegenis.size();i++)
    {
        prB << studentasBesmegenis[i].getVardas() << setw(21-studentasBesmegenis[i].getVardas().length()+studentasBesmegenis[i].getPavarde().length()) << studentasBesmegenis[i].getPavarde() 
            << setw(23-studentasBesmegenis[i].getPavarde().length()+3) << fixed << setprecision(2) << studentasBesmegenis[i].getmedRez()  
            << setw(20-3+3) << fixed << setprecision(2) << studentasBesmegenis[i].getavgRez() << endl;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1-start1;
        cout << "\nIsvedimas uztruko: "<< diff1.count() << " s\n";
}

void sarIsvedimas(vector<studentoSt> studentas)
{   
    ofstream pr("rez.txt");
    
    pr << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i=0; i<studentas.size(); i++)
    {
        pr << studentas[i].getVardas() << setw(21-studentas[i].getVardas().length()+studentas[i].getPavarde().length()) << studentas[i].getPavarde() 
        << setw(23-studentas[i].getPavarde().length()+3) << fixed << setprecision(2) << studentas[i].getmedRez()  
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].getavgRez() << endl;
    }
}

ifstream failoPasirinkimas()
{
    string failas;
    cout << "Pasirinkite faila: \n 1. 10000 \n 2. 100000 \n 3. 1000000" << endl;
    cin >> failas;
    while(failas!="1" && failas!="2" && failas!="3")
    {   
            cout << "Iveskite tinkama reiksme (1,2 arba 3)" << endl;
            cin.clear();
            cin >> failas;
    }

    if(failas=="1")
    {
        ifstream rd("10000.txt");
        return rd;
    }
    else if(failas=="2")
    {  
        ifstream rd("100000.txt");
        return rd;
    }
    ifstream rd("1000000.txt");
    return rd;
}

void skaitymas(vector<studentoSt> &studentas, bool tipas)
{
    
    ifstream rd;
    if(tipas)
    rd = failoPasirinkimas();
    else
    rd.open("genFile.txt");

    try
    {
        if(rd.fail()) throw "Pasitikrinkite failo pavadinima"; 
    }
    catch(const char * e)
    {
        std::cerr << e << endl;
        exit(EXIT_FAILURE);
    } 

    auto start = std::chrono::high_resolution_clock::now();
    stringstream buffStream;
    
    buffStream << rd.rdbuf();
    rd.close();
    string temp;
    getline(buffStream,temp);
    temp.clear();
    if(tipas==0)
    {
        getline(buffStream,temp);
        temp.clear();
    }
    int i=0;
    while(!buffStream.eof())
    {
        string eil;
        getline(buffStream, eil);
        if(buffStream.eof()) break;
        stringstream lineStream(eil);

        double egzamRez;
        vector<double> pazymiai;
        studentoSt buffStud;
        
        string vTemp, pTemp;


        lineStream >> vTemp >> pTemp; 
        buffStud.setVardas(vTemp);
        buffStud.setPavarde(pTemp);
        
        while(!lineStream.eof())
        {      
            double paz;
            lineStream >> paz;
            try
            {
                if(paz > 10 || paz < 0)
                {
                    throw std::runtime_error("Aptiktas klaidingas pazymys\n");
                }
            }
            catch(const std::runtime_error& e)
            {
                std::cout << e.what() << '\n';
                exit(EXIT_FAILURE);
            }

            if(lineStream.eof())
                egzamRez = paz;
            else
                pazymiai.push_back(paz);          
        }
        buffStud.setavgRez((sarVidurkis(pazymiai, egzamRez)));
        buffStud.setmedRez((sarMediana(pazymiai, egzamRez)));
        
        studentas.push_back(buffStud);  
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
        cout << "\nSkaitymas uztruko: "<< diff.count() << " s\n";
    
    sort(studentas.begin(),studentas.end());
}
