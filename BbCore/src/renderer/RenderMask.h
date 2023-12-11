#pragma once

#define RENDER_MASK_VISIBLE 1
#define RENDER_MASK_CUSTOM_1 2
#define RENDER_MASK_CUSTOM_2 4
#define RENDER_MASK_CUSTOM_3 8
#define RENDER_MASK_CUSTOM_4 16
#define RENDER_MASK_CUSTOM_5 32

#define MAKE_RENDER_MASK(flags) (RenderMask)(flags)
#define ADD_FLAG_TO_RENDER_MASK(mask, flag) mask |= flag;
#define REMOVE_FLAG_FROM_RENDER_MASK(mask, flag) mask &= ~flag;

#define DOES_MASK_HAVE_FLAGS(mask, flag) (mask & (flags)) == (flags)

typedef char RenderMask;