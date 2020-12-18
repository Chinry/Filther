#include "DistrhoUI.hpp"

START_NAMESPACE_DISTRHO

using DGL_NAMESPACE::Color;

static const float kSmoothMultiplier = 3.0f;

class FiltherUI : public UI
{
public:
    FiltherUI()
        : UI(128, 512), //set the initial to 128 x 512
    {
        setGeometryConstraints(128, 512, false);
    }

protected:
    void parameterChanged(uint32_t index, float value) override
    {
    }

    void stateChanged(const char*, const char*) override
    {
    }

    bool onMouse(const MouseEvent& ev) override
    {
    }

private:
    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FiltherUI)
};


UI* createUI()
{
    return new FiltherUI();
}

END_NAMESPACE_DISTRHO
