#ifndef TILESET_H
#define TILESET_H

#include <string>

#include "tile.h"
#include "palette-map.h"
#include "utils.h"

#define TILES_PER_ROW 16
#define TILES_PER_COL (MAX_NUM_TILES / TILES_PER_ROW)

class Tileset {
public:
	enum Result { GFX_OK, GFX_NO_PALETTE, GFX_BAD_FILE, GFX_BAD_EXT, GFX_BAD_DIMS,
		GFX_TOO_SHORT, GFX_TOO_LARGE, GFX_NOT_GRAYSCALE, GFX_BAD_CMD, GFX_NULL };
private:
	std::string _name;
	Lighting _lighting;
	Palette_Map _palette_map;
	Tile *_tiles[MAX_NUM_TILES];
	size_t _num_tiles;
	Result _result;
	bool _modified;
public:
	Tileset();
	~Tileset();
	inline const char *name(void) const { return _name.c_str(); }
	inline void name(const char *name) { _name = name; }
	inline Lighting lighting(void) const { return _lighting; }
	inline Palette_Map &palette_map(void) { return _palette_map; }
	inline Tile *tile(uint8_t i) { return _tiles[i]; }
	inline const Tile *const_tile(uint8_t i) const { return _tiles[i]; }
	inline size_t num_tiles(void) const { return _num_tiles; }
	inline Result result(void) const { return _result; }
	inline bool modified(void) const { return _modified; }
	inline void modified(bool m) { _modified = m; }
	void clear(void);
	void update_lighting(Lighting l);
	uchar *print_rgb(size_t w, size_t h, size_t n) const;
	inline Palette_Map::Result read_palette_map(const char *f) { return _palette_map.read_from(f); }
	Result read_graphics(const char *f, Lighting l);
	static const char *error_message(Result result);
	bool write_graphics(const char *f);
};

#endif
