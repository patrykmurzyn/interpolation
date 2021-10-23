#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Interpolation;

vector<Interpolation> interpolationVector;

int calculatedPoint;

class Interpolation {

public: int ammount;

    vector<float> x;

    vector<float> fx;

public: static void CreateObjs() 
    {
        interpolationVector.clear();

        Interpolation temp;

        fstream file;

        file.open("File.txt", ios::in);

        float num;

        if (file.is_open()) {

            while (file.is_open()) {

                file >> temp.ammount;

                for (int i = 0; i < temp.ammount; i++) {

                        file >> num;
                        temp.x.push_back(num);
                    
                }

                for (int i = 0; i < temp.ammount; i++) {

                        file >> num;
                        temp.fx.push_back(num);
                    
                }

                interpolationVector.push_back(temp);

                if (file.eof()) file.close();
            }
            
        }

        for (int i = 0; i < interpolationVector.size(); i++) {
            
            while (interpolationVector[i].ammount != interpolationVector[i].GetSize())
            {
                interpolationVector[i].RemoveFirstX();
                interpolationVector[i].RemoveFirstFx();
            }



        }
        
    }

public: float GetX(int index) {
    if (index > x.size()) {
        cout << "Poza zakresem" << endl;
        return -404;
    }

    else return x[index];
    }

public: float GetFx(int index) {
    if (index > fx.size()) {
        cout << "Poza zakresem" << endl;
        return -404;
    }

    else return fx[index];
}

public: int GetSize() {
    return x.size();
}

public: void RemoveFirstX() {
    x.erase(x.begin());
      }

public: void RemoveFirstFx() {
    fx.erase(fx.begin());
}
};

int main()
{
    Interpolation::CreateObjs();

    //cout << "Podaj punkt w którym obliczyc wartosc: ";
    //cin >> calculatedPoint;

    for (int i = 0; i < interpolationVector.size(); i++) {

        cout << "Wielomian nr. " << i << endl;

        for (int j = 0; j < interpolationVector[i].GetSize(); j++) {

            cout << "Wezel " << j << ": " << interpolationVector[i].GetX(j)
                << ", wartosc: " << interpolationVector[i].GetFx(j) << endl;
        
        }
    }

}
