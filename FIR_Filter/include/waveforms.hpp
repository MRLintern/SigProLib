// waveforms.hpp

/*

- built-in test waveform with 320 samples; amplitude components that make up the entire input signal

- the definition of these expressions live inside waveforms.cpp

*/

extern double InputSignal_f32_1kHz_15kHz[320];

// avoid repeating the number signal components everywhere
constexpr std::size_t WAVEFORM_LENGTH = 320;