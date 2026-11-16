#pragma once
#include <cstddef>

// The caller must first validate that entries contains every requested item.
// Validate all metadata before creating a texture or modifying glyph trees.
template<class Entry, class Range>
bool FontCacheGlyphsMatch(const Entry *entries, Range *ranges, std::size_t count,
                          unsigned width, unsigned height)
{
    for (std::size_t i = 0; i < count; ++i)
        for (std::size_t j = 0; j < ranges[i].Length(); ++j, ++entries)
            if (entries->ch != static_cast<unsigned>(ranges[i].Character(j)) ||
                entries->left > entries->right || entries->top > entries->bottom ||
                entries->right > width || entries->bottom > height)
                return false;
    return true;
}
