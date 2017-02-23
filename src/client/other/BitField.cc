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

#include <BitField.h>
#include <boost/lexical_cast.hpp>
#include <iostream>

// helper function
namespace {
// private
std::set<int> getPiecesSet(boost::dynamic_bitset<> const& bitField) {
    std::set<int> ret;
    std::set<int>::iterator it = ret.begin();

    for (int i = 0; i < bitField.size(); ++i) {
        if (bitField.test(i)) {
            // efficient insert because pieces are inserted in order
            it = ret.insert(it, i);
        }
    }

    return ret;
}
}

BitField::BitField() :
        numberOfPieces(0), numberOfAvailable(0) {
}
/*!
 * @param numberOfPieces The number of pieces in the BitField.
 * @param pieceSize      The size of the pieces, in bytes.
 * @param seed           True if the BitField is a seeder BitField (all pieces present).
 */
BitField::BitField(int numberOfPieces, bool seed) :
        numberOfPieces(numberOfPieces),
            numberOfAvailable(seed ? numberOfPieces : 0),
            bitField(numberOfPieces) {
    if (seed) {
        this->bitField = this->bitField.flip();
    }
}

BitField::~BitField() {
}

void BitField::addPiece(int index) {
    // if piece was 0, then the number of pieces went up by one.
    if (!this->bitField.test(index)) {
        ++this->numberOfAvailable;
    }
    this->bitField[index] = 1;
}
/*!
 * The BitField is interesting if it has any piece not owned by this BitField.
 * BitField b must have the same number of pieces as this BitField.
 */
bool BitField::isBitFieldInteresting(BitField const& b) const {
    if (this->numberOfPieces != b.numberOfPieces) {
        throw std::invalid_argument("The BitField has the incorrect size");
    }

    return (~this->bitField & b.bitField).any();
}
/*!
 *
 */
std::set<int> BitField::getInterestingPieces(BitField const& b) const {
    if (this->numberOfPieces != b.numberOfPieces) {
        throw std::invalid_argument("The BitField has the incorrect size");
    }

    boost::dynamic_bitset<> interestingPieces = ~this->bitField & b.bitField;
    return getPiecesSet(interestingPieces);
}
std::set<int> BitField::getBitFieldPieces() const {
    return getPiecesSet(this->bitField);
}
bool BitField::hasPiece(int index) const {
    return this->bitField.test(index);
}
int BitField::getByteSize() const {
    return ((this->numberOfPieces / 8) + ((this->numberOfPieces % 8) ? 1 : 0));
}

size_t BitField::size() const {
    return this->bitField.size();
}

bool BitField::empty() const {
    return this->numberOfAvailable == 0;
}

bool BitField::full() const {
    return this->numberOfAvailable == this->numberOfPieces;
}

bool BitField::operator!=(BitField const& b) const {
    return this->bitField != b.bitField;
}

bool BitField::operator==(BitField const& b) const {
    return this->bitField == b.bitField;
}

std::string BitField::unavailablePieces() const {
    std::string strRep;
    for (int i = 0; i < this->bitField.size(); ++i) {
        if (!this->bitField.test(i)) {
            strRep += boost::lexical_cast<std::string>(i) + " ";
        }
    }
    return strRep;
}
double BitField::getCompletedPercentage() const {
    return (double) this->numberOfAvailable * 100 / this->numberOfPieces;
}
