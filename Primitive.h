#include <bits/stdc++.h>
#include "Component.h"

using namespace std;

class number: public component {
private:
    int num;
public:
    number(double _num) : num(_num) {}
    int findAns();
};
