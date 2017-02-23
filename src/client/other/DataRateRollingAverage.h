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

#ifndef CLIENT_OTHER_DATARATEROLLINGAVERAGE_H_
#define CLIENT_OTHER_DATARATEROLLINGAVERAGE_H_

#include <list>
/*!
 * Calculate the rolling average of the data rate.
 */
class DataRateRollingAverage {
public:
    //! Tell the number of elements considered in the rolling average.
    DataRateRollingAverage(int window = 10);
    //! Store the number of bytes downloaded since last call of collect.
    void collect(double now, int totalDownloaded);
    //! Return the average of the last 'n' data rates, where 'n' is the size of the window.
    double getDataRateAverage() const;
private:
    //! The sum of data rates.
    double dataRateSum;
    std::list<double> dataRates;
    //! The last time interval utilized in the calculations
    double previousDeltaT;
    //! The last time instant when a quantity of bytes where computed.
    double previousT;
    //! The total of bytes downloaded up until previousT
    double totalDownloaded;
    //! The size of the rolling window.
    unsigned int window;
};

#endif /* CLIENT_OTHER_DATARATEROLLINGAVERAGE_H_ */
