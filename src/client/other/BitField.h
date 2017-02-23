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

#ifndef CLIENT_OTHER_BITFIELD_H_
#define CLIENT_OTHER_BITFIELD_H_

#include <set>
#include <string>
#include <boost/dynamic_bitset.hpp>

class BitField {
public:
    BitField();
    BitField(int numberOfPieces, bool seed = false);
    virtual ~BitField();
    //! Add the piece pointed by index to the BitField.
    void addPiece(int index);
    //! Return true if the BitField b is interesting.
    bool isBitFieldInteresting(BitField const& b) const;
    //! Return a set with all interesting pieces from BitField b.
    std::set<int> getInterestingPieces(BitField const& b) const;
    //! Return a set with the indexes of all set bits
    std::set<int> getBitFieldPieces() const;
    //! Return true if the piece is in the BitField.
    bool hasPiece(int index) const;
    //! Return the size of the BitField in bytes.
    int getByteSize() const;
    //! Return the size of the BitField (the number of pieces).
    size_t size() const;
    //! Return true if this BitField is empty.
    bool empty() const;
    //! Return true if this BitField is full.
    bool full() const;
    //! Return true if b equals to this BitField.
    bool operator!=(BitField const& b) const;
    //! Return true if b differs from this BitField.
    bool operator==(BitField const& b) const;
    //! Return a string representation of the BitField.
    std::string unavailablePieces() const;
    //! Return the completed percentage.
    double getCompletedPercentage() const;
private:
    //! The number of pieces in the BitField.
    int numberOfPieces;
    //! The number of available pieces in the BitField (or the number of set bits).
    int numberOfAvailable;
    //! The bitfield representation.
    boost::dynamic_bitset<> bitField;
};

#endif /* CLIENT_OTHER_BITFIELD_H_ */
