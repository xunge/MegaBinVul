#include <cmath>

class BiquadProcessor {
public:
    enum Type {
        LowPass,
        HighPass,
        BandPass,
        LowShelf,
        HighShelf,
        Peaking,
        Notch,
        Allpass
    };

    bool filterCoefficientsDirty() const;
    bool hasSampleAccurateValues() const;
    Type type() const;

    class Parameter {
    public:
        double finalValue() const;
        double smoothedValue() const;
        double value() const;
    };

    Parameter* parameter1() const;
    Parameter* parameter2() const;
    Parameter* parameter3() const;
    Parameter* parameter4() const;
};

class BiquadDSPKernel {
public:
    BiquadProcessor* biquadProcessor() const;
    void updateCoefficients(double cutoffFrequency, double Q, double gain, double detune);
    double nyquist() const;
    void updateCoefficientsIfNecessary();
    void updateCoefficientsIfNecessary(bool useSmoothing, bool forceUpdate);
    
    class Biquad {
    public:
        void setLowpassParams(double frequency, double Q);
        void setHighpassParams(double frequency, double Q);
        void setBandpassParams(double frequency, double Q);
        void setLowShelfParams(double frequency, double gain);
        void setHighShelfParams(double frequency, double gain);
        void setPeakingParams(double frequency, double Q, double gain);
        void setNotchParams(double frequency, double Q);
        void setAllpassParams(double frequency, double Q);
    };

    Biquad m_biquad;
};