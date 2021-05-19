#include <iostream>
#include<fstream>
#include <vector>
using namespace std;
class Time {
private:
    int year, month, day, hour, minute, second;
public:
    Time(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
};
class PeopleFlowMonitoringEquipment {
private:
    //Time date;//̽��ʱ��
    string date;
    string station;//׮��
    string location;//�ص�
    string num;//�豸��
    string IMEI;//IMEI��
public:
    void show(){
        cout<<date<<station<<location<<num<<IMEI<<endl;
    }
    string getDate() const;
    string getStation() const;
    string getLocation() const;
    string getNum() const;
    string getIMEI() const;
    void setDate(const string &value);
    void setStation(const string &value);
    void setLocation(const string &value);
    void setNum(const string &value);
    void setIMEI(const string &value);
};

class Vpfme{
private:
    vector<PeopleFlowMonitoringEquipment> v;
public:
    Vpfme(string s){
        fstream load(s);
        if(load.fail()==true)
            cout<<"���ļ�ʧ��"<<endl;
        else
        {
            string str;
            getline(load,str);
            getline(load,str);
            PeopleFlowMonitoringEquipment p;
            while (!load.eof()) {
                load>>str;
                p.setDate(str);
                load>>str;
                p.setStation(str);
                load>>str;
                p.setLocation(str);
                load>>str;
                p.setNum(str);
                load>>str;
                p.setIMEI(str);
                v.push_back(p);
            }
        }
    }

    void show(){
        vector<PeopleFlowMonitoringEquipment>::iterator it;
        for(it=v.begin();it!=v.end()-1;it++){
            cout<<(*it).getDate()<<" "<<(*it).getStation()<<" "<<(*it).getLocation()<<" "<<(*it).getNum()<<" "<<(*it).getIMEI()<<" "<<endl;
        }
    }
};


int main()
{
    Vpfme v("������������.txt");
    v.show();

}

string PeopleFlowMonitoringEquipment::getStation() const
{
return station;
}

string PeopleFlowMonitoringEquipment::getLocation() const
{
return location;
}

string PeopleFlowMonitoringEquipment::getNum() const
{
return num;
}

string PeopleFlowMonitoringEquipment::getIMEI() const
{
return IMEI;
}

void PeopleFlowMonitoringEquipment::setDate(const string &value)
{
date = value;
}

void PeopleFlowMonitoringEquipment::setStation(const string &value)
{
station = value;
}

void PeopleFlowMonitoringEquipment::setLocation(const string &value)
{
location = value;
}

void PeopleFlowMonitoringEquipment::setNum(const string &value)
{
num = value;
}

void PeopleFlowMonitoringEquipment::setIMEI(const string &value)
{
IMEI = value;
}

string PeopleFlowMonitoringEquipment::getDate() const
{
return date;
}
