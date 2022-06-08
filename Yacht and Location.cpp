#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Yacht {

    string Name;
    int SerialNumber;
    int Degrees = 0;
    static int YachtCount;
    string Latitude;
    string Longitude;

public:

    Yacht(string name, int serialNumber) {
        this->Name = name;
        this->SerialNumber = serialNumber;
        YachtCount++;
    };

    void getpos(Yacht& yacht1, string latitude, string longitude)
    {
        this->Latitude = latitude;
        this->Longitude = longitude;
    };

    void display() {
        cout << "\nThe yacht name is: " << this->Name << endl;
        cout << "The yacht serial number is: " << this->SerialNumber << endl;
        cout << "The yacht location is: \n" << this->Latitude << "\n" << this->Longitude << endl;
    };

    int yachtCount() {
        return YachtCount / 2;
    }
};

int Yacht::YachtCount = 0;

class Location : protected Yacht {

    int Degrees;
    float Minutes;
    char Direction;
    char degree = '\xF8';
    stringstream ss1;
    stringstream ss2;
    string Latitude;
    string Longitude;

public:

    Location(string name, int serialNumber) : Yacht (name, serialNumber) {

    };

    void getpos(Yacht& yacht1, int degrees1, int minutes1, char direction1, int degrees2, int minutes2, char direction2) {
        string deg1 = to_string(degrees1);
        string min1 = to_string(minutes1);
        ss1 << deg1 << degree << min1 << " " << direction1 << " Latitude";
        Latitude = ss1.str();
        string deg2 = to_string(minutes2);
        string min2 = to_string(minutes2);
        ss2 << deg2 << degree << min2 << " " << direction2 <<  " Longitude";
        Longitude = ss2.str();
        yacht1.getpos(yacht1, Latitude, Longitude);
    };
};

int main()
{
    Yacht yacht1("Yacht 1", 1);
    Yacht yacht2("Yacht 2", 2);
    Yacht yacht3("Yacht 3", 3);

    Location location1("Yacht 1", 1);
    Location location2("Yacht 2", 2);
    Location location3("Yacht 3", 3);

    int degrees1[3];
    int minutes1[3];
    char direction1[3];
    int degrees2[3];
    int minutes2[3];
    char direction2[3];

    cout << "************OCEAN RACE 2022*****************\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPlease enter the location of ship number: " << i + 1 << endl;
        cout << "\nInput latitude degrees between 0 and 180: ";
        cin >> degrees1[i];
        cout << "Input latitude minutes between 0 and 60: ";
        cin >> minutes1[i];
        cout << "Input latitude direction (N/S): ";
        cin >> direction1[i];
        cout << "Input longitude degrees between 0 and 180: ";
        cin >> degrees2[i];
        cout << "Input longitude minutes between 0 and 60: ";
        cin >> minutes2[i];
        cout << "Input longitude direction (E/W): ";
        cin >> direction2[i];

    }

    location1.getpos(yacht1, degrees1[0], minutes1[0], direction1[0], degrees2[0], minutes2[0], direction2[0]);
    location2.getpos(yacht2, degrees1[1], minutes1[1], direction1[1], degrees2[1], minutes2[1], direction2[1]);
    location3.getpos(yacht3, degrees1[2], minutes1[2], direction1[2], degrees2[2], minutes2[2], direction2[2]);

    yacht1.display();
    yacht2.display();
    yacht3.display();

    cout << "\nTotal yacht count: " << yacht1.yachtCount() << endl;
}