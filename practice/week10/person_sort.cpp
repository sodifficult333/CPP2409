#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    string GetName() {return name;}
    int GetAge() {return age;}
    void Print() {
        cout << name << " " << age << endl;
    }
};

bool Compare(Person &p, Person &q) { // 데이터 정리 기준 역할
    return p.GetAge() < q.GetAge(); // 나이 크기순
}

int main() {
    vector<Person> list;

    list.push_back(Person("Kim", 30));
    list.push_back(Person("Park", 22));
    list.push_back(Person("Lee", 26));

    sort(list.begin(), list.end(), Compare); // 데이터 정리(시작값, 끝값, 기준)

    // 리스트(벡터) 출력
    for(auto& e:list) {
        e.Print();
    }

    return 0;
}