#include <cassert>

#include "domain/types.h"

int main()
{
    uttt::BoardState boardSt;
    assert(boardSt.bigBoard[0][0][0][0] == uttt::Field::Empty);
}
