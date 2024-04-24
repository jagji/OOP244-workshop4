
/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/


/*
name: jagjit kaur
id:156806226


*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

#include <iostream>

#include "Fridge.h"

#include <iomanip>

using namespace std;


namespace seneca 
{


    const char* Food::name() const
    {

        return m_name;

    }

    int Food::weight() const
    
    {

        return m_weight;

    }

    Food::Food()
    {}


    Food::Food(const char* nm, int wei)
    
    {

        strncpy(m_name, nm, NAME_LEN);


        m_weight = wei;


    }


    Fridge::Fridge() : m_numFoods(0), m_model(nullptr) 
    
    {}



    Fridge::Fridge(Food farr[], int nf, const char* mod) : m_numFoods(0), m_model(nullptr) 
    
    {


        if (nf > 0 && mod != nullptr && *mod != '\0') 
        
        
        {


            m_model = new char[strlen(mod) + 1];


            strcpy(m_model, mod);


            int i = 0;


            while (i < nf && i < FRIDGE_CAP)
            
            {
                m_foods[i] = farr[i];


                m_numFoods++;


                i++;


            }


        }


    }



    Fridge::~Fridge() 
    
    {


        delete[] m_model;



    }



    bool Fridge::addFood(const Food& f) 
    
    
    {


        if (m_numFoods < FRIDGE_CAP)
        
        {


            m_foods[m_numFoods++] = f;


            return true;


        }


        return false;


    }



    void Fridge::changeModel(const char* m)
    
    {
        if (m != nullptr && *m != '\0')
        
        {
            delete[] m_model;


            m_model = new char[strlen(m) + 1];


            strcpy(m_model, m);


        }


    }



    bool Fridge::fullFridge() const
    
    
    {


        return m_numFoods >= FRIDGE_CAP;


    }



    bool Fridge::findFood(const char* f) const 
    
    {


        int i = 0;


        while (i < m_numFoods)
        
        {


            if (strcmp(m_foods[i].name(), f) == 0)
            
            {


                return true;


            }


            i++;


        }


        return false;


    }



    std::ostream& Fridge::display(std::ostream& os) const 
    
    
    {


        if (m_model == nullptr || *m_model == '\0')
        
        {


            return os;


        }

        os << "Fridge Model: " << m_model << std::endl;


        os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << std::endl;


        os << "List of Foods" << std::endl;


        int i = 0;


        while (i < m_numFoods) 
        
        {


            os << setw(20) << right << m_foods[i].name() << " | " << m_foods[i].weight() << std::endl;


            i++;


        }


        return os;


    }



}


