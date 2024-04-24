/*  Name      : jagjit kaur 
    User Email: jkaur682@myseneca.ca
    Student ID: 156806226
    Date      : February 14th  2024

    I have done all the coding by myself and only copied the
    code that my professor provided to complete my workshops and assignments.  */

#pragma once
#ifndef UTILS_H
#define UTILS_H
namespace seneca {

    const int MAT_LEN = 10;

    class GuitarStr {
        char m_material[MAT_LEN]{};
        double m_gauge{};
    public:
        const char* material()const;
        double gauge()const;
        GuitarStr();
        GuitarStr(const char* ma, double ga);
    };

}

#endif
