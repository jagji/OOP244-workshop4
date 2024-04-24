/*  Name      : jagjit kaur 
    User Email: jkaur682@myseneca.ca
    Student ID: 156806226
    Date      : February  14th  2024

    I have done all the coding by myself and only copied the
    code that my professor provided to complete my workshops and assignments.  */
#pragma once
#ifndef GUITAR_H
#define GUITAR_H

#include "Utils.h" 
#include <iostream>

namespace seneca {

    class Guitar {
        // Dynamic array of GuitarStr
        GuitarStr* m_strings; 
        // Number of GuitarStr in the array
        int m_numStrings;    
        // Model name for the Guitar (max length 15)
        char m_model[16];      
    public:

        // Constructors/Destructor
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], int ns, const char* mod);
        ~Guitar();

        // Modifiers
        bool changeString(const GuitarStr& gs, int sn);
        void reString(GuitarStr strs[], int ns);
        void deString();

        // Queries
        bool strung() const;
        bool matchGauge(double ga) const;

        // Display function
        std::ostream& display(std::ostream& os = std::cout) const;
    };

    
    std::ostream& operator<<(std::ostream& os, const GuitarStr& gs);

}

#endif
