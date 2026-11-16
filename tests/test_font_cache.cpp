#include "FontCacheValidation.h"
#include <cassert>
struct Entry { unsigned ch,left,right,top,bottom; };
struct Range { unsigned first, count; unsigned Length() const { return count; } int Character(unsigned i) const { return first+i; } };
int main() {
 Range ranges[] = {{65,2},{0x4e00,2}};
 Entry valid[] = {{65,0,8,0,12},{66,8,16,0,12},{0x4e00,16,24,0,12},{0x4e01,24,32,0,12}};
 assert(FontCacheGlyphsMatch(valid,ranges,2,32,12));
 valid[3].ch = 0x4e02; assert(!FontCacheGlyphsMatch(valid,ranges,2,32,12));
 valid[3].ch = 0x4e01; valid[3].right = 33; assert(!FontCacheGlyphsMatch(valid,ranges,2,32,12));
 valid[3].right = 32; valid[0].top = 13; assert(!FontCacheGlyphsMatch(valid,ranges,2,32,12));
 return 0;
}
