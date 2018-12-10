//Placement struct

typedef enum direction {horizontal, vertical} direction;

typedef struct ShipPosition {
	int xcoordinate;
	int ycoordinate;
	direction d;
} ShipPosition;
