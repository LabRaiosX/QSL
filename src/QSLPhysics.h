//     Copyright (C) 2012  Elvis M. Teixeira
// 
//     The Q Scientific Library is free software; you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation; either version 2 of the License, or
//     (at your option) any later version.
// 
//     The Q Scientific Library is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
// 
//     You should have received a copy of the GNU General Public License
//     along with this program; if not, write to the Free Software
//     Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA


#ifndef QSL_PHYSICS_H
#define QSL_PHYSICS_H

#include "QSLGlobal.h"


namespace QSL {
    namespace Phys {
        /*!
         * The Plank's constant appears in various equations of quantum mechanics,
         * an example is the fotoelectric effect explained by Einstein in 1905:
         * \f[ E=h\nu \f]. Here h is Plank's constant
         */
        const double PlanksConstant                      = 6.6260755e-34;
        const double PlanksConstantNoExponent            = 6.6260755;
        const double PlanksConstantMagnitudeOrder        = 1.0e-34;
        /*!
         * The speed of light is the same in all reference frames according
         * to Einstein's relativity
         */
        const double SpeedOfLight                        = 299792458.0;
        const double SpeedOfLightNoExponent              = 2.99792458;
        const double SpeedOfLightMagnitudeOrder          = 1.0e8;
        /*!
         * The elementar charge is the absolute value of the charge of 
         * an electron, that is negative, no free particle is known to have
         * a non-integer multiple of this charge.
         */
        const double ElementaryCharge                    = 1.60217733e-19;
        const double ElementaryChargeNoExponent          = 1.60217733;
        const double ElementaryChargeMagnitudeOrder      = 1.0e-19;
        /*!
         * Mass of an electron
         */
        const double ElectronMass                        = 9.1093897e-31;
        const double ElectronMassNoExponent              = 9.1093897;
        const double ElectronMassMagnitudeOrder          = 1.0e-31;
        /*!
         * The vacuum permitivity fixes the constant in the Coulomb's electric
         * field equation, in a matterial medium this permitivity is no longer
         * valid
         */
        const double VacuumPermitivity                   = 8.854187817e-12;
        const double VacuumPermitivityNoExponent         = 8.854187817;
        const double VacuumPermitivityMagnitudeOder      = 1.0e-12;
        
        
        /*!
         * The vacuum permeability fixes the constant in the Biot-Savart's magnetic
         * field equation, in a matterial medium this permeability is no longer
         * valid
         */
        const double VacuumPermeability                  = 12.56637061e-7;
        const double VacuumPermeabilityNoExponent        = 12.56637061e-7;
        const double VacuumPermeabilityMagnitudeOrder    = 12.56637061e-7;
        
        
        const double GravityConstant                 = 6.67259e-11;
        const double BoltzmannConstant               = 1.380658e-23;
        const double AvogradoNumber                  = 6.0221367e23;
        const double ProtonMass                      = 1.6726231e-27;
        const double NeutronMass                     = 1.6749286e-27;

        // OTHER UTILITIES
        const double JaulesPerCal                    = 4.186;
        const double EarthsAtmosferePressure         = 1.01325e5;
        const double JaulesPerElectronVolt           = 1.60217733e-19;
        const double KilogramsPerUnitAtomMass        = 1.6605402e-27;
        const double EarthsGravityAcceleration       = 9.80665;
        const double AbsoluteZeroInCelcius           = -273.15;
        
        // EARTH DATA
        const double SunsMass                        = 1.9891e30;
        const double EarthsMass                      = 5.97e24;
        const double EarthsOrbitAverageVelocity      = 29885.8;
        const double EarthsRadius                    = 6.38e6;
        const double EarthsOrbitRadius               = 1.50e11;
        const double SecondsPerYear                  = 31536000.0;
        const double SecondsPerDay                   = 86400.0;
        
        //Utility functions
        inline double celciusToKelvin(double t) { return t - AbsoluteZeroInCelcius; }
        inline double kelvinToCelcius(double t) { return t + AbsoluteZeroInCelcius; }
        
        /**
         * returns the argument without the exponential part, util for
         * using great numbers of small numbers in an appropriate system of units
         */
        inline double withoutExponent(double x)
        {
            return x; //TODO
        }
    }
}

#endif /* QSL_PHYSICS_H */
