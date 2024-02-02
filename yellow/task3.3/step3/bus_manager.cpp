#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
	buses_to_stops[bus] = stops;
	for (const auto &stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
	BusesForStopResponse ans;

  if (stops_to_buses.count(stop) == 0) {
		ans.no_stop = true;
  } else {
		ans.no_stop = false;
		ans.buses = stops_to_buses.at(stop);
  }
	return (ans);
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
	StopsForBusResponse ans;
	
	if (buses_to_stops.count(bus) == 0)  {
		ans.stops.resize(0);
		return (ans);
	}
	ans.stops = buses_to_stops.at(bus);
	ans.stops_to_buses.resize(ans.stops.size());
	for (size_t i = 0; i < ans.stops.size(); ++i) {
		if (stops_to_buses.at(ans.stops[i]).size() == 1)
			ans.stops_to_buses[i].push_back("no interchange");
		else  {
			for (const std::string& other_bus : stops_to_buses.at(ans.stops[i])) {
      	if (bus != other_bus) {
					ans.stops_to_buses[i].push_back(other_bus);
        }
			}
		}
	}
	return (ans);
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse ans;

	ans.buses_to_stops = buses_to_stops;
	return (ans);
}

