#include <array>
#include <optional>

namespace uttt
{

enum class Field
{
    Empty,
    X,
    O
};

struct Move
{
    int bigRow;
    int bigColumn;
    int littleRow;
    int littleColumn;
};

template <class T>
using Board = std::array<std::array<T, 3>, 3>;

using MiniBoard = Board<Field>;
using BigBoard  = Board<MiniBoard>;

struct BoardState
{
    BigBoard bigBoard;
    int turnNumber; // 0-80
    std::optional<Move> lastMove;
    BoardState()
        : turnNumber(0)
    {
        // board.fill(Field::Empty);
    }
};
//applyMove(Move)
//possibleMoves() generateFrom lastMove

struct GameParameters
{
    bool isPrePlacement;
    bool availableMoveAtWonBoard;
};

struct PrePlacement
{
    Board<Move> xPreMoves;
    Board<Move> oPreMoves;
};
// removeMatching

struct GameHistory
{
    long int gameId;
    GameParameters params;
    std::array<Move, 81> moves;
    int countMoves;
    std::optional<PrePlacement> prePlacement;
};
// BoardState   createBoardState(History, turnNumber)

}
