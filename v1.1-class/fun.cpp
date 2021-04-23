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

void sortedIsvedimas(vector<studentoSarStruct> studentas)
{
    ofstream prS("smegeniai.txt");
    ofstream prB("besmegeniai.txt");
    
    prS << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    prB << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    vector<studentoSarStruct> studentasSmegenis;
    vector<studentoSarStruct> studentasBesmegenis;

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

void sarIsvedimas(vector<studentoSarStruct> studentas)
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

void skaitymas(vector<studentoSarStruct> &studentas, bool tipas)
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
        studentoSarStruct buffStud;
        
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

/*void isvedimas(int studentuSkaicius, studentoStruct* studentas)
{   
    ofstream pr("rez.txt");
    
    pr << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i=0; i<studentuSkaicius; i++)
    {
        pr << studentas[i].vardas << setw(21-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
        << setw(23-studentas[i].pavarde.length()+3) << fixed << setprecision(2) << mediana(studentuSkaicius, studentas, i) 
        << setw(20-3+3) << fixed << setprecision(2) << vidurkis(studentuSkaicius, studentas, i) << endl;
    }
}*/

/*void nd(studentoStruct* studentas, int i)
{
    int kartai = 0;
    int pazymys;
    string str1="0";
    cout << "Studento pazymiai (baige rasyti, paspauskite 'enter' 2 kartus): " << endl;
    
    while (str1.length()!=0)
    {
        cin.clear();
        cin.sync();
        getline(cin, str1);
        if(str1.length()!=0)
        {
            pazymys = stoi(str1);
            studentas[i].ndRez.push_back(pazymys);
            kartai++;
        }
    }    
    studentas[i].pazymiuSkaicius=kartai;
}*/

/*void ivedimas(int studentuSkaicius, studentoStruct* studentas)
{   
    RandInt rnd{1,10};
    srand(time(0));
    for(int i = 0; i < studentuSkaicius; i++)
    {
        cout << "Studento vardas: " << endl;
        cin >> studentas[i].vardas;
        cout << "Studento pavarde: " << endl;
        cin >> studentas[i].pavarde;

        cout << "Ar zinote pazymiu skaiciu? y/n" << endl;
        string y;
        tinkamaReiksme(y);
        
        if(y == "Y" || y == "y")
        {
            cout << "Pazymiu skaicius: " << endl;
            cin >> studentas[i].pazymiuSkaicius;

            cout << "Ar norite, kad pazymiai butu sugeneruoti automatiskai? y/n" << endl;
            tinkamaReiksme(y);
            
            if(y == "Y" || y == "y")
            {
                
                for(int j=0;j<studentas[i].pazymiuSkaicius;j++)
                {
                    studentas[i].ndRez.push_back(rnd());
                    cout << studentas[i].ndRez[j] << " ";
                }
                cout << endl;
            }
            else 
            {
                cout << "Pazymiai: " << endl;
                for(int j=0;j<studentas[i].pazymiuSkaicius;j++)
                {
                    int pazymys;
                    cin >> pazymys;
                    studentas[i].ndRez.push_back(pazymys);
                }
                   
            }
            
        }
        else
        {
            nd(studentas, i);
        }
        
        cout << "Ar norite, kad egzamino balas butu sugeneruotas automatiskai? y/n" << endl;
        tinkamaReiksme(y);

        if(y == "Y" || y == "y")
        {
            studentas[i].egzamRez = rnd();
            cout << studentas[i].egzamRez << endl;
        }
        else
        {
            cout << "Studento egzamino balas: " <<endl;
            cin >> studentas[i].egzamRez;
        }
        
    }
} */