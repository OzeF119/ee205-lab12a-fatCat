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
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"

const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SlUGS_IN_A_POUND = 0.031081 ;
const float Weight::UNKNOWN_WEIGHT = -1;

const string Weight::KILO_LABEL = "Kilo";
const string Weight::POUND_LABEL = "Pound";
const string Weight::SLUG_LABEL = "Slug";

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)


Weight::Weight	(	const Weight::UnitOfWeight 	newUnitOfWeight	) {

}



float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}
static float fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

static float fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}
static float fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}
static float convertWeight( float fromWeight ,UnitOfWeight fromUnit ,UnitOfWeight toUnit ) noexcept {

}
