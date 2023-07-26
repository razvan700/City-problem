#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
    public:
        string mName;
        uint16_t mAge;
        double mSalary;
    Person()
    {
        mAge=0;
        mSalary=0;
        mName="";
    }
    Person(string nume, int16_t varsta, double salariu)
    {
        mName=nume;
        mAge=varsta;
        mSalary=salariu;
    }
    bool operator == (const Person &Cosmin) const
    {
        if(Cosmin.mAge == this->mAge && Cosmin.mName == this->mName  && Cosmin.mSalary == this->mSalary)
            return true;
        return false;
    }
    bool operator < (const Person &Cosmin) const
    {
        if(this->mName < Cosmin.mName)
            return true;
        return false;
    }
};
class Building
{
    protected:
        string mBuildingName;
        string mType;
        Person mCoordinator;
        vector<Person> mEmployees;
        vector<Person> mCitizens;
    public:
        Building(string tip, string nume)
        {
            mBuildingName=nume;
            mType=tip;
        }
    virtual void add(const Person &Cosmin)
    {
        
    }
    virtual void remove(const Person &Cosmin)
    {

    }
    virtual Building*  operator+ (const Person& Cosmin)=0;
    virtual Building  *operator- (const Person& Cosmin)
    {
        return nullptr;
    }
    virtual Building*  operator -()
    {
        return nullptr;
    }
    string getBuildingName() const
    {
        return mBuildingName;
    }
    string getType() const
    {
        return mType;
    }
    uint16_t getEmployeesSize() const
    {
        return mEmployees.size();
    }
    uint16_t getCitizensSize() const
    {
        return mCitizens.size();
    }
    Person getEmployee(uint16_t index) const
    {
        return mEmployees[index];
    }
    Person getCitizen(uint16_t index) const
    {
        return mCitizens[index];
    }
    Person getCoordinator() const
    {
        return mCoordinator;
    }
};

class CityHall : public Building
{
    public:
        explicit CityHall(string nume) :  Building("CityHall", std::move(nume))
        {
            mCitizens.clear();
            mCoordinator=Person();
        }
    Building*  operator +(const Person &Cosmin) override{
            if(mCoordinator==Person()) mCoordinator=Cosmin;
        return this;
        }

    Building*  operator -() override {
        mCoordinator = Person();
        return this;
    }
    void add(const Person &Cosmin) override{
    mCitizens.push_back(Cosmin);
}
    
    void remove(const Person &Cosmin) override
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName == Cosmin.mName) {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};



class Hospital : public Building
{
    public:
        explicit Hospital(string nume) : Building("Hospital", nume)
        {
            mCitizens.clear();
            mEmployees.clear();
        }
    Building*  operator +(const Person &Cosmin) override{
        mEmployees.push_back(Cosmin);
        return this;
    }

    Building*  operator -(const Person &Cosmin) override {
        for(int i=0;i<mEmployees.size();i++)
        {
            if(mEmployees[i].mName == Cosmin.mName) {
                mEmployees.erase(mEmployees.begin() + i);
                break;
            }
        }
        return this;
    }
    void add(const Person &Cosmin) override
    {
        mCitizens.push_back(Cosmin);
    }
    void remove(const Person &Cosmin) override
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName == Cosmin.mName) {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};
class PoliceStation : public Building
{
public:
    explicit PoliceStation(string nume) :  Building("PoliceStation", std::move(nume))
    {
        mCitizens.clear();
        mEmployees.clear();
    }
    Building*  operator +(const Person &Cosmin) override{
        mEmployees.push_back(Cosmin);
        return this;
    }
    Building*  operator -(const Person &Cosmin) override {
        for(int i=0;i<mEmployees.size();i++)
        {
            if(mEmployees[i].mName == Cosmin.mName) {
                mEmployees.erase(mEmployees.begin() + i);
                break;
            }
        }
        return this;
    }
    void add(const Person &Cosmin) override
    {
        mCitizens.push_back(Cosmin);
    }
    void remove(const Person &Cosmin) override
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName == Cosmin.mName) {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};
class House : public Building
{
    private:
        uint16_t mMaxNumber;
    public:
    House(const string& nume, uint16_t Maxim) : Building("House",nume)
    {
        mType="House";
        mBuildingName=nume;
        mMaxNumber=Maxim;
    }
    Building*  operator +(const Person &Cosmin) override{
        if(mCoordinator==Person()) mCoordinator=Cosmin;
        return this;
    }
    Building*  operator -() override {
        mCoordinator = Person();
        return this;
    }
    void add(const Person &Cosmin) override
    {
        if(mCitizens.size()<mMaxNumber)mCitizens.push_back(Cosmin);
    }
    void remove(const Person &Cosmin) override
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i].mName == Cosmin.mName && mCitizens[i].mAge>=18) {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};
class Block : public Building
{
    private:
        uint16_t mMaxNumberPerFloor;
    public:
        Block(string nume, uint16_t nret, uint16_t persmax) : Building("Block", std::move(nume))
        {
            mMaxNumberPerFloor=persmax;
            mCitizens.clear();
            mCoordinator=Person();
            mCitizens.resize(mMaxNumberPerFloor*nret, Person());
        }
    Building*  operator +(const Person &Cosmin) override{
        if(mCoordinator==Person()) mCoordinator=Cosmin;
        return this;
    }
    Building*  operator -() override {
        mCoordinator = Person();
        return this;
    }
    void add(const Person &Cosmin) override
    {
        for(auto & mCitizen : mCitizens)
        {
            if(mCitizen==Person())
            {mCitizen=Cosmin;break;}

        }
    }
    void remove(const Person &Cosmin) override
    {
        for(int i=0;i<mCitizens.size();i++)
        {
            if(mCitizens[i] == Cosmin && mCitizens[i].mAge>=18) {
                mCitizens.erase(mCitizens.begin() + i);
                break;
            }
        }
    }
};

int main()
{
/*string Command, Subject, Name, PlaceToAddIn;
uint16_t NrMaxHouse, NrMaxOnFl, NrOfFl, Age;
double Wage;
string obj;
vector <CityHall> CityHalls;
vector <Hospital> Hospitals;
vector <Building> PoliceStations;
vector <Building> Houses;
vector <Building> Blocks;


while(cin>>Command)
{
    if(Command=="add")
    {
        cin>>Subject;
            if(Subject=="CityHall" || Subject=="Hospital" || Subject=="PoliceStation" || Subject=="House" || Subject=="Block")
            {
                cin>>Name;
                if(Subject=="House")
                {
                cin>>NrMaxHouse;
                Houses.push_back(House(Name,NrMaxHouse));
                }
                if(Subject=="Block"){
                    cin >> NrOfFl >> NrMaxOnFl;
                    Blocks.push_back(Block(Name,NrOfFl,NrMaxOnFl));
                }
                if(Subject=="PoliceStation")
                {
                    PoliceStations.push_back(PoliceStation(Name));
                }
                if(Subject=="Hospital")
                {
                    Hospitals.emplace_back(Hospital(Name));
                }
                if(Subject=="CityHall")
                {
                    CityHalls.emplace_back(CityHall(Name));
                }
            }
            else
            {
                cin>>Name;
                cin>>Age;
                cin>>Wage;
                cin>>PlaceToAddIn;
                Person x(Name,Age,Wage);
                
                
    }
}







}*/
return 0;
}