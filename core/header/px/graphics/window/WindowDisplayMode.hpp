#ifndef PXENGINE_WINDOWDISPLAYMODE_HPP
#define PXENGINE_WINDOWDISPLAYMODE_HPP

namespace px
{
/**
 * Represent all available window display mode
 */
enum WindowDisplayMode
{
    FULLSCREEN, /**< Represent a fullscreen keep current resolution */
    BORDERLESS, /**< Represent a fullscreen default desktop resolution */
    WINDOWED,   /**< Represent a windowed */
};
}

#endif //PXENGINE_WINDOWDISPLAYMODE_HPP
