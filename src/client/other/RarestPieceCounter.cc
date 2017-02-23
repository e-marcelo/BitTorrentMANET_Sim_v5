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

#include <RarestPieceCounter.h>
#include <list>
#include <set>
#include <algorithm>

//[EAM]#include <random.h>
#include "BitField.h"

RarestPieceCounter::RarestPieceCounter() {
}
RarestPieceCounter::RarestPieceCounter(int numberOfPieces) :
        pieceCount(numberOfPieces, 0) {
}

RarestPieceCounter::~RarestPieceCounter() {
}

/*!
 * Each bit set in the BitField add one to the piece count.
 * Throw an std::out_of_range exception if the size of the pieceCount
 * vector is different from the size of the BitField.
 */
void RarestPieceCounter::addBitField(BitField const& bitField) {
    std::set<int> const& setPieces = bitField.getBitFieldPieces();
    std::set<int>::const_iterator it, end;
    it = setPieces.begin();
    end = setPieces.end();

    for (; it != end; ++it) {
        ++this->pieceCount[*it];
    }
}
/*!
 * Add one to the piece count with the passed index.
 */
void RarestPieceCounter::addPiece(int index) {
    if (index < 0 || (unsigned) index >= this->pieceCount.size()) {
        throw std::out_of_range("The piece index is out of bounds");
    }

    ++this->pieceCount[index];
}

int RarestPieceCounter::getPieceCount(int index) const {
    if (index < 0 || (unsigned) index >= this->pieceCount.size()) {
        throw std::out_of_range("The piece index is out of bounds");
    }
    return this->pieceCount.at(index);
}
/*! Invalid pieces will not be considered.
 * @param pieces .
 * @param numberOfPieces .
 */
std::vector<int> RarestPieceCounter::getRarestPieces(
    std::set<int> const& pieces, unsigned int numberOfPieces) const {
    if (numberOfPieces < 0) {
        throw std::invalid_argument("numberOfPieces must be bigger than zero");
    }
    if (pieces.empty()) {
        throw std::invalid_argument("pieces must not be empty");
    }

    std::vector<int> returnedPieces;

    // sets are ordered, so it is easy to find the minimum and maximum values.
    if ((*(pieces.begin()) < 0)
        || ((unsigned) *(pieces.rbegin()) >= this->pieceCount.size())) {
        throw std::logic_error(
            "There are pieces in the set that are outside the allowed range");
    }

    std::set<int>::const_iterator it = pieces.begin();
    // will store <count, index> pairs
    std::list<std::pair<int, int> > orderedList;

    // create list that will be ordered by piece quantity
    for (; it != pieces.end(); ++it) {
        orderedList.push_back(std::make_pair(this->pieceCount[*it], *it));
    }

    if (!orderedList.empty()) {
        // avoid reallocation when adding elements to the end of the vector
        returnedPieces.reserve(orderedList.size());
        // TODO Maybe, a way to make it more efficient would be to store the count groups
        //      and move the pieces from one group to another as their values changes

        // Sort according to the piece count, then index.
        // The pieces with the same count will be grouped in the sorted list
        orderedList.sort();

        std::list<std::pair<int, int> >::iterator it = orderedList.begin();
        int lastGroupCount = it->first;
        int retGroupBegin = 0;

        // random shuffle the groups of pieces with the same count
        for (int i = 0;
                it != orderedList.end()
                    && returnedPieces.size() < numberOfPieces; ++it, ++i) {
            // group changed
            if (lastGroupCount != it->first) {
                // shuffle the previous group
                //[EAM]std::random_shuffle(returnedPieces.begin() + retGroupBegin,
                //[EAM]    returnedPieces.begin() + i, intrand);
                // start a new group
                lastGroupCount = it->first;
                retGroupBegin = i;
            }

            returnedPieces.push_back(it->second);
        }

        // If all pieces were inserted, then it is necessary to shuffle the last group
        if (it == orderedList.end()) {
            //[EAM]std::random_shuffle(returnedPieces.begin() + retGroupBegin,
            //[EAM]    returnedPieces.end(), intrand);
        }
    }

    int front = returnedPieces.front();
    int back = returnedPieces.back();
    int size = returnedPieces.size();

    return returnedPieces;
}
/*!
 * Each bit set in the BitField subtract one to the piece count. The piece
 * count minimizes at zero.
 * Throw an std::out_of_range exception if the size of the pieceCount
 * vector is different from the size of the BitField.
 */
void RarestPieceCounter::removeBitField(BitField const& bitField) {
    std::set<int> const& setPieces = bitField.getBitFieldPieces();
    std::set<int>::const_iterator it, end;
    it = setPieces.begin();
    end = setPieces.end();

    for (; it != end; ++it) {
        --this->pieceCount[*it];
    }
}
size_t RarestPieceCounter::size() const {
    return this->pieceCount.size();
}
