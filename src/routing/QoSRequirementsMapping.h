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

#ifndef SRC_ROUTING_QOSREQUIREMENTSMAPPING_H_
#define SRC_ROUTING_QOSREQUIREMENTSMAPPING_H_

class QoSRequirementsMapping
{
    public:
        class QoSRequirelemts
        {
            public:
                double getMaxDelay() const
                {
                    return maxDelay;
                }

                double getMinBandwidth() const
                {
                    return minBandwidth;
                }

                double getMinSlotTime() const
                {
                    return minSlotTime;
                }
                void setMaxDelay(double maxDelay)
                {
                    this->maxDelay = maxDelay;
                }
                void setMinBandwidth(double minBandwidth)
                {
                    this->minBandwidth = minBandwidth;
                }

                void setMinSlotTime(double minSlotTime)
                {
                    this->minSlotTime = minSlotTime;
                }

            private:
                double minBandwidth;
                double maxDelay;
                double minSlotTime;

        };

        QoSRequirelemts *requirements;
    public:
        QoSRequirementsMapping();
        virtual ~QoSRequirementsMapping();
        QoSRequirelemts* determineQoSRequirements(int tos);
};

#endif /* SRC_ROUTING_QOSREQUIREMENTSMAPPING_H_ */
