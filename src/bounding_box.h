#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <bn_rect.h>
#include <bn_size.h>
#include <bn_sprite_ptr.h>

bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size);

#endif