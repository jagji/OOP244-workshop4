/*  Name      : jagjit kaur 
    User Email: jkaur682@myseneca.ca
    Student ID: 156806226
    Date      : February  14th 2024

    I have done all the coding by myself and only copied the
    code that my professor provided to complete my workshops and assignments.  */

#define _CRT_SECURE_NO_WARNINGS
#include "Guitar.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {

    // Constructors/Destructor
    Guitar::Guitar(const char* mod) : m_strings(nullptr), m_numStrings(0) {
        strncpy(m_model, mod, 15);
        m_model[15] = '\0';
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) : m_strings(nullptr), m_numStrings(0) {
        if (ns > 0 && ns <= 10) {
            m_strings = new GuitarStr[ns];
            for (int i = 0; i < ns; ++i) {
                m_strings[i] = strs[i];
            }
            m_numStrings = ns;
        }
        strncpy(m_model, mod, 15);
        m_model[15] = '\0';
    }

    Guitar::~Guitar() {
        deString(); // This calls deString to deallocate resources
    }

    // Modifiers Functions
    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn < m_numStrings) {
            m_strings[sn] = gs;
            return true;
        }
        return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        deString(); // Deallocate existing strings
        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }
        m_numStrings = ns;
    }

    void Guitar::deString() {
        delete[] m_strings; // Deallocate dynamic array
        m_strings = nullptr;
        m_numStrings = 0;
    }

    // Queries Functions
    bool Guitar::strung() const {
        return m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; ++i) {
            if (m_strings[i].gauge() == ga) {
                return true;
            }
        }
        return false;
    }

    // Display function
    std::ostream& Guitar::display(std::ostream& os) const {
        if (m_numStrings == 0) {
            os << "***Empty Guitar***\n";
        }
        else {
            os << "Guitar Model: " << m_model << "\n";
            os << "Strings: " << m_numStrings << "\n";
            for (int i = 0; i < m_numStrings; ++i) {
                os << "#" << i + 1 << std::setw(MAT_LEN + 3) << m_strings[i] << "\n";
            }
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const GuitarStr& gs) {
        return os << std::setw(MAT_LEN) << gs.material() << " | " << std::fixed << std::setprecision(1) << gs.gauge();
    }

}
