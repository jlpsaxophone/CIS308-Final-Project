//Ship struct

typedef enum ShipState {afloat, sunk} ShipState;
typedef enum bool {FALSE, TRUE} bool;

typedef struct Ship {
    int size;
    ShipState state;
    bool Segments[5];
} Ship;
