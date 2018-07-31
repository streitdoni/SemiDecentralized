//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "QoSRequirementsMapping.h"

QoSRequirementsMapping::QoSRequirementsMapping()
{
    requirements = new QoSRequirementsMapping::QoSRequirelemts();
}

QoSRequirementsMapping::~QoSRequirementsMapping()
{
    delete requirements;
}

QoSRequirementsMapping::QoSRequirelemts* QoSRequirementsMapping::determineQoSRequirements(int tos)
{
    if (tos > 0 && tos < 32)
    {
        requirements->setMaxDelay(1100);
        requirements->setMinBandwidth(350);
        requirements->setMinSlotTime(20);
    }
    else if (tos > 32 && tos < 64)
    {
        requirements->setMaxDelay(80);
        requirements->setMinBandwidth(80);
        requirements->setMinSlotTime(20);
    }
    return requirements;
}
