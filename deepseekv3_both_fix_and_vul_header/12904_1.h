#include <vector>
#include <limits>
#include <cmath>
#include <iostream>

class MfccMelFilterbank {
public:
    bool Initialize(int input_length, double input_sample_rate,
                   int output_channel_count,
                   double lower_frequency_limit,
                   double upper_frequency_limit);

private:
    double FreqToMel(double freq);
    
    int num_channels_;
    double sample_rate_;
    int input_length_;
    int start_index_;
    int end_index_;
    bool initialized_;
    std::vector<double> center_frequencies_;
    std::vector<int> band_mapper_;
    std::vector<double> weights_;
};

#define ERROR 1
#define LOG(severity) std::cerr