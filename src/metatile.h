#ifndef METATILE_H
#define METATILE_H

#pragma warning(push, 0)
#include <FL/fl_types.h>
#pragma warning(pop)

#include "tile.h"

#define METATILE_SIZE 4

class Metatile {
private:
	uint8_t _id;
	uint8_t _tile_ids[METATILE_SIZE][METATILE_SIZE];
public:
	Metatile(uint8_t id);
	inline uint8_t id(void) const { return _id; }
	inline void id(uint8_t id) { _id = id; }
	inline uint8_t tile_id(int x, int y) const { return _tile_ids[y][x]; }
	inline void tile_id(int x, int y, uint8_t id) { _tile_ids[y][x] = id; }
	void clear(void);
};

#endif
