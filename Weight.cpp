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

#define KILOS_IN_A_POUND 0.453592 ;
#define SlUGS_IN_A_POUND 0.031081 ;
#define UNKNOWN_WEIGHT -1;

//const string Weight::KILO_LABEL = "Kilo";
//const string Weight::POUND_LABEL = "Pound";
//const string Weight::SLUG_LABEL = "Slug";

//#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52);

void Weight::Initialize() {
    weight = UNKNOWN_WEIGHT;
    blsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight() noexcept {
    Initialize();
}

Weight::Weight(float newWeight) {
    Initialize();
    weight = newWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    Initialize();
    unitOfWeight = newUnitOfWeight;
}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    Initialize();
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
}
Weight::Weight(float newWeight, float newMaxWeight) {
    Initialize();
    weight = newWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Initialize();
    unitOfWeight = newUnitOfWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Initialize();
    weight = newWeight;
    unitOfWeight = newUnitOfWeight;
    bHasMax = true;
    maxWeight = newMaxWeight;
}

bool Weight::hasMaxWeight() const noexcept {
    if(maxWeight == -1) {
        return true;
    }
    return false;
}

bool Weight::isWeightKnown() const noexcept {
    if(weight == -1) {
        return false;
    }
    return true;
}

float Weight::getWeight() const noexcept {
    if (blsKnown == false) {
        return UNKNOWN_WEIGHT;
    }
    else {
        return weight;
    }
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return convertWeight( weight, unitOfWeight ,weightUnits );
}

float Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    weight = newWeight;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    weight = newWeight;
    unitOfWeight = weightUnits;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(checkWeight <= 0) {
        return false;
    }
    if(bHasMax == true) {
        if(checkWeight <= maxWeight) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    if (convertWeight(weight, unitOfWeight, KILO) == convertWeight(&rhs_Weight, unitOfWeight, KILO)){
        return true;
    }
    return false;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
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

Weight &Weight::operator+=(float rhs_addToWeight) {
    weight = weight + rhs_addToWeight;
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
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
            return fromPoundToKilogram(fromWeight);
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

void Weight::setMaxWeight(float newMaxWeight) {
    if(newMaxWeight <= 0) {
        cout << "Error: Weight cannot be equal to or less than zero" << endl ;
    }
    else {
        maxWeight = newMaxWeight;
    }
}

