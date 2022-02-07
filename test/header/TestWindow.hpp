#ifndef PXENGINE_TESTWINDOW_HPP
#define PXENGINE_TESTWINDOW_HPP

#include <px/graphics/window/AbstractWindow.hpp>

namespace test
{
/**
 * Represent a test window
 */
class TestWindow : public px::AbstractWindow
{
public:

    /**
     * Create a new test window
     *
     * @param title The title
     * @param width The width
     * @param height The height
     * @param debugClear The debug clear event flag
     * @param debugRefresh The debug refresh event flag
     */
    TestWindow(const std::string &title, int width, int height, bool debugClear = false, bool debugRefresh = false);

    void onInit() override;

    void onClose() override;

    void onClear() override;

    void onRefresh() override;

    void onShow() override;

    void onHide() override;

    void onMaximize() override;

    void onMinimize() override;

    void onTitleChange(const std::string &oldTitle, const std::string &newTitle) override;

    void onSizeChange(int oldWidth, int oldHeight, int newWidth, int newHeight) override;

    void onDisplayModeChange(px::WindowDisplayMode oldValue, px::WindowDisplayMode newValue) override;

private:

    /** \var The debug clear event flag */
    bool _debugClear {false};

    /** \var The debug refresh event flag */
    bool _debugRefresh {false};
};
}

#endif //PXENGINE_TESTWINDOW_HPP
