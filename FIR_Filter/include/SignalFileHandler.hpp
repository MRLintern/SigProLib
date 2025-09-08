// SignalFileHandler.hpp

/*

- utility function for reading/writing signals to/from .dat files

*/

#pragma once

#include <vector>
#include <memory>
#include <string_view>

// utility class used for reading/writing signals from .dat files
class SignalFileHandler {

public:

	// read signal samples (1/line)
	static std::unique_ptr<std::vector<double>> LoadFromFile(std::string_view path);

	// save signal output to .dat file (1/line)
	static void SaveToFile(const std::vector<double>& data, std::string_view path);
};