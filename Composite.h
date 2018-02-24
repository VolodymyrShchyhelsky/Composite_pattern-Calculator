#include <bits/stdc++.h>
#include "Component.h"

using namespace std;

class act: public component {
private:
    component* left;
    component* right;
    char sign;
public:
    int findAns();
    act(char _sign, component* l, component* r) : left(l) , right(r) , sign(_sign) {}
};
