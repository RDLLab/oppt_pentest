/**
 * Copyright 2017
 * 
 * This file is part of On-line POMDP Planning Toolkit (OPPT).
 * OPPT is free software: you can redistribute it and/or modify it under the terms of the 
 * GNU General Public License published by the Free Software Foundation, 
 * either version 2 of the License, or (at your option) any later version.
 * 
 * OPPT is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with OPPT. 
 * If not, see http://www.gnu.org/licenses/.
 */
#include "oppt/robotHeaders/ObservationSpaceDiscretizer.hpp"
#include "oppt/robotHeaders/ObservationSpace.hpp"

namespace oppt
{

class TigerProblemObservationSpaceDiscretizer : public ObservationSpaceDiscretizer{

public:

    TigerProblemObservationSpaceDiscretizer(ObservationSpaceSharedPtr& observationSpace)
    : ObservationSpaceDiscretizer(observationSpace) {
        // Print init
        std::cout << "INITIALIZING CUSTOM OBSERVATION SPACE" << std::endl;
    }

    std::vector<ObservationSharedPtr> getAllObservationsInOrder(const unsigned int& numStepsPerDimension) const
    {
    
        std::vector<ObservationSharedPtr> allObservationsOrdered_;

        VectorFloat observationValues(1,0);


        
        // Append all observations to the observation vector
        ObservationSharedPtr observation(new DiscreteVectorObservation(observationValues));	
        observation->as<DiscreteVectorObservation>()->setBinNumber(code);
        allObservationsOrdered_.push_back(observation);


        // Print out all observations here to test that the observation happened
        std::cout << "PRINTING FROM CUSTOM OBSERVATION SPACE" << std::endl;
        for(auto& observation : allObservationsOrdered_){
            observation->print(cout);
            std::cout << std::endl;
        }
        

        return allObservationsOrdered_;
    }

}
