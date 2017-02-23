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

#ifndef CLIENT_OTHER_RARESTPIECECOUNTER_H_
#define CLIENT_OTHER_RARESTPIECECOUNTER_H_


#include <vector>
#include <set>
#include <stdexcept>

class BitField;

class RarestPieceCounter {
public:
    RarestPieceCounter();
    RarestPieceCounter(int numberOfPieces);
    virtual ~RarestPieceCounter();
    //! Add the pieces from the passed BitField to the piece count.
    void addBitField(BitField const& bitField);
    //! Add piece to the piece count.
    void addPiece(int index);
    //! Return the count for the piece
    int getPieceCount(int index) const;
    //! Return a list with the n rarest pieces from the passed set of pieces.
    std::vector<int> getRarestPieces(std::set<int> const& pieces,
            unsigned int numberOfPieces) const;
    //! Remove the pieces from the passed BitField from the piece count.
    void removeBitField(BitField const& bitField);
    //! Return the size of the piece vector.
    size_t size() const;
protected:
    //! pieceCount Store the piece count of each piece in the peer set, used to calculate the rarest piece.
    std::vector<int> pieceCount;
};


#endif /* CLIENT_OTHER_RARESTPIECECOUNTER_H_ */
