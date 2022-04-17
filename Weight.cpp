///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Oze Farris <ofarris@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"

const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SlUGS_IN_A_POUND = 0.031080 ;
const float Weight::UNKNOWN_WEIGHT;

float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}
