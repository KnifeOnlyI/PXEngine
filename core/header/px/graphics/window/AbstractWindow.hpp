#ifndef PXENGINE_ABSTRACTWINDOW_HPP
#define PXENGINE_ABSTRACTWINDOW_HPP

#include <string>

#include <SDL2/SDL.h>
#include "WindowDisplayMode.hpp"

namespace px
{
/**
 * Represent a window
 */
class AbstractWindow
{
public:

    /**
     * Create a new window
     *
     * @param title The title
     * @param width The width
     * @param height The height
     */
    AbstractWindow(const std::string &title, int width, int height);

    /**
     * Destroy the window
     */
    virtual ~AbstractWindow();

    /**
     * Check if the window open flag is TRUE or FALSE
     *
     * @return The window open flag value
     */
    [[nodiscard]] bool isOpen() const;

    /**
     * Check the visibility flag
     *
     * @return TRUE if the window is visible, FALSE otherwise
     */
    [[nodiscard]] bool isVisible() const;

    /**
     * Check the maximized flag
     *
     * @return TRUE if the window is maximized, FALSE otherwise
     */
    [[nodiscard]] bool isMaximized() const;

    /**
     * Check the minimized flag
     *
     * @return TRUE if the window is minimized, FALSE otherwise
     */
    [[nodiscard]] bool isMinimized() const;

    /**
     * Get the title
     *
     * @return The title
     */
    [[nodiscard]] std::string getTitle() const;

    /**
     * Get the width
     *
     * @return The width
     */
    [[nodiscard]] int getWidth() const;

    /**
     * Get the height
     *
     * @return The height
     */
    [[nodiscard]] int getHeight() const;

    /**
     * Get the display mode
     *
     * @return The display mode
     */
    [[nodiscard]] WindowDisplayMode getDisplayMode() const;

    /**
     * Clear the window
     */
    void clear();

    /**
     * Refresh the window
     */
    void refresh();

    /**
     * Maximize the window
     */
    void maximize();

    /**
     * Minimize the window
     */
    void minimize();

    /**
     * Show the window
     */
    void show();

    /**
     * Hide the window
     */
    void hide();

    /**
     * Close the window
     */
    void close();

    /**
     * Set the title
     *
     * @param value The new title value
     */
    void setTitle(const std::string &value);

    /**
     * Set the width
     *
     * @param value The new width value
     */
    void setWidth(int value);

    /**
     * Set the height
     *
     * @param value The new height value
     */
    void setHeight(int value);

    /**
     * Set the size
     *
     * @param width The new width value
     * @param height The new height value
     */
    void setSize(int width, int height);

    /**
     * Set the display mode
     *
     * @param mode The new display mode
     */
    void setDisplayMode(WindowDisplayMode mode);

    // Events **********************************************************************************************************

    /**
     * Executed on init
     */
    virtual void onInit();

    /**
     * Executed on window open flag is set to FALSE
     */
    virtual void onClose();

    /**
     * Executed on clear
     */
    virtual void onClear();

    /**
     * Executed on refresh
     */
    virtual void onRefresh();

    /**
     * Executed on show
     */
    virtual void onShow();

    /**
     * Executed on hide
     */
    virtual void onHide();

    /**
     * Executed on window maximization
     */
    virtual void onMaximize();

    /**
     * Executed on window minimization
     */
    virtual void onMinimize();

    /**
     * Executed on title change
     *
     * @param oldTitle The old title
     * @param newTitle The new title
     */
    virtual void onTitleChange(const std::string &oldTitle, const std::string &newTitle);

    /**
     * Executed on size change
     *
     * @param oldWidth The old width
     * @param oldHeight The old height
     * @param newWidth The new width
     * @param newHeight The new height
     */
    virtual void onSizeChange(int oldWidth, int oldHeight, int newWidth, int newHeight);

    /**
     * Executed on display mode change
     *
     * @param oldValue The old display mode
     * @param newValue The new display mode
     */
    virtual void onDisplayModeChange(WindowDisplayMode oldValue, WindowDisplayMode newValue);

private:

    /** \var The handle SDL window */
    SDL_Window *_window {nullptr};

    /** \var The handle SDL renderer */
    SDL_Renderer *_renderer {nullptr};

    /** \var The window open flag */
    bool _isOpen {true};
};
}

#endif //PXENGINE_ABSTRACTWINDOW_HPP
