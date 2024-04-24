/*  Name      : jagjit kaurr 
    User Email: jkaur682@myseneca.ca
    Student ID: 156806226
    Date      : February 14th 2024

    I have done all the coding by myself and only copied the
    code that my professor provided to complete my workshops and assignments.  */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
using namespace std;

namespace seneca {
    const char* GuitarStr::material() const {
        return m_material;
    }
    double GuitarStr::gauge() const {
        return m_gauge;
    }
    GuitarStr::GuitarStr() {};

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    };
}
