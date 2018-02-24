#include <bits/stdc++.h>
#include "Composite.h"

using namespace std;

int act::findAns() {
    switch(sign) {
    case '+':
        return left->findAns() + right->findAns();
    case '-':
        return left->findAns() - right->findAns();
    case '*':
        return left->findAns() * right->findAns();
    case '/':
        return left->findAns() / right->findAns();
    }
}
