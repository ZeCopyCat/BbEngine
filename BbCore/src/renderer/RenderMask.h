#pragma once

#define RENDER_MASK_WORLD 1
#define RENDER_MASK_UI 2
#define RENDER_MASK_CUSTOM_1 4
#define RENDER_MASK_CUSTOM_2 8
#define RENDER_MASK_CUSTOM_3 16
#define RENDER_MASK_CUSTOM_4 32

#define MAKE_RENDER_MASK(flags) (RenderMask)(flags)
#define ADD_FLAG_TO_RENDER_MASK(mask, flag) mask |= flag;
#define REMOVE_FLAG_FROM_RENDER_MASK(mask, flag) mask &= ~flag;

#define DOES_MASK_HAVE_FLAGS(mask, flag) (mask & (flag)) == (flag)

typedef char RenderMask;