#include <stdint.h>

extern "C" {

struct GlyphRasterSpace {
  enum class Tag : uint8_t {
    Local,
    Screen,

    Sentinel /* this must be last for serialization purposes. */
  };

  struct Local_Body {
    float _0;

    bool operator==(const Local_Body& aOther) const {
      return _0 == aOther._0;
    }
  };

  Tag tag;
  union {
    Local_Body local;
  };

  static GlyphRasterSpace Local(float const& a0) {
    GlyphRasterSpace result;
    result.local._0 = a0;
    result.tag = Tag::Local;
    return result;
  }

  static GlyphRasterSpace Screen() {
    GlyphRasterSpace result;
    result.tag = Tag::Screen;
    return result;
  }

  bool IsLocal() const {
    return tag == Tag::Local;
  }

  bool IsScreen() const {
    return tag == Tag::Screen;
  }
};

struct LayoutRect {
  struct {
    float x, y;
  };
  struct {
    float width, height;
  };
};

enum class TransformStyle: uint8_t { Flat, Preserve3D };
enum class MixBlendMode: uint8_t { Default, Whatever };

void wr_dp_push_stacking_context(void *aState,
                                 LayoutRect aBounds,
                                 const void *aClipNodeId,
                                 const void *aAnimation,
                                 const void *aOpacity,
                                 const void *aTransform,
                                 TransformStyle aTransformStyle,
                                 const void *aPerspective,
                                 MixBlendMode aMixBlendMode,
                                 const void *aFilters,
                                 uintptr_t aFilterCount,
                                 bool aIsBackfaceVisible,
                                 GlyphRasterSpace aGlyphRasterSpace);




}


int main() {
  auto localRasterSpace = GlyphRasterSpace::Local(1.0);
  auto screenRasterSpace = GlyphRasterSpace::Screen();
  
  auto rect = LayoutRect {{0, 0}, {0, 0}};
  auto transStyle = TransformStyle::Preserve3D;
  auto blendMode = MixBlendMode::Default;

  wr_dp_push_stacking_context(
    nullptr, rect, nullptr, nullptr, nullptr, nullptr,
    transStyle, nullptr, blendMode, nullptr, 0, true,
    localRasterSpace
  );

  wr_dp_push_stacking_context(
    nullptr, rect, nullptr, nullptr, nullptr, nullptr,
    transStyle, nullptr, blendMode, nullptr, 0, true,
    screenRasterSpace
  );
}