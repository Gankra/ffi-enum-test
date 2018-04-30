#![allow(unused_variables)]

#[repr(C, u8)]
#[derive(Debug)]
pub enum GlyphRasterSpace {
	Local(f32),
	Screen,
}

#[repr(u8)] pub enum TransformStyle { Flat, Preserve3D }
#[repr(u8)] pub enum MixBlendMode { Default, Whatever }

pub type Void = u8;

#[repr(C)] pub struct Point(f32, f32);
#[repr(C)] pub struct LayoutRect(Point, Point);

#[no_mangle]
pub extern "C" fn wr_dp_push_stacking_context(state: &mut Void,
                                              bounds: LayoutRect,
                                              clip_node_id: *const Void,
                                              animation: *const Void,
                                              opacity: *const f32,
                                              transform: *const Void,
                                              transform_style: Void,
                                              perspective: *const Void,
                                              mix_blend_mode: MixBlendMode,
                                              filters: *const Void,
                                              filter_count: usize,
                                              is_backface_visible: bool,
                                              glyph_raster_space: GlyphRasterSpace) {

  println!("GlyphRasterSpace {:?}", glyph_raster_space);
}