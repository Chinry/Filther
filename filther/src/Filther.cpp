
#include "DistrhoPlugin.hpp"

#define RINGBUFFER_SIZE 0xFFFFFF


START_NAMESPACE_DISTRHO


class Filther : public Plugin
{
public:
    Filther()
        : Plugin(4, 0, 0), // 3 parameters, 0 programs, 0 states
    {
    	std::memset(ringbuffer, 0, sizeof(float)*RINGBUFFER);
    }

protected:

    const char* getLabel() const override
    {
        return "Filther";
    }

    const char* getDescription() const override
    {
        return "Filter Plugin.";
    }

    const char* getMaker() const override
    {
        return "";
    }

    const char* getHomePage() const override
    {
        return "";
    }

    const char* getLicense() const override
    {
        return "None";
    }

    uint32_t getVersion() const override
    {
        return d_version(1, 0, 0);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('b', 'b', 'b', 'b');
    }

    void initParameter(uint32_t index, Parameter& parameter) override
    {
    	parameter.hints = kParameterIsAutomable;
	switch (index)
	{
	case 0:
		parameter.name = "cutoff";// hz
		parameter.ranges.min = 0.0f;
		parameter.ranges.max = 44100.0f;
		parameter.ranges.def = 0.0f;
		break;
	case 1:
		parameter.name = "resonance";// db
		parameter.ranges.min = 0.0f;
		parameter.ranges.max = 2000.0f;
		parameter.ranges.def = 0.0f;
		break;
	case 2:
		parameter.name = "filter_type"; //lowpass, highpass, bandpass, notch
    		parameter.hints = kParameterIsAutomable|kParameterIsInteger;
		parameter.ranges.min = 0.0f;
		parameter.ranges.max = 3.0f;
		parameter.ranges.def = 0.0f;
		break;
	case 3:
		parameter.name = "bandwidth"; //octave
		parameter.ranges.min = 0.03f;
		parameter.ranges.max = 2.0f;
		parameter.ranges.def = 1.0;
		break;
	}
	parameter.symbol = parameter.name;
    }

    void getParameterValue(uint32_t index) const override 
    {
    	return params[index];
    }
    
    void setParameterValue(uint32_t index, float value) override
    {
	params[index] = value;
    }

    void run(const float** inputs, float** outputs, uint32_t frames) override
    {
	    		
    }

    private:
	float params[4];
	float ringbuffer[RINGBUFFER_SIZE];

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExamplePluginMeters)
};


Plugin* createPlugin()
{
    return new Filther();
}

END_NAMESPACE_DISTRHO
