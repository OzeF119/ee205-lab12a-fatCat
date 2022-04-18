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
#include <string>
#include <ostream>
#include "Weight.h"

const float KILOS_IN_A_POUND = 0.453592 ;
const float SlUGS_IN_A_POUND = 0.031081 ;
const float UNKNOWN_WEIGHT = -1;

//const string Weight::KILO_LABEL = "Kilo";
//const string Weight::POUND_LABEL = "Pound";
//const string Weight::SLUG_LABEL = "Slug";

//#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52);

Weight() noexcept {
    weight = UNKNOWN_WEGHT;
}

Weight(float newWeight) {
    weight = newWeight;
}

Weight(UnitOfWeight newUnitOfWeight) noexcept {
    newUnitOfWeight = UnitOfWeight;
}

Weight(float newWeight, UnitOfWeight newUnitOfWeight){
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
}

Weight(float newWeight, float newMaxWeight){
    weight = newWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}

Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    unitOfWeight = newUnitOfWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}

Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}

bool isWeightKnown() const noexcept {
    if(weight == UNKNOWN_WEIGHT) {
        blsKnown = false;
        return false;
    }
    blsKnown = true;
    return true;
}

bool hasMaxWeight() const noexcept {
    if(maxWeight == UNKNOWN_WEIGHT) {
        bHasMax = true;
        return true;
    }
    bHasMax = false;
    return false;
}

float getWeight() const noexcept {
    if (blsKnown == false) {
        return UNKNOWN_WEIGHT;
    }
    else {
        return weight;
    }
}


bool isWeightValid(float checkWeight) const noexcept{
    if(checkWeight <= 0) {
        return false;
    }
    if(bHaxMax == true) {
        if(checkWeight <= maxWeight) {
            return true;
        }
        else {
            return false;
        }
    }
}


Weight & operator+=(float rhs_addToWeight) {
    weight = weight + rhs_addToWeight;
}

bool operator<(const Weight &rhs_Weight) const {
    if (weight == UNKNOWN_WEIGHT) {
        weight = 0;
    }
    if (&rhs_Weight == UNKNOWN_WEIGHT) {
        weight = 0;
    }
    if (convertWeight(weight, unitOfWeight, KILO) < convertWeight(&rhs_Weight, unitOfWeight, KILO)){
        return true;
    }
    return false;
}

bool operator==(const Weight &rhs_Weight) const {
    if (weight == UNKNOWN_WEIGHT) {
        weight = 0;
    }
    if (&rhs_Weight == UNKNOWN_WEIGHT) {
        weight = 0;
    }
    if (convertWeight(weight, unitOfWeight, KILO) == convertWeight(&rhs_Weight, unitOfWeight, KILO)){
        return true;
    }
    return false;
}

void setMaxWeight(float newMaxWeight){
    if(newMaxWeight <= 0) {
        cout << "Error: Weight cannot be equal to or less than zero" << endl ;
    }
    else {
        maxWeight = newMaxWeight;
    }
}


static float fromKilogramToPound( const float kilogram ) noexcept {
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
    float finalWeight;
    if(toUnit == SLUG) {
        if (fromUnit == SLUG) {
            return fromWeight;
        }
        if (fromUnit == POUND) {
            return fromPoundToSlug(fromWeight);
        }
        if (fromUnit == KILO) {
            finalWeight = KilogramToPound(fromWeight);
            return fromPoundToSlug(finalWeight);
        }
    }
    if(toUnit == KILO) {
        if (fromUnit == SLUG) {
            finalWeight = fromSlugToPound(fromWeight);
            return fromPoundToKilogram(finalWeight);
        }
        if (fromUnit == POUND) {
            return fromPoundToKilogram(fromLWeight);
        }
        if (fromUnit == KILO) {
            return fromWeight;
        }
    }
    if(toUnit == POUND){
        if (fromUnit == SLUG){
            return fromPoundToSlug(fromWeight);
        }
        if (fromUnit == POUND){
            return fromWeight;
        }
        if (fromUnit == KILO){
            return fromKilogramToPound(fromWeight);
        }
    }
}
