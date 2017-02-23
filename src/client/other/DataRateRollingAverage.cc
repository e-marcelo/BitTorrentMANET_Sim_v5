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

#include <DataRateRollingAverage.h>
#include <stdexcept>

DataRateRollingAverage::DataRateRollingAverage(int window) :
        dataRateSum(0), dataRates(0), previousDeltaT(0), previousT(0), totalDownloaded(
                0), window(window) {
}
void DataRateRollingAverage::collect(double now, int totalDownloaded) {
    // If now is equal the previous time, than it is still calculating the current data rate
    if (now <= this->previousT) {
        throw std::invalid_argument("Now is older than the previous time");
    }
    this->dataRates.push_back(
            (totalDownloaded - this->totalDownloaded)
                    / (now - this->previousT));
    this->previousT = now;
    this->totalDownloaded = totalDownloaded;

    // passed data rate is added to the sum of dataRates.
    this->dataRateSum += this->dataRates.back();

    // if the rolling window was reached, remove the oldest value from the average
    if (this->dataRates.size() > this->window) {
        this->dataRateSum -= this->dataRates.front();
        this->dataRates.pop_front();
    }
}
double DataRateRollingAverage::getDataRateAverage() const {
    double ret = 0;

    if (!this->dataRates.empty()) {
        ret = (this->dataRateSum / this->dataRates.size());
    }
    return ret;
}
