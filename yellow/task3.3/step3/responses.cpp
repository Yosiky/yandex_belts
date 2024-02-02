#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
	if (r.no_stop) {
		os << "No stop";
	} else {
		for (const std::string &bus : r.buses)
			 os << bus << ' ';
	}
  return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
	if (r.stops.size() == 0) {
		os << "No bus";
	} else {
		for (size_t i = 0; i < r.stops.size(); ++i) {
			os << "Stop " << r.stops[i] << ":";
			for (const auto &j : r.stops_to_buses[i])
				os << ' ' << j;
			if (i + 1 != r.stops.size())
				os << std::endl;
		}
	}
  return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.size() == 0) 
		os << "No buses";
	else {
		for (const auto &[bus, stops] : r.buses_to_stops) {
			os << "Bus " << bus << ":";
			for (const auto &stop : stops)
				os << ' ' << stop;
			if ((--r.buses_to_stops.end())->first != bus)
				os << std::endl;
		}
	}
  return os;
}
